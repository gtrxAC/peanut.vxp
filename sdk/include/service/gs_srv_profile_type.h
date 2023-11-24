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
 *   gs_srv_profile_type.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IProfile type header file
 *
 * Author:
 * -------
 *  Isiah Chen
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 26 2010 isiah.chen
 * [MAUI_02645644] query service mm check in
 * .
 *
 * 12 23 2010 lihong.li
 * NULL
 * .
 *
 * 12 16 2010 lihong.li
 * NULL
 * .
 *
 * 11 25 2010 isiah.chen
 * NULL
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _GS_SRV_PROFILE_TYPE_
#define _GS_SRV_PROFILE_TYPE_

/*****************************************************************************
 * Enumeration and definitions
 *****************************************************************************/

/* Service result defines, negatives for failure cases */
#define GS_SRV_PROF_RET_SUCCESS 0                  /* Success */
#define GS_SRV_PROF_RET_PROFILE_ACTIVATED 1        /* Profile activated */
#define GS_SRV_PROF_RET_DRM_NOT_FORWARDABLE 2      /* Drm not forwardable */
#define GS_SRV_PROF_RET_TRY_TO_RECOVER 3           /* Play tone file fail and try to recover */
#define GS_SRV_PROF_RET_PLAY_FINISHED 4            /* Play tone finished */
#define GS_SRV_PROF_RET_EXT_MELODY_REPLACED 5      /* External melody replaced */
#define GS_SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK 6 /* Play tone success without callback */
#define GS_SRV_PROF_RET_NOT_PLAY 7                 /* Do not play tone due to some reason */
#define GS_SRV_PROF_RET_YES 0                      /* Yes */
#define GS_SRV_PROF_RET_NO -1                      /* No */
#define GS_SRV_PROF_RET_FAIL -1                    /* Fail */
#define GS_SRV_PROF_RET_PROFILE_NOT_ACTIVATED -2   /* Profile not activated */
#define GS_SRV_PROF_RET_PROFILE_NOT_SUPPORTED -3   /* Profile not supported */
#define GS_SRV_PROF_RET_SETTING_NOT_SUPPORTED -4   /* Setting not supported */
#define GS_SRV_PROF_RET_MIDI_FILE_TOO_LARGE   -5   /* Midi file size too large */
#define GS_SRV_PROF_RET_MIDI_CHECK_FILE_FAIL  -6   /* Midi check file size fail */
#define GS_SRV_PROF_RET_PATH_TOO_LONG         -7   /* File path string too long */

/* Definde audio silent */
#define GS_SRV_PROF_TONE_SILENT 0  /* Defines the tone silent for appliaction to use */


/* Profile service event id definition */
// typedef enum
// {
//     EVT_ID_GS_SRV_PROF_IS_PLAYING = PROF_BASE + 1,     /* Profile check if player is playing, returns >0 means it is playing, 0 means it is not playing */
//     EVT_ID_GS_SRV_PROF_PROFILE_SWITCHED,               /* Profile switched */
//     EVT_ID_GS_SRV_PROF_END_OF_ENUM
// } gs_srv_prof_event_enum;

/* This enum defines the profile name for external applications to refer to */
typedef enum
{
    GS_SRV_PROF_MEETING_MODE,          /* Meeting mode */
    GS_SRV_PROF_SILENT_MODE,           /* Silnet mode */
    GS_SRV_PROF_HEADSET_MODE,          /* Headset mode */
    GS_SRV_PROF_BLUETOOTH_MODE,        /* Bluetooth profile */
    GS_SRV_PROF_MODE_END_OF_ENUM       /* End of enum */
}gs_srv_prof_external_profile_enum;


/* This enum defined BT HFP connect type */
typedef enum
{
    GS_SRV_PROF_BT_HFP_ACL,            /* ACL link */
    GS_SRV_PROF_BT_HFP_SCO,            /* SCO link */
    GS_SRV_PROF_BT_HFP_END_OF_ENUM     /* End of enum */
}gs_srv_prof_bt_connect_type_enum;


/* This enum defined BT HFP callback type */
typedef enum
{
    GS_SRV_PROF_BT_IND,                /* Indication */
    GS_SRV_PROF_BT_RSP,                /* Response */
    GS_SRV_PROF_BT_REQ,                /* Request */
    GS_SRV_PROF_BT_END_OF_ENUM         /* End of enum */
}gs_srv_prof_bt_cb_type_enum;


/* This enum defined file deletion type */
typedef enum
{
    GS_SRV_PROF_DEL_FILE,              /* Delete certain file */
    GS_SRV_PROF_DEL_FOLDER,            /* Delete whole folder */
    GS_SRV_PROF_DEL_END_OF_ENUM        /* End of enum */
}gs_srv_prof_del_type_enum;


/* This enum deinfes the audio play type */
typedef enum
{
    GS_SRV_PROF_AUDIO_NONE,             /* None */
    GS_SRV_PROF_AUDIO_DTMF,             /* DTMF tone */
    GS_SRV_PROF_AUDIO_STRING,           /* Audio string */
    GS_SRV_PROF_AUDIO_FILE,             /* File */
    GS_SRV_PROF_AUDIO_TYPE_END_OF_ENUM  /* End of enum*/
}gs_srv_prof_audio_type_enum;


/* This enum defines all possible setting items */
typedef enum
{
    GS_SRV_PROF_SETTINGS_RING_VOL_LEVEL,           /* Ring volume level : GS_SRV_PROF_volume_level */
    GS_SRV_PROF_SETTINGS_KEYPAD_VOL_LEVEL,         /* Keypad volume level : GS_SRV_PROF_volume_level */
    GS_SRV_PROF_SETTINGS_MESSAGE_VOL_LEVEL,        /* Message volume level : GS_SRV_PROF_volume_level */
    GS_SRV_PROF_SETTINGS_ALERT_TYPE,               /* Alert Type : GS_SRV_PROF_alert_type_enum */
    GS_SRV_PROF_SETTINGS_RING_TYPE,                /* Ring type : GS_SRV_PROF_ring_type_enum */
    GS_SRV_PROF_SETTINGS_INTELLIGENT_CALL_ALERT,   /* Intelligent call alert : MMI_BOOL */
    GS_SRV_PROF_SETTINGS_SYSTEM_ALERT,             /* System alert tone : MMI_BOOL */
    GS_SRV_PROF_SETTINGS_STATUS_LED,               /* Status LED pattern : GS_SRV_PROF_led_pattern_enum */
    GS_SRV_PROF_SETTINGS_KEYPAD_TONE_TYPE,         /* keypad tone : GS_SRV_PROF_keypad_tone_type_enum */

    GS_SRV_PROF_SETTINGS_POWER_ON_TONE,            /* Power on tone : GS_SRV_PROF_audio_id */
    GS_SRV_PROF_SETTINGS_POWER_OFF_TONE,           /* Power off tone : GS_SRV_PROF_audio_id */
    GS_SRV_PROF_SETTINGS_COVER_OPEN_TONE,          /* Cover on tone : GS_SRV_PROF_audio_id */
    GS_SRV_PROF_SETTINGS_COVER_CLOSE_TONE,         /* Cover off tone : GS_SRV_PROF_audio_id */
    GS_SRV_PROF_SETTINGS_SMS_TONE,                 /* SMS tone, stands for all message tone when message 
                                                   tones are not split : GS_SRV_PROF_audio_id */
    GS_SRV_PROF_SETTINGS_SMS_CARD2_TONE,           /* SMS tone - card2 ,stands for all message tone when 
                                                   message tones are not split : GS_SRV_PROF_audio_id */
    GS_SRV_PROF_SETTINGS_MMS_TONE,                 /* MMS tone : GS_SRV_PROF_audio_id */
    GS_SRV_PROF_SETTINGS_MMS_CARD2_TONE,           /* MMS tone - card2 : GS_SRV_PROF_audio_id */
    GS_SRV_PROF_SETTINGS_EMAIL_TONE,               /* Email tone : GS_SRV_PROF_audio_id */
    GS_SRV_PROF_SETTINGS_EMAIL_CARD2_TONE,         /* Email tone - card2 : GS_SRV_PROF_audio_id */
    GS_SRV_PROF_SETTINGS_VOICE_TONE,               /* Voice tone : GS_SRV_PROF_audio_id */
    GS_SRV_PROF_SETTINGS_VOICE_CARD2_TONE,         /* Voice tone - card2 : GS_SRV_PROF_audio_id */
    GS_SRV_PROF_SETTINGS_MT_CALL_TONE,             /* Icoming call tone : GS_SRV_PROF_audio_id */
    GS_SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE,       /* Icoming call tone - card2 : GS_SRV_PROF_audio_id */
    GS_SRV_PROF_SETTINGS_VT_CALL_TONE,             /* Icoming call tone - video call : GS_SRV_PROF_audio_id */
    GS_SRV_PROF_SETTINGS_VT_CALL_CARD2_TONE,       /* Icoming call tone - video call - card2 : GS_SRV_PROF_audio_id */

    GS_SRV_PROF_SETTINGS_END_OF_ENUM               /* End of enum */
}gs_srv_prof_settings_enum;


/* This enum defines the tone types for other apps to refer to for play tone request*/
typedef enum
{
    GS_SRV_PROF_TONE_NONE,                 /* None */
    GS_SRV_PROF_TONE_ERROR,                /* Error tone */
    GS_SRV_PROF_TONE_CONNECT,              /* Connect tone */
    GS_SRV_PROF_TONE_CAMP_ON,              /* Camp on tone */
    GS_SRV_PROF_TONE_WARNING,              /* Warning tone */
    GS_SRV_PROF_TONE_INCOMING_CALL,        /* Incoming call tone */
    GS_SRV_PROF_TONE_IMCOMING_CALL_CARD2,  /* Incoming call tone - card2 */
    GS_SRV_PROF_TONE_VIDEO_CALL,           /* Video call tone */
    GS_SRV_PROF_TONE_VIDEO_CALL_CARD2,     /* Video call tone - card2 */
    GS_SRV_PROF_TONE_SMS,                  /* SMS tone */
    
    GS_SRV_PROF_TONE_SMS_CARD2,            /* SMS tone - card2 */
    GS_SRV_PROF_TONE_MMS,                  /* MMS tone */
    GS_SRV_PROF_TONE_MMS_CARD2,            /* MMS tone - card2 */
    GS_SRV_PROF_TONE_EMAIL,                /* Email tone */
    GS_SRV_PROF_TONE_EMAIL_CARD2,          /* Email tone - card2 */
    GS_SRV_PROF_TONE_VOICE,                /* Voice tone */
    GS_SRV_PROF_TONE_VOICE_CARD2,          /* Voice tone - card2 */
    GS_SRV_PROF_TONE_ALARM,                /* Alarm tone */
    GS_SRV_PROF_TONE_POWER_ON,             /* Power on tone */
    GS_SRV_PROF_TONE_POWER_OFF,            /* Power off tone */

    GS_SRV_PROF_TONE_COVER_OPEN,           /* Cover open tone */
    GS_SRV_PROF_TONE_COVER_CLOSE,          /* Cover close tone */
    GS_SRV_PROF_TONE_SUCCESS,              /* Success tone */
    GS_SRV_PROF_TONE_SAVE,                 /* Save tone */
    GS_SRV_PROF_TONE_EMPTY_LIST,           /* Empty tone */
    GS_SRV_PROF_TONE_GENERAL_TONE,         /* General tone */
    GS_SRV_PROF_TONE_AUX,                  /* AUX tone */
    GS_SRV_PROF_TONE_BATTERY_LOW,          /* Battery low tone */
    GS_SRV_PROF_TONE_BATTERY_WARNING,      /* Battery warning tone */
    GS_SRV_PROF_TONE_CALL_REMINDER,        /* Call reminder tone */

    GS_SRV_PROF_TONE_CCBS,                 /* CCBS tone */
    GS_SRV_PROF_TONE_CONGESTION,           /* Congestion tone */
    GS_SRV_PROF_TONE_AUTH_FAIL,            /* Authentication fail tone */
    GS_SRV_PROF_TONE_NUM_UNOBTAIN,         /* Number un-obtained tone */
    GS_SRV_PROF_TONE_CALL_DROP,            /* Call drop tone */
    GS_SRV_PROF_TONE_SMS_INCALL,           /* SMS in call tone */
    GS_SRV_PROF_TONE_WARNING_INCALL,       /* Warning in call tone */
    GS_SRV_PROF_TONE_ERROR_INCALL,         /* Error in call tone */
    GS_SRV_PROF_TONE_CONNECT_INCALL,       /* Connect in call tone */
    GS_SRV_PROF_TONE_SUCCESS_INCALL,       /* Success in call tone */

    GS_SRV_PROF_TONE_IMPS_CONTACT_ONLINE,          /* IMPS tone - contact online */
    GS_SRV_PROF_TONE_IMPS_NEW_MESSAGE,             /* IMPS tone - new message */
    GS_SRV_PROF_TONE_IMPS_CONTACT_INVITATION,      /* IMPS tone - contact invitation */
    GS_SRV_PROF_TONE_IMPS_CHATROOM_NOTIFICATION,   /* IMPS tone - chat room notification */
    GS_SRV_PROF_TONE_FILE_ARRIVAL,         /* File arrival tone */
    GS_SRV_PROF_TONE_SENT,                 /* Sent tone */
    GS_SRV_PROF_TONE_DELETED,              /* Deleted tone */
    GS_SRV_PROF_TONE_PROBLEM,              /* Problem tone */
    GS_SRV_PROF_TONE_CONFIRM,              /* Confirm tone */
    GS_SRV_PROF_TONE_EXPLICITLY_SAVE,      /* Explicitly save tone */

    GS_SRV_PROF_TONE_NOT_AVAILABLE,        /* Not available tone */
    GS_SRV_PROF_TONE_ANS_PHONE,            /* Answer phone tone */
    GS_SRV_PROF_TONE_WAP_PUSH,             /* WAP push tone */
    GS_SRV_PROF_TONE_REMIND,               /* Remind tone */
    GS_SRV_PROF_TONE_KEYPAD,               /* Key pad tone */
    GS_SRV_PROF_TONE_EM,                   /* Engineering mode tone */
    GS_SRV_PROF_TONE_FM,                   /* Factory mode tone */
    GS_SRV_PROF_TONE_PHONEBOOK,            /* Phonebook tone */
    GS_SRV_PROF_TONE_POC,                  /* PoC tone */
    GS_SRV_PROF_TONE_VOIP,                 /* Voip tone */

    GS_SRV_PROF_TONE_SAT,                  /* SAT tone */
    GS_SRV_PROF_TONE_GSM_BUSY,             /* GSM busy */

    //NONE_TONE = GS_SRV_PROF_TONE_NONE,
    //ERROR_TONE = GS_SRV_PROF_TONE_ERROR,
    //CONNECT_TONE = GS_SRV_PROF_TONE_CONNECT,
    //CAMP_ON_TONE = GS_SRV_PROF_TONE_CAMP_ON,
    //WARNING_TONE = GS_SRV_PROF_TONE_WARNING,
    //INCOMING_CALL_TONE = GS_SRV_PROF_TONE_INCOMING_CALL,        /*5*/
    //ALARM_TONE = GS_SRV_PROF_TONE_ALARM,
    //POWER_ON_TONE = GS_SRV_PROF_TONE_POWER_ON,
    //POWER_OFF_TONE = GS_SRV_PROF_TONE_POWER_OFF,
    //COVER_OPEN_TONE = GS_SRV_PROF_TONE_COVER_OPEN,
    //COVER_CLOSE_TONE = GS_SRV_PROF_TONE_COVER_CLOSE,          /*10*/
    //MESSAGE_TONE = GS_SRV_PROF_TONE_SMS,
    //KEYPAD_PLAY_TONE = GS_SRV_PROF_TONE_KEYPAD,
    //SUCCESS_TONE = GS_SRV_PROF_TONE_SUCCESS,
    //SAVE_TONE = GS_SRV_PROF_TONE_SAVE,
    //EMPTY_LIST_TONE = GS_SRV_PROF_TONE_EMPTY_LIST,           /*15*/
    //GENERAL_TONE = GS_SRV_PROF_TONE_GENERAL_TONE,
    //SMS_IN_CALL_TONE = GS_SRV_PROF_TONE_SMS_INCALL,
    //AUX_TONE = GS_SRV_PROF_TONE_AUX,
    //WARNING_TONE_IN_CALL = GS_SRV_PROF_TONE_WARNING_INCALL,
    //ERROR_TONE_IN_CALL = GS_SRV_PROF_TONE_ERROR_INCALL,        /*20*/
    //CONNECT_TONE_IN_CALL = GS_SRV_PROF_TONE_CONNECT_INCALL,
    //SUCCESS_TONE_IN_CALL = GS_SRV_PROF_TONE_SUCCESS_INCALL,
    //BATTERY_LOW_TONE = GS_SRV_PROF_TONE_BATTERY_LOW,
    //BATTERY_WARNING_TONE = GS_SRV_PROF_TONE_BATTERY_WARNING,
    //CALL_REMINDER_TONE = GS_SRV_PROF_TONE_CALL_REMINDER,        /*25*/
    //CCBS_TONE = GS_SRV_PROF_TONE_CCBS,
    //CONGESTION_TONE = GS_SRV_PROF_TONE_CONGESTION,
    //AUTH_FAIL_TONE = GS_SRV_PROF_TONE_AUTH_FAIL,
    //NUM_UNOBTAIN_TONE = GS_SRV_PROF_TONE_NUM_UNOBTAIN,
    //CALL_DROP_TONE = GS_SRV_PROF_TONE_CALL_DROP,            /*30*/
    //IMPS_CONTACT_ONLINE_TONE = GS_SRV_PROF_TONE_IMPS_CONTACT_ONLINE,
    //IMPS_NEW_MESSAGE_TONE = GS_SRV_PROF_TONE_IMPS_NEW_MESSAGE,
    //IMPS_CONTACT_INVITATION_TONE = GS_SRV_PROF_TONE_IMPS_CONTACT_INVITATION,
    //IMPS_CHATROOM_NOTIFICATION_TONE = GS_SRV_PROF_TONE_IMPS_CHATROOM_NOTIFICATION,
    //CARD2_INCOMING_CALL_TONE = GS_SRV_PROF_TONE_IMCOMING_CALL_CARD2,  /*35*/
    //CARD2_MESSAGE_TONE = GS_SRV_PROF_TONE_SMS_CARD2,
    //FILE_ARRIVAL_TONE = GS_SRV_PROF_TONE_FILE_ARRIVAL,

    ///*for op11*/
    //SENT_TONE = GS_SRV_PROF_TONE_SENT,
    //DELETED_TONE = GS_SRV_PROF_TONE_DELETED,
    //PROBLEM_TONE = GS_SRV_PROF_TONE_PROBLEM,              /*40*/
    //NETWORK_PROBLEM_TONE = GS_SRV_PROF_TONE_PROBLEM,
    //CONFIRM_TONE = GS_SRV_PROF_TONE_CONFIRM,
    //EXPLICITLY_SAVE_TONE = GS_SRV_PROF_TONE_EXPLICITLY_SAVE,
    //NOT_AVAILABLE_TONE = GS_SRV_PROF_TONE_NOT_AVAILABLE,        /*Oops tone*/
    //ANS_PHONE_TONE = GS_SRV_PROF_TONE_ANS_PHONE,            /*45*/
    //SMS_TONE = GS_SRV_PROF_TONE_SMS,
    //MMS_TONE = GS_SRV_PROF_TONE_MMS,
    //EMAIL_TONE = GS_SRV_PROF_TONE_EMAIL,
    //VOICE_TONE = GS_SRV_PROF_TONE_VOICE,
    //WAP_PUSH_TONE = GS_SRV_PROF_TONE_WAP_PUSH,             /*50*/
    //REMIND_TONE = GS_SRV_PROF_TONE_REMIND,

    GS_SRV_PROF_TONE_END_OF_ENUM           /* End of enum */
}gs_srv_prof_tone_enum;

typedef enum
{
    GS_SRV_PROF_AUD_TONE1 = 101,
    GS_SRV_PROF_AUD_TONE2,
    GS_SRV_PROF_AUD_TONE3,
    GS_SRV_PROF_AUD_TONE4,
    GS_SRV_PROF_AUD_TONE5,
    GS_SRV_PROF_AUD_TONE6,
    GS_SRV_PROF_AUD_TONE7,
    GS_SRV_PROF_AUD_TONE8,
    GS_SRV_PROF_AUD_TONE9,
    GS_SRV_PROF_AUD_TONE10,
    GS_SRV_PROF_AUD_TONE_END_OF_ENUM
}gs_srv_prof_aud_tone_enum;


typedef enum
{
    GS_SRV_PROF_AUD_RING1 = 151,
    GS_SRV_PROF_AUD_RING2,
    GS_SRV_PROF_AUD_RING3,
    GS_SRV_PROF_AUD_RING4,
    GS_SRV_PROF_AUD_RING5,
    GS_SRV_PROF_AUD_RING6,
    GS_SRV_PROF_AUD_RING7,
    GS_SRV_PROF_AUD_RING8,
    GS_SRV_PROF_AUD_RING9,
    GS_SRV_PROF_AUD_RING10,
    GS_SRV_PROF_AUD_RING11,
    GS_SRV_PROF_AUD_RING12,
    GS_SRV_PROF_AUD_RING13,
    GS_SRV_PROF_AUD_RING14,
    GS_SRV_PROF_AUD_RING15,
    GS_SRV_PROF_AUD_RING16,
    GS_SRV_PROF_AUD_RING17,
    GS_SRV_PROF_AUD_RING18,
    GS_SRV_PROF_AUD_RING19,
    GS_SRV_PROF_AUD_RING20,
    GS_SRV_PROF_AUD_RING_END_OF_ENUM
}gs_srv_prof_aud_ring_enum;


/* This enum defined the ring type */
typedef enum
{
    GS_SRV_PROF_RING_TYPE_REPEAT,         /* Ringing */
    GS_SRV_PROF_RING_TYPE_ASCENDING,      /* Acending */
    GS_SRV_PROF_RING_TYPE_ONCE,           /* Once */
    GS_SRV_PROF_RING_TYPE_BEEP_ONCE,      /* Beep once */
    GS_SRV_PROF_RING_TYPE_END_OF_ENUM     /* End of enum */
}gs_srv_prof_ring_type_enum;


/* This enum defined the ring type */
typedef enum
{
    GS_SRV_PROF_VOL_LEVEL_0,       /* Level 0 */
    GS_SRV_PROF_VOL_LEVEL_1,       /* Level 1 */
    GS_SRV_PROF_VOL_LEVEL_2,       /* Level 2 */
    GS_SRV_PROF_VOL_LEVEL_3,       /* Level 3 */
    GS_SRV_PROF_VOL_LEVEL_4,       /* Level 4 */
    GS_SRV_PROF_VOL_LEVEL_5,       /* Level 5 */
    GS_SRV_PROF_VOL_LEVEL_6,       /* Level 6 */
    GS_SRV_PROF_VOL_LEVEL_7,       /* Level 7 */
    GS_SRV_PROF_VOL_LEVEL_END_OF_ENUM /* End of enum */
}gs_srv_prof_vol_level_enum;


/* This enum defined the ring play type */
typedef enum
{
    GS_SRV_PROF_ALERT_TYPE_INVALID,       /* Invalid */
    GS_SRV_PROF_ALERT_TYPE_RING,          /* Ringing */
    GS_SRV_PROF_ALERT_TYPE_VIB_ONLY,      /* Vibrate only */
    GS_SRV_PROF_ALERT_TYPE_VIB_AND_RING,  /* Vibrate and ring */
    GS_SRV_PROF_ALERT_TYPE_VIB_THEN_RING, /* Vibrate then ring */
    GS_SRV_PROF_ALERT_TYPE_SILENT,        /* Silent */
    GS_SRV_PROF_ALERT_TYPE_END_OF_ENUM    /* End of enum */
}gs_srv_prof_alert_type_enum;


/* This enum defined LED patterns */
typedef enum
{
    GS_SRV_PROF_LED_NONE,                  /* None */
    GS_SRV_PROF_LED_PATTERN_1,             /* Color 1 */
    GS_SRV_PROF_LED_PATTERN_2,             /* Color 2 */
    GS_SRV_PROF_LED_PATTERN_3,             /* Color 3 */
    GS_SRV_PROF_LED_PATTERN_4,             /* Color 4 */
    GS_SRV_PROF_LED_PATTERN_5,             /* Color 5 */
    GS_SRV_PROF_LED_PATTERN_6,             /* Color 6 */
    GS_SRV_PROF_LED_PATTERN_END_OF_ENUM    /* End of enum */
}gs_srv_prof_led_pattern_enum;


/* This enum defined the keypad tone type */
typedef enum
{
    GS_SRV_PROF_KEYPAD_SILENT,             /* Silent */
    GS_SRV_PROF_KEYPAD_CLICK,              /* Click */
    GS_SRV_PROF_KEYPAD_TONE,               /* Tone */
    GS_SRV_PROF_KEYPAD_NUM_1,              /* Special number key 1 */
    GS_SRV_PROF_KEYPAD_NUM_2,              /* Special number key 2 */
    GS_SRV_PROF_KEYPAD_NUM_3,              /* Special number key 3 */
    GS_SRV_PROF_KEYPAD_NUM_4,              /* Special number key 4 */
    GS_SRV_PROF_KEYPAD_NUM_5,              /* Special number key 5 */
    GS_SRV_PROF_KEYPAD_NUM_6,              /* Special number key 6 */
    GS_SRV_PROF_KEYPAD_CUST_1,             /* Customer 1 */
    GS_SRV_PROF_KEYPAD_CUST_2,             /* Customer 2 */
    GS_SRV_PROF_KEYPAD_CUST_3,             /* Customer 3 */
    GS_SRV_PROF_KEYPAD_CUST_4,             /* Customer 4 */
    GS_SRV_PROF_KEYPAD_CUST_5,             /* Customer 5 */
    GS_SRV_PROF_KEYPAD_CUST_6,             /* Customer 6 */
    GS_SRV_PROF_KEYPAD_END_OF_ENUM 
}gs_srv_prof_keypad_tone_type_enum;


typedef U8 gs_srv_prof_volume_level;
typedef U16 gs_srv_prof_audio_id;
typedef S32 gs_srv_prof_ret;
typedef gs_srv_prof_ret (*gs_srv_prof_play_tone_callback)(gs_srv_prof_ret result);


typedef struct
{
    gs_srv_prof_audio_id audio_id;             /* audio id to play */
    WCHAR* filepath;                        /* filepath fo play */
    gs_srv_prof_ring_type_enum play_style;     /* play style */
    gs_srv_prof_volume_level volume;           /* volume */
    gs_srv_prof_tone_enum tone_type;           /* tone type */
    U8  aud_path;                           /* audio path */
    gs_srv_prof_audio_type_enum audio_type;    /* audio type */
    gs_srv_prof_play_tone_callback callback;   /* callback */
} gs_srv_prof_play_req_struct;


/* Tone, Keypad sound to play on audio device. */
#define GS_MDI_DEVICE_SPEAKER      0
/* Microphone sound to send on audio device. */
#define GS_MDI_DEVICE_MICROPHONE   1
/* Earphone, carkit */
#define GS_MDI_DEVICE_SPEAKER2     4
/* Loudspeaker for free sound */
#define GS_MDI_DEVICE_LOUDSPEAKER  5
/* Output from earphone and loud speaker */
#define GS_MDI_DEVICE_SPEAKER_BOTH 6
/* Used to be OR bitwise with above audio output devices */
#define GS_MDI_DEVICE_BT_HEADSET   8

#endif /* _GS_SRV_PROFILE_TYPE_ */ 

