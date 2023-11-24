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

#ifndef GS_SRV_FONTENGINE_DATATYPE_H
#define GS_SRV_FONTENGINE_DATATYPE_H

#include "vfx_datatype.h"
#include "vfx_base.h"

#ifdef __MRE_SDK__

typedef struct
{
    VfxU8 *String;   /* String pointer */
    VfxS32 w;        /* gap between character */
    VfxS32 n;        /* character counter to query */
    VfxS32 pWidth;   /* string width */
    VfxS32 pHeight;  /* string height */
    VfxBool enableTruncated; /* truncate or not */
    VfxS32 targetWidth;          /* target width */
    VfxU8 checklinebreak;        /* if need to check new line symbol */
    VfxU8 checkCompleteWord;     /* word wrap or not*/
    VfxS32 baseline;             /* base line */
    VfxS32 maxAscent;            /* max ascent */
    VfxS32 maxDescent;           /* max descent */
    VfxS32 adv_w;                /* advance width */
    VfxS32 adv_h;                /* advance height */
    VfxU8 assign_direction;
}mmi_fe_get_string_info_param_struct, *mmi_fe_get_string_info_param_struct_p;


typedef struct
{
    VfxU32 index;    /* cluster index in text buffer */
    VfxS32 x;        /* cluster x position */
    VfxU8 len;       /* Cluster length */
    VfxU8 width;     /* cluster width. */
    VfxU8 adv_w;     /* cluster adv_w. */
    VfxU8 bidi_type;  /* is arabic char */
}mmi_fe_cluster_metrics_struct, *mmi_fe_cluster_metrics_struct_p;

typedef void (*fe_save_cluster_info_cb) (mmi_fe_cluster_metrics_struct metric, void *user_data);


typedef enum
{
    ON = 0, /* Other Neutral */
    BIDI_L, /* Left Letter */
    BIDI_R, /* Right Letter */
    AN,     /* Arabic Number */
    EN,     /* European Number */
    AL,     /* Arabic Letter (Right-to-left) */
    NSM,    /* Non-spacing Mark */
    CS,     /* Common Separator */
    ES,     /* European Separator */
    ET,     /* European Terminator */
    BN,     /* Boundary neutral */
    S,      /* Segment Separator (TAB)               // used only in L1 */
    WS,     /* White space                                  // used only in L1 */
    BIDI_B,
    RLO,    /* these are used only in X1-X9 */
    RLE,
    LRO,
    LRE,
    PDF,
    N = ON  /* alias, where ON, WS and S are treated the same */
} PMT_BIDI_TYPES;

/*  <group dom_utility_macro> */
#define UI_STRING_GET_NEXT_CHARACTER(p,c)                                                    \
      {                                                                                      \
         c=(UI_character_type)((*((p)+0))|((*((p)+1))<<8));                                  \
         (p)+=2;                                                                             \
      }
/*  <group dom_utility_macro> */
#define UI_STRING_GET_PREVIOUS_CHARACTER(p,c)                                                \
      {                                                                                      \
         p-=2;                                                                               \
         c=(UI_character_type)((*((p)+0))|((*((p)+1))<<8));                                  \
      }
/*  <group dom_utility_macro> */
#define UI_STRING_INSERT_CHARACTER(p,c)                                                      \
      {                                                                                      \
         (*((p))++)=(U8)(((c)&0xff));                                                        \
         (*((p))++)=(U8)(((c)>>8));                                                          \
      }

/*  <group dom_utility_macro> */
#define UI_TEST_CR_CHARACTER1(c)              (((UI_character_type)(c)==(UI_character_type)0x0D)?(1):(0))
/*  <group dom_utility_macro> */
#define UI_TEST_CR_CHARACTER(c)               (((*(UI_character_type*)&(c))==(UI_character_type)0x0D)?(1):(0))
/*  <group dom_utility_macro> */
#define UI_TEST_LF_CHARACTER1(c)              (((UI_character_type)(c)==(UI_character_type)0x0A)?(1):(0))
/*  <group dom_utility_macro> */
#define UI_TEST_LF_CHARACTER(c)               (((*(UI_character_type*)&(c))==(UI_character_type)0x0A || ((c) == 0x2029) || ((c) == 0x2028))?(1):(0))
/*  <group dom_utility_macro> */
#define UI_TEST_ESC_CHARACTER1(c)             (((UI_character_type)(c)==(UI_character_type)0x1B)?(1):(0))
/*  <group dom_utility_macro> */
#define UI_TEST_ESC_CHARACTER(c)              (((*(UI_character_type*)&(c))==(UI_character_type)0x1B)?(1):(0))
/*  <group dom_utility_macro> */
#define UI_TEST_SEMICOLON_CHAR(c)             (((UI_character_type)(c) == 0x003B || (UI_character_type)(c) == 0xff1b)?(1):(0))   /* check if the char is ';'*/

/*  <group dom_utility_macro> */
#define UI_STRING_LINE_BREAK_CHARACTER1(c)    (((UI_character_type)(c)==(UI_character_type)'\n')?(1):(0))
/*  <group dom_utility_macro> */
#define UI_STRING_LINE_BREAK_CHARACTER(c)     (((*(UI_character_type*)&(c))==(UI_character_type)'\n' || ((c) == 0x2029) || ((c) == 0x2028))?(1):(0))                                                                             

/*  <group dom_utility_macro> */
#define UI_STRING_END_OF_STRING_CHARACTER1(c) (((UI_character_type)(c)==(UI_character_type)'\0')?(1):(0))
/*  <group dom_utility_macro> */
#define UI_STRING_END_OF_STRING_CHARACTER(c)  (((*(UI_character_type*)&(c))==(UI_character_type)'\0')?(1):(0))

/*  <group dom_utility_macro> */
#define UI_STRING_SPACE_CHARACTER1(c)         (((UI_character_type)(c)==(UI_character_type)' ')?(1):(0))
/*  <group dom_utility_macro> */
#define UI_STRING_SPACE_CHARACTER(c)          (((*(UI_character_type*)&(c))==(UI_character_type)' ')?(1):(0))
/*  <group dom_utility_macro> */
#define UI_TEST_ASCII_NOT_IN_GSM_DEF_CHAR(c) (((c)==96)?(1):(0))
/*  <group dom_utility_macro> */
#define UI_TEST_8895_1_CHAR_IN_GSM_DEF_CHAR(c)  (((c)==162 ||(c)==163 ||(c)==165 || (c)==232 ||(c)==233 ||(c)==249 ||(c)==236 ||(c)==242 ||(c)==199 ||(c)==216 ||(c)==248 ||(c)==197 ||(c)==229 ||(c)==198 ||(c)==230 ||(c)==223 ||(c)==201 ||(c)==164 ||(c)==161 ||(c)==196 ||(c)==214 ||(c)==209 ||(c)==220 ||(c)==167 ||(c)==191 ||(c)==228 ||(c)==246 ||(c)==241 ||(c)==252 ||(c)==224)?(1):(0))

/* #define UI_TEST_UCS2_CHARACTER(c)            (((((c)&0xff80) && ( !UI_TEST_8895_1_CHAR_IN_GSM_DEF_CHAR(c))) || UI_TEST_ASCII_NOT_IN_GSM_DEF_CHAR(c))?(1):(0)) */
/*  <group dom_utility_macro> */
#define UI_TEST_UCS2_CHARACTER(c)         ((c != 0) && !mmi_7bit_check_gsm_default(c) && !mmi_7bit_check_gsm_ext_character_default(c))
    
/*  <group dom_utility_macro> */
#define UI_TEST_UCS2_INCREMENT_COUNT(c,count)   if(UI_TEST_UCS2_CHARACTER(c)) ((count)++)
/*  <group dom_utility_macro> */
#define UI_TEST_UCS2_DECREMENT_COUNT(c,count)   if(UI_TEST_UCS2_CHARACTER(c) && ((count)>0)) ((count)--)
/*  <group dom_utility_macro> */
#define UI_TEST_ASCII_CHARACTER(c)        (((c) < 0x7f) ? (1) : (0))
/*  <group dom_utility_macro> */
#define UI_TEST_NON_ASCII_INCREMENT_COUNT(c,count)   if(!UI_TEST_ASCII_CHARACTER(c)) ((count)++)
/*  <group dom_utility_macro> */
#define UI_TEST_NON_ASCII_DECREMENT_COUNT(c,count)   if(!UI_TEST_ASCII_CHARACTER(c) && ((count)>0)) ((count)--)
/*  <group dom_utility_macro> */
#define UI_UCS2_STRING_HALF_LENGTH(x)        (((x)&3)?(((x)>>1)+1):((x)>>1))

/*  <group dom_utility_macro>
 *  For Phone Book Name Length */
    // #define UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(x)      (((x)&3)?(((x)>>1)-1):(((x)>>1)-2))
#define UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(x) (((x)&3)?(((x)>>1)-1):(((x)>>1)))
/*  <group dom_utility_macro> */
#define UI_UCS2_STRING_HALF_LENGTH_MINUS_FORTYFOUR(x) (((x)&3)?(((x)>>1)-87):(((x)>>1)-88))
/*  <group dom_utility_macro> */
#define UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(c,count,allocated_length,length)                   \
      {  if(UI_TEST_UCS2_CHARACTER(c))                                                             \
         {  if((count)==0) (length)=UI_UCS2_STRING_HALF_LENGTH(allocated_length);                  \
            (count)++;                                                                             \
         }                                                                                         \
      }

/* <group dom_utility_macro> */
    /* Added for n/2-1 Chinese characters input mode   */
#define UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(c,count,allocated_length,length)                \
      {  if(UI_TEST_UCS2_CHARACTER(c))                                                                \
         {  if((count)==0) (length)=UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(allocated_length);           \
            (count)++;                                                                                \
         }                                                                                            \
      }
/* <group dom_utility_macro> */
    /* Added for n/2-44 Chinese characters input mode  */
#define UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE3(c,count,allocated_length,length)                      \
      {  if(UI_TEST_UCS2_CHARACTER(c))                                                                      \
         {  if((count)==0) (length)=UI_UCS2_STRING_HALF_LENGTH_MINUS_FORTYFOUR(allocated_length);           \
            (count)++;                                                                                      \
         }                                                                                                  \
      }
/*  <group dom_utility_macro> */
#define UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(c,count,allocated_length,length)                   \
      {  if(UI_TEST_UCS2_CHARACTER(c) && ((count)>0))                                              \
         {  ((count)--);                                                                           \
            if((count)==0) (length)=(allocated_length);                                            \
         }                                                                                         \
      }
/*  <group dom_utility_macro> */
#define UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(old_c,c,count,allocated_length,length)                   \
      {  UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(old_c,count,allocated_length,length);                \
         UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(c,count,allocated_length,length);                    \
      }
/* <group dom_utility_macro> */
    /* Added for n/2-1 Chinese characters input mode   */
#define UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(old_c,c,count,allocated_length,length)             \
      {  UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(old_c,count,allocated_length,length);                \
         UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(c,count,allocated_length,length);              \
      }
/* <group dom_utility_macro> */
    /* Added for n/2-44 Chinese characters input mode  */
#define UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE3(old_c,c,count,allocated_length,length)             \
      {  UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(old_c,count,allocated_length,length);                \
         UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE3(c,count,allocated_length,length);              \
      }
/* <group dom_utility_macro> */
#define UI_TEST_UCS2_COUNT_SET_LENGTH(count,allocated_length,length)                            \
      {  if((count)>0) (length)=UI_UCS2_STRING_HALF_LENGTH(allocated_length);                   \
      }
/* <group dom_utility_macro> */
    /* Added for n/2-1 Chinese characters input mode   */
#define UI_TEST_UCS2_COUNT_SET_LENGTH_TYPE2(count,allocated_length,length)                            \
      {  if((count)>0) (length)=UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(allocated_length);               \
      }
/* <group dom_utility_macro> */
    /* Added for n/2-44 Chinese characters input mode  */
#define UI_TEST_UCS2_COUNT_SET_LENGTH_TYPE3(count,allocated_length,length)                                  \
      {  if((count)>0) (length)=UI_UCS2_STRING_HALF_LENGTH_MINUS_FORTYFOUR(allocated_length);               \
      }

#define ENCODING_LENGTH       2
#define FONT_TEST_NEW_LINE_CHAR(c) (((c) == 0x0a || (c) == 0x0d) ? (1) : (0))
#define FONT_TYPE_FIXED_WIDTH                0x80
#else
#endif /* __MRE_SDK__ */

#endif /* GS_SRV_FONTENGINE_DATATYPE_H */
 

