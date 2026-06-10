#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <vmsys.h>

typedef VMINT(*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef enum {
	PCM_NONE,
	PCM_DATA_REQUEST,
	PCM_DATA_NOTIFICATION,
	PCM_END,
	PCM_ERROR,
	PCM_DECODER_UNSUPPORT,
	PCM_REPEATED,
	PCM_TERMINATED,
	PCM_LED_ON,
	PCM_LED_OFF,
	PCM_VIBRATOR_ON,
	PCM_VIBRATOR_OFF,
	PCM_BACKLIGHT_ON,
	PCM_BACKLIGHT_OFF,
	PCM_EXTENDED_EVENT,
	PCM_READ_ERROR,
	PCM_UPDATE_DUR,
	PCM_STOP_TIME_UP,
	PCM_DEMO_TIME_UP,
	PCM_BUFFER_UNDERFLOW,
	PCM_READY_TO_PLAY,
	PCM_DATA_REFILL
} PCM_Event;

typedef enum {
	PCM_SUCCESS = 200,
	PCM_FAIL,
	PCM_REENTRY,
	PCM_NOT_INITIALIZED,
	PCM_BAD_FORMAT,
	PCM_BAD_PARAMETER,
	PCM_BAD_COMMAND,
	PCM_NO_HANDLER,
	PCM_UNSUPPORTED_CHANNEL,
	PCM_UNSUPPORTED_FREQ,
	PCM_UNSUPPORTED_TYPE,
	PCM_UNSUPPORTED_OPERATION,
	PCM_SEEK_FAIL,
	PCM_SEEK_EOF,
	PCM_READ_FAIL,
	PCM_WRITE_FAIL,
	PCM_DISK_FULL,
	PCM_MERGE_TYPE_MISMATCH,
	PCM_FILE_INCOMPLETE
} PCM_Status;

typedef enum {
	PCM_CHANNEL_NONE = 0,
	PCM_CHANNEL_MAIN,
	PCM_CHANNEL_SUB
} PCM_Channel;

typedef enum {
	PCM_FREE_SPACE_MODE,
	PCM_DATA_COMSUME_MODE
} PCM_Buffer_Mode;

typedef struct PCM PCM;

struct PCM {
	VMUINT8 unknown[0x78];

	void (*SetBuffer)(PCM* hdl, VMUINT8* buffer, VMUINT32 buf_len);
	void (*GetWriteBuffer)(PCM* hdl, VMUINT8** buffer, VMUINT32* buf_len);
	void (*GetReadBuffer)(PCM* hdl, VMUINT8** buffer, VMUINT32* buf_len);
	void (*WriteDataDone)(PCM* hdl, VMUINT32 len);
	void (*FinishWriteData) (PCM* hdl);
	void (*ResetMediaBuf) (PCM* hdl);
	void (*ReadDataDone)(PCM* hdl, VMUINT32 len);
	void (*DataFinished)(PCM* hdl);
	void (*SetStoreFlag)(PCM* hdl, VMUINT8 fStoreLastFileOffset);
	void (*StoreFileOffset)(PCM* hdl);
	void (*SetFileOffset)(PCM* hdl, VMUINT32 uCurOffset);
	VMUINT32(*GetFileOffset)(PCM* hdl);
	VMINT32(*GetFreeSpace)(PCM* hdl);
	VMINT32(*GetDataCount)(PCM* hdl);
	PCM_Status(*SetLevel)(PCM* hdl, VMUINT8 level);
	VMUINT8(*GetLevel)(PCM* hdl);
	PCM_Status(*SetStartTime)(PCM* hdl, VMUINT32 msStartTime);
	PCM_Status(*SetStopTime)(PCM* hdl, VMUINT32 msStopTime);
	VMUINT32(*GetCurrentTime)(PCM* hdl);
	VMUINT32(*GetTotalDuration)(PCM* hdl);
	void (*BuildCache)(PCM* hdl, PCM_Status* eGetDurLastRet, VMUINT32* uProgress, VMUINT8 fLimitFrameNumber);
	void (*SetCacheTbl)(PCM* hdl, VMUINT8* ptr, VMUINT32 usize);
	VMUINT32(*GetCacheDuration)(PCM* hdl);
	void (*SelectChannel)(PCM* hdl, PCM_Channel channel);
	PCM_Status(*ReachValidRegion)(PCM* hdl);
	void (*SetUserData)(PCM* hdl, void* pAppData);
	void (*GetUserData)(PCM* hdl, void** pAppData);
	PCM_Status(*Trim)(PCM* hdl);
	void (*SetBufferInternal)(PCM* hdl, VMUINT32 uSize);
	void (*FreeBufferInternal)(PCM* hdl);

	PCM_Status (*Play)(PCM* hdl);
	PCM_Status (*Record)(PCM* hdl);
	PCM_Status (*Stop)(PCM* hdl);
	PCM_Status (*Pause)(PCM* hdl);
	PCM_Status (*Resume)(PCM* hdl);
	PCM_Event (*Process)(PCM* hdl, PCM_Event event);
	PCM_Status (*Close)(PCM* hdl);

	VMUINT8 unknown2[16];

	void (*SetDataRequestThreshold)(PCM* hdl, PCM_Buffer_Mode mode, VMUINT32 threshold, void* param);
};

typedef struct {
	VMUINT8 isStereo;
	VMUINT8 bitPerSample;
	VMUINT16 sampleFreq;
	VMUINT8 forceVoice;
} PCM_Param;

typedef void (*PCM_handle_t)(PCM* handle, PCM_Event event);


int injected_bitstream_init(PCM_Param* pcmParam, PCM_handle_t handle);
void injected_bitstream_deinit();
void injected_bitstream_put_buffer(VMUINT8* buf, VMUINT buf_size, VMUINT* written);
void injected_bitstream_start(VMUINT start_time);
void injected_bitstream_resume();
VMINT injected_bitstream_get_buffer_size();
VMINT injected_bitstream_get_free_buffer_size();

#ifdef __cplusplus
}
#endif