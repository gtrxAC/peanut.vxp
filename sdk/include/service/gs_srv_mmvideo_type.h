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

/*****************************************************************************
*
* Filename:
* ---------
*   gs_srv_mmvideo_type.h
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   IMMVideo type header file
*
* Author:
* -------
*  Isiah Chen
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
* $Log$
 *
 * 03 29 2011 isiah.chen
 * [MAUI_02654916] MAUI AND 11A GETSRV
 * .
 *
 * 03 10 2011 isiah.chen
 * [MAUI_02655722] 11AW11.12 check in
 * getsrv. audio bt case. camera.
 *
 * 03 09 2011 isiah.chen
 * [MAUI_02654916] MAUI AND 11A GETSRV
 * .
 *
 * 12 28 2010 isiah.chen
 * [MAUI_02646071] 11A bitstream audio build error
 * .
 *
 * 12 26 2010 isiah.chen
 * [MAUI_02645644] query service mm check in
 * .
 *
 * 12 16 2010 lihong.li
 * NULL
 * .
 *
 * 12 15 2010 isiah.chen
 * NULL
 * .
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef GS_SRV_MMVIDEO_TYPE_H
#define GS_SRV_MMVIDEO_TYPE_H





/* Main sensor */
#define GS_VIDEO_MAIN_SENSOR               0
/* Sub sensor */
#define GS_VIDEO_SUB_SENSOR                1

typedef enum
{
    GS_VIDEO_EV_N4 = 0,
    GS_VIDEO_EV_N3,
    GS_VIDEO_EV_N2,
    GS_VIDEO_EV_N1,
    GS_VIDEO_EV_0,
    GS_VIDEO_EV_P1,
    GS_VIDEO_EV_P2,
    GS_VIDEO_EV_P3,
    GS_VIDEO_EV_P4,
    GS_VIDEO_EV_NIGHT,
    GS_VIDEO_EV_COUNT
} GS_VIDEO_EV_ENUM;


typedef enum
{
    GS_VIDEO_EFFECT_NOMRAL = 0,
    GS_VIDEO_EFFECT_GRAYSCALE,
    GS_VIDEO_EFFECT_SEPIA,
    GS_VIDEO_EFFECT_SEPIA_GREEN,
    GS_VIDEO_EFFECT_SEPIA_BLUE,
    GS_VIDEO_EFFECT_COLOR_INVERT,
    GS_VIDEO_EFFECT_GRAY_INVERT,
    GS_VIDEO_EFFECT_BLACKBOARD,
    GS_VIDEO_EFFECT_WHITEBOARD,
    GS_VIDEO_EFFECT_COPPER_CARVING,
    GS_VIDEO_EFFECT_EMBOSSMENT,
    GS_VIDEO_EFFECT_BLUE_CARVING,
    GS_VIDEO_EFFECT_CONTRAST,
    GS_VIDEO_EFFECT_JEAN,
    GS_VIDEO_EFFECT_SKETCH,
    GS_VIDEO_EFFECT_OIL,
    GS_VIDEO_EFFECT_COUNT
} GS_VIDEO_IMAGE_EFFECT_ENUM;


typedef enum
{
    GS_VIDEO_WB_AUTO = 0,
    GS_VIDEO_WB_CLOUD,
    GS_VIDEO_WB_DAYLIGHT,
    GS_VIDEO_WB_INCANDESCENCE,
    GS_VIDEO_WB_FLUORESCENT,
    GS_VIDEO_WB_TUNGSTEN,
    GS_VIDEO_WB_MANUAL,
    GS_VIDEO_WB_COUNT
} GS_VIDEO_WB_ENUM;

typedef enum
{
    GS_VIDEO_BANDING_50HZ = 0,
    GS_VIDEO_BANDING_60HZ,
    GS_VIDEO_BANDING_COUNT
} GS_VIDEO_BANDING_FREQ_ENUM;



typedef enum
{
    GS_VIDEO_SIZE_SQCIF=0,
    GS_VIDEO_SIZE_QQVGA,
    GS_VIDEO_SIZE_QCIF,
    GS_VIDEO_SIZE_QVGA,
    GS_VIDEO_SIZE_CIF,
    GS_VIDEO_SIZE_VGA,
    GS_VIDEO_SIZE_WQVGA,
    GS_VIDEO_SIZE_HVGA,
    GS_VIDEO_SIZE_NHD,
    GS_VIDEO_SIZE_WVGA,
    GS_VIDEO_SIZE_D1,
    GS_NO_OF_VIDEO_SIZE
} GS_VIDEO_SIZE_ENUM;

typedef enum
{
    GS_VIDEO_REC_QTY_LOW = 0,
    GS_VIDEO_REC_QTY_NORMAL,
    GS_VIDEO_REC_QTY_HIGH,
    GS_VIDEO_REC_QTY_FINE,
    GS_VIDEO_NO_OF_REC_QTY
} GS_VIDEO_REC_QTY_ENUM;


enum
{
    GS_VIDEO_FORMAT_3GP = 0,
    GS_VIDEO_FORMAT_MP4,
    GS_VIDEO_FORMAT_COUNT
};

enum
{
    GS_VIDEO_PREVIEW_ROTATE_0 = 0,
    GS_VIDEO_PREVIEW_ROTATE_90,
    GS_VIDEO_PREVIEW_ROTATE_180,
    GS_VIDEO_PREVIEW_ROTATE_270,
    GS_VIDEO_PREVIEW_ROTATE_0_MIRROR,
    GS_VIDEO_PREVIEW_ROTATE_90_MIRROR,
    GS_VIDEO_PREVIEW_ROTATE_180_MIRROR,
    GS_VIDEO_PREVIEW_ROTATE_270_MIRROR,
    GS_VIDEO_PREVIEW_NO_OF_ROTATE
};





/* LCD rotate: 0 degree */
#define GS_VIDEO_LCD_ROTATE_0            0
/* LCD rotate: 90 degree */
#define GS_VIDEO_LCD_ROTATE_90           1
/* LCD rotate: 180 degree */
#define GS_VIDEO_LCD_ROTATE_180          2
/* LCD rotate: 270 degree */
#define GS_VIDEO_LCD_ROTATE_270          3
/* LCD rotate: 0 degree + Mirror */
#define GS_VIDEO_LCD_ROTATE_0_MIRROR     4
/* LCD rotate: 90 degree + Mirror */
#define GS_VIDEO_LCD_ROTATE_90_MIRROR    5
/* LCD rotate: 180 degree + Mirror */
#define GS_VIDEO_LCD_ROTATE_180_MIRROR   6
/* LCD rotate: 270 degree + Mirror */
#define GS_VIDEO_LCD_ROTATE_270_MIRROR   7


/* Brightness value which is darker than default value by 5 levels */
#define GS_VIDEO_BRIGHTNESS_N5              0
/* Brightness value which is darker than default value by 4 levels */
#define GS_VIDEO_BRIGHTNESS_N4              1
/* Brightness value which is darker than default value by 3 levels */
#define GS_VIDEO_BRIGHTNESS_N3              2
/* Brightness value which is darker than default value by 2 levels */
#define GS_VIDEO_BRIGHTNESS_N2              3
/* Brightness value which is darker than default value by 1 levels */
#define GS_VIDEO_BRIGHTNESS_N1              4
/* Default brightness value */
#define GS_VIDEO_BRIGHTNESS_0               5
/* Brightness value which is brighter than default value by 1 level */
#define GS_VIDEO_BRIGHTNESS_P1              6
/* Brightness value which is brighter than default value by 2 level */
#define GS_VIDEO_BRIGHTNESS_P2              7
/* Brightness value which is brighter than default value by 3 level */
#define GS_VIDEO_BRIGHTNESS_P3              8
/* Brightness value which is brighter than default value by 4 level */
#define GS_VIDEO_BRIGHTNESS_P4              9
/* Brightness value which is brighter than default value by 5 level */
#define GS_VIDEO_BRIGHTNESS_P5              10

/* Contrast value which is lower than default value by 5 levels */
#define GS_VIDEO_CONTRAST_N5                0
/* Contrast value which is lower than default value by 4 levels */
#define GS_VIDEO_CONTRAST_N4                1
/* Contrast value which is lower than default value by 3 levels */
#define GS_VIDEO_CONTRAST_N3                2
/* Contrast value which is lower than default value by 2 levels */
#define GS_VIDEO_CONTRAST_N2                3
/* Contrast value which is lower than default value by 1 levels */
#define GS_VIDEO_CONTRAST_N1                4
/* Default contrast value */
#define GS_VIDEO_CONTRAST_0                 5
/* Contrast value which is higher than default value by 1 levels */
#define GS_VIDEO_CONTRAST_P1                6
/* Contrast value which is higher than default value by 2 levels */
#define GS_VIDEO_CONTRAST_P2                7
/* Contrast value which is higher than default value by 3 levels */
#define GS_VIDEO_CONTRAST_P3                8
/* Contrast value which is higher than default value by 4 levels */
#define GS_VIDEO_CONTRAST_P4                9
/* Contrast value which is higher than default value by 5 levels */
#define GS_VIDEO_CONTRAST_P5                10

/* Max length of content info */
#define GS_VIDEO_MAX_CONTENT_INFO_LEN       80

/* Max buffer size of content info */
#define GS_VIDEO_CONTENT_BUFFER_SIZE        ((GS_VIDEO_MAX_CONTENT_INFO_LEN + 1) * 2)

/* Character count of the info title */
#define GS_VIDEO_INFO_TITLE_CHAR_COUNT      32

#define GS_SDP_MAX_URL_LEN     256
/* Max SDP file size */
#define GS_SDP_MAX_FILE_SIZE   40960

#define GS_SDP_ATTRIB_PURGE    "X-purge"
#define GS_SDP_ATTRIB_FSIZE    "X-filesize"
#define GS_SDP_ATTRIB_FWALLOW  "X-FORWARD-ALLOWED"



/* camera 1000 */
#define GS_RES_CAMERA_SUCCEED                        0
#define GS_RES_CAMERA_XENONFLASH_CHARGING            1001
#define GS_RES_CAMERA_ERR_FAILED                     -1001
#define GS_RES_CAMERA_ERR_DISK_FULL                  -1002
#define GS_RES_CAMERA_ERR_WRITE_PROTECTION           -1003
#define GS_RES_CAMERA_ERR_NO_DISK                    -1004
#define GS_RES_CAMERA_ERR_HW_NOT_READY               -1005
#define GS_RES_CAMERA_ERR_MEMORY_NOT_ENOUGH          -1006
#define GS_RES_CAMERA_ERR_PREVIEW_FAILED             -1007
#define GS_RES_CAMERA_ERR_CAPTURE_FAILED             -1008
#define GS_RES_CAMERA_ERR_ROOT_DIR_FULL              -1009
#define GS_RES_CAMERA_ERR_XENONFLASH_TIMEOUT         -1010
#define GS_RES_CAMERA_ERR_XENONFLASH_LOW_BATTERY     -1011
#define GS_RES_CAMERA_ERR_CBM_BEARER_ERROR           -1012

/* webcam 1500 */
#define GS_RES_WEBCAM_SUCCEED                      0
#define GS_RES_WEBCAM_DRV_ABORT                    1501
#define GS_RES_WEBCAM_ERR_FAILED                   -1502

/* video recorder 2000 */
#define GS_RES_VDOREC_SUCCEED                        0
#define GS_RES_VDOREC_DISK_FULL                      2001
#define GS_RES_VDOREC_REACH_SIZE_LIMIT               2002
#define GS_RES_VDOREC_RECORD_ALREADY_STOP            2003
#define GS_RES_VDOREC_ERR_FAILED                     -2001
#define GS_RES_VDOREC_ERR_DISK_FULL                  -2002
#define GS_RES_VDOREC_ERR_WRITE_PROTECTION           -2003
#define GS_RES_VDOREC_ERR_NO_DISK                    -2004
#define GS_RES_VDOREC_ERR_HW_NOT_READY               -2005
#define GS_RES_VDOREC_ERR_PREVIEW_FAILED             -2006
#define GS_RES_VDOREC_ERR_RESUME_FAILED              -2007
#define GS_RES_VDOREC_ERR_PAUSE_FAILED               -2008
#define GS_RES_VDOREC_ERR_SAVE_FILE_FAILED           -2009
#define GS_RES_VDOREC_ERR_POWER_ON_FAILED            -2010
#define GS_RES_VDOREC_ERR_RECORD_FAILED              -2011
#define GS_RES_VDOREC_ERR_STORAGE_TOO_SLOW           -2012
#define GS_RES_VDOREC_ERR_CBM_BEARER_ERROR           -2013
#define GS_RES_VDOREC_ERR_MEMORY_INSUFFICIENT        -2014

/* vdioe player 3000 */
#define GS_RES_VDOPLY_SUCCEED                        0
#define GS_RES_VDOPLY_SEEK_PARTIAL_DONE              3001
#define GS_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH    3002
#define GS_RES_VDOPLY_REACH_STOP_TIME                3003
#define GS_RES_VDOPLY_STREAM_BUFFER_OVERFLOW         3004
#define GS_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW        3005
#define GS_RES_VDOPLY_STREAM_DRM_NEED_RIGHT          3006 
#define GS_RES_VDOPLY_ALREADY_FINISHED                3007
#define GS_RES_VDOPLY_ERR_FAILED                     -3001
#define GS_RES_VDOPLY_ERR_OPEN_FILE_FAILED           -3002
#define GS_RES_VDOPLY_ERR_FILE_TOO_LARGE             -3003
#define GS_RES_VDOPLY_ERR_SNAPSHOT_FAILED            -3004
#define GS_RES_VDOPLY_ERR_PLAY_FAILED                -3005
#define GS_RES_VDOPLY_ERR_SEEK_FAILED                -3006
#define GS_RES_VDOPLY_ERR_SNAPSHOT_DISK_FULL         -3007
#define GS_RES_VDOPLY_ERR_SNAPSHOT_WRITE_PROTECTION  -3008
#define GS_RES_VDOPLY_ERR_SNAPSHOT_NO_DISK           -3009
#define GS_RES_VDOPLY_ERR_SNAPSHOT_ROOT_DIR_FULL     -3010
#define GS_RES_VDOPLY_ERR_STREAM_CONNECT_FAILED      -3011
#define GS_RES_VDOPLY_ERR_INVALID_RESOULTION         -3012
#define GS_RES_VDOPLY_ERR_NETWORK_DISCONNECT         -3013
#define GS_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT         -3014
#define GS_RES_VDOPLY_ERR_NETWORK_FORBIDDEN          -3015
#define GS_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT        -3016
#define GS_RES_VDOPLY_ERR_DRM_PROHIBITED             -3017     /* no rights */
#define GS_RES_VDOPLY_ERR_DRM_DURATION_USED          -3018
#define GS_RES_VDOPLY_ERR_FRAMERATE_TOO_HIGH         -3019
#define GS_RES_VDOPLY_ERR_STREAM_BUFFER_FAILED       -3020

typedef enum
{
	GS_VIDEO_TRACK_NONE,   /* Video has no track in it */
	GS_VIDEO_TRACK_AV,     /* Video has both audio and video tracks */
	GS_VIDEO_TRACK_A_ONLY, /* Video has audio track only */
	GS_VIDEO_TRACK_V_ONLY, /* Video has video track only */
	GS_VIDEO_TRACK_COUNT   /* Count of video track enum */
} gs_video_track_enum;



typedef struct
{
	U16 width;                      /* Width of the video */
	U16 height;                     /* Height of the video */
	U32 total_frame_count;          /* Total framecount of the video */
	U64 total_time_duration;        /* Total time duration of the video */
	gs_video_track_enum track;     /* Track information of the video */
	S32 handle;              /* Handle of the opened video file */
	MMI_BOOL is_seekable;           /* Is this video seekable */
	MMI_BOOL is_stereo;             /* Not used */
	U8 aud_channel_no;              /* Audio channel count information */
	U16 aud_sample_rate;            /* Audio sample rate information */

	MMI_BOOL is_drm_streaming;      /* Is this is a drm streaming file */
	MMI_BOOL is_rec_allowed;        /* Recording is allowed or not */    
	S32 drm_handle;                 /* DRM handle of this video */

	S8 title_desc[GS_VIDEO_CONTENT_BUFFER_SIZE];       /* Title information */
	S8 artist_desc[GS_VIDEO_CONTENT_BUFFER_SIZE];      /* Artist information */
	S8 album_desc[GS_VIDEO_CONTENT_BUFFER_SIZE];       /* Album information */
	S8 author_desc[GS_VIDEO_CONTENT_BUFFER_SIZE];      /* Author information */
	S8 copyright_desc[GS_VIDEO_CONTENT_BUFFER_SIZE];   /* Copyright information */
	S8 date_desc[GS_VIDEO_CONTENT_BUFFER_SIZE];        /* Date information */ 
} gs_video_info_struct;


typedef void (*gs_open_result_callback)(S32 ret, gs_video_info_struct *video_info,void *user_data);
typedef void (*gs_play_finish_callback) (S32 ret,void *user_data);
typedef void (*gs_seek_result_callback) (S32 ret,void *user_data);



typedef struct
{
	U8 elapse_ticks;
	U8 sleep_ticks;
} gs_video_sleep_struct;



typedef struct
{
	S32 player_layer_handle;
	MMI_BOOL is_play_audio;
	U8 audio_path;
}gs_video_play_struct;


typedef struct
{
	U16 wb;                 /* Current white balance value cached in MDI-Video */
	U16 ev;                 /* Current EV value cached in MDI-Video */
	U16 banding;            /* Current camera banding value cached in MDI-Video */
	U16 effect;             /* Current effect value cached in MDI-Video */
	U16 zoom;               /* Current zoom value cached in MDI-Video */
	U16 brightness;         /* Current brightness value cached in MDI-Video */
	U16 contrast;           /* Current contrast value cached in MDI-Video */
	U16 saturation;         /* Current saturation value cached in MDI-Video */
	U16 hue;                /* Current hue value cached in MDI-Video */
	U16 preview_rotate;     /* Current preview rotate value cached in MDI-Video */
	U16 lcm_rotate;         /* Current lcm rotate value cached in MDI-Video */
	U16 night;              /* Current night mode value cached in MDI-Video */

	U16 dsc_mode;           /* Current scene mode value cached in MDI-Video */
	U16 af_operation_mode;  /* Current af operation mode value cached in MDI-Video */
	U16 af_range;           /* Current af range value cached in MDI-Video */
	U16 sharpness;          /* Current sharpness value cached in MDI-Video */
	U32 max_zoom_factor;    /* Current max zoom factor value cached in MDI-Video */
	U8 total_zoom_step;     /* Current total zoom sted cached in MDI-Video */

	U16 video_size;         /* Current video size cached in MDI-Video */
	U16 video_qty;          /* Current video quality cached in MDI-Video */
	U16 size_limit;         /* Current video limit of size cached in MDI-Video */
	U16 time_limit;         /* Current video time limit of size cached in MDI-Video */
	U16 record_aud;         /* Record audio or not flag cached in MDI-Video */
	U16 video_format;       /* Current video format cached in MDI-Video */
	U16 user_def_width;     /* User defined width cached in MDI-Video */
	U16 user_def_height;    /* User defined height cached in MDI-Video */

	MMI_BOOL overlay_frame_mode;            /* Overlay frame mode */
	U8 overlay_frame_depth;             /* Overlay frame depth */
	U8 overlay_frame_source_key;        /* Overlay frame source key */
	U16 overlay_frame_width;            /* Overlay frame width */
	U16 overlay_frame_height;           /* Overlay frame height */
	U32 overlay_frame_buffer_address;   /* Overlay frame buffer address */

	U16 peer_enc_qty; /* Video Telephony: peer encode quality */
	MMI_BOOL display_mirror;    /* Video Telephony: mirror display */
	U16  display_rotate;    /* Video Telephony: rotate display */
} gs_video_setting_struct;


#endif
