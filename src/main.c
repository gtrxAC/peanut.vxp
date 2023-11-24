#include "vmsys.h"
#include "vmio.h"
#include "vmgraph.h"
#include "vmchset.h"
#include "vmstdlib.h"
#include "vmtimer.h"
#include "vm4res.h"

#define ENABLE_LCD 1
#define PEANUT_GB_12_COLOUR 0
#include "peanut_gb.h"

#include "rom.h"

/* ---------------------------------------------------------------------------
* global variables
* ------------------------------------------------------------------------ */

/* define this macro if application support background running. */
// #define		SUPPORT_BG		

VMINT		layer_hdl[2];	/* layer handle array. */

struct gb_s *gb;
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

/*
* key events 
*/
void handle_keyevt(VMINT event, VMINT keycode);

/*
* pen events
*/
void handle_penevt(VMINT event, VMINT x, VMINT y);

VMUINT8 gb_rom_read(struct gb_s *gb, const uint_fast32_t addr) {
	// vm_file_seek(rom, addr, BASE_BEGIN);
	// vm_file_read(rom, &read_result, 1, &read_unused);
	// return read_result;
	return rom_data[addr];
}

VMUINT8 gb_cart_ram_read(struct gb_s *gb, const uint_fast32_t addr) {}
void gb_cart_ram_write(struct gb_s *gb, const uint_fast32_t addr, const uint8_t val) {}
void gb_error(struct gb_s* gb, const enum gb_error_e err, const uint16_t addr) {}

void lcd_draw_line(struct gb_s *gb, const uint8_t pixels[160], const unsigned int line) {
	for (int i = 0; i < 160; i++) {
		((VMUINT16 *)canvas_buf)[160*line + i] = palette[pixels[i]];
	}
}

char fps_str[16];
VMSHORT fps_str_ucs2[32];

void draw_frame(VMINT tid) {
	// VMINT tickcount = vm_get_tick_count(); 
	gb_run_frame(gb);

	// color.vm_color_565 = VM_COLOR_BLACK;
	// vm_graphic_setcolor(&color);
	// vm_graphic_fill_rect_ex(layer_hdl[0], 0, 144, 160, 24);

	// sprintf(fps_str, "%d fps", 1000 / (vm_get_tick_count() - tickcount));
	// vm_ascii_to_ucs2(fps_str_ucs2, 64, fps_str);

	// color.vm_color_565 = VM_COLOR_WHITE;
	// vm_graphic_setcolor(&color);
	// vm_graphic_textout_to_layer(layer_hdl[0], 0, 145, fps_str_ucs2, 32);

	vm_graphic_flush_layer(layer_hdl, 2);
}

/*
* entry
*/
void vm_main(void) {
	/* initialize layer handle */
	layer_hdl[0] = -1;
	layer_hdl[1] = -1;

	// Init emulator
	gb = malloc(sizeof (struct gb_s));
	gb_init(gb, gb_rom_read, gb_cart_ram_read, gb_cart_ram_write, gb_error, NULL);
	gb_init_lcd(gb, lcd_draw_line);

	// Frameskip
	// gb->direct.interlace = 1;
	gb->direct.frame_skip = 1;

	vm_switch_power_saving_mode(turn_off_mode);

	// Open ROM file (gb_rom_read reads bytes from it as needed)
	// vm_ascii_to_ucs2(filename_ucs2, 32, "e:\\mre\\rom.gb");
	// vm_file_open(filename_ucs2, MODE_READ, 1);
	
	// Register MRE event handlers
	vm_reg_sysevt_callback(handle_sysevt);
	vm_reg_keyboard_callback(handle_keyevt);
	vm_reg_pen_callback(handle_penevt);
	vm_create_timer(17, draw_frame);

	/* Init MRE resource */
	vm_res_init();
}

vm_graphic_color_argb * canvas_trans_color;

void handle_sysevt(VMINT message, VMINT param) {
	switch (message) {
	case VM_MSG_CREATE:	/* the message of creation of application */
	case VM_MSG_ACTIVE: /* the message of application state from inactive to active */
		/*cerate base layer that has same size as the screen*/
		layer_hdl[0] = vm_graphic_create_layer(0, 0, 
			vm_graphic_get_screen_width(),		/* get screen width */
			vm_graphic_get_screen_height(),		/* get screen height */
			-1);		/* -1 means layer or canvas have no transparent color */
		
		/* set clip area*/
		vm_graphic_set_clip(0, 0, 
			vm_graphic_get_screen_width(), 
			vm_graphic_get_screen_height());

		canvas = vm_graphic_create_canvas_cf(VM_GRAPHIC_COLOR_FORMAT_16, 160, 144);
		canvas_buf = vm_graphic_get_canvas_buffer(canvas) + VM_CANVAS_DATA_OFFSET;
		layer_hdl[1] = vm_graphic_create_layer_cf(
			VM_GRAPHIC_COLOR_FORMAT_16, 0, 0, 160, 144, VM_NO_TRANS_COLOR,
			VM_BUF, canvas_buf, 160*144*2
		);
		break;
		
	case VM_MSG_PAINT: {
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
				case VM_KEY_UP: gb->direct.joypad_bits.up = 0; break;
				case VM_KEY_LEFT: gb->direct.joypad_bits.left = 0; break;
				case VM_KEY_DOWN: gb->direct.joypad_bits.down = 0; break;
				case VM_KEY_RIGHT: gb->direct.joypad_bits.right = 0; break;
				case VM_KEY_RIGHT_SOFTKEY: gb->direct.joypad_bits.a = 0; break;
				case VM_KEY_LEFT_SOFTKEY: gb->direct.joypad_bits.b = 0; break;
				case VM_KEY_STAR: gb->direct.joypad_bits.select = 0; break;
				case VM_KEY_POUND: gb->direct.joypad_bits.start = 0; break;
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