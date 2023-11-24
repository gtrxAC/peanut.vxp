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
 *  vpi_base_popup_interface.h
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
#ifndef __VPI_BASE_POPUP_INTERFACE_H__
#define __VPI_BASE_POPUP_INTERFACE_H__

#include "vmsys.h"
#include "vpi_interface_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"
#include "vpi_control_interface.h"


/*
 * Interface of base popup delegator.
 */
class IVpiBasePopupDelegator : public IVpiBase
{
public:
    // Override the virtual function to return whatever the popup 
    //  need to push to history. Most popup need to push to stack,
    //  but some popup, for example, waiting icon does not need.
    virtual VMBOOL needPushHistory() = 0;

    // While entering the popup to be active
    virtual void onEnter() = 0;

    // While leaving the popup to be inactive
    virtual void onExit() = 0;

    // While leaving the popup to be inactive (after animaiton)
    virtual void onExited() = 0;

    // While push the popup into popup stack of the screen
    virtual void onEnterStack() = 0;

    // While pop the popup from popup stack of the screen
    virtual void onLeaveStack() = 0;

    // While the LCD screen has been rotate
    virtual void onRotate(const vm_screen_rotate_param_struct &param) = 0;

    // When user pen on Out side area, this function will be called.
    virtual void onPenInputOnOutside(vm_pen_event_struct &event) = 0;

    // When start playing tone
    virtual void onPlayTone() = 0;

    // When stop playing tone
    virtual void onStopTone() = 0;
};


/*
 * Interface of base popup.
 */
class IVpiBasePopup : public IVpiBase
{
public:
    // Show the popup
    virtual void show(VMBOOL isAnim) = 0;

    // Hide the popup
    virtual void hide(VMBOOL isAnim) = 0;
    
    // Exit the popup, it will close itself
    virtual void exit(VMBOOL isAnim) = 0;
    
    // Leave the popup, it will close itself depend on autoDestory
    virtual void leave(VMBOOL isAnim) = 0;

    // Set custom frame effect
    virtual void setFrameEffect(vm_effect_type_enum effectType, VMMSEC duration, vm_effect_direction_type_enum direction, void *data, VMINT32 dataSize) = 0;

    // Whatever destory the popup after popup leave by itself, 
    //  such like press key or time out. The default value is VM_TRUE
    virtual void setAutoDestory(VMBOOL value) = 0;

    // Return whatever destory the popup after popup leave by itself
    //
    // RETURNS: Whatever destory the popup after popup leave by itself
    virtual VMBOOL getAutoDestory() = 0;

//    virtual IVpiScreen *getTargetScreen() const = 0;
};


VPI_CMD_ID_DECLARE_BEGIN(BASE_POPUP)

    CMD_ID_BASE_POPUP_STATE,

/* NOTE. The new IDs must be added at the end */
VPI_CMD_ID_DECLARE_END(BASE_POPUP)

#endif /* __VPI_BASE_POPUP_INTERFACE_H__ */

