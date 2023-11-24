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
 *  vpi_indicator_popup_interface.h
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
#ifndef __VPI_INDICATOR_POPUP_INTERFACE_H__
#define __VPI_INDICATOR_POPUP_INTERFACE_H__

#include "vmsys.h"
#include "vpi_interface_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"
#include "vpi_base_popup_interface.h"
#include "vpi_popup_data_type.h"

enum VMIndicatorPopupStyleEnum
{
     VM_INDICATOR_POPUP_STYLE_NONE,
     VM_INDICATOR_POPUP_STYLE_TEXT,                            // Popup with text only
     VM_INDICATOR_POPUP_STYLE_TEXT_WITH_CANCEL_BUTTON,         // Popup with text with Cancel Button
     VM_INDICATOR_POPUP_STYLE_ACTIVITY,                        // Popup with activity indicator
     VM_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON,     // Popup with activity indicator with Cancel button
     VM_INDICATOR_POPUP_STYLE_PROGRESS,                        // Popup with progress indicator
     VM_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON,     // Popup with progress indicator with Cancel button
     VM_INDICATOR_POPUP_STYLE_TOTAL,

     VM_END_OF_ENUM(VMIndicatorPopupStyleEnum)
};


/*
 * class IVpiIndicatorPopup
 */
class IVpiIndicatorPopup : public IVpiBase
{
public:
    // <group DOM_IndicatorPopup_IVpiIndicatorPopup_Method>
    // Sets popup text.
    virtual void setText(const vm_wstring_struct &text) = 0;

    // <group DOM_IndicatorPopup_IVpiIndicatorPopup_Method>
    // Sets the Popup type.
    virtual void setInfoType(VMIndicatorPopupStyleEnum type) = 0;

    // <group DOM_IndicatorPopup_IVpiIndicatorPopup_Method>
    // Gets popup text.
    // RETURNS :
    // Popup text string.
    virtual void getText(vm_wstring_struct *wstring) = 0;

    // <group DOM_IndicatorPopup_IVpiIndicatorPopup_Method>
    // Get Popup type enum value.
    // RETURNS :
    // Info type enum value.
    virtual VMIndicatorPopupStyleEnum getInfoType() = 0;

    // <group DOM_IndicatorPopup_IVpiIndicatorPopup_Method>
    // Sets progress value for progress Indicator.
    // RETURNS :
    // VFX_TRUE, if supplied value is set as current value successfully.
    virtual VMBOOL setProgress(VMFLOAT progress_value) = 0;

    // <group DOM_IndicatorPopup_IVpiIndicatorPopup_Method>
    // Gets progress indicator's value.
    // RETURNS :
    // Current progress value.
    virtual VMFLOAT getProgress(void) = 0;

    // <group DOM_IndicatorPopup_IVpiIndicatorPopup_Method>
    // Sets Maximum Indicator progress value.
    // RETURNS :
    // VFX_TRUE, if supplied value is set as max value successfully.
    virtual VMBOOL setMaxProgress(VMFLOAT progress_value) = 0;

    // <group DOM_IndicatorPopup_IVpiIndicatorPopup_Method>
    // Gets Max Indicator Progress value.
    // RETURNS :
    // Max progress value.
    virtual VMFLOAT getMaxProgress(void) = 0;

    // <group DOM_IndicatorPopup_IVpiIndicatorPopup_Method>
    // Progress bar animation toggle.
    virtual void setIsAnimate(VMBOOL isAnim) = 0;

    // <group DOM_IndicatorPopup_IVpiIndicatorPopup_Method>
    // Returns the Progress bar animation state.
    // RETURNS :
    // Animation flag.
    virtual VMBOOL getIsAnimate() = 0;

    // <group DOM_IndicatorPopup_IVpiIndicatorPopup_Method>
    // Stops Progress bar internal frame animation.
    virtual void pauseProgress() = 0;

    // <group DOM_IndicatorPopup_IVpiIndicatorPopup_Method>
    // Starts Progress bar internal frame animation.
    virtual void resumeProgress() = 0;
};


VPI_CMD_ID_DECLARE_BEGIN(INDICATOR_POPUP)

    CMD_ID_INDICATOR_POPUP_BUTTON_CLICKED,
    CMD_ID_INDICATOR_POPUP_CANCELED,

/* NOTE. The new IDs must be added at the end */
VPI_CMD_ID_DECLARE_END(INDICATOR_POPUP)


#endif /* __VPI_INDICATOR_POPUP_INTERFACE_H__ */

