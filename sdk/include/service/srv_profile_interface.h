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
 *   srv_profile_interface.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IProfile interface
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
#include "gs_id.h"
#include "gs_base.h"

#define GS_C_INTERFACE
#include "gs_srv_profile_interface_def.h"

#include "gs_srv_profile_type.h"

/*****************************************************************************
 * IProfile methods
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  IProfile_addRef
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 * RETURNS
 *  The error code of the operation.
 *****************************************************************************/
S32 __inline IProfile_addRef(IProfile *obj)
{
    return obj->vt->addRef(obj);
}


/*****************************************************************************
 * FUNCTION
 *  IProfile_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 * RETURNS
 *  The error code of the operation.
 *****************************************************************************/
S32 __inline IProfile_release(IProfile *obj)
{
    return obj->vt->release(obj);
}


/*****************************************************************************
 * FUNCTION
 *  IProfile_queryInterface
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 *  iid : [IN]        
 *  pptr : [IN]        
 * RETURNS
 *  The error code of the operation.
 *****************************************************************************/
S32 __inline IProfile_queryInterface(IProfile *obj, S32 iid, IBase **pptr)
{
    return obj->vt->queryInterface(obj, iid, pptr);
}

/*****************************************************************************
 * FUNCTION
 *  IProfile_active
 * DESCRIPTION
 *  This function is to activte specific profile and will not provide any pop up actions.
 *  It will also check if the requested profile can be activated in cureent status. 
 *  Ex: when earphone is plugged in, and current profile is in earphone profie, then 
 *  request to activate meeting profile will not be allowed.
 *  When silent profile is not supported, request to activte silent mode will turn on
 *  silent flag for all profiles.
 * PARAMETERS
 *  obj     [IN]    object pointer
 *  profile     [IN]    profile to activate
 * RETURNS
 *  gs_srv_prof_ret    
 *      GS_SRV_PROF_RET_SUCCESS : activate profile success
 *      GS_SRV_PROF_RET_PROFILE_NOT_SUPPORTED : profile is not supported in current profile service
 *      GS_SRV_PROF_RET_FAIL : other errors (ex: profile can not be actiaved in current status)
 *****************************************************************************/
gs_srv_prof_ret __inline IProfile_active(IProfile *obj, gs_srv_prof_external_profile_enum profile)
{
    return obj->vt->active(obj, profile);
}


/*****************************************************************************
 * FUNCTION
 *  IProfile_deactive
 * DESCRIPTION
 *  This function is to deactivate specific profile.
 * PARAMETERS
 *  obj     [IN]    object pointer
 *  profile     [IN]    profile to deactivate
 * RETURNS
 *  gs_srv_prof_ret    
 *      GS_SRV_PROF_RET_SUCCESS : deactivate profile success
 *      GS_SRV_PROF_RET_PROFILE_NOT_SUPPORTED : profile is not supported in current profile service
 *      GS_SRV_PROF_RET_FAIL : other errors (ex: profile can not be deactiaved in current status)
 *****************************************************************************/  
gs_srv_prof_ret __inline IProfile_deactive(IProfile *obj, gs_srv_prof_external_profile_enum profile)
{
    return obj->vt->deactive(obj, profile);
}

/*****************************************************************************
 * FUNCTION
 *  IProfile_getCurrentProfileValue
 * DESCRIPTION
 *  This function is to get setting value of current profile. The value will be filled
 *  in the second parameter and the caller shall cast it to the type of the setting value
 * PARAMETERS
 *  obj     [IN]    object pointer
 *  setting     [IN]    which setting item
 *  value       [OUT]   returns setting value, type of the setting itme is commented 
 *                      in srv_prof_settings_enum
 * RETURNS
 *  gs_srv_prof_ret    
 *      GS_SRV_PROF_RET_SUCCESS : get value success
 *      GS_SRV_PROF_RET_SETTING_NOT_SUPPORTED : requested setting is not supported in 
 *                                           current profile service
 *****************************************************************************/
gs_srv_prof_ret __inline IProfile_getCurrentProfileValue(IProfile *obj, gs_srv_prof_settings_enum setting, void* value)
{
    return obj->vt->getCurrentProfileValue(obj, setting, value);
}


/*****************************************************************************
 * FUNCTION
 *  IProfile_setCurrentProfileValue
 * DESCRIPTION
 *  This function is to set setting value of current profile.
 * PARAMETERS
 *  obj     [IN]    object pointer
 *  setting     [IN]    which setting item
 *  value       [IN]    the setting value, type of the setting itme is commented 
 *                      in srv_prof_settings_enum
 * RETURNS
 *  gs_srv_prof_ret    
 *      GS_SRV_PROF_RET_SUCCESS : get value success
 *      GS_SRV_PROF_RET_SETTING_NOT_SUPPORTED : setting is not supported in current profile service
 *      GS_SRV_PROF_RET_FAIL : other errors (ex: current profile can not set this value)
 *****************************************************************************/
gs_srv_prof_ret __inline IProfile_setCurrentProfileValue(IProfile *obj, gs_srv_prof_settings_enum setting, void* value)
{
    return obj->vt->setCurrentProfileValue(obj, setting, value);
}


/*****************************************************************************
 * FUNCTION
 *  IProfile_isProfileActivated
 * DESCRIPTION
 *  This function is to check if a specific profile is currently activated.
 *  If there is no such profile cofigured for profile service, the return
 *  value will be SRV_PROF_RET_PROFILE_NOT_SUPPORTED.
 * PARAMETERS
 *  obj     [IN]    object pointer
 *  profile     [IN]    profile enum to be checked
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL __inline IProfile_isProfileActivated(IProfile *obj, gs_srv_prof_external_profile_enum profile)
{
    return obj->vt->isProfileActivated(obj, profile);
}


/*****************************************************************************
 * FUNCTION
 *  IProfile_ifCanRing
 * DESCRIPTION
 *  This function will tell the caller if he shall ring based on current 
 *  profile's setting. In plutommi profile app, we will check alert type and
 *  reutrns MMI_TRUE if the setting is not SRV_PROF_ALERT_TYPE_VIB_ONLY. 
 *  Please be aware that in plutommi, this is only for users who is intersted
 *  in alert type setting.
 * PARAMETERS
 *  obj     [IN]    object pointer
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL __inline IProfile_ifCanRing(IProfile *obj)
{
    return obj->vt->ifCanRing(obj);
}


/*****************************************************************************
 * FUNCTION
 *  IProfile_ifCanVibrate
 * DESCRIPTION
 *  This function will tell the caller if he shall vibrate based on current 
 *  profile's setting. In plutommi profile app, we will check alert type and
 *  reutrns MMI_TRUE if the setting is not SRV_PROF_ALERT_TYPE_RING. Please be 
 *  aware that in plutommi, this is only for users who is intersted in alert
 *  type setting.
 * PARAMETERS
 *  obj     [IN]    object pointer
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL __inline IProfile_ifCanVibrate(IProfile *obj)
{
    return obj->vt->ifCanVibrate(obj);
}

/*****************************************************************************
 * FUNCTION
 *  IProfile_playTone
 * DESCRIPTION
 *  This function is for playing tone type.
 * PARAMETERS
 *  obj     [IN]    object pointer
 *  tone_type     [IN]    requested tone type
 *  callback      [IN]    play tone callback
 * RETURNS
 *  gs_srv_prof_ret      
 *      GS_SRV_PROF_RET_SUCCESS : play tone success and will have callback
 *      GS_SRV_PROF_RET_SUCCESS_WO_CALLBACK: play tone success but do not have callback (DTMF)
 *      GS_SRV_PROF_RET_FAIL : play tone fail and will not have callback
 *****************************************************************************/
gs_srv_prof_ret __inline IProfile_playTone(IProfile *obj,gs_srv_prof_tone_enum tone_type, gs_srv_prof_play_tone_callback callback)
{
    return obj->vt->playTone(obj,tone_type,callback);
}


/*****************************************************************************
 * FUNCTION
 *  IProfile_playToneWithId
 * DESCRIPTION
 *  This function is for playing tone with ID.
 * PARAMETERS
 *  obj     [IN]    object pointer
 *  tone_type     [IN]    requested tone type
 *  tone_id       [IN]    tone id to be played
 * RETURNS
 *  gs_srv_prof_ret      
 *      GS_SRV_PROF_RET_SUCCESS : play tone success and will have callback
 *      GS_SRV_PROF_RET_SUCCESS_WO_CALLBACK: play tone success but do not have callback (DTMF)
 *      GS_SRV_PROF_RET_FAIL : play tone fail and will not have callback
 *****************************************************************************/
gs_srv_prof_ret __inline IProfile_playToneWithId(IProfile *obj,gs_srv_prof_tone_enum tone_type, U16 audio_id, gs_srv_prof_ring_type_enum play_type, gs_srv_prof_play_tone_callback callback)
{
    return obj->vt->playToneWithId(obj,tone_type,audio_id,play_type,callback);
}


/*****************************************************************************
 * FUNCTION
 *  IProfile_playToneWithFullStruct
 * DESCRIPTION
 *  This function is for modules to play according to its own configure.
 *  Plz remember to use srv_prof_play_req_struct_init to initiate the configurations
 *  and update the audio_id / filepath and audio_type
 * PARAMETERS
 *  obj     [IN]    object pointer
 *  play_struct     [IN]    play structure
 * RETURNS
 *  gs_srv_prof_ret
 *      GS_SRV_PROF_RET_SUCCESS : play tone success and will have callback
 *      GS_SRV_PROF_RET_NOT_PLAY : not play tone due to current setting and do not have callback
 *      GS_SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK: play tone success but do not have callback (DTMF)
 *      GS_SRV_PROF_RET_FAIL : play tone fail and do not have callback
 *****************************************************************************/
gs_srv_prof_ret __inline IProfile_playToneWithFullStruct(IProfile *obj,gs_srv_prof_play_req_struct* play_struct)
{
    return obj->vt->playToneWithFullStruct(obj,play_struct);
}


/*****************************************************************************
 * FUNCTION
 *  IProfile_playToneWithText
 * DESCRIPTION
 *  This function is for modules to play tone with text words. Currently is used for
 *  intelligent call alert for incoming call.
 * PARAMETERS
 *  obj     [IN]    object pointer
 *  tone_type     [IN]    requested tone type
 *  text          [IN]    text to play
 *  text_speed    [IN]    text play speed in msec.
 *  callback      [IN]    callback function
 * RETURNS
 *  gs_srv_prof_ret      
 *      GS_SRV_PROF_RET_SUCCESS : play tone success and will have callback
 *      GS_SRV_PROF_RET_NOT_PLAY : not play tone due to current setting and do not have callback
 *      GS_SRV_PROF_RET_FAIL : play tone fail and do not have callback
 *****************************************************************************/
gs_srv_prof_ret __inline IProfile_playToneWithText(IProfile *obj,gs_srv_prof_tone_enum tone_type, U8* text, S32 text_speed, gs_srv_prof_play_tone_callback callback)
{
    return obj->vt->playToneWithText(obj,tone_type,text,text_speed,callback);
}


/*****************************************************************************
 * FUNCTION
 *  IProfile_isSettingAvailable
 * DESCRIPTION
 *  This function is to check if specific setting is supported in current service
 * PARAMETERS
 *  obj     [IN]    object pointer
 *  setting     [IN]    which setting item
 * RETURNS
 *  MMI_BOOL      MMI_TRUE : supported
 *                MMI_FALSE : not supported
 *****************************************************************************/
MMI_BOOL __inline IProfile_isSettingAvailable(IProfile *obj,gs_srv_prof_settings_enum setting)
{
    return obj->vt->isSettingAvailable(obj,setting);
}


/*****************************************************************************
 * FUNCTION
 *  IProfile_stopTone
 * DESCRIPTION
 *  This function is to stop the requested tone which is requested to play before.
 * PARAMETERS
 *  obj     [IN]    object pointer
 *  tone_type     [IN]    requested tone type
 * RETURNS
 *  void
 *****************************************************************************/
void __inline IProfile_stopTone(IProfile *obj,gs_srv_prof_tone_enum tone_type)
{
    obj->vt->stopTone(obj,tone_type);
}

/*****************************************************************************
 * FUNCTION
 *  IProfile_isTonePlaying
 * DESCRIPTION
 *  This function is to check if the tone_type is crrently playing
 * PARAMETERS
 *  obj     [IN]    object pointer
 *  tone_type     [IN]    query tone type
 * RETURNS
 *  MMI_BOOL      MMI_TRUE : tone_type is playing
 *                MMI_FALSE : tone_type is not playing
 *****************************************************************************/
MMI_BOOL __inline IProfile_isTonePlaying(IProfile *obj,gs_srv_prof_tone_enum tone_type)
{
    return obj->vt->isTonePlaying(obj,tone_type);
}


/*****************************************************************************
 * FUNCTION
 *  IProfile_getProfileCount
 * DESCRIPTION
 *  This function is for getting total number of profiles
 * PARAMETERS
 *  obj     [IN]    object pointer
 * RETURNS
 *  U8      total profile numbers
 *****************************************************************************/
MMI_BOOL __inline IProfile_getProfileCount(IProfile *obj)
{
    return obj->vt->getProfileCount(obj);
}


