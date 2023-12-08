#define PEANUT_GB_HEADER_ONLY
#include "common.h"

extern VMINT layer_hdl[2]; // second layer is not used for key mapper
extern VMINT screen_width;
extern VMINT screen_height;
extern vm_graphic_color color;

extern VMWCHAR ucs2_str[128];

int keymapper_cur_key;
const char *key_names[] = {
    "up", "down", "left", "right", "A", "B", "start", "select"
};

// _____________________________________________________________________________
//
//  Rendering
// _____________________________________________________________________________
//
void draw_keymapper() {
    // Clear screen
    color.vm_color_565 = VM_COLOR_BLACK;
    vm_graphic_setcolor(&color);
    vm_graphic_fill_rect_ex(layer_hdl[0], 0, 0, screen_width, screen_height);

	// Compose string and calculate draw position (center)
	char format_str[32];
	sprintf(format_str, "Press the key for: %s", key_names[keymapper_cur_key]);
	vm_ascii_to_ucs2(ucs2_str, 256, format_str);
	int x = screen_width/2 - vm_graphic_get_string_width(ucs2_str)/2;
	int y = screen_height/2 - vm_graphic_get_character_height()/2;

	// Draw string
    color.vm_color_565 = VM_COLOR_WHITE;
    vm_graphic_setcolor(&color);
	vm_graphic_textout_to_layer(layer_hdl[0], x, y, ucs2_str, 256);

    vm_graphic_flush_layer(layer_hdl, 1);
}

// _____________________________________________________________________________
//
//  Key event handler
// _____________________________________________________________________________
//
void handle_keyevt_keymapper(VMINT event, VMINT keycode) {
	if (event != VM_KEY_EVENT_DOWN) return;
	if (keycode == VM_KEY_NUM0) return;  // 0 is reserved for menu
	
	switch (keymapper_cur_key) {
		case 0: config->key_up = keycode; break;
		case 1: config->key_down = keycode; break;
		case 2: config->key_left = keycode; break;
		case 3: config->key_right = keycode; break;
		case 4: config->key_a = keycode; break;
		case 5: config->key_b = keycode; break;
		case 6: config->key_start = keycode; break;
		case 7: config->key_select = keycode; break;
	}
	keymapper_cur_key++;
	if (keymapper_cur_key > 7) {
		save_config();
		set_state(ST_MENU);
	}
}