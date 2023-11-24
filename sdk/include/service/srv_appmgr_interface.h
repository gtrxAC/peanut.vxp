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
 *   srv_appmgr_interface.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IAppmgr interface
 *
 * Author:
 * -------
 *  Jia Luo
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "gs_id.h"
#include "gs_base.h"

#define GS_C_INTERFACE
#include "gs_srv_appmgr_interface_def.h"

#include "gs_srv_appmgr_type.h"

/*****************************************************************************
 * Imms methods
 *****************************************************************************/

S32 __inline IAppmgr_addRef(IAppmgr *obj)
{
    return obj->vt->addRef(obj);
}


S32 __inline IAppmgr_release(IAppmgr *obj)
{
    return obj->vt->release(obj);
}


S32 __inline IAppmgr_queryInterface(IAppmgr *obj, S32 iid, GS_IBase **pptr)
{
    return obj->vt->queryInterface(obj, iid, pptr);
}

  
U32 __inline IAppmgr_get_app_package_num(IAppmgr *obj, gs_appmgr_query_type_enum flag)
{
    return obj->vt->get_app_package_num(obj, flag);
}


S32 __inline IAppmgr_get_app_package_list(IAppmgr *obj, gs_appmgr_query_type_enum flag,gs_app_package_name_struct* name_array,U32 num)
{
    return obj->vt->get_app_package_list(obj, flag,name_array,num);
}

S32 __inline IAppmgr_get_app_package_name(IAppmgr *obj, const CHAR* app_name,WCHAR * string)
{
    return obj->vt->get_app_package_name(obj, app_name,string);
}

S32 __inline IAppmgr_get_app_package_image(IAppmgr *obj, const CHAR* app_name,gs_image_src_struct * image)
{
    return obj->vt->get_app_package_image(obj, app_name, image);
}

S32 __inline IAppmgr_get_app_package_badge(IAppmgr *obj, const CHAR* app_name,WCHAR * badge)
{
    return obj->vt->get_app_package_badge(obj, app_name, badge);
}

gs_appmgr_app_package_type_enum __inline IAppmgr_get_app_package_type(IAppmgr *obj, const CHAR* app_name)
{
    return obj->vt->get_app_package_type(obj, app_name);
}

U16 __inline IAppmgr_launch_app(IAppmgr *obj, const CHAR* app_name)  
{
    return obj->vt->launch_app(obj, app_name);
}

S32 __inline IAppmgr_install_app(IAppmgr *obj, const CHAR* file_path)
{
    return obj->vt->install_app(obj, file_path);
}

S32 __inline IAppmgr_uninstall_app(IAppmgr *obj, const CHAR* app_name, gs_appmgr_uninstall_cb_fct cb_fct, void* user_data)
{
    return obj->vt->uninstall_app(obj, app_name, cb_fct, user_data);
}

S32 __inline IAppmgr_reg_event_hdlr(IAppmgr *obj, gs_appmgr_event_cb_fct cb_fct, void* user_data)
{
    return obj->vt->reg_event_hdlr(obj, cb_fct, user_data);
}

void __inline IAppmgr_unreg_event_hdlr(IAppmgr *obj)
{
    obj->vt->unreg_event_hdlr(obj);
}


