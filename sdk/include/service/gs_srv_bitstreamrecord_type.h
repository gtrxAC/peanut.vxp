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
 *   gs_srv_bitstreamrecord_type.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IBitstreamRecord type header file
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
 * 10 28 2011 ruifang.qin
 * [MAUI_03065819] Record related API check in
 * .
 *
 * 10 26 2011 ruifang.qin
 * [MAUI_03056708] Record related API check in
 * .
 *
 * 10 20 2011 ruifang.qin
 * [MAUI_03056708] Record related API check in
 * .
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
#ifndef _GS_SRV_BITSTREAMRECORD_TYPE_
#define _GS_SRV_BITSTREAMRECORD_TYPE_


typedef void (*bistream_record_open_handle_result_callback)(S32 handle, S32 result);

typedef struct
{ 
    U16 codec_type;  /* gs_bitstream_codec_type_enum */
    U16 quality;     /* gs_bitstream_rec_quality_enum */
} gs_bitstream_record_cfg_struct;

/* Bitstream record quality */
typedef enum
{
    GS_BITSTREAM_RECORD_QUALITY_LOW,   /* Low quality */
    GS_BITSTREAM_RECORD_QUALITY_MED,   /* Reserved */
    GS_BITSTREAM_RECORD_QUALITY_HIGH,  /* High quality */
    GS_BITSTREAM_RECORD_QUALITY_BEST,  /* Reserved */

    /* For GS_BITSTREAM_CODEC_TYPE_AMR only */
    GS_BITSTREAM_RECORD_AMR_4_75,      /* AMR 4.75 kbit/s */
    GS_BITSTREAM_RECORD_AMR_5_15,      /* AMR 5.15 kbit/s */
    GS_BITSTREAM_RECORD_AMR_5_9,       /* AMR 5.9  kbit/s */
    GS_BITSTREAM_RECORD_AMR_6_7,       /* AMR 6.7  kbit/s */
    GS_BITSTREAM_RECORD_AMR_7_4,       /* AMR 7.4  kbit/s */
    GS_BITSTREAM_RECORD_AMR_7_95,      /* AMR 7.95 kbit/s */
    GS_BITSTREAM_RECORD_AMR_10_2,      /* AMR 10.2 kbit/s */
    GS_BITSTREAM_RECORD_AMR_12_2       /* AMR 12.2 kbit/s */
} gs_bitstream_rec_quality_enum;

/* Get type of bitstream recorder */
typedef enum
{ 
    GS_BITSTREAM_RECORD_GET_LENGTH, /* Get the length of recorded data(U16*) */
    GS_BITSTREAM_RECORD_GET_DATA,    /* Get recorded data(U16*) */
    GS_BITSTREAM_RECORD_GET_STRENGTH /* Get current data strengh value*/
} gs_bitstream_record_get_type_enum;

/* Set type of bitstream recorder */
typedef enum
{ 
    GS_BITSTREAM_RECORD_SET_PAUSE,  /* Pause bitstream record */
    GS_BITSTREAM_RECORD_SET_RESUME,  /* Resume bitstream record */
    GS_BITSTREAM_RECORD_SET_CB_THRESHOLD /* Set callback threshold: default is 200 (words), pass the address of a U32 to data_p*/
} gs_bitstream_record_set_type_enum;



#endif 
