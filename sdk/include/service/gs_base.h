/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

#ifndef _GS_BASE_
#define _GS_BASE_

#ifdef __cplusplus
extern "C"
{
#endif
#ifndef __MRE_SDK__
#endif
#ifdef __cplusplus
}
#endif


#ifdef _WIN32
#   define CALLCC __stdcall
#else
#   define CALLCC 
#endif


#ifdef __MRE_SDK__
   typedef double			  DOUBLE;
   typedef float			   FLOAT;
   typedef char 			   S8;
   typedef char 			   *PS8;
   typedef unsigned char	   U8;
   typedef unsigned char	   *PU8;
   typedef unsigned short	   pBOOL;
   typedef char 			   CHAR;
   typedef short int		   S16;
   typedef short int		   *PS16;
   typedef unsigned short int  U16;
   typedef unsigned short int  *PU16;
   typedef unsigned short int  WCH16;
   typedef unsigned short int  *PWCH16;
   typedef int				   S32;
   typedef int				   *PS32;
   typedef unsigned int 	   U32;
   typedef unsigned int 	   *PU32;
   typedef float			   float32;
#endif

   typedef enum {
	MMI_FALSE   = 0,
  MMI_TRUE    = 1
} MMI_BOOL;

typedef char                S8;
typedef char                *PS8;
typedef unsigned char       U8;
typedef unsigned char       *PU8;

typedef unsigned short      pBOOL;

typedef short int           S16;
typedef short int           *PS16;
typedef unsigned short int  U16;
typedef unsigned short int  *PU16;

typedef int                 S32;
typedef int                 *PS32;
typedef unsigned int        U32;
typedef unsigned int        *PU32;


typedef unsigned short       WCHAR;
#ifdef WIN32
   typedef unsigned __int64     U64;
   typedef __int64              S64;
#else
   typedef unsigned long long   U64;
   typedef long long            S64;
#endif
typedef U32 gdi_handle;
#define BOOL	int



#ifndef NULL
#define NULL 0
#endif
#define GS_RES_BITSTREAM_SUCCEED                   0
#define GS_RES_BITSTREAM_BUFFER_OVERFLOW           8001
#define GS_RES_BITSTREAM_BUFFER_UNDERFLOW          8002
#define GS_RES_BITSTREAM_EVENT_NONE                8003
#define GS_RES_BITSTREAM_EVENT_DATA_REQUEST        8004
#define GS_RES_BITSTREAM_EVENT_ERROR               8005
#define GS_RES_BITSTREAM_RECOVER                   8006        /* mcu too busy to decode this video */
#define GS_RES_BITSTREAM_ERR_FAILED                -8001
#define GS_RES_BITSTREAM_ERR_INVALID_RESOULTION    -8002
#define GS_RES_BITSTREAM_ERR_UNSUPPORTED_FORMAT    -8003
#define GS_RES_BITSTREAM_ERR_INVALID_BITSTREAM     -8004
#define GS_RES_BITSTREAM_ERR_MEMORY_INSUFFICIENT   -8005
#define GS_RES_BITSTREAM_ERR_INSUFFICIENT_MEMORY   -8006  /* MED memory is not enough, should check MED memory scenario */
#define GS_RES_BITSTREAM_ERR_INVALID_FORMAT        -8007  /* there is some error while decoding the frame, the frame may not be a valid one */
#define GS_RES_BITSTREAM_NOT_SUPPORTED             -8008  /* Something which is not supported by Bitstream API, e.g. incorrect invoking sequence, features not available */
#define GS_RES_BITSTREAM_INVALID_PARAMETER         -8009  /* The parameter passed through the API is invalid */
#define GS_AUD_MODE_NORMAL     0
#define GS_AUD_MODE_HEADSET    1
#define GS_AUD_MODE_LOUDSPK    2
#define GS_MAX_AUD_MODE_NUM    3
#define GS_VOLUME_CTN          0
#define GS_VOLUME_KEY          1
#define GS_VOLUME_MIC          2
#define GS_VOLUME_FMR          3
#define GS_VOLUME_SPH          4
#define GS_VOLUME_SID          5
#define GS_VOLUME_MEDIA        6
#define GS_VOLUME_TVO          7
#define GS_VOLUME_ATV          8
#define GS_MAX_VOLUME_TYPE     9
#define GS_MAX_VOLUME_LEVEL    7
#define GS_DEVICE_SPEAKER      0
#define GS_DEVICE_MICROPHONE   1
#define GS_DEVICE_SPEAKER2     4
#define GS_DEVICE_LOUDSPEAKER  5
#define GS_DEVICE_SPEAKER_BOTH 6
#define GS_DEVICE_BT_HEADSET   8
#define GS_AUDIO_PLAY_CRESCENDO    0
#define GS_AUDIO_PLAY_INFINITE     1
#define GS_AUDIO_PLAY_ONCE         2
#define GS_AUDIO_PLAY_DESCENDO     3
#define GS_INPUT_MIC1  0
#define GS_INPUT_MIC2  1
#define GS_INPUT_FMRR  2
#define GS_AUDIO_MAX_SPEED_NUM     5
#define GS_AUDIO_SPEED_SLOW2       50
#define GS_AUDIO_SPEED_SLOW1       80
#define GS_AUDIO_SPEED_NORMAL      100
#define GS_AUDIO_SPEED_FAST1       125
#define GS_AUDIO_SPEED_FAST2       160
#define GS_AUD_VOL_GET_EX_LEVEL(x)     ((x) & 0x3F)
#define GS_AUD_VOL_IS_EX_LEVEL(x)      ((x) & 0x80)
#define GS_AUD_VOL_IS_MUTE_LEVEL(x)    ((x) & 0x40)
#define GS_AUD_VOL_EX(x)       ((x) | 0x80)
#define GS_AUD_VOL_MUTE(x)     ((x) | 0x40)
#define GS_AUD_VOL_EX_MUTE(x)  ((x) | 0xC0)
#define GS_AUD_PTH_EX(x) (x)
#define GS_AUD_VOL_LEVEL_NORMAL        1
#define GS_AUD_VOL_LEVEL_NORMAL_MUTE   2
#define GS_AUD_VOL_LEVEL_EXTEND        3
#define GS_AUD_VOL_LEVEL_EXTEND_MUTE   4
typedef enum
{
    GS_AUD_VOL_0,  /* Volume level 0 (Not mute) */
    GS_AUD_VOL_1,  /* Volume level 1 */
    GS_AUD_VOL_2,  /* Volume level 2 */
    GS_AUD_VOL_3,  /* Volume level 3 */
    GS_AUD_VOL_4,  /* Volume level 4 */
    GS_AUD_VOL_5,  /* Volume level 5 */
    GS_AUD_VOL_6,  /* Volume level 6 */
    GS_AUD_VOL_NUM /* Total volume level */
} GS_AUD_VOL_ENUM;
typedef enum
{
    GS_BITSTREAM_CODEC_TYPE_NONE,  /* No type */
    GS_BITSTREAM_CODEC_TYPE_SILENT, /* To play silence frame for video only file */
    GS_BITSTREAM_CODEC_TYPE_AMR,   /* AMR */
    GS_BITSTREAM_CODEC_TYPE_AMRWB, /* Wideband AMR */
    GS_BITSTREAM_CODEC_TYPE_AAC,   /* AAC */
    GS_BITSTREAM_CODEC_TYPE_DAF,   /* DAF */
    GS_BITSTREAM_CODEC_TYPE_MP4A,  /* Mpeg-4 audio */
    GS_BITSTREAM_CODEC_TYPE_MP4AG,
    GS_BITSTREAM_CODEC_TYPE_WAV,
    GS_BITSTREAM_CODEC_TYPE_ADPCM,
    GS_BITSTREAM_CODEC_TYPE_PCM,
    GS_BITSTREAM_CODEC_TYPE_TOTAL  /* Total codec type */
} gs_bitstream_codec_type_enum;


#define GS_NEW(_ptr, _OBJ) do { \
    _ptr = (_OBJ*) gs_alloc(sizeof(_OBJ)); \
    _ptr = new (_ptr) _OBJ; \
} while(0);

#define GS_NEW_EX(_ptr, _OBJ, _arg) do { \
    _ptr = (_OBJ*) gs_alloc(sizeof(_OBJ)); \
    _ptr = new (_ptr) _OBJ _arg; \
} while(0);

#define GS_DEL(_ptr) do { \
    delete _ptr; \
} while(0)

// For testing, we force define GS_USE_PROXY
#define GS_USE_PROXY

#ifdef __cplusplus
// C++ version header
class GS_IBase
{
public:
    virtual int CALLCC addRef() = 0;
    virtual int CALLCC release() = 0;
    virtual int CALLCC queryInterface(int iid, GS_IBase** pptr) = 0;
};

#else
// C version header
struct GS_IBase;
struct GS_IBaseVT;
typedef struct GS_IBase GS_IBase;
typedef struct GS_IBaseVT GS_IBaseVT;
struct GS_IBaseVT
{
    int (CALLCC *addRef)(GS_IBase* self);
    int (CALLCC *release)(GS_IBase* self);
    int (CALLCC *queryInterface)(GS_IBase* self, int iid, GS_IBase** pptr);
};

struct GS_IBase
{
    const GS_IBaseVT*      vt;
};
#endif

#ifdef GS_USE_PROXY
GS_IBase* GS_IBaseProxy_bind(GS_IBase* ptr);
#endif

#ifdef GS_USE_PROXY
#define BIND_PROXY(IOBJ, ptr) IOBJ##Proxy_bind(ptr)
#else 
#define BIND_PROXY(IOBJ, ptr) (IOBJ*)ptr
#endif

#ifndef __MRE_SDK__
#ifdef __cplusplus
#endif
#endif

#endif // _GS_BASE_

