/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

#ifndef	_VM_PRO_MNG_SDK_
#define _VM_PRO_MNG_SDK_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

typedef VMINT VM_P_HANDLE;

//process procedure related interfaces

#define	VM_PMNG_OP_OK					        (0)
#define VM_PMNG_PROCESS_NO_EXISTS		        (-1)
#define	VM_PMNG_NO_OP_IN_STATUS			        (-2)
#define VM_PMNG_ERROR_PARAM				        (-3)
#define VM_PMNG_NO_MEM					        (-4)
#define VM_PMNG_ERROR_IO					    (-5)
#define	VM_PMNG_NO_SCHEDULE				        (-6)
#define	VM_PMNG_EXIT						    (-7)
#define	VM_PMNG_CERT_FAIL                       (-8)
#define	VM_PMNG_ERROR_FUNLST                    (-9)

#define VM_PMNG_SEC_TAG_PLATFORM_PARAM_DISMATCH (-10)
#define	VM_PMNG_SEC_APP_TIMESTAMP_ERROR	        (-11)
#define	VM_PMNG_SEC_IMSI_DISMATCH				(-12)
#define	VM_PMNG_SEC_BAN_LIST_APP				(-13)
#define VM_PMNG_SEC_INVALIDATE_APP				(-14)
#define VM_PMNG_SEC_CERT_OMREDUE				(-15)
#define VM_PMNG_SEC_CERT_SMALL_SYS_MEM		    (-16)

#define VM_PMNG_WAIT_ASM                        (-17)
#define VM_PMNG_NOT_SUPPORT_VP                  (-18)
#define VM_PMNG_ONLY_ONE_FOREGROUND             (-19)
#define VM_PMNG_MAX_APP_NUM_REACHED             (-20)

#define	VM_PMNG_CUR_HANDLE				(0x0f)

#define VM_PMNG_KERNEL_HANDLE			(0)

#define VM_MAX_PATH                     261

typedef enum 
{
    VM_PMNG_UNLOAD = 0,			/* state that loaded to memory but not started */
    VM_PMNG_FOREGROUND, 		/*  state of foreground running */
    VM_PMNG_BACKGROUND,			/*state of background running */ 
    VM_PMNG_STARTING,
    VM_PMNG_CLOSING,
    VM_PMNG_INACTIVE,
    VM_PMNG_MAX_NUM
}VM_PROCESS_STATUS;

typedef enum
{
    VM_QUIT_NORMAL,
    VM_QUIT_MASS_STORAGE,
    VM_QUIT_CARD_PLUG_OUT    
}VM_QUIT_TYPE;

typedef struct
{
    VM_P_HANDLE         pHandle;
    VMINT               appID;
    VM_PROCESS_STATUS   status;
    VM_P_HANDLE         pParentHandle;
    VMINT               type;
    VMINT               reserved[5];
    VMWCHAR             filePath[VM_MAX_PATH];
}vm_process_property;

typedef struct {
	VMINT (*sys_event_filter)(VMINT message, VMINT param);
	VMINT (*pen_event_filter)(VMINT pen_event, VMINT x, VMINT y);
	VMINT (*key_event_filter)(VMINT key_event, VMINT key_code);
} _event_filter_t;
/*****************************************************************************
* FUNCTION
 *    vm_pmng_set_bg
 * DESCRIPTION
 *  set the caller process to background state. This function can be invoked only during foreground
 *  state, and all the UI resource should be release before call this function.
 * RETURNS
 *  result of setting background state
 * RETURN VALUES                                      
 *  VM_PMNG_OP_OK : set successfully.
 *  VM_PMNG_NO_OP_IN_STATUS : the caller process is not during foreground state.
 *  
*****************************************************************************/
VMINT vm_pmng_set_bg(void);

/*****************************************************************************
* FUNCTION
 *    vm_pmng_state
 * DESCRIPTION
 *  get the state of specified process ID.
 * PARAMETERS
 *  p_handle : [IN]  process handle to be checked. If want to get current process state,
 *  it should be VM_PMNG_CUR_HANDLE.
 * RETURNS
 *  the state of specified process.
* RETURN VALUES                                      
 *  VM_PMNG_FOREGROUND : foreground state
 *  VM_PMNG_BACKGROUND : background state
 *  VM_PMNG_PAUSED : inactive state
 *  VM_PMNG_UNLOAD : unloaded state
 *  
*****************************************************************************/
VM_PROCESS_STATUS vm_pmng_state(VM_P_HANDLE p_handle);

/*****************************************************************************
* FUNCTION
 *    vm_pmng_get_current_handle
 * DESCRIPTION
 *  get process handle of current process.
 * RETURNS
 *  the process ID of current running if larger than zero, 0 means no process running 
 *  
*****************************************************************************/
VM_P_HANDLE vm_pmng_get_current_handle(void);


/****************************************************************************
 * for application communication begin
 ****************************************************************************/

/* MRE application messge id base, application should define its own message id started from this. */
#define VM_MESSAGE_ID_BASE  1000

typedef VMINT (*VM_MESSAGE_PROC) (VM_P_HANDLE sender, VMUINT msg_id, VMINT wparam, VMINT lparam);
/*****************************************************************************
* FUNCTION
 *    vm_pmng_get_handle
 * DESCRIPTION
 *  get process handle of specified file name.
 * PARAMETERS
 *  file_name : [IN]  file name to be checked. 
 * RETURNS
 *  the process ID of specified file if larger than zero, 0 means there is no specified file running 
 *  
*****************************************************************************/
VM_P_HANDLE vm_pmng_get_handle(VMWSTR file_name);

/*****************************************************************************
* FUNCTION
 *    vm_reg_msg_proc
 * DESCRIPTION
 *  register user defined message callback function.
 * PARAMETERS
 *  proc : [IN] callback function.
*****************************************************************************/
void vm_reg_msg_proc(VM_MESSAGE_PROC proc);

/*****************************************************************************
* FUNCTION
 *    vm_send_msg
 * DESCRIPTION
 *  send message to MRE app or native app, will invoke message procedure directly.
 * PARAMETERS
 *  phandle : [IN] receiver process handle, if receiver is native application, this value should be zero.
 *  msg_id : [IN] user defined message ID, should larger than VM_MESSAGE_ID_BASE.
 *  wparam : [IN] wparam of message.
 *  lparam : [IN] lparam of message.
 * RETURNS
 *  message procedure return value.
*****************************************************************************/
VMINT vm_send_msg(VM_P_HANDLE phandle, VMUINT msg_id, VMINT wparam, VMINT lparam);


/*****************************************************************************
* FUNCTION
 *    vm_post_msg
 * DESCRIPTION
 *  post message to MRE app or native app, will put this message to the end of MRE message queue. 
 *  when this function call finish, MMI task will dispatch MRE message and invoke message procedure. 
 * PARAMETERS
 *  phandle : [IN] receiver process handle, if receiver is native application, this value should be zero.
 *  msg_id : [IN] user defined message ID, should larger than VM_MESSAGE_ID_BASE.
 *  wparam : [IN] wparam of message.
 *  lparam : [IN] lparam of message.
 * RETURNS
 *  1 means add message into message queue successfully, 0 means message queue is full.
*****************************************************************************/
VMINT vm_post_msg(VM_P_HANDLE phandle, VMUINT msg_id, VMINT wparam, VMINT lparam);

/****************************************************************************
 * for application communication end
 ****************************************************************************/
VMINT vm_pmng_get_app_handle(void);

/**
 * notification mode of background running application applying to foreground running.
 */
typedef enum 
{
	VM_NOTIFY_TYPE_DEFAULT = 0,            /* by default mode (follow engine control) */
	VM_NOTIFY_TYPE_SOUND = 1,		/* by sound mode */
	VM_NOTIFY_TYPE_VIBRATILITY = 2	/* by vibration mode */
} VM_FG_NOTIFY_TYPE;

/*****************************************************************************
* FUNCTION
 *  vm_start_app
 * DESCRIPTION
 *  Run another APP
 * PARAMETERS 
 *  filepath :          [IN]  The file path need to startup.
 *  parent_app_handle : [IN]  Parent APP handle, usually should be current APP.
 *  is_parent_exit :    [IN]  Is need exit Parent APP before enter new one.
 * RETURNS
 *  void
 *  
*****************************************************************************/
void vm_start_app(const VMWCHAR* filepath, VMINT parent_app_handle, VMINT is_parent_exit);

/*****************************************************************************
* FUNCTION
 *  vm_start_app_with_para
 * DESCRIPTION
 *  Run another APP
 * PARAMETERS 
 *  filepath :          [IN]  The file path need to startup.
 *  parent_app_handle : [IN]  Parent APP handle, usually should be current APP.
 *  is_parent_exit :    [IN]  Is need exit Parent APP before enter new one.
 *  parameter : [IN] parmeter.
 *  parameter_size : [IN] parameter size
 * RETURNS
 *  void
 *  
*****************************************************************************/
void vm_start_app_with_para(const VMWCHAR* filepath, VMINT parent_app_handle, VMINT is_parent_exit,void* parameter,VMINT parameter_size);


/*****************************************************************************
* FUNCTION
 *    vm_pmng_get_process_list
 * DESCRIPTION
 *  get process list. set handle_list NULL to get process number.
 * PARAMETERS
 *  handle_list : [IN] process handle list
 *  num : [IN/OUT] process number.
 * RETURNS
 *  >0 means process number, <0 means fail
*****************************************************************************/
VMINT vm_pmng_get_process_list(VM_P_HANDLE *handle_list, VMUINT *num);

/*****************************************************************************
* FUNCTION
 *    vm_pmng_get_process_property
 * DESCRIPTION
 *  get process property
 * PARAMETERS
 *  handle : [IN] process handle
 *  property : [OUT] process property
 * RETURNS
 *  0 means success, < 0 means fail
*****************************************************************************/
VMINT vm_pmng_get_process_property(VM_P_HANDLE handle, vm_process_property *property);

/*****************************************************************************
 * FUNCTION
 *  vm_pmng_set_fg
 * DESCRIPTION
 *  bring an application from bg to fg
 * PARAMETERS
 *  fileName        [IN]         Application file name encoding with USC2 format.
 * RETURNS
 *  sucess app handle, <0 means fail
 *****************************************************************************/
VM_P_HANDLE vm_pmng_set_fg(VMWSTR fileName);

#ifdef __cplusplus
}
#endif 
#endif /* _VM_PRO_MNG_SDK_ */
