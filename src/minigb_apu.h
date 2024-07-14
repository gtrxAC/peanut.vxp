/**
* Copyright (c) 2017 Alex Baines <alex@abaines.me.uk>
* Copyright (c) 2019 Mahyar Koshkouei <mk@deltabeard.com>

* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:

* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.

* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.

* minigb_apu emulates the audio processing unit (APU) of the Game Boy. This
* project is based on MiniGBS by Alex Baines: https://github.com/baines/MiniGBS
**/

#pragma once

#include <stdint.h>

#define AUDIO_SAMPLE_RATE	32768

#define DMG_CLOCK_FREQ		4194304.0
#define SCREEN_REFRESH_CYCLES	70224.0
#define VERTICAL_SYNC		(DMG_CLOCK_FREQ/SCREEN_REFRESH_CYCLES)

#define AUDIO_SAMPLES		((unsigned)(AUDIO_SAMPLE_RATE / VERTICAL_SYNC))

/**
 * Fill allocated buffer "data" with "len" number of 32-bit floating point
 * samples (native endian order) in stereo interleaved format.
 */
void audio_apu_callback(void *ptr, uint8_t *data, int len);

/**
 * Read audio register at given address "addr".
 */
uint8_t audio_apu_read(const uint16_t addr);

/**
 * Write "val" to audio register at given address "addr".
 */
void audio_apu_write(const uint16_t addr, const uint8_t val);

/**
 * Initialise audio driver.
 */
void audio_apu_init(void);
