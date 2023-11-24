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
 *  vpi_widget_kit_interface.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the interface of the widget kit.
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
 * 03 12 2012 ch.ko
 * [MAUI_03147028] [DLUI] Check-in new features
 * Check-in MRE launcher and widget.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VPI_WIDGET_KIT_INTERFACE_H
#define VPI_WIDGET_KIT_INTERFACE_H

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
#include "vpi_widget_interface.h"


/*****************************************************************************
 * Widget Kit Interface
 *****************************************************************************/
class IVpiWidgetKit : public IVpiBase
{
public:
    // This function gets the total number of the widgets.
    // RETURNS: Total number.
    virtual VMUINT32 getTotalNum() = 0;

    // This function gets the ID of all the widgets.
    // RETURNS: Total number.
    virtual VMUINT32 getAllId(
        IVpiWidgetId **id,              // [OUT] Widget ID array
        VMUINT32 size,                  // [IN]  Size of the array
        IVpiObject *parentObj           // [IN]  Parent of the ID object
    ) = 0;

    // This function checks if the ID is valid to create a widget.
    // RETURNS: valid or not.
    virtual VMBOOL isIdValid(
        const IVpiWidgetId *id          // [IN] Widget ID
    ) = 0;

    // This function gets the name of the widgets.
    // RETURNS: length of the widget name
    virtual VMUINT32 getName(
        const IVpiWidgetId *id,     // [IN]  Widget ID
        VMWCHAR *string,            // [OUT] String buffer
        VMUINT32 size               // [IN]  Buffer size in wchar
    ) = 0;

    // This function creates the widget icon.
    // RETURNS: the widget icon.
    virtual void createIcon(
        IVpiFrame **icon,           // [OUT] Widget icon
        const IVpiWidgetId *id,     // [IN]  Widget ID
        IVpiObject *parentObj       // [IN]  Parent object of the widget
    ) = 0;

    // This function creates the widgets.
    // RETURNS: the created widget.
    virtual void createWidget(
        IVpiWidget **widget,        // [OUT] Widget
        const IVpiWidgetId *id,     // [IN]  Widget ID
        IVpiObject *parentObj       // [IN]  Parent object of the widget
    ) = 0;
};

#endif /* VPI_WIDGET_KIT_INTERFACE_H */

