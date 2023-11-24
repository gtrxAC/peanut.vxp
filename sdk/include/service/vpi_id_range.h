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
 *  vpi_event_range.h
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
 
#ifndef __VPI_ID_RANGE_H__
#define __VPI_ID_RANGE_H__

/* DOM-NOT_FOR_SDK-BEGIN */

/*
 * Use these tow macro to get the event base and event end
 */
#define VPI_GET_ID_BASE(id)   VPI_ID_BASE_##id
#define VPI_GET_ID_MAX(id)    VPI_ID_BASE_##id##_END


#define VPI_ID_BASE_RANGE(module_id, count)    \
    module_id,                                   \
    VPI_GET_ID_BASE(module_id) = module_id,        \
    VPI_GET_ID_MAX(module_id) = module_id + count


#define VPI_ID_BASE_ENUM_BEGIN()      \
    typedef enum                                    \
    {                                               \
        VPI_ID_BASE_FIRST_VALUE = 1,           


#define VPI_ID_BASE_ENUM_END()                    \
        VPI_ID_BASE_RANGE(VPI_ID_END, 1)                 \
    } VPI_ID_BASE_ENUM;

/*
 *  Use these two macros to declare event IDs of each module
 */
#define VPI_EVENT_ID_DECLARE_BEGIN(module_id)    \
    typedef enum                                 \
    {                                            \
        VPI_EVENT_ID_##module_id##_BASE = VPI_GET_ID_BASE(module_id),    


#define VPI_EVENT_ID_DECLARE_END(module_id)                    \
        VPI_EVENT_ID_##module_id##_MAX = VPI_GET_ID_MAX(module_id) \
    } VPI_EVENT_ID_##module_id##_ENUM;


/*
 *  Use these two macros to declare cmd IDs of each module
 */
#define VPI_CMD_ID_DECLARE_BEGIN(module_id)    \
    typedef enum                                 \
    {                                            \
        VPI_CMD_ID_##module_id##_BASE = VPI_GET_ID_BASE(module_id),    


#define VPI_CMD_ID_DECLARE_END(module_id)                    \
        VPI_CMD_ID_##module_id##_MAX = VPI_GET_ID_MAX(module_id) \
    } VPI_CMD_ID_##module_id##_ENUM;


/* 
 * Declare the range of ID ID of each module.
 *      VPI_ID_BASE_RANGE(<module id>, <event range>)
 *
 * For example:
 *      For modules:
 *          VPI_ID_BASE_RANGE(MODULE_XXX1,   100),
 *          VPI_ID_BASE_RANGE(MODULE_XXX2,    50),
 */

VPI_ID_BASE_ENUM_BEGIN()

    VPI_ID_BASE_RANGE(FRAME, 300),

    VPI_ID_BASE_RANGE(TIMELINE, 100),

    VPI_ID_BASE_RANGE(TIMER, 100),

    VPI_ID_BASE_RANGE(BASE_POPUP, 100),

    VPI_ID_BASE_RANGE(TOP_LEVEL, 100),

    VPI_ID_BASE_RANGE(PAGE_TRANSITION, 100),

    VPI_ID_BASE_RANGE(SCROLLABLE, 100),

    VPI_ID_BASE_RANGE(TEXT_VIEW, 100),

    VPI_ID_BASE_RANGE(TEXT_EDITOR, 100),

    VPI_ID_BASE_RANGE(SETTINGS_PAGE, 100),

    VPI_ID_BASE_RANGE(WIDGET, 100),

    VPI_ID_BASE_RANGE(INDICATOR_POPUP, 100),

    VPI_ID_BASE_RANGE(ANIM_IMAGE_FRAME, 100),

    VPI_ID_BASE_RANGE(CONFIRM_POPUP, 100),

    VPI_ID_BASE_RANGE(LAUNCHER, 100),

    VPI_ID_BASE_RANGE(BASE_MENU, 100),

    VPI_ID_BASE_RANGE(RENDERER, 500),

    VPI_ID_BASE_RANGE(OWNER_DRAW, 100),

    VPI_ID_BASE_RANGE(OWNER_DRAW_CONTROL, 100),

VPI_ID_BASE_ENUM_END()

/* DOM-NOT_FOR_SDK-END */

#endif /* __VPI_ID_RANGE_H__ */

