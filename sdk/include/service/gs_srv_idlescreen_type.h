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
 *   gs_srv_idlescreen_type.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IIdleScreen type header file
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
#ifndef _GS_SRV_IDLESCREEN_TYPE_
#define _GS_SRV_IDLESCREEN_TYPE_

typedef enum
{
    GS_SIM_NONE = 0, /* No bit-wise operation for none case */
    GS_SIM1 = 0x0001,
    GS_SIM2 = 0x0002,
    GS_SIM_END_OF_ENUM
}gs_sim_enum;


typedef enum
{
    /* Network name from EONS. */
    NW_NAME_TYPE_EONS,

    /* Network name from NITZ. */
    NW_NAME_TYPE_NITZ,

    /* Network name from CPHS. */
    NW_NAME_TYPE_CPHS,

    /* Network name from ME ROM. */
    NW_NAME_TYPE_ROM,

    /* End of enum. */
    NW_NAME_TYPE_TOTAL
} nw_name_type_enum;


#define SRV_MAX_PLMN_LEN 6
typedef struct
{
    char plmn[SRV_MAX_PLMN_LEN + 1];    /* Network PLMN */
    U16 lac;                            /* LAC */
    U16 cell_id;                        /* Cell ID. */
} nw_info_location_info_struct;


#define EONS_MAX_STR_LEN            (28)

#define EONS_MAX_BUF_SIZE           (EONS_MAX_STR_LEN + 1)

typedef struct
{
    /* SIM associated with the name. */
    gs_sim_enum sim;
    
    /* The full name of the operator. */
    WCHAR full_name[EONS_MAX_BUF_SIZE];

    /* The short name of the operator. */
    WCHAR short_name[EONS_MAX_BUF_SIZE];
} eons_name_struct;


typedef void (*eons_get_name_cb)(
                const eons_name_struct *name, 
                void *user_data);


#endif /* _GS_SRV_IDLESCREEN_TYPE_ */ 

