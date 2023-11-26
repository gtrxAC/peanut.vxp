#include "vmsys.h"
#include "vmio.h"
#include "vmgraph.h"
#include "vmchset.h"
#include "vmstdlib.h"
#include "vmtimer.h"
#include "vm4res.h"
#include <stdio.h>

#include "fs.h"

#define ENABLE_LCD 1
#define PEANUT_GB_12_COLOUR 0
#include "peanut_gb.h"

/* ---------------------------------------------------------------------------
* global variables
* ------------------------------------------------------------------------ */

/* define this macro if application support background running. */
// #define		SUPPORT_BG		

VMINT		layer_hdl[2];	/* layer handle array. */

VMINT screen_width;
VMINT screen_height;

struct gb_s *gb;
VMUINT8 *rom_data;
VMUINT8 *rom_name;
char save_name[32];
VMUINT8 *cart_ram;

int cart_ram_has_changed;
// VMINT16 filename_ucs2[32];
// VMFILE rom;
// VMUINT read_result, read_unused;

vm_graphic_color color;

const VMUINT16 palette[4] = {0xE77C, 0x9CF0, 0x52AC, 0x20A3};
VMINT canvas;
VMUINT8 *canvas_buf;

/* ---------------------------------------------------------------------------
 * local variables
 * ------------------------------------------------------------------------ */
/*
* system events 
*/
void handle_sysevt(VMINT message, VMINT param);
void handle_keyevt(VMINT event, VMINT keycode);
void handle_penevt(VMINT event, VMINT x, VMINT y);

VMUINT8 gb_rom_read(struct gb_s *gb, const uint_fast32_t addr) {
	// vm_file_seek(rom, addr, BASE_BEGIN);
	// vm_file_read(rom, &read_result, 1, &read_unused);
	// return read_result;
	return rom_data[addr];
}

VMUINT8 gb_cart_ram_read(struct gb_s *gb, const uint_fast32_t addr) {
	return cart_ram[addr];
}

void gb_cart_ram_write(struct gb_s *gb, const uint_fast32_t addr, const uint8_t val) {
	cart_ram[addr] = val;
	cart_ram_has_changed = 1;  // mark cart ram to be written to file next frame
}

void gb_error(struct gb_s* gb, const enum gb_error_e err, const uint16_t addr) {}

void lcd_draw_line(struct gb_s *gb, const uint8_t pixels[160], const unsigned int line) {
	for (int i = 0; i < 160; i++) {
		((VMUINT16 *)canvas_buf)[160*line + i] = palette[pixels[i]];
	}
}

VMINT16 message[32];
int message_timer;

void set_message(char *msg) {
	vm_ascii_to_ucs2(message, 32, msg);
	message_timer = 60;

	color.vm_color_565 = VM_COLOR_BLACK;
	vm_graphic_setcolor(&color);
	vm_graphic_fill_rect_ex(layer_hdl[0], 0, 0, screen_width, 24);
	color.vm_color_565 = 0xF7F0;
	vm_graphic_setcolor(&color);
	vm_graphic_textout_to_layer(layer_hdl[0], 2, 2, message, 64);
}

int show_fps;
int tick;
char fps_str[32];

void draw_frame(VMINT tid) {
	if (show_fps) tick = vm_get_tick_count();

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
		sprintf(fps_str, "%d fps", (int) 1000 / (vm_get_tick_count() - tick));
		set_message(fps_str);
	}

	if (cart_ram_has_changed) {
		write_from_addr_to_file(save_name, cart_ram, gb_get_save_size(gb));
		cart_ram_has_changed = 0;
	}
}

/*
* entry
*/
void vm_main(void) {
	log_init();
	log_write("Started logging");
	
	/* initialize layer handle */
	layer_hdl[0] = -1;
	layer_hdl[1] = -1;

	// Allocate emulator, load ROM data
	gb = malloc(sizeof (struct gb_s));
	log_write("Allocated GB state");
	read_from_file_to_addr("rom.gb", (void **)&rom_data);
	log_write("Loaded ROM");

	// Init emulator
	gb_init(gb, gb_rom_read, gb_cart_ram_read, gb_cart_ram_write, gb_error, NULL);
	gb_init_lcd(gb, lcd_draw_line);
	log_write("Initialized emulator");

	rom_name = malloc(16);
	rom_name = (char *)gb_get_rom_name(gb, rom_name);
	sprintf(save_name, "save_%s.sav", rom_name);
	log_write("Created save file name");

	VMCHAR save_name_full[64];
	sprintf(save_name_full, "e:\\peanutvxp\\%s", save_name);
	VMWCHAR save_name_ucs2[64];
	vm_ascii_to_ucs2(save_name_ucs2, 128, save_name_full);
	log_write("Created save file full name");

	if (vm_file_get_attributes(save_name_ucs2) != -1) {
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

	// Frameskip
	// gb->direct.interlace = 1;
	gb->direct.frame_skip = 1;

	vm_switch_power_saving_mode(turn_off_mode);
	vm_graphic_set_font(VM_SMALL_FONT);
	log_write("Set runtime parameters");

	// Open ROM file (gb_rom_read reads bytes from it as needed)
	// vm_ascii_to_ucs2(filename_ucs2, 32, "e:\\mre\\rom.gb");
	// vm_file_open(filename_ucs2, MODE_READ, 1);
	
	// Register MRE event handlers
	vm_reg_sysevt_callback(handle_sysevt);
	vm_reg_keyboard_callback(handle_keyevt);
	vm_reg_pen_callback(handle_penevt);
	vm_create_timer(33, draw_frame);
	log_write("Created event handlers. Running.");

	/* Init MRE resource */
	vm_res_init();
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
		
		/* Release all resource */
		vm_res_deinit();
		break;	
	}
}

void handle_keyevt(VMINT event, VMINT keycode) {
	switch (event) {
		case VM_KEY_EVENT_DOWN: {
			switch (keycode) {
				case VM_KEY_UP: case VM_KEY_NUM2: gb->direct.joypad_bits.up = 0; break;
				case VM_KEY_LEFT: case VM_KEY_NUM4: gb->direct.joypad_bits.left = 0; break;
				case VM_KEY_DOWN: case VM_KEY_NUM8: gb->direct.joypad_bits.down = 0; break;
				case VM_KEY_RIGHT: case VM_KEY_NUM6: gb->direct.joypad_bits.right = 0; break;
				case VM_KEY_RIGHT_SOFTKEY: case VM_KEY_NUM5: gb->direct.joypad_bits.a = 0; break;
				case VM_KEY_LEFT_SOFTKEY: gb->direct.joypad_bits.b = 0; break;
				case VM_KEY_STAR: gb->direct.joypad_bits.select = 0; break;
				case VM_KEY_POUND: gb->direct.joypad_bits.start = 0; break;

				case VM_KEY_NUM0:
					gb_reset(gb);
					set_message("Reset");
					break;

				case VM_KEY_NUM1:
					gb->direct.interlace = !gb->direct.interlace;
					set_message(gb->direct.interlace ? "Interlace ON" : "Interlace OFF");
					break;

				case VM_KEY_NUM9:
					gb->direct.frame_skip = !gb->direct.frame_skip;
					set_message(gb->direct.frame_skip ? "Frameskip ON" : "Frameskip OFF");
					break;

				case VM_KEY_NUM7:
					show_fps = !show_fps;
					message_timer = 0;
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

void handle_penevt(VMINT event, VMINT x, VMINT y)
{
}