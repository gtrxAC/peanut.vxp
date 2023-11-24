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
 *   gs_srv_idlescreen_interface_def.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IIdleScreen interface
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
 * 11 25 2010 isiah.chen
 * NULL
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "gs_idef.h"
#include "gs_memory.h"

#include "gs_srv_idlescreen_type.h"



/***************************************************************************** 
* 
*****************************************************************************/
#define DEF_METHODS_IIDLESCREEN(IOBJ) \
    DEF_METHODS_GS_IBase(IOBJ) \
	DEF_METHOD3(IOBJ,S32,networkGetName,gs_sim_enum,sim, WCHAR*,name, S32,size)\
	DEF_METHOD4(IOBJ,S32,networkGetNameEx,gs_sim_enum,sim, nw_name_type_enum,type,WCHAR*,name, S32,size)\
	DEF_METHOD3(IOBJ,S32,networkGetNameIfAny,gs_sim_enum,sim, WCHAR*,name, S32,size)\
	DEF_METHOD3(IOBJ,S32,networkGetSPN,gs_sim_enum,sim, WCHAR*,name, S32,size)\
    DEF_METHOD1(IOBJ, MMI_BOOL, networkNameServiceIsReady, gs_sim_enum,sim) \
	DEF_METHOD2(IOBJ,MMI_BOOL,networkGetLocationInfo,gs_sim_enum,sim, nw_info_location_info_struct*,out_info)\
	DEF_METHOD5(IOBJ,MMI_BOOL,eonsGetName,gs_sim_enum,sim, const S8*,plmn, U16,lac, eons_get_name_cb,callback, void*,user_data)\
    DEF_METHOD1(IOBJ, MMI_BOOL, eonsServiceIsReady, gs_sim_enum,sim)

DEF_INTERFACE(IIdleScreen, GS_IBase)
    DEF_METHODS_IIDLESCREEN(IIdleScreen)
DEF_INTERFACE_END(IIdleScreen)


