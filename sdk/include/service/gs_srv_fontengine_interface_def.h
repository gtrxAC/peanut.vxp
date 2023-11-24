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

#include "gs_idef.h"
#include "gs_srv_fontengine_datatype.h"

////////////////////////////////////////////////////////////////////////////////////
//
//  IFONTENGINE
//
////////////////////////////////////////////////////////////////////////////////////
#ifdef __MRE_SDK__
#define DEF_METHODS_IFONTENGINE(IOBJ) \
    DEF_METHODS_GS_IBase(IOBJ) \
    DEF_METHOD3(IOBJ, unsigned char, SetFont, stFontAttribute, font, unsigned char, arrCount, int, size_of_font) \
    DEF_METHOD4(IOBJ, void, mmi_fe_get_char_info_of_common_lang, unsigned char, size, int*, pheight, int*, pascent, int*, pdescent) \
    DEF_METHOD2(IOBJ, unsigned char , mmi_fe_get_string_direction, unsigned char*, string, int, len) \
    DEF_METHOD3(IOBJ, void, GetFont, stFontAttribute*, font, unsigned char*, arrCount, int, size_of_font) \
    DEF_METHOD2(IOBJ, unsigned int, mmi_fe_get_string_widthheight, mmi_fe_get_string_info_param_struct_p, query, int, size_of_query) \
    DEF_METHOD5(IOBJ, unsigned int, mmi_fe_get_string_widthheight_ext, mmi_fe_get_string_info_param_struct_p, query, unsigned char*, direction, fe_save_cluster_info_cb, f_save_info, void*, user_data, int, size_of_query) \
    DEF_METHOD8(IOBJ, unsigned int, Get_StringWidthHeight_variant, unsigned char*, string, int, w, int, n, int*, pWidth, int*, pHeight, int, max_width, unsigned char, line_break, unsigned char, completed_word)

#else
#endif

DEF_INTERFACE(IFONTENGINE, GS_IBase)
    DEF_METHODS_IFONTENGINE(IFONTENGINE)
DEF_INTERFACE_END(IFONTENGINE)

