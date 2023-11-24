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
 *   srv_videopdl_interface.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IVideoPDL interface
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
#include "gs_srv_videopdl_interface_def.h"

#include "gs_srv_videopdl_type.h"

/*****************************************************************************
 * IVideoPDL methods
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  IVideoPDL_addRef
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 * RETURNS
 *  The error code of the operation.
 *****************************************************************************/
S32 __inline IVideoPDL_addRef(IVideoPDL *obj)
{
    return obj->vt->addRef(obj);
}


/*****************************************************************************
 * FUNCTION
 *  IVideoPDL_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 * RETURNS
 *  The error code of the operation.
 *****************************************************************************/
S32 __inline IVideoPDL_release(IVideoPDL *obj)
{
    return obj->vt->release(obj);
}


/*****************************************************************************
 * FUNCTION
 *  IVideoPDL_queryInterface
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 *  iid : [IN]        
 *  pptr : [IN]        
 * RETURNS
 *  The error code of the operation.
 *****************************************************************************/
S32 __inline IVideoPDL_queryInterface(IVideoPDL *obj, S32 iid, GS_IBase **pptr)
{
    return obj->vt->queryInterface(obj, iid, pptr);
}


 /*****************************************************************************
 * FUNCTION
 *  IVideoPDL_open_file
 * DESCRIPTION
 *  To open progressive vidoe file.
 * PARAMETERS
 *  filename : [IN] Filename of the video.
 *  progressive_result_callback : [IN] Callback function of this open operation.
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to open video file, need to wait callback function when open operation is finished.
 *  GS_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT : Fail to open video file due to memory is insufficient.
 *  GS_RES_VDOPLY_ERR_OPEN_FILE_FAILED : Fail to open video file.
 *****************************************************************************/
S32 __inline IVideoPDL_open_file(IVideoPDL *obj,const S8 *filename,gs_progressive_result_callback progressive_result_callback,void* user_data)
{
	return obj->vt->gs_video_progressive_open_file(obj,filename, progressive_result_callback,user_data);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoPDL_close_file
 * DESCRIPTION
 *  To close the progressive video file.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to close progressive download file.
 *  GS_RES_VDORLY_ERR_FAILED : Fail to close progressive download file.
 *****************************************************************************/
S32 __inline IVideoPDL_close_file(IVideoPDL *obj)
{
	return obj->vt->gs_video_progressive_close_file(obj);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoPDL_get_max_play_time
 * DESCRIPTION
 *  To get the max play time of this progressive downloading file.
 * PARAMETERS
 *  max_play_time : [OUT] Max play time of this progressive downloading file.
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to get max play time.
 *  GS_RES_VDORLY_ERR_FAILED : Fail to get max play time.
 *****************************************************************************/
S32 __inline IVideoPDL_get_max_play_time(IVideoPDL *obj,U64 *max_play_time)
{
	return obj->vt->gs_video_progressive_get_max_play_time(obj,max_play_time);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoPDL_get_buf_percentage
 * DESCRIPTION
 *  To get current downloaded buffer percentage.
 * PARAMETERS
 *  buf_percentage : [OUT] Current buffer percentage.
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to get buffer percentage.
 *  GS_RES_VDORLY_ERR_FAILED : Fail to get buffer percentage.
 *****************************************************************************/
S32 __inline IVideoPDL_get_buf_percentage(IVideoPDL *obj,S32 *buf_percentage)
{
	return obj->vt->gs_video_progressive_get_buf_percentage(obj,buf_percentage);
}

/*****************************************************************************
 * FUNCTION
 *  IVideoPDL_is_pdl_format
 * DESCRIPTION
 *  To check if this video file is in progresssive download support format.
 * PARAMETERS
 *  file_buf : [IN] Filepath of the specific video file.
 *  buf_size : [IN] Buffer size of the file buffer.
 *  is_pdl : [OUT] Is this file is progressive download format.
 * RETURN VALUES
 *  GS_RES_VDOPLY_SUCCEED : Succeed to check this file.
 *  GS_RES_VDOPLY_ERR_OPEN_FILE_FAILED : Fail to check this file due to fail to open it.
 *  GS_RES_VDOPLY_ERR_FAILED : Fail to check this file.
 *****************************************************************************/
S32 __inline IVideoPDL_is_pdl_format(IVideoPDL *obj,U8 *file_buf, S32 buf_size, MMI_BOOL *is_pdl)
{
	return obj->vt->gs_video_progressive_is_pdl_format(obj,file_buf,  buf_size, is_pdl);
}

