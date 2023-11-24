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
*   srv_idlescreen_interface.h
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
 * 11 26 2010 isiah.chen
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
#include "gs_srv_idlescreen_interface_def.h"

#include "gs_srv_idlescreen_type.h"

/*****************************************************************************
* IIdleScreen methods
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  IIdleScreen_addRef
* DESCRIPTION
*  
* PARAMETERS
*  obj : [IN] Pointer to object.
* RETURNS
*  The error code of the operation.
*****************************************************************************/
S32 __inline IIdleScreen_addRef(IIdleScreen *obj)
{
	return obj->vt->addRef(obj);
}


/*****************************************************************************
* FUNCTION
*  IIdleScreen_release
* DESCRIPTION
*  
* PARAMETERS
*  obj : [IN] Pointer to object.
* RETURNS
*  The error code of the operation.
*****************************************************************************/
S32 __inline IIdleScreen_release(IIdleScreen *obj)
{
	return obj->vt->release(obj);
}


/*****************************************************************************
* FUNCTION
*  IIdleScreen_queryInterface
* DESCRIPTION
*  
* PARAMETERS
*  obj : [IN] Pointer to object.
*  iid : [IN]        
*  pptr : [IN]        
* RETURNS
*  The error code of the operation.
*****************************************************************************/
S32 __inline IIdleScreen_queryInterface(IIdleScreen *obj, S32 iid, IBase **pptr)
{
	return obj->vt->queryInterface(obj, iid, pptr);
}

/*****************************************************************************
 * FUNCTION
 *  IIdleScreen_networkGetName
 * DESCRIPTION
 *  This function gets the network name. It consider the "Display Condition"
 *  byte in the EF_SPN.
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 *  sim             : [IN]      SIM ID
 *  name            : [OUT]     Name string
 *  size            : [IN]      Size of the 'name' buffer in WORD.
 * RETURNS
 *  String length.
 *****************************************************************************/
S32   __inline IIdleScreen_networkGetName(IIdleScreen *obj,mmi_sim_enum sim, WCHAR * name, S32 size)
{
    return obj->vt->networkGetName( obj,sim,  name,  size);
}


/*****************************************************************************
 * FUNCTION
 *  IIdleScreen_networkGetNameEx
 * DESCRIPTION
 *  This function gets the operator name.
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 *  sim             : [IN]      SIM ID
 *  type            : [IN]      Network name type
 *  name            : [OUT]     Name string
 *  size            : [IN]      Size of the 'name' buffer in WORD.
 * RETURNS
 *  String length.
 *****************************************************************************/
S32  __inline IIdleScreen_networkGetNameEx(IIdleScreen *obj,mmi_sim_enum sim, nw_name_type_enum type, WCHAR * name, S32 size)
{
	return obj->vt->networkGetNameEx(obj,sim, type,  name, size);
}


/*****************************************************************************
 * FUNCTION
 *  IIdleScreen_networkGetNameIfAny
 * DESCRIPTION
 *  This function gets the network name. It consider the "Display Condition"
 *  byte in the EF_SPN.
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 *  sim             : [IN]      SIM ID
 *  name            : [OUT]     Name string
 *  size            : [IN]      Size of the 'name' buffer in WORD.
 * RETURNS
 *  String length.
 *****************************************************************************/
S32  __inline IIdleScreen_networkGetNameIfAny(IIdleScreen *obj,mmi_sim_enum sim, WCHAR * name, S32 size)
{
	return obj->vt->networkGetNameIfAny(obj,sim, name, size);
}


/*****************************************************************************
 * FUNCTION
 *  IIdleScreen_networkGetSPN
 * DESCRIPTION
 *  This function gets the Service Provider Name (SPN).
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 *  sim             : [IN]      SIM ID
 *  name            : [OUT]     Name string
 *  size            : [IN]      Size of the 'name' buffer in WORD.
 * RETURNS
 *  String length.
 *****************************************************************************/
S32  __inline IIdleScreen_networkGetSPN(IIdleScreen *obj,mmi_sim_enum sim, WCHAR * name, S32 size)
{
	return obj->vt->networkGetSPN(obj,sim, name, size);

}


/*****************************************************************************
 * FUNCTION
 *  IIdleScreen_networkNameServiceIsReady
 * DESCRIPTION
 *  This function checks if the service is ready.
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 *  sim             : [IN]      SIM ID
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL  __inline IIdleScreen_networkNameServiceIsReady(IIdleScreen *obj,mmi_sim_enum sim)
{
	return obj->vt->networkNameServiceIsReady(obj,sim);
}


/*****************************************************************************
 * FUNCTION
 *  IIdleScreen_networkGetLocationInfo
 * DESCRIPTION
 *  Get location information. Client can use function to get current PLMN,
 *  lac or cell ID.
 *  If the network is disabled by mode setting, the out_info returned is invalid.
 *  Please check the setting before calling this function.
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 *  sim         : [IN] Which protocol layer of SIM
 *  out_info    : [OUT] Output location info.
 * RETURN VALUES
 *  MMI_TRUE    : If out_info is valid.
 *  MMI_FALSE   : If location is not available. For example, on the condition
 *                of SEARCHING, or NO_SERVICE.
 *****************************************************************************/
MMI_BOOL  __inline IIdleScreen_networkGetLocationInfo(IIdleScreen *obj,mmi_sim_enum sim, nw_info_location_info_struct * out_info)
{
	return obj->vt->networkGetLocationInfo( obj,sim, out_info);
}


/*****************************************************************************
 * FUNCTION
 *  IIdleScreen_eonsGetName
 * DESCRIPTION
 *  This function gets the name assoicated with this (PLMN, LAC) couple.
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 *  sim             : [IN]      SIM ID
 *  plmn            : [IN]      PLMN. Should be NULL terminated.
 *  lac             : [IN]      LAC
 *  callback        : [IN]      Callback function
 *  user_data       : [IN]      User data
 * RETURNS
 *  If the name is present, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL  __inline IIdleScreen_eonsGetName(IIdleScreen *obj,mmi_sim_enum sim, const S8 * plmn, U16 lac, eons_get_name_cb callback, void * user_data)
{
	return obj->vt->eonsGetName(obj,sim, plmn, lac, callback, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  IIdleScreen_eonsServiceIsReady
 * DESCRIPTION
 *  This function checks if the EONS service is ready.
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 *  sim             : [IN]      SIM ID
 * RETURNS
 *  If the name is ready, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL  __inline IIdleScreen_eonsServiceIsReady(IIdleScreen *obj,mmi_sim_enum sim)
{
	return obj->vt->eonsServiceIsReady( obj,sim);
}


