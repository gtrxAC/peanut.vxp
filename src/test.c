/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

#include "vmsys.h"
#include "vmio.h"
#include "vmgraph.h"
#include "vmchset.h"
#include "vmstdlib.h"
#include "vmtimer.h"
// #include "ResID.h"
#include "vm4res.h"

#define ENABLE_LCD 1
#include "peanut_gb.h"

#include "rom.h"

/* ---------------------------------------------------------------------------
* global variables
* ------------------------------------------------------------------------ */

/* define this macro if application support background running. */
// #define		SUPPORT_BG		


VMINT		layer_hdl[1];	/* layer handle array. */

struct gb_s *gb;
VMINT16 filename_ucs2[32];
VMFILE rom;
VMUINT read_result, read_unused;

VMUINT8 gray_level;
vm_graphic_color color;

int framecount;
#define FRAMESKIP 9

// const VMUINT palette[4] = {0x7FFF, 0x5294, 0x294A, 0x0000};
vm_graphic_color palette[4];

// VMUINT16 framebuf[144][160];

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
	if (framecount % FRAMESKIP) return;
	for (int i = 0; i < 160; i++) {
		// framebuf[line][i] = palette[pixels[i] & 3];
		vm_graphic_setcolor(&palette[pixels[i] & 3]);
		vm_graphic_set_pixel_ex(layer_hdl[0], i, line);
	}
}

void draw_frame(VMINT tid) {
	// color.vm_color_565 = VM_COLOR_BLACK;
	// vm_graphic_setcolor(&color);
	
	// /* fill rect with screen color */
	// vm_graphic_fill_rect_ex(layer_hdl[0], 0, 0, vm_graphic_get_screen_width(), vm_graphic_get_screen_height());

	// char tick[32];
	// VMSHORT tick_ucs2[64];

	// color.vm_color_565 = VM_COLOR_RED;
	// vm_graphic_setcolor(&color);
	// sprintf(tick, "%d", vm_get_tick_count());
	// vm_ascii_to_ucs2(tick_ucs2, 64, tick);
	// vm_graphic_textout_to_layer(layer_hdl[0], 0, 160, tick_ucs2, 64);

	// Run emulator for one frame
	gb_run_frame(gb);
	
	// sprintf(tick, "%d", vm_get_tick_count());
	// vm_ascii_to_ucs2(tick_ucs2, 64, tick);
	// vm_graphic_textout_to_layer(layer_hdl[0], 0, 180, tick_ucs2, 64);

	/* flush the screen with text data */
	if (framecount % FRAMESKIP == 0) {
		// vm_graphic_draw_image_from_memory(layer_hdl[0], 0, 0, (VMUINT8 *) framebuf, 46080);
		vm_graphic_flush_layer(layer_hdl, 1);
	}

	framecount++;
}

/*
* entry
*/
void vm_main(void) {
	/* initialize layer handle */
	layer_hdl[0] = -1;	

	// Init emulator
	gb = malloc(sizeof (struct gb_s));
	gb_init(gb, gb_rom_read, gb_cart_ram_read, gb_cart_ram_write, gb_error, NULL);
	gb_init_lcd(gb, lcd_draw_line);

	// Frameskip
	// gb->direct.interlace = 1;

	vm_switch_power_saving_mode(turn_off_mode);

	// Open ROM file (gb_rom_read reads bytes from it as needed)
	// vm_ascii_to_ucs2(filename_ucs2, 32, "e:\\mre\\rom.gb");
	// vm_file_open(filename_ucs2, MODE_READ, 1);
	
	// Register MRE event handlers
	vm_reg_sysevt_callback(handle_sysevt);
	vm_reg_keyboard_callback(handle_keyevt);
	vm_reg_pen_callback(handle_penevt);
	vm_create_timer(17, draw_frame);

	// Init color array
	palette[0].vm_color_565 = 0x7FFF;
	palette[1].vm_color_565 = 0x5294;
	palette[2].vm_color_565 = 0x294A;
	palette[3].vm_color_565 = 0x0000;

	/* Init MRE resource */
	vm_res_init();
}

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
		break;
		
	case VM_MSG_PAINT: {
		// draw_frame(0);
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
		case VM_KEY_EVENT_DOWN: case VM_KEY_EVENT_LONG_PRESS: case VM_KEY_EVENT_REPEAT: {
			switch (keycode) {
				case VM_KEY_UP: gb->direct.joypad_bits.up = 1; break;
				case VM_KEY_LEFT: gb->direct.joypad_bits.left = 1; break;
				case VM_KEY_DOWN: gb->direct.joypad_bits.down = 1; break;
				case VM_KEY_RIGHT: gb->direct.joypad_bits.right = 1; break;
				case VM_KEY_RIGHT_SOFTKEY: gb->direct.joypad_bits.a = 1; break;
				case VM_KEY_LEFT_SOFTKEY: gb->direct.joypad_bits.b = 1; break;
				case VM_KEY_STAR: gb->direct.joypad_bits.select = 1; break;
				case VM_KEY_POUND: gb->direct.joypad_bits.start = 1; break;
			}
			break;
		}

		case VM_KEY_EVENT_UP: {
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

		default: break;
	}
}

void handle_penevt(VMINT event, VMINT x, VMINT y)
{
	/* touch and return*/
	if( layer_hdl[0] != -1 )
	{
		vm_graphic_delete_layer(layer_hdl[0]);
		layer_hdl[0] = -1;
	}
	
	vm_exit_app();		/* quit application */
}