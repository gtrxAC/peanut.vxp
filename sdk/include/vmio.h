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

#ifndef VMIO_SDK_H_
#define VMIO_SDK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "vmsim.h"
#include "vmtel.h"

#ifndef MAX_APP_NAME_LEN
#define MAX_APP_NAME_LEN					(260)
#endif

typedef enum 
{
	VM_FILE_COMMIT_ERROR = -1,
	VM_FILE_OPEN_ERROR = -2,
	VM_FILE_NAME_ERROR = -1,
	VM_FILE_OK = 0
} vm_file_error_t;

typedef enum
{
      VM_STORE_PATH_TYPE_PHOTO,
      VM_STORE_PATH_TYPE_VIDEO,
      VM_STORE_PATH_TYPE_MUSIC,
      VM_STORE_PATH_TYPE_RINGTONE,
      VM_STORE_PATH_TYPE_DOCUMENT,
      VM_STORE_PATH_TYPE_OTHERS

} VM_STORE_PATH_TYPE;


/* Key events supported by MRE. */

#define VM_KEY_EVENT_UP       (1)       /* Key up event */
#define VM_KEY_EVENT_DOWN        (2)    /* Key down event */
#define VM_KEY_EVENT_LONG_PRESS  (3)    /* Key long press event */
#define VM_KEY_EVENT_REPEAT      (4)    /* Key repeat event */

/* Key codes supported by MRE. */

#define VM_KEY_UP             (-1)      /* Arrow key up */
#define VM_KEY_DOWN           (-2)      /* Arrow key down */
#define VM_KEY_LEFT              (-3)   /* Arrow key left */
#define VM_KEY_RIGHT          (-4)      /* Arrow key right */
#define VM_KEY_LEFT_SOFTKEY      (-6)   /* Left soft key */
#define VM_KEY_RIGHT_SOFTKEY     (-7)   /* Right soft key */
#define VM_KEY_OK             (-5)      /* OK key */
#define VM_KEY_CLEAR          (-8)      /* Clear key */
#define VM_KEY_BACK              (-9)   /* Back key */
#define VM_KEY_NUM0           (48)      /* Number key 0 */
#define VM_KEY_NUM1           (49)      /* Number key 1 */
#define VM_KEY_NUM2           (50)      /* Number key 2 */
#define VM_KEY_NUM3           (51)      /* Number key 3 */
#define VM_KEY_NUM4           (52)      /* Number key 4 */
#define VM_KEY_NUM5           (53)      /* Number key 5 */
#define VM_KEY_NUM6           (54)      /* Number key 6 */
#define VM_KEY_NUM7           (55)      /* Number key 7 */
#define VM_KEY_NUM8           (56)      /* Number key 8 */
#define VM_KEY_NUM9           (57)      /* Number key 9 */
#define VM_KEY_VOL_UP            (58)   /* Volume key up */
#define VM_KEY_VOL_DOWN       (59)      /* Volume key down */
#define VM_KEY_POUND          (35)      /* Key # */
#define VM_KEY_STAR              (42)   /* Key * */

/* Key codes from A to Z on a qwerty keypad, each code represents the Unicode value of the corresponding capital letter. */
#define  VM_KEY_A 65    /* A */
#define  VM_KEY_B 66    /* B */
#define  VM_KEY_C 67    /* C */
#define  VM_KEY_D 68    /* D */
#define  VM_KEY_E 69    /* E */
#define  VM_KEY_F 70    /* F */
#define  VM_KEY_G 71    /* G */
#define  VM_KEY_H 72    /* H */
#define  VM_KEY_I 73    /* I */
#define  VM_KEY_J 74    /* J */
#define  VM_KEY_K 75    /* K */
#define  VM_KEY_L 76    /* L */
#define  VM_KEY_M 77    /* M */
#define  VM_KEY_N 78    /* N */
#define  VM_KEY_O 79    /* O */
#define  VM_KEY_P 80    /* P */
#define  VM_KEY_Q 81    /* Q */
#define  VM_KEY_R 82    /* R */
#define  VM_KEY_S 83    /* S */
#define  VM_KEY_T 84    /* T */
#define  VM_KEY_U 85    /* U */
#define  VM_KEY_V 86    /* V */
#define  VM_KEY_W 87    /* W */
#define  VM_KEY_X 88    /* X */
#define  VM_KEY_Y 89    /* Y */
#define  VM_KEY_Z 90    /* Z */
#define  VM_KEY_SPACE 91    /* Space */
#define  VM_KEY_TAB 92    /* Tab */
#define  VM_KEY_DEL 93    /* Delete */
#define  VM_KEY_ALT 94    /* Alt */
#define  VM_KEY_CTRL 95    /* Ctrl */
#define  VM_KEY_WIN 96    /* Winodows key */
#define  VM_KEY_SHIFT 97    /* Shift */
#define  VM_KEY_QUESTION 98    /* Question */
#define  VM_KEY_PERIOD 99    /* Period */
#define  VM_KEY_COMMA 100    /* Comma (,) */
#define  VM_KEY_EXCLAMATION 101    /* Exclamation (!) */
#define  VM_KEY_APOSTROPHE 102    /* Apostrophe (') */
#define  VM_KEY_AT 103    /* @ */
#define  VM_KEY_BACKSPACE 104    /* Backspace */
#define  VM_KEY_QWERTY_ENTER 105    /* Qwerty enter */
#define  VM_KEY_FN 106    /* Function */
#define  VM_KEY_SYMBOL 107    /* Symbol */
#define  VM_KEY_NUM_LOCK 108    /* Number lock */
#define  VM_KEY_QWERTY_MENU 109    /* Qwerty menu */


typedef enum
{
VM_INPUT_MODE_NONE = 0,
VM_INPUT_MODE_123,
VM_INPUT_MODE_123_SYMBOLS,
/* English */
VM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_ABC,
VM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC,
VM_INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC,
/* The above 6 input modes are used by Q03C WCSS editor, and the
 * editor requires the input modes values are smaller than 0x1F,
 * so we should make sure the input modes used in UI_check_WCSS_normal_character() 
 * of gui_inputs.c are smaller than 0x1F
 */
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ABC, 
VM_INPUT_MODE_SMART_LOWERCASE_ABC, 
VM_INPUT_MODE_SMART_UPPERCASE_ABC, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_ABC,

VM_INPUT_MODE_ARABIC_NUMERIC,
VM_INPUT_MODE_FLOAT_123,
VM_INPUT_MODE_HK_STROKE,    
VM_INPUT_MODE_KEYPAD_NUMERIC,
VM_INPUT_MODE_MAGIC_NUMBER,
VM_INPUT_MODE_PHONE_NUMBER,
VM_INPUT_MODE_PHONE_NUMBER_WILDCHAR,
VM_INPUT_MODE_SIGNED_123,
VM_INPUT_MODE_SIGNED_FLOAT_123,
VM_INPUT_MODE_SIM_NUMERIC,

/*Afrikaans*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_AFRIKAANS,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_AFRIKAANS,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_AFRIKAANS, 
VM_INPUT_MODE_SMART_LOWERCASE_AFRIKAANS, 
VM_INPUT_MODE_SMART_UPPERCASE_AFRIKAANS, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_AFRIKAANS,
/*Albanian*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_ALBANIAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_ALBANIAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ALBANIAN, 
VM_INPUT_MODE_SMART_LOWERCASE_ALBANIAN, 
VM_INPUT_MODE_SMART_UPPERCASE_ALBANIAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_ALBANIAN,
/*Armenian*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_ARMENIAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_ARMENIAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ARMENIAN, 
VM_INPUT_MODE_SMART_LOWERCASE_ARMENIAN, 
VM_INPUT_MODE_SMART_UPPERCASE_ARMENIAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_ARMENIAN,
/*Arabic*/
VM_INPUT_MODE_MULTITAP_ARABIC,    
VM_INPUT_MODE_SMART_ARABIC,
/*Assamese*/
VM_INPUT_MODE_MULTITAP_ASSAMESE,    
VM_INPUT_MODE_SMART_ASSAMESE,
/*Azerbaijani*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_AZERBAIJANI,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_AZERBAIJANI,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_AZERBAIJANI, 
VM_INPUT_MODE_SMART_LOWERCASE_AZERBAIJANI, 
VM_INPUT_MODE_SMART_UPPERCASE_AZERBAIJANI, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_AZERBAIJANI,
/*Basque*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_BASQUE,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_BASQUE,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_BASQUE, 
VM_INPUT_MODE_SMART_LOWERCASE_BASQUE, 
VM_INPUT_MODE_SMART_UPPERCASE_BASQUE, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_BASQUE,
/*Bengali*/
VM_INPUT_MODE_MULTITAP_BENGALI,    
VM_INPUT_MODE_SMART_BENGALI,
/*Bulgarian*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_BULGARIAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_BULGARIAN, 
VM_INPUT_MODE_SMART_LOWERCASE_BULGARIAN, 
VM_INPUT_MODE_SMART_UPPERCASE_BULGARIAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_BULGARIAN,
/*Catalan*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_CATALAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_CATALAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CATALAN, 
VM_INPUT_MODE_SMART_LOWERCASE_CATALAN, 
VM_INPUT_MODE_SMART_UPPERCASE_CATALAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_CATALAN,
/*Croatian*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_CROATIAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CROATIAN, 
VM_INPUT_MODE_SMART_LOWERCASE_CROATIAN, 
VM_INPUT_MODE_SMART_UPPERCASE_CROATIAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_CROATIAN,
/*Czech*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_CZECH,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_CZECH,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CZECH, 
VM_INPUT_MODE_SMART_LOWERCASE_CZECH, 
VM_INPUT_MODE_SMART_UPPERCASE_CZECH, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_CZECH,
/*Danish*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_DANISH,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_DANISH,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_DANISH, 
VM_INPUT_MODE_SMART_LOWERCASE_DANISH, 
VM_INPUT_MODE_SMART_UPPERCASE_DANISH, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_DANISH,
/*Dutch*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_DUTCH,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_DUTCH,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_DUTCH, 
VM_INPUT_MODE_SMART_LOWERCASE_DUTCH, 
VM_INPUT_MODE_SMART_UPPERCASE_DUTCH, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_DUTCH,
/*Estonian*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_ESTONIAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_ESTONIAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ESTONIAN, 
VM_INPUT_MODE_SMART_LOWERCASE_ESTONIAN, 
VM_INPUT_MODE_SMART_UPPERCASE_ESTONIAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_ESTONIAN,
/*Filipino*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_FILIPINO,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_FILIPINO,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FILIPINO, 
VM_INPUT_MODE_SMART_LOWERCASE_FILIPINO, 
VM_INPUT_MODE_SMART_UPPERCASE_FILIPINO, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_FILIPINO,
/*Finnish*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_FINNISH,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_FINNISH,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FINNISH, 
VM_INPUT_MODE_SMART_LOWERCASE_FINNISH, 
VM_INPUT_MODE_SMART_UPPERCASE_FINNISH, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_FINNISH,
/*French*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_FRENCH,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_FRENCH,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FRENCH, 
VM_INPUT_MODE_SMART_LOWERCASE_FRENCH, 
VM_INPUT_MODE_SMART_UPPERCASE_FRENCH, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_FRENCH,
/*Galician*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_GALICIAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_GALICIAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GALICIAN, 
VM_INPUT_MODE_SMART_LOWERCASE_GALICIAN, 
VM_INPUT_MODE_SMART_UPPERCASE_GALICIAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_GALICIAN,
/*Georgian*/
VM_INPUT_MODE_MULTITAP_GEORGIAN,    
VM_INPUT_MODE_SMART_GEORGIAN,
/*German*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_GERMAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_GERMAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GERMAN, 
VM_INPUT_MODE_SMART_LOWERCASE_GERMAN, 
VM_INPUT_MODE_SMART_UPPERCASE_GERMAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_GERMAN,
/*Greek*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_GREEK,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_GREEK,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GREEK, 
VM_INPUT_MODE_SMART_LOWERCASE_GREEK, 
VM_INPUT_MODE_SMART_UPPERCASE_GREEK, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_GREEK,
/*Gujarati*/
VM_INPUT_MODE_MULTITAP_GUJARATI,    
VM_INPUT_MODE_SMART_GUJARATI,
/*Hausa*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_HAUSA,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_HAUSA,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_HAUSA, 
VM_INPUT_MODE_SMART_LOWERCASE_HAUSA, 
VM_INPUT_MODE_SMART_UPPERCASE_HAUSA, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_HAUSA,
/*Hebrew*/
VM_INPUT_MODE_MULTITAP_HEBREW,    
VM_INPUT_MODE_SMART_HEBREW,
/*Hindi*/
VM_INPUT_MODE_MULTITAP_HINDI,    
VM_INPUT_MODE_SMART_HINDI,
/*Hungarian*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_HUNGARIAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_HUNGARIAN, 
VM_INPUT_MODE_SMART_LOWERCASE_HUNGARIAN, 
VM_INPUT_MODE_SMART_UPPERCASE_HUNGARIAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_HUNGARIAN,
/*Icelandic*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_ICELANDIC,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_ICELANDIC,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ICELANDIC, 
VM_INPUT_MODE_SMART_LOWERCASE_ICELANDIC, 
VM_INPUT_MODE_SMART_UPPERCASE_ICELANDIC, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_ICELANDIC,
/*Igbo*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_IGBO,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_IGBO,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_IGBO, 
VM_INPUT_MODE_SMART_LOWERCASE_IGBO, 
VM_INPUT_MODE_SMART_UPPERCASE_IGBO, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_IGBO,
/*Indonesian*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_INDONESIAN, 
VM_INPUT_MODE_SMART_LOWERCASE_INDONESIAN, 
VM_INPUT_MODE_SMART_UPPERCASE_INDONESIAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_INDONESIAN,
/*Irish*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_IRISH,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_IRISH,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_IRISH, 
VM_INPUT_MODE_SMART_LOWERCASE_IRISH, 
VM_INPUT_MODE_SMART_UPPERCASE_IRISH, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_IRISH,
/*Italian*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ITALIAN, 
VM_INPUT_MODE_SMART_LOWERCASE_ITALIAN, 
VM_INPUT_MODE_SMART_UPPERCASE_ITALIAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_ITALIAN,
/*Kannada*/
VM_INPUT_MODE_MULTITAP_KANNADA,    
VM_INPUT_MODE_SMART_KANNADA,
/*Kazakh*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_KAZAKH,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_KAZAKH,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_KAZAKH, 
VM_INPUT_MODE_SMART_LOWERCASE_KAZAKH, 
VM_INPUT_MODE_SMART_UPPERCASE_KAZAKH, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_KAZAKH,
VM_INPUT_MODE_MULTITAP_KOREAN,
/*Latvian*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_LATVIAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_LATVIAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_LATVIAN, 
VM_INPUT_MODE_SMART_LOWERCASE_LATVIAN, 
VM_INPUT_MODE_SMART_UPPERCASE_LATVIAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_LATVIAN,
/*Lithuanian*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_LITHUANIAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_LITHUANIAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_LITHUANIAN, 
VM_INPUT_MODE_SMART_LOWERCASE_LITHUANIAN, 
VM_INPUT_MODE_SMART_UPPERCASE_LITHUANIAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_LITHUANIAN,
/*Macedonian*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_MACEDONIAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_MACEDONIAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MACEDONIAN, 
VM_INPUT_MODE_SMART_LOWERCASE_MACEDONIAN, 
VM_INPUT_MODE_SMART_UPPERCASE_MACEDONIAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_MACEDONIAN,
/*Malay*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_MALAY,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_MALAY,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MALAY, 
VM_INPUT_MODE_SMART_LOWERCASE_MALAY, 
VM_INPUT_MODE_SMART_UPPERCASE_MALAY, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_MALAY,
/*Malayalam*/
VM_INPUT_MODE_MULTITAP_MALAYALAM,    
VM_INPUT_MODE_MULTITAP_LAO,
VM_INPUT_MODE_MULTITAP_KHMER,
VM_INPUT_MODE_SMART_KHMER,
VM_INPUT_MODE_MULTITAP_MYANMAR,
VM_INPUT_MODE_SMART_MALAYALAM,
/*Marathi*/
VM_INPUT_MODE_MULTITAP_MARATHI,    
VM_INPUT_MODE_SMART_MARATHI,
/*Moldovan*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_MOLDOVAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_MOLDOVAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MOLDOVAN, 
VM_INPUT_MODE_SMART_LOWERCASE_MOLDOVAN, 
VM_INPUT_MODE_SMART_UPPERCASE_MOLDOVAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_MOLDOVAN,
/*Norwegian*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_NORWEGIAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_NORWEGIAN, 
VM_INPUT_MODE_SMART_LOWERCASE_NORWEGIAN, 
VM_INPUT_MODE_SMART_UPPERCASE_NORWEGIAN,
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_NORWEGIAN,
/*Oriya*/
VM_INPUT_MODE_MULTITAP_ORIYA,    
VM_INPUT_MODE_SMART_ORIYA,
/*Persian*/ 
VM_INPUT_MODE_MULTITAP_PERSIAN,    
VM_INPUT_MODE_SMART_PERSIAN,
/*Polish*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_POLISH,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_POLISH,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_POLISH, 
VM_INPUT_MODE_SMART_LOWERCASE_POLISH, 
VM_INPUT_MODE_SMART_UPPERCASE_POLISH, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_POLISH,
/*Portuguese*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_PORTUGUESE, 
VM_INPUT_MODE_SMART_LOWERCASE_PORTUGUESE, 
VM_INPUT_MODE_SMART_UPPERCASE_PORTUGUESE, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_PORTUGUESE,
/*Punjabi*/
VM_INPUT_MODE_MULTITAP_PUNJABI,    
VM_INPUT_MODE_SMART_PUNJABI,
/*Romanian*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_ROMANIAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ROMANIAN, 
VM_INPUT_MODE_SMART_LOWERCASE_ROMANIAN, 
VM_INPUT_MODE_SMART_UPPERCASE_ROMANIAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_ROMANIAN,
/*Russian*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_RUSSIAN, 
VM_INPUT_MODE_SMART_LOWERCASE_RUSSIAN, 
VM_INPUT_MODE_SMART_UPPERCASE_RUSSIAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_RUSSIAN,
/*Serbian*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_SERBIAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_SERBIAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SERBIAN, 
VM_INPUT_MODE_SMART_LOWERCASE_SERBIAN, 
VM_INPUT_MODE_SMART_UPPERCASE_SERBIAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_SERBIAN,
/*Sesotho*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_SESOTHO,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_SESOTHO,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SESOTHO, 
VM_INPUT_MODE_SMART_LOWERCASE_SESOTHO, 
VM_INPUT_MODE_SMART_UPPERCASE_SESOTHO, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_SESOTHO,
/*Slovak*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVAK,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SLOVAK, 
VM_INPUT_MODE_SMART_LOWERCASE_SLOVAK, 
VM_INPUT_MODE_SMART_UPPERCASE_SLOVAK, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_SLOVAK,
/*Slovenian*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVENIAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SLOVENIAN, 
VM_INPUT_MODE_SMART_LOWERCASE_SLOVENIAN, 
VM_INPUT_MODE_SMART_UPPERCASE_SLOVENIAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_SLOVENIAN,
/*Spanish*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_SPANISH,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_SPANISH,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SPANISH, 
VM_INPUT_MODE_SMART_LOWERCASE_SPANISH, 
VM_INPUT_MODE_SMART_UPPERCASE_SPANISH, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_SPANISH,
/*Swahili*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_SWAHILI,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_SWAHILI,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SWAHILI, 
VM_INPUT_MODE_SMART_LOWERCASE_SWAHILI, 
VM_INPUT_MODE_SMART_UPPERCASE_SWAHILI, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_SWAHILI,
/*Swedish*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_SWEDISH,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SWEDISH, 
VM_INPUT_MODE_SMART_LOWERCASE_SWEDISH, 
VM_INPUT_MODE_SMART_UPPERCASE_SWEDISH, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_SWEDISH,
/*Tagalog*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_TAGALOG,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_TAGALOG,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_TAGALOG, 
VM_INPUT_MODE_SMART_LOWERCASE_TAGALOG, 
VM_INPUT_MODE_SMART_UPPERCASE_TAGALOG, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_TAGALOG,
/*Tamil*/
VM_INPUT_MODE_MULTITAP_TAMIL,    
VM_INPUT_MODE_SMART_TAMIL,
/*Telugu*/
VM_INPUT_MODE_MULTITAP_TELUGU,    
VM_INPUT_MODE_SMART_TELUGU,
/*Thai*/
VM_INPUT_MODE_MULTITAP_THAI,    
VM_INPUT_MODE_SMART_THAI,
/*Turkish*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_TURKISH,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_TURKISH,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_TURKISH, 
VM_INPUT_MODE_SMART_LOWERCASE_TURKISH, 
VM_INPUT_MODE_SMART_UPPERCASE_TURKISH, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_TURKISH,
/*Ukrainian*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_UKRAINIAN,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_UKRAINIAN, 
VM_INPUT_MODE_SMART_LOWERCASE_UKRAINIAN, 
VM_INPUT_MODE_SMART_UPPERCASE_UKRAINIAN, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_UKRAINIAN,
/*Urdu*/
VM_INPUT_MODE_MULTITAP_URDU,    
VM_INPUT_MODE_SMART_URDU,
/*Vietnamese*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_VIETNAMESE, 
VM_INPUT_MODE_SMART_LOWERCASE_VIETNAMESE, 
VM_INPUT_MODE_SMART_UPPERCASE_VIETNAMESE, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_VIETNAMESE,
/*Xhosa*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_XHOSA,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_XHOSA,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_XHOSA, 
VM_INPUT_MODE_SMART_LOWERCASE_XHOSA, 
VM_INPUT_MODE_SMART_UPPERCASE_XHOSA, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_XHOSA,
/*Yoruba*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_YORUBA,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_YORUBA,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_YORUBA, 
VM_INPUT_MODE_SMART_LOWERCASE_YORUBA, 
VM_INPUT_MODE_SMART_UPPERCASE_YORUBA, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_YORUBA,
/*Zulu*/ 
VM_INPUT_MODE_MULTITAP_UPPERCASE_ZULU,    
VM_INPUT_MODE_MULTITAP_LOWERCASE_ZULU,
VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ZULU, 
VM_INPUT_MODE_SMART_LOWERCASE_ZULU, 
VM_INPUT_MODE_SMART_UPPERCASE_ZULU, 
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_ZULU,

/* Dialects */
VM_INPUT_MODE_SMART_UPPERCASE_UK_ABC,
VM_INPUT_MODE_SMART_LOWERCASE_UK_ABC,
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_UK_ABC,
VM_INPUT_MODE_SMART_UPPERCASE_CA_FRENCH,
VM_INPUT_MODE_SMART_LOWERCASE_CA_FRENCH,
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_CA_FRENCH,
VM_INPUT_MODE_SMART_UPPERCASE_HINGLISH,
VM_INPUT_MODE_SMART_LOWERCASE_HINGLISH,
VM_INPUT_MODE_SMART_UPPERCASE_SA_SPANISH,
VM_INPUT_MODE_SMART_LOWERCASE_SA_SPANISH,
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_SA_SPANISH,
VM_INPUT_MODE_SMART_UPPERCASE_SA_PORTUGUESE,
VM_INPUT_MODE_SMART_LOWERCASE_SA_PORTUGUESE,
VM_INPUT_MODE_SMART_FIRST_UPPERCASE_SA_PORTUGUESE,

/* Chinese*/
VM_INPUT_MODE_TR_BOPOMO,
VM_INPUT_MODE_TR_MULTITAP_BOPOMO,
VM_INPUT_MODE_TR_STROKE,
VM_INPUT_MODE_QUICK_SEARCH_BOPOMO,
VM_INPUT_MODE_QUICK_SEARCH_HK_STROKE,    
VM_INPUT_MODE_QUICK_SEARCH_PINYIN,
VM_INPUT_MODE_QUICK_SEARCH_SM_STROKE,
VM_INPUT_MODE_QUICK_SEARCH_TR_STROKE,
VM_INPUT_MODE_SM_MULTITAP_PINYIN,
VM_INPUT_MODE_SM_PINYIN,
VM_INPUT_MODE_SM_STROKE,

VM_INPUT_MODE_MAX_NUM
} vm_input_mode_enum;

/*
 * file attribution
 */
#define VM_FS_ATTR_READ_ONLY        	0x01
#define VM_FS_ATTR_HIDDEN           	0x02
#define VM_FS_ATTR_SYSTEM           	0x04
#define VM_FS_ATTR_VOLUME          	0x08
#define VM_FS_ATTR_DIR              		0x10
#define VM_FS_ATTR_ARCHIVE          	0x20
#define VM_FS_LONGNAME_ATTR         	0x0F

/* file info */
struct vm_fileinfo_t
{
	VMWCHAR filename[MAX_APP_NAME_LEN]; /* full path of file */
	VMINT size; /* file size */
};

/* file info */
typedef  struct  vm_fileinfo_ext
{
    /* file name without path */
    VMWCHAR filefullname[MAX_APP_NAME_LEN];
    /* file name character array by 8.3 format encoding with UCS2, and the last character may be not '\0' */
    VMCHAR filename[8];
    /* file extention name character array by 8.3 format encoding with UCS2, and the last character may be not '\0' */
    VMCHAR extension[3];/* file attributes */
   VMBYTE           attributes; 
   vm_time_t       create_datetime; /* create time */
   vm_time_t	    modify_datetime; /* modify time */
   VMUINT           filesize; /* file size */
   VMUINT           drive; /* drive */
   VMUINT           stamp; /* stamp */
} vm_fileinfo_ext;

/* Disk information */
typedef struct
{
    /* A zero-terminated <color Red><b>Short File Name</b></color> with the volume's label. */
    VMCHAR            Label[24];

    /* The drive letter in <color Red><b>UPPER</b></color> case. */
    VMCHAR            DriveLetter;

    /* Indicate the disk is in write protection or not. 1 for protect, 0 for not protect. */
    VMUINT8            WriteProtect;

    /* Reserved fields */
    VMCHAR            Reserved[2];

    /* The volume's serial number. */
    VMUINT32            SerialNumber;

    /* The LBA address of the logical drive's boot record. For diskettes, this value will be 0. */
    VMUINT32            FirstPhysicalSector;

    /* 2, 16, or 32 for FAT-12, FAT-16, or FAT-32 */
    VMUINT32            FATType;

    /* The number of FATs on the volume. */
    VMUINT32            FATCount;

    /* The number of FATs on the volume. */
    VMUINT32            MaxDirEntries;

    /* The sector size. This value will usually be 512. */
    VMUINT32            BytesPerSector;

    /* Specifies the size of the smallest unit of storage that can be allocated to a file in sectors. */
    VMUINT32            SectorsPerCluster;

    /* Number of clusters for file storage on the volume. */
    VMUINT32            TotalClusters;

    /* The number of clusters, which are marked bad and are unavailable for file storage. */
    VMUINT32            BadClusters;

    /* The number of clusters currently available. */
    VMUINT32            FreeClusters;

    /* The number of files on the volume including directories, but not counting the root directory and files with an allocated file size of 0. */
    VMUINT32            Files;

    /* The number of contiguous cluster chains. On a completely unfragmented volume, this value would be identical to Files. */
    VMUINT32            FileChains;

    /* The number of contiguous cluster chains of free clusters. On a completely unfragmented volume, this value would be 1. */
    VMUINT32            FreeChains;

    /* The maximum allocated file size for a newly allocated contiguous file in clusters. On a completely unfragmented volume, this value would be identical to FreeClusters. */
    VMUINT32            LargestFreeChain;
} vm_fs_disk_info;

/* vm_get_disk_info Parameter */
typedef enum
{
    /*
     * Returns all fields in structure vm_get_disk_info except FreeClusters, BadClusters, Files, FileChains, FreeChains, LargestFreeChain.
     * <color Red><b>This flag never requires a FAT scan.</b></color>
     */
    VM_FS_DI_BASIC_INFO     =  0x00000001L,

    /*
     * Returns field FreeClusters. This flags may require FS to scan the complete FAT if the amount of free space is not known.
     * In this case, FS_DI_FAT_STATISTICS is returned in addition to FS_DI_FREE_SPACE.
     */
    VM_FS_DI_FREE_SPACE     =  0x00000002L,

    /*
     * Returns fields BadClusters, Files, FileChains, FreeChains, LargestFreeChain.
     * This flag will always cause FS to scan the complete FAT.
     */
    VM_FS_DI_FAT_STATISTICS =  0x00000004L,

    /*
     * Get volume label of the target drive. The maximum length is 11 wide characters.
     * <color Red><b>This option must be used with FS_DI_BASIC_INFO.</b></color>
     */
    VM_FS_DI_VOLUME_LABEL   =  0x00000008L,

    VM_FS_DI_INVALID
}vm_fs_di_enum;


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  vm_key_handler_t
 * DESCRIPTION
 *  Callback function type for key event handler.
 * PARAMETERS
 *  event : [IN] Key event.
 *  keycode : [IN] Key code.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*vm_key_handler_t)(VMINT event, VMINT keycode);

/*****************************************************************************
 * FUNCTION
 *  vm_reg_keyboard_callback
 * DESCRIPTION
 *  Registers key handler.
 * PARAMETERS
 *  vm_key_handler_t : [IN] Key event handler.
 * RETURNS
 *  void
 *****************************************************************************/
void vm_reg_keyboard_callback(vm_key_handler_t handler);

/* Pen events supported by MRE. */

/* Pen down event */
#define VM_PEN_EVENT_TAP				1
/* Pen release event */
#define VM_PEN_EVENT_RELEASE			2
/* Pen move event */
#define VM_PEN_EVENT_MOVE				3
 /* Pen long tap event. 
    Note:
    1. LongTap handler is invoked when  the pen is tapped for a period of time
        and stays at the same place where it is tapped down. 
    2. If pen move happen after pen down, there will be no pen LongTap event.
    3. Pen long tap can only happen one time at most.*/
#define VM_PEN_EVENT_LONG_TAP			4
/* Pen double click event */
#define VM_PEN_EVENT_DOUBLE_CLICK		5
/* Pen repeat event. 
    Note:
    1. Repeat can happen after LongTap or move or another repeat.
    2. Repeat event's coordinate will follow the previous events.*/
#define VM_PEN_EVENT_REPEAT			6
/* Pen abort event */
#define VM_PEN_EVENT_ABORT          7

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  vm_pen_handler_t
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event : [IN] Key event.
 *  x : [IN] x coordinate.
 *  y : [IN] y coordinate.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*vm_pen_handler_t)(VMINT event, VMINT x, VMINT y);

/*****************************************************************************
 * FUNCTION
 *  vm_reg_pen_callback
 * DESCRIPTION
 *  Registers pen event handler.
 * PARAMETERS
 *  handler : [IN] Pen event handler.
 * RETURNS
 *  void
 *****************************************************************************/
void vm_reg_pen_callback(vm_pen_handler_t handler);

/**
 * open file with file Read-Only mode.
 */
#define MODE_READ					1

/**
 * open file with Read-Write mode.
 */
#define MODE_WRITE					2

/**
 * open file with Read-Write mode, create if the file not exist.
 */
#define MODE_CREATE_ALWAYS_WRITE	4

/**
 * open file with Append mode.
 */
#define MODE_APPEND					8

/*****************************************************************************
* FUNCTION
 *    vm_file_open
 * DESCRIPTION
 *  open file 
 * PARAMETERS
 *  filename : [IN]  file full path encoding with UCS2
 *  mode : [IN] file open mode:
 *                MODE_READ: Read-Only
 *                MODE_WRITE : Read-Write
 *                MODE_CREATE_ALWAYS_WRITE : Read-Write mode, create if the file not exist.
 *  binary : [IN] TRUE means open with binary format, FALSE means open with ASCII format.
 * RETURNS
 *  non-negative file handle if successfully, and error code if failed to open. 
 *
*****************************************************************************/
VMFILE vm_file_open(const VMWSTR filename, VMUINT mode, VMUINT binary);

/*****************************************************************************
* FUNCTION
 *    vm_file_close
 * DESCRIPTION
 *  close file 
 * PARAMETERS
 *  handle : [IN]  file handle to be closed.
 *
*****************************************************************************/
void vm_file_close(VMFILE handle);

/*****************************************************************************
* FUNCTION
 *    vm_file_read
 * DESCRIPTION
 *  read file from current pointer of file
 * PARAMETERS
 *  handle : [IN]  file handle to be read.
 *  data : [OUT] output data address
 *  length : [IN] bytes to be read
 *  nread : [IN] bytes read actually
 * RETURNS
 *  bytes of read data if > 0, 0 means error happened or reach end of file.
 *
*****************************************************************************/
VMINT vm_file_read(VMFILE handle, void * data, VMUINT length, VMUINT *nread);

/*****************************************************************************
* FUNCTION
 *    vm_file_write
 * DESCRIPTION
 *  write data to current pointer of the file
 * PARAMETERS
 *  handle : [IN]  file handle to write.
 *  data : [IN] the address of data to be written
 *  length : [IN] bytes to be written
 *  written : [IN] bytes written actually
 * RETURNS
 *  bytes of written data if > 0, 0 means error happened.
 *
*****************************************************************************/
VMINT vm_file_write(VMFILE handle, void * data, VMUINT length, VMUINT * written);

/*****************************************************************************
* FUNCTION
 *    vm_file_commit
 * DESCRIPTION
 *  commit the I/O cache data to file.
 * PARAMETERS
 *  handle : [IN]  file handle to commit.
 * RETURNS
 *  0 means successfully, non-zero is error code.
 *
*****************************************************************************/
VMINT vm_file_commit(VMFILE handle);

#define BASE_BEGIN		1
#define BASE_CURR		2
#define BASE_END		3

/*****************************************************************************
* FUNCTION
 *    vm_file_seek
 * DESCRIPTION
 *  move the file pointer to specified position. If exceed file size, this operation will return error.
 * PARAMETERS
 *  handle : [IN]  file handle to seek.
 *  offset : [IN]  bytes to move.
 *  base: [IN]  base position to move.
 *          BASE_BEGIN means from begin of file;
 *          BASE_CURR means from current position; 
 *          BASE_END means from end of file.
 * RETURNS
 *  0 means successfully, non-zero is error code.
 * 
*****************************************************************************/
VMINT vm_file_seek(VMFILE handle, VMINT offset, VMINT base);

/*****************************************************************************
* FUNCTION
 *    vm_file_tell
 * DESCRIPTION
 *  get the position of current pointer of file.
 * PARAMETERS
 *  handle : [IN]  file handle.
 * RETURNS
 *  current pointer position,  or negative number error code if failed.
 *
*****************************************************************************/
VMINT vm_file_tell(VMFILE handle);

/*****************************************************************************
* FUNCTION
 *    vm_file_is_eof
 * DESCRIPTION
 *  check if the current pointer is end of file or not.
 * PARAMETERS
 *  handle : [IN]  file handle.
 * RETURNS
 *  current pointer is end of file or not.
 * RETURN VALUES                                      
 *  TRUE : current pointer is end of file.
 *  FALSE : current pointer is not end of file.
 *
*****************************************************************************/
VMINT vm_file_is_eof(VMFILE handle);

/*****************************************************************************
* FUNCTION
 *    vm_file_getfilesize
 * DESCRIPTION
 *  get file size by byte.
 * PARAMETERS
 *  handle : [IN]  file handle.
 *  file_size : [OUT] output the file size by byte
 * RETURNS
 *  get file size successfully or failed
 * RETURN VALUES                                      
 *  0 : get file size successfully.
 *  non-zero : failed to get file size
 * 
*****************************************************************************/
VMINT vm_file_getfilesize(VMFILE handle, VMUINT *file_size);

/*****************************************************************************
* FUNCTION
 *    vm_file_delete
 * DESCRIPTION
 *  delete specified file.
 * PARAMETERS
 *  filename : [IN]  file name full path  encoding with UCS2 format.
 * RETURNS
 *  delete file successfully or failed
 * RETURN VALUES                                      
 *  0 : delete file successfully.
 *  non-zero : failed to delete file.
 * 
*****************************************************************************/
VMINT vm_file_delete(const VMWSTR filename);

/*****************************************************************************
* FUNCTION
 *    vm_file_rename
 * DESCRIPTION
 *  delete specified file.
 * PARAMETERS
 *  filename : [IN]  old file name full path encoding with UCS2 format.
 *  newname : [IN]  new file name full path encoding with UCS2 format.
 * RETURNS
 *  rename file successfully or failed
 * RETURN VALUES                                      
 *  0 : rename file successfully.
 *  non-zero : failed to rename file.
 * 
*****************************************************************************/
VMINT vm_file_rename(const VMWSTR filename, const VMWSTR newname);

/*****************************************************************************
* FUNCTION
 *    vm_file_mkdir
 * DESCRIPTION
 *  create new directory with specified path name.
 * PARAMETERS
 *  dirname : [IN]  path name encoding with UCS2 format.
 * RETURNS
 *  create directory successfully or failed
 * RETURN VALUES                                      
 *  0 : create directory successfully.
 *  non-zero : failed to create directory.
 *
*****************************************************************************/
VMINT vm_file_mkdir(const VMWSTR dirname);

/*****************************************************************************
* FUNCTION
 *    vm_file_rmdir
 * DESCRIPTION
 *  remove directory with specified path name.
 * PARAMETERS
 *  dirname : [IN]  path name encoding with UCS2 format.
 * RETURNS
 *  remove directory successfully or failed
 * RETURN VALUES                                      
 *  0 : remove directory successfully.
 *  non-zero : failed to remove directory.
 *
*****************************************************************************/
VMINT vm_file_rmdir(const VMWSTR dirname);

/*****************************************************************************
* FUNCTION
 *    vm_file_set_attributes
 * DESCRIPTION
 *  set attributes of specified full path file name encoding with UCS2 format. The attributes
 *  can not include VM_FS_ATTR_VOLUME, VM_FS_ATTR_DIR, or VM_FS_LONGNAME_ATTR.
 *  The value of attributes is the result of OR operator.
 * PARAMETERS
 *  filename : [IN]  file name encoding with UCS2 format.
 *  attributes : [IN]  file attributes.
 * RETURNS
 *  set attributes successfully or failed
 * RETURN VALUES                                      
 *  0 : set attributes successfully.
 *  non-zero : failed to set attributes.
 *
*****************************************************************************/
VMINT vm_file_set_attributes(const VMWSTR filename, VMBYTE attributes);

/*****************************************************************************
* FUNCTION
 *    vm_file_get_attributes
 * DESCRIPTION
 *  set attributes of specified full path file name encoding with UCS2 format. 
 *  The value of attributes is the result of OR operator.
 * PARAMETERS
 *  filename : [IN]  file name encoding with UCS2 format.
 * RETURNS
 *  get attributes successfully or failed
 * RETURN VALUES                                      
 *  -1 : failed to get attributes.
 *  else : get the attributes value.
 *
*****************************************************************************/
VMINT vm_file_get_attributes(const VMWSTR filename);

/*****************************************************************************
* FUNCTION
 *    vm_find_first
 * DESCRIPTION
 *  find files from specified path, support wild character finding.
 * PARAMETERS
 *  pathname : [IN]  path name encoding with UCS2 format.
 *  info : [OUT] result of finding
 * RETURNS
 *  find handle or error code
 * RETURN VALUES                                      
 *  non-negative number : find handle.
 *  negative number : error code.
 *
*****************************************************************************/
VMINT vm_find_first(VMWSTR pathname, struct vm_fileinfo_t* info);

/*****************************************************************************
* FUNCTION
 *    vm_find_next
 * DESCRIPTION
 *  continue to find next file.
 * PARAMETERS
 *  handle : [IN]  find handle.
 *  info : [OUT] result of finding
 * RETURNS
 *  find handle or error code
 * RETURN VALUES                                      
 *  0 : find next file successfully.
 *  negative number : end of finding.
 *
*****************************************************************************/
VMINT vm_find_next(VMINT handle, struct vm_fileinfo_t* info);

/*****************************************************************************
* FUNCTION
 *    vm_find_close
 * DESCRIPTION
 *  close finding process.
 * PARAMETERS
 *  handle : [IN]  find handle.
 *
*****************************************************************************/
void vm_find_close(VMINT handle);

#define vm_get_removable_driver vm_get_removeable_driver
/*****************************************************************************
* FUNCTION
 *    vm_get_removable_driver
 * DESCRIPTION
 *  get drive letter of removable disk, which normally is memory card.
 * RETURNS
 *  drive letter of removable disk. negative number means no removable drive.
 *
*****************************************************************************/
VMINT vm_get_removable_driver(void);

/*****************************************************************************
* FUNCTION
 *    vm_get_system_driver
 * DESCRIPTION
 *  get drive letter of phone disk, which normally is public drive.
 * RETURNS
 *  drive letter of phone disk. negative number means no public drive.
 *
*****************************************************************************/
VMINT vm_get_system_driver(void);

/*****************************************************************************
* FUNCTION
 *    vm_get_disk_free_space
 * DESCRIPTION
 *  get free space by byte of specified drive.
 * PARAMETERS
 *  drv_name : [IN]  drive letter string terminated with '\0' .
 * RETURNS
 *  free space by byte. 0 means specified disk does not exist.
 * 0xFFFFFFFF means exceed the max limitation, the free space size lager than this value.
 * another choice to use vm_get_disk_info
 * 
* EXAMPLE                                  [this TAG is optional]
 * <code>
 * VMINT sys_driver = -1;
 * VMUINT sys_driver_size = 0;
 * if ((sys_driver = vm_get_system_driver()) >= 0)
 * {
 *     VMCHAR driver_str[2] = {0};
 *     
 *     sprintf(driver_str, "%c", (VMCHAR)sys_driver);
 *     sys_driver_size = vm_get_disk_free_space(vm_ucs2_string(driver_str));
 * }
 * </code>
*****************************************************************************/
VMUINT vm_get_disk_free_space(VMWSTR drv_name);

/*****************************************************************************
 * FUNCTION
 *  vm_get_disk_info
 * DESCRIPTION
 *  Return information about a logical drive
 * PARAMETERS
 *  DriveName   :   [IN] <P>Must be a valid file name, e.g., a root directory name. 
 * Only the drive information (possibly the current default drive) is determined.
 *  DiskInfo    :   [OUT]<P>Refer to vm_fs_disk_info.
 *  Flags       :   [IN] <P>Refer to vm_fs_di_enum.
 * RETURNS
 *  success if >= 0, else failure.
 *****************************************************************************/
VMINT vm_get_disk_info(const VMCHAR * drv_name, vm_fs_disk_info * fs_disk, vm_fs_di_enum e_di);

/* If selects OK or Cancel in editor screen, the state will pass to application via callback's parameter. */

#define VM_INPUT_OK             (1)     /* If selects OK */
#define VM_INPUT_CANCEL     (0) /* If selects Cancel */
#define VM_INPUT_NOTIFY     (2) /* If another screen makes editor exit, this message will be sent */
#define VM_INPUT_CLOSE      (3) /* If application close the input screen self, application will receive this message */
 /*****************************************************************************
 * FUNCTION
 *  vm_input_text
 * DESCRIPTION
 *  Display a editor screen. The default input method is VM_INPUT_METHOD_TEXT.
 *  The max length of input string is 250.
 * PARAMETERS
 *  f : [IN] This callback will be invoked when the editor screen closed. If user selects OK, the state will be VM_INPUT_OK.
 *  If user select Cancel, the state will be VM_INPUT_CANCEL.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  0 : If open the input screen successfully.
 *  <0 : If failed.
 *****************************************************************************/
VMINT vm_input_text(void (*f)(VMINT state, VMWSTR text));

#define VM_INPUT_METHOD_TEXT     1      /* Input text and the default input method is PINYIN */
#define VM_INPUT_METHOD_PASSWORD 2      /* Input password and the default input method is multitap abc.
                                           only 0~9, *, # are allowed and the content would be displayed as * in editor. */
#define VM_INPUT_METHOD_NUMERIC         4       /* Input number and the default input method is phone number */
#define VM_INPUT_METHOD_ALPHABETIC    8 /* Input English and the default input method is multitap abc */
#define VM_INPUT_METHOD_URL         16 /* Input URL */
#define VM_INPUT_METHOD_ALPHABETIC_EXT    32 /* Input English and the default input method is mmi language's */

 /*****************************************************************************
 * FUNCTION
 *  vm_input_text2
 * DESCRIPTION
 *  Display a editor screen. User can set default string and default input method.
 *  The max length of input string is 250.
 * PARAMETERS
 *  def_str : [IN] Default string in editor screen.
 *  def_input_method: [IN] Default input method.
 *  f : [IN] This callback will be invoked when the editor screen closed. If user selects OK, the state will be VM_INPUT_OK.
 *  If user select Cancel, the state will be VM_INPUT_CANCEL.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  0 : If open the input screen successfully.
 *  <0 : If failed.
 *****************************************************************************/
VMINT vm_input_text2(VMWSTR def_str, VMINT def_input_method, void (*f) (VMINT state, VMWSTR text));

 /*****************************************************************************
 * FUNCTION
 *  vm_input_text3
 * DESCRIPTION
 *  Display a editor screen. User can set default string and default input method.
 *  User can also set the max input length (in short) via parameter input_max_size.
 * PARAMETERS
 *  default_string : [IN] Default string in editor screen.
 *  input_max_size : [IN] 
 *  default_input_method: [IN] Default input method.
 *  input_text_cb : [IN] This callback will be invoked when the editor screen closed. If user selects OK, the state will be VM_INPUT_OK.
 *  If user select Cancel, the state will be VM_INPUT_CANCEL.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  0 : If open the input screen successfully.
 *  <0 : If failed.
 *****************************************************************************/
VMINT vm_input_text3(VMWSTR default_string, VMINT input_max_size, 
	VMINT default_input_method, void (*input_text_cb)(VMINT state, VMWSTR text));

 /*****************************************************************************
 * FUNCTION
 *  vm_set_app_desired_input_mode
 * DESCRIPTION
 *  To set editor desired input mode. Used when App call vm_input_text/vm_input_text2/vm_input_text3 to enter editor screen.
 * PARAMETERS
 *  desired_input_mode : [IN] input mode.
 * RETURN VALUES
 *  void
 *****************************************************************************/
void vm_set_app_desired_input_mode(vm_input_mode_enum desired_input_mode);

/*****************************************************************************
 * FUNCTION
 *  vm_input_close_screen
 * DESCRIPTION
 *  Close input screen by application self. And it will send VM_INPUT_CLOSE to application.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void vm_input_close_screen(void);
 
/*****************************************************************************
 * FUNCTION
 *  vm_input_move_cursor_to_start
 * DESCRIPTION
 *  Move the cursor to the start position and edit from the beginning.
 *  You need to call this API after vm_input_text/vm_input_text2/vm_input_text3.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void vm_input_move_cursor_to_start(void);

/*****************************************************************************
 * FUNCTION
 *  vm_input_set_vk_default_enlarge
 * DESCRIPTION
 *  Set VK default enlarge.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void vm_input_set_vk_default_enlarge(void);

/******************************************************************************
 * FUNCTION
 *	vm_input_set_editor_title
 * DESCRIPTION
 *	set the input editor title. This function should be called just before
 *	vm_input_text, vm_input_text2 or vm_input_text3, and the title's length must
 *	be less than 60.
 * PARAMETERS
 *	title	:	[IN]	editor title provided by user
 * RETURN VALUES
 *	TRUE	:	if set the editor title successfully.
 *	FALSE	:	if fail to set the editor title.
 *****************************************************************************/
VMINT vm_input_set_editor_title(VMWSTR title);

 /*****************************************************************************
 * FUNCTION
 *  vm_is_support_keyborad
 * DESCRIPTION
 *  Check whether the phone support keypad or not.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  TRUE : Supports keypad.
 *  FALSE : Not support.
 *****************************************************************************/
VMINT vm_is_support_keyborad(void);

 /*****************************************************************************
 * FUNCTION
 *  vm_is_support_pen_touch
 * DESCRIPTION
 *  Check whether the phone support touch panel or not.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  TRUE : Supports touch panel.
 *  FALSE : Not support.
 *****************************************************************************/
VMINT vm_is_support_pen_touch(void);

/*****************************************************************************
 * FUNCTION
 *  vm_is_finger_touch_version
 * DESCRIPTION
 *  Check whether the phone support finger touch feature or not.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  TRUE : Supports finger touch feature.
 *  FALSE : Not support.
 *****************************************************************************/
VMINT vm_is_finger_touch_version(void);

/*****************************************************************************
 * FUNCTION
 *  vm_is_support_gsensor
 * DESCRIPTION
 *  Check whether the phone support G-sensor or not.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  TRUE : Supports G-sensor.
 *  FALSE : Not support.
 *****************************************************************************/
VMINT vm_is_support_gsensor(void);

/*****************************************************************************
 * FUNCTION
 *  vm_is_support_camera_sensor
 * DESCRIPTION
 *  Check whether the phone support camera sensor or not.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  TRUE : Supports camera sensor.
 *  FALSE : Not support.
 *****************************************************************************/
VMINT vm_is_support_camera_sensor(void);

/*****************************************************************************
* FUNCTION
 *    vm_file_get_modify_time
 * DESCRIPTION
 *  get the latest modified time of specified file.
 * PARAMETERS
 *  filename : [IN]  file name of full path encoding with UCS2 format.
 *  modify_time : [OUT]  output the latest modified time
 * RETURNS
 *  0 means get modified time successfully, -1 means failed.
 *
*****************************************************************************/
VMINT vm_file_get_modify_time(const VMWSTR filename, vm_time_t * modify_time);

/*****************************************************************************
* FUNCTION
 *    vm_find_first_ext
 * DESCRIPTION
 *  find files from specified path, support wild character finding.
 * PARAMETERS
 *  pathname : [IN]  path name encoding with UCS2 format.
 *  direntry : [OUT] result of finding
 * RETURNS
 *  find handle or error code
 * RETURN VALUES                                      
 *  non-negative number : find handle.
 *  negative number : error code.
 *
*****************************************************************************/
VMINT vm_find_first_ext(VMWSTR pathname, vm_fileinfo_ext * direntry);

/*****************************************************************************
* FUNCTION
 *    vm_find_next_ext
 * DESCRIPTION
 *  continue to find next file.
 * PARAMETERS
 *  handle : [IN]  find handle.
 *  direntry : [OUT] result of finding
 * RETURNS
 *  find handle or error code
 * RETURN VALUES                                      
 *  0 : find next file successfully.
 *  negative number : end of finding.
 *
*****************************************************************************/
VMINT vm_find_next_ext(VMINT handle,  vm_fileinfo_ext * direntry);

/*****************************************************************************
* FUNCTION
 *    vm_find_close_ext
 * DESCRIPTION
 *  close finding process.
 * PARAMETERS
 *  handle : [IN]  find handle.
 *
*****************************************************************************/
void vm_find_close_ext(VMINT handle);

typedef struct
{
    VMUINT8 home_city;
    VMUINT8 foreign_city;
    VMUINT8 date_seperator;
    VMUINT8 date_format;
    VMUINT8 time_format;
    VMINT current_dst;

    VMUINT8 current_city;
    float current_timezone;
    
    VMUINT8 foreign_index;
    VMUINT8 wc_dst;
    VMUINT8 setting_dt_dst;
    VMUINT16 timezone;
    VMUINT16 frn_timezone;

    VMUINT8     wc_entry_screen;    /* wc_entry_screen, 0:worldclock, 1:homecity, 2:foreigncity */
    VMUINT8     tz_city_match;      /* tz_city_match, 0:Not Match, 1:Match */
} vm_phoneset_info_struct;




/* error code of storage */
typedef enum
{
    VM_STORAGE_ERR_RES = -10, /* resource is not enough */
    VM_STORAGE_ERR_PARAM = -9, /* input param error */
    VM_STORAGE_ERR_FILE_CREATE = -8, /* sto create failure */
    VM_STORAGE_ERR_FILE_OPEN = -7, /* sto open failure */
    VM_STORAGE_ERR_FILE_SEEK = -6, /* sto seek failure */
    VM_STORAGE_ERR_FILE_WRITE = -5, /* sto wirte failure */
    VM_STORAGE_ERR_FILE_READ = -4, /* sto read failure */
    VM_STORAGE_ERR_AUTHORIZATION = -3, /* no authorization */
    VM_STORAGE_ERR_NONE = 0 /* no error */
}vm_storage_error_type;

/*****************************************************************************
 * FUNCTION
 *  vm_storage_open
 * DESCRIPTION
 *  open storage.
 * PARAMETERS
 *  void
 * RETURNS
 *  storage handle or error code
 * RETURN VALUES
 *  vm_storage_error_type
*****************************************************************************/
VMINT vm_storage_open(void);

/*****************************************************************************
 * FUNCTION
 *  vm_storage_close
 * DESCRIPTION
 *  close storage.
 * PARAMETERS
 *  h : [IN] handle of storage
*****************************************************************************/
void vm_storage_close(VMINT h);

/*****************************************************************************
 * FUNCTION
 *  vm_storage_read
 * DESCRIPTION
 *  read data from storage.
 * PARAMETERS
 *  h : [IN] handle of storage
 * data : [OUT] buffer will be filled
 * offset : [IN] offset from head of storage
 * size : [IN] buffer size
 * read : [OUT] read size
 * RETURNS
 *  0 or error code
 * RETURN VALUES
 *  vm_storage_error_type
*****************************************************************************/
VMINT vm_storage_read(VMINT h, void * data, VMUINT offset, VMUINT size, VMUINT * read);

/*****************************************************************************
 * FUNCTION
 *  vm_storage_write
 * DESCRIPTION
 *  write data to storage
 * PARAMETERS
 *  h : [IN] handle of storage
 * data : [IN] buffer will be written to storage
 * offset : [IN] offset from head of storage
 * size : [IN] buffer size
 * written : [OUT] written size
 * RETURNS
 *  0 or error code
 * RETURN VALUES
 *  vm_storage_error_type
*****************************************************************************/
VMINT vm_storage_write(VMINT h, const void * data, VMUINT offset, VMUINT size, VMUINT * written);
/* DOM-NOT_FOR_SDK-BEGIN */

/* error code of storage */
typedef enum
{
    VM_SYS_FILE_ERR_DISK_FULL = -12, 
    VM_SYS_FILE_ERR_RES , /* resource is not enough */
    VM_SYS_FILE_ERR_PARAM, /* input param error */
    VM_SYS_FILE_ERR_FILE_CREATE, /* create failure */
    VM_SYS_FILE_ERR_FILE_OPEN, /* open failure */
    VM_SYS_FILE_ERR_FILE_DELETE,
    VM_SYS_FILE_ERR_FILE_SEEK, /* seek failure */
    VM_SYS_FILE_ERR_FILE_WRITE, /* wirte failure */
    VM_SYS_FILE_ERR_FILE_WRITE_PARTLY, 
    VM_SYS_FILE_ERR_FILE_READ, /* read failure */
    VM_SYS_FILE_ERR_AUTHORIZATION, /* no authorization */
    VM_SYS_FILE_ERR_NONE = 0 /* no error */
}vm_sys_file_error_type;


/*****************************************************************************
* FUNCTION
 *    vm_sys_file_open
 * DESCRIPTION
 *  open file in system drive disk
 * PARAMETERS
 *  mode : [IN] file open mode:
 *                MODE_READ: Read-Only
 *                MODE_WRITE : Read-Write
 *                MODE_CREATE_ALWAYS_WRITE : Read-Write mode, create if the file not exist.
 *  binary : [IN] TRUE means open with binary format, FALSE means open with ASCII format.
 * RETURNS
 *  non-negative file handle if successfully, and error code if failed to open. 
 *
*****************************************************************************/
VMFILE vm_sys_file_open(VMUINT mode, VMUINT binary);

/*****************************************************************************
* FUNCTION
 *    vm_sys_file_seek
 * DESCRIPTION
 *  move the sys file pointer to specified position. If exceed file size, this operation will return error.
 * PARAMETERS
 *  handle : [IN]  sys file handle to seek.
 *  offset : [IN]  bytes to move.
 *  base: [IN]  base position to move.
 *          BASE_BEGIN means from begin of file;
 *          BASE_CURR means from current position; 
 *          BASE_END means from end of file.
 * RETURNS
 *  0 means successfully, non-zero is error code.
 * 
*****************************************************************************/
VMINT vm_sys_file_seek(VMFILE handle, VMINT offset, VMINT base);


/*****************************************************************************
* FUNCTION
 *    vm_sys_file_read
 * DESCRIPTION
 *  read file from current pointer of sys file
 * PARAMETERS
 *  handle : [IN]  file handle to be read.
 *  data : [OUT] output data address
 *  length : [IN] bytes to be read
 *  nread : [IN] bytes read actually
 * RETURNS
 *  bytes of read data if > 0, 0 means error happened or reach end of file.
 *
*****************************************************************************/
VMINT vm_sys_file_read(VMFILE handle, void * data, VMUINT length, VMUINT *nread);

/*****************************************************************************
* FUNCTION
 *    vm_sys_file_write
 * DESCRIPTION
 *  write data to current pointer of the sys file
 * PARAMETERS
 *  handle : [IN]  file handle to write.
 *  data : [IN] the address of data to be written
 *  length : [IN] bytes to be written
 *  written : [IN] bytes written actually
 * RETURNS
 *  bytes of written data if > 0, 0 means error happened.
 *
*****************************************************************************/
VMINT vm_sys_file_write(VMFILE handle, void * data, VMUINT length, VMUINT * written);


/*****************************************************************************
* FUNCTION
 *    vm_sys_file_close
 * DESCRIPTION
 *  close sys file 
 * PARAMETERS
 *  handle : [IN]  sys file handle to be closed.
 *
*****************************************************************************/
void vm_sys_file_close(VMFILE h);

/*****************************************************************************
* FUNCTION
 *    vm_sys_file_delete
 * DESCRIPTION
 *  delete sys file.
 * RETURNS
 *  delete sys file successfully or failed
 * RETURN VALUES                                      
 *  0 : delete file successfully.
 *  non-zero : failed to delete sys file.
 * 
*****************************************************************************/
VMINT vm_sys_file_delete(void);

/*****************************************************************************
* FUNCTION
 *    vm_sys_file_get_space
 * DESCRIPTION
 *  get the current free size of sys file 
 * PARAMETERS
 * RETURNS
 *  rest space size. 
 *
*****************************************************************************/
VMINT vm_sys_file_get_space(void);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
* FUNCTION
 *    vm_get_default_store_path_by_type
 * DESCRIPTION
 *  get default store path of  different types
 * PARAMETERS
 * RETURNS
 *  path string. 
 *
*****************************************************************************/

VMUWSTR vm_get_default_store_path_by_type(VMINT disk_letter, VM_STORE_PATH_TYPE type);


typedef enum
{
    VM_SELECTOR_ERR_NO_RES = -7, /* no avalible resource */
    VM_SELECTOR_ERR_PARAM, /* input invalid parameter */
    VM_SELECTOR_ERR_NO_MEMORY, /* no memmory */
    VM_SELECTOR_ERR_NO_DISK, /* driver path failure */
    VM_SELECTOR_ERR_EXCEPTION, /* exception */
    VM_SELECTOR_ERR_NOT_SUPPORT, /* platform dose not support */
    VM_SELECTOR_ERR_NOT_AUTHORIZED, /* no authrization */
    VM_SELECTOR_ERR_SUCCESS = 0 /* success */
}vm_selector_error_t;

typedef enum
{ 
    VM_SELECTOR_TYPE_ALL = 0, /* all file type */
    VM_SELECTOR_TYPE_IMAGE, /* image type */
    VM_SELECTOR_TYPE_TXT /* txt type */
}vm_selector_type_t;

/*****************************************************************************
 * FUNCTION
 *  vm_selector_run
 * DESCRIPTION
 *  Start Fmgr to select a file.
 * PARAMETERS
 * type : [IN] the browse type of file, define in vm_selector_type_t
 * folder_path : [IN] witch path need to be browsed, NULL means root 
 * callback : [IN] the result callback of file selection. file_path is the path name of current selected file, 
 * it be set NULL if error. wlen is the length of path name in words.
 * RETURNS
 *  0 or error code define in vm_selector_error_t
 * RETURN VALUES
 *  vm_selector_error_t
*****************************************************************************/

VMINT vm_selector_run(VMINT type, const VMWCHAR * folder_path, VMINT (*callback)(VMWCHAR * file_path, VMINT wlen));



/*****************************************************************************
 * FUNCTION
 *  vm_pen_configure_sampling_period
 * DESCRIPTION
 *  Config sampling period of Event-based
 * PARAMETERS
 *  sp         :[IN]        (Pen Event)Sampling period in pen-moving (multiple of 10ms)
 * RETURNS
 *  VMINT
 * RETURN VALUES
 *  0 : success
 *  non-zero : failure
 *  -1 : no authorization
 *****************************************************************************/
VMINT vm_pen_configure_sampling_period(VMUINT sp);


typedef enum
{
    /* KEY1 Number */
    VM_KEYPAD_1KEY_NUMBER = 0,
    /* KEY2 Number */
    VM_KEYPAD_2KEY_NUMBER,
    /* reserved */
    VM_KEYPAD_3KEY_NUMBER,
    /* KEY1 Qwerty */
    VM_KEYPAD_1KEY_QWERTY,
    /* KEY2 Qwerty */
    VM_KEYPAD_2KEY_QWERTY,
    /* reserved */
    VM_KEYPAD_3KEY_QWERTY,
    /* reserved */
    VM_KEYPAD_MODE_END
} vm_keypad_mode_enum;

typedef enum
{
    VM_KBD_MODE_ERR_PARAM = -2, /* input invalid parameter */
    VM_KBD_MODE_ERR_NOT_AUTHORIZED, /* no authrization */
    VM_KBD_MODE_ERR_SUCCESS = 0 /* success */
}vm_kbd_mode_error_t;

/*****************************************************************************
 * FUNCTION
 *  vm_kbd_set_mode
 * DESCRIPTION
 *  set the concurrent key mode
 * PARAMETERS
 *  mode : [IN] see vm_keypad_mode_enum
 * RETURNS
 *  vm_kbd_mode_error_t
 * RETURN VALUES
 *  0 : success
 *  non-zero : failure
 *****************************************************************************/
VMINT vm_kbd_set_mode(VMUINT8 mode);

typedef enum
{
    VM_CAM_ERR_BUSY = -4,
    VM_CAM_ERR_EXCEPTION,
    VM_CAM_ERR_NOT_SUPPORT,
    VM_CAM_ERR_NOT_AUTHORIZED,
    VM_CAM_ERR_SUCCESS = 0,
}vm_camera_startup_error_t;


/*****************************************************************************
 * FUNCTION
 *  vm_camera_startup
 * DESCRIPTION
 *  Run Camrea APP directly, In lowend project, APP maybe need to exit cause of Out of Memory.
 * PARAMETERS
 *  Void
 * RETURNS
 *  Run result
 * RETURN VALUES
 *  0 : success
 *  non-zero : failure
 *****************************************************************************/
VMINT vm_camera_startup(void);

typedef enum
{
    VM_DEVCONFIG_KEYPAD_TYPE_NORMAL,     /* normal keypad type */
    VM_DEVCONFIG_KEYPAD_TYPE_REDUCED,    /* reduced keypad type */
    VM_DEVCONFIG_KEYPAD_TYPE_QWERTY,     /* qwerty keypad type */
    VM_DEVCONFIG_KEYPAD_TYPE_TOTAL
} vm_devconfig_keypad_type_enum;


/*****************************************************************************
* FUNCTION
*  vm_get_keypad_type
* DESCRIPTION
*  check the current type of keypad
* PARAMETERS
*  void
* RETURN VALUES
*  less than zero : failure
*  VM_DEVCONFIG_KEYPAD_TYPE_NORMAL : normal keypad type.
*  VM_DEVCONFIG_KEYPAD_TYPE_REDUCED : reduced keypad type.
*  VM_DEVCONFIG_KEYPAD_TYPE_QWERTY : qwerty keypad type.
*****************************************************************************/
VMINT vm_get_keypad_type(void);


/*****************************************************************************
 * FUNCTION
 *  vm_startup_email
 * DESCRIPTION
 *  startup email
 * PARAMETERS
 *  to_addr : [IN] email address of receiver (UCS2)
 * RETURN VALUES
 *  0 : success
 *  non-zero : failure
 *  -2 : platform not support
 *  -3 : no email account
 *****************************************************************************/
VMINT vm_startup_email(const VMWSTR to_addr);

/* vm_fmgr_default_folder_enum */
typedef enum
{
    VM_FMGR_DEFAULT_FOLDER_EBOOKS, /* path of defualt ebooks */
    VM_FMGR_DEFAULT_FOLDER_IMAGES, /* path of defualt images */
    VM_FMGR_DEFAULT_FOLDER_AUDIO, /* path of defualt audio */
    VM_FMGR_DEFAULT_FOLDER_VIDEO, /* path of defualt video */
    VM_FMGR_DEFAULT_FOLDER_SWFLASH, /* path of defualt swflash */
    VM_FMGR_DEFAULT_FOLDER_LANGLN, /* path of defualt langln */
    VM_FMGR_DEFAULT_FOLDER_TEMP, /* path of defualt temp */
    VM_FMGR_DEFAULT_FOLDER_THEMES, /* path of defualt themes */
    VM_FMGR_DEFAULT_FOLDER_BARCODE, /* path of defualt barcode */
    VM_FMGR_DEFAULT_FOLDER_MMSBOX, /* path of defualt mmsbox */
    VM_FMGR_DEFAULT_FOLDER_ROOT,  /* path of defualt root */
    VM_FMGR_DEFAULT_FOLDER_TOTAL
}vm_fmgr_default_folder_enum;

/*****************************************************************************
 * FUNCTION
 *  vm_get_default_folder_path
 * DESCRIPTION
 *  get the default path of folder type
 * PARAMETERS
 *  mode : [IN] see vm_fmgr_default_folder_enum
 * RETURNS
 *  const VMWCHAR * (UCS2)
 * RETURN VALUES
 *  non-NULL : success
 *  NULL : failure
 *****************************************************************************/
const VMWCHAR * vm_get_default_folder_path(vm_fmgr_default_folder_enum type);


/* vm_file_copy Callback Return Value */
typedef enum
{
   /* <color red>if something wrong, will call once</color>
    * Fail to do the copy action. Total and Completed will be zero.
    */
    VM_FS_MOVE_PGS_FAIL = -1,

    /*
     * <color red>Always call once</color>
     * Prepare to do the copy action. Parameter checking and remove target will be done at this stage.
     * Total and Completed will be zero.
     */
    VM_FS_MOVE_PGS_PREPARE,

   /*
    * <color red>If pass parameter checking, always call once.</color>
    * Start to do the copy action. Total and Completed will be zero.
    */
    VM_FS_MOVE_PGS_START,

   /*
    * <color red>Not always call even if nothing wrong.</color>
    * If you move/copy a folder recursively, Total will be the number of files/folders to be moved/copied.
    * Completed will be the files/folders that had been copied.
    * If you just copy a file, Total will be the size of this file and Completed will be the bytes that had been copied.
    * <color red>Note</color> that if move/copy only one file, this callback will be triggered when interval is longer than 100ms around.
    */
    VM_FS_MOVE_PGS_ING,

   /*
    * <color redIf nothing fail, always call once</color>
    * Move/copy action is done. Total and Completed will be zero.
    */
    VM_FS_MOVE_PGS_DONE
} vm_fs_move_pgs_enum;


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 * FUNCTION
 *  vm_file_copy_cb
 * DESCRIPTION
 *  Callback function type for file copy.
 * PARAMETERS
 *  act : [IN] see vm_fs_move_pgs_enum.
 *  total : [IN] the size of source file.
 *  completed : [IN] copied size.
 *  hdl : [IN] handle of file copy.
 * RETURNS
 *  VMINT
 *****************************************************************************/
typedef VMINT (*vm_file_copy_cb)(VMINT act, VMUINT32 total, VMUINT32 completed, VMINT hdl);

/*****************************************************************************
 * FUNCTION
 *  vm_file_copy
 * DESCRIPTION
 *  copy file
 * PARAMETERS
 *  dst : [IN] the file path of destination UCS2
 *  src : [IN] the file path of source UCS2
 *  cb : [IN] callback of file copy
 * RETURNS
 *  VMINT
 * RETURN VALUES
 *  successful if 0, else failure
 *  (-2): bad parameter.
 *  (-3): Either source full path or destination full path is wrong
 *  (-19): Cannot find source full path specified.
 *  (-36): destination full path exists.
 *  (-44): Cannot get memory to do the operation
 *  (-46): busy.
 *  (-47): This action has been aborted in the user's callback function.
 *****************************************************************************/
VMINT vm_file_copy(const VMWSTR dst, const VMWSTR src, vm_file_copy_cb cb);

/*****************************************************************************
 * FUNCTION
 *  vm_file_copy_abort
 * DESCRIPTION
 *  abort file copy
 * PARAMETERS
 *  hdl : [IN] handle of file copy
 * RETURNS
 *  VMINT
 * RETURN VALUES
 *  success if 0, else failure
 *****************************************************************************/
VMINT vm_file_copy_abort(VMINT hdl);



typedef enum
{
    VM_MULTI_TOUCH_ERR_NO_RES = -7, /* no avalible resource */
    VM_MULTI_TOUCH_ERR_PARAM, /* input invalid parameter */
    VM_MULTI_TOUCH_ERR_NO_MEMORY, /* no memmory */
    VM_MULTI_TOUCH_ERR_NO_DISK, /* driver path failure */
    VM_MULTI_TOUCH_ERR_EXCEPTION, /* exception */
    VM_MULTI_TOUCH_ERR_NOT_SUPPORT, /* platform dose not support */
    VM_MULTI_TOUCH_ERR_NOT_AUTHORIZED, /* no authrization */
    VM_MULTI_TOUCH_ERR_SUCCESS = 0 /* success */
}vm_multi_touch_error_t;


/* Touch screen mode */
typedef enum
{
    /* Single touch mode, just send one finger event to application, this is default behavior */
    VM_SINGLE_TOUCH,
    /* Multi-touch mode, send several events to application, according to how many fingers on the screen, at most it is five */
    VM_MULTI_TOUCH,
    /* Total touch event total, no need to handle this */
    VM_MULTI_TOUCH_TOTAL
} vm_touch_mode;


/* structure of Point */
typedef struct
{
    /* x coordinate */
    VMINT16 x;
    /* x coordinate */
    VMINT16 y;
} vm_pen_point_struct;

/* The touch position structure */
typedef struct
{
    /* The coordinates of this event */
    vm_pen_point_struct pos;
    /* The timestamp of this event */
    VMUINT32 timestamp;
} vm_touch_pos_struct;

/*
 *  Each finger touch data information
 *  Example:
 *  typedef struct
 *  {
 *      vm_pen_point_struct down_pos; // ((200, 110), 29999)
 *      VMUINT16 merge_num; // 2
 *      vm_pen_point_struct* merge_points; // ((200, 200), 30010), ((200, 250), 30020)
 *      VMUINT16* merge_area; // (50, 40)
 *  } mmi_touch_data_struct;
 */
typedef struct
{
    VMUINT16 id; /* finger id */
    VMINT  event; /* current touch event */
    vm_touch_pos_struct currpos; /* current touch info */
    VMUINT16 area; /* current finger area */
    VMINT pre_event; /* previous touch event */
    vm_touch_pos_struct pre_pos; /* previous touch info */
    vm_touch_pos_struct down_pos; /* pen down info */
    VMUINT16 merge_num;  /* if there are several pen move events, we will send several pen move events together to application */
    vm_touch_pos_struct* merge_points; /* pen move events array */
    VMUINT16* merge_area; /* related pen move area */
} vm_multi_touch_data_struct;

typedef struct 
{
    /* The finger number of this event, at most it is five */
    VMUINT16 touch_num;
    /* The touch data of each event */
    vm_multi_touch_data_struct * touch_data;
}vm_multi_touch_event_struct;

/*****************************************************************************
 * FUNCTION
 *  vm_multi_touch_get_mode
 * DESCRIPTION
 *  get current screen touch mode
 * PARAMETERS
 *  void
 * RETURNS
 *  VMINT
 *****************************************************************************/
VMINT vm_multi_touch_get_mode(void);

/*****************************************************************************
 * FUNCTION
 *  vm_multi_touch_set_mode
 * DESCRIPTION
 *  set touch screen mode
 * PARAMETERS
 *  mode : [IN] the parameter should be vm_touch_mode, single or multiple
 * RETURNS
 *  VMINT
 *****************************************************************************/
VMINT vm_multi_touch_set_mode(vm_touch_mode mode);

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 * FUNCTION
 *  vm_multi_touch_proc_t
 * DESCRIPTION
 * PARAMETERS
 *  param : [IN] vm_multi_touch_event_struct.
 *  user_data : [IN] user data.
 * RETURNS
 *  VMINT
 *****************************************************************************/
typedef VMINT (*vm_multi_touch_proc_t) (vm_multi_touch_event_struct * evt_info, void * user_data);

/*****************************************************************************
 * FUNCTION
 *  vm_touch_register_proc
 * DESCRIPTION
 *  Register touch proc by screen level, no need to reset, the single touch event or
 * PARAMETERS
 *  proc : [IN] the proc, the event in the proc should be vm_multi_touch_event_struct.
 *  user_data : [IN] user data, framework will send this user_data to your proc
 * RETURNS
 *  vm_touch_register_proc
 *****************************************************************************/
VMINT vm_multi_touch_register_proc(vm_multi_touch_proc_t proc, void *user_data);



/* flag for async fs */
#define VM_FS_READ_WRITE           0x00000000L
#define VM_FS_READ_ONLY            0x00000100L
#define VM_FS_OPEN_SHARED          0x00000200L
#define VM_FS_OPEN_NO_DIR          0x00000400L
#define VM_FS_OPEN_DIR             0x00000800L
#define VM_FS_CREATE               0x00010000L
#define VM_FS_CREATE_ALWAYS        0x00020000L
#define VM_FS_COMMITTED            0x01000000L
#define VM_FS_CACHE_DATA           0x02000000L
#define VM_FS_LAZY_DATA            0x04000000L
#define VM_FS_NONBLOCK_MODE        0x10000000L
#define VM_FS_PROTECTION_MODE      0x20000000L
#define VM_FS_NOBUSY_CHECK_MODE    0x40000000L



typedef VMINT vm_fs_api_enum;
typedef VMINT vm_fs_job_state_enum;
typedef VMINT vm_fs_job_id;
typedef VMINT vm_module_type;
typedef VMINT VM_FS_HANDLE;
typedef VMINT (*vm_fs_async_callback)(vm_fs_job_id jid, VMINT64 * result, void *data);


typedef enum
{
    VM_FS_PRIORITY_DEFAULT         = 0,        // Default: This job will use lower priority to run. Suitable to non-critical jobs.
    VM_FS_PRIORITY_INHERITED,                  // Inherited: This job will inherites the priority of user. Suitable to critical jobs.
    VM_FS_PRIORITY_INVALID         = 0xFF
}vm_fs_prioity_enum;

typedef struct
{
    vm_fs_api_enum             api;        // The API enumeration of this job
    vm_fs_job_state_enum       reserved1;  // Reserved
    VMUINT8               reserved2;  // Reserved
    vm_fs_job_id               jid;         // Job ID. It also appears in the 1st parameter of callback function.
    vm_module_type             reserved3;  // Reserved
    VMINT64               result;     // Execution result of FS API. It also appears in the 2nd parameter of callback function.
    vm_fs_async_callback       callback;   // Callback function pointer
    void                    *param;     // Parameter of callback function. It is defined in by user whenever FS async I/F is used.
    void                    *reserved4;  // Reserved
}vm_fs_async_callback_data_struct;


typedef struct
{
    vm_fs_async_callback_data_struct head;
    VMINT   job_id;
    VMINT    aborted;
}vm_fs_job_abort_struct;

typedef struct
{
    vm_fs_async_callback_data_struct head;
    VMWCHAR *  filename;
    VMUINT  flag;
}vm_fs_job_open_struct;

typedef struct
{
    vm_fs_async_callback_data_struct head;
    VMINT   fs_hdl;
    void        * data;
    VMUINT  length;
    VMUINT  * read;
}vm_fs_job_read_struct;

typedef struct
{
    vm_fs_async_callback_data_struct head;
    VMINT   fs_hdl;
    void        * data;
    VMUINT  length;
    VMUINT  * written;
}vm_fs_job_write_struct;

typedef struct
{
    vm_fs_async_callback_data_struct head;
    const VMWCHAR * filename;
}vm_fs_job_delete_struct;

typedef struct
{
    vm_fs_async_callback_data_struct head;
    VMINT   fs_hdl;
    VMINT64   offset;
    VMINT   whence;
}vm_fs_job_seek_struct;


typedef struct
{
    vm_fs_prioity_enum         priority;   // priority configuration of this job
    vm_fs_async_callback       callback;   // callback function pointer
    void                    *param;     // parameter of callback function
}vm_fs_overlapped_struct;

/*****************************************************************************
 * FUNCTION
 *    fs_aysnc_open
 *
 * DESCRIPTION
 *    Open a file
 *
 * PARAMETERS
 *  filename         :[IN]  Must point to the name of the file to open/create.
 *                          File names are not case sensitive; they will be converted to
 *                          upper case when file system searches this file, and they should
 *                          be two-byte aligned and UCS2 encoded. The file name can have one
 *                          of the following formats:
 *  flag             :[IN]  Can be a combination of the following flags:
 *                          VM_FS_READ_WRITE       VM_FS_READ_ONLY        VM_FS_OPEN_SHARED      VM_FS_OPEN_NO_DIR
 *                          VM_FS_OPEN_DIR         VM_FS_CREATE           VM_FS_CREATE_ALWAYS    VM_FS_COMMITTED
 *                          VM_FS_CACHE_DATA       VM_FS_LAZY_DATA        VM_FS_ATTR_HIDDEN      VM_FS_ATTR_SYSTEM
 *                          VM_FS_ATTR_ARCHIVE     VM_FS_NONBLOCK_MODE    VM_FS_PROTECTION_MODE
 *  overlapped       :[IN]  Overlapped structure has 3 members,
 *                          1. callback :[IN]   (Optional) Call back function. This function will be executed just after response message is received by user.
 *                          2. param    :[IN]   (Optional) Parameters for call back function
 *                          3. priority :[IN]   (*Required) Priority of this job, it can be any one of following options,
 *                                                  1. VM_FS_PRIORITY_DEFAULT  : User has no priority concern for this job)
 *                                                  2. VM_FS_PRIORITY_INHERITED: FS task will be raised to a higher priorty to execute this job)
 * RETURNS
 *  Successful  : A positive integer. It is Job ID.
 *  Failed      : A negative integer. -1 means no authorization.
 *****************************************************************************/
VMINT vm_fs_async_open(const VMWSTR file_name, VMINT flag, vm_fs_overlapped_struct *overlapped);

/*****************************************************************************
 * FUNCTION
 *    vm_fs_async_write
 *
 * DESCRIPTION
 *    Write data to a file
 *
 * PARAMETERS
 *  fs_hdl          :[IN]   file handle, get it from *result in VMINT (*vm_fs_async_callback)(vm_fs_job_id jid, VMINT64 * result, void *data);
 *  data            :[IN]   Specifies the address of the data to be written.
 *  length          :[IN]   Specifies the number of bytes to write.
 *  written         :[OUT]  Pointer to an unsigned integer to receive the number of
 *                          bytes actually been written. Usually, *Written will contain
 *                          Length after the call. However, in case of an error, the
 *                          returned value may be less. Written may be set to NULL if
 *                          this information is not required by an application.
 *  overlapped       :[IN]  Overlapped structure has 3 members,
 *                          1. callback :[IN]   (Optional) Call back function. This function will be executed just after response message is received by user.
 *                          2. param    :[IN]   (Optional) Parameters for call back function
 *                          3. priority :[IN]   (*Required) Priority of this job, it can be any one of following options,
 *                                                  1. VM_FS_PRIORITY_DEFAULT  : User has no priority concern for this job)
 *                                                  2. VM_FS_PRIORITY_INHERITED: FS task will be raised to a higher priorty to execute this job)
 * RETURNS
 *  Successful  : A positive integer. It is Job ID.
 *  Failed      : A negative integer. -1 means no authorization.
 *****************************************************************************/
VMINT vm_fs_async_write(VM_FS_HANDLE fs_hdl, void *data, VMUINT length, VMUINT *written, vm_fs_overlapped_struct *overlapped);

/*****************************************************************************
 * FUNCTION
 *    vm_fs_async_write
 *
 * DESCRIPTION
 *    Read data to a file
 *
 * PARAMETERS
 *  fs_hdl          :[IN]   file handle, get it from *result in VMINT (*vm_fs_async_callback)(vm_fs_job_id jid, VMINT64 * result, void *data);
 *  data            :[IN]   Specifies the address of the data to be read.
 *  length          :[IN]   Specifies the number of bytes to write.
 *  read         :[OUT]  Pointer to an unsigned integer to receive the number of
 *                          bytes actually been read. Usually, *Written will contain
 *                          Length after the call. However, in case of an error, the
 *                          returned value may be less. Written may be set to NULL if
 *                          this information is not required by an application.
 *  overlapped       :[IN]  Overlapped structure has 3 members,
 *                          1. callback :[IN]   (Optional) Call back function. This function will be executed just after response message is received by user.
 *                          2. param    :[IN]   (Optional) Parameters for call back function
 *                          3. priority :[IN]   (*Required) Priority of this job, it can be any one of following options,
 *                                                  1. VM_FS_PRIORITY_DEFAULT  : User has no priority concern for this job)
 *                                                  2. VM_FS_PRIORITY_INHERITED: FS task will be raised to a higher priorty to execute this job)
 * RETURNS
 *  Successful  : A positive integer. It is Job ID.
 *  Failed      : A negative integer. -1 means no authorization.
 *****************************************************************************/
VMINT vm_fs_async_read(VM_FS_HANDLE fs_hdl, void *data, VMUINT length, VMUINT *read, vm_fs_overlapped_struct *overlapped);

/*****************************************************************************
 * FUNCTION
 *    vm_fs_async_seek
 *
 * DESCRIPTION
 *    Seek to a specific position of a file
 *
 * PARAMETERS
 *  fs_hdl          :[IN]   file handle, get it from *result in VMINT (*vm_fs_async_callback)(vm_fs_job_id jid, VMINT64 * result, void *data);
 *  offset          :[IN]   Specifies the offset (bytes) of the file to be seeked.
 *  whence          :[IN]   Specifies the method (start address) of the seek.
 *  overlapped       :[IN]  Overlapped structure has 3 members,
 *                          1. callback :[IN]   (Optional) Call back function. This function will be executed just after response message is received by user.
 *                          2. param    :[IN]   (Optional) Parameters for call back function
 *                          3. priority :[IN]   (*Required) Priority of this job, it can be any one of following options,
 *                                                  1. VM_FS_PRIORITY_DEFAULT  : User has no priority concern for this job)
 *                                                  2. VM_FS_PRIORITY_INHERITED: FS task will be raised to a higher priorty to execute this job)
 * RETURNS
 *  Successful  : A positive integer. It is Job ID.
 *  Failed      : A negative integer. -1 means no authorization.
 *****************************************************************************/
VMINT vm_fs_async_seek(VM_FS_HANDLE fs_hdl, VMINT64 * offset, VMINT whence, vm_fs_overlapped_struct *overlapped);


/*****************************************************************************
 * FUNCTION
 *    vm_fs_async_delete
 *
 * DESCRIPTION
 *    Delete a file
 *
 * PARAMETERS
 *  filename        :[IN]   References the open file to seek to.
 *  overlapped       :[IN]  Overlapped structure has 3 members,
 *                          1. callback :[IN]   (Optional) Call back function. This function will be executed just after response message is received by user.
 *                          2. param    :[IN]   (Optional) Parameters for call back function
 *                          3. priority :[IN]   (*Required) Priority of this job, it can be any one of following options,
 *                                                  1. VM_FS_PRIORITY_DEFAULT  : User has no priority concern for this job)
 *                                                  2. VM_FS_PRIORITY_INHERITED: FS task will be raised to a higher priorty to execute this job)
 * RETURNS
 *  Successful  : A positive integer. It is Job ID.
 *  Failed      : A negative integer. -1 means no authorization.
 *****************************************************************************/
VMINT vm_fs_async_delete(const VMWSTR filename, vm_fs_overlapped_struct *overlapped);

/*****************************************************************************
 * FUNCTION
 *  vm_fs_async_abort
 *
 * DESCRIPTION
 *  This function provides the facility to abort a specific job by Job ID
 *
 * PARAMETERS
 *  jid      :[IN]   Job ID
 * 
 * RETURNS
 *  Successful  : A non-negative integer
 *  Failed      : A negative integer. -1 means no authorization.
 *****************************************************************************/
VMINT vm_fs_async_abort(vm_fs_job_id jid);


/*****************************************************************************
 * FUNCTION
 *  vm_fs_async_commit
 *
 * PARAMETERS
 *  fs_hdl          :[IN]   file handle, get it from *result in VMINT (*vm_fs_async_callback)(vm_fs_job_id jid, VMINT64 * result, void *data);
 *
 * DESCRIPTION
 *  Immediately flushes all buffers associated with a file to disk.
 *
 * PARAMETERS
 *  jid      :[IN]   Job ID
 * 
 * RETURNS
 *  Successful  : A non-negative integer
 *  Failed      : A negative integer. -1 means no authorization.
 *****************************************************************************/
VMINT vm_fs_async_commit(VM_FS_HANDLE fs_hdl);

/*****************************************************************************
 * FUNCTION
 *  vm_fs_async_close
 *
 * PARAMETERS
 *  fs_hdl          :[IN]   file handle, get it from *result in VMINT (*vm_fs_async_callback)(vm_fs_job_id jid, VMINT64 * result, void *data);
 *
 * DESCRIPTION
 *  Immediately flushes all buffers associated with a file to disk.
 *
 * RETURNS
 *  Successful  : A non-negative integer
 *  Failed      : A negative integer. -1 means no authorization.
 *****************************************************************************/
VMINT vm_fs_async_close(VM_FS_HANDLE fs_hdl);

VMINT vm_fs_async_get_working_buf_size(void);

/*****************************************************************************
 * FUNCTION
 *  vm_kbd_is_key_supported
 * DESCRIPTION
 *  query if specified key code is supported
 * PARAMETERS
 *  keycode    [IN]    key code
 * RETURNS
 *  non-zero  : supported.
 *  zero      : unsupported
 *****************************************************************************/
VMINT vm_kbd_is_key_supported(VMINT keycode);


/* This enumeration defines the error code of dispatching URI request or registering URI request handler by scheme or by prefix. */
typedef enum
{
    VM_SRV_URIAGENT_ERR_OK,                    /* Success to process this request. */
    VM_SRV_URIAGENT_ERR_SCHEME_IS_REGISTERED,  /* Fail to process this registration  because handler was already registered for this scheme; this error code is used for URI request handler registration only. */
    VM_SRV_URIAGENT_ERR_PREFIX_IS_REGISTERED,  /* Fail to process this registration  because handler was already registered for this prefix; this error code is used for URI request handler registration only. */
    VM_SRV_URIAGENT_ERR_PROCESSING,            /* Fail to process this URI request because the previous request from the same URA is  still in processing; this error code is used for URI request dispatch only. */
    VM_SRV_URIAGENT_ERR_UNSUPPORTED            /* Fail to process this request. */
}vm_srv_uriagent_err_enum;


/*****************************************************************************
 * FUNCTION
 *  vm_uriagent_uri_request
 * DESCRIPTION
 *  wtai
 * PARAMETERS
 *  str    [IN]    string of wati
 *  confirm    [IN]    confirm
 * RETURNS
 *  -1 : no authorization
 *  -2 : not be supported
 *  refer to vm_srv_uriagent_err_enum
 *****************************************************************************/
VMINT vm_uriagent_uri_request(const VMCHAR * str, VMINT confirm);

/*****************************************************************************
 * FUNCTION
 *  vm_start_native_browser
 * DESCRIPTION
 *  query if specified key code is supported
 * PARAMETERS
 *  url    [IN]    open native browser if there dose exist.
 * RETURNS
 *  -1 : no authorization
 *  -2 : not be supported
 *  refer to return value of vm_open_wap_url 
 *****************************************************************************/
VMINT vm_start_native_browser(const VMWSTR url);

#ifdef __cplusplus
}
#endif

#endif /* VMIO_SDK_H_ */ 

