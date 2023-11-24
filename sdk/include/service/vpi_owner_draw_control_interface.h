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
 *  vpi_owner_draw_control_interface.h
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
#ifndef __VPI_OWNER_DRAW_CONTROL_INTERFACE_H__
#define __VPI_OWNER_DRAW_CONTROL_INTERFACE_H__

#include "vmsys.h"
#include "vpi_interface_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"
#include "vpi_object_interface.h"
#include "vpi_frame_interface.h"
#include "vpi_archive_interface.h"
#include "vmio.h"

/*
 * class IVpiOwnerDrawControlDelegator
 */
class IVpiOwnerDrawControlDelegator : public IVpiBase
{
public:

    virtual void onDrawFrameBuffer(vm_image_buffer_struct &buffer, const vm_point_struct &frameOrigin, const vm_rect_struct &dirtyRect) = 0;

	virtual vm_render_owner_draw_dirty_type_enum onExecuteAnimation(VMMSEC currFrameTime, vm_rect_struct &dirtyRect) = 0;

    virtual void onCommit() = 0;
};


/*
 * class IVpiOwnerDrawControl
 */
class IVpiOwnerDrawControl : public IVpiBase
{
public:

    virtual void setFrameBuffer(vm_image_buffer_struct &buffer) = 0;

	virtual void getFrameBuffer(vm_image_buffer_struct *buffer) = 0;

	virtual void invalidateFrameBuffer(vm_rect_struct &rect) = 0;

	virtual void setFrameAttributes(VMUINT32 width, VMUINT32 height, vm_color_type_enum cf) = 0;

	virtual void beginUpdateRenderProperties() = 0;

	virtual void endUpdateRenderProperties() = 0;

    virtual VMUINT8 *beginHWRendering() = 0;

    virtual VMUINT8 *endHWRendering() = 0;
};


VPI_EVENT_ID_DECLARE_BEGIN(OWNER_DRAW_CONTROL)

    EVT_ID_OWNER_DRAW_CONTROL_SET_NEED_HW_RENDERING_BUFFER,

    EVT_ID_OWNER_DRAW_CONTROL_GET_NEED_HW_RENDERING_BUFFER,

VPI_EVENT_ID_DECLARE_END(OWNER_DRAW_CONTROL)

#endif /* __VPI_OWNER_DRAW_CONTROL_INTERFACE_H__ */

