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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   gs_srv_appmgr_type.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IAppmgr type header file
 *
 * Author:
 * -------
 *  Jia Luo
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _GS_SRV_APPMGR_TYPE_
#define _GS_SRV_APPMGR_TYPE_

//Maximum lenght of package name & badge. The length does NOT include the NULL terminator
#define GS_APP_PACKAGE_NAME_MAX_LEN  (60)
#define GS_APP_PACKAGE_BADGE_MAX_LEN (3)

//AppMgrSrv query type
typedef enum
{
        GS_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU = 0x0001,
        GS_APPMGR_ALL_APP_PACKAGE = 0x0002,
        GS_APPMGR_INSTALLED_APP_PACKAGE = 0x0004,
        GS_APPMGR_SHORTCUT_APP_PACKAGE = 0x0008
} gs_appmgr_query_type_enum;

//Application package type
typedef enum
{
        GS_APPMGR_UNKNOWN_APP_PACKAGE_TYPE, 
        GS_APPMGR_NATIVE_APP_PACKAGE_TYPE, 
        GS_APPMGR_JAVA_APP_PACKAGE_TYPE, 
        GS_APPMGR_MRE_APP_PACKAGE_TYPE, 
        GS_APPMGR_WIDGET_APP_PACKAGE_TYPE
} gs_appmgr_app_package_type_enum;

//Callback event
typedef enum
{
        GS_APPMGR_CB_EVENT_INSTALL_PACKAGE,
        GS_APPMGR_CB_EVENT_UPDATE_PACKAGE,
        GS_APPMGR_CB_EVENT_UNINSTALL_PACKAGE,
        GS_APPMGR_CB_EVENT_UPDATE_BADGE,
        GS_APPMGR_CB_EVENT_INSTALL_START,
        GS_APPMGR_CB_EVENT_INSTALL_PROGRESS,
        GS_APPMGR_CB_EVENT_INSTALL_FINISH,
        GS_APPMGR_CB_EVENT_INSTALL_ERROR
} gs_appmgr_cb_event_enum;

//Uninstall CB
typedef enum      
{ 
        GS_APPMGR_UNINSTALL_CB_DONE,
        GS_APPMGR_UNINSTALL_CB_ERROR,
        GS_APPMGR_UNINSTALL_CB_CANCEL
} gs_appmgr_uninstall_cb_enum;

//Image source type
typedef enum
 {
        GS_IMAGE_SRC_TYPE_NULL = 0,
        GS_IMAGE_SRC_TYPE_IMG_HANDLE,
        GS_IMAGE_SRC_TYPE_PATH,
        GS_IMAGE_SRC_TYPE_MEM,                   /* Image from mem buffer */
        GS_IMAGE_SRC_TYPE_ROM_MEMORY,
        GS_IMAGE_SRC_TYPE_MAX
} gs_image_src_type_enum;


//Application package name
typedef CHAR  gs_app_package_name_struct[60];
typedef U32* IMG_HANDLE;
//Image source
typedef struct
{
        gs_image_src_type_enum type;               /* Image source type */
        union
        {
            IMG_HANDLE  res_id;                                    /* Resource ID if using MMI_IMAGE_SRC_TYPE_RES_ID */
            WCHAR       path[256];                                /* File path if using MMI_IMAGE_SRC_TYPE_PATH */
            U8* mem;                             /* Mem address if using MMI_IMAGE_SRC_TYPE_MEM */
            struct image_struct
            {
            	U8 *image_ptr;                                                 /*Image memory pointer if using MMI_IMAGE_SRC_TYPE_MEMORY*/
            	U32 image_len;
            }image;
        } data;
} gs_image_src_struct;

//Event callback function
typedef void (*gs_appmgr_event_cb_fct)(gs_appmgr_cb_event_enum event, void* data, U16 data_len, void* user_data);

//Uninstall callback function
typedef void (*gs_appmgr_uninstall_cb_fct)(gs_appmgr_uninstall_cb_enum result, void* user_data);

#endif //_GS_SRV_APPMGR_TYPE_


