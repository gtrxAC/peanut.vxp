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
*   gs_srv_videostream_type.h
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   IVideoStream type header file
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
 * 11 21 2011 isiah.chen
 * [MAUI_03023606] MRE Camera Revise
 * .
 *
 * 08 09 2011 isiah.chen
 * [MAUI_03001899] video stream query service revision
 * .
 *
 * 03 09 2011 isiah.chen
 * [MAUI_02654916] MAUI AND 11A GETSRV
 * .
*
* 01 23 2011 lihong.li
* NULL
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
* 11 25 2010 isiah.chen
* NULL
* .
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef _GS_SRV_VIDEOSTREAM_TYPE_
#define _GS_SRV_VIDEOSTREAM_TYPE_
#include "gs_srv_mmvideo_type.h"

typedef void (*gs_connect_result_callback)(S32 ret, gs_video_info_struct* video_info,void *user_data);

typedef void (*gs_buffering_result_callback)(S32 ret, gs_video_info_struct* video_info,void *user_data);

typedef void (*gs_video_stream_play_finish_callback) (S32 ret,void *user_data);

typedef enum
{
	GS_VIDEO_STREAM_RTSP_URL,  /* Stream type in RSTP URL format */
	GS_VIDEO_STREAM_SDP_FILE   /* Stream type in SDP File format */
} gs_video_stream_type_enum;

typedef struct
{
	S32 player_layer_handle;
	MMI_BOOL is_visual_update;
	U8 audio_path;
	U16 rotate;
	U32 blt_layer_flag;
	U32 play_layer_flag;
}gs_video_stream_resume_struct;

typedef struct
{
	S32 player_layer_handle;
	MMI_BOOL is_visual_update;
	U8 audio_path;
	U16 rotate;
	U32 blt_layer_flag;
	U32 play_layer_flag;
}gs_video_stream_play_struct;


typedef struct
{
	gs_video_stream_type_enum stream_type;
	CHAR *data_path;
	MMI_BOOL use_proxy;
	U8 *proxy;
	U16 port;
	MMI_BOOL use_udp_port;
	U16 highest_udp_port;
	U16 lowest_udp_port;
}gs_video_stream_connect_struct;





#endif 
