#include "injected_bitstream.h"
#include <vmmm.h>

typedef PCM* (*PCM_Open_t)(PCM_handle_t handler, PCM_Param* param);
static PCM_Open_t PCM_Open = 0x00000000;

static PCM* pcm = 0;
static VMUINT8* ring_buf = 0;

const int RING_BUFFER_SIZE = 1024 * 8;

// Scaning phone firmare for PCM_Open entry point by magic value. Warning: May cause fatal error (reboot) after activation
static void injector() {
    const int magic_len = 12;
    const unsigned char PCM_Open_magic[] = { 0x70, 0xB5, 0x06, 0x00, 0x0D, 0x00, 0x00, 0x22, 0x11, 0x00, 0x1C, 0x20 };

    for (int i = 0; i < 0x1000000; i += 4) {
        unsigned char* adr = (((unsigned int)vm_get_sym_entry) & (0xFF000000)) + i;
        int j = 0;
        for (; j < magic_len; ++j)
            if (adr[j] != PCM_Open_magic[j])
                break;

        if (j == magic_len) {
            PCM_Open = (((unsigned int)adr) | 1);
            break;
        }
    }
}

int injected_bitstream_init(PCM_Param* pcmParam, PCM_handle_t handle) {
    if (!PCM_Open) // If PCM_Open is unknown, try to find
        injector();

    if (!PCM_Open)// If PCM_Open still unknown than return
        return 1;

    if (pcm) // if PCM alredy created return
        return 1;

    // Stop all audio things, otherwise a fatal error may occur 
    vm_midi_stop_all();
    vm_audio_suspend_bg_play();
    vm_audio_stop(0);

    pcm = PCM_Open(handle, pcmParam); // Warning: May cause fatal error (reboot) after activation

    ring_buf = (VMUINT8*)vm_malloc(RING_BUFFER_SIZE);

    if (!ring_buf) {
        pcm->Close(pcm);
        pcm = 0;
        return 1;
    }

    pcm->SetBuffer(pcm, ring_buf, RING_BUFFER_SIZE);

    //pcm->SetDataRequestThreshold(pcm, PCM_DATA_COMSUME_MODE, 128, 0);
    //pcm->SetDataRequestThreshold(pcm, PCM_FREE_SPACE_MODE, 2048, 0);

    return 0;
}

void injected_bitstream_deinit() {
    if (pcm) {
        pcm->Stop(pcm);
        pcm->Close(pcm);
        pcm = 0;
    }
    if (ring_buf) {
        vm_free(ring_buf);
        ring_buf = 0;
    }
}

void injected_bitstream_put_buffer(VMUINT8* buf, VMUINT buf_size, VMUINT* written) {
    VMUINT8* pcm_buf = 0;
    VMUINT32 pcm_bufsize = 0;
    VMUINT32 used_len = 0;

    if (!pcm) return;

    pcm->GetWriteBuffer(pcm, &pcm_buf, &pcm_bufsize); // Get buffer pointer and allow size

    if (pcm_bufsize == 0) // overflow
        return;

    if (pcm_bufsize >= buf_size) { // If all data fits
        memcpy(pcm_buf, buf, buf_size);
        pcm->WriteDataDone(pcm, buf_size); // Inform about wroten data
        used_len = buf_size;
    }
    else {
        memcpy(pcm_buf, buf, pcm_bufsize);
        pcm->WriteDataDone(pcm, pcm_bufsize);
        used_len = pcm_bufsize;

        pcm->GetWriteBuffer(pcm, &pcm_buf, &pcm_bufsize); // Again, because it is ring buffer

        if (pcm_bufsize > 0) {
            if (pcm_bufsize >= (buf_size - used_len)) {
                memcpy(pcm_buf, (buf + used_len), (buf_size - used_len));
                pcm->WriteDataDone(pcm, (buf_size - used_len));
                used_len = buf_size;
            }
            else {
                memcpy(pcm_buf, (buf + used_len), pcm_bufsize);
                pcm->WriteDataDone(pcm, pcm_bufsize);
                used_len += pcm_bufsize;
            }
        }
    }
    if (written)
        *(written) = used_len;

    pcm->FinishWriteData(pcm);

    pcm->Resume(pcm);
}

void injected_bitstream_start(VMUINT start_time) {
    if (!pcm) return;
    
    pcm->SetStartTime(pcm, start_time);
    pcm->Play(pcm); 
}

void injected_bitstream_resume() {
    if (!pcm) return;
    pcm->Resume(pcm);
}

VMINT injected_bitstream_get_buffer_size() {
    return RING_BUFFER_SIZE;
}

VMINT injected_bitstream_get_free_buffer_size() {
    if (!pcm) return 0;

    return pcm->GetFreeSpace(pcm);
}