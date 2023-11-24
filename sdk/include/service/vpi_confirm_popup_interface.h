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
 *  vpi_confirm_popup_interface.h
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
 *  Siddhartha Saxena
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VPI_CONFIRM_POPUP_INTERFACE_H__
#define __VPI_CONFIRM_POPUP_INTERFACE_H__

#include "vmsys.h"
#include "vpi_interface_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"
#include "vpi_base_popup_interface.h"
#include "vpi_popup_data_type.h"

#define     VM_CONFIRM_POPUP_BUTTON_NONE       (0)
#define     VM_CONFIRM_POPUP_BUTTON_OK         ('OK')
#define     VM_CONFIRM_POPUP_BUTTON_CANCEL     ('NoOK')
#define     VM_CONFIRM_POPUP_BUTTON_YES        ('YES')
#define     VM_CONFIRM_POPUP_BUTTON_NO         ('NO')
#define     VM_CONFIRM_POPUP_BUTTON_USER_1     ('USR1')
#define     VM_CONFIRM_POPUP_BUTTON_USER_2     ('USR2')


enum VMConfirmPopupButtonSetEnum
{
    VM_CONFIRM_BUTTON_SET_NONE,
    VM_CONFIRM_BUTTON_SET_OK,              // One Button with "Ok" label.
    VM_CONFIRM_BUTTON_SET_CANCEL,          // One Button with "Cancel" label.
    VM_CONFIRM_BUTTON_SET_YES_NO,          // Two Buttons with "Yes" and "No" label.
    VM_CONFIRM_BUTTON_SET_USER_DEFINE,     // Two Buttons with customised labels.

    VM_END_OF_ENUM(VMConfirmPopupButtonSetEnum)
};


/*
 * Class IVpiConfirmPopup
 */
class IVpiConfirmPopup : public IVpiBase
{
public:
    // <group DOM_ConfirmPopup_IVpiConfirmPopup_Method>
    // Sets popup text.
    virtual void setText(const vm_wstring_struct &text) = 0;

    // <group DOM_ConfirmPopup_IVpiConfirmPopup_Method>
    // Sets info type for popup.
    virtual void setInfoType(VMPopupTypeEnum type) = 0;

    // <group DOM_ConfirmPopup_IVpiConfirmPopup_Method>
    // Sets custom buttom, user can set at most 2 buttons.
    // Use button type enum to change the button appearence.
    virtual void setCustomButton(const vm_wstring_struct &btnText1, const vm_wstring_struct &btnText2, VMPopupButtonTypeEnum type1, VMPopupButtonTypeEnum type2) = 0;

    // <group DOM_ConfirmPopup_IVpiConfirmPopup_Method>
    // Sets default button set.
    virtual void setButtonSet(VMConfirmPopupButtonSetEnum buttonSet) = 0;

    // <group DOM_ConfirmPopup_IVpiConfirmPopup_Method>
    // Gets popup text.
    virtual void getText(vm_wstring_struct *wstring) = 0;

    // <group DOM_ConfirmPopup_IVpiConfirmPopup_Method>
    // Gets popup info type.
    // RETURNS :
    // Info type enum value.
    virtual VMPopupTypeEnum getInfoType() = 0;

    // <group DOM_ConfirmPopup_IVpiConfirmPopup_Method>
    // Sets icon image.
    virtual void setImage(const vm_image_source_struct &imgSrc) = 0;

    // <group DOM_ConfirmPopup_IVpiConfirmPopup_Method>
    // Sets text alignment mode.
    virtual void setTextAlignMode(vm_text_frame_align_mode_enum value) = 0;
};


VPI_CMD_ID_DECLARE_BEGIN(CONFIRM_POPUP)

    CMD_ID_CONFIRM_POPUP_BUTTON_CLICKED,

/* NOTE. The new IDs must be added at the end */
VPI_CMD_ID_DECLARE_END(CONFIRM_POPUP)

#endif /* __VPI_CONFIRM_POPUP_INTERFACE_H__ */

