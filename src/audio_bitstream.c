#define PEANUT_GB_HEADER_ONLY
#include "audio_bitstream.h"
#include "minigb_apu.h"
#include "vmmm.h"

PCM *pcm;
uint8_t *ring_buf = 0;

uint8_t audio_bitstream_read(const uint16_t addr){
    return audio_apu_read(addr);
}

void audio_bitstream_write(const uint16_t addr, const uint8_t val){
    audio_apu_write(addr, val);
}

void audio_bitstream_update(){}
 
F_ADR(PCM*,PCM_Open,(PCM_handle_t handler, PCM_Param *param),0x00000000);

static void injector(){ // Warning: May cause reboot after activation
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

void PCM_handler(PCM *handle, PCM_Event event){}

void audio_bitstream_init(){
    if(!PCM_Open)
        injector();

    vm_midi_stop_all(); // Stop all audio things
	vm_audio_suspend_bg_play();
	vm_audio_stop(0);

    static PCM_Param pcmParam;
    pcmParam.isStereo = TRUE;
    pcmParam.bitPerSample = 16;
    pcmParam.sampleFreq = AUDIO_SAMPLE_RATE;
    pcmParam.forceVoice = FALSE;

    pcm = PCM_Open(PCM_handler, &pcmParam);

    ring_buf = (uint8_t*)vm_malloc(RING_BUFFER_SIZE);

    if(!ring_buf){
        pcm->Close(pcm);
        pcm = 0;
        return;
    }

    pcm->SetBuffer(pcm, ring_buf, RING_BUFFER_SIZE);
}

void audio_bitstream_deinit(){
    if(pcm){
        pcm->Stop(pcm);
        pcm->Close(pcm);
        pcm = 0;
    }
    if(ring_buf){
        vm_free(ring_buf);
        ring_buf = 0;
        return;
    }
}