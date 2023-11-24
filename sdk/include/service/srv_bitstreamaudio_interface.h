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
 *   srv_bitstreamaudio_interface.h
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

#include "gs_id.h"
#include "gs_base.h"

#define GS_C_INTERFACE
#include "gs_srv_bitstreamaudio_interface_def.h"

#include "gs_srv_bitstreamaudio_type.h"

/*****************************************************************************
 * IBitstreamAudio methods
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  IBitstreamAudio_addRef
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 * RETURNS
 *  The error code of the operation.
 *****************************************************************************/
S32 __inline IBitstreamAudio_addRef(IBitstreamAudio *obj)
{
    return obj->vt->addRef(obj);
}


/*****************************************************************************
 * FUNCTION
 *  IBitstreamAudio_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 * RETURNS
 *  The error code of the operation.
 *****************************************************************************/
S32 __inline IBitstreamAudio_release(IBitstreamAudio *obj)
{
    return obj->vt->release(obj);
}


/*****************************************************************************
 * FUNCTION
 *  IBitstreamAudio_queryInterface
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 *  iid : [IN]        
 *  pptr : [IN]        
 * RETURNS
 *  The error code of the operation.
 *****************************************************************************/
S32 __inline IBitstreamAudio_queryInterface(IBitstreamAudio *obj, S32 iid, GS_IBase **pptr)
{
    return obj->vt->queryInterface(obj, iid, pptr);
}





S32 __inline IBitstreamAudio_open_handle(IBitstreamAudio *obj,S32* p_handle, gs_bitstream_audio_cfg_struct* p_cfg, bistream_audio_open_handle_result_callback result_callback)
{
    return obj->vt->gs_bitstream_audio_open_handle(obj,p_handle, p_cfg, result_callback);
}



/*****************************************************************************


 * FUNCTION


 *  IBitstreamAudio_close


 * DESCRIPTION


 *  This function is to close a bitstream audio handle


 * PARAMETERS


 *  handle          : [IN] The audio handle to be closed.


 * RETURN VALUES


 *  GS_RES_BITSTREAM_SUCCEED : Close successfully.


 *****************************************************************************/
S32 __inline IBitstreamAudio_close(IBitstreamAudio *obj,S32 handle)
{
	return obj->vt->gs_bitstream_audio_close(obj,handle);
}



/*****************************************************************************


 * FUNCTION


 *  IBitstreamAudio_get_buffer_status


 * DESCRIPTION


 *  This function is to get current bitstream ring buffer status


 * PARAMETERS


 *  handle      : [IN] The audio handle


 *  p_status    : [OUT] Buffer status


 * RETURN VALUES


 *  GS_RES_BITSTREAM_SUCCEED : Get successfully.


 *****************************************************************************/
S32 __inline IBitstreamAudio_get_buffer_status(IBitstreamAudio *obj,S32 handle, gs_bitstream_audio_buffer_status* p_status)
{
	return obj->vt->gs_bitstream_audio_get_buffer_status(obj, handle,  p_status);
}



/*****************************************************************************


 * FUNCTION


 *  IBitstreamAudio_put_data


 * DESCRIPTION


 *  This function is to put audio data into media ring buffer


 * PARAMETERS


 *  handle      : [IN] The audio handle


 *  p_buffer    : [IN] Buffer pointer for input data


 *  buffer_size : [IN] Buffer size for input data


 *  p_used_size : [OUT] The actual filled buffer size


 * RETURN VALUES


 *  GS_RES_BITSTREAM_SUCCEED : Put successfully.


 *****************************************************************************/
S32 __inline IBitstreamAudio_put_data(IBitstreamAudio *obj,S32 handle, U8* p_buffer, U32 buffer_size, U32* p_used_size)
{
    return obj->vt->gs_bitstream_audio_put_data( obj,handle,  p_buffer,  buffer_size,  p_used_size);
}


/*****************************************************************************


 * FUNCTION


 *  IBitstreamAudio_put_frame


 * DESCRIPTION


 *  This function is to put a complete audio frame into media ring buffer.


 *  If the buffer is not enough, the entire frame will not be put into buffer.


 * PARAMETERS


 *  handle      : [IN] The audio handle


 *  p_buffer    : [IN] Buffer pointer for input data


 *  buffer_size : [IN] Buffer size for input data


 *  timestape   : [IN] Timestamp for audio frame


 * RETURN VALUES


 *  MDI_RES_BITSTREAM_SUCCEED : Put successfully.


 *****************************************************************************/
S32 __inline IBitstreamAudio_put_frame(IBitstreamAudio *obj,S32 handle, U8* p_buffer, U32 buffer_size, U32 timestamp)
{
	return obj->vt->gs_bitstream_audio_put_frame( obj,handle,  p_buffer,  buffer_size,  timestamp);
}


/*****************************************************************************


 * FUNCTION


 *  IBitstreamAudio_audio_start


 * DESCRIPTION


 *  This function is to start play data in audio bitstream buffer


 * PARAMETERS


 *  handle  : [IN] The audio handle


 *  p_para  : [IN] Configuration for play


 * RETURN VALUES


 *  GS_RES_BITSTREAM_SUCCEED : Start successfully.


 *****************************************************************************/
S32 __inline IBitstreamAudio_start(IBitstreamAudio *obj,S32 handle, gs_bitstream_audio_start_param* p_para)
{
    return obj->vt->gs_bitstream_audio_start( obj,handle,  p_para);
}


/*****************************************************************************


 * FUNCTION


 *  IBitstreamAudio_stop


 * DESCRIPTION


 *  This function is to stop bitstream audio playback


 * PARAMETERS


 *  handle          : [IN] The audio handle


 * RETURN VALUES


 *  GS_RES_BITSTREAM_SUCCEED : Stop successfully.


 *****************************************************************************/
S32 __inline IBitstreamAudio_stop(IBitstreamAudio *obj,S32 handle)
{
	return obj->vt->gs_bitstream_audio_stop(obj,handle);
}


/*****************************************************************************


 * FUNCTION


 *  IBitstreamAudio_get_play_time


 * DESCRIPTION


 *  This function is to get current play time, accumulation from start_time given in start request.


 * PARAMETERS


 *  handle              : [IN] The audio handle


 *  p_ms_current_time   : [OUT] Current play time


 * RETURN VALUES


 *  GS_RES_BITSTREAM_SUCCEED : Get successfully.


 *****************************************************************************/
S32 __inline IBitstreamAudio_get_play_time(IBitstreamAudio *obj,S32 handle, U32* p_ms_current_time)
{
	return obj->vt->gs_bitstream_audio_get_play_time( obj,handle,  p_ms_current_time);
}



/*****************************************************************************


 * FUNCTION


 *  IBitstreamAudio_get_open_handle_count


 * DESCRIPTION


 *  This function is to get total number of bitstream handle


 * PARAMETERS


 *  void


 * RETURNS


 *  U16 : Number of total opened bitstream audio handle


 *****************************************************************************/
U16 __inline IBitstreamAudio_get_open_handle_count(IBitstreamAudio *obj)
{
	return obj->vt->gs_bitstream_audio_get_open_handle_count(obj);	
}

