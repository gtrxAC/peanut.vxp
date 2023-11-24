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
 *   gs_srv_bitstreamaudio_interface_def.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IBitstreamAudio interface
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
#include "gs_srv_bitstreamaudio_type.h"



/***************************************************************************** 
* IBitstreamAudio
*****************************************************************************/
#define DEF_METHODS_IBITSTREAMAUDIO(IOBJ) \
    DEF_METHODS_GS_IBase(IOBJ) \
    DEF_METHOD3(IOBJ, S32, gs_bitstream_audio_open_handle, S32* ,p_handle, gs_bitstream_audio_cfg_struct* ,p_cfg, bistream_audio_open_handle_result_callback, result_callback) \
	DEF_METHOD1(IOBJ, S32, gs_bitstream_audio_close,S32,handle)\
	DEF_METHOD2(IOBJ, S32, gs_bitstream_audio_get_buffer_status,S32,handle,gs_bitstream_audio_buffer_status*,p_status)\
	DEF_METHOD4(IOBJ, S32, gs_bitstream_audio_put_data,S32,handle, U8*,p_buffer, U32,buffer_size, U32*,p_used_size)\
	DEF_METHOD4(IOBJ, S32, gs_bitstream_audio_put_frame,S32 ,handle, U8* ,p_buffer, U32 ,buffer_size, U32 ,timestamp)\
	DEF_METHOD2(IOBJ, S32, gs_bitstream_audio_start,S32 ,handle, gs_bitstream_audio_start_param* ,p_para)\
	DEF_METHOD1(IOBJ, S32, gs_bitstream_audio_stop,S32,handle)\
	DEF_METHOD2(IOBJ, S32, gs_bitstream_audio_get_play_time,S32 ,handle, U32*,p_ms_current_time)\
	DEF_METHOD0(IOBJ, U16, gs_bitstream_audio_get_open_handle_count)

DEF_INTERFACE(IBitstreamAudio, GS_IBase)
    DEF_METHODS_IBITSTREAMAUDIO(IBitstreamAudio)
DEF_INTERFACE_END(IBitstreamAudio)

