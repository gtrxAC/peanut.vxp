#include "bitstream.h"
#include "injected_bitstream.h"
#include <vmbitstream.h>
#include <vmmm.h>

static const int sample_rate_enum_to_int[VM_BITSTREAM_SAMPLE_FREQ_TOTAL] =
{
	8000, 11025, 16000, 22050, 24000, 32000, 44100, 48000
};

static int mre_bitstream_alloved = -1;
static int mre_bitstream_handle = -1;
static int mre_bitstream_buffer_size = -1;
static int mre_bitstream_sample_rate = -1;
static bitstream_callback mre_bitstream_callback = 0;

static VMUINT32 sync_start_time = 0;
static VMUINT32 sync_total_bytes = 0;
static VMUINT32 sync_bytes_per_ms = 0;
static VMINT    sync_max_queue_bytes = 0;

static void mre_vm_bitstream_callback(VMINT handle, VMINT result) {
	enum bitstream_events event;

	switch (result) {
	case VM_BITSTREAM_EVENT_DATA_REQUEST:
		event = BITSTREAM_EVENT_DATA_REQUEST;
		break;
	case VM_BITSTREAM_EVENT_ERROR:
		event = BITSTREAM_EVENT_ERROR;
		break;
	case VM_BITSTREAM_EVENT_NONE:
	default:
		event = BITSTREAM_EVENT_NONE;
		break;
	}

	if (mre_bitstream_callback)
		mre_bitstream_callback(event);
}

static void injected_bitstream_callback(PCM* handle, PCM_Event pcm_event) {
	enum bitstream_events event;

	switch (pcm_event) {
	case PCM_DATA_REQUEST:
		event = BITSTREAM_EVENT_DATA_REQUEST;
		break;
	case PCM_BUFFER_UNDERFLOW:
		event = BITSTREAM_EVENT_BUFFER_UNDERFLOW;
		break;
	case PCM_ERROR:
		event = BITSTREAM_EVENT_ERROR;
		break;
	default:
		event = BITSTREAM_EVENT_NONE;
		break;
	}

	if (mre_bitstream_callback)
		mre_bitstream_callback(event);
}

static VMINT bitstream_sample_rate_enum_to_int(vm_bitstream_sample_freq_enum sampleFreq) {
	if ((VMUINT)sampleFreq >= VM_BITSTREAM_SAMPLE_FREQ_TOTAL)
		return 0;
	else
		return sample_rate_enum_to_int[sampleFreq];
}

VMINT bitstream_open(VMBOOL isStereo, VMUINT8 bitPerSample, vm_bitstream_sample_freq_enum sampleFreq, bitstream_callback callback) {
	if (mre_bitstream_alloved == -1)
		mre_bitstream_alloved = (vm_get_sym_entry("vm_bitstream_audio_open_pcm") != 0);

	mre_bitstream_buffer_size = -1;
	mre_bitstream_sample_rate = bitstream_sample_rate_enum_to_int(sampleFreq);
	mre_bitstream_callback = callback;

	sync_bytes_per_ms = (mre_bitstream_sample_rate * (isStereo ? 2 : 1) * (bitPerSample / 8)) / 1000;
	sync_max_queue_bytes = sync_bytes_per_ms * 60;

	if (mre_bitstream_alloved)
	{
		if (mre_bitstream_handle != -1)
			vm_bitstream_audio_close(mre_bitstream_handle);

		vm_bitstream_pcm_audio_cfg_struct settings;
		settings.vm_codec_type = VM_BITSTREAM_CODEC_TYPE_PCM;
		settings.isStereo = isStereo;
		settings.bitPerSample = bitPerSample;
		settings.sampleFreq = sampleFreq;

		return vm_bitstream_audio_open_pcm(&mre_bitstream_handle, &settings, mre_vm_bitstream_callback);
	}
	else
	{
		if (((VMUINT32)sampleFreq) >= VM_BITSTREAM_SAMPLE_FREQ_TOTAL)
			return 1;

		PCM_Param pcmParam;
		pcmParam.isStereo = isStereo;
		pcmParam.bitPerSample = bitPerSample;
		pcmParam.sampleFreq = bitstream_sample_rate_enum_to_int(sampleFreq);
		pcmParam.forceVoice = FALSE;

		return injected_bitstream_init(&pcmParam, injected_bitstream_callback);
	}
}

VMINT bitstream_close() {
	mre_bitstream_buffer_size = -1;

	if (mre_bitstream_alloved)
	{
		int res = vm_bitstream_audio_close(mre_bitstream_handle);
		mre_bitstream_handle = -1;
		return res;
	}
	else
	{
		injected_bitstream_deinit();
		return 0;
	}
}

VMINT bitstream_put_data(VMUINT8* buffer, VMUINT buffer_size, VMUINT* written) {
	VMINT res = 0;
	VMUINT actual_written = 0;

	if (mre_bitstream_alloved)
	{
		vm_bitstream_audio_put_data(mre_bitstream_handle, buffer, buffer_size, &actual_written);
	}
	else
	{
		injected_bitstream_put_buffer(buffer, buffer_size, &actual_written);
	}

	if (written) {
		*written = actual_written;
	}

	sync_total_bytes += actual_written;

	return res;
}

VMINT bitstream_get_free_buffer_size() {
	if (mre_bitstream_alloved)
	{
		vm_bitstream_audio_buffer_status status;
		vm_bitstream_audio_get_buffer_status(mre_bitstream_handle, &status);
		return status.free_buf_size;
	}
	else
	{
		return injected_bitstream_get_free_buffer_size();
	}
}

VMINT bitstream_get_sample_rate() {
	return mre_bitstream_sample_rate;
}

VMINT bitstream_get_buffer_size() {
	if (mre_bitstream_alloved)
	{
		if (mre_bitstream_buffer_size == -1) {
			vm_bitstream_audio_buffer_status status;
			vm_bitstream_audio_get_buffer_status(mre_bitstream_handle, &status);
			mre_bitstream_buffer_size = status.total_buf_size;
		}
		return mre_bitstream_buffer_size;
	}
	else
	{
		return injected_bitstream_get_buffer_size();
	}
}

VMINT bitstream_get_queued_bytes() {
	if (sync_bytes_per_ms == 0) return 0;

	VMUINT32 current_time = vm_get_tick_count();
	VMUINT32 elapsed_ms = current_time - sync_start_time;

	VMUINT32 played_bytes = elapsed_ms * sync_bytes_per_ms;

	int queued_bytes = (int)sync_total_bytes - (int)played_bytes;

	if (queued_bytes < 0) {
		sync_start_time = current_time;
		sync_total_bytes = 0;
		return 0;
	}

	return queued_bytes;
}

VMINT bitstream_get_queued_time_ms() {
	return bitstream_get_queued_bytes() / sync_bytes_per_ms;
}

VMINT bitstream_start(VMUINT start_time, VMUINT8 audio_path, VMINT volume) {
	sync_start_time = vm_get_tick_count();
	//sync_total_bytes = 0;

	if (mre_bitstream_alloved)
	{
		vm_bitstream_audio_start_param param;
		param.start_time = start_time;
		param.audio_path = audio_path;
		param.volume = volume;
		return vm_bitstream_audio_start(mre_bitstream_handle, &param);
	}
	else
	{
		vm_set_volume(volume);
		injected_bitstream_start(start_time);
	}
}

VMINT bitstream_resume() {
	if (mre_bitstream_alloved)
	{
		// todo
	}
	else
	{
		injected_bitstream_resume();
	}
}

void bitstream_reset_counters() {
	sync_total_bytes = 0;
	sync_start_time = 0;
}