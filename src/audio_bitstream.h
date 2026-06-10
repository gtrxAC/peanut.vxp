#pragma once
#include "audio_midi.h"

uint8_t audio_bitstream_read(const uint16_t addr);
void audio_bitstream_write(const uint16_t addr, const uint8_t val);
void audio_bitstream_update();

void audio_bitstream_init();
void audio_bitstream_deinit();

#define AUDIO_BUF_SIZE (AUDIO_SAMPLES_TOTAL * 2 * 4)