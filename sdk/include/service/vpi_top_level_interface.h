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
 *  vpi_object_interface.h
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
#ifndef __VPI_TOP_LEVEL_INTERFACE_H__
#define __VPI_TOP_LEVEL_INTERFACE_H__

#include "vpi_frame_interface.h"
#include "vpi_screen_interface.h"

/* DOM-NOT_FOR_SDK-BEGIN */

/*
 * Internal used interface.
 */
class IVpiTopLevel : public IVpiBase
{
public:

    virtual void getActiveScr(IVpiScreen **screen) = 0;

    virtual void setScreenRotateType(vm_scr_rotate_type_enum newRotateType, VMBOOL noAnimation = VM_FALSE) = 0;

    virtual vm_scr_rotate_type_enum getScreenRotateType() = 0;

    virtual void captureFocus(IVpiFrame* childFrame) = 0;

    virtual void releaseFocus(IVpiFrame* childFrame) = 0;
};

/* DOM-NOT_FOR_SDK-END */

VPI_CMD_ID_DECLARE_BEGIN(TOP_LEVEL)

    CMD_ID_TOP_LEVEL_BEFORE_ROTATE,
    CMD_ID_TOP_LEVEL_ROTATED,
    CMD_ID_TOP_LEVEL_ACTIVE_SCREEN_BEFORE_ENTER,
    CMD_ID_TOP_LEVEL_ACTIVE_SCREEN_ENTER,
    CMD_ID_TOP_LEVEL_ACTIVE_SCREEN_EXIT,
    CMD_ID_TOP_LEVEL_POPUP_ENTER,
    CMD_ID_TOP_LEVEL_POPUP_EXIT,

/* NOTE. The new IDs must be added at the end */
VPI_CMD_ID_DECLARE_END(TOP_LEVEL)


#endif /* __VPI_TOP_LEVEL_INTERFACE_H__ */

