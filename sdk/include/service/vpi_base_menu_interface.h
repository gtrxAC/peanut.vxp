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
 *  vpi_base_menu_interface.h
 *
 * Project:
 * --------
 *  Venus Plug-In CP: Base Menu
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  Fred
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VPI_BASE_MENU_INTERFACE_H__
#define __VPI_BASE_MENU_INTERFACE_H__

#include "vmsys.h"
#include "vpi_interface_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"
#include "vpi_object_interface.h"
#include "vpi_frame_interface.h"
#include "vpi_control_interface.h"
#include "vpi_scrollable_interface.h"

/***************************************************************************** 
 * Enum
 *****************************************************************************/

VPI_EVENT_ID_DECLARE_BEGIN(BASE_MENU)
    EVT_ID_BASE_MENU_SET_CACHE_LEN,
/* NOTE. The new IDs must be added at the end */
VPI_EVENT_ID_DECLARE_END(BASE_MENU)


// Indicate the cell is in target region
#define VM_BASE_MENU_CELL_FLAG_TARGET        (1 << 0)

// Indicate this is the first time to update this cell
#define VM_BASE_MENU_CELL_FLAG_FIRSTINIT     (1 << 1)

// Indicate menu is in opening animation state
#define VM_BASE_MENU_CELL_FLAG_OPENING       (1 << 2)

// Indicate menu is in closing animation state
#define VM_BASE_MENU_CELL_FLAG_CLOSING       (1 << 3)


// <group DOM_BaseMenuLayout_IVpiBaseMenuLayout_Enum>
// This enum is for scrolling direction. 
typedef enum
{
    VM_BASE_MENU_LAYOUT_SCROLL_DIR_HORZ, // Horizontal scroll direction
    VM_BASE_MENU_LAYOUT_SCROLL_DIR_VERT, // Vertical scroll direction

    VM_END_OF_ENUM(vm_base_menu_layout_scroll_dir_enum)
} vm_base_menu_layout_scroll_dir_enum;


// <group DOM_BaseMenuLayout_IVpiBaseMenuLayout_Enum>
// This enum is for navigation key.typedef enum 
typedef enum 
{
    VM_BASE_MENU_LAYOUT_NAV_DIR_NAV_DIR_NONE,   // No direction
    VM_BASE_MENU_LAYOUT_NAV_DIR_NAV_DIR_UP,     // Up direction
    VM_BASE_MENU_LAYOUT_NAV_DIR_NAV_DIR_DOWN,   // Down direction 
    VM_BASE_MENU_LAYOUT_NAV_DIR_NAV_DIR_LEFT,   // Left direction
    VM_BASE_MENU_LAYOUT_NAV_DIR_NAV_DIR_RIGHT,  // Right direction

    VM_END_OF_ENUM(vm_base_menu_layout_nav_dir_enum)
} vm_base_menu_layout_nav_dir_enum;

// <group DOM_BaseMenu_IVpiBaseMenu_Enum>
// The touch event type enum
typedef enum
{
    VM_BASE_MENU_CELL_TOUCH_TYPE_DOWN,     // User's finger or pen is press down the cell.
    VM_BASE_MENU_CELL_TOUCH_TYPE_UP,       // User's finger or pen is release up the cell.
    VM_BASE_MENU_CELL_TOUCH_TYPE_TAP,      // User's finger or pen is press down and up on a cell, and FW think it is a tap event.
    VM_BASE_MENU_CELL_TOUCH_TYPE_LONGTAP,  // User's finger or pen is press down on a cell very long.

    VM_END_OF_ENUM(vm_base_menu_cell_touch_type_enum)
} vm_base_menu_cell_touch_type_enum;


/***************************************************************************** 
 * Class IVpiBaseMenu
 *****************************************************************************/
class IVpiBaseMenu;

/***************************************************************************** 
 * Class IVpiBaseMenuLayout
 *****************************************************************************/
class IVpiBaseMenuLayout : public IVpiBase
{
public:
    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayout_Method>
    // set menu
    virtual void setMenu(IVpiBaseMenu* menu) = 0;
    
    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayout_Method>
    // Get the menu object pointer.
    // RETURNS: The associated menu object
    virtual void getMenu(IVpiBaseMenu **menu) = 0;
    
    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayout_Method>
    // Call this function to notify menu to relayout cell.
    virtual void update() = 0;
    
    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayout_Method>
    // Return whether the scrolling direction is vertical
    virtual VMBOOL isScrollVert() = 0;

    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayout_Method>
    // Return the view size of the menu.
    // RETURNS: The menu view size.
    virtual void getViewSize(vm_size_struct *size) = 0;
    
    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayout_Method>
    // Return the view position of the menu.
    // RETURNS: The menu view position.
    virtual void getViewPos(vm_point_struct *pos) = 0;

    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayout_Method>
    // Make a menu item visible in the screen.
    virtual void makeVisible(vm_base_menu_pos_struct p, VMBOOL isAnim) = 0;
};


/***************************************************************************** 
 * Class IVpiBaseMenuLayoutDelegator
 *****************************************************************************/
class IVpiBaseMenuLayoutDelegator : public IVpiBase
{
public:

    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayoutDelegator_Overridable>
    // Return the scroll direction
    // RETURNS: the enum about scroll direction
    virtual vm_base_menu_layout_scroll_dir_enum getScrollDir() = 0;

    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayoutDelegator_Overridable>
    // Return the number of groups of this layout.
    // Inherit should override this method.
    // RETURNS: the number of group count    
    virtual VMINT32 getGroupCount() = 0;
    
    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayoutDelegator_Overridable>
    // Return whether there are group headers
    // RETURNS: VFX_TRUE if has group header, otherwise return VFX_FALSE
    virtual VMBOOL hasGroupHeader(VMINT32 group) = 0;
    
    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayoutDelegator_Overridable>
    // Return the number of cells of a group.
    // Inherit should override this method.
    // RETURNS: The number of cell count
    virtual VMINT32 getCellCount(VMINT32 group) = 0;
    
    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayoutDelegator_Overridable>
    // Return the whole size of the menu.
    // Inherit should override this method.
    // RETURNS: the length of content area
    virtual VMINT32 getContentLength() = 0;

    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayoutDelegator_Overridable>
    // Return the region within a rectangle.
    // RETURNS: The region object about the input rect
    virtual void queryRegion(const vm_rect_struct &r, vm_base_menu_region_struct *region) = 0;
    
    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayoutDelegator_Overridable>
    // Return the header rect of a group
    // RETURNS: the region object for the input group 
    virtual void queryGroupHeaderRect(VMINT32 group, vm_rect_struct *rect) = 0;
    
    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayoutDelegator_Overridable>
    // Return a cell rect
    // RETURNS: the rect for the input menu pos 
    virtual void queryCellRect(vm_base_menu_pos_struct pos, vm_rect_struct *rect) = 0;

    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayoutDelegator_Overridable>
    // Change the Focus Index
    virtual void setFocusItem(vm_base_menu_pos_struct focus, VMBOOL isMoveToVisible) = 0;
    
    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayoutDelegator_Overridable>
    // Query the focus index
    // RETURNS: the menu pos about focus item
    virtual void getFocusItem(vm_base_menu_pos_struct *pos) = 0;
    
    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayoutDelegator_Overridable>
    // Clear Focus, so the lauout will clear focus index.
    virtual void clearFocusItem() = 0;

    // <group DOM_BaseMenuLayout_IVpiBaseMenuLayoutDelegator_Overridable>
    // Change the focus by Navigation key
    // RETURNS: VFX_TRUE if you can navigation by this direction
    virtual VMBOOL navDir(vm_base_menu_layout_nav_dir_enum dir) = 0;
};


/***************************************************************************** 
 * Class IVpiBaseMenu
 *****************************************************************************/
class IVpiBaseMenu : public IVpiBase
{
public:
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Method>
    // Return the layout object which return from createLayout function.
    // RETURNS: the layout object
    virtual void getLayout(IVpiBaseMenuLayout **layout) = 0;
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Method>
    // This method notify the menu that the layout changed, 
    //  so menu need to do re-layout.
    virtual void updateLayout() = 0;
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Method>
    // Get the cell frame if the frame is exist
    virtual void getCellIfPresent(VMINT32 group, VMINT32 pos, IVpiFrame **cell) = 0;
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Method>
    // Get the header frame if the frame is exist
    virtual void getHeaderIfPresent(VMINT32 group, IVpiFrame **header) = 0;

    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Method>
    // Query the region about valid view. This function will convert rect into region object.
    // RETURNS: The region about real content rect
    virtual void getRealContentRegion(vm_base_menu_region_struct *region) = 0;

    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Method>
    // Scroll the view to make the cell visible
    virtual void makeVisible(vm_base_menu_pos_struct p, VMBOOL isAnim) = 0;
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Method>
    // Scroll a rectangle into view
    virtual void makeVisible(const vm_rect_struct& r, VMBOOL isAnim) = 0;

    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Method>
    // Get the current view state, you can set the data back to base menu to restore previous view state.
    virtual void getViewState(vm_base_menu_view_state_struct* history) = 0;
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Method>
    // Restore the menu view state, you can get the view state by getViewState API.
    virtual void setViewState(vm_base_menu_view_state_struct* history) = 0;
};


/***************************************************************************** 
 * Class IVpiBaseMenuDelegator
 *****************************************************************************/
class IVpiBaseMenuDelegator : public IVpiBase
{
public:

    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // Create a layout object for menu.
    // Inheritor should override this function.
    // RETURNS: a layout object 
    // SEE ALSO: VcpBaseLayout
    virtual void createLayout(IVpiBaseMenuLayout **layout) = 0;
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // After menu create a new layout and query basic information.
    virtual void onAfterCreateLayout() = 0;

    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // Create a group header.
    // Inheritor should override this function.
    // RETURNS: a group object 
    // SEE ALSO: VcpBaseLayout
    virtual void createGroupHeader(VMINT32 group, IVpiFrame **header) = 0;
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // Create a cell object.
    // Inheritor should override this function.
    // RETURNS: a cell object 
    // SEE ALSO: VcpBaseLayout
    virtual void createCell(VMINT32 group, VMINT32 pos, IVpiFrame **cell) = 0;
        
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // A notify that menu is going to close a header
    virtual void onCloseGroupHeader(VMINT32 group, IVpiFrame* groupFrame) = 0;
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // A notify that menu is going to close a cell
    virtual void onCloseCell(VMINT32 group, VMINT32 pos, IVpiFrame* cellFrame) = 0;

    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // Notify before updating cell and group.
    virtual void onBeforeUpdate(const vm_base_menu_region_struct &currentRegion, const vm_base_menu_region_struct &targetRegion) = 0;
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // Notify before updating cell and group.
    virtual void onAfterUpdate(const vm_base_menu_region_struct &currentRegion, const vm_base_menu_region_struct &targetRegion) = 0;
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // Notify to update a header's attributes
    // Inheritor should override this function.
    virtual void onUpdateGroupHeader(const vm_rect_struct &rect, VMINT32 group, IVpiFrame* groupObject, VMUINT32 flag) = 0;
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // Notify to update a cell's attributes
    // Inheritor should override this function.
    virtual void onUpdateCell(const vm_rect_struct &rect, VMINT32 group, VMINT32 pos, IVpiFrame* cell, VMUINT32 flag) = 0;

    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // set the default parameters
    virtual void reset() = 0;

    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // Notify when a group header is clicked
    virtual void onTapGroupHeader(VMINT32 group, IVpiFrame* groupObject) = 0;
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // Notify when a cell is clicked
    virtual void onTapCell(VMINT32 group, VMINT32 pos, IVpiFrame* cell) = 0;
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // Notify when a cell or header is interact.
    virtual void onTouchCell(vm_base_menu_pos_struct cellPos, vm_base_menu_cell_touch_type_enum touchType, vm_point_struct pt, IVpiFrame* cell) = 0;

    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // Notify when the focus item is change
    virtual void onFocusIndexChange(vm_base_menu_pos_struct focusItem, vm_base_menu_pos_struct previousFocusItem) = 0;

    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // Notify when the user start drag the menu
    virtual void onDragStart() = 0;
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // Notify when the user stop drag the menu
    virtual void onDragEnd() = 0;
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // Notify the view is scrolling.
    virtual void onViewScrollStart() = 0;
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // Notify the view is end of scrolling.
    virtual void onViewScrollEnd() = 0;
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // Notify when the view is dragged
    virtual void onDrag(VMINT32 xoffset, VMINT32 yoffset) = 0;
    
    // <group DOM_BaseMenu_IVpiBaseMenuDelegator_Overridable>
    // Override this function to decide whether your menu support transition effect.
    // If you return True in this function, base menu will enter closing and opening state when reset layout.
    // Usually it can use to do some animation effect when change content.
    // Default value in base class is True.
    // RETURNS: VFX_TRUE if support transition, otherwise return VFX_FALSE
    virtual VMBOOL IsSupportTransition() = 0;
};


#endif /* __VPI_BASE_MENU_INTERFACE_H__ */

