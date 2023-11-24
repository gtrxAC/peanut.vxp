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
 *  vpi_anim_image_frame_interface.h
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
#ifndef __VPI_ANIM_IMAGE_FRAME_INTERFACE_H__
#define __VPI_ANIM_IMAGE_FRAME_INTERFACE_H__

#include "vmsys.h"
#include "vpi_interface_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"
#include "vpi_object_interface.h"

/*
 * Interface of animation image frame.
 */
class IVpiAnimImageFrame : public IVpiBase
{
public:
	
    // Set animation repeat count, default value is VM_ANIM_IMAGE_FRAME_PLAY_COUNT_INFINIT
	virtual VMBOOL setRepeatCount(VMUINT32 repeatCount) = 0;

	// Get the animation repeat count
	virtual VMUINT32 getRepeatCount() = 0;

	// Set the animation end frame index, default is the last index
	virtual void setEndIndex(VMUINT32 endIndex) = 0;

	// Get the animation end frame index
	virtual VMUINT32 getEndIndex() = 0;

	// Start to play the animation
	virtual void play() = 0;

	// Stop the animation
	virtual void stop() = 0;

    // Suspend the animation at the specified index
	virtual void suspend(
	    VMUINT32 suspendAtIndex = VM_ANIM_IMAGE_FRAME_MAX_INDEX    // [IN] The inedx to suspend at
	) = 0;

    // Resume the suspended animation
	virtual void resume() = 0;

    // Helper interface, play and suspend the animation at the specific index
	virtual void playAndSuspend(
	    VMUINT32 suspendAtIndex = VM_ANIM_IMAGE_FRAME_MAX_INDEX    // [IN] The inedx to suspend at
	) = 0;
};

VPI_CMD_ID_DECLARE_BEGIN(ANIM_IMAGE_FRAME)

    CMD_ID_ANIM_IMAGE_FRAME_ANIM_END,

/* NOTE. The new IDs must be added at the end */
VPI_CMD_ID_DECLARE_END(ANIM_IMAGE_FRAME)


#endif /* __VPI_ANIM_IMAGE_FRAME_INTERFACE_H__ */

