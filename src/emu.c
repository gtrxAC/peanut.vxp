#define PEANUT_GB_HEADER_ONLY
#include "common.h"

struct gb_s *gb;
VMBOOL gb_inited;
char *save_name;
VMUINT8 *rom_data;
VMUINT8 *cart_ram;

int show_fps;
int tick_count;
char fps_str[16];

VMWCHAR message[32];
int message_timer;

extern VMUINT8 *canvas_buf;
extern VMINT layer_hdl[2];
extern VMINT screen_width;
extern VMINT screen_height;
extern vm_graphic_color color;

extern State state;
extern VMWCHAR ucs2_str[128];

// _____________________________________________________________________________
//
void set_message(char *msg) {
	vm_ascii_to_ucs2(message, 64, msg);
	message_timer = 60;

	color.vm_color_565 = VM_COLOR_BLACK;
	vm_graphic_setcolor(&color);
	vm_graphic_fill_rect_ex(layer_hdl[0], 0, 0, screen_width, 24);
	color.vm_color_565 = 0xF7F0;
	vm_graphic_setcolor(&color);
	vm_graphic_textout_to_layer(layer_hdl[0], 2, 2, message, 64);
}

// _____________________________________________________________________________
//
//  Peanut-GB implementation
// _____________________________________________________________________________
//
VMUINT8 gb_rom_read(struct gb_s *gb, const uint_fast32_t addr) {
	return rom_data[addr];
}

VMUINT8 gb_cart_ram_read(struct gb_s *gb, const uint_fast32_t addr) {
	return cart_ram[addr];
}

void gb_cart_ram_write(struct gb_s *gb, const uint_fast32_t addr, const uint8_t val) {
	cart_ram[addr] = val;
}

void gb_error(struct gb_s* gb, const enum gb_error_e err, const uint16_t addr) {
	switch (err) {
		case GB_UNKNOWN_ERROR: log_write("Unknown error"); break;
		case GB_INVALID_OPCODE: log_write("Invalid opcode"); break;
		case GB_INVALID_READ: log_write("Invalid read"); break;
		case GB_INVALID_WRITE: log_write("Invalid write"); break;
		case GB_HALT_FOREVER: log_write("Halt forever"); break;
	}
}

void lcd_draw_line(struct gb_s *gb, const uint8_t pixels[160], const unsigned int line) {
	for (int i = 0; i < 160; i++) {
		((VMUINT16 *)canvas_buf)[160*line + i] = config->palette[pixels[i]];
	}
}

// _____________________________________________________________________________
//
//  Rendering
// _____________________________________________________________________________
//
void draw_emu() {
    if (show_fps) tick_count = vm_get_tick_count();

    if (message_timer == 0) {
        color.vm_color_565 = VM_COLOR_BLACK;
        vm_graphic_setcolor(&color);
        vm_graphic_fill_rect_ex(layer_hdl[0], 0, 0, screen_width, 24);
    }
    message_timer--;

    gb_run_frame(gb);
    gb_run_frame(gb);
    vm_graphic_flush_layer(layer_hdl, 2);

    if (show_fps) {
        sprintf(fps_str, "%d fps", (int) 1000 / (vm_get_tick_count() - tick_count));
        set_message(fps_str);
    }
}

// _____________________________________________________________________________
//
//  Key event handler
// _____________________________________________________________________________
//
void handle_keyevt_emu(VMINT event, VMINT keycode) {
	switch (event) {
		case VM_KEY_EVENT_DOWN: {
			switch (keycode) {
				case config->key_up: gb->direct.joypad_bits.up = 0; break;
				case config->key_left: gb->direct.joypad_bits.left = 0; break;
				case config->key_down: gb->direct.joypad_bits.down = 0; break;
				case config->key_right: gb->direct.joypad_bits.right = 0; break;
				case config->key_a: gb->direct.joypad_bits.a = 0; break;
				case config->key_b: gb->direct.joypad_bits.b = 0; break;
				case config->key_select: gb->direct.joypad_bits.select = 0; break;
				case config->key_start: gb->direct.joypad_bits.start = 0; break;

				case VM_KEY_NUM0:
					set_state(ST_MENU);
					set_menu(MENU_MAIN);
					break;
			}
			break;
		}

		case VM_KEY_EVENT_UP: {
			gb->direct.joypad_bits.up = 1;
			gb->direct.joypad_bits.left = 1;
			gb->direct.joypad_bits.down = 1;
			gb->direct.joypad_bits.right = 1;
			gb->direct.joypad_bits.a = 1;
			gb->direct.joypad_bits.b = 1;
			gb->direct.joypad_bits.select = 1;
			gb->direct.joypad_bits.start = 1;
			break;
		}

		default: break;
	}
}

// _____________________________________________________________________________
//
//  Emulator initialization and ROM loading
// _____________________________________________________________________________
//
// This initializes the emulator just enough so that its settings are loaded
// and can be modified. Further loading happens in load_rom.
void init_emu() {
	if (gb) free(gb);
	gb = calloc(1, sizeof (struct gb_s));
	log_write("Allocated GB state");
	
	load_config();
	gb->direct.interlace = config->interlace;
}

void load_rom(char *filename) {
	init_emu();

	// Load ROM data
	if (rom_data) free(rom_data);
	read_from_file_to_addr(filename, (void **)&rom_data);
	log_write("Loaded ROM");

	// Init emulator
	gb_init(gb, gb_rom_read, gb_cart_ram_read, gb_cart_ram_write, gb_error, NULL);
	gb_init_lcd(gb, lcd_draw_line);
	log_write("Initialized emulator");
	gb->direct.frame_skip = 1;
	gb_inited = VM_TRUE;

	// Get save name based on ROM name (replace .gbc or .gb suffix)
	if (save_name) free(save_name);
	save_name = TextReplace(filename, ".gbc", ".sav");
	if (!strcmp(filename, save_name)) {
		free(save_name);
		save_name = TextReplace(filename, ".gb", ".sav");
	}
	log_write("Created save file name");

	// Get full path of save name (as UCS2 encoded string)
	VMCHAR save_name_full[128];
	sprintf(save_name_full, "e:\\peanutvxp\\%s", save_name);
	vm_ascii_to_ucs2(ucs2_str, 256, save_name_full);
	log_write("Created save file path");

	// Load or create save file
	if (vm_file_get_attributes(ucs2_str) != -1) {
		log_write("Save file found, loading it");
		read_from_file_to_addr(save_name, (void **)&cart_ram);
	} else {
		if (gb_get_save_size(gb)) {
			log_write("Save file not found, creating it");
			cart_ram = calloc(gb_get_save_size(gb), 1);
		} else {
			log_write("This game doesn't use save data");
		}
	}
	log_write("Loaded/created save file");
    set_state(ST_RUNNING);
}