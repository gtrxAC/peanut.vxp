#define PEANUT_GB_HEADER_ONLY
#include "audio_bitstream.h"
#include "minigb_apu.h"
#include "vmmm.h"

PCM *pcm = 0;
uint8_t *ring_buf = 0;
uint8_t audio_buf[AUDIO_BUF_SIZE]; // temporally here, todo move to vm_malloc

extern int fps;

uint8_t audio_bitstream_read(const uint16_t addr){
    return audio_apu_read(addr);
}

void audio_bitstream_write(const uint16_t addr, const uint8_t val){
    audio_apu_write(addr, val);
}
 
F_ADR(PCM*,PCM_Open,(PCM_handle_t handler, PCM_Param *param),0x00000000);

static void injector(){ // Warning: May cause reboot after activation
    const int magic_len = 12;
    const unsigned char PCM_Strm_Open_magic[] = {0x70, 0xB5, 0x06, 0x00, 0x0D, 0x00, 0x00, 0x22, 0x11, 0x00, 0x1C, 0x20};

    for(int i = 0; i < 0x1000000; i += 4){
        unsigned char* adr = (((unsigned int)vm_get_sym_entry)&(0xFF000000)) + i;
        int j = 0;
        for(; j < magic_len; ++j)
            if(adr[j] != PCM_Strm_Open_magic[j])
                break;

        if(j == magic_len){
            PCM_Open = (((unsigned int)adr)|1);
            break;
        }
    }
}

void PCM_handler(PCM *handle, PCM_Event event){}

void audio_bitstream_init(){
    if(!PCM_Open)
        injector();

    if(pcm)
        return;

    vm_midi_stop_all(); // Stop all audio things
	vm_audio_suspend_bg_play();
	vm_audio_stop(0);

    static PCM_Param pcmParam;
    pcmParam.isStereo = TRUE;
    pcmParam.bitPerSample = 16;
    pcmParam.sampleFreq = AUDIO_SAMPLE_RATE;
    pcmParam.forceVoice = FALSE;

    pcm = PCM_Open(PCM_handler, &pcmParam); // Warning: May cause reboot after activation

    ring_buf = (uint8_t*)vm_malloc(RING_BUFFER_SIZE);

    if(!ring_buf){
        pcm->Close(pcm);
        pcm = 0;
        return;
    }

    pcm->SetBuffer(pcm, ring_buf, RING_BUFFER_SIZE);

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
        return;
    }
}

static void audio_bitstream_put_buffer(uint8_t* buf, uint32_t buf_size, uint32_t *used_size)
{
    uint8_t *pcm_buf = 0;
    uint32_t pcm_bufsize = 0;
    uint32_t used_len = 0;
    
    pcm->GetWriteBuffer(pcm, &pcm_buf, &pcm_bufsize); 

    if(pcm_bufsize == 0)
        return;

    if(pcm_bufsize >= buf_size){
        memcpy(pcm_buf, buf, buf_size);
        pcm->WriteDataDone(pcm, buf_size);
        used_len = buf_size;
    }
    else {
        memcpy(pcm_buf, buf, pcm_bufsize);
        pcm->WriteDataDone(pcm, pcm_bufsize);
        used_len = pcm_bufsize;        

        pcm->GetWriteBuffer(pcm, &pcm_buf, &pcm_bufsize); 

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
    if(!pcm)
        return;

    int free_ring_space = pcm->GetFreeSpace(pcm);
    int in_ring_buf = RING_BUFFER_SIZE - free_ring_space;

    if(free_ring_space < AUDIO_BUF_SIZE) // Data starts to break when the buffer is almost full, so it's better to skip
        return;

    int a_fps = fps;

    if(a_fps<10)
        a_fps = 10;
    else if (a_fps>60)
        a_fps = 60;

    int avg_audio_samples = AUDIO_SAMPLE_RATE / a_fps;

    int next_audio_size = avg_audio_samples * 4 * 105 / 100;

    if(next_audio_size < in_ring_buf)
        return;

    int audio_size = next_audio_size - in_ring_buf;

    if(audio_size>AUDIO_BUF_SIZE)
        return;

    audio_size&=~0b11l;

    audio_apu_callback(0, audio_buf, audio_size);

    audio_bitstream_put_buffer(audio_buf, audio_size, 0);

    pcm->Play(pcm);
}