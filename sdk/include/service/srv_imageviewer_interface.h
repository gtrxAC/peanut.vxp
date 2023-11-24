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
 *   srv_imageviewer_interface.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IImageviewer interface
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
 * 12 23 2010 lihong.li
 * NULL
 * .
 *
 * 12 16 2010 lihong.li
 * NULL
 * .
 *
 * 11 26 2010 isiah.chen
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
#ifndef SRV_IMAGEVIEWER_INTERFACE_H
#define SRV_IMAGEVIEWER_INTERFACE_H

#include "gs_id.h"
#include "gs_base.h"

#define GS_C_INTERFACE
#include "gs_srv_imageviewer_interface_def.h"

#include "gs_srv_imageviewer_type.h"

/*****************************************************************************
 * IImageviewer methods
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  IImageviewer_addRef
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 * RETURNS
 *  The error code of the operation.
 *****************************************************************************/
S32 __inline IImageviewer_addRef(IImageviewer *obj)
{
    return obj->vt->addRef(obj);
}


/*****************************************************************************
 * FUNCTION
 *  IImageviewer_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 * RETURNS
 *  The error code of the operation.
 *****************************************************************************/
S32 __inline IImageviewer_release(IImageviewer *obj)
{
    return obj->vt->release(obj);
}


/*****************************************************************************
 * FUNCTION
 *  IImageviewer_queryInterface
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 *  iid : [IN]        
 *  pptr : [IN]        
 * RETURNS
 *  The error code of the operation.
 *****************************************************************************/
S32 __inline IImageviewer_queryInterface(IImageviewer *obj, S32 iid, IBase **pptr)
{
    return obj->vt->queryInterface(obj, iid, pptr);
}


/*****************************************************************************
 * FUNCTION
 *  IImageviewer_close
 * DESCRIPTION
 *  Close imageviewer.
 * PARAMETERS
 *  obj  :  [IN]  object pointer.
 * RETURNS
 *  
 *****************************************************************************/
void __inline IImageviewer_close(IImageviewer *obj)
{
	obj->vt->close(obj);
}


/*****************************************************************************
 * FUNCTION
 *  IImageviewer_create
 * DESCRIPTION
 *  Creat imageviewer.
 * PARAMETERS
 *  obj  :  [IN]  object pointer.
 * RETURNS
 *  
 *****************************************************************************/
void __inline IImageviewer_create(IImageviewer *obj)
{
	return obj->vt->create(obj);
}


/*****************************************************************************
 * FUNCTION
 *  IImageviewer_run
 * DESCRIPTION
 *  Run imageviewer.
 * PARAMETERS
 *  obj  :  [IN]  object pointer.
 * RETURNS
 *  
 *****************************************************************************/
void __inline IImageviewer_run(IImageviewer *obj)
{
	return obj->vt->run(obj);
}


/*****************************************************************************
 * FUNCTION
 *  IImageviewer_setTitle
 * DESCRIPTION
 *  Set imageviewer title.
 * PARAMETERS
 *  obj  :  [IN]  object pointer.
 *  string  :  [IN]  title string.
 * RETURNS
 *  
 *****************************************************************************/
void  __inline IImageviewer_setTitle(IImageviewer *obj,WCHAR* string)
{
	return obj->vt->setTitle(obj,string);
}


/*****************************************************************************
 * FUNCTION
 *  IImageviewer_setUIDirection
 * DESCRIPTION
 *  Set imageviewer UI direction.
 * PARAMETERS
 *  obj  :  [IN]  object pointer.
 *  direction  :  [IN]  view direction.
 * RETURNS
 *  
 *****************************************************************************/
void __inline IImageviewer_setUIDirection(IImageviewer *obj,gs_imgview_ui_direction_enum direction)
{
	return obj->vt->setUIDirection(obj,direction);
}

/*****************************************************************************
 * FUNCTION
 *  IImageviewer_setModeFileName
 * DESCRIPTION
 *  Set image file name that want to view.
 * PARAMETERS
 *  obj  :  [IN]  object pointer.
 *  filename  :  [IN]  full file name in WideChar.
 * RETURNS
 *  
 *****************************************************************************/
void __inline IImageviewer_setModeFileName(IImageviewer *obj,PS8 filename)
{
	return obj->vt->setModeFileName(obj,filename);
}


#endif
