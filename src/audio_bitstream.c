#define PEANUT_GB_HEADER_ONLY
#include "audio_bitstream.h"
#include "minigb_apu.h"
#include "vmmm.h"

PCM *pcm = 0;
uint8_t *ring_buf = 0;
uint8_t *audio_buf = 0;

extern int fps; // get fps value from emu.c

uint8_t audio_bitstream_read(const uint16_t addr){
    return audio_apu_read(addr);
}

void audio_bitstream_write(const uint16_t addr, const uint8_t val){
    audio_apu_write(addr, val);
}

typedef PCM *(*PCM_Open_t)(PCM_handle_t handler, PCM_Param *param);
PCM_Open_t PCM_Open = 0x00000000;

// Scaning phone firmare for PCM_Open entry point by magic value. Warning: May cause fatal error (reboot) after activation
static void injector(){ 
    const int magic_len = 12;
    const unsigned char PCM_Open_magic[] = {0x70, 0xB5, 0x06, 0x00, 0x0D, 0x00, 0x00, 0x22, 0x11, 0x00, 0x1C, 0x20};

    for(int i = 0; i < 0x1000000; i += 4){
        unsigned char* adr = (((unsigned int)vm_get_sym_entry)&(0xFF000000)) + i;
        int j = 0;
        for(; j < magic_len; ++j)
            if(adr[j] != PCM_Open_magic[j])
                break;

        if(j == magic_len){
            PCM_Open = (((unsigned int)adr)|1);
            break;
        }
    }
}

void PCM_handler(PCM *handle, PCM_Event event){}

void audio_bitstream_init(){
    if(!PCM_Open) // If PCM_Open is unknown, try to find
        injector();

    if(!PCM_Open)// If PCM_Open still unknown than return
        return;

    if(pcm) // if PCM alredy created return
        return;

    // Stop all audio things, otherwise a fatal error may occur 
    vm_midi_stop_all(); 
	vm_audio_suspend_bg_play();
	vm_audio_stop(0);

    static PCM_Param pcmParam;
    pcmParam.isStereo = TRUE;
    pcmParam.bitPerSample = 16;
    pcmParam.sampleFreq = AUDIO_SAMPLE_RATE; // See vmbitstream.h to find alowed values 
    pcmParam.forceVoice = FALSE;

    pcm = PCM_Open(PCM_handler, &pcmParam); // Warning: May cause fatal error (reboot) after activation

    ring_buf = (uint8_t*)vm_malloc(RING_BUFFER_SIZE); 

    if(!ring_buf){
        pcm->Close(pcm);
        pcm = 0;
        return;
    }

    pcm->SetBuffer(pcm, ring_buf, RING_BUFFER_SIZE);

    audio_buf = (uint8_t*)vm_malloc(AUDIO_BUF_SIZE);

    if(!audio_buf){
        pcm->Close(pcm);
        pcm = 0;
        vm_free(ring_buf);
        ring_buf = 0;
        return;
    }
    // Init apu
    audio_apu_init();
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
    }
    if(audio_buf){
        vm_free(audio_buf);
        audio_buf = 0;
    }
}

static void audio_bitstream_put_buffer(uint8_t* buf, uint32_t buf_size, uint32_t *used_size){
    uint8_t *pcm_buf = 0;
    uint32_t pcm_bufsize = 0;
    uint32_t used_len = 0;
    
    pcm->GetWriteBuffer(pcm, &pcm_buf, &pcm_bufsize); // Get buffer pointer and allow size

    if(pcm_bufsize == 0) // overflow
        return;

    if(pcm_bufsize >= buf_size){ // If all data fits
        memcpy(pcm_buf, buf, buf_size);
        pcm->WriteDataDone(pcm, buf_size); // Inform about wroten data
        used_len = buf_size;
    }
    else {
        memcpy(pcm_buf, buf, pcm_bufsize);
        pcm->WriteDataDone(pcm, pcm_bufsize);
        used_len = pcm_bufsize;        

        pcm->GetWriteBuffer(pcm, &pcm_buf, &pcm_bufsize); // Again, because it is ring buffer

        if(pcm_bufsize > 0){
            if(pcm_bufsize >= (buf_size - used_len)){
                memcpy(pcm_buf, (buf+used_len), (buf_size - used_len));
                pcm->WriteDataDone(pcm, (buf_size - used_len));
                used_len = buf_size;
            }
            else{
                memcpy(pcm_buf, (buf+used_len), pcm_bufsize);
                pcm->WriteDataDone(pcm, pcm_bufsize);
                used_len += pcm_bufsize;
            }
        }
    }
    if(used_size)
        *(used_size) = used_len;
}

void audio_bitstream_update(){
    if(!pcm) // if PCM hasn`t created than return
        return;

    // Get free and used space in ring buffer
    int free_space_in_ring = pcm->GetFreeSpace(pcm);
    int used_space_in_ring = RING_BUFFER_SIZE - free_space_in_ring;

    int a_fps = fps;
    if(a_fps < 10) // Limiting FPS values ​​to prevent bad values
        a_fps = 10;
    else if (a_fps > 30)
        a_fps = 30;

    // Calculate average sample rate based on current FPS 
    int avg_audio_sample_rate = AUDIO_SAMPLE_RATE / a_fps;
    // Count the number of samples for the next frame (average + 5%)
    int next_audio_samples_count = avg_audio_sample_rate * 105 / 100;
    int next_audio_frame_size = next_audio_samples_count * 4;

    // If there is already more data in the ring than needed, then we skip it
    if(next_audio_frame_size < used_space_in_ring)
        return;

    // Calculate how many data we need to add to ring
    int need_audio_frame_size = next_audio_frame_size - used_space_in_ring;

    // Limit to audio buffer
    if(need_audio_frame_size > AUDIO_BUF_SIZE)
        need_audio_frame_size = AUDIO_BUF_SIZE;

    // Correction of multiple of size (to 4)
    need_audio_frame_size&=~0b11l;

    // Get audio frame from apu
    audio_apu_callback(0, audio_buf, need_audio_frame_size);
    // Put data to pcm
    audio_bitstream_put_buffer(audio_buf, need_audio_frame_size, 0);

    // Play data
    pcm->Play(pcm);
}