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
 *  vpi_scrollable_interface.h
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
 *  Herman Yang (mtk03745)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VPI_SCROLLABLE_INTERFACE_H__
#define __VPI_SCROLLABLE_INTERFACE_H__

#include "vmsys.h"
#include "vpi_interface_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"
#include "vpi_control_interface.h"


typedef enum 
{
    // no scroll bar
    VM_SCROLLABLE_SCROLL_INDICATOR_STYLE_NONE,
    // fixed scroll bar style 
    VM_SCROLLABLE_SCROLL_INDICATOR_STYLE_FIXED,
    // auto-hidden scroll bar style
    VM_SCROLLABLE_SCROLL_INDICATOR_STYLE_AUTO_HIDE,
    // overlay scroll bar style
    VM_SCROLLABLE_SCROLL_INDICATOR_STYLE_OVERLAY,

    VM_END_OF_ENUM(vm_scrollable_scroll_indicator_style_enum)
} vm_scrollable_scroll_indicator_style_enum ;


/****************************************************************************
* VpiScrollableView
****************************************************************************/

/*
 * class IVpiScrollableViewDelegator
 */
class IVpiScrollableViewDelegator : public IVpiBase
{
public:

    // <group DOM_ScrollableView_IVpiScrollableViewDelegator_Overridable>
    // fix the free run final target position
    virtual void onFreeRunSetTargetContentOffset(vm_point_struct &offset) = 0;
};


/*
 * class IVpiScrollableView
 */
class IVpiScrollableView : public IVpiBase
{
#if 0
public:
    virtual void setContentSize(const vm_size_struct &contentSize ) = 0;
    virtual void getContentSize(vm_size_struct *size) = 0;
    virtual void setWarningContentRect(vm_rect_struct &rect) = 0;
    virtual void getWarningContentRect(vm_rect_struct *rect) = 0;
    virtual void setValidContentRect(vm_rect_struct &rect) = 0;
    virtual void getValidContentRect(vm_rect_struct *rect) = 0;  
    virtual void stopScrolling() = 0;
#endif    
};


/****************************************************************************
* VpiScrollable
****************************************************************************/


/*
 * class IVpiScrollableDelegator
 */
class IVpiScrollableDelegator : public IVpiBase
{
public:

    // <group DOM_Scrollable_IVpiScrollableDelegator_Overridable>
    // Creates the view.
    // RETURNS: created view object
    virtual void onCreateView(IVpiScrollableView **view) = 0;
    
    // <group DOM_Scrollable_IVpiScrollableDelegator_Overridable>
    // Closes the view.
    virtual void onCloseView() = 0;
};


/*
 * class IVpiScrollable
 */
class IVpiScrollable : public IVpiBase
{
public:
    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Sets the scrollable content width and height.
    virtual void setContentSize(const vm_size_struct &contentSize) = 0;
    
    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Gets the scrollable content width and height.
    // RETURNS: the scrollable content size    
    virtual void getContentSize(vm_size_struct *size) = 0;
        
    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Sets the view rect inside the scrollable
    virtual void setViewRect(const vm_rect_struct &rect) = 0;

    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Sets the scroll bar style.    
    virtual void setScrollIndicatorStyle(vm_scrollable_scroll_indicator_style_enum style) = 0;
    
    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Sets the scroll indicator image.
    virtual void setScrollIndicatorImg(const vm_image_source_struct &value) = 0;    
    
    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Enables the horizontal scroll bar.
    virtual void enableHorizontalScrollIndicator(VMBOOL isEnable ) = 0;
    
    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Enables the vertical scroll bar.
    virtual void enableVerticalScrollIndicator(VMBOOL isEnable) = 0;
    
    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Sets the content offset.
    virtual void setContentOffset(vm_point_struct offset, VMBOOL isAnimated) = 0;
    
    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Makes the specified rect visible.
    virtual void scrollRectToVisible(vm_rect_struct rect, VMBOOL isAnimated) = 0; 
    
    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Sets the warning content rect.
    virtual void setWarningContentRect(vm_rect_struct rect) = 0;
    
    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Gets the warning content rect.
    virtual void getWarningContentRect(vm_rect_struct *rect) = 0;  
    
    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Sets the valid content rect. 
    virtual void setValidContentRect(vm_rect_struct rect) = 0;
    
    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Gets the valid content rect.
    virtual void getValidContentRect(vm_rect_struct *rect) = 0;
    
    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Gets the current view bounds.
    // RETURNS: current view bounds
    virtual void getViewBounds(vm_rect_struct *bounds) = 0;
    
    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Sets slow factors for horizontal/vertical dragging and free run.
    virtual void setSlowFactor(VMFLOAT horizontalFactor,VMFLOAT verticalFactor, VMFLOAT freerunFactor) = 0;
    
    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Sets the scroll indicator color.
    virtual void setScrollIndicatorColor(const VMCOLOR32 &value) = 0;
    
    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Stops scrolling.
    virtual void stopScrolling() = 0;

    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Sets the deceleration distance limit.
    virtual void setMaxDecelerationDistance(VMINT horizontalDist, VMINT verticalDist) = 0;   
    
    // <group DOM_Scrollable_IVpiScrollable_Method>
    // Sets free run moving unit
    virtual void setFreeRunUnit(vm_size_struct unit) = 0;

};


VPI_CMD_ID_DECLARE_BEGIN(SCROLLABLE)

    CMD_ID_SCROLLABLE_VIEW_CONTENT_WARNING,	
    CMD_ID_SCROLLABLE_VIEW_CONTENT_ERROR, 
	CMD_ID_SCROLLABLE_CONTENT_WARNING,
	CMD_ID_SCROLLABLE_CONTENT_ERROR,	
	CMD_ID_SCROLLABLE_SCROLL_STARTED,	
	CMD_ID_SCROLLABLE_SCROLL_ING,	
	CMD_ID_SCROLLABLE_SCROLL_STOPPED,

/* NOTE. The new IDs must be added at the end */
VPI_CMD_ID_DECLARE_END(SCROLLABLE)


#endif /* __VPI_SCROLLABLE_INTERFACE_H__ */


