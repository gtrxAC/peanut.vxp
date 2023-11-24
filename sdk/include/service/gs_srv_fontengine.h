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

#ifdef __MRE_SDK__
 
#include "gs_base.h"
 
#define GS_C_INTERFACE
#include "gs_srv_fontengine_interface_def.h"

#ifdef __cplusplus
extern "C"
{
#endif

extern IFONTENGINE       *vfx_get_font_srv(void);

#ifdef  __cplusplus
}
#endif


#define VFX_FONT_SRV     vfx_get_font_srv()

#define FONT_SRV_CALL0(method)                  (VFX_FONT_SRV->vt->method(VFX_FONT_SRV))
#define FONT_SRV_CALL1(method, arg1)            (VFX_FONT_SRV->vt->method(VFX_FONT_SRV, arg1))
#define FONT_SRV_CALL2(method, arg1, arg2)      (VFX_FONT_SRV->vt->method(VFX_FONT_SRV, arg1, arg2))
#define FONT_SRV_CALL3(method, arg1, arg2, arg3)      (VFX_FONT_SRV->vt->method(VFX_FONT_SRV, arg1, arg2, arg3))
#define FONT_SRV_CALL4(method, arg1, arg2, arg3, arg4)      (VFX_FONT_SRV->vt->method(VFX_FONT_SRV, arg1, arg2, arg3, arg4))
#define FONT_SRV_CALL5(method, arg1, arg2, arg3, arg4, arg5)      (VFX_FONT_SRV->vt->method(VFX_FONT_SRV, arg1, arg2, arg3, arg4, arg5))
#define FONT_SRV_CALL6(method, arg1, arg2, arg3, arg4, arg5, arg6)      (VFX_FONT_SRV->vt->method(VFX_FONT_SRV, arg1, arg2, arg3, arg4, arg5, arg6))
#define FONT_SRV_CALL7(method, arg1, arg2, arg3, arg4, arg5, arg6, arg7)      (VFX_FONT_SRV->vt->method(VFX_FONT_SRV, arg1, arg2, arg3, arg4, arg5, arg6, arg7))
#define FONT_SRV_CALL8(method, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)      (VFX_FONT_SRV->vt->method(VFX_FONT_SRV, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8))
#define FONT_SRV_CALL9(method, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9)      (VFX_FONT_SRV->vt->method(VFX_FONT_SRV, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9))



#define mmi_fe_get_char_info_of_common_lang(size, pHeight, pAscent, pDescent)               FONT_SRV_CALL4(mmi_fe_get_char_info_of_common_lang, size, pHeight, pAscent, pDescent)
#define SetFont(Font, arrCount)                                                             FONT_SRV_CALL3(SetFont, Font, arrCount, sizeof(Font))
#define mmi_fe_get_string_direction(string, len)                                            FONT_SRV_CALL2(mmi_fe_get_string_direction, string, len)
#define GetFont(Font, arrCount)                                                             FONT_SRV_CALL3(GetFont, Font, arrCount, sizeof(*Font))
#define mmi_fe_get_string_widthheight(query)                                                FONT_SRV_CALL2(mmi_fe_get_string_widthheight, query, sizeof(*query))
#define mmi_fe_get_string_widthheight_ext(query, m_direction, proc, data)                   FONT_SRV_CALL5(mmi_fe_get_string_widthheight_ext, query, m_direction, proc, data, sizeof(*query))
#define Get_StringWidthHeight_variant(string, w, n, pWidth, pHeight, max_width, checkLineBreak, checkCompleteWord)     FONT_SRV_CALL8(Get_StringWidthHeight_variant, string, w, n, pWidth, pHeight, max_width, checkLineBreak, checkCompleteWord)
#endif /* __MRE_SDK__ */
 

