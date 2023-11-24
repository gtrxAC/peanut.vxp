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
 *   gs_srv_videorecord_interface_def.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IVideoRecord interface
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
 * 03 29 2011 isiah.chen
 * [MAUI_02654916] MAUI AND 11A GETSRV
 * .
 *
 * 03 10 2011 isiah.chen
 * [MAUI_02655722] 11AW11.12 check in
 * getsrv. audio bt case. camera.
 *
 * 03 09 2011 isiah.chen
 * [MAUI_02654916] MAUI AND 11A GETSRV
 * .
 *
 * 01 23 2011 lihong.li
 * NULL
 * .
 *
 * 12 26 2010 isiah.chen
 * [MAUI_02645644] query service mm check in
 * .
 *
 * 12 16 2010 lihong.li
 * NULL
 * .
 *
 * 12 15 2010 isiah.chen
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

#include "gs_idef.h"
#include "gs_srv_videorecord_type.h"



/***************************************************************************** 
* IVideoRecord
*****************************************************************************/
#define DEF_METHODS_IVIDEORECORD(IOBJ) \
    DEF_METHODS_GS_IBase(IOBJ)\
	DEF_METHOD1(IOBJ, S32,gs_video_set_camera_id,U16,camera_id)\
	DEF_METHOD1(IOBJ, S32,gs_video_detect_sensor_id,U8,cam_id)\
	DEF_METHOD0(IOBJ, S32,gs_video_rec_power_on)\
	DEF_METHOD0(IOBJ, S32,gs_video_rec_power_off)\
	DEF_METHOD3(IOBJ, S32,gs_video_rec_record_start,S8*,filename,  gs_record_result_callback, record_result_callback,void*,user_data)\
	DEF_METHOD0(IOBJ, S32,gs_video_rec_record_stop)\
	DEF_METHOD1(IOBJ, S32,gs_video_rec_record_pause,MMI_BOOL,stop_preview)\
	DEF_METHOD0(IOBJ, S32,gs_video_rec_record_resume)\
	DEF_METHOD3(IOBJ, S32,gs_video_rec_preview_start,S32 ,preview_layer_handle,MMI_BOOL ,is_lcd_update,gs_video_setting_struct*,setting_p)\
	DEF_METHOD0(IOBJ, S32,gs_video_rec_preview_stop)\
	DEF_METHOD3(IOBJ, S32,gs_video_rec_save_file,S8 *,filepath,  gs_save_result_callback ,save_result_callback,void*,user_data)\
	DEF_METHOD0(IOBJ, S32,gs_video_rec_stop_save)\
	DEF_METHOD1(IOBJ, BOOL,gs_video_rec_has_unsaved_file,S8*,filepath)\
	DEF_METHOD1(IOBJ, void,gs_video_rec_delete_unsaved_file,S8*,filepath)\
	DEF_METHOD1(IOBJ, void,gs_video_rec_get_cur_record_time,U64*,cur_record_time)\
	DEF_METHOD1(IOBJ, void,gs_video_rec_update_para_ev,U16,para)\
	DEF_METHOD1(IOBJ, void,gs_video_rec_update_para_zoom,U16,para)\
	DEF_METHOD1(IOBJ, void,gs_video_rec_update_para_effect,U16,para)\
	DEF_METHOD1(IOBJ, void,gs_video_rec_update_para_wb,U16,para)\
	DEF_METHOD1(IOBJ, void,gs_video_rec_update_para_night,U16,para)\
	DEF_METHOD2(IOBJ, U16,gs_video_rec_get_max_zoom_factor,S32,record_width, S32,record_height)\
	DEF_METHOD0(IOBJ, U64,gs_video_rec_get_record_file_size)\
	DEF_METHOD1(IOBJ, void,gs_video_rec_load_default_setting,gs_video_setting_struct*,setting_p)\
	DEF_METHOD0(IOBJ, S32,gs_video_rec_update_blt_pause)\
	DEF_METHOD4(IOBJ, S32,gs_video_rec_update_blt_resume,S32, preview_layer_handle,U32, blt_layer_flag,U32, preview_layer_flag, MMI_BOOL, is_lcd_update)

DEF_INTERFACE(IVideoRecord, GS_IBase)
    DEF_METHODS_IVIDEORECORD(IVideoRecord)
DEF_INTERFACE_END(IVideoRecord)


