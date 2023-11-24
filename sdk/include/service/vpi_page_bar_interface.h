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
 *  vpi_page_bar_interface.h
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
 * 07 13 2012 wei.fu
 * [MAUI_03180984] DLUI check-in
 * Document check in.
 *
 * 06 18 2012 jun.liu
 * [MAUI_03053506] Plug-in check in
 * .
 *
 * 06 14 2012 jun.liu
 * [MAUI_03053506] Plug-in check in
 * .
 *
 * 04 20 2012 wei.fu
 * [MAUI_03053506] Plug-in check in
 * .
 *
 * 04 06 2012 wei.fu
 * [MAUI_03053506] Plug-in check in
 * - VpiPageBar.
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
#ifndef __VPI_PAGE_BAR_INTERFACE_H__
#define __VPI_PAGE_BAR_INTERFACE_H__

#include "vmsys.h"
#include "vpi_object_interface.h"
#include "vpi_frame_interface.h"

// Pre-defined classes
class IVpiMainScr;
class IVpiPage;
class IVpiPageTransition;

/*
 * Interface of Venus page bar.
 */
class IVpiPageBar : public IVpiBase
{
public:
    // Setup a new page transition, it is used while pushing/popuping
    virtual void setTransition(
        IVpiPageTransition *transition   // [IN] Page transition object
    ) = 0;

    // Turn on/off shadow support
    virtual void setEnableShadow(
        VMBOOL value                   // [IN] enable shadow or not.
    ) = 0;

    // Query VfxMainScr pointer
    virtual void getMainScr(IVpiMainScr **ret) = 0;

    // Query VfxPage pointer
    virtual void getPage(IVpiPage **ret) = 0;

    // Query location
    virtual vm_page_bar_location_enum getLoc() = 0;

    // Call this interface when user press Back button
    virtual void doBackFunc() = 0;

    // Set a shadow frame
    virtual void setShadowFrame(IVpiFrame* frame, IVpiFrame **ret) = 0;
};


/*
 * class IVpiPageBarDelegator
 */
class IVpiPageBarDelegator : public IVpiBase
{
public:
    // Notify when translucent flag is changed
    virtual void onSetTranslucent(
        VMBOOL translucent // [IN] on or off
    ) = 0;

    // Notify when rotate direction is changed
    virtual void onSetRotate(
        vm_scr_rotate_type_enum rotate // [IN] new direction
    ) = 0;

    // Notify when transition end
    virtual void onTransitionStop(
        VMBOOL  in,             // [IN] transit in or out
        VMINT32 direction       // [IN] direction, can be 1, 0, -1
    ) = 0;
};

#endif /* __VPI_PAGE_BAR_INTERFACE_H__ */

