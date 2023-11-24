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
 *  vpi_wallpaper_interface.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the interface of the VPI wallpaper.
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
 * 06 18 2012 wei.fu
 * [MAUI_03180984] DLUI check-in
 * Revise datatype.
 *
 * 04 07 2012 stella.yang
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

#ifndef VPI_WALLPAPER_INTERFACE_H
#define VPI_WALLPAPER_INTERFACE_H

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
 * Widget Interface
 *****************************************************************************/

typedef enum
{
    VM_WALLPAPER_SUSPEND_ON_DESKTOP_SWIPE,
    VM_WALLPAPER_SUSPEND_ON_PEN_DOWN,

    VM_END_OF_ENUM(vm_wallpaper_suspend_type_enum)
} vm_wallpaper_suspend_type_enum;

typedef enum
{
    VM_WALLPAPER_EVENT_TYPE_DRAGGED,    // userData is vm_wallpaper_pos_struct
    VM_WALLPAPER_EVENT_TYPE_MOVED,      // userData is vm_wallpaper_pos_struct
    VM_WALLPAPER_EVENT_TYPE_DROPPED,    // userData is vm_wallpaper_pos_struct

    VM_END_OF_ENUM(vm_wallpaper_event_type_enum)
} vm_wallpaper_event_type_enum;

typedef struct
{
    VM_STRUCT_HEADER
    vm_wallpaper_event_type_enum evt_type;          // Event
    VMUINT32 size;                          // size of userData
    void *userData;                        // pointer to userData
} vm_wallpaper_event_struct;

typedef struct
{
    VM_STRUCT_HEADER
    vm_point_struct pos;       // Position of item
    IVpiControl *targetWidget;    // Target item interface
} vm_wallpaper_pos_struct;


/*****************************************************************************
 * Wallpaper Interface
 *****************************************************************************/
class IVpiWallpaper : public IVpiBase
{
// Method
public:
    // This function creates the wallpaper's view.
    //
    // SEE ALSO: releaseView
    virtual void createView() = 0;

    // This function releases the wallpaper's view.
    //
    // SEE ALSO: createView
    virtual void releaseView() = 0;

    // Serialize the wallpaper view.
    virtual void serializeView() = 0;

    // Restore the wallpaper view.
    virtual void restoreView() = 0;

    // Suspend the wallpaper view.
    virtual void suspend() = 0;

    // Resume the wallpaper view.
    virtual void resume() = 0;

    // returns VM_TRUE if the wallpaper is being suspended
    virtual VMBOOL isSuspended() = 0;
    
    // Set number of total desktop pages
    virtual void setTotalPage(VMINT32 page) = 0;

    // Set destop curser changed
    virtual void setDesktopCursorChanged(
        VMFLOAT curPos,
        VMFLOAT oldPos
    ) = 0;

    // Query if wallpaper needs to be suspended
    virtual VMBOOL querySuspend(vm_wallpaper_suspend_type_enum suspendType) = 0;

    // Notify event
    virtual void notifyEvent(vm_wallpaper_event_struct* event) = 0;

    // Send pen input to wallpaper
    virtual void doPenInput(vm_pen_event_struct &event) = 0;
};

#endif /* VPI_WALLPAPER_INTERFACE_H */

