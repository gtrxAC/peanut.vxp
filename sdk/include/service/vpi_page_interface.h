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
 *  vpi_page_interface.h
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
#ifndef __VPI_PAGE_INTERFACE_H__
#define __VPI_PAGE_INTERFACE_H__

#include "vmsys.h"
#include "vpi_object_interface.h"

// Pre-defined classes
class IVpiMainScr;
class IVpiPageBar;
class IVpiPageTransition;

/*
 * Interface of Venus page.
 */
class IVpiPageDelegator : public IVpiBase
{
public:
    // While entering the page to be active
    virtual void onEnter(VMBOOL isBackward) = 0;
    
    // After the page entered. If there is transit effect, it will 
    // be called when the effect finished.
    virtual void onEntered() = 0;

    // While leaving the screen to be inactive
    virtual void onExit(VMBOOL isBackward) = 0;
    
    // After the page exited. If there is transit effect, it will 
    // be called when the effect finished.
    virtual void onExited() = 0;

    // After the page exited and after the screen snapshot. 
    virtual void onExited2() = 0;

    // Override this virtual function to return the screen support rotate types.
    //  The defualt behavior is setting param.rotateTo to VFX_SCREEN_SUPPORT_ROTATE_NORMAL
    virtual void onQueryRotateEx(
        vm_screen_rotate_param_struct &param // The parameter to rotate
    ) = 0;

    // While the LCD screen has been rotate
    virtual void onRotate(
        const vm_screen_rotate_param_struct &param // The parameter to rotate
    ) = 0;

    // Notify that transition effect is finished
    // If you override this function, please remember to call VfxPage::onTransitionStop()
    virtual void onTransitionStop(
        VMBOOL in,              // [IN] in or out
        VMINT32 direction       // [IN] direction of trasnsition, can be 1, 0, -1
    ) = 0;

    // Notify for back key process
    virtual void onBack() = 0;

    // Notify when Bar is about to become invisible. Only when setBarAutoHide(VFX_TRUE)
    virtual void onBarAutoHide() = 0;
};


/*
 * Interface of Venus page.
 */
class IVpiPage : public IVpiBase
{
public:
    // Query page id, it is assigned when page enter page stack.
    // So if the page is not at stack yet, VFX_ID_NULL will be returned.
    // RETURNS: page id
    virtual VMID       getId() = 0;

    // Query if this is current page
    virtual VMBOOL     isActive() = 0;

    // close self, with animation if page is at top.
    virtual void       exit() = 0;

    // close self, emulate back key process
    virtual void       back() = 0;

    // Setup a new page transition, it is used while pushing/popuping
    virtual void        setTransition(
        IVpiPageTransition *transition   // [IN] Page transition object
    ) = 0;

    // Query if a page is translucent
    virtual VMBOOL     isTranslucent() = 0;

    // Query if a page has status bar
    virtual VMBOOL     hasStatusBar() = 0;

    // turn on/off status bar
    virtual void       setStatusBar(VMBOOL on) = 0;

    // set customized background for status bar
    // Note. Only support static image resource
    virtual void        setStatusBarBg(
        VMRESID bgImage  // [IN] Native resource id
    ) = 0;

    // get customized background for status bar
    virtual VMRESID    getStatusBarBg(void) = 0;

    // turn on/off translucent support
    virtual void       setTranslucent(VMBOOL on) = 0;

    // turn on/off bar auto hiding.
    virtual void       setBarAutoHide(VMBOOL on) = 0;

    // check if bar is in hidden or not.
    virtual VMBOOL     getIsBarHidden() = 0;

    // Setup a bar to top area
    virtual void        setTopBar(
        IVpiPageBar *bar // [IN] bar pointer
    ) = 0;

    // Setup a bar to bottom area
    virtual void        setBottomBar(
        IVpiPageBar *bar // [IN] bar pointer
    ) = 0;

    // Allow page to be delete?
    virtual VMBOOL getAllowDelete() = 0;

    // Set whether allow to delete page.
    virtual void setAllowDelete(VMBOOL allowDelete) = 0;

    // Query VfxMainScr pointer
    virtual void getMainScr(IVpiMainScr **screen) = 0;

    // Attach bar to this page
    virtual void        setBar(
        vm_page_bar_location_enum loc,     // [IN] top or bottom area
        IVpiPageBar *newBar,             // [IN] bar pointer
        VMBOOL deleteOldBar = VM_FALSE// [IN] close the old bar or not
    ) = 0;

    // Turn on/off bar
    virtual void        toggleBar(
        vm_page_bar_location_enum loc,     // [IN] top or bottom bar to be toggle
        VMBOOL on                      // [IN] on or off
    ) = 0;

    // Query bar pointer
    virtual void getBar(
        vm_page_bar_location_enum loc,      // [IN] top or bottom
        IVpiPageBar  **ret                  // [OUT] pointer of bar
    ) = 0;

    // Query if a bar is currenly on or off
    virtual VMBOOL     isBarOn(
        vm_page_bar_location_enum loc      // [IN] top or bottom
    ) = 0;

    // Hide/unhide all bars on this page
    virtual void        hideAllBars(
        VMBOOL hide = VM_TRUE         // [IN] hide or unhide
    ) = 0;

    // Return current rotate angle of page
    virtual vm_scr_rotate_type_enum getRotate() = 0;
};

#endif /* __VPI_PAGE_INTERFACE_H__ */

