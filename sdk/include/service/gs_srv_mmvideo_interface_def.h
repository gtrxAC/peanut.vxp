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
 *   gs_srv_mmvideo_interface_def.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IMMVideo interface
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
 * 12 23 2010 lihong.li
 * NULL
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "gs_idef.h"
#include "gs_srv_mmvideo_type.h"



/***************************************************************************** 
* IMMVideo
*****************************************************************************/
#define DEF_METHODS_IMMVIDEO(IOBJ) \
    DEF_METHODS_GS_IBase(IOBJ) \
    DEF_METHOD0(IOBJ, S32, video_ply_close_file)\
    DEF_METHOD0(IOBJ, S32, video_ply_stop)\
	DEF_METHOD3(IOBJ, S32, video_ply_play,gs_video_play_struct* ,pPlayStruct,gs_play_finish_callback ,callback,void*, user_data)\
	DEF_METHOD3(IOBJ, S32, video_ply_open_file, const S8*,filename,gs_open_result_callback,open_result_callback,void*, user_data)\
    DEF_METHOD2(IOBJ, S32, video_ply_snapshot, S32,layer_handle,PS8,file_name)\
    DEF_METHOD1(IOBJ, void, video_ply_get_cur_play_time,U64*,cur_play_time)\
    DEF_METHOD2(IOBJ, S32, video_ply_seek_and_get_frame, int,time,S32,player_layer_handle)\
    DEF_METHOD4(IOBJ, S32, video_ply_non_block_seek_and_get_frame, int,time,S32,player_layer_handle,gs_seek_result_callback,seek_result_callback,void*,user_data)\
    DEF_METHOD0(IOBJ, S32, video_ply_stop_non_block_seek)\
    DEF_METHOD1(IOBJ, S32, video_ply_set_brightness,U16,brightness)\
    DEF_METHOD1(IOBJ, S32, video_ply_set_contrast,U16,contrast)\
    DEF_METHOD1(IOBJ, S32, video_ply_check_is_able_to_play,PS8,file_name)\
	DEF_METHOD0(IOBJ, BOOL, video_is_playing)\
	DEF_METHOD0(IOBJ, BOOL, video_is_recording)\
    DEF_METHOD2(IOBJ, S32, video_ply_get_total_duration, const S8*,filename, U64*,total_duration)\
    DEF_METHOD1(IOBJ, S32, video_ply_test, U64,para)\
    DEF_METHOD2(IOBJ, S32, video_ply_test_1, U64,para,U32,p2)

DEF_INTERFACE(IMMVideo, GS_IBase)
    DEF_METHODS_IMMVIDEO(IMMVideo)
DEF_INTERFACE_END(IMMVideo)


