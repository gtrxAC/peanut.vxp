#define PEANUT_GB_HEADER_ONLY
#include "audio.h"

uint8_t audio_read(const uint16_t addr){
    switch (config->audio)
    {
    case AUDIO_MIDI:
        return audio_midi_read(addr);
        break;
    case AUDIO_BITSTREAM:
        return audio_bitstream_read(addr);
        break;
    case AUDIO_OFF:
    default:
        return 0;
        break;
    }
}
void audio_write(const uint16_t addr, const uint8_t val){
    switch (config->audio)
    {
    case AUDIO_MIDI:
        audio_midi_write(addr, val);
        break;
    case AUDIO_BITSTREAM:
        audio_bitstream_write(addr, val);
        break;
    case AUDIO_OFF:
    default:
        break;
    }
}


void audio_update(){
    switch (config->audio)
    {
    case AUDIO_MIDI:
        audio_midi_update();
        break;
    case AUDIO_BITSTREAM:
        audio_bitstream_update();
        break;
    case AUDIO_OFF:
    default:
        break;
    }
}

void audio_init(){
    if(config->audio == AUDIO_BITSTREAM)
        audio_bitstream_init();
}

void audio_deinit(){
    if(config->audio == AUDIO_BITSTREAM)
        audio_bitstream_deinit();
}

void audio_next_conf() {
    audio_deinit();

    config->audio++;

    if (config->audio == AUDIO_COUNT) 
        config->audio = AUDIO_OFF;

    audio_init();
}
