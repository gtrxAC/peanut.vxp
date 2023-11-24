/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vpi_screen_lock_provider_interface.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the interface of the VPI screen lock provider.
 *
 * Author:
 * -------
 *  Stella Yang (mtk01564)
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
 * 06 11 2012 stella.yang
 * [MAUI_03146398] [DLUI] VPI Check in
 * .
 *
 * 03 13 2012 stella.yang
 * [MAUI_03146398] [DLUI] VPI Check in
 * .
 *
 * 03 13 2012 stella.yang
 * [MAUI_03146398] [DLUI] VPI Check in
 * .
 *
 * 03 09 2012 stella.yang
 * [MAUI_03146398] [DLUI] Wallpaper VPI
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VPI_SCREEN_LOCK_PROVIDER_INTERFACE_H
#define VPI_SCREEN_LOCK_PROVIDER_INTERFACE_H

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
 * ScreenLock Proivder's Delegator Interface
 *****************************************************************************/
class IVpiScreenLockProviderDelegator : public IVpiBase
{
// Override
public:
    
    // Override this function to create your screen lock's view. 
    virtual void onCreateView() = 0;

    // Override this function to release your screen lock's view.
    virtual void onReleaseView() = 0;

    // Override this function to enter your screen lock's page
    virtual void onPageEnter() = 0;

    // Override this function to exit your screen lock's page
    virtual void onPageExit() = 0;  

    // Override this function to handle backlight on
    virtual void onBacklightOn() = 0;

    // Override this function to handle backlight off
    virtual void onBacklightOff() = 0;
};


/*****************************************************************************
 * ScreenLock Provider Interface
 *****************************************************************************/
class IVpiScreenLockProvider : public IVpiBase
{
// Method
public:
    // call this function when unlock
    virtual void onUnlock(IVpiScreenLockProvider *provider) = 0;

    // call this function when configuration is completed
    virtual void onConfigurationCompleted(IVpiScreenLockProvider *provider, VMBOOL isSuccess) = 0;
};

#endif /* VPI_SCREEN_LOCK_PROVIDER_INTERFACE_H */

