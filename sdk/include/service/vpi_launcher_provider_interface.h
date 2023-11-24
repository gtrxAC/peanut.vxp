/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  vpi_launcher_provider_interface.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the interface of the launcher provider.
 *
 * Author:
 * -------
 *  Cheng-Hung Ko (mtk01585)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 07 13 2012 wei.fu
 * [MAUI_03180984] DLUI check-in
 * Document check in.
 *
 * 07 02 2012 ch.ko
 * [MAUI_03200817] It will go to HS when press back key(RSK)
 * Support API to know if Home key is pressed.
 *
 * 06 28 2012 ch.ko
 * [MAUI_03200817] It will go to HS when press back key(RSK)
 * Support API to know if the launcher should restore its state.
 *
 * 06 18 2012 wei.fu
 * [MAUI_03180984] DLUI check-in
 * Revise datatype.
 *
 * 06 06 2012 ch.ko
 * [MAUI_03163831] [DLUI] Check-in patch
 * Revise comments.
 *
 * 05 30 2012 ch.ko
 * [MAUI_03163831] [DLUI] Check-in patch
 * Support API to hide or unhide status bar.
 *
 * 05 18 2012 ch.ko
 * [MAUI_03163831] [DLUI] Check-in patch
 * Check-in MRE launcher memory model.
 *
 * 04 18 2012 ch.ko
 * [MAUI_03163831] [DLUI] Check-in patch
 * Support new API.
 *
 * 03 21 2012 ch.ko
 * [MAUI_03147028] [DLUI] Check-in new features
 * Check-in hello world launcher..
 *
 * 03 12 2012 ch.ko
 * [MAUI_03147028] [DLUI] Check-in new features
 * Check-in MRE launcher and widget.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VPI_LAUNCHER_PROVIDER_INTERFACE_H
#define VPI_LAUNCHER_PROVIDER_INTERFACE_H

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vmsys.h"
#include "vmpromng.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vpi_interface_id.h"
#include "vpi_object_interface.h"


/*****************************************************************************
 * Universal Event
 *****************************************************************************/

/* Note: New IDs must be added in the end. */
VPI_EVENT_ID_DECLARE_BEGIN(LAUNCHER)

    EVT_ID_LAUNCHER_IS_RESTORE_INSTANCE_STATE,

    EVT_ID_LAUNCHER_IS_HOME_KEY_PRESSED,

VPI_EVENT_ID_DECLARE_END(LAUNCHER)


/*****************************************************************************
 * Enum
 *****************************************************************************/

enum VMLauncherProviderEventEnum
{
    VM_LAUNCHER_PROVIDER_EVENT_ENTERED,
    VM_LAUNCHER_PROVIDER_EVENT_WALLPAPER_CHANGED,
    VM_LAUNCHER_PROVIDER_EVENT_NOTIFICATION_CENTER_ENTER,
    VM_LAUNCHER_PROVIDER_EVENT_NOTIFICATION_CENTER_EXITED,

    VM_END_OF_ENUM(VMLauncherProviderEventEnum)
};


/*****************************************************************************
 * Typedef
 *****************************************************************************/

struct VMLauncherProviderEventStruct
{
    VM_STRUCT_HEADER
    VMLauncherProviderEventEnum id;
    void *userData;
    VMUINT32 size;
};


/*****************************************************************************
 * Launcher Provider Delegator Interface
 *****************************************************************************/
class IVpiLauncherProviderDelegator : public IVpiBase
{
// Override
public:
    // Override this function to create the launcher's view.
    //
    // SEE ALSO: onReleaseView
    virtual void onCreateView() = 0;

    // Override this function to release the launcher's view. Note that all the
    // object created in onCreateView must be released in onReleaseView.
    //
    // SEE ALSO: onCreateView
    virtual void onReleaseView() = 0;

    // Override this virtual to handle the scenario when the mobile enters the
    // launcher page.
    //
    // SEE ALSO: onExit
    virtual void onEnter() = 0;

    // Override this virtual to handle the scenario when the mobile exits the
    // launcher page.
    //
    // SEE ALSO: onEnter
    virtual void onExit() = 0;

    // This function is called when the launcher is inactive. It provides the
    // launcher a timing to serialize part of its resources when the launcher is
    // inactive. The 'ar' is an archive writer for you to save the launcher's
    // state if needed. The same archive will be provided as a reader in
    // onRestoreView.
    //
    // SEE ALSO: onRestoreView
    virtual void onSerializeView() = 0;

    // This function is called when the launcher is active. It provides the
    // launcher a timing to restore its resources that it serialized in
    // onSerializeView before. The 'ar' is an archive reader for your to read
    // the launcher's state that you have ever write in onSerializeView.
    //
    // SEE ALSO: onSerializeView
    virtual void onRestoreView() = 0;

    // This function is called to notify the launcher to process events. These
    // events are all optional. That means you can choose to respond to it or
    // not. Don't assert your launcher if you receive an event you don't know.
    //
    // RETURNS: If you have processed the event, return VM_TRUE; otherwise,
    //          return VFX_FALSE.
    virtual VMBOOL onEvent(
        VMLauncherProviderEventStruct *event    // [IN] Event structure
    ) = 0;
};


/*****************************************************************************
 * Launcher Provider Interface
 *****************************************************************************/
class IVpiLauncherProvider : public IVpiBase
{
// Method
public:
    // This function is used to hide / unhide the status icon bar. The default
    // value is un-hidden.
    virtual void setStatusBarHidden(
        VMBOOL isHidden     // [IN] Event structure
    ) = 0;
};


#endif /* VPI_LAUNCHER_PROVIDER_INTERFACE_H */

