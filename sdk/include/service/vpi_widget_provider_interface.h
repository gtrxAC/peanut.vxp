/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vpi_widget_provider_interface.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the interface of the VPI widget provider.
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
 * 06 14 2012 jun.liu
 * [MAUI_03053506] Plug-in check in
 * .
 *
 * 04 06 2012 ch.ko
 * [MAUI_03163831] [DLUI] Check-in patch
 * Don't close MRE widget when launcher is inactive.
 *
 * 03 21 2012 ch.ko
 * [MAUI_03147028] [DLUI] Check-in new features
 * Check-in hello world launcher..
 *
 * 03 12 2012 ch.ko
 * [MAUI_03147028] [DLUI] Check-in new features
 * Check-in MRE launcher and widget.
 *
 * 02 26 2012 ch.ko
 * [MAUI_03137280] [VPI] Check-in MRE widget framework
 * Check-in MRE widget framework.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VPI_WIDGET_PROVIDER_INTERFACE_H
#define VPI_WIDGET_PROVIDER_INTERFACE_H

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vmsys.h"
#include "vmpromng.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vpi_interface_id.h"
#include "vpi_object_interface.h"


/*****************************************************************************
 * Widget Proivder Delegator Interface
 *****************************************************************************/
class IVpiWidgetProviderDelegator : public IVpiBase
{
// Override
public:
    // Override this function to create the widget's view.
    //
    // SEE ALSO: onReleaseView
    virtual void onCreateView() = 0;

    // Override this function to release the widget's view. Note that all the
    // object created in onCreateView must be released in onReleaseView.
    //
    // SEE ALSO: onCreateView
    virtual void onReleaseView() = 0;

    // This function is called when the launcher is inactive. It provides the
    // widget a timing to serialize part of its resources when the launcher is
    // inactive.
    //
    // SEE ALSO: onRestoreView
    virtual void onSerializeView() = 0;

    // This function is called when the launcher is active. It provides the
    // widget a timing to restore its resources that it serialized in
    // onSerializeView before.
    //
    // SEE ALSO: onSerializeView
    virtual void onRestoreView() = 0;

    // This function is called to determine the delete button's position.
    //
    // SEE ALSO: setDeleteButtonHidden
    virtual void onGetDeleteButtonOffset(
        vm_point_struct *offset     // [OUT] Offset
    ) = 0;
};


/*****************************************************************************
 * Widget Provider Interface
 *****************************************************************************/
class IVpiWidgetProvider : public IVpiBase
{
// Method
public:
    // No public interface now.
};

#endif /* VPI_WIDGET_PROVIDER_INTERFACE_H */

