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
*   srv_mmvideo_interface.h
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   IMMVideo interface
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
 * 03 28 2011 isiah.chen
 * [MAUI_02656715] 11AW11.12MP check in
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
 * 02 25 2011 isiah.chen
 * [MAUI_02652532] MRE2.0 11A
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

#ifndef SRV_MMVIDEO_INTERFACE_H
#define SRV_MMVIDEO_INTERFACE_H

#include "gs_id.h"
#include "gs_base.h"

#define GS_C_INTERFACE
#include "gs_srv_mmvideo_interface_def.h"

#include "gs_srv_mmvideo_type.h"

/*****************************************************************************
* IMMVideo methods
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  IMMVideo_addRef
* DESCRIPTION
*  
* PARAMETERS
*  obj : [IN] Pointer to object.
* RETURNS
*  The error code of the operation.
*****************************************************************************/
S32 __inline IMMVideo_addRef(IMMVideo *obj)
{
	return obj->vt->addRef(obj);
}


/*****************************************************************************
* FUNCTION
*  IMMVideo_release
* DESCRIPTION
*  
* PARAMETERS
*  obj : [IN] Pointer to object.
* RETURNS
*  The error code of the operation.
*****************************************************************************/
S32 __inline IMMVideo_release(IMMVideo *obj)
{
	return obj->vt->release(obj);
}


/*****************************************************************************
* FUNCTION
*  IMMVideo_queryInterface
* DESCRIPTION
*  
* PARAMETERS
*  obj : [IN] Pointer to object.
*  iid : [IN]        
*  pptr : [IN]        
* RETURNS
*  The error code of the operation.
*****************************************************************************/
S32 __inline IMMVideo_queryInterface(IMMVideo *obj, S32 iid, GS_IBase **pptr)
{
	return obj->vt->queryInterface(obj, iid, pptr);
}




S32 __inline IMMVideo_video_ply_open_file(IMMVideo *obj,const S8* filename,gs_open_result_callback open_result_callback,void* user_data)
{
	return obj->vt->video_ply_open_file(obj,filename,open_result_callback,user_data);
}

S32 __inline IMMVideo_video_ply_close_file(IMMVideo *obj)
{
	return obj->vt->video_ply_close_file(obj);
}
S32 __inline IMMVideo_video_ply_play(IMMVideo *obj,gs_video_play_struct* pPlayStruct,gs_play_finish_callback callback,void* user_data)
{
	return obj->vt->video_ply_play(obj,pPlayStruct,callback,user_data);
}

S32 __inline IMMVideo_video_ply_stop(IMMVideo *obj)
{
	return obj->vt->video_ply_stop(obj);
}




S32 __inline IMMVideo_video_ply_snapshot(IMMVideo *obj,S32 layer_handle, PS8 file_name)
{
	return obj->vt->video_ply_snapshot(obj, layer_handle,  file_name);
}

void __inline IMMVideo_video_ply_get_cur_play_time(IMMVideo *obj,U64 *cur_play_time)
{
	obj->vt->video_ply_get_cur_play_time(obj,cur_play_time);
}



S32 __inline IMMVideo_video_ply_seek_and_get_frame(IMMVideo *obj,int time,S32 player_layer_handle)
{
	return obj->vt->video_ply_seek_and_get_frame( obj, time, player_layer_handle);
}

S32 __inline IMMVideo_video_ply_test(IMMVideo* obj,U64 para)
{
	return obj->vt->video_ply_test(obj,para);
}

S32 __inline IMMVideo_video_ply_test_1(IMMVideo* obj,U64 para,U32 p2)
{
	return obj->vt->video_ply_test_1(obj,para,p2);
}

S32 __inline IMMVideo_video_ply_non_block_seek_and_get_frame(IMMVideo *obj,int time,
                    S32 player_layer_handle,
                    gs_seek_result_callback seek_result_callback,
                    void *user_data)
{
	return obj->vt->video_ply_non_block_seek_and_get_frame(obj,time,player_layer_handle,seek_result_callback,user_data);
}


S32 __inline IMMVideo_video_ply_stop_non_block_seek(IMMVideo *obj)
{
	return obj->vt->video_ply_stop_non_block_seek(obj);
}


S32 __inline IMMVideo_video_ply_set_brightness(IMMVideo *obj,U16 brightness)
{
	return obj->vt->video_ply_set_brightness(obj, brightness);
}

S32 __inline IMMVideo_video_ply_set_contrast(IMMVideo *obj,U16 contrast)
{
	return obj->vt->video_ply_set_contrast(obj, contrast);
}


S32 __inline IMMVideo_video_ply_check_is_able_to_play(IMMVideo *obj,PS8 file_name)
{
	return obj->vt->video_ply_check_is_able_to_play(obj,file_name);
}


BOOL __inline IMMVideo_video_is_playing(IMMVideo *obj)
{
	return obj->vt->video_is_playing(obj);
}

BOOL __inline IMMVideo_video_is_recording(IMMVideo *obj)
{
	return obj->vt->video_is_recording(obj);
}

S32 __inline IMMVideo_video_ply_get_total_duration(IMMVideo *obj,const S8 *filename, U64* total_duration)
{
	return obj->vt->video_ply_get_total_duration(obj,filename, total_duration);
}


#endif

