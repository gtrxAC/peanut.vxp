#define PEANUT_GB_HEADER_ONLY
#include "common.h"

struct gb_s *gb;
VMBOOL gb_inited;
char *save_name;
VMUINT8 *rom_data;
VMUINT8 *cart_ram;

char fps_str[8];
int fps = 0;
int fps_count = 0;
int fps_timepoint = 0;


VMBOOL fast_forward;

extern VMUINT8 *canvas_buf;
extern VMUINT8 *scale_buf;
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
	if (cart_ram) cart_ram[addr] = val;
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

#define RGB555_TO_RGB565(c) (((c & 0b111111111100000) << 1) | (c & 0b11111))

void lcd_draw_line(struct gb_s *gb, const uint8_t pixels[160], const unsigned int line) {
	switch (config->scale) {
		// 1x scaling: draw directly on canvas buffer
		case SCALE_1X: {
			#if PEANUT_FULL_GBC_SUPPORT
				if (gb->cgb.cgbMode) {
					for (int i = 0; i < 160; i++) {
						((VMUINT16 *)canvas_buf)[160*line + i] = RGB555_TO_RGB565(gb->cgb.fixPalette[pixels[i]]);
					}
				} else {
					for (int i = 0; i < 160; i++) {
						((VMUINT16 *)canvas_buf)[160*line + i] = config->palette[pixels[i] & 0b11];
					}
				}
			#else
				for (int i = 0; i < 160; i++) {
					((VMUINT16 *)canvas_buf)[160*line + i] = config->palette[pixels[i]];
				}
			#endif
			break;
		}

		// 1.5x scaling: same as 1x but draw to a separate buffer which gets scaled to the canvas buffer later
		case SCALE_1_5X_NEAREST: case SCALE_1_5X_BILINEAR: {
			#if PEANUT_FULL_GBC_SUPPORT
				if (gb->cgb.cgbMode) {
					for (int i = 0; i < 160; i++) {
						((VMUINT16 *)scale_buf)[160*line + i] = RGB555_TO_RGB565(gb->cgb.fixPalette[pixels[i]]);
					}
				} else {
					for (int i = 0; i < 160; i++) {
						((VMUINT16 *)scale_buf)[160*line + i] = config->palette[pixels[i] & 0b11];
					}
				}
			#else
				for (int i = 0; i < 160; i++) {
					((VMUINT16 *)scale_buf)[160*line + i] = config->palette[pixels[i]];
				}
			#endif
			break;
		}

		// 2x scaling: draw 4 pixels at a time on canvas buffer
		case SCALE_2X: {
			#if PEANUT_FULL_GBC_SUPPORT
				if (gb->cgb.cgbMode) {
					for (int i = 0; i < 160; i++) {
						((VMUINT16 *)canvas_buf)[640*line + i*2] = RGB555_TO_RGB565(gb->cgb.fixPalette[pixels[i]]);
						((VMUINT16 *)canvas_buf)[640*line + i*2 + 1] = RGB555_TO_RGB565(gb->cgb.fixPalette[pixels[i]]);
						((VMUINT16 *)canvas_buf)[640*line + i*2 + 320] = RGB555_TO_RGB565(gb->cgb.fixPalette[pixels[i]]);
						((VMUINT16 *)canvas_buf)[640*line + i*2 + 321] = RGB555_TO_RGB565(gb->cgb.fixPalette[pixels[i]]);
					}
				} else {
					for (int i = 0; i < 160; i++) {
						((VMUINT16 *)canvas_buf)[640*line + i*2] = config->palette[pixels[i] & 0b11];
						((VMUINT16 *)canvas_buf)[640*line + i*2 + 1] = config->palette[pixels[i] & 0b11];
						((VMUINT16 *)canvas_buf)[640*line + i*2 + 320] = config->palette[pixels[i] & 0b11];
						((VMUINT16 *)canvas_buf)[640*line + i*2 + 321] = config->palette[pixels[i] & 0b11];
					}
				}
			#else
				for (int i = 0; i < 160; i++) {
					((VMUINT16 *)canvas_buf)[640*line + i*2] = config->palette[pixels[i]];
					((VMUINT16 *)canvas_buf)[640*line + i*2 + 1] = config->palette[pixels[i]];
					((VMUINT16 *)canvas_buf)[640*line + i*2 + 320] = config->palette[pixels[i]];
					((VMUINT16 *)canvas_buf)[640*line + i*2 + 321] = config->palette[pixels[i]];
				}
			#endif
			break;
		}
	}
}

void lcd_draw_line_stub(struct gb_s *gb, const uint8_t pixels[160], const unsigned int line) {};

void write_save() {
	if (!gb_inited) return;
	int save_size = gb_get_save_size(gb);
	if (save_size < 0 || !cart_ram) return;

	write_from_addr_to_file(save_name, cart_ram, save_size);
	log_write("Wrote save file");
}

// _____________________________________________________________________________
//
//  Rendering
// _____________________________________________________________________________
//
#define FIXED_POINT_BITS 11

#define I2F(x) ((x) << FIXED_POINT_BITS)
#define F2I(x) ((x) >> FIXED_POINT_BITS)
#define FIXMUL(x, y) (F2I((x) * (y)))
#define FIXDIV(x, y) (I2F(x) / (y))

#define fixed_point int

int scaled_interlace_count;

// Bilinear scaling using fixed-point arithmetic and constant values, used for 1.5x scaling mode
void scale_bilinear() {
	int begin = config->interlace ? scaled_interlace_count : 0;
	int step = 1 + config->interlace;

    for (int y = begin; y < 216; y += step) {
		fixed_point y_position_FFF = y*1356;
        int y_floor = F2I(y_position_FFF);

        fixed_point y_fraction_FFF = y_position_FFF - I2F(y_floor);
        fixed_point y_flip_fraction = 2048 - y_fraction_FFF;

        for (int x = 0; x < 240; x++) {
			fixed_point x_position_FFF = x*1356;
            int x_floor = F2I(x_position_FFF);
            fixed_point x_fraction_FFF = x_position_FFF - I2F(x_floor);

            int index = y_floor * 160 + x_floor;
            VMUINT16 pixel_tl = ((VMUINT16 *)scale_buf)[index];
            VMUINT16 pixel_tr = ((VMUINT16 *)scale_buf)[index + 1];
            VMUINT16 pixel_bl = ((VMUINT16 *)scale_buf)[index + 160];
            VMUINT16 pixel_br = ((VMUINT16 *)scale_buf)[index + 161];

            fixed_point fraction_tl = FIXMUL(2048 - x_fraction_FFF, y_flip_fraction);
            fixed_point fraction_tr = FIXMUL(x_fraction_FFF, y_flip_fraction);
            fixed_point fraction_bl = FIXMUL(2048 - x_fraction_FFF, y_fraction_FFF);
            fixed_point fraction_br = FIXMUL(x_fraction_FFF, y_fraction_FFF);

            int interp_r = (FIXMUL(fraction_tl, pixel_tl) +
                            FIXMUL(fraction_tr, pixel_tr) +
                            FIXMUL(fraction_bl, pixel_bl) +
                            FIXMUL(fraction_br, pixel_br));

            int interp_g = (FIXMUL(fraction_tl, (pixel_tl << 6) & 0b11111100000000000) +
                            FIXMUL(fraction_tr, (pixel_tr << 6) & 0b11111100000000000) +
                            FIXMUL(fraction_bl, (pixel_bl << 6) & 0b11111100000000000) +
                            FIXMUL(fraction_br, (pixel_br << 6) & 0b11111100000000000));

            int interp_b = (FIXMUL(fraction_tl, (pixel_tl << 11) & 0b1111100000000000) +
                            FIXMUL(fraction_tr, (pixel_tr << 11) & 0b1111100000000000) +
                            FIXMUL(fraction_bl, (pixel_bl << 11) & 0b1111100000000000) +
                            FIXMUL(fraction_br, (pixel_br << 11) & 0b1111100000000000));

            ((VMUINT16 *)canvas_buf)[y * 240 + x] = (interp_r & VM_COLOR_RED) | ((interp_g >> 6) & VM_COLOR_GREEN) | (interp_b >> 11);
        }
    }

	scaled_interlace_count = !scaled_interlace_count;
}

// Grayscale version (only calculates red component, faster)
void scale_bilinear_gray() {
	int begin = config->interlace ? scaled_interlace_count : 0;
	int step = 1 + config->interlace;

    for (int y = begin; y < 216; y += step) {
		fixed_point y_position_FFF = y*1356;
        int y_floor = F2I(y_position_FFF);

        fixed_point y_fraction_FFF = y_position_FFF - I2F(y_floor);
        fixed_point y_flip_fraction = 2048 - y_fraction_FFF;

        for (int x = 0; x < 240; x++) {
			fixed_point x_position_FFF = x*1356;
            int x_floor = F2I(x_position_FFF);
            fixed_point x_fraction_FFF = x_position_FFF - I2F(x_floor);

            int index = y_floor * 160 + x_floor;
            VMUINT16 pixel_tl = ((VMUINT16 *)scale_buf)[index];
            VMUINT16 pixel_tr = ((VMUINT16 *)scale_buf)[index + 1];
            VMUINT16 pixel_bl = ((VMUINT16 *)scale_buf)[index + 160];
            VMUINT16 pixel_br = ((VMUINT16 *)scale_buf)[index + 161];

            int interp_r = (FIXMUL(FIXMUL(2048 - x_fraction_FFF, y_flip_fraction), pixel_tl) +
                            FIXMUL(FIXMUL(x_fraction_FFF, y_flip_fraction), pixel_tr) +
                            FIXMUL(FIXMUL(2048 - x_fraction_FFF, y_fraction_FFF), pixel_bl) +
                            FIXMUL(FIXMUL(x_fraction_FFF, y_fraction_FFF), pixel_br));

            ((VMUINT16 *)canvas_buf)[y * 240 + x] = (interp_r & VM_COLOR_RED) | ((interp_r >> 5) & VM_COLOR_GREEN) | (interp_r >> 11);
        }
    }

	scaled_interlace_count = !scaled_interlace_count;
}

// Nearest neighbor version
void scale_nearest() {
	int begin = config->interlace ? scaled_interlace_count : 0;
	int step = 1 + config->interlace;

    for (int y = begin; y < 216; y += step) {
        for (int x = 0; x < 240; x++) {
            ((VMUINT16 *)canvas_buf)[y*240 + x] = ((VMUINT16 *)scale_buf)[(y*2/3)*160 + (x*2/3)];
        }
    }

	scaled_interlace_count = !scaled_interlace_count;
}

void draw_emu() {
    gb_run_frame(gb);
    gb_run_frame(gb);
	if (fast_forward) {
		int interlace_count = gb->display.interlace_count;
		gb->display.lcd_draw_line = lcd_draw_line_stub;
		gb_run_frame(gb);
    	gb_run_frame(gb);
		gb->display.lcd_draw_line = lcd_draw_line;
		gb->display.interlace_count = interlace_count;
	}

	if (config->scale == SCALE_1_5X_NEAREST) scale_nearest();

	else if (config->scale == SCALE_1_5X_BILINEAR) {
		// If using the grayscale palette and not in GBC mode, use a faster algorithm
		#if PEANUT_FULL_GBC_SUPPORT
			if (config->palette_choice == 0 && !gb->cgb.cgbMode) scale_bilinear_gray();
		#else
			if (config->palette_choice == 0) scale_bilinear_gray();
		#endif
		else scale_bilinear();
	}

    vm_graphic_flush_layer(layer_hdl, 2);
	if (config->audio) audio_update();

    if (config->show_fps) {
		int timepoint = vm_get_tick_count();
		fps_count++;
		
		if(timepoint - fps_timepoint >= 1000){
			fps_timepoint = timepoint;
			fps = fps_count;
			fps_count = 0;
		}

		color.vm_color_565 = VM_COLOR_BLACK;
		vm_graphic_setcolor(&color);
		vm_graphic_fill_rect_ex(layer_hdl[0], 1, 1, 50, vm_graphic_get_character_height());

		color.vm_color_565 = VM_COLOR_WHITE;
		vm_graphic_setcolor(&color);

        sprintf(fps_str, "%d", fps);
        vm_ascii_to_ucs2(ucs2_str, 256, fps_str);
		vm_graphic_textout_to_layer(layer_hdl[0], 1, 1, ucs2_str, 256);
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

			else if (keycode == config->key_fast_forward) fast_forward = !fast_forward;
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
	gb = gx_calloc(sizeof (struct gb_s));
	if (!gb) return;
	log_write("Allocated GB state");
	
	load_config();
	gb->direct.interlace = config->interlace;
}

void load_rom(char *filename) {
	init_emu();

	// Load ROM data
	if (rom_data) {
		free(rom_data);
		rom_data = 0;
	}
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
	if (cart_ram) {
		free(cart_ram);
		cart_ram = 0;
	}
	if (vm_file_get_attributes(ucs2_str) != -1) {
		log_write("Save file found, loading it");
		read_from_file_to_addr(save_name, (void **)&cart_ram);
		if (!cart_ram) return;
	} else {
		if (gb_get_save_size(gb)) {
			log_write("Save file not found, creating it");
			cart_ram = gx_calloc(gb_get_save_size(gb));
			if (!cart_ram) return;
		} else {
			log_write("This game doesn't use save data");
		}
	}
	log_write("Loaded/created save file");

    set_state(ST_RUNNING);
}