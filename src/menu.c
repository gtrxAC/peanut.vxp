#define PEANUT_GB_HEADER_ONLY
#include "common.h"

extern VMINT layer_hdl[2];  // second layer isn't used for the menu
extern VMINT screen_width;
extern VMINT screen_height;
extern vm_graphic_color color;

extern VMBOOL gb_inited;
extern struct gb_s *gb;

extern State state;
extern VMWCHAR ucs2_str[128];

extern const VMUINT16 palettes[PALETTE_COUNT][4];

char **menu_list; // stb_ds
int menu_choice;
int main_menu_choice;

Menu menu;

// _____________________________________________________________________________
//
//  Rendering
// _____________________________________________________________________________
//
void draw_menu() {
    // Clear screen
    color.vm_color_565 = VM_COLOR_BLACK;
    vm_graphic_setcolor(&color);
    vm_graphic_fill_rect_ex(layer_hdl[0], 0, 0, screen_width, screen_height);

    int row_height = vm_graphic_get_character_height() + 2;
    int items_on_screen = screen_height/row_height - 1;
    
    // Draw menu elements
    for (int i = 0; i < items_on_screen; i++) {
        int y = i*row_height + 1;
        int item = menu_choice - items_on_screen/2 + i;

        if (item < 0 || item >= arrlen(menu_list)) continue;

        if (item == menu_choice) {
            color.vm_color_565 = VM_COLOR_WHITE;
            vm_graphic_setcolor(&color);
            vm_ascii_to_ucs2(ucs2_str, 256, ">");
            vm_graphic_textout_to_layer(layer_hdl[0], 1, y, ucs2_str, 16);
        } else {
            color.vm_color_565 = 0xA554;
            vm_graphic_setcolor(&color);
        }
        
        vm_ascii_to_ucs2(ucs2_str, 256, menu_list[item]);
        vm_graphic_textout_to_layer(layer_hdl[0], 16, y, ucs2_str, screen_width);
    }

    // Draw softkeys
    color.vm_color_565 = 0x1082;
    vm_graphic_setcolor(&color);
    vm_graphic_fill_rect_ex(layer_hdl[0], 0, screen_height - row_height - 2, screen_width, row_height + 2);

    color.vm_color_565 = 0XD6DA;
    vm_graphic_setcolor(&color);

    if (menu != MENU_ABOUT) {
        vm_ascii_to_ucs2(ucs2_str, 256, "Select");
        vm_graphic_textout_to_layer(layer_hdl[0], 1, screen_height - row_height + 1, ucs2_str, screen_width);
    }

    if (menu != MENU_MAIN || gb_inited) {
        vm_ascii_to_ucs2(ucs2_str, 256, "Back");
        vm_graphic_textout_to_layer(
            layer_hdl[0], screen_width - 1 - vm_graphic_get_string_width(ucs2_str),
            screen_height - row_height + 1, ucs2_str, screen_width
        );
    }

    vm_graphic_flush_layer(layer_hdl, 1);
}

// _____________________________________________________________________________
//
//  Menu structure
// _____________________________________________________________________________
//
void arrput_ucs2(VMWSTR item) {
    char *item_ascii = malloc(vm_wstrlen(item) + 1);
    vm_ucs2_to_ascii(item_ascii, vm_wstrlen(item) + 1, item);
    arrput(menu_list, item_ascii);
}

char memstat_str[3][32];

void set_menu(Menu new_menu) {
    menu = new_menu;
    menu_choice = 0;
    arrfree(menu_list);
    switch (menu) {
        case MENU_MAIN: {
            menu_choice = main_menu_choice;
            if (gb_inited) arrput(menu_list, "Back to game");
            arrput(menu_list, "Load ROM");
            if (gb_inited) {
                arrput(menu_list, "Reset");
                // arrput(menu_list, "Load state (coming soon)");
                // arrput(menu_list, "Save state (coming soon)");
            }
            arrput(menu_list, "Options");
            arrput(menu_list, "About");
            break;
        }

        case MENU_FILE_PICKER: {
            // This menu uses malloc'ed strings because the MRE find functions
            // return UCS2 strings, we need to convert them to ASCII
            struct vm_fileinfo_t fileinfo;
            vm_ascii_to_ucs2(ucs2_str, 256, "e:\\peanutvxp\\*.gb");
            VMINT find_handle = vm_find_first(ucs2_str, &fileinfo);
            VMINT find_result;

            if (find_handle < 0) {
                char *no_files_str = malloc(16);
                strcpy(no_files_str, "No files found.");
                arrput(menu_list, no_files_str);
                break;
            }
            arrput_ucs2(fileinfo.filename);

            while (VM_TRUE) {
                find_result = vm_find_next(find_handle, &fileinfo);
                if (find_result < 0) break;
                arrput_ucs2(fileinfo.filename);
            }
            vm_find_close(find_handle);
            break;
        }

        case MENU_OPTIONS: {
            arrput(menu_list, gb->direct.interlace ? "Interlacing: ON" : "Interlacing: OFF");
            switch (config->scale) {
                case SCALE_1X: arrput(menu_list, "Scaling: 1x"); break;
                case SCALE_1_5X: arrput(menu_list, "Scaling: 1.5x (not impl'd)"); break;
                case SCALE_2X: arrput(menu_list, "Scaling: 2x (experimental)"); break;
                default: arrput(menu_list, "Scaling: Unknown"); break;
            }
            switch (config->palette_choice) {
                case 0: arrput(menu_list, "Palette: Default"); break;
                case 1: arrput(menu_list, "Palette: BGB"); break;
                case 2: arrput(menu_list, "Palette: Blue"); break;
                case 3: arrput(menu_list, "Palette: Gold"); break;
                case 4: arrput(menu_list, "Palette: Crimson"); break;
                default: arrput(menu_list, "Palette: Unknown"); break;
            }
            // arrput(menu_list, "Key mappings");
            // arrput(menu_list, "Rotation");
            break;
        }

        case MENU_ABOUT: {
            arrput(menu_list, "peanut.vxp");
            arrput(menu_list, "GB emulator for MRE");
            arrput(menu_list, "github.com/gtrxAC");
            break;
        }
    }
}

void menu_back() {
    switch (menu) {
        case MENU_MAIN: if (gb_inited) set_state(ST_RUNNING); break;
        case MENU_FILE_PICKER: {
            // Free memory used by ROM file names
            for (int i = 0; i < arrlen(menu_list); i++) {
                free(menu_list[i]);
            }
            set_menu(MENU_MAIN);
            break;
        }
        case MENU_OPTIONS: set_menu(MENU_MAIN); break;
        case MENU_ABOUT: set_menu(MENU_MAIN); break;
    }
}

void menu_confirm() {
    switch (menu) {
        case MENU_MAIN: {
            main_menu_choice = menu_choice;
            if (!strcmp(menu_list[menu_choice], "Back to game")) {
                set_state(ST_RUNNING);
            }
            else if (!strcmp(menu_list[menu_choice], "Load ROM")) {
                set_menu(MENU_FILE_PICKER);
            }
            else if (!strcmp(menu_list[menu_choice], "Reset")) {
                gb_reset(gb);
                set_state(ST_RUNNING);
            }
            else if (!strcmp(menu_list[menu_choice], "Options")) {
                set_menu(MENU_OPTIONS);
            }
            else if (!strcmp(menu_list[menu_choice], "About")) {
                set_menu(MENU_ABOUT);
            }
            break;
        }

        case MENU_FILE_PICKER:
            load_rom(menu_list[menu_choice]);

            // Free memory used by ROM file names
            for (int i = 0; i < arrlen(menu_list); i++) {
                free(menu_list[i]);
            }
            break;
            
        case MENU_OPTIONS:
            if (!strncmp(menu_list[menu_choice], "Interlacing", 11)) {
                gb->direct.interlace = !gb->direct.interlace;
                config->interlace = gb->direct.interlace;
                save_config();
                set_menu(MENU_OPTIONS);
            }
            else if (!strncmp(menu_list[menu_choice], "Scaling", 7)) {
                config->scale++;
                if (config->scale == SCALE_COUNT) config->scale = SCALE_1X;
                init_canvas();
                save_config();
                set_menu(MENU_OPTIONS);
                menu_choice = 1;
            }
            else if (!strncmp(menu_list[menu_choice], "Palette", 7)) {
                config->palette_choice++;
                if (config->palette_choice == PALETTE_COUNT) config->palette_choice = 0;
                for (int i = 0; i < 4; i++) {
                    config->palette[i] = palettes[config->palette_choice][i];
                }
                save_config();
                set_menu(MENU_OPTIONS);
                menu_choice = 2;
            }
            break;
            
        case MENU_ABOUT:
            set_menu(MENU_MAIN);
            break;
    }
}

// _____________________________________________________________________________
//
//  Key event handler
// _____________________________________________________________________________
//
void menu_up(int count) {
    menu_choice -= count;
    if (menu_choice < 0) menu_choice = arrlen(menu_list) - 1;
}
void menu_down(int count) {
    menu_choice += count;
    if (menu_choice >= arrlen(menu_list)) menu_choice = 0;
}

void handle_keyevt_menu(VMINT event, VMINT keycode) {
	switch (event) {
		case VM_KEY_EVENT_DOWN: {
			switch (keycode) {
                case VM_KEY_UP: case VM_KEY_NUM2: menu_up(1); break;
                case VM_KEY_DOWN: case VM_KEY_NUM8: menu_down(1); break;

                case VM_KEY_LEFT: case VM_KEY_NUM4: menu_up(5); break;
                case VM_KEY_RIGHT: case VM_KEY_NUM6: menu_down(5); break;

                case VM_KEY_OK: case VM_KEY_NUM5: case VM_KEY_LEFT_SOFTKEY:
                    menu_confirm(); break;

                case VM_KEY_BACK: case VM_KEY_RIGHT_SOFTKEY:
                    menu_back(); break;

				case VM_KEY_NUM0:
                    if (gb_inited) set_state(ST_RUNNING);
					break;
			}
			break;
		}
		default: break;
	}
}