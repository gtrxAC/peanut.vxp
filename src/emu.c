#define PEANUT_GB_HEADER_ONLY
#include "common.h"

struct gb_s *gb;
VMBOOL gb_inited;
char *save_name;
VMUINT8 *rom_data;
VMUINT8 *cart_ram;

int tick_count;
char fps_str[8];

int last_rtc_tick;

extern VMUINT8 *canvas_buf;
extern VMINT layer_hdl[2];
extern VMINT screen_width;
extern VMINT screen_height;
extern vm_graphic_color color;

extern State state;
extern VMWCHAR ucs2_str[128];

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
	switch (config->scale) {
		case SCALE_1X: {
			for (int i = 0; i < 160; i++) {
				((VMUINT16 *)canvas_buf)[160*line + i] = config->palette[pixels[i]];
			}
			break;
		}

		case SCALE_2X: {
			for (int i = 0; i < 160; i++) {
				((VMUINT16 *)canvas_buf)[640*line + i*2] = config->palette[pixels[i]];
				((VMUINT16 *)canvas_buf)[640*line + i*2 + 1] = config->palette[pixels[i]];
				((VMUINT16 *)canvas_buf)[640*line + i*2 + 320] = config->palette[pixels[i]];
				((VMUINT16 *)canvas_buf)[640*line + i*2 + 321] = config->palette[pixels[i]];
			}
			break;
		}
	}
}

void write_save() {
	if (!gb_inited) return;
	int save_size = gb_get_save_size(gb);
	if (save_size) {
		write_from_addr_to_file(save_name, cart_ram, save_size);
		log_write("Wrote save file");
	}
}

// _____________________________________________________________________________
//
//  Rendering
// _____________________________________________________________________________
//
void draw_emu() {
    if (config->show_fps) tick_count = vm_get_tick_count();

    gb_run_frame(gb);
    gb_run_frame(gb);
    vm_graphic_flush_layer(layer_hdl, 2);

	int new_tick_count = vm_get_tick_count();

    if (config->show_fps) {
        sprintf(fps_str, "%d", (int) 1000 / (new_tick_count - tick_count));
        vm_ascii_to_ucs2(ucs2_str, 256, fps_str);

		color.vm_color_565 = VM_COLOR_BLACK;
		vm_graphic_setcolor(&color);
		vm_graphic_fill_rect_ex(layer_hdl[0], 1, 1, 50, vm_graphic_get_character_height());

		color.vm_color_565 = VM_COLOR_WHITE;
		vm_graphic_setcolor(&color);
		vm_graphic_textout_to_layer(layer_hdl[0], 1, 1, ucs2_str, 256);
    }
	if (new_tick_count >= last_rtc_tick + 1000) {
		gb_tick_rtc(gb);
		last_rtc_tick += 1000;
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
			if      (keycode == config->key_up) gb->direct.joypad_bits.up = 0;
			else if (keycode == config->key_down) gb->direct.joypad_bits.down = 0;
			else if (keycode == config->key_left) gb->direct.joypad_bits.left = 0;
			else if (keycode == config->key_right) gb->direct.joypad_bits.right = 0;
			else if (keycode == config->key_a) gb->direct.joypad_bits.a = 0;
			else if (keycode == config->key_b) gb->direct.joypad_bits.b = 0;
			else if (keycode == config->key_start) gb->direct.joypad_bits.start = 0;
			else if (keycode == config->key_select) gb->direct.joypad_bits.select = 0;

			else if (keycode == VM_KEY_NUM0) {
				write_save();
				set_state(ST_MENU);
				set_menu(MENU_MAIN);
			}
			break;
		}

		case VM_KEY_EVENT_UP: {
			if      (keycode == config->key_up) gb->direct.joypad_bits.up = 1;
			else if (keycode == config->key_down) gb->direct.joypad_bits.down = 1;
			else if (keycode == config->key_left) gb->direct.joypad_bits.left = 1;
			else if (keycode == config->key_right) gb->direct.joypad_bits.right = 1;
			else if (keycode == config->key_a) gb->direct.joypad_bits.a = 1;
			else if (keycode == config->key_b) gb->direct.joypad_bits.b = 1;
			else if (keycode == config->key_start) gb->direct.joypad_bits.start = 1;
			else if (keycode == config->key_select) gb->direct.joypad_bits.select = 1;
			break;
		}

		default: break;
	}
}
// _____________________________________________________________________________
//
//  Save states
// _____________________________________________________________________________
//
char *get_state_name(int num) {
	char extension[8];
	sprintf(extension, ".ss%d", num);
	return TextReplace(save_name, ".sav", extension);
}

VMBOOL state_exists(int num) {
	char *state_name = get_state_name(num);
	if (!state_name) return VM_FALSE;

	VMCHAR state_name_full[128];
	sprintf(state_name_full, "e:\\peanutvxp\\%s", state_name);
	vm_ascii_to_ucs2(ucs2_str, 256, state_name_full);
	
	VMBOOL result = vm_file_get_attributes(ucs2_str) != -1;
	free(state_name);
	return result;
}

void load_state(int num) {
	char *state_name = get_state_name(num);
	if (!state_name) return;

	read_from_file_to_addr(state_name, (void **)&gb);

	// Re-assign frontend functions to the loaded gb structure
	gb->gb_rom_read = gb_rom_read;
	gb->gb_cart_ram_read = gb_cart_ram_read;
	gb->gb_cart_ram_write = gb_cart_ram_write;
	gb->gb_error = gb_error;
	gb->display.lcd_draw_line = lcd_draw_line;

	free(state_name);
}

void save_state(int num) {
	char *state_name = get_state_name(num);
	if (!state_name) return;
	write_from_addr_to_file(state_name, gb, sizeof(struct gb_s));
	free(state_name);
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
	if (!rom_data) return;
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
		if (!cart_ram) return;
	} else {
		if (gb_get_save_size(gb)) {
			log_write("Save file not found, creating it");
			cart_ram = calloc(gb_get_save_size(gb), 1);
		} else {
			log_write("This game doesn't use save data");
		}
	}
	log_write("Loaded/created save file");

	init_rtc();
    set_state(ST_RUNNING);
}

// _____________________________________________________________________________
//
//  RTC initialization (MRE vm_time -> C struct tm)
// _____________________________________________________________________________
//
const int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void init_rtc() {
	vm_time_t mre_time;
	int result = vm_get_time(&mre_time);
	if (result == -1) return;

	// Calculate day of year (0-365).
	for (int i = 0; i < mre_time.mon - 1; i++) {
		mre_time.day += days_in_month[i];
	}

	gb->rtc_bits.sec = mre_time.sec - 1;
	gb->rtc_bits.min = mre_time.min - 1;
	gb->rtc_bits.hour = mre_time.hour - 1;
	gb->rtc_bits.yday = (mre_time.day - 1) & 0xFF;
	gb->rtc_bits.high = ((mre_time.day - 1) & 0xFF00) >> 8;
	log_write("Set RTC time");
}