#define ENABLE_LCD 1
#define STB_DS_IMPLEMENTATION
#define PEANUT_GB_HIGH_LCD_ACCURACY 0
#define ENABLE_SOUND 1
#include "common.h"

VMINT layer_hdl[2];
VMINT screen_width;
// screen_height is the height which is used for the app UI (game and menus), 
// may be lower than screen_full_height if touch mode is enabled (bottom of the
// screen has the touch controls)
VMINT screen_height;       
VMINT screen_full_height;  // Actual screen height
vm_graphic_color color;

extern struct gb_s *gb;

VMINT canvas;
VMUINT8 *canvas_buf;

// in 1.5x scaling mode, game is drawn into scale_buf, then it's upscaled to
// canvas_buf, which is then drawn
VMUINT8 *scale_buf;

// Most MRE functions use wide (UCS2) strings, here's a general purpose buffer for them
VMWCHAR ucs2_str[128];

State state = ST_MENU;
VMBOOL touch_mode;

extern int keymapper_cur_key;

const VMWSTR key_labels[12] = {
	u"―", u"↑", u"―", u"A",
	u"←", u"", u"→", u"B",
	u"Menu", u"↓", u"Sel", u"St"
};

const VMWSTR key_labels_basic[12] = {
	u"-", u"Up", u"-", u"A",
	u"Lt", u"", u"Rt", u"B",
	u"Menu", u"Dn", u"Sel", u"St"
};

void draw_touch_area() {
	// Clear touch area with black
	color.vm_color_565 = VM_COLOR_BLACK;
	vm_graphic_setcolor(&color);
	vm_graphic_fill_rect_ex(layer_hdl[0], 0, screen_height, screen_width, screen_full_height);

	int touch_area_height = screen_full_height - screen_height;
	int cell_width = screen_width/4;
	int cell_height = touch_area_height/3;

	color.vm_color_565 = 0xA554;
	vm_graphic_setcolor(&color);

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 4; x++) {
			int i = y*4 + x;
			// Don't show right softkey when in game (left softkey is replaced by speed-up)
			if (state == ST_RUNNING && i == 2) continue;

			// Don't show game buttons when in menus
			if (state != ST_RUNNING && (i == 3 || i == 7 || i == 8 || i == 10 || i == 11)) continue;

			VMWSTR label = (VMWSTR) (config->basic_touch_labels ? key_labels_basic : key_labels)[i];
			if (state == ST_RUNNING && i == 0) label = u">>";

			vm_graphic_textout_to_layer(
				layer_hdl[0],
				x*cell_width + cell_width/2 - vm_graphic_get_string_width(label)/2,
				screen_height + y*cell_height + cell_height/2 - vm_graphic_get_character_height()/2,
				label, 256
			);
		}
	}
}

void calc_screen_size() {
	screen_width = vm_graphic_get_screen_width();
	screen_full_height = vm_graphic_get_screen_height();
	
	if (!touch_mode) {
		screen_height = screen_full_height;
		return;
	}
	switch (config->scale) {
		case SCALE_1X: screen_height = 160; break;
		case SCALE_1_5X_BILINEAR: SCALE_1_5X_NEAREST: screen_height = 216; break;
		case SCALE_2X: screen_height = 288; break;
	}
}

void set_state(State new_state) {
	state = new_state;
	if (touch_mode) draw_touch_area();
	switch (state) {
		case ST_RUNNING: {
			// Clear screen so there are no graphical leftovers from the menu.
			// When the game is running, the screen isn't cleared every frame for performance reasons.
			color.vm_color_565 = VM_COLOR_BLACK;
			vm_graphic_setcolor(&color);
			vm_graphic_fill_rect_ex(layer_hdl[0], 0, 0, screen_width, screen_height);

			// Interlacing in 1x and 2x modes simply means half of the lines are
			// not rendered by the emulator core itself.
			// However, in 1.5x modes, the emulator core renders the whole
			// frame, but the scaling algorithm is what skips half of the lines.
			if (config->scale == SCALE_1_5X_NEAREST || config->scale == SCALE_1_5X_BILINEAR) {
				gb->direct.interlace = 0;
			} else {
				gb->direct.interlace = config->interlace;
			}
			break;
		}

		case ST_KEY_MAPPER: {
			keymapper_cur_key = 0;
			break;
		}

		default: break;
	}
}

void init_canvas() {
	calc_screen_size();
	int canvas_width, canvas_height;
	switch (config->scale) {
		case SCALE_1X: canvas_width = 160; canvas_height = 144; break;
		case SCALE_1_5X_NEAREST: case SCALE_1_5X_BILINEAR: canvas_width = 240; canvas_height = 216; break;
		case SCALE_2X: canvas_width = 320; canvas_height = 288; break;
	}

	// Delete previous canvas/layer data if needed
	if (layer_hdl[1] != -1) {
		vm_graphic_delete_layer(layer_hdl[1]);
		vm_graphic_release_canvas(canvas);
	}
	if (scale_buf) {
		free(scale_buf);
		scale_buf = 0;
	}

	// Create scaling layer for 1.5x scaling mode
	if (config->scale == SCALE_1_5X_NEAREST || config->scale == SCALE_1_5X_BILINEAR) {
		scale_buf = malloc(160*144*2);
		if (!scale_buf) {
			show_error_and_exit("Out of memory!");
			return;
		}
	}

	// Create new canvas and layer with the appropriate size
	canvas = vm_graphic_create_canvas_cf(VM_GRAPHIC_COLOR_FORMAT_16, canvas_width, canvas_height);
	if (canvas < 0) {
		show_error_and_exit("Out of memory!");
		config->scale = SCALE_1X;
		save_config();
		init_canvas();
	}
	canvas_buf = vm_graphic_get_canvas_buffer(canvas) + VM_CANVAS_DATA_OFFSET;
	layer_hdl[1] = vm_graphic_create_layer_cf(
		VM_GRAPHIC_COLOR_FORMAT_16,
		screen_width/2 - canvas_width/2, screen_height/2 - canvas_height/2, 
		canvas_width, canvas_height,
		(vm_graphic_color_argb *)VM_NO_TRANS_COLOR, VM_BUF, canvas_buf,
		canvas_width*canvas_height*2
	);
	if (touch_mode) draw_touch_area();
}

void draw_frame(VMINT tid) {
	switch (state) {
		case ST_MENU: draw_menu(); break;
		case ST_KEY_MAPPER: draw_keymapper(); break;
		case ST_RUNNING: draw_emu(); break;
	}
}

void handle_penevt(VMINT event, VMINT x, VMINT y);

void handle_keyevt(VMINT event, VMINT keycode) {
	switch (state) {
		case ST_MENU: handle_keyevt_menu(event, keycode); break;
		case ST_KEY_MAPPER: handle_keyevt_keymapper(event, keycode); break;
		case ST_RUNNING: handle_keyevt_emu(event, keycode); break;
	}
}

void handle_penevt(VMINT event, VMINT x, VMINT y) {
	// Activate touch mode when pen is pressed for the first time.
	if (!touch_mode) {
		touch_mode = VM_TRUE;
		calc_screen_size();
		init_canvas();
		return;
	}

	// Map pen events to key events.
	int key_event;
	switch (event) {
		case VM_PEN_EVENT_TAP: key_event = VM_KEY_EVENT_DOWN; break;
		case VM_PEN_EVENT_RELEASE: key_event = VM_KEY_EVENT_UP; break;
		default: return;
	}

	// Touch area is divided into a 4×3 grid.
	// Each cell simply corresponds to a key event for a specific key.
	int touch_area_height = screen_full_height - screen_height;
	int cell_width = screen_width/4;
	int cell_height = touch_area_height/3;

	y -= screen_height;
	if (y < 0) return;

	x /= cell_width;
	y /= cell_height;

	int key;
	switch (y*4 + x) {
		// Top left-most key is left softkey when in menus, and speed-up when in game.
		case 0: {
			if (state == ST_RUNNING) {
				key = config->key_fast_forward;
			} else {
				key = VM_KEY_LEFT_SOFTKEY;
			}
			break;
		}

		case 1: key = config->key_up; break;
		case 2: key = VM_KEY_RIGHT_SOFTKEY; break;
		case 3: key = config->key_a; break;
		case 4: key = config->key_left; break;
		case 5: return;
		case 6: key = config->key_right; break;
		case 7: key = config->key_b; break;
		case 8: key = VM_KEY_NUM0; break;
		case 9: key = config->key_down; break;
		case 10: key = config->key_select; break;
		case 11: key = config->key_start; break;
	}
	handle_keyevt(key_event, key);
}

void handle_sysevt(VMINT message, VMINT param);
void handle_penevt(VMINT event, VMINT x, VMINT y);

void vm_main(void) {
	vm_file_mkdir(u"e:\\peanutvxp");
	
	log_init();
	log_write("Started logging");
	
	// Initialize layer handles
	layer_hdl[0] = -1;
	layer_hdl[1] = -1;

	vm_switch_power_saving_mode(turn_off_mode);
	vm_graphic_set_font(VM_SMALL_FONT);
	log_write("Set runtime parameters");
	
	// Register MRE event handlers
	vm_reg_sysevt_callback(handle_sysevt);
	vm_reg_keyboard_callback(handle_keyevt);
	vm_reg_pen_callback(handle_penevt);
	vm_create_timer(33, draw_frame);
	vm_kbd_set_mode(VM_KEYPAD_2KEY_NUMBER);
	log_write("Created event handlers");

	// Initialize emulator settings
	init_emu();

	// Initialize menu
	set_state(ST_MENU);
	set_menu(MENU_MAIN);
	log_write("Initialized menu. Running.");
}

void handle_sysevt(VMINT message, VMINT param) {
	switch (message) {
		case VM_MSG_CREATE:
		case VM_MSG_ACTIVE:
			// Create base layer that has same size as the screen. This layer is
			// used for the menus, and is usually a static black background when
			// in-game, except for pop-up messages. 
			screen_width = vm_graphic_get_screen_width();
			screen_full_height = vm_graphic_get_screen_height();
			screen_height = screen_full_height;
			layer_hdl[0] = vm_graphic_create_layer(0, 0, screen_width, screen_height, VM_NO_TRANS_COLOR);
			vm_graphic_set_clip(0, 0, screen_width, screen_height);

			// Create second layer that is used for rendering the game. This
			// layer is not drawn when in the menus.
			init_canvas();
			break;
			
		case VM_MSG_PAINT: {
			// Screen clearing is handled by the paint event, so it's only done when necessary
			// Rest of the rendering will be handled by the draw_frame timer
			color.vm_color_565 = VM_COLOR_BLACK;
			vm_graphic_setcolor(&color);
			vm_graphic_fill_rect_ex(layer_hdl[0], 0, 0, screen_width, screen_height);
			break;
		}
			
		case VM_MSG_INACTIVE:
		case VM_MSG_QUIT:
			// This is where de-initialization tasks would be done, but they are
			// unnecessary for MRE (all allocated memory is freed at once).
			write_save();
			if( layer_hdl[0] != -1 ) {
				vm_graphic_delete_layer(layer_hdl[0]);
			}
			break;
	}
}