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
*   srv_videostream_interface.h
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   IVideoStream interface
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

#include "gs_id.h"
#include "gs_base.h"

#define GS_C_INTERFACE
#include "gs_srv_videostream_interface_def.h"

#include "gs_srv_videostream_type.h"

/*****************************************************************************
* IVideoStream methods
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  IVideoStream_addRef
* DESCRIPTION
*  
* PARAMETERS
*  obj : [IN] Pointer to object.
* RETURNS
*  The error code of the operation.
*****************************************************************************/
S32 __inline IVideoStream_addRef(IVideoStream *obj)
{
	return obj->vt->addRef(obj);
}


/*****************************************************************************
* FUNCTION
*  IVideoStream_release
* DESCRIPTION
*  
* PARAMETERS
*  obj : [IN] Pointer to object.
* RETURNS
*  The error code of the operation.
*****************************************************************************/
S32 __inline IVideoStream_release(IVideoStream *obj)
{
	return obj->vt->release(obj);
}


/*****************************************************************************
* FUNCTION
*  IVideoStream_queryInterface
* DESCRIPTION
*  
* PARAMETERS
*  obj : [IN] Pointer to object.
*  iid : [IN]        
*  pptr : [IN]        
* RETURNS
*  The error code of the operation.
*****************************************************************************/
S32 __inline IVideoStream_queryInterface(IVideoStream *obj, S32 iid, GS_IBase **pptr)
{
	return obj->vt->queryInterface(obj, iid, pptr);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_init
 * DESCRIPTION
 *  To initialize video streaming module.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to initialize video streaming module.
 *  GS_RES_VDOPLY_ERR_FAILED : Fail to initialize video streaming module.
 *****************************************************************************/
S32 __inline IVideoStream_init(IVideoStream *obj)
{
	return obj->vt->gs_video_stream_init(obj);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_deinit
 * DESCRIPTION
 *  To de-initialze video streaming module.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to de-initialize video streaming module.
 *  GS_RES_VDOPLY_ERR_FAILED : Fail to de-initialize video streaming module.
 *****************************************************************************/
S32 __inline IVideoStream_deinit(IVideoStream *obj)
{
	return obj->vt->gs_video_stream_deinit(obj);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_connect
 * DESCRIPTION
 *  blah
 * PARAMETERS
 *  blah
 * RETURNS
 *  GS_RES_VDOPLY_SUCCEED : Succeed to connect to server.
 *  GS_RES_VDOPLY_ERR_FAILED : Fail to connect to server.
 *****************************************************************************/
S32 __inline IVideoStream_connect(IVideoStream *obj,gs_video_stream_connect_struct* p,	gs_connect_result_callback connect_result_callback,void* user_data)
{
	return obj->vt->gs_video_stream_connect(obj,p,connect_result_callback,user_data);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_disconnect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to disconnect to server.
 *  GS_RES_VDOPLY_ERR_FAILED : Fail to disconnect to server.
 *****************************************************************************/
S32 __inline IVideoStream_disconnect(IVideoStream *obj)
{
	return obj->vt->gs_video_stream_disconnect(obj);
}

/*****************************************************************************
 * FUNCTION
 *  gs_video_stream_is_connected
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE : It is connected with stream server.
 *  MMI_FALSE : It is not connected with stream server.
 *****************************************************************************/
MMI_BOOL __inline IVideoStream_is_connected(IVideoStream *obj)
{
	return obj->vt->gs_video_stream_is_connected(obj);
}


/*****************************************************************************
 * FUNCTION
 *  IVideoStream_start_buffering
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  GS_RES_VDOPLY_SUCCEED : Succeed to start buffering.
 *  GS_RES_VDOPLY_ERR_DRM_PROHIBITED : Fail to start buffering due to drm check is prohibited.
 *  GS_RES_VDOPLY_REACH_STOP_TIME : Fail to start buffering due to it is stopped due to stop time is reached.
 *  GS_RES_VDOPLY_ERR_PLAY_FAILED : Fail to start buffering.
 *****************************************************************************/
S32 __inline IVideoStream_start_buffering(IVideoStream *obj,U32 time, gs_buffering_result_callback buffering_result_callback,void* user_data)
{
	return obj->vt->gs_video_stream_start_buffering(obj,time,buffering_result_callback,user_data);

}

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_stop_buffering
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to stop buffering.
 *  GS_RES_VDOPLY_ERR_FAILED : Fail to stop buffering.
 *****************************************************************************/
S32 __inline IVideoStream_stop_buffering(IVideoStream *obj)
{
	return obj->vt->gs_video_stream_stop_buffering(obj);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_play
 * DESCRIPTION
 *  To start play streaming video.
 * PARAMETERS
 *  player_layer_handle : [IN]Layer handle of playback layer.
 *  blt_layer_flag : [IN]Layers to blt to LCM
 *  play_layer_flag : [IN]Layer for HW to draw
 *  is_visual_update : [IN]To update to LCM or not.
 *  audio_path : [IN]Audio output path.
 *  rotate : [IN]Rotate.
 *  play_finish_callback : [IN]Callback function.
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to start play.
 *  GS_RES_VDOPLY_ERR_DRM_PROHIBITED : Fail to start play due to drm check is prohibited.
 *  GS_RES_VDOPLY_REACH_STOP_TIME : Fail to start play due to it is stopped due to stop time is reached.
 *  GS_RES_VDOPLY_ERR_PLAY_FAILED : Fail to start play.
 *****************************************************************************/
S32 __inline IVideoStream_play(IVideoStream *obj,gs_video_stream_play_struct *p,gs_play_finish_callback play_finish_callback,void* user_data)
{
	return obj->vt->gs_video_stream_play(obj,p,play_finish_callback,user_data);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to stop play.
 *  GS_RES_VDOPLY_ERR_FAILED : Fail to stop play.
 *****************************************************************************/
S32 __inline IVideoStream_stop(IVideoStream *obj)
{
	return obj->vt->gs_video_stream_stop(obj);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_pause
 * DESCRIPTION
 *  To pause play stream video.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to pause stream play.
 *  GS_RES_VDOPLY_ERR_FAILED : Fail to pause stream play.
 *****************************************************************************/
S32 __inline IVideoStream_pause(IVideoStream *obj)
{
	return obj->vt->gs_video_stream_pause(obj);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_resume
 * DESCRIPTION
 *  To resume playing streaming video
 * PARAMETERS
 *  player_layer_handle : [IN]Layer handle of playback layer.
 *  blt_layer_flag : [IN]Layers to blt to LCM
 *  play_layer_flag : [IN]Layer for HW to draw
 *  is_visual_update : [IN]To update to LCM or not.
 *  audio_path : [IN]Audio output path.
 *  rotate : [IN]Rotate.
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to resume stream play.
 *  GS_RES_VDOPLY_ERR_FAILED : Fail to resume stream play.
 *****************************************************************************/
S32 __inline IVideoStream_resume(IVideoStream *obj,gs_video_stream_resume_struct* p)
{
	return obj->vt->gs_video_stream_resume(obj,p);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_drm_disable_consume_count
 * DESCRIPTION
 *  Do not consume drm count when play.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to disable consume drm count for next playing.
 *  GS_RES_VDOPLY_ERR_FAILED : Fail to disable consume drm count for next playing.
 *****************************************************************************/



/*****************************************************************************
 * FUNCTION
 *  IVideoStream_drm_disable_consume_time
 * DESCRIPTION
 *  Do not consume drm count when play
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to disable consume drm time limitation for next playing.
 *  GS_RES_VDOPLY_ERR_FAILED : Fail to disable consume drm time limitation for next playing.
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_get_buf_percentage
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to get buffer percentage of the stream downloaded data.
 *  GS_RES_VDOPLY_ERR_FAILED : Fail to get buffer percentage of the stream downloaded data.
 *****************************************************************************/
S32 __inline IVideoStream_get_buf_percentage(IVideoStream *obj,S32 *percentage)
{
	return obj->vt->gs_video_stream_get_buf_percentage(obj,percentage);
}

/*****************************************************************************
 * FUNCTION
 *  gs_video_stream_get_cur_play_time
 * DESCRIPTION
 * 
 * PARAMETERS
 *  cur_play_time : [OUT]Current play time.
 * RETURNS
 *  void
 *****************************************************************************/
void __inline gs_video_stream_get_cur_play_time(IVideoStream *obj,U64 *cur_play_time)
{
	obj->vt->gs_video_stream_get_cur_play_time(obj,cur_play_time);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_set_brightness
 * DESCRIPTION
 *  To set brightness parameter for video player.
 * PARAMETERS
 *  brightness : [IN]Brightness value
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to set brightness parameter to video player.
 *  GS_RES_VDOREC_ERR_FAILED : Fail to set brightness parameter to video player.
 *****************************************************************************/
S32 __inline IVideoStream_set_brightness(IVideoStream *obj,U16 brightness)
{
	return obj->vt->gs_video_stream_set_brightness(obj,brightness);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_set_contrast
 * DESCRIPTION
 *  To set contrast parameter to video player.
 * PARAMETERS
 *  contrast : [IN]Contrast value
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to set EV parameter to video player.
 *  GS_RES_VDOREC_ERR_FAILED : Fail to set EV parameter to video player.
 *****************************************************************************/
S32 __inline IVideoStream_set_contrast(IVideoStream *obj,U16 contrast)
{
	return obj->vt->gs_video_stream_set_contrast(obj, contrast);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_get_dimension
 * DESCRIPTION
 *  Get stream source dimension, this function may only be called after 
 *  calling mdi_video_stream_start_buffering, and buf percentage > 0
 * PARAMETERS
 *  video_width : [OUT]video width ptr
 *  video_height : [OUT]video height ptr 
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to get dimension.
 *  GS_RES_VDOPLY_ERR_FAILED : Fail to get dimension.
 *****************************************************************************/
S32 __inline IVideoStream_get_dimension(IVideoStream *obj,S32 *video_width, S32 *video_height)
{
	return obj->vt->gs_video_stream_get_dimension(obj,video_width, video_height);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_enable_partial_display
 * DESCRIPTION
 *  To enable video to play outside lcd region.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to enable partial display (outside lcd region) to video player.
 *  GS_RES_VDOREC_ERR_FAILED : Fail to enable partial display (outside lcd region) to video player.
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_set_stop_time
 * DESCRIPTION
 *  Set stop time for stream playback, currently for Java use only.
 * PARAMETERS
 *  stop_time : [IN]Stop time
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to set stop time to video player.
 *  GS_RES_VDOREC_ERR_FAILED : Fail to set stop time to video player.
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_set_sleep_time
 * DESCRIPTION
 *  Set sleep time, currently for Java use only.
 * PARAMETERS
 *  elapse_ticks : [IN] elapse time to make one sleep operation.
 *  sleep_ticks  : [IN] time duration per sleep.
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to set sleep time to video player.
 *  GS_RES_VDOREC_ERR_FAILED : Fail to set sleep time to video player.
 *****************************************************************************/



/*****************************************************************************
 * FUNCTION
 *  IVideoStream_is_drm_streaming
 * DESCRIPTION
 *  Check if it is drm stream or not.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE : It is a drm file.
 *  MMI_FALSE : It is not a drm file.
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_get_audio_info
 * DESCRIPTION
 *  To get stream audio info.
 * PARAMETERS
 *  
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to get audio info.
 *  GS_RES_VDORLY_ERR_FAILED : Fail to get audio info.
 *****************************************************************************/
S32 __inline IVideoStream_get_audio_info(IVideoStream *obj,PU8 aud_channel_no, PU16 aud_sample_rate)
{
	return obj->vt->gs_video_stream_get_audio_info( obj,aud_channel_no,  aud_sample_rate);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_stop_visual_update
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to stop visual update.
 *  GS_RES_VDORLY_ERR_FAILED : Fail to stop visual update.
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  IVideoStream_set_track
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to set track.
 *  GS_RES_VDORLY_ERR_FAILED : Fail to set track.
 *****************************************************************************/
S32 __inline IVideoStream_set_track(IVideoStream *obj,U8 type)
{
	return obj->vt->gs_video_stream_set_track(obj,type);
}


/*****************************************************************************
 * FUNCTION
 *  IVideoStream_set_uaprof_diff
 * DESCRIPTION
 *  set the uaprofile string.
 * PARAMETERS
 *  uaprof_p    [IN]  the profile url string pointer(char)
 * RETURNS
 *  GS_RES_VDOPLY_SUCCEED if success, otherwise GS_RES_VDOPLY_ERR_FAILED
 *****************************************************************************/
