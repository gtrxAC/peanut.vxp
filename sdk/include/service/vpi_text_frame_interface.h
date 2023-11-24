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
 *  vpi_text_frame_interface.h
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
#ifndef __VPI_TEXT_FRAME_INTERFACE_H__
#define __VPI_TEXT_FRAME_INTERFACE_H__

#include "vmsys.h"
#include "vpi_interface_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"
#include "vpi_frame_interface.h"


/*
 * class IVpiTextFrame
 */
class IVpiTextFrame : public IVpiBase
{
public:

    // The text to be draw on the frame
    //
    // NOTE: The default value is null string.
    virtual void getString(vm_wstring_struct *wstring) = 0;

    // The color of the text
    //
    // NOTE: The default value is VM_COLOR_WHITE.
    virtual const VMCOLOR32 getColor() = 0;

    // The horizontal alignment mode
    //
    // NOTE: The default value is VM_ALIGN_MODE_NATURAL.
    //
    // SEE ALSO: vm_text_frame_align_mode_enum
    virtual vm_text_frame_align_mode_enum getAlignMode() = 0;

    // The truncate mode
    //
    // NOTE: The default value is VM_TRUNCATE_MODE_NONE.
    //    
    // SEE ALSO: vm_text_frame_truncate_mode_enum
    virtual vm_text_frame_truncate_mode_enum getTruncateMode() = 0;

    // Whether the auto resized is enabled
    //
    // NOTE: The default value is VM_TRUE.
    virtual VMBOOL getAutoResized() = 0;

    // Get the current line mode
    virtual vm_text_frame_line_mode_enum getLineMode() = 0;

    // Whether the auto font resized is enabled
    virtual VMBOOL getAutoFontResized() = 0;

    // Set text of the frame.
    virtual void setString(const vm_wstring_struct &value) = 0;

    // Set font color.
    virtual void setColor(const VMCOLOR32 &value) = 0;

    // Set text align mode.
    virtual void setAlignMode(vm_text_frame_align_mode_enum value) = 0;

    // Set text truncate mode.
    virtual void setTruncateMode(vm_text_frame_truncate_mode_enum value) = 0;

    // Enable auto resizing when text is changed.
    virtual void setAutoResized(VMBOOL value) = 0;

    // set margins to textframe
    virtual void setMargins(VMINT32 value) = 0;

    // set margins to textframe
    virtual void setMargins(VMINT32 leftMargin, VMINT32 topMargin, VMINT32 rightMargin, VMINT32 bottomMargin) = 0;

    // set singline or multiline mode
    virtual void setLineMode(vm_text_frame_line_mode_enum value) = 0;

    // set whether auto resize the font size
    virtual void setAutoFontSize(VMBOOL value) = 0;

    // set the indent for the first character
    virtual void setIndent(VMINT32 value) = 0;

    // set the max line count as the limitation of auto-resized multiline frame
    virtual void setMaxLines(VMINT32 value) = 0;

    // set the line gap in multiline mode
    virtual void setLineGap(VMINT32 value) = 0;

    // set the min line height in multiline mode
    virtual void setMinLineHeight(VMINT32 value) = 0;

    // Set the font of text    
    virtual void setFont(const vm_font_desc_struct &fontDesc) = 0;

    // Set Singline line height as fully-character height
    virtual void setFullLineHeightMode(const VMBOOL value) = 0;

    // Return the font of text
    //
    // RETURNS: The font of text
    virtual void getFont(vm_font_desc_struct *fontDesc) = 0;

    // Measure the size of text
    // 
    // RETURNS: The size of text
    virtual void getMeasureBounds(vm_rect_struct *bounds) = 0;

    // Get the line count of text
    // RETURNS: the line count of text
    virtual VMINT32 getLineCount() = 0;

    // Align the text to the center of vertical
    virtual void setVerticalToCenter(VMBOOL value) = 0;

    // Dec width to match the all lines width, only available for multiline with auto resized mode
    virtual void setBestFitWidth(VMBOOL value) = 0;

    // This function will post emit the forceUpdate function.
    // And this function will only invoke once forceUpdate function even you call it many times.
    virtual void checkUpdate() = 0;

    // force update all layout immediatelly
    virtual void forceUpdate() = 0;
};

#endif /* __VPI_TEXT_FRAME_INTERFACE_H__ */

