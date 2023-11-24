/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vpi_widget_interface.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the interface of the VPI widget.
 *
 * Author:
 * -------
 *  Cheng-Hung Ko (mtk01585)
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
 * 06 15 2012 jun.liu
 * [MAUI_03053506] Plug-in check in
 * .
 *
 * 06 12 2012 cathytr.huang
 * [MAUI_03183719] [DLUI] Revise code
 * .
 *
 * 06 07 2012 cathytr.huang
 * [MAUI_03197092] [UE] too much gap between shortcuts
 * .
 *
 * 05 16 2012 cathytr.huang
 * [MAUI_03186526] [DLUI] Widget new service API
 * .
 *
 * 04 18 2012 ch.ko
 * [MAUI_03163831] [DLUI] Check-in patch
 * Support new API.
 *
 * 04 06 2012 ch.ko
 * [MAUI_03163831] [DLUI] Check-in patch
 * Don't close MRE widget when launcher is inactive.
 *
 * 03 12 2012 ch.ko
 * [MAUI_03147028] [DLUI] Check-in new features
 * Check-in MRE launcher and widget.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VPI_WIDGET_INTERFACE_H
#define VPI_WIDGET_INTERFACE_H

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vmsys.h"
#include "vmpromng.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vpi_interface_id.h"
#include "vpi_object_interface.h"
#include "vpi_widget_primitive_interface.h"


/*****************************************************************************
 * Widget Interface
 *****************************************************************************/
class IVpiWidget : public IVpiBase
{
// Method
public:
    // Get the widget ID.
    virtual void getId(
        IVpiWidgetId **id       // [OUT] Widget Id
    ) = 0;

    // This function creates the widget's view.
    //
    // SEE ALSO: releaseView
    virtual void createView() = 0;

    // This function releases the widget's view.
    //
    // SEE ALSO: createView
    virtual void releaseView() = 0;

    // Serialize the widget view.
    //
    // NOTE: Internal used only.
    virtual void serializeView() = 0;

    // Restore the widget view.
    //
    // NOTE: Internal used only.
    virtual void restoreView() = 0;

    // This function displays or hides the delete button. The delete button is
    // hidden by default.
    virtual void setDeleteButtonHidden(
        VMBOOL isHidden             // [IN] Hide the button or not
    ) = 0;

    // This function is generally called after the createView function to check if the view
    // is created successfully. If it is failed, the 'errorString' is used to
    // prompt the user about the error message. If it is successful,
    // 'errorString' is undefined.
    // RETURNS: If failure exists, return VFX_TRUE; otherwise, return VFX_FALSE.
    //
    // SEE ALSO: createView
    virtual VMBOOL getCreateViewFailure(
        VMWSTR errorString     // [OUT] Prompt message for the user
    ) = 0;    

    // Get max. size of the widget.
    // RETURNS: size
    virtual void getMaxSize(
            vm_size_struct *size
    ) = 0;
};


VPI_CMD_ID_DECLARE_BEGIN(WIDGET)

    CMD_ID_WIDGET_DRAG,
    CMD_ID_WIDGET_MOVE,
    CMD_ID_WIDGET_DROP,
    CMD_ID_WIDGET_ABORT,
    CMD_ID_WIDGET_DELETE,

/* NOTE. The new IDs must be added at the end */
VPI_CMD_ID_DECLARE_END(WIDGET)



#endif /* VPI_WIDGET_INTERFACE_H */

