#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <vmbitstream.h>

typedef enum bitstream_events {
	BITSTREAM_EVENT_NONE,
	BITSTREAM_EVENT_DATA_REQUEST,
	BITSTREAM_EVENT_BUFFER_UNDERFLOW,
	BITSTREAM_EVENT_ERROR
};

typedef (*bitstream_callback)(enum bitstream_events event);

VMINT bitstream_open(VMBOOL isStereo, VMUINT8 bitPerSample, vm_bitstream_sample_freq_enum sampleFreq, bitstream_callback callback);
VMINT bitstream_close();
VMINT bitstream_put_data(VMUINT8* buffer, VMUINT buffer_size, VMUINT* written);
VMINT bitstream_get_free_buffer_size();
VMINT bitstream_get_buffer_size();
VMINT bitstream_get_sample_rate();
VMINT bitstream_get_queued_bytes();
VMINT bitstream_get_queued_time_ms();
VMINT bitstream_start(VMUINT start_time, VMUINT8 audio_path, VMINT volume);
VMINT bitstream_resume();
void bitstream_reset_counters();

#ifdef __cplusplus
}
#endif