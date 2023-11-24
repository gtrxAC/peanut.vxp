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
 *  vpi_text_editor_interface.h
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
 *  Fangyi Huang (mtk80175)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VPI_TEXT_EDITOR_INTERFACE_H__
#define __VPI_TEXT_EDITOR_INTERFACE_H__

#include "vmsys.h"
#include "vpi_interface_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"
#include "vpi_text_view_interface.h"

/*
 * class IVpiTextEditor
 */
class IVpiTextEditor : public IVpiBase
{
public:
    // <group DOM_TextEditor_IVpiTextEditor_Method>
    // Set a editable string with a specfic encoding type for counter
    virtual void setText(VMWSTR text, VMINT32 maxLen, VMBOOL isStatic = VM_FALSE, vm_text_encoding_enum encoding = VM_TEXT_ENCODING_UCS2) = 0;

    // <group DOM_TextEditor_IVpiTextEditor_Method>
    // Set input method
    virtual void setIME(VMUINT64 inputType, VMUINT32 inputSetting = 0) = 0;

    // <group DOM_TextEditor_IVpiTextEditor_Method>
    // Activate editor
    virtual void activate() = 0;

    // <group DOM_TextEditor_IVpiTextEditor_Method>
    // Deactivate editor
    virtual void deactivate() = 0;

    // <group DOM_TextEditor_IVpiTextEditor_Method>    
    // Return if editor is active or not
    virtual VMBOOL isActive() = 0;

    // <group DOM_TextEditor_IVpiTextEditor_Method>
    // Set editor background image when inactive state (In unfocus state)
    virtual void setInactiveBgImage(VMRESID value) = 0;

    // <group DOM_TextEditor_IVpiTextEditor_Method>
    // Set editor background image when active state (In focus state)
    virtual void setActiveBgImage(VMRESID value) = 0;

    // <group DOM_TextEditor_IVpiTextEditor_Method>
    // Set hint text which is displayed when editor content is empty and editor is deactivate
    // For example "Please input"
    virtual void setHint(const vm_wstring_struct &value) = 0;

    // <group DOM_TextEditor_IVpiTextEditor_Method>
    // Set if need to disable editor default background image
    virtual void setIsDisableBgImage(VMBOOL value) = 0;

    // <group DOM_TextEditor_IVpiTextEditor_Method>
    // Set editor cursor index (in text buffer)
    virtual void setCursorIndex(VMINT32 value) = 0;

    // <group DOM_TextEditor_IVpiTextEditor_Method>
    // Get editor cursor index (in text buffer)
    virtual VMINT32 getCursorIndex() = 0;

    // <group DOM_TextEditor_IVpiTextEditor_Method>
    // Delete all text in editor
    virtual void deleteAll() = 0;

    // <group DOM_TextEditor_IVpiTextEditor_Method>
    // Insert text to editor
    virtual VMUINT32 insertText(VMWSTR str) = 0;

    // <group DOM_TextEditor_IVpiTextEditor_Method>
    // Delete text in editor
    virtual VMUINT32 deleteText(VMINT32 start, VMINT32 end) = 0;
};



VPI_CMD_ID_DECLARE_BEGIN(TEXT_EDITOR)

    CMD_ID_TEXT_EDITOR_TEXT_CHANGED,
    CMD_ID_TEXT_EDITOR_ACTIVATED,
    CMD_ID_TEXT_EDITOR_BEFORE_CHANGE,
    CMD_ID_TEXT_EDITOR_CURSOR_IDX_CHANGED,

/* NOTE. The new IDs must be added at the end */
VPI_CMD_ID_DECLARE_END(TEXT_EDITOR)


#endif /* __VPI_TEXT_EDITOR_INTERFACE_H__ */

