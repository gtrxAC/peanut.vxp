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
 *  vpi_widget_primitive_interface.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the interface of the VPI widget primitive.
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
 * 06 18 2012 wei.fu
 * [MAUI_03180984] DLUI check-in
 * Revise datatype.
 *
 * 06 14 2012 jun.liu
 * [MAUI_03053506] Plug-in check in
 * .
 *
 * 05 16 2012 cathytr.huang
 * [MAUI_03186526] [DLUI] Widget new service API
 * .
 *
 * 03 12 2012 ch.ko
 * [MAUI_03147028] [DLUI] Check-in new features
 * Check-in MRE launcher and widget.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VPI_WIDGET_PRIMITIVE_INTERFACE_H
#define VPI_WIDGET_PRIMITIVE_INTERFACE_H

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vmsys.h"
#include "vmpromng.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vpi_interface_id.h"
#include "vpi_object_interface.h"
#include "vpi_archive_interface.h"


/*****************************************************************************
 * Enum
 *****************************************************************************/

// Define the source of the widget.
enum VMWidgetSrcEnum
{
    // Unknown.
    VM_WIDGET_SRC_UNKNOWN,

    // Application shortcuts.
    VM_WIDGET_SRC_APP_SHORTCUT,

    // System default widget.
    VM_WIDGET_SRC_SYSTEM_DEFAULT,

    // Downloaded widgets.
    VM_WIDGET_SRC_DOWNLOAD,

    // Proprietary widgets. (NOT AVAILABLE)
    VM_WIDGET_SRC_PROPRIETARY,

    VM_END_OF_ENUM(VMWidgetSrcEnum)
};


/*****************************************************************************
 * Widget ID Interface
 *****************************************************************************/
class IVpiWidgetId : public IVpiBase
{
// Method
public:
    // This function gets the kind of the widget associated with this ID.
    virtual VMWidgetSrcEnum getSource() = 0;

    // This function assigns the widget ID from other widget ID.
    virtual void assignWith(
        const IVpiWidgetId *other   // [IN] Other widget ID
    ) = 0;

    // This function compares the widget ID with other widget ID.
    // RETURNS: On the same, return VM_TRUE; otherwise, return VM_FALSE.
    virtual VMBOOL compareWith(
        const IVpiWidgetId *other   // [IN] Other widget ID
    )  = 0;

    // This function decodes the widget ID from the archive.
    virtual void decodeFromArchive(
        IVpiArchive *ar             // [IN] Archive
    ) = 0;

    // This function encodes the widget ID to the archive.
    virtual void encodeToArchive(
        IVpiArchive *ar             // [IN] Archive
    ) = 0;

    // This function decodes the widget ID from the memory buffer.
    // RETURNS: the number of decoded bytes.
    virtual VMINT32 decodeFromMem(
        VMUINT8 *buf,               // [IN] Memory buffer
        VMUINT32 size               // [IN] Size of the buffer
    ) = 0;

    // This function encodes the widget ID to the memory buffer.
    // RETURNS: the number of encoded bytes.
    virtual VMINT32 encodeToMem(
        VMUINT8 *buf,               // [IN] Memory buffer
        VMUINT32 size               // [IN] Size of the buffer
    ) = 0;
};

#endif /* VPI_WIDGET_PRIMITIVE_INTERFACE_H */

