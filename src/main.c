#define ENABLE_LCD 1
#define PEANUT_GB_12_COLOUR 0
#define STB_DS_IMPLEMENTATION
#include "common.h"

VMINT layer_hdl[2];
VMINT screen_width;
VMINT screen_height;
vm_graphic_color color;

VMINT canvas;
VMUINT8 *canvas_buf;

// Most MRE functions use wide (UCS2) strings, here's a general purpose buffer for them
VMWCHAR ucs2_str[128];

State state = ST_MENU;

extern int keymapper_cur_key;

void set_state(State new_state) {
	state = new_state;
	switch (state) {
		case ST_RUNNING: {
			// Clear screen so there are no graphical leftovers from the menu.
			// When the game is running, the screen isn't cleared every frame for performance reasons.
			color.vm_color_565 = VM_COLOR_BLACK;
			vm_graphic_setcolor(&color);
			vm_graphic_fill_rect_ex(layer_hdl[0], 0, 0, screen_width, screen_height);
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
	int canvas_width, canvas_height;
	switch (config->scale) {
		case SCALE_1X: canvas_width = 160; canvas_height = 144; break;
		case SCALE_1_5X: canvas_width = 240; canvas_height = 216; break;
		case SCALE_2X: canvas_width = 320; canvas_height = 288; break;
	}

	// Delete previous canvas/layer data if needed
	if (layer_hdl[1] != -1) {
		vm_graphic_delete_layer(layer_hdl[1]);
		vm_graphic_release_canvas(canvas);
	}

	// Create new canvas and layer with the appropriate size
	canvas = vm_graphic_create_canvas_cf(VM_GRAPHIC_COLOR_FORMAT_16, canvas_width, canvas_height);
	canvas_buf = vm_graphic_get_canvas_buffer(canvas) + VM_CANVAS_DATA_OFFSET;
	layer_hdl[1] = vm_graphic_create_layer_cf(
		VM_GRAPHIC_COLOR_FORMAT_16,
		screen_width/2 - canvas_width/2, screen_height/2 - canvas_height/2, 
		canvas_width, canvas_height,
		(vm_graphic_color_argb *)VM_NO_TRANS_COLOR, VM_BUF, canvas_buf,
		canvas_width*canvas_height*2
	);
}

void draw_frame(VMINT tid) {
	switch (state) {
		case ST_MENU: draw_menu(); break;
		case ST_KEY_MAPPER: draw_keymapper(); break;
		case ST_RUNNING: draw_emu(); break;
	}
}

void handle_keyevt(VMINT event, VMINT keycode) {
	switch (state) {
		case ST_MENU: handle_keyevt_menu(event, keycode); break;
		case ST_KEY_MAPPER: handle_keyevt_keymapper(event, keycode); break;
		case ST_RUNNING: handle_keyevt_emu(event, keycode); break;
	}
}

void handle_sysevt(VMINT message, VMINT param);
void handle_penevt(VMINT event, VMINT x, VMINT y) { }

void vm_main(void) {
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
			screen_height = vm_graphic_get_screen_height();
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