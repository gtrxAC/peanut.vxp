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
 *   gs_srv_appmgr_interface_def.h
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

#include "gs_idef.h"
//#include "gs_memory.h"

#include "gs_srv_appmgr_type.h"

/***************************************************************************** 
* IAppmgr
*****************************************************************************/   
DEF_INTERFACE(IAppmgr, GS_IBase)

    DEF_METHODS_GS_IBase(IAppmgr)
    DEF_METHOD1(IAppmgr,U32,get_app_package_num,gs_appmgr_query_type_enum,flag)  
    DEF_METHOD3(IAppmgr,S32,get_app_package_list,gs_appmgr_query_type_enum,flag,gs_app_package_name_struct*,name_array,U32,num)
    DEF_METHOD2(IAppmgr,S32,get_app_package_name,const CHAR*,app_name,WCHAR *,string)
    DEF_METHOD2(IAppmgr,S32,get_app_package_image,const CHAR*,app_name,gs_image_src_struct *,image)
    DEF_METHOD2(IAppmgr,S32,get_app_package_badge,const CHAR*,app_name,WCHAR *,badge)
    DEF_METHOD1(IAppmgr,gs_appmgr_app_package_type_enum,get_app_package_type,const CHAR*,app_name)
    DEF_METHOD1(IAppmgr,U16,launch_app,const CHAR*,app_name)    
    DEF_METHOD1(IAppmgr,S32,install_app,const CHAR*,file_path)
    DEF_METHOD3(IAppmgr,S32,uninstall_app,const CHAR*,app_name, gs_appmgr_uninstall_cb_fct, cb_fct, void*, user_data)
    DEF_METHOD2(IAppmgr,S32,reg_event_hdlr,gs_appmgr_event_cb_fct, cb_fct, void*, user_data)
    DEF_METHOD0(IAppmgr,void,unreg_event_hdlr)
DEF_INTERFACE_END(IAppmgr)


