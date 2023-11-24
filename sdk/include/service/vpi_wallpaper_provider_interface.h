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
 *  vpi_wallpaper_provider_interface.h
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

 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VPI_WALLPAPER_PROVIDER_INTERFACE_H
#define VPI_WALLPAPER_PROVIDER_INTERFACE_H

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
 * Wallpaper Proivder's Delegator Interface
 *****************************************************************************/
typedef enum
{
    VM_WP_PROVIDER_SUSPEND_ON_DESKTOP_SWIPE,
    VM_WP_PROVIDER_SUSPEND_ON_PEN_DOWN,

    VM_END_OF_ENUM(vm_wp_provider_suspend_type_enum)
} vm_wp_provider_suspend_type_enum;

typedef enum
{
    VM_WP_PROVIDER_EVENT_DRAGGED,    // userData is vm_wallpaper_provider_pos_struct
    VM_WP_PROVIDER_EVENT_MOVED,      // userData is vm_wallpaper_provider_pos_struct
    VM_WP_PROVIDER_EVENT_DROPPED,    // userData is vm_wallpaper_provider_pos_struct

    VM_END_OF_ENUM(vm_wp_provider_event_enum)
} vm_wp_provider_event_enum;

typedef struct
{
    VM_STRUCT_HEADER
    vm_wp_provider_event_enum event; // Event
    VMUINT32 size;                          // size of userData
    void *userData;                        // pointer to userData
}vm_wp_provider_event_struct;

typedef struct
{
    VM_STRUCT_HEADER
    vm_point_struct pos;       // Position of item
    IVpiFrame *targetWidget;    // Target item interface
}vm_wp_provider_pos_struct;

/*****************************************************************************
 * Wallpaper Proivder's Delegator Interface
 *****************************************************************************/
class IVpiWallpaperProviderDelegator : public IVpiBase
{
// Override
public:
    // Create wallpaper. Allocate all animation/image resources here.
    virtual void onCreateView() = 0;

    // Release wallpaper. Free all animation/image resources here.
    virtual void onReleaseView() = 0;

    // This is called when the home screen becomes inactive and invisible.
    // You can partially release resource here.
    // SEE ALSO: onRestoreView
    virtual void onSerializeView() = 0;

    // Override this virtual to restore your view.
    // SEE ALSO: onSerializeView
    virtual void onRestoreView() = 0;

    // Suspend all wallpaper animation
    virtual void onSuspend() = 0;

    // Resume wallpaper animation
    virtual void onResume() = 0;

    // This function pass a value range from 0.0f to 1.0f,
    // if desktop is left-right, 0 is left most page and 1 is right most page
    // if desktop is top-bottom, 0 is topmost and 1 is bottom page
    virtual void onDesktopCursorChanged(
        VMFLOAT curPos,
        VMFLOAT oldPos
    ) = 0;

    // Is allow suspend wallpaper when desktop swipe
    virtual VMBOOL onQuerySuspend(vm_wp_provider_suspend_type_enum suspendType) = 0;

    // Notifications from wallpaper to provider,
    // e.g. widget dropped
    virtual void onEvent(vm_wp_provider_event_struct* event) = 0;
};


typedef enum
{
    VPI_WALLPAPER_ENV_SRC_TYPE, // env is (vm_wallpaper_src_type_enum *)

    VM_END_OF_ENUM(vm_wallpaper_env_enum)
} vm_wallpaper_env_enum;

typedef enum
{
    VPI_WALLPAPER_SRC_HOME,
    VPI_WALLPAPER_SRC_LOCK,

    VM_END_OF_ENUM(vm_wallpaper_src_type_enum)
} vm_wallpaper_src_type_enum;


/*****************************************************************************
 * Wallpaper Provider Interface
 *****************************************************************************/
class IVpiWallpaperProvider : public IVpiBase
{
public:
    // query how many pages
    virtual VMUINT32 getTotalPage() = 0;

    // returns VM_TRUE if the wallpaper is being suspended
    virtual VMBOOL isSuspended() = 0;

    // Allow provider to suspend itself
    virtual void suspend() = 0;

    // Allow provider to resume itself
    virtual void resume() = 0;

    // return
    virtual VMUINT32 getEnv(
        vm_wallpaper_env_enum env,  // [IN]
        void *value                 // [OUT]
    ) = 0;
};

#endif /* VPI_WALLPAPER_PROVIDER_INTERFACE_H */

