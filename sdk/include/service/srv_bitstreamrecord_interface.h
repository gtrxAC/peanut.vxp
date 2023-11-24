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
 *   srv_bitstreamrecord_interface.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IBitstreamRecord interface
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
#include "gs_srv_bitstreamrecord_interface_def.h"

#include "gs_srv_bitstreamrecord_type.h"

/*****************************************************************************
 * IBitstreamRecord methods
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  IBitstreamRecord_addRef
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 * RETURNS
 *  The error code of the operation.
 *****************************************************************************/
S32 __inline IBitstreamRecord_addRef(IBitstreamRecord *obj)
{
    return obj->vt->addRef(obj);
}


/*****************************************************************************
 * FUNCTION
 *  IBitstreamRecord_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 * RETURNS
 *  The error code of the operation.
 *****************************************************************************/
S32 __inline IBitstreamRecord_release(IBitstreamRecord *obj)
{
    return obj->vt->release(obj);
}


/*****************************************************************************
 * FUNCTION
 *  IBitstreamRecord_queryInterface
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj : [IN] Pointer to object.
 *  iid : [IN]        
 *  pptr : [IN]        
 * RETURNS
 *  The error code of the operation.
 *****************************************************************************/
S32 __inline IBitstreamRecord_queryInterface(IBitstreamRecord *obj, S32 iid, GS_IBase **pptr)
{
    return obj->vt->queryInterface(obj, iid, pptr);
}


/*****************************************************************************
 * FUNCTION
 *  IBitstreamRecord_open
 * DESCRIPTION
 *  This function is to open a record handle for bit-stream record.
 * PARAMETERS
 *  handle_p        [OUT]       Recorder handle.
 *  cfg_p           [IN]        Recorder configuration.
 *  callback        [IN]        Callback function to handle record event.
 * RETURNS
 *  GS_RES_BITSTREAM_SUCCEED   Successful.
 *  Others                      Failed.
 *****************************************************************************/
S32 __inline IBitstreamRecord_open(IBitstreamRecord *obj,S32* handle_p,gs_bitstream_record_cfg_struct* cfg_p,bistream_record_open_handle_result_callback callback)
{
	return obj->vt->gs_bitstream_record_open( obj,handle_p, cfg_p, callback);
}


/*****************************************************************************
 * FUNCTION
 *  IBitstreamRecord_close
 * DESCRIPTION
 *  This function is to close a bit-stream record handle.
 * PARAMETERS
 *  handle_p        [IN]        Recorder handle.
 * RETURNS
 *  GS_RES_BITSTREAM_SUCCEED   Successful.
 *  Others                      Failed.
 *****************************************************************************/
S32 __inline IBitstreamRecord_close(IBitstreamRecord *obj,S32 handle)
{
	return obj->vt->gs_bitstream_record_close(obj, handle);
}


/*****************************************************************************
 * FUNCTION
 *  IBitstreamRecord_start
 * DESCRIPTION
 *  This function is to start bit-stream record process.
 * PARAMETERS
 *  handle_p        [IN]        Recorder handle.
 * RETURNS
 *  GS_RES_BITSTREAM_SUCCEED   Successful.
 *  Others                      Failed.
 *****************************************************************************/
S32 __inline IBitstreamRecord_start(IBitstreamRecord *obj,S32 handle)
{
	return obj->vt->gs_bitstream_record_start( obj,handle);
}


/*****************************************************************************
 * FUNCTION
 *  IBitstreamRecord_stop
 * DESCRIPTION
 *  This function is to stop bit-stream record process.
 * PARAMETERS
 *  handle_p        [IN]        Recorder handle.
 * RETURNS
 *  GS_RES_BITSTREAM_SUCCEED   Successful.
 *  Others                      Failed.
 *****************************************************************************/
S32 __inline IBitstreamRecord_stop(IBitstreamRecord *obj,S32 handle)
{
	return obj->vt->gs_bitstream_record_stop(obj, handle);
}


/*****************************************************************************
 * FUNCTION
 *  IBitstreamRecord_get
 * DESCRIPTION
 *  This function is a general get function to get information in the 
 *  bit-stream recorder.
 * PARAMETERS
 *  handle          [IN]        Recorder handle.
 *  get_type        [IN]        The information to be got.
 *  data_p          [OUT]       Data buffer. The information will be stored to
 *                              the data buffer.
 *  data_len_p      [IN/OUT]    When input, it indicates the length of data buffer. 
 *                              When output, it indicates the length of data that
 *                              is retrieved.
 * RETURNS
 *  GS_RES_BITSTREAM_SUCCEED   Successful.
 *  Others                      Failed.
 *****************************************************************************/
S32 __inline IBitstreamRecord_get(IBitstreamRecord *obj,S32 handle,gs_bitstream_record_get_type_enum get_type,void* data_p,U16* data_len_p)
{
	return obj->vt->gs_bitstream_record_get( obj,handle, get_type, data_p, data_len_p);
}


/*****************************************************************************
 * FUNCTION
 *  IBitstreamRecord_set
 * DESCRIPTION
 *  This function is a general set function to parameter of the bit-stream recorder.
 * PARAMETERS
 *  handle          [IN]        Recorder handle.
 *  set_type        [IN]        The type of the parameter to be set.
 *  data_p          [IN]        Data buffer. The data in the data buffer will be
 *                              set to bit-stream recorder.
 *  data_len        [IN]        The length of data. Note that the length of data
 *                              should be equal to the length of the parameter to
 *                              be set.
 * RETURNS
 *  GS_RES_BITSTREAM_SUCCEED   Successful.
 *  Others                      Failed.
 *****************************************************************************/
S32 __inline IBitstreamRecord_set(IBitstreamRecord *obj,S32 handle,gs_bitstream_record_set_type_enum set_type,void* data_p,U16 data_len)
{
	return obj->vt->gs_bitstream_record_set( obj,handle, set_type, data_p, data_len);
}




