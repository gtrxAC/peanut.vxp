#pragma once
//#include "common.h"
#include "audio_midi.h"

uint8_t audio_bitstream_read(const uint16_t addr);
void audio_bitstream_write(const uint16_t addr, const uint8_t val);
void audio_bitstream_update();