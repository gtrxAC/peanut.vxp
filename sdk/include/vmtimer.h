/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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

#ifndef VMTIMER_SDK_H_
#define VMTIMER_SDK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

typedef enum
{
	
	VM_TIMER_MTK_TIMER_NO_FREE = -5,
	VM_TIMER_ERROR_OF_PROCESS,
	VM_TIMER_ERROR_OF_RES ,
	VM_TIMER_ERROR_OF_MEM ,
	VM_TIMER_ERROR ,
	VM_TIMER_OK
} vm_timer_error_t;

/*callback function VM_TIMERPROC_T */
typedef void (*VM_TIMERPROC_T)(VMINT tid);

/*****************************************************************************
 * FUNCTION
 *  vm_create_timer
 * DESCRIPTION
 *  create timer. 
 *  Once the timer is created, it will be looply called till user delete it. It is a non-aligned timer, so it is a precise timer and will be stopped
 *  when the LCD backlight is off. For one application , the max number of this kind of timer is 10 
 * PARAMETERS
 *  millisec : [IN] the length if the interval. The unit of interval is millisecond
 *  timerproc : [IN] the callback function when the timer is over time
 * RETURNS
 *  The timer handle,the handle >0 when succeed,otherwise, handle <0
 *****************************************************************************/
VMINT vm_create_timer(VMUINT32 millisec, VM_TIMERPROC_T timerproc);


/*****************************************************************************
 * FUNCTION
 *  vm_delete_timer
 * DESCRIPTION
 *  delete the timer created by vm_create_timer
 * PARAMETERS
 *  timerid  : [IN] the timer handler
 * RETURNS
 *   succeed when return 0,otherwise, fail
 *****************************************************************************/
VMINT vm_delete_timer(VMINT timerid);



/*****************************************************************************
 * FUNCTION
 *  vm_create_timer_ex
 * DESCRIPTION
 *  create timer. 
 *  Once the timer is created, it will be looply called till user delete it. It is an aligned timer, so it is not a precise timer. but it will still work
 *  when the LCD backlight is off. For one application , the max number of this kind of timer is 10 
 * PARAMETERS
 *  millisec : [IN] the length if the interval. The unit of interval is millisecond
 *  timerproc : [IN] the callback function when the timer is over time
 * RETURNS
 *  The timer handle,the handle >0 when succeed,otherwise, handle <0
 *****************************************************************************/
VMINT vm_create_timer_ex(VMUINT32 millisec, VM_TIMERPROC_T timerproc);


/*****************************************************************************
 * FUNCTION
 *  vm_delete_timer_ex
 * DESCRIPTION
 *  delete the timer created by vm_create_timer_ex
 * PARAMETERS
 *  timerid : [IN]  the timer handler
 * RETURNS
 *   succeed when return 0,otherwise, fail
 *****************************************************************************/
VMINT vm_delete_timer_ex(VMINT timerid);


#ifdef __cplusplus
}
#endif

#endif
