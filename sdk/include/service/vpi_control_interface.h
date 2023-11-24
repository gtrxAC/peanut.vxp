/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vpi_control_interface.h
 *
 * Project:
 * --------
 *  Venus Plug-in Core
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  Jun Liu (mtk80064)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VPI_CONTROL_INTERFACE_H__
#define __VPI_CONTROL_INTERFACE_H__

#include "vmsys.h"
#include "vpi_interface_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"
#include "vpi_object_interface.h"
#include "vpi_frame_interface.h"
#include "vpi_archive_interface.h"
#include "vmio.h"

class IVpiControl;

/*
 * Interface of control delegator.
 */
class IVpiControlDelegator : public IVpiBase
{
public:
    // Override to handle the pen input event.
    //
    // NOTE: The default behavior is doing nothing and return VM_FALSE.
    //
    // RETURNS: Return VM_TRUE if the event has been handled. 
    //  Otherwise return VM_FALSE.
    //
    // SEE ALSO: vm_pen_event_struct
    virtual VMBOOL onPenInput(vm_pen_event_struct &event) = 0;

    // Override to handle this control to be serialized
    //
    // RETURNS: 
    //  VM_TRUE if the control would like to serialize itself.
    //  VM_FALSE if the control does not support serialize.
    virtual VMBOOL onSerialize(IVpiArchive *ar) = 0;

    // Override to handle the control to be restored
    virtual void onRestore(IVpiArchive *ar) = 0;

    // Override to handle the preview pen input event.
    //
    // NOTE: The default behavior is doing nothing and return VM_FALSE.
    //
    // RETURNS: Return VM_TRUE if the event has been handled. 
    //  Otherwise return VM_FALSE.
    //
    // SEE ALSO: onPenInput, vm_pen_event_struct
    virtual VMBOOL onPreviewPenInput(vm_pen_event_struct &event) = 0;

    // Override to change the behavior of register access key handler
    //
    // NOTE: The default behavior is ask parent control to handle
    virtual VMBOOL onKeyInput(vm_key_event_struct &event) = 0;

    // onUpdate will be called after someone call checkUpdate.
    //
    // SEE ALSO: VMControl::checkUpdate
    virtual void onUpdate()  = 0;

    // Override this to accept capture pen abort or not.
    // RETURNS: VM_TRUE if pen abort is accepeted; otherwise VM_FALSE.
    virtual VMBOOL onPenAbortAccepted(IVpiControl *aborter, vm_pen_abort_reason_enum reason) = 0;
};


/*
 * Interface of control.
 */
class IVpiControl : public IVpiBase
{
public:
    // Return the disabled states.
    //
    // RETURNS: VFX_TRUE if the control is disabled.
    virtual VMBOOL getIsDisabled() = 0;

    // Set the control to disabled state.
    virtual void setIsDisabled(VMBOOL isDisabled) = 0;

    // Return the parent control.
    //
    // RETURNS: The parent control.
    virtual void getParentControl(IVpiControl **control) = 0;

    // Find the screen that contains the control
    //
    // RETURNS: The screen that contains the control.
    //  Returns NULL if there is no screen contains the control.
    virtual void findScreen(IVpiControl **control) = 0;

    // Serialize this control state to given archive.
    virtual VMBOOL serialize(IVpiArchive *ar) = 0;
    
    // Restore this control state from given archive.
    virtual void restore(IVpiArchive *ar) = 0;

    // Try to set the pen capture control to this control.
    //
    // RETURNS: Return VM_TRUE if successful. Otherwise, return VM_FALSE.
    //
    // SEE ALSO: vm_pen_abort_reason_enum
    virtual VMBOOL capture(vm_pen_abort_reason_enum reason = VM_PEN_ABORT_REASON_DEFAULT) = 0;

    // Register an accelerator key. When the key is pressed, 
    //  and no one focus control handle it, your onKeyInput will be invoked.
    //
    // SEE ALSO: unregisterKeyHandler, onKeyInput
    virtual void registerKeyHandler(vm_key_code_enum keyCode) = 0;

    // Unregister an accelerator key.
    //
    // SEE ALSO: registerKeyHandler
    virtual void unregisterKeyHandler(vm_key_code_enum keyCode) = 0;

    // Unregister all accelerator keys.
    //
    // SEE ALSO: registerKeyHandler
    virtual void unregisterAllKeyHandler() = 0;

    // Set the frame is focused
    virtual void setFocused(VMBOOL value) = 0;

    // Check focus state of this frame
    virtual VMBOOL getFocused() = 0;

    // Make no child is focused
    virtual void resetFocusChild() = 0;
    
    // This function will post emit the onUpdate function.
    // And this function will only invoke once onUpdate function even you call it many times.
    virtual void checkUpdate() = 0;
};

#endif /* __VPI_CONTROL_INTERFACE_H__ */

