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

 
F_ADR(PCM*,PCM_Open,(PCM_handle_t handler, void *param),0x00000000);

void injector(){
    if(PCM_Open)
        return;

    const unsigned char PCM_Strm_Open_magic[12] = {0x70, 0xB5, 0x06, 0x00, 0x0D, 0x00, 0x00, 0x22, 0x11, 0x00, 0x1C, 0x20};

    for(int i=0; i<0x1000000; i+=4){
        unsigned char* adr = (((unsigned int)vm_get_sym_entry)&(0xFF000000)) + i;
        for(int j=0; j<12; ++j)
            if(adr[j] != PCM_Strm_Open_magic[j])
                continue;
        PCM_Open = (((unsigned int)adr)|1);
        break;
    }
}