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
*   gs_srv_bitstreamaudio_type.h
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   IBitstreamAudio type header file
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
 * 01 23 2011 lihong.li
 * NULL
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
* 11 25 2010 isiah.chen
* NULL
* .
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef _GS_SRV_BITSTREAMAUDIO_TYPE_
#define _GS_SRV_BITSTREAMAUDIO_TYPE_


typedef  void (*bistream_audio_open_handle_result_callback)(S32 handle, S32 result);



#define GS_BITSTREAM_MAX_H264_CFG_RECORD_SIZE   128




































/* H.264 config parameters */


typedef struct


{


	U32  timescale;	                /*  Time scale of the time stamp to the video frame*/


	BOOL is_ps_oob;                 /*  The H.264 paremater is in-band (FALSE) or out-of-band (TRUE). 


									The H.264 related parameters below are required if is_ps_oob == TRUE (out of band parameters == TRUE):


									packetization_mode,


									profile_idc,


									level_idc,


									p_AVC_config_record  */


	U8   packetization_mode;	      /*  H.264 packetization mode, it is by default to be 0 if this parameter is not present.


									  0: single NAL mode.


									  1: Non-interleaved mode.


									  2: Interleaved mode. */


	U8   profile_idc;               /*  Profile idc */


	U8   level_idc;                 /*  Level IDC   */


	U8*  p_AVC_config_record;       /*  Pointer to the AVC config record.  */


	U32  AVC_config_record_size;    /*  Buffer size of p_AVC_config record */





	/* audio information */


	gs_bitstream_codec_type_enum audio_type;   /* Audio codec enum. (from gs_bitstream_codec_type_enum)        */


	U32 sampling_rate;                          /* Audio sampling rate          */





} gs_bitstream_video_h264_cfg;


typedef struct
{
	U32  timescale;

} gs_bitstream_audio_amr_cfg;


/* Codec config union */


typedef union
{
	gs_bitstream_video_h264_cfg h264;  /* H.264 config */
	gs_bitstream_audio_amr_cfg amr;    /* AMR config */
} gs_bitstream_codec_cfg;


/* Coniguration struct definition */


typedef struct
{ 
	U16 codec_type;                                 /* GS_BITSTREAM_CODEC_TYPE_H264 or GS_BITSTREAM_CODEC_TYPE_AMR */
	gs_bitstream_codec_cfg codec_cfg;              /* Configuration to codec */
} gs_bitstream_cfg_struct;



/* Config for audio playback struct*/


typedef struct
{ 
	U16 codec_type;                                 /* Codec type, use enum of gs_bitstream_codec_type_enum */

} gs_bitstream_audio_cfg_struct;

/* Video buffer status query struct */


typedef struct
{
	U32 buffer_duration;            /* The total duration of the video frames in buffer */ 
	U32 percentage_used;            /* The used perecntage of video buffer */
	U32 free_space;                 /* Free space of video buffer (in bytes) */
	U32 current_frame_count;        /* Available number of frames inside video buffer */
	U32 required_frame_count;       /* The minimum frame number required to start video playback */
} gs_bitstream_video_buffer_status;


/* Config for starting to play video */


typedef struct
{
	U32 ms_start_time;                  /* Reference video time for first frame (in milisecond) */
	gdi_handle h_layer;                 /* Video playback layer handle                          */
	U32 blt_layer_flag;                 /* Flag of current layer configuration                  */
	U32 play_layer_flag;                /* Current video configuration flag                     */
	MMI_BOOL is_visual_update;          /* Update the video to LCM or not                       */
	U16 rotate;                         /* Rotation value of LCM                                */
} gs_bitstream_video_start_param;


/* Audio buffer status */


typedef struct
{
	U32 total_buf_size; /* Total buffer size */
	U32 free_buf_size;  /* Free buffer size */
} gs_bitstream_audio_buffer_status;





/* Config for starting to play audio */


typedef struct
{
	U32 start_time; /* Set start time to driver */
	U8 volume;      /* Set play volume */
	U8 audio_path;  /* Set audio output path */
} gs_bitstream_audio_start_param;















#endif 
