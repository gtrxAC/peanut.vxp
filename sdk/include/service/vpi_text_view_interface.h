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
 *  vpi_text_view_interface.h
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
#ifndef __VPI_TEXT_VIEW_INTERFACE_H__
#define __VPI_TEXT_VIEW_INTERFACE_H__

#include "vmsys.h"
#include "vpi_interface_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"
#include "vpi_control_interface.h"


// <group DOM_TextView_VpiTextView_Enum>
// Enum for text view line mode
typedef enum
{
    // Single line mode
    VM_TEXT_LINE_MODE_SINGLE = 0,
    // Multiline mode
    VM_TEXT_LINE_MODE_MULTI,

    VM_END_OF_ENUM(vm_text_line_mode_enum)
} vm_text_line_mode_enum;

// <group DOM_TextView_VpiTextView_Enum>
// Enum for text view truncate mode
typedef enum
{
    VM_TEXT_TRUNCATE_MODE_NONE = 0,
    // Add the truncate string at end of missing text.
    VM_TEXT_TRUNCATE_MODE_END,
    // Add the truncate string at the middle of text
    VM_TEXT_TRUNCATE_MODE_MID,
    // truncate with frame max limitation
    VM_TEXT_TRUNCATE_WITH_AUTO_RESIZE,

    VM_END_OF_ENUM(vm_text_truncate_mode_enum)
} vm_text_truncate_mode_enum;

// <group DOM_TextView_VpiTextView_Enum>
// Enum for text view keyword type
typedef enum 
{
    VM_TEXT_KEYWORD_NONE        = 0x0,
    VM_TEXT_KEYWORD_EMAIL       = 0x1,
    VM_TEXT_KEYWORD_URL         = 0x2,
    VM_TEXT_KEYWORD_PHONENUMBER = 0x4,
    VM_TEXT_KEYWORD_USSD        = 0x8,

    VM_END_OF_ENUM(vm_text_keyword_enum)
} vm_text_keyword_enum;

// <group DOM_TextView_VpiTextView_Struct>
// Text emotion icon table struct
typedef struct
{
    VM_STRUCT_HEADER
    VMINT32 imageId;
    const VMWSTR text;
} vm_text_icon_table_struct;

// <group DOM_TextView_VpiTextView_Struct>
// text format struct
typedef struct
{
    VM_STRUCT_HEADER
    VMINT32 start;
    VMINT32 end;
    vm_font_desc_struct font;
    VMCOLOR32 textColor;
    VMCOLOR32 textBgColor;
} vm_text_format_struct;

// <group DOM_TextView_VpiTextView_Enum>
// Horizontal alignment mode
typedef enum
{
    // The natural alignment according to the system language
    VM_TEXT_HORI_ALIGN_MODE_NATURAL = 0,
    // Align text to the left side of frame bounds
    VM_TEXT_HORI_ALIGN_MODE_LEFT,
    // Align text to the right side of frame bounds
    VM_TEXT_HORI_ALIGN_MODE_RIGHT,
    // Align text to the center of frame bounds
    VM_TEXT_HORI_ALIGN_MODE_CENTER,

    VM_END_OF_ENUM(vm_text_hori_align_enum)
} vm_text_hori_align_enum;

// <group DOM_TextView_VpiTextView_Enum>
// Vertical alignment mode
typedef enum
{
    // align top
    VM_TEXT_VERT_ALIGN_MODE_TOP = 0,
    // align middle
    VM_TEXT_VERT_ALIGN_MODE_MID,
    // align bottom
    VM_TEXT_VERT_ALIGN_MODE_BOTTOM,
    // align end
    VM_END_OF_ENUM(vm_text_vert_align_enum)
} vm_text_vert_align_enum;

// <group DOM_TextView_VpiTextView_Enum>
// Enum for text encoding type
typedef enum
{
    // UCS2 encoding type
    VM_TEXT_ENCODING_UCS2,

    // GB encoding type
    VM_TEXT_ENCODING_GB2312,

    // ascii encoding based length
    // if input ASCII char, can input N chars,
    // if input UCS2 char, can only input N/2 chars
    VM_TEXT_ENCODING_ASCII,

    // gsm char based length
    // if input GSM char, can input N chars,
    // if input UCS2 char, can only input N/2 chars
    // if input GSM extension char, it will +2
    VM_TEXT_ENCODING_GSM,

    // 0x81 encoding
    VM_TEXT_ENCODING_0X81,

    // UTF8 encoding type
    VM_TEXT_ENCODING_UTF8,

    // End of enum
    VM_END_OF_ENUM(vm_text_encoding_enum)
} vm_text_encoding_enum;

// <group DOM_TextView_VpiTextView_Enum>
// tap area enum
typedef enum
{
    // Tap on text
    VM_TEXT_TAP_AREA_TEXT = 0,
    // Tap on object
    VM_TEXT_TAP_AREA_OBJECT,
    // Tap on empty area
    VM_TEXT_TAP_AREA_EMPTY,

    VM_END_OF_ENUM(vm_text_tap_area_enum)
} vm_text_tap_area_enum;

// <group DOM_TextView_VpiTextView_Enum>
// Enum for text change type
typedef enum
{
    // the text to be insert
    VM_TEXT_CHANGE_INSERT_CHAR,
    // the text to be delete
    VM_TEXT_CHANGE_DELETE_CHAR,
    // the text to be delete all
    VM_TEXT_CHANGE_DELETE_ALL,
    // the string to be insert
    VM_TEXT_CHANGE_INSERT_STR,
    // END of Enum
    VM_END_OF_ENUM(vm_text_change_enum)
} vm_text_change_enum;

/*
 * class IVpiTextView
 */
class IVpiTextView : public IVpiBase
{
public:
    // <group DOM_TextView_IVpiTextView_Method>
    // Set text to text view
    virtual void setText(const vm_wstring_struct &value, VMBOOL isStatic = VM_FALSE) = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Get text of text view
    virtual VMWSTR getText() = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Get text length of text view
    virtual VMINT32 getTextLength() = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Set text font
    virtual void setFont(const vm_font_desc_struct &fontDesc) = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Get text font
    virtual vm_font_desc_struct* getFont() = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Set line mode (singleline or multiline), by default, text view is multiline mode
    virtual void setLineMode(vm_text_line_mode_enum value) = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Set text view margin value on left/right/top/bottom
    virtual void setMargins(VMINT32 leftMargin, VMINT32 topMargin, VMINT32 rightMargin, VMINT32 bottomMargin) = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Get text view margin value on left/right/top/bottom
    virtual void getMargins(VMINT32 *leftMargin, VMINT32 *topMargin, VMINT32 *rightMargin, VMINT32 *bottomMargin) = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Set keyword mode (text view will parse the url/email/ussd/phonenumber and display with underline)
    virtual void setKeyword(VMINT32 mode) = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Set icon mode (text view will display the icon instead of text which mapped in passed table)
    virtual void setIconMode(VMBOOL value, vm_text_icon_table_struct *table, VMUINT8 table_size) = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Set truncate mode when text length exceed the boundary
    virtual void setTruncateMode(vm_text_truncate_mode_enum value) = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Set text color
    virtual void setTextColor(VMCOLOR32 value) = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Set min line height
    virtual void setMinLineHeight(VMINT32 value) = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Set horizontal align mode
    virtual void setHorizontalAlignMode(vm_text_hori_align_enum value) = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Set vertical align mode
    virtual void setVerticalAlignMode(vm_text_vert_align_enum value) = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Get total line count after layout done
    virtual VMINT32 getLineCount() = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Set auto resize mode
    virtual void setAutoResized(VMBOOL value, VMINT32 minHeight = -1, VMINT32 maxHeight = -1) = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Set auto adjust font size mode according to given bounds
    virtual void setAutoFontSize(VMBOOL value) = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Force udpate all text view content immediately
    virtual void forceUpdate(VMBOOL isAsyncUpdate = VM_TRUE) = 0;

    // <group DOM_TextView_IVpiTextView_Method>
    // Set text format to text view
    virtual void setTextFormat(vm_text_format_struct *format) = 0;

};


VPI_CMD_ID_DECLARE_BEGIN(TEXT_VIEW)

    CMD_ID_TEXT_VIEW_KEYWORD_CLICKED,

/* NOTE. The new IDs must be added at the end */
VPI_CMD_ID_DECLARE_END(TEXT_VIEW)


#endif /* __VPI_TEXT_VIEW_INTERFACE_H__ */

