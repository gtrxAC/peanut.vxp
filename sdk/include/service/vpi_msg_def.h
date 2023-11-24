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
 *  vpi_msg_def.h
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
#ifndef __VPI_MSG_DEF_H__
#define __VPI_MSG_DEF_H__

#include "vmsys.h"
#include "vpi_object_factory_interface.h"
#include "vpi_object_interface.h"
#include "vpi_control_interface.h"

// DOM-NOT_FOR_SDK-BEGIN

typedef VMUINT32 (*_vm_vpi_msg_proc_ptr)(VMUINT32 msgID, VMUINT32 arg0, VMUINT32 arg1);


typedef enum
{
    VPI_MSG_LAUNCH, // arg0: the pointer to vpi_launch_data_struct, arg1: the size of vpi_launch_data_struct
    VPI_MSG_TERMINATE,
    VPI_MSG_GET_RESOURCE_START,
    VPI_MSG_GET_RESOURCE, // arg0: the pointer to vpi_get_resource_data_struct, arg1: the size of vpi_get_resource_data_struct
    VPI_MSG_GET_RESOURCE_END,
    VPI_MSG_CLOSE_OBJECT,

    VM_END_OF_ENUM(vpi_msg_id_enums)
} vpi_msg_id_enums;


typedef VMUINT32 (*vm_vpi_notification_callbak_ptr)(VMUINT32 notificationID, VMUINT32 arg0, VMUINT32 arg1, void *userData, VMUINT32 userDataSize);


typedef enum
{
    VPI_NOTIFICATION_QUIT_BY_INTERRUPT, // arg0: interrupt type (vpi_quit_by_interrupt_type_enums), arg1: not used
    VPI_NOTIFICATION_TAKE_MUTEX,
    VPI_NOTIFICATION_GIVE_MUTEX,

    VM_END_OF_ENUM(vpi_notification_id_enums)
} vpi_notification_id_enums;


typedef enum
{
    VPI_QUIT_TYPE_PLUG_IN_USB, 
    VPI_QUIT_TYPE_PLUG_OUT_T_CARD,
    VPI_QUIT_TYPE_UNKNOWN,

    VM_END_OF_ENUM(vpi_quit_by_interrupt_type_enums)
} vpi_quit_by_interrupt_type_enums;


typedef struct
{
    IVpiObjectFactory *objFactory;
    IVpiObject *context;
    IVpiControl *parentControl;
    vm_vpi_notification_callbak_ptr notificationCallbackPtr;
    void *notificationCallbackUserData;
    VMUINT32 notificationCallbackUserDataSize;
} vpi_launch_data_struct;


typedef struct
{
    VMRESID resId;
    const void *buf;
    VMBOOL isOwnerDraw;
} vpi_get_resource_data_struct;

// DOM-NOT_FOR_SDK-END

#endif /* __VPI_MSG_DEF_H__ */

