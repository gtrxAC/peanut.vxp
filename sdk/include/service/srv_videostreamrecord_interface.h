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
*   srv_videostreamrecord_interface.h
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   IVideoStreamRecord interface
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
#include "gs_srv_videostreamrecord_interface_def.h"

#include "gs_srv_videostreamrecord_type.h"

/*****************************************************************************
* IVideoStreamRecord methods
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  IVideoStreamRecord_addRef
* DESCRIPTION
*  
* PARAMETERS
*  obj : [IN] Pointer to object.
* RETURNS
*  The error code of the operation.
*****************************************************************************/
S32 __inline IVideoStreamRecord_addRef(IVideoStreamRecord *obj)
{
	return obj->vt->addRef(obj);
}


/*****************************************************************************
* FUNCTION
*  IVideoStreamRecord_release
* DESCRIPTION
*  
* PARAMETERS
*  obj : [IN] Pointer to object.
* RETURNS
*  The error code of the operation.
*****************************************************************************/
S32 __inline IVideoStreamRecord_release(IVideoStreamRecord *obj)
{
	return obj->vt->release(obj);
}


/*****************************************************************************
* FUNCTION
*  IVideoStreamRecord_queryInterface
* DESCRIPTION
*  
* PARAMETERS
*  obj : [IN] Pointer to object.
*  iid : [IN]        
*  pptr : [IN]        
* RETURNS
*  The error code of the operation.
*****************************************************************************/
S32 __inline IVideoStreamRecord_queryInterface(IVideoStreamRecord *obj, S32 iid, IBase **pptr)
{
	return obj->vt->queryInterface(obj, iid, pptr);
}


S32 __inline IVideoStreamRecord_open(IVideoStreamRecord *obj, PS8 p_file_path)
{
	return obj->vt->gs_video_stream_rec_open(obj,  p_file_path);
}

S32 __inline IVideoStreamRecord_close(IVideoStreamRecord *obj)
{
	return obj->vt->gs_video_stream_rec_close(obj);

}


S32 __inline IVideoStreamRecord_save(IVideoStreamRecord *obj, PS8 p_file_path, gs_video_stream_record_save_result_callback save_result_callback)
{
	return obj->vt->gs_video_stream_rec_save(obj,  p_file_path,  save_result_callback);

}


S32 __inline IVideoStreamRecord_save_abort(IVideoStreamRecord *obj)
{
	return obj->vt->gs_video_stream_rec_save_abort(obj);

}
void __inline IVideoStreamRecord_delete_unsaved_file(IVideoStreamRecord *obj, PS8 dir)
{
	return obj->vt->gs_video_stream_rec_delete_unsaved_file(obj,  dir);

}

BOOL __inline IVideoStreamRecord_have_unsaved_file(IVideoStreamRecord *obj, PS8 dir)
{
	return obj->vt->gs_video_stream_rec_have_unsaved_file(obj,  dir);
}
