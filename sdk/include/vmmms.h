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

#ifndef VMMMS_SDK_H
#define VMMMS_SDK_H 


#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

/**
 *maxium length of xml file path, including '\0'
 */
#define MAX_MMS_APP_NAME_LEN  100

/*Max length of address MMS adaptor supports*/
#define VM_MMS_MAX_ADDR_LEN 128
/*Max length of subbject MMS adaptor supports*/
#define VM_MMS_MAX_SUBJECT_LEN 41

typedef enum
{
    VM_MMS_CANCEL = -3,						 /*user cancelled sending*/
    VM_MMS_FAIL = -2,                        /*operation request error*/     
    VM_MMS_MEMORY_NOT_ENOUGH = -1,    		 /*not enough memory*/
    VM_MMS_SUCCESS							 /*operation successfully*/
 }vm_mms_result_enum;

typedef enum
{
	VM_MMS_TYPE_SMIL_MMS = 0,       			 /*SMIL type of XML */
	VM_MMS_TYPE_MIXED_MMS          				 /*MIXED type of XML */
}vm_mms_type_enum;

typedef enum
{
	VM_MMS_SIM_ID_SIM1 = 0x01,          			 	 /*sim1 card */
	VM_MMS_SIM_ID_SIM2 = 0x02,                				 /*sim2 card */
	VM_MMS_SIM_ID_SIM3 = 0x04,          			 	 /*sim3 card */
	VM_MMS_SIM_ID_SIM4 = 0x08,                				 /*sim4 card */
}vm_mms_sim_id_enum;

typedef struct
{
	VMUWCHAR xml_filepath[MAX_MMS_APP_NAME_LEN];/*XML file path*/
	VMUINT xml_size;							 /*XML file size*/
	VMUINT8 mms_type;                    		 /*refer to vm_mms_type_enum*/
	VMUINT8 sim_id;                        		 /*refer to vm_mms_sim_id_enum*/
}vm_send_mms_req_t;

typedef enum
{
    VM_MMS_ADDR_PHONE_NUM = 0,
    VM_MMS_ADDR_EMAIL,
    VM_MMS_ADDR_IP
}vm_mms_addr_type_enum;



typedef enum
{
    VM_EVT_ID_MMS_NEW_MSG,
    VM_EVT_ID_MMS_MAX_ENUM
}vm_mms_event_enum;


/* This enum is used to specify MMS contains only one media type objects. */
typedef enum
{
    VM_MMS_MEDIA_MSG_NONE = 0, /* Not specified */
    VM_MMS_MEDIA_MSG_TEXT,     /* Text MMS: One MMS only contains text object */
    VM_MMS_MEDIA_MSG_AUDIO,    /* Audio MMS: One MMS only contains audio object */
    VM_MMS_MEDIA_MSG_PHOTO,    /* Photo MMS: One MMS only contains image object */
    VM_MMS_MEDIA_MSG_VIDEO     /* Video MMS: One MMS only contains video object */
} vm_mms_media_msg_enum;


/* This enum is used to specify message type. */
typedef enum
{
    VM_MMS_MSG_TYPE_NOTIFICATION,     /* MMS notification */
    VM_MMS_MSG_TYPE_DELIVERY_REPORT,  /* MMS delivery report */
    VM_MMS_MSG_TYPE_READ_REPORT,      /* MMS read report v1.1 */
    VM_MMS_MSG_TYPE_MMS,              /* normal MMS message */
    VM_MMS_MSG_TYPE_JAVA,             /* Java MMS */   
    VM_MMS_MSG_TYPE_TEMPLATE,         /* MMS template */
    VM_MMS_MSG_TYPE_POSTCARD,          /* MMS postcard */
    VM_MMS_MSG_TYPE_UNSUPPORTED
}vm_mms_msg_type_enum;

typedef enum
{
    VM_MMS_MSG_STORAGE_NONE = 0X00,
    VM_MMS_MSG_STORAGE_PHONE = 0X01,
    VM_MMS_MSG_STORAGE_CARD1 = 0X02,
    VM_MMS_MSG_STORAGE_TOTAL = 0X03 
} vm_mms_msg_storage_type_enum;

/* This enum is used to specify MMS folder. */
typedef enum
{
    VM_MMS_FOLDER_NONE = 0x0,
    VM_MMS_FOLDER_INBOX = 0x1,
    VM_MMS_FOLDER_OUTBOX = 0x2,
    VM_MMS_FOLDER_SENT = 0x4,
    VM_MMS_FOLDER_DRAFT = 0x8,
    VM_MMS_FOLDER_TEMPLATE = 0x10,        /* This folder is for predefined MMS template */
    VM_MMS_FOLDER_USRDEF_TEMPLATE = 0x20, /* This folder is for user to save MMS as template */
    VM_MMS_FOLDER_ARCHIVE = 0x40,
    VM_MMS_FOLDER_HIDDEN = 0x80,
    VM_MMS_FOLDER_REPORT_BOX = 0x100,
    VM_MMS_FOLDER_ALL = 0xFFFF
}vm_mms_folder_enum;

typedef struct
{
    VMUINT  msg_id;                             /* Message id */
    VMUINT  msg_size;                           /* The size of message. Counted by byte */
    VMUINT  user_elements_size;                 /* The size of MMS bodies and subject*/
    VMUINT  date;                               /* The date field is in mms header of mms message. It should be given in seconds since 1.Jan. 1970 GMT. */
    VMUINT  expiry_date;                        /* Expiration date. The format is in relative seconds value. */
    VMUINT  received_date;                      /* Received date. This value is only valid for the received MMS message. */
    VMINT16  from_address[VM_MMS_MAX_ADDR_LEN];  /* SRV_MMS_MAX_ADDR_LEN From address of the MMS. Encoded by USC2 */
    VMINT16  subject[VM_MMS_MAX_SUBJECT_LEN];    /* SRV_MMS_MAX_SUBJECT_LEN Subject of the MMS. Encoded by USC2 */
    VMBOOL  need_read_report;              /* Specify if the MMS message require to send read report to sender. */
    VMBOOL  isRead;                        /* Specify if the MMS message is already read. */
    VMBOOL  isForwardLock;                 /* When MMS contain any DRM forward-lock or combine-delivery object, the value is KAL_TRUE. Because separate-delivery DRM object can be forwarded. */
    VMBOOL  isDRM;                         /* When MMS contain any DRM object, the value is KAL_TRUE */
    VMBOOL  isFollowPhoneMMSContentClass;  /* Specify if the MMS follow handset content class */   
    VMBOOL  hasAttachment;                 /* Specify if the MMS message contain any attachment. */
    VMUINT8   result;                             /* 0 means success, other fail */
    VMUINT8   msg_media_type;                     /* vm_mms_media_msg_enum, media type , for no media=0,text=1,audio=2,photo=3,video=4 */
    VMUINT8   from_address_type;                  /* vm_mms_addr_type_enum, from address type,unknown=0,phone=1,email=2,IPV4=3 */
    VMUINT8   msg_type;                           /* vm_mms_msg_type_enum, message type Notification=0,DR=1,RR=2,MMS=3,JAVA=4,Template=5,postcard=6 */
	VMUINT8   storage_type;                       /* vm_mms_msg_storage_type_enum, storage type,phone=1,card=2*/
    VMUINT8   sim_id;                             /* vm_mms_sim_id_enum, sim ID SIM1=1 SIM2=2 SIM3=4 ,SIM4=8 */  
}vm_mms_msg_info;

typedef struct
{
    VMINT sim; // sim card :1,2,3,4
    vm_mms_addr_type_enum addr_type;
    VMWCHAR* addr; // address UCS2
    VMWCHAR* subject; //subject UCS2
    VMWCHAR* content; //content UCS2
    VMWCHAR* att_path; //attach_file
}vm_mms_launch_data;


/*****************************************************************************
* <GROUP  CallBackFunctions>        
*
 * FUNCTION
 *    vm_mms_interrupt_callback
 * DESCRIPTION
 *  MMS interrupt callback function 
 * RETURN VALUES   
 *  result :  [IN]  TRUE means deleted the MMS, othewise return FALSE
*****************************************************************************/
typedef VMBOOL (*vm_mms_interrupt_callback)(vm_mms_msg_info* param, void* user_data);


/*****************************************************************************
* <GROUP  CallBackFunctions>        
*
 * FUNCTION
 *    vm_mms_delete_callback
 * DESCRIPTION
 *  MMS delete callback function 
 * RETURN VALUES   
 *  
*****************************************************************************/
typedef VMINT (*vm_mms_delete_callback)(
                                VMINT result, VMUINT* msg_id_list,VMINT* result_list,VMUINT num,void* user_data);

/*****************************************************************************
* <GROUP  CallBackFunctions>        
*
 * FUNCTION
 *    vm_mms_callback_type
 * DESCRIPTION
 *  MMS callback function 
 * PARAMETERS
 *  result :  [IN]  refer to vm_mms_result_enum.
*****************************************************************************/
typedef void (*vm_mms_callback_type)(VMINT  result);

/*****************************************************************************
* FUNCTION
 *    vm_mms_send_mms
 * DESCRIPTION
 *  Send MMS. The result will be returned in callback. 
 * PARAMETERS
 *  req_ptr : [IN]  MMS information to send, refer to vm_send_mms_req_t
 *  callback : [IN] callback function pointer. 
 * RETURNS
 *  send request successfully or failed.
 * RETURN VALUES                                      
 *  FALSE : failed to send request.
 *  TRUE : send request successfully.
 *
*****************************************************************************/
VMINT vm_mms_send_mms(vm_send_mms_req_t * req_ptr,  vm_mms_callback_type callback);

/*****************************************************************************
* FUNCTION
 *    vm_mms_cancel_send_mms
 * DESCRIPTION
 *  Cancel the procedure of sending MMS. If the MMS has sent already and callback
 *  has been invoked or there is no sending function invoked before, this cancelling
 *  will be ignored.
 *
*****************************************************************************/
void vm_mms_cancel_send_mms(void);

/*****************************************************************************
* FUNCTION
 *    vm_mms_launch
 * DESCRIPTION
 *  launch native editor to edit mms
 * PARAMETERS
 *  data : [IN]  MMS info
 *  data_size : [IN] sizeof data
 * RETURN VALUES                                      
 *  0 means success
 *
*****************************************************************************/
VMINT vm_mms_launch(vm_mms_launch_data* data, VMINT data_size);

/*****************************************************************************
* FUNCTION
 *    vm_mms_set_interrupt_event_handler
 * DESCRIPTION
 *  set handler to interrupt MMS
 * PARAMETERS
 *  event : [IN]  MMS event type
 *  callback : [IN] sizeof data
 *  user_data : [IN] user_data
 * RETURN VALUES                                      
 *  0 means success
 *
*****************************************************************************/
VMINT vm_mms_set_interrupt_event_handler(vm_mms_event_enum event, vm_mms_interrupt_callback callback, void* user_data);

/*****************************************************************************
* FUNCTION
 *    vm_mms_clear_interrupt_event_handler
 * DESCRIPTION
 *  clear handler 
 * PARAMETERS
 *  event : [IN]  MMS event type
 * RETURN VALUES                                      
 *  0 means success
 *
*****************************************************************************/
VMINT vm_mms_clear_interrupt_event_handler(vm_mms_event_enum event);

/*****************************************************************************
* FUNCTION
 *    vm_mms_download
 * DESCRIPTION
 *  download mms
 * PARAMETERS
 *  msg_id : [IN]  message id
 *  sim : [IN]  sim card id
 *  storage_type : [IN] storage type    
 * RETURN VALUES  
 *  0 means success
 *
*****************************************************************************/
VMINT vm_mms_download(VMUINT msg_id, vm_mms_sim_id_enum sim, vm_mms_msg_storage_type_enum storage_type);

/*****************************************************************************
* FUNCTION
 *    vm_mms_cancel_download
 * DESCRIPTION
 *  cancel downloading mms
 * PARAMETERS
 *  msg_id : [IN]  message id
 * RETURN VALUES  
 *
*****************************************************************************/
void vm_mms_cancel_download(VMINT msg_id);

/*****************************************************************************
* FUNCTION
 *    vm_mms_delete
 * DESCRIPTION
 *  delete mms
 * PARAMETERS
 *  msg_id_list : [IN]  message id
 *  msg_num : [IN]  sim card id
 *  folder : [IN] storage type    
 *  vm_mms_delete_callback : [IN]  sim card id
 *  user_data : [IN] storage type   
 * RETURN VALUES  
 *  0 means success
 *
*****************************************************************************/
VMINT vm_mms_delete(VMUINT* msg_id_list, VMUINT msg_num, vm_mms_folder_enum folder, vm_mms_delete_callback callback,void* user_data);


#ifdef __cplusplus
}
#endif

#endif /* VMMMS_SDK_H */




