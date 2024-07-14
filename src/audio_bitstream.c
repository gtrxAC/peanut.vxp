#define PEANUT_GB_HEADER_ONLY
#include "audio_bitstream.h"
#include "minigb_apu.h"

uint8_t audio_bitstream_read(const uint16_t addr){
    return audio_apu_read(addr);
}

void audio_bitstream_write(const uint16_t addr, const uint8_t val){
    audio_apu_write(addr, val);
}
void audio_bitstream_update(){}