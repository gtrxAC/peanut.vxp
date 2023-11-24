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
 *  vpi_page_transition_interface.h
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
 *  Wei Fu (mtk80927)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 06 18 2012 wei.fu
 * [MAUI_03180984] DLUI check-in
 * Revise datatype.
 *
 * 06 15 2012 jun.liu
 * [MAUI_03053506] Plug-in check in
 * .
 *
 * 04 20 2012 wei.fu
 * [MAUI_03053506] Plug-in check in
 * .
 *
 * 04 09 2012 wei.fu
 * [MAUI_03053506] Plug-in check in
 * .
 *
 * 03 30 2012 wei.fu
 * [MAUI_03053506] Plug-in check in
 * .
 *
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VPI_PAGE_TRANSITION_INTERFACE_H__
#define __VPI_PAGE_TRANSITION_INTERFACE_H__

#include "vmsys.h"
#include "vpi_control_interface.h"

/*
 * Interface of Venus page transition.
 */
class IVpiPageTransitionDelegator : public IVpiBase
{
public:
    // Prepare the transition
    virtual void customPrepare(
        VMBOOL in,                                      // [IN] in or our
        VMINT32 direction,                              // [IN] direction, can be 1, 0, -1
        const vm_screen_rotate_param_struct *param      // [IN] rotate information
    ) = 0;

    // Start the transition.
    // Derived class can override this interface to do customized transition effect.
    // Base class implement a default slide / swap effect.
    // Dont call it if you implement your own effect.
    virtual void customStart(
        VMBOOL in,              // [IN] in or out
        VMINT32 direction,      // [IN] direction, can be 1, 0, -1
        VMMSEC duration         // [IN] duration
    ) = 0;

    // Stop the transition.
    // Derived class can override this interface to do customized transition effect.
    // Base class implement a default slide / swap effect.
    // Dont call it if you implement your own effect.
    virtual void customStop(
        VMBOOL in,              // [IN] in or out
        VMINT32 direction,      // [IN] direction, can be 1, 0, -1
        VMMSEC duration         // [IN] duration
    ) = 0;

    // The target is transitted out completely
    // Dont call it if you implement your own effect.
    virtual VMBOOL customOuted(void) = 0;
};


/*
 * Interface of Venus page transition.
 */
class IVpiPageTransition : public IVpiBase
{
public:
    // Prepare the transition
    virtual void prepare(
        VMBOOL in = VM_TRUE,           // [IN] in or our
        VMINT32 direction = 0,          // [IN] direction, can be 1, 0, -1
        const vm_screen_rotate_param_struct *param = NULL    // [IN] rotate information
    ) = 0;

    // Start the transition
    virtual VMBOOL start(
        IVpiControl *target,            // [IN] the control that applied the transition
        VMBOOL noAnimation = VM_FALSE,  // [IN] turn off animation effect
        VMBOOL closeTarget = VM_FALSE   // [IN] close control after finishing transit out
    ) = 0;

    // Stop the transition
    virtual VMBOOL stop() = 0;

    // Restart the transition
    virtual VMBOOL restart() = 0;

    // Query if still in transition animation
    virtual VMBOOL inAnimation() = 0;

    // Query in or not
    virtual VMBOOL getIn() = 0;

    // Query direction
    virtual VMINT32 getDir() = 0;

    // Query that target control applying the transition
    virtual void getTarget(IVpiControl **ret) = 0;
};


VPI_CMD_ID_DECLARE_BEGIN(PAGE_TRANSITION)

    CMD_ID_PAGE_TRANSITION_STOP,
    CMD_ID_PAGE_TRANSITION_STOPPED,

/* NOTE. The new IDs must be added at the end */
VPI_CMD_ID_DECLARE_END(PAGE_TRANSITION)


#endif /* __VPI_PAGE_TRANSITION_INTERFACE_H__ */

