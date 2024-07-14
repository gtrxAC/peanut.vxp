#pragma once
#include "audio_midi.h"
#include "audio_bitstream.h"

uint8_t audio_read(const uint16_t addr);
void audio_write(const uint16_t addr, const uint8_t val);
void audio_update();