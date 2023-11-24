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
 *  vpi_settings_menu_pages_interface.h
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
 *  Ankur Mathur (mtk33056)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VPI_SETTINGS_MENU_PAGES_INTERFACE_H__
#define __VPI_SETTINGS_MENU_PAGES_INTERFACE_H__

#include "vmsys.h"
#include "vpi_interface_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"
#include "vpi_control_interface.h"

// Invalid ID value
#define VM_SETTINGS_INVALID_ID 0xffffffff

// Maximum length of string supported by text frames used in this components.
#define VM_SETTINGS_MENU_MAX_STRING_LENGTH 129

// Structure for the data required for a single IVpiSettingsSelListPage list cell.
typedef struct _vm_settings_sel_list_item_data
{	
    VM_STRUCT_HEADER
    VMUINT32      m_idx;
    vm_wstring_struct m_text;
    vm_wstring_struct m_subText1;
    vm_wstring_struct m_tailText;	
    VMBOOL    m_isSelected;
    VMBOOL    m_isDisabled;
    VMBOOL    m_isHidden;
} vm_settings_sel_list_item_data;

// Function pointer type accepted by IVpiSettingsSelListPage for dynamic cell data retrieval.
typedef void (*VMSettingsSelListGetItemData)(VMUINT32 index, vm_settings_sel_list_item_data *data);

// Enum of all item types supported by IVpiSettingsStandardPage
// <group DOM_SettingsMenu_Macro&Enum_Enum>
enum VMSettingsStandardPageItemType
{
    VM_SETTINGS_ITEM_LAUNCHER,
    VM_SETTINGS_ITEM_SWITCH,
    VM_SETTINGS_ITEM_AID_BUTTON,

    VM_END_OF_ENUM(VMSettingsStandardPageItemType)
};

// Enum of all possible modes of a IVpiSettingsSelListPage list.
// <group DOM_SettingsMenu_Macro&Enum_Enum>
enum VMSettingsSelListMode
{
    VM_SETTINGS_NORMAL_MODE,
    VM_SETTINGS_CHECKBOXLIST_MODE,
    VM_SETTINGS_RADIOLIST_MODE,

    VM_END_OF_ENUM(VMSettingsSelListMode)
};

// Enum of all possible input methods to a IVpiSettingsSelListPage object.
// <group DOM_SettingsMenu_Macro&Enum_Enum>
enum VMSettingsSelListDataInputMethod
{
    VM_SETTINGS_STATIC_INPUT,   // Static input mode. Cell Data storage handled by IVpiSettingsSelListPage
    VM_SETTINGS_DYNAMIC_INPUT,   // Dynamic input mode. Cell Data storage handled by Application

    VM_END_OF_ENUM(VMSettingsSelListDataInputMethod)
};

/*
 * class IVpiSettingsBasePage
 */
class IVpiSettingsBasePage : public IVpiBase
{
public:
    // Set the title text of page
    // <group DOM_SettingsMenu_IVpiSettingsBasePage_Property>    
    virtual void setPageTitleText(const vm_wstring_struct &text) =  0;
    // Get the title text of page
    // <group DOM_SettingsMenu_IVpiSettingsBasePage_Property>    
    virtual void getPageTitleText(vm_wstring_struct &text) =  0;

    // Insert a new toolbar button. The BtnId should be unique for each toolbar button in a page.    
    // <group DOM_SettingsMenu_IVpiSettingsBasePage_Method>    
    virtual VMBOOL insertToolBarBtn(VMID BtnId, const vm_wstring_struct &text, const vm_image_source_struct &icon, VMID beforeId = VM_SETTINGS_INVALID_ID) =  0;
    // Remove a particular button from the page's toolbar
    // <group DOM_SettingsMenu_IVpiSettingsBasePage_Method>    
    virtual VMBOOL removeToolBarBtn(VMID BtnId) =  0;

    // Set a particular button in toolbar as disabled or enabled
    // <group DOM_SettingsMenu_IVpiSettingsBasePage_Method>
    virtual VMBOOL setToolBarBtnIsDisabled(VMID BtnId, VMBOOL state) =  0;
    // Get whether a particular button in toolbar is disabled or not
    // <group DOM_SettingsMenu_IVpiSettingsBasePage_Method>
    virtual VMBOOL getToolBarBtnIsDisabled(VMID BtnId) =  0;

    // <group DOM_SettingsMenu_IVpiSettingsBasePage_Method>    
    // Make the current page visible
    // Pushes the current page to the top of page stack    
    // It's a convenience method. Same could be done using the parent screen API.
    virtual void push() =  0;
    // Remove the current page from top, if it is on top.  
    // It's a convenience method. Same could be done using the parent screen API.  
    // <group DOM_SettingsMenu_IVpiSettingsBasePage_Method>    
    virtual void popIfOnTop() =  0;
    // Close the current page.
    // It's a convenience method. Same could be done using the parent screen API.      
    // <group DOM_SettingsMenu_IVpiSettingsBasePage_Method>
    virtual void closePage() =  0;
};


/*
 * class IVpiSettingsStandardPage
 */
class IVpiSettingsStandardPage : public IVpiBase
{
public:
    // Insert a new item to the standard page. 
    // <group DOM_SettingsMenu_IVpiSettingsStandardPage_Method>    
    virtual VMBOOL insertItem(VMID id, VMSettingsStandardPageItemType itemType, VMID AfterId = VM_SETTINGS_INVALID_ID) = 0;
    // Remove a particular item from the page
    // <group DOM_SettingsMenu_IVpiSettingsStandardPage_Method>        
    virtual VMBOOL removeItem(VMID id) = 0;
    
    // Set the main text for a particular item in the standard page
    // <group DOM_SettingsMenu_IVpiSettingsStandardPage_Method>        
    virtual VMBOOL setItemMainText(VMID id, const vm_wstring_struct &text) = 0;
    // Set the isDisabled status for a particular item in the standard page
    // <group DOM_SettingsMenu_IVpiSettingsStandardPage_Method>        
    virtual VMBOOL setItemIsDisabled(VMID id,  VMBOOL state) = 0;
    // Set the isHidden status for a particular item in the standard page
    // <group DOM_SettingsMenu_IVpiSettingsStandardPage_Method>    
    virtual VMBOOL setItemIsHidden(VMID id,  VMBOOL state) = 0;
    // Set the hint text for a particular item. 
    // Hint text shows below the main text
    // <group DOM_SettingsMenu_IVpiSettingsStandardPage_Method>            
    virtual VMBOOL setItemHintText(VMID id, const vm_wstring_struct &text) = 0;
    
    // Set the switch state of a particular item.
    // This works only on VM_SETTINGS_ITEM_SWITCH type items, for obvious reasons
    // <group DOM_SettingsMenu_IVpiSettingsStandardPage_Method>        
    virtual VMBOOL setItemSwitchState(VMID id, VMBOOL state) = 0;    
    
    // Set the icon image on the aid-button of a particular item.
    // Aid button shows up on the right end of VM_SETTINGS_ITEM_AID_BUTTON type items
    // This works only on VM_SETTINGS_ITEM_AID_BUTTON type items, for obvious reasons        
    // <group DOM_SettingsMenu_IVpiSettingsStandardPage_Method>        
    virtual VMBOOL setItemIconOnAidButton(VMID id, const vm_image_source_struct &icon) = 0;		
    
    // Get the main text for a particular item in the standard page    
    // <group DOM_SettingsMenu_IVpiSettingsStandardPage_Method>              
    virtual void getItemMainText(VMID id, vm_wstring_struct &text) = 0;    
    // Get the hint text for a particular item in the standard page        
    // <group DOM_SettingsMenu_IVpiSettingsStandardPage_Method>        
    virtual void getItemHintText(VMID id, vm_wstring_struct &text) = 0;    
    // <group DOM_SettingsMenu_IVpiSettingsStandardPage_Method>        
    virtual VMBOOL getItemSwitchState(VMID id) = 0;    
    // Get the icon image on the aid-button of a particular item.
    // This works only on VM_SETTINGS_ITEM_AID_BUTTON type items, for obvious reasons            
    // <group DOM_SettingsMenu_IVpiSettingsStandardPage_Method>    
    virtual void getItemIconOnAidButton(VMID id, vm_image_source_struct &icon) = 0;			
};


/*
 * class IVpiSettingsSelListPage
 */
class IVpiSettingsSelListPage : public IVpiBase
{
public:
    // Set the list mode.
    // List could be a single selection, multi selection or normal text list.
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Property>        
    virtual VMBOOL setListMode(VMSettingsSelListMode mode) = 0;
    // Get the current list mode.
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Property>            
    virtual VMSettingsSelListMode getListMode() = 0;
    // Set the callback function that would be called frequently by list to retrieve cell data.
    // This callback would be called several times, so try to keep it light so it does not result in scrolling lag.
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Property>            
    virtual void setItemContentProviderCallback(VMSettingsSelListGetItemData getItemDataForIndex) = 0; 
    // Set the input-mode for the list
    // Static input: In this case, app. would insert/update cell data using APIs, and list would store/maintain this data for each cell till the end
    // Dynamic input: In this case, list would use the app. callback (assigned using setItemContentProviderCallback) for cell data.
    //                This callback would be called frequently when scrolling list. It shoudl always be ready with latest data for each cell index.
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Property>            
    virtual void setListInputMode(VMSettingsSelListDataInputMethod mode) = 0; 
    // Get the current list input mode.
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Property>            
    virtual VMSettingsSelListDataInputMethod getListInputMode() = 0;
    // Set the total item count. 
    // This is not applicable in Static input mode, since list maintains item count on its own
    // This is necessary to be correct value in Dynamic input mode, since list would query cell data only for this many cells.
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Property>            
    virtual void setTotalItemCount(VMUINT32 count) = 0;
    // Get the current tem count.
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Property>            
    virtual VMUINT32 getTotalItemCount() = 0;
    
    // Insert new item to the list.
    // Applicable only with static input mode.
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Method>            
    virtual VMUINT32 insertItem(const vm_wstring_struct &text, VMUINT32 index = VM_SETTINGS_INVALID_ID) = 0;
    // Remove a particular item from the list.
    // Applicable only with static input mode.    
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Method>                
    virtual VMBOOL removeItem(VMUINT32 idx) = 0;    
    
    // Item properties:
    
    // Set the main text for a particular item.
    // Applicable only with static input mode.    
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Method>            
    virtual VMBOOL setItemMainText(VMUINT32 idx,const vm_wstring_struct &text) = 0;
    // Set the sub-text-1 for a particular item. It shows up below the main text
    // Applicable only with static input mode.        
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Method>            
    virtual VMBOOL setItemSubText1(VMUINT32 idx,const vm_wstring_struct &text) = 0;
    // Set the tail-text for a particular item. It shows up on the right of main text, but in a smaller font size.
    // Applicable only with static input mode.            
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Method>            
    virtual VMBOOL setItemTailText(VMUINT32 idx,const vm_wstring_struct &text) = 0;	
    // Set a particular item as disabled/enabled
    // Applicable only with static input mode.            
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Method>            
    virtual VMBOOL setItemIsDisabled(VMUINT32 idx,  VMBOOL state) = 0;
    // Set a particular item as selected.
    // Applicable only with static input mode.                
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Method>            
    virtual VMBOOL setItemIsSelected(VMUINT32 idx, VMBOOL state) = 0;

    // Get the current main text for a particular item
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Method>            
    virtual void getItemMainText(VMUINT32 idx, vm_wstring_struct &text) = 0;
    // Get the current sub-text-1 for a particular item
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Method>                
    virtual void getItemSubText1(VMUINT32 idx, vm_wstring_struct &text) = 0;
    // Get the current tail-text for a particular item
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Method>            
    virtual void getItemTailText(VMUINT32 idx, vm_wstring_struct &text) = 0;	
    
    // Get whether a particular item is selected or not.
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Method>            
    virtual VMBOOL getItemIsSelected(VMUINT32 idx) = 0;
    // Get whether a particular item is disabled or not.
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Method>            
    virtual VMBOOL getItemIsDisabled(VMUINT32 idx) = 0;

    // Set the search bar as enabled
    // Search bar displays just below the title bar. 
    // It is independent of list operations. Application needs to coordinate search actions and resulting list.
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Property>            
    virtual void setSearchIsEnabled(VMBOOL isEnabled) = 0;
    // Get whether search bar is enabled or not.
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Property>            
    virtual VMBOOL getSearchIsEnabled() = 0;
    // Get the current search text.
   // It will provide the search editor contents as a string.
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Property>            
    virtual void getCurrentSearchText(vm_wstring_struct &text) = 0;
    // Set the search bar options.
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Method>            
    virtual void setSearchBoxOptions(VMBOOL showSearchButton, const vm_wstring_struct &hint, const vm_wstring_struct &label) = 0;    
    // Display an animating activity indicator.
    // This is helpful to indicate that some processing is going on, and so user needs to wait.
    // To hide the indicator, just call this function with VFX_FALSE.
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Method>            
    virtual void showActivityIndicator(VMBOOL isShown) = 0;	
    // Set the empty-list-text 
    // This text shows up on the list frame whenever the list is empty.
    // Set it to NULL/EMPTY string if you do not want any text on empty lists.
    // Please note that this text does not show up if list has atleast 1 item.
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Property>            
    virtual void setEmptyListText(const vm_wstring_struct &text) = 0;
    // Get the current empty-list-text
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Property>            
    virtual void getEmptyListText(vm_wstring_struct &text) = 0;

    // Set whether the menu items are focussed when touched. 
    // This should be set TRUE, when the menu items have some action mapped on them.
    // It should be set FALSE, if list items are just to show information, but don't do any action when tapped.
    // Default value = VM_TRUE    
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Property>            
    virtual void setIsItemFocussedOnTouch(VMBOOL state) = 0;
    // Get whether the menu items are focussed when touched. 
    // <group DOM_SettingsMenu_IVpiSettingsSelListPage_Property>            
    virtual VMBOOL getIsItemFocussedOnTouch() = 0;
};


VPI_CMD_ID_DECLARE_BEGIN(SETTINGS_PAGE)

    CMD_ID_SETTINGS_BASE_PAGE_TOOLBAR_CLICK,	
    CMD_ID_SETTINGS_BASE_PAGE_AUTO_CLOSE,
    
    CMD_ID_SETTINGS_STANDARD_PAGE_ITEM_TAP,
    CMD_ID_SETTINGS_STANDARD_PAGE_ITEM_SWITCH_TOGGLE_REQ,
    CMD_ID_SETTINGS_STANDARD_PAGE_ITEM_AID_BUTTON_PRESS,

    CMD_ID_SETTINGS_SEL_LIST_SELECTION_TOGGLE,	
    CMD_ID_SETTINGS_SEL_LIST_SEARCH_TEXT_CHANGE,
    CMD_ID_SETTINGS_SEL_LIST_SEARCH_BUTTON_CLICK,
    

/* NOTE. The new IDs must be added at the end */
VPI_CMD_ID_DECLARE_END(SETTINGS_PAGE)


#endif /* __VPI_SETTINGS_MENU_PAGES_INTERFACE_H__ */
