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
 *   gs_srv_mms_type.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IUm type header file
 *
 * Author:
 * -------
 *  Jia Luo
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 26 2010 jia.luo
 * [MAUI_02642061] [VRE4.0]AVK check in
 * [gs interface].
 *
 * 12 23 2010 lihong.li
 * NULL
 * .
 *
 * 12 16 2010 lihong.li
 * NULL
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _GS_SRV_MMS_TYPE_
#define _GS_SRV_MMS_TYPE_

#define GS_MAX_MMS_APP_NAME_LEN  100

typedef enum
{
    GS_MMS_CANCEL = -3,						 /*user cancelled sending*/
    GS_MMS_FAIL = -2,                        /*operation request error*/     
    GS_MMS_MEMORY_NOT_ENOUGH = -1,    		 /*not enough memory*/
    GS_MMS_SUCCESS							 /*operation successfully*/
 }gs_mms_result_enum;

typedef enum
{
	GS_MMS_TYPE_SMIL_MMS = 0,       			 /*SMIL type of XML */
	GS_MMS_TYPE_MIXED_MMS          				 /*MIXED type of XML */
}gs_mms_type_enum;

typedef enum
{
	GS_MMS_SIM_ID_SIM1 = 1,          			 	 /*sim1 card */
	GS_MMS_SIM_ID_SIM2                 				 /*sim2 card */
}gs_mms_sim_id_enum;

typedef struct
{
	WCHAR xml_filepath[GS_MAX_MMS_APP_NAME_LEN];/*XML file path*/
	U32 xml_size;							 /*XML file size*/
	U8 mms_type;                    		 /*refer to gs_mms_type_enum*/
	U8 sim_id;                        		 /*refer to gs_mms_sim_id_enum*/
}gs_send_mms_req_t;


/*****************************************************************************
* <GROUP  CallBackFunctions>        
*
 * FUNCTION
 *    gs_mms_callback_type
 * DESCRIPTION
 *  MMS callback function 
 * PARAMETERS
 *  result :  [IN]  refer to gs_mms_result_enum.
*****************************************************************************/
typedef void (*gs_mms_callback_type)(S32  result);

#endif //_GS_SRV_MMS_TYPE_


