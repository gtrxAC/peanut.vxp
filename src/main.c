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

		default: break;
	}
}

void draw_frame(VMINT tid) {
	switch (state) {
		case ST_MENU: draw_menu(); break;
		case ST_RUNNING: draw_emu(); break;
	}
}

void handle_keyevt(VMINT event, VMINT keycode) {
	switch (state) {
		case ST_MENU: handle_keyevt_menu(event, keycode); break;
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
	case VM_MSG_CREATE:	/* the message of creation of application */
	case VM_MSG_ACTIVE: /* the message of application state from inactive to active */
		/*cerate base layer that has same size as the screen*/
		screen_width = vm_graphic_get_screen_width();
		screen_height = vm_graphic_get_screen_height();
		layer_hdl[0] = vm_graphic_create_layer(0, 0, screen_width, screen_height, VM_NO_TRANS_COLOR);
		
		/* set clip area*/
		vm_graphic_set_clip(0, 0, screen_width, screen_height);

		canvas = vm_graphic_create_canvas_cf(VM_GRAPHIC_COLOR_FORMAT_16, 160, 144);
		canvas_buf = vm_graphic_get_canvas_buffer(canvas) + VM_CANVAS_DATA_OFFSET;
		layer_hdl[1] = vm_graphic_create_layer_cf(
			VM_GRAPHIC_COLOR_FORMAT_16, screen_width/2 - 80, screen_height/2 - 72, 
			160, 144, (vm_graphic_color_argb *)VM_NO_TRANS_COLOR, VM_BUF, canvas_buf, 160*144*2
		);
		break;
		
	case VM_MSG_PAINT: {
		// Screen clearing is handled by the paint event, so it's only done when necessary
		// Rest of the rendering will be handled by the draw_frame timer
		color.vm_color_565 = VM_COLOR_BLACK;
		vm_graphic_setcolor(&color);
		vm_graphic_fill_rect_ex(layer_hdl[0], 0, 0, screen_width, screen_height);
		break;
	}
		
	case VM_MSG_INACTIVE:	/* the message of application state from active to inactive */
		if( layer_hdl[0] != -1 )
			vm_graphic_delete_layer(layer_hdl[0]);
		break;	

	case VM_MSG_QUIT:		/* the message of quit application */
		if( layer_hdl[0] != -1 )
			vm_graphic_delete_layer(layer_hdl[0]);
		break;	
	}
}