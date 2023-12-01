#pragma once
#include "common.h"

void set_message(char *msg);

VMUINT8 gb_rom_read(struct gb_s *gb, const uint_fast32_t addr);
VMUINT8 gb_cart_ram_read(struct gb_s *gb, const uint_fast32_t addr);
void gb_cart_ram_write(struct gb_s *gb, const uint_fast32_t addr, const uint8_t val);
void gb_error(struct gb_s* gb, const enum gb_error_e err, const uint16_t addr);
void lcd_draw_line(struct gb_s *gb, const uint8_t pixels[160], const unsigned int line);

void draw_emu();

void handle_keyevt_emu(VMINT event, VMINT keycode);

void load_rom(char *filename);