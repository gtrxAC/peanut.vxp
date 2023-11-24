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
*   srv_videorecord_interface.h
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   IVideoRecord interface
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
#include "gs_srv_videorecord_interface_def.h"

#include "gs_srv_videorecord_type.h"

/*****************************************************************************
* IVideoRecord methods
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  IVideoRecord_addRef
* DESCRIPTION
*  
* PARAMETERS
*  obj : [IN] Pointer to object.
* RETURNS
*  The error code of the operation.
*****************************************************************************/
S32 __inline IVideoRecord_addRef(IVideoRecord *obj)
{
	return obj->vt->addRef(obj);
}


/*****************************************************************************
* FUNCTION
*  IVideoRecord_release
* DESCRIPTION
*  
* PARAMETERS
*  obj : [IN] Pointer to object.
* RETURNS
*  The error code of the operation.
*****************************************************************************/
S32 __inline IVideoRecord_release(IVideoRecord *obj)
{
	return obj->vt->release(obj);
}


/*****************************************************************************
* FUNCTION
*  IVideoRecord_queryInterface
* DESCRIPTION
*  
* PARAMETERS
*  obj : [IN] Pointer to object.
*  iid : [IN]        
*  pptr : [IN]        
* RETURNS
*  The error code of the operation.
*****************************************************************************/
S32 __inline IVideoRecord_queryInterface(IVideoRecord *obj, S32 iid, GS_IBase **pptr)
{
	return obj->vt->queryInterface(obj, iid, pptr);
}


/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_set_camera_id
 * DESCRIPTION
 *  Choose the camera sensor.
 * PARAMETERS
 *  camera_id : [IN] Camera sensor id [main or sub]
 * RETURN VALUES
 *  GS_RES_VDOREC_SUCCEED : Succeed to set camera id.
 *  GS_RES_VDOREC_ERR_FAILED : Fail to set camera id.
 *****************************************************************************/
S32 __inline IVideoRecord_set_camera_id(IVideoRecord *obj,U16 camera_id)
{
	return obj->vt->gs_video_set_camera_id(obj, camera_id);
}


/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_detect_sensor_id
 * DESCRIPTION
 *  To detect camera sensor module id.
 * PARAMETERS
 *  cam_id : [IN] Main/Sub camera sensor id.
 * RETURN VALUES
 *  GS_RES_VDOREC_SUCCEED : Succeed to detect camera sensor module id.
 *  GS_RES_VDOREC_ERR_FAILED : Fail to detect camera sensor module id.
 *****************************************************************************/
S32 __inline IVideoRecord_detect_sensor_id(IVideoRecord *obj,U8 cam_id)
{
	return obj->vt->gs_video_detect_sensor_id(obj, cam_id);
}


/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_power_on
 * DESCRIPTION
 *  To power on recorder hw.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOREC_SUCCEED : Succeed to power on camera module.
 *  GS_RES_VDOREC_ERR_POWER_ON_FAILED : Fail to power on camera module.
 *****************************************************************************/
S32 __inline IVideoRecord_power_on(IVideoRecord *obj)
{
	return obj->vt->gs_video_rec_power_on(obj);
}


/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_power_off
 * DESCRIPTION
 *  To power off recorder hw.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOREC_SUCCEED : Succeed to power off camera module.
 *  GS_RES_VDOREC_ERR_FAILED : Fail to power off camera module.
 *****************************************************************************/
S32 __inline IVideoRecord_power_off(IVideoRecord *obj)
{
	return obj->vt->gs_video_rec_power_off(obj);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_start
 * DESCRIPTION
 *  To start recording.
 * PARAMETERS
 *  filename : [IN] Video clip's filename.
 *  record_result_callback : [IN] Record result callback function ptr.
 * RETURN VALUES
 *  GS_RES_VDOREC_SUCCEED : Succeed to start recording.
 *  GS_RES_VDOREC_ERR_DISK_FULL : Fail to start recording due to disk is full.
 *  GS_RES_VDOREC_ERR_WRITE_PROTECTION : Fail to start recording due to disk is in write protection mode.
 *  GS_RES_VDOREC_ERR_FAILED : Fail to start recording due to open file fail.
 *  GS_RES_VDOREC_ERR_RECORD_FAILED : Fail to start recording.
 *****************************************************************************/
S32 __inline IVideoRecord_start(IVideoRecord *obj,S8 *filename, gs_record_result_callback record_result_callback,void* user_data)
{
	return obj->vt->gs_video_rec_record_start(obj,filename,  record_result_callback,user_data);
}


/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_stop
 * DESCRIPTION
 *  To stop recording.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOREC_SUCCEED : Succeed to stop recording.
 *  GS_RES_VDOREC_ERR_FAILED : Fail to stop recording.
 *****************************************************************************/
S32 __inline IVideoRecord_stop(IVideoRecord *obj)
{
	return obj->vt->gs_video_rec_record_stop(obj);
}



/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_pause
 * DESCRIPTION
 *  To pause recording.
 * PARAMETERS
 *  stop_preview : [IN] To stop preview or not.
 * RETURN VALUES
 *  GS_RES_VDOREC_SUCCEED : Succeed to pause recording.
 *  GS_RES_VDOREC_RECORD_ALREADY_STOP : Fail to pause recording due to it is already stopped.
 *  GS_RES_VDOREC_REACH_SIZE_LIMIT : Fail to pause recording due to due to it is reached record size limitation (already stopped).
 *  GS_RES_VDOREC_ERR_DISK_FULL : Fail to pause recording due to disk is full (already stopped).
 *  GS_RES_VDOREC_ERR_PAUSE_FAILED : Fail to pause recording.
 *****************************************************************************/
S32 __inline IVideoRecord_pause(IVideoRecord *obj,MMI_BOOL stop_preview)
{
	return obj->vt->gs_video_rec_record_pause(obj, stop_preview);
}


/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_resume
 * DESCRIPTION
 *  To resume recording.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOREC_SUCCEED : Succeed to resume recording.
 *  GS_RES_VDOREC_RECORD_ALREADY_STOP : Fail to resume recording due to it is already stopped.
 *  GS_RES_VDOREC_ERR_RESUME_FAILED : Fail to resume recording.
 *****************************************************************************/
S32 __inline IVideoRecord_resume(IVideoRecord *obj)
{
	return obj->vt->gs_video_rec_record_resume(obj);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_preview_start
 * DESCRIPTION
 *  To start preview for video recorder.
 * PARAMETERS
 *  preview_layer_handle : [IN] Layer handle of preview layer.
 *  blt_layer_flag : [IN] Blt out layer flag.
 *  preview_layer_flag : [IN] Preview layer flag.
 *  is_lcd_update : [IN] Update lcd or not.
 *  setting_p : [IN] Setting data.
 * RETURN VALUES
 *  GS_RES_VDOREC_SUCCEED : Succeed to start preview.
 *  GS_RES_VDOREC_ERR_HW_NOT_READY : Fail to start preview.
 *****************************************************************************/
S32 __inline IVideoRecord_preview_start(
									  IVideoRecord *obj,
									  S32 preview_layer_handle,
									  MMI_BOOL is_lcd_update,
									  gs_video_setting_struct *setting_p)
{
	return obj->vt->gs_video_rec_preview_start(
									  obj,
									   preview_layer_handle,
									   is_lcd_update,
									  setting_p);
}


/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_preview_stop
 * DESCRIPTION
 *  To stop preview or recorder.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOREC_SUCCEED : Succeed to stop preview.
 *  GS_RES_VDOREC_ERR_FAILED : Fail to stop preview.
 *****************************************************************************/
S32 __inline IVideoRecord_preview_stop(IVideoRecord *obj)
{
	return obj->vt->gs_video_rec_preview_stop(obj);
}


/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_save_file
 * DESCRIPTION
 *  To merge and save file in non-blocking mode.
 * PARAMETERS
 *  filepath : [IN] Path to merge file.
 *  save_result_callback : [IN] Callback function for this operation.
 * RETURN VALUES
 *  GS_RES_VDOREC_SUCCEED : Succeed to send save request to media task.
 *  GS_RES_VDOREC_ERR_FAILED : Fail to send save request to media task.
 *****************************************************************************/
S32 __inline IVideoRecord_save_file(IVideoRecord *obj,S8 *filepath,  gs_save_result_callback save_result_callback,void* user_data)
{
	return obj->vt->gs_video_rec_save_file(obj,filepath,  save_result_callback,user_data);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_stop_save
 * DESCRIPTION
 *  To stop record saving.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOREC_SUCCEED : Succeed to stop save operation.
 *  GS_RES_VDOREC_ERR_FAILED : Fail to stop save operation.
 *****************************************************************************/
S32 __inline IVideoRecord_stop_save(IVideoRecord *obj)
{
	return obj->vt->gs_video_rec_stop_save(obj);
}


/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_has_unsaved_file
 * DESCRIPTION
 *  To check if there is an unsaved video clip.
 * PARAMETERS
 *  filepath : [IN] Path to check.
 * RETURN VALUES
 *  MMI_TRUE : There is unsaved video clip.
 *  MMI_FALSE : There is no unsaved video clip.
 *****************************************************************************/
BOOL __inline IVideoRecord_has_unsaved_file(IVideoRecord *obj,S8 *filepath)
{
	return obj->vt->gs_video_rec_has_unsaved_file(obj,filepath);
}


/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_delete_unsaved_file
 * DESCRIPTION
 *  To delete unsaved video file.
 * PARAMETERS
 *  filepath : [IN] Path of unsaved video temp file to be deleted.
 * RETURNS
 *  void
 *****************************************************************************/
void __inline IVideoRecord_delete_unsaved_file(IVideoRecord *obj,S8 *filepath)
{
	 obj->vt->gs_video_rec_delete_unsaved_file(obj,filepath);
}


/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_get_cur_record_time
 * DESCRIPTION
 *  To get current recorded time.
 * PARAMETERS
 *  cur_record_time : [OUT] Current recorded time.
 * RETURNS
 *  void
 ****************************************************************************/
void __inline IVideoRecord_get_cur_record_time(IVideoRecord *obj,U64 *cur_record_time)
{
	 obj->vt->gs_video_rec_get_cur_record_time(obj,cur_record_time);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_update_para_ev
 * DESCRIPTION
 *  To update ev setting value.
 * PARAMETERS
 *  para : [IN] Ev setting parameter.
 * RETURNS
 *  void
 *****************************************************************************/
void __inline IVideoRecord_update_para_ev(IVideoRecord *obj,U16 para)
{
	 obj->vt->gs_video_rec_update_para_ev(obj,para);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_update_para_zoom
 * DESCRIPTION
 *  To update zoom setting value
 * PARAMETERS
 *  para : [IN] Zoom setting parameter.
 * RETURNS
 *  void
 *****************************************************************************/
void __inline IVideoRecord_update_para_zoom(IVideoRecord *obj,U16 para)
{
	 obj->vt->gs_video_rec_update_para_zoom(obj, para);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_update_para_effect
 * DESCRIPTION
 *  To update effect setting value.
 * PARAMETERS
 *  para : [IN] Effect setting parameter.
 * RETURNS
 *  void
 *****************************************************************************/
void __inline IVideoRecord_update_para_effect(IVideoRecord *obj,U16 para)
{
	 obj->vt->gs_video_rec_update_para_effect(obj, para);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_update_para_wb
 * DESCRIPTION
 *  To update wb setting value.
 * PARAMETERS
 *  para : [IN] White balance setting parameter.
 * RETURNS
 *  void
 *****************************************************************************/
void __inline IVideoRecord_update_para_wb(IVideoRecord *obj,U16 para)
{
	 obj->vt->gs_video_rec_update_para_wb(obj, para);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_update_para_night
 * DESCRIPTION
 *  To update night mode setting value
 * PARAMETERS
 *  para : [IN] Night mode setting parameter
 * RETURNS
 *  void
 *****************************************************************************/
void __inline IVideoRecord_update_para_night(IVideoRecord *obj,U16 para)
{
	 obj->vt->gs_video_rec_update_para_night(obj, para);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_get_max_zoom_factor
 * DESCRIPTION
 *  To get max zoom factor based on resoultion
 * PARAMETERS
 *  record_width : [IN] Record size width
 *  record_height : [IN] Record size height
 * RETURNS
 *  Current zoom factor.
 *****************************************************************************/
U16 __inline IVideoRecord_get_max_zoom_factor(IVideoRecord *obj,S32 record_width, S32 record_height)
{
	return obj->vt->gs_video_rec_get_max_zoom_factor(obj, record_width,  record_height);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_get_record_file_size
 * DESCRIPTION
 *  To get current record file size
 * PARAMETERS
*   void
 * RETURNS
 *  Current file size of the recording.
 *****************************************************************************/
U64 __inline IVideoRecord_get_record_file_size(IVideoRecord *obj)
{
	return obj->vt->gs_video_rec_get_record_file_size(obj);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_load_default_setting
 * DESCRIPTION
 *  Initialize default setting value for video preview/record structure.
 * PARAMETERS
 *  setting_p : [OUT] Setting data (All member data in its default values).
 * RETURNS
 *  void
 *****************************************************************************/
void __inline IVideoRecord_load_default_setting( IVideoRecord *obj,gs_video_setting_struct *setting_p)
{
	 obj->vt->gs_video_rec_load_default_setting( obj,setting_p);
}






/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_update_blt_pause
 * DESCRIPTION
 *  Pause for update blt parameters, special function for Java use only; This function should be pariled with mdi_video_rec_resume_for_update_blt_para().
 * EXAMPLE
 *  mdi_video_rec_update_blt_pause();
 *  ....
 *  update related GDI layer configuration
 *  ....
 *  mdi_video_rec_update_blt_resume(); 
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOREC_SUCCEED : Succeed to pause to update blt layers.
 *  GS_RES_VDOREC_ERR_FAILED : Fail to pause.
 *****************************************************************************/
S32 __inline IVideoRecord_update_blt_pause(IVideoRecord *obj)
{
	return obj->vt->gs_video_rec_update_blt_pause(obj);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoRecord_update_blt_resume
 * DESCRIPTION
 *  Resume for update blt parameters, special function for Java use only; This function should be pariled with mdi_video_rec_resume_for_update_blt_para().
 * EXAMPLE
 *  mdi_video_rec_update_blt_pause();
 *  ....
 *  update related GDI layer configuration
 *  ....
 *  mdi_video_rec_update_blt_resume();
 * PARAMETERS
 *  preview_layer_handle : [IN] Layer for preview.
 *  blt_layer_flag : [IN] Blt out layer flag.
 *  preview_layer_flag : [IN] Preview layer flag.
 *  is_lcd_update : [IN] Update lcd or not.
 * RETURNS
 *  GS_RES_VDOREC_SUCCEED : Succeed to resume after updating blt layers.
 *  GS_RES_VDOREC_ERR_FAILED : Fail to resume.
 *****************************************************************************/
S32 __inline IVideoRecord_update_blt_resume(
	IVideoRecord *obj,
	S32 preview_layer_handle,
	U32 blt_layer_flag,     
	U32 preview_layer_flag, 
	MMI_BOOL is_lcd_update)
{
	return obj->vt->gs_video_rec_update_blt_resume(obj,preview_layer_handle,blt_layer_flag,preview_layer_flag, is_lcd_update);
}




