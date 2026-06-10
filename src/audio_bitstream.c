#define PEANUT_GB_HEADER_ONLY
#include "audio_bitstream.h"
#include "minigb_apu.h"
#include "bitstream.h"
#include "common.h"

uint8_t *audio_buf = 0;

uint8_t audio_bitstream_read(const uint16_t addr){
    return audio_apu_read(addr);
}

void audio_bitstream_write(const uint16_t addr, const uint8_t val){
    audio_apu_write(addr, val);
}

static void bitstream_handle(enum bitstream_events event) {
    if (event != BITSTREAM_EVENT_ERROR) {
    }
}

void audio_bitstream_init(){
    VMINT res = bitstream_open(1, 16, VM_BITSTREAM_SAMPLE_FREQ_32000, bitstream_handle);

    audio_buf = (uint8_t*)vm_malloc(AUDIO_BUF_SIZE);

    // Init apu
    audio_apu_init();

    memset(audio_buf, 0, AUDIO_BUF_SIZE);
    bitstream_put_data(audio_buf, AUDIO_BUF_SIZE, 0);

    bitstream_start(0, 0, config->audio_volume);
}

void audio_bitstream_deinit(){
    bitstream_close();
    if(audio_buf){
        vm_free(audio_buf);
        audio_buf = 0;
    }
}

#define FRAME_AUDIO_SIZE (AUDIO_SAMPLES_TOTAL * 2)
#define MAX_QUEUED_BYTES (FRAME_AUDIO_SIZE * 3)

void audio_bitstream_update() {
    int play_buf_size = bitstream_get_free_buffer_size();
    int queued_bytes = bitstream_get_queued_bytes();

    if (play_buf_size > AUDIO_BUF_SIZE)
        play_buf_size = AUDIO_BUF_SIZE;

    if (play_buf_size > MAX_QUEUED_BYTES - queued_bytes)
        play_buf_size = MAX_QUEUED_BYTES - queued_bytes;

    if (play_buf_size < 0)
        play_buf_size = 0;

    play_buf_size &= ~0b11l;

    if (play_buf_size) {
        // Get audio frame from apu
        audio_apu_callback(0, audio_buf, play_buf_size);
        // Put data to pcm
        bitstream_put_data(audio_buf, play_buf_size, 0);
    }
}