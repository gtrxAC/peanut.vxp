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

#ifndef VMSETTINGS_SDK_H
#define VMSETTINGS_SDK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

#define VM_SETTINGS_RET_OK              0
#define VM_SETTINGS_RET_FAIL            -2
#define VM_SETTINGS_RET_NOT_SUPPORT     -3  
#define VM_SETTINGS_RET_PARAM_ERR       -4 
#define VM_SETTINGS_RET_NO_MEM          -5


typedef VMINT (*vm_settings_set_wallpaper_callback)(void* user_data);

typedef enum
{
    VM_SETTINGS_POWER_ON_TONE,            
    VM_SETTINGS_POWER_OFF_TONE,           
    VM_SETTINGS_POWER_ON_OFF_TONE,        
    VM_SETTINGS_COVER_OPEN_TONE,          
    VM_SETTINGS_COVER_CLOSE_TONE,         
    VM_SETTINGS_SMS_TONE,
    VM_SETTINGS_SMS_CARD2_TONE,     
    VM_SETTINGS_SMS_CARD3_TONE,       
    VM_SETTINGS_SMS_CARD4_TONE, 
    VM_SETTINGS_MMS_TONE,                 
    VM_SETTINGS_MMS_CARD2_TONE,           
    VM_SETTINGS_MMS_CARD3_TONE,           
    VM_SETTINGS_MMS_CARD4_TONE,           
    VM_SETTINGS_EMAIL_TONE,               
    VM_SETTINGS_EMAIL_CARD2_TONE,         
    VM_SETTINGS_EMAIL_CARD3_TONE,         
    VM_SETTINGS_EMAIL_CARD4_TONE,         
    VM_SETTINGS_VOICE_TONE,               
    VM_SETTINGS_VOICE_CARD2_TONE,         
    VM_SETTINGS_VOICE_CARD3_TONE,         
    VM_SETTINGS_VOICE_CARD4_TONE,         
    VM_SETTINGS_MT_CALL_TONE,            
    VM_SETTINGS_MT_CALL_CARD2_TONE,       
    VM_SETTINGS_MT_CALL_CARD3_TONE,       
    VM_SETTINGS_MT_CALL_CARD4_TONE,       
    VM_SETTINGS_VT_CALL_TONE,             
    VM_SETTINGS_VT_CALL_CARD2_TONE,       
    VM_SETTINGS_VT_CALL_CARD3_TONE,       
    VM_SETTINGS_VT_CALL_CARD4_TONE,       
    VM_SETTINGS_TONE_END               
}vm_settings_tone_enum;

typedef enum
{
    VM_SETTINGS_HOME_PAPER,
    VM_SETTINGS_LOCK_PAPER,
    VM_SETTINGS_WALLPAPER_END
}vm_setttings_wallpaper_enum;


/* Enum for time format */
typedef enum
{
    VM_SETTING_TIME_FORMAT_12_HOURS,
    VM_SETTING_TIME_FORMAT_24_HOURS,

    VM_SETTING_TIME_FORMAT_END
} vm_setting_time_format_enum;

/* Enum for date format */
typedef enum
{
    VM_SETTING_DATE_FORMAT_DD_MM_YYYY,
    VM_SETTING_DATE_FORMAT_MM_DD_YYYY,        
    VM_SETTING_DATE_FORMAT_YYYY_MM_DD,

    VM_SETTING_DATE_FORMAT_END
} vm_setting_date_format_enum;

/* Enum for date seperator */
typedef enum
{
    VM_SETTING_DATE_SEPERATOR_DOT,
    VM_SETTING_DATE_SEPERATOR_COLON,
    VM_SETTING_DATE_SEPERATOR_SLOPE,    
    VM_SETTING_DATE_SEPERATOR_LINE,

    VM_SETTING_DATE_SEPERATOR_END
} vm_setting_date_seperator_enum;


/*****************************************************************************
 * FUNCTION
 *  vm_setting_get_time_format
 * DESCRIPTION
 *  Get system time format 
 * PARAMETERS
 *  void
 * RETURNS
 *  vm_setting_time_format_enum
 *****************************************************************************/
VMINT vm_setting_get_time_format(void);


/*****************************************************************************
 * FUNCTION
 *  vm_setting_get_date_format
 * DESCRIPTION
 *  Get system date format 
 * PARAMETERS
 *  void
 * RETURNS
 *  vm_setting_date_format_enum
 *****************************************************************************/
VMINT vm_setting_get_date_format(void);


/*****************************************************************************
 * FUNCTION
 *  vm_setting_get_date_seperator
 * DESCRIPTION
 *  Get system date seperator 
 * PARAMETERS
 *  void
 * RETURNS
 *  vm_setting_date_seperator_enum
 *****************************************************************************/
VMINT vm_setting_get_date_seperator(void);


/*****************************************************************************
 * FUNCTION
 *  vm_settings_set_tone
 * DESCRIPTION
 *  set tone
 * PARAMETERS
 *  type  [in] vm_settings_tone_enum
 *  path  [in] tone path
 * RETURNS
 *  vm_settings_tone_enum
 *****************************************************************************/
VMINT vm_settings_set_tone(vm_settings_tone_enum type, VMWCHAR* path);

/*****************************************************************************
 * FUNCTION
 *  vm_settings_set_wallpaper
 * DESCRIPTION
 *  set wallpaper 
 * PARAMETERS
 *  type [in] vm_setttings_wallpaper_enum
 *  path [in] wallpaper path
 * RETURNS
 *  vm_setttings_wallpaper_enum
 *****************************************************************************/
VMINT vm_settings_set_wallpaper(vm_setttings_wallpaper_enum type, 
                                            VMWCHAR* path,vm_settings_set_wallpaper_callback callback, void* user_data);
                                            											

typedef void (*vm_srv_sensor_hr_data_cb)(void *sensor_data); 
typedef void (*vm_srv_sensor_acc_data_cb)(void *acc_x, void *acc_y, void *acc_z); 

void vm_srv_sensor_hr_data_rigister_cb(vm_srv_sensor_hr_data_cb event_hdlr);
void vm_srv_sensor_acc_data_rigister_cb(vm_srv_sensor_acc_data_cb event_hdlr);

typedef void (*vm_idle_swatch_pedometer_cb)(void *data);
void vm_idle_swatch_pedometer_register_callback(vm_idle_swatch_pedometer_cb event_hdlr);

                                            											
#ifdef __cplusplus
}
#endif 

#endif /* VMSETTINGS_SDK_H */

