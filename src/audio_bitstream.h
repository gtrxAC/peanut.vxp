#pragma once
//#include "common.h"
#include "audio_midi.h"

uint8_t audio_bitstream_read(const uint16_t addr);
void audio_bitstream_write(const uint16_t addr, const uint8_t val);
void audio_bitstream_update();

void audio_bitstream_init();
void audio_bitstream_deinit();

typedef VMINT(*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

#define RING_BUFFER_SIZE (AUDIO_SAMPLES*4*3)
#define AUDIO_BUF_SIZE (AUDIO_SAMPLES*4)

#define F_ADR(t,x,a,adr) typedef t (*x##_) a; x##_ x = (x##_) adr;

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
   PCM_MERGE_TYPE_MISMATCH ,
   PCM_FILE_INCOMPLETE
} PCM_Status;

typedef enum {
   PCM_CHANNEL_NONE = 0,
   PCM_CHANNEL_MAIN,
   PCM_CHANNEL_SUB
} PCM_Channel;

typedef struct PCM PCM;

struct PCM {
   uint8_t unknown[0x78];

   void         (*SetBuffer)(PCM *hdl, uint8_t *buffer, uint32_t buf_len);
   void         (*GetWriteBuffer)(PCM *hdl, uint8_t **buffer, uint32_t *buf_len);
   void         (*GetReadBuffer)(PCM *hdl, uint8_t **buffer, uint32_t *buf_len);
   void         (*WriteDataDone)(PCM *hdl, uint32_t len);
   void         (*FinishWriteData) (PCM *hdl);
   void         (*ResetMediaBuf) (PCM *hdl);
   void         (*ReadDataDone)(PCM *hdl, uint32_t len);
   void         (*DataFinished)(PCM *hdl);
   void         (*SetStoreFlag)(PCM *hdl, uint8_t fStoreLastFileOffset);
   void         (*StoreFileOffset)(PCM *hdl);
   void         (*SetFileOffset)(PCM *hdl, uint32_t uCurOffset);
   uint32_t     (*GetFileOffset)(PCM *hdl);
   int32_t      (*GetFreeSpace)(PCM *hdl);
   int32_t      (*GetDataCount)(PCM *hdl);
   PCM_Status   (*SetLevel)(PCM *hdl, uint8_t level);
   uint8_t      (*GetLevel)(PCM *hdl);
   PCM_Status   (*SetStartTime)(PCM *hdl, uint32_t msStartTime);
   PCM_Status   (*SetStopTime)(PCM *hdl, uint32_t msStopTime);
   uint32_t     (*GetCurrentTime)(PCM *hdl);
   uint32_t     (*GetTotalDuration)(PCM *hdl);
   void         (*BuildCache)(PCM *hdl, PCM_Status *eGetDurLastRet, uint32_t *uProgress, uint8_t fLimitFrameNumber);
   void         (*SetCacheTbl)(PCM *hdl, uint8_t *ptr, uint32_t usize);
   uint32_t     (*GetCacheDuration)(PCM *hdl);
   void         (*SelectChannel)(PCM *hdl, PCM_Channel channel);
   PCM_Status   (*ReachValidRegion)(PCM *hdl); 
   void         (*SetUserData)(PCM *hdl, void* pAppData);
   void         (*GetUserData)(PCM *hdl, void** pAppData);
   PCM_Status   (*Trim)(PCM *hdl);
   void         (*SetBufferInternal)(PCM *hdl , uint32_t uSize);
   void         (*FreeBufferInternal)(PCM *hdl);

   PCM_Status   (*Play)(PCM *hdl);
   PCM_Status   (*Record)(PCM *hdl);
   PCM_Status   (*Stop)(PCM *hdl);
   PCM_Status   (*Pause)(PCM *hdl);
   PCM_Status   (*Resume)(PCM *hdl);
   PCM_Event    (*Process)(PCM *hdl, PCM_Event event);
   PCM_Status   (*Close)(PCM *hdl);
};

typedef struct {
   uint8_t      isStereo;
   uint8_t      bitPerSample;
   uint16_t     sampleFreq;
   uint8_t      forceVoice;
} PCM_Param;

typedef void (*PCM_handle_t)(PCM *handle, PCM_Event event);