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
 *  vpi_timer_interface.h
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
#ifndef __VPI_TIMER_INTERFACE_H__
#define __VPI_TIMER_INTERFACE_H__

#include "vmsys.h"
#include "vpi_interface_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"
#include "vpi_object_interface.h"


/*
 * Interface of timer.
 */
class IVpiTimer : public IVpiBase
{
public:
    // The first time emit signal after start the timer, in mili-second.
    //
    // NOTE: Default value is 0.
    virtual VMMSEC getStartDelay() = 0;

    // The interval time to emit signal, in mili-second. 
    //
    // NOTE: Default value is 0. 
    //  The value 0 means the timer will emit signal only one time.
    virtual VMMSEC getDuration() = 0;

    // SEE ALSO: VMTimer::getStartDelay.
    virtual void setStartDelay(VMMSEC value) = 0;

    // SEE ALSO: VMTimer::getDuration.
    virtual void setDuration(VMMSEC value) = 0;

    // Return if the timer is started.
    //
    // RETURNS: 
    //  Return VM_TURE if the timer is enabled, otherwise return VM_FALSE
    virtual VMBOOL getIsEnabled() = 0;

    // Start the timer.
    //
    // NOTE: If the timer started, it will stop and restart.
    virtual void start() = 0;

    // Stop the timer.
    // NOTE: If the timer does not started, it will do nothing.
    virtual void stop() = 0;
};

/* DOM-NOT_FOR_SDK-BEGIN */

/*
 * Internal used interface.
 */
class IVpiTimerStatic : public IVpiBase
{
public:
    virtual VMMSEC getCurrentTime() = 0;

    virtual VMMSEC getCurrentSystemTime() = 0;
};

/* DOM-NOT_FOR_SDK-END */

VPI_CMD_ID_DECLARE_BEGIN(TIMER)

    CMD_ID_TIMER_TICK,

/* NOTE. The new IDs must be added at the end */
VPI_CMD_ID_DECLARE_END(TIMER)



#endif /* __VPI_RENDERER_INTERFACE_H__ */

