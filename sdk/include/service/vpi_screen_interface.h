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
 *  vpi_control_interface.h
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
#ifndef __VPI_SCREEN_INTERFACE_H__
#define __VPI_SCREEN_INTERFACE_H__

#include "vmsys.h"
#include "vpi_interface_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"
#include "vpi_object_interface.h"
#include "vpi_base_popup_interface.h"
#include "vmio.h"


/*
 * Interface of Venus screen.
 */
class IVpiScreen : public IVpiBase
{
public:
    // Return whether the screen is in snaptshot drawing mode, ex. small screen redraw
    virtual VMBOOL getIsSnapshotDrawing() = 0;

    // Return the current client area rectangle
    virtual void getClientRect(vm_rect_struct *rect) = 0;

    // Return the active popup of the screen
    virtual void getActivePopup(IVpiBasePopup **popup) = 0;

    // Destroy all popup below to this screen
    virtual void clearPopupStack() = 0;

    // check if any popup present
    virtual VMBOOL isPopupPresent() = 0;

    // Set transit type
    virtual void setTransitType(vm_scr_transit_type_enum type) = 0;

    // Query current transit type
    virtual vm_scr_transit_type_enum getTransitType() = 0;

    // Set the screen rotate type
    virtual void setScreenRotateType(vm_scr_rotate_type_enum newRotateType) = 0;

    // Get context of the screen
    virtual void getContext(IVpiObject **context) = 0;
};

#endif /* __VPI_SCREEN_INTERFACE_H__ */

