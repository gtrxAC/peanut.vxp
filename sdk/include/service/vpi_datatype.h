/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vpi_animation_interface.h
 *
 * Project:
 * --------
 *  Venus Plug-in Core
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  Jun Liu (mtk80064)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VPI_DATATYPE_H__
#define __VPI_DATATYPE_H__

#include "vmio.h"
#include "vmsys.h"

/*****************************************************************************
 * Define
 *****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
#define VM_STRUCT_HEADER \
            VMUINT32 _size;

#define VM_STRUCT_SIZE(_struct) \
            ((_struct)._size)

#define VM_STRUCT_INIT(_struct, _type) \
            do { \
                (_struct)._size = sizeof(_type); \
            } while (0)

#define VM_END_OF_ENUM_VALUE 0x7FFFFFFF

#define VM_END_OF_ENUM(_enum) End_of_enum_##_enum = 0x7FFFFFFF

#define VM_ALIGN_TO_4(_n)              (((_n) + 3) / 4 * 4)
#define VM_CALLBACK_STRUCT_SIZE(_type, _user_data_size) \
        (VM_ALIGN_TO_4(sizeof(_type)) + VM_ALIGN_TO_4(_user_data_size))
#define VM_CALLBACK_STRUCT_PTR_SIZE(_ptr) \
        ((_ptr) == NULL ? \
            0 : \
            VM_ALIGN_TO_4(sizeof(*_ptr) + VM_ALIGN_TO_4((_ptr)->userDataSize)))
#define VM_CALLBACK_STRUCT_DATA(_ptr) \
        ((_ptr)->userDataSize == 0 ? \
            NULL : \
            (void *)((VMUINT8 *)(_ptr) + VM_ALIGN_TO_4(sizeof(*_ptr))))
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * Basic datatype
 *****************************************************************************/
/* Color type ID */
typedef enum
{
    VM_COLOR_TYPE_UNKNOWN = 0,

    /* alpha format */
    VM_COLOR_TYPE_ARGB8888,
    VM_COLOR_TYPE_PARGB8888,
    VM_COLOR_TYPE_PARGB6666,
    VM_COLOR_TYPE_A8,

    /* non alpha format */
    VM_COLOR_TYPE_RGB565,
    VM_COLOR_TYPE_RGB888,
    VM_COLOR_TYPE_UYVY422,
    VM_COLOR_TYPE_D16,
    VM_COLOR_TYPE_S8,

    /* not real color format */
    VM_COLOR_TYPE_RGB565_FULLY_OPAQUE,
    VM_COLOR_TYPE_RGB888_FULLY_OPAQUE,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_color_type_enum)
} vm_color_type_enum;

/* File Raw data format*/
typedef enum
{
    VM_FILE_FORMAT_TYPE_AUTO,

    /* BMP Image Format */
    VM_FILE_FORMAT_TYPE_BMP,

    /* GIF Image Format */
    VM_FILE_FORMAT_TYPE_GIF,

    /* GIF Image Format */
    VM_FILE_FORMAT_TYPE_PNG,

    /* JPG Image Format */
    VM_FILE_FORMAT_TYPE_JPG,

    /* ABM Image Format */
    VM_FILE_FORMAT_TYPE_ABM,

    /* AB2 Image Format */
    VM_FILE_FORMAT_TYPE_AB2,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_file_raw_data_format_enum)
} vm_file_raw_data_format_enum;

/* Point type */
typedef struct _vm_point_struct
{
    VMINT32 x;
    VMINT32 y;
} vm_point_struct;

typedef vm_point_struct * vm_point_struct_p;

/* Size type */
typedef struct _vm_size_struct
{
    VMINT32 width;
    VMINT32 height;
} vm_size_struct;

typedef vm_size_struct * vm_size_struct_p;

/* Rectangle type */
typedef struct _vm_rect_struct
{
    vm_point_struct origin;
    vm_size_struct  size;
} vm_rect_struct;

typedef vm_rect_struct * vm_rect_struct_p;

/* Point type with floating point */
typedef struct _vm_fpoint_struct
{
    VMFLOAT x;
    VMFLOAT y;
} vm_fpoint_struct;

typedef vm_fpoint_struct * vm_fpoint_struct_p;

/* Size type with floating point */
typedef struct _vm_fsize_struct
{
    VMFLOAT width;
    VMFLOAT height;
} vm_fsize_struct;

typedef vm_fsize_struct * vm_fsize_struct_p;

/* Rectangle type with floating point */
typedef struct _vm_frect_struct
{
    vm_fpoint_struct origin;
    vm_fsize_struct  size;
} vm_frect_struct;

typedef vm_frect_struct * vm_frect_struct_p;

/*
 * Transform
 */
/* 3 * 3 matrix type */
typedef struct _vm_matrix3x3_struct
{
    VMFLOAT m[9];
} vm_matrix3x3_struct;

typedef vm_matrix3x3_struct * vm_matrix3x3_struct_p;

/* 3 * 3 matrix type (s32)*/
typedef struct
{
    VMINT32 m[9];
} vm_matrix3x3_s32_struct;

/* 4 * 4 matrix type */
typedef struct _vm_matrix4x4_struct
{
    VMFLOAT m[16];
} vm_matrix4x4_struct;

typedef vm_matrix4x4_struct * vm_matrix4x4_struct_p;

/* 2D affine transform parameters
 * The process order is scaling -> rotation -> translation */
typedef struct
{
    VMFLOAT sx, sy;        /* scaling */
    VMFLOAT rz;            /* rotation */
    VMFLOAT tx, ty;        /* translation */
} vm_affine_parameter_struct;

/* transform type */
typedef enum
{
    VM_TRANSFORM_TYPE_IDENTITY,
    VM_TRANSFORM_TYPE_AFFINE,
    VM_TRANSFORM_TYPE_MATRIX3X3,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_transform_type_enum)
} vm_transform_type_enum;

/* transform structure */
typedef struct _vm_transform_struct
{
    vm_transform_type_enum type;        /* the transform type */
    union
    {
        /* no data needed for identity type */
        vm_affine_parameter_struct  affine;     /* data for affine transfrom type */
        vm_matrix3x3_struct         matrix3x3;  /* data for matrix 3x3 transfrom type */
        vm_matrix3x3_s32_struct     matrix3x3_s32;
    } data;                             /* the transform data, choose by type */
} vm_transform_struct;

typedef vm_transform_struct * vm_transform_struct_p;

/* type id */
typedef enum
{
    VM_TYPE_ID_UNKNOWN = 0,
    VM_TYPE_ID_BOOL,
    VM_TYPE_ID_FLOAT,
    VM_TYPE_ID_S8,
    VM_TYPE_ID_U8,
    VM_TYPE_ID_S16,
    VM_TYPE_ID_U16,
    VM_TYPE_ID_S32,
    VM_TYPE_ID_U32,
    VM_TYPE_ID_S64,
    VM_TYPE_ID_U64,
    VM_TYPE_ID_CHAR,
    VM_TYPE_ID_WCHAR,
    VM_TYPE_ID_FLAG,
    VM_TYPE_ID_MSEC,
    VM_TYPE_ID_COLOR,
    VM_TYPE_ID_POINT,
    VM_TYPE_ID_SIZE,
    VM_TYPE_ID_RECT,
    VM_TYPE_ID_FPOINT,
    VM_TYPE_ID_FSIZE,
    VM_TYPE_ID_FRECT,
    VM_TYPE_ID_TRANSFORM,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_type_id_enum)
} vm_type_id_enum;


/*****************************************************************************
 * Font
 *****************************************************************************/
/* font engine color type */
typedef struct
{
    VMUINT8 a;    /* alpha */
    VMUINT8 r;    /* red   */
    VMUINT8 g;    /* greed */
    VMUINT8 b;    /* blue  */
} vm_fe_color;

/* font effect color, identical to stFontColor */
typedef struct
{
    VM_STRUCT_HEADER
    vm_fe_color bordered_color;                /* The bordered color */
    vm_fe_color first_gradient_color;          /* The text color for gradient effect. It works with existing text color to present the gradient effect */
    vm_fe_color second_gradient_color;         /* The text color for gradient effect. It works with existing text color to present the gradient effect */
    vm_fe_color shadow_color;                  /* The shadow color */
    vm_fe_color outerglow_color;               /* The shadow color */
    vm_fe_color upper_engraved_color;          /* The engraved color  */
    vm_fe_color lower_engraved_color;          /* The engraved color  */
} vm_font_effect_color;

/* font effect attributes */
typedef struct
{
    VM_STRUCT_HEADER
    VMINT16 shadow_degree;                  /* The degree of change of shadow color. It presents the direction of the light. The degree is limited to 0¢X, 45¢X, 90¢X, 135¢X, 180¢X, 225¢X, 270¢X, 315¢X*/
    VMINT16 engraved_degree;                /* The degree of change of shadow */
    VMUINT8 shadow_distant;                 /* The distant between the shadow original to the text original */
    VMUINT8 shadow_range;                   /* The shadow range */
    VMUINT8 shadow_transparency;            /* The shadow intensity */
    VMUINT8 border_size;                    /* The size of the border */
    VMUINT8 gradient_direction;             /* The direction of gradient */
    VMUINT8 gradient_transparency;          /* The direction of gradient */
    VMUINT8 outerglow_range;                /* The outer glow range */
    VMUINT8 outerglow_transparency;         /* The shadow intensity */
    VMUINT8 engraved_transparency;          /* The shadow intensity */
    VMUINT8 border_transparency;            /* The shadow intensity */
} vm_font_effect_attr;

/* font description */
typedef struct _vm_font_desc_struct
{
    VM_STRUCT_HEADER
    VMUINT8  size;       // Font size. Default size is VM_FONT_DESC_SIZE_MEDIUM.
    VMUINT32 attr;       // Font attribute. Default attribute is VM_FONT_DESC_ATTR_NORMAL.
    VMUINT8  effect;     // Font effect. Default effect is VM_FONT_DESC_EFFECT_NONE.
} vm_font_desc_struct;

/* font effect */
typedef struct _vm_font_effect_struct
{
    VM_STRUCT_HEADER

    vm_fe_color bordered_color;                /* The bordered color */
    vm_fe_color first_gradient_color;          /* The text color for gradient effect. It works with existing text color to present the gradient effect */
    vm_fe_color second_gradient_color;         /* The text color for gradient effect. It works with existing text color to present the gradient effect */
    vm_fe_color shadow_color;                  /* The shadow color */
    vm_fe_color outerglow_color;               /* The shadow color */
    vm_fe_color upper_engraved_color;          /* The engraved color  */
    vm_fe_color lower_engraved_color;          /* The engraved color  */

    VMINT16 shadow_degree;                  /* The degree of change of shadow color. It presents the direction of the light. The degree is limited to 0¢X, 45¢X, 90¢X, 135¢X, 180¢X, 225¢X, 270¢X, 315¢X*/
    VMINT16 engraved_degree;                /* The degree of change of shadow */
    VMUINT8 shadow_distant;                 /* The distant between the shadow original to the text original */
    VMUINT8 shadow_range;                   /* The shadow range */
    VMUINT8 shadow_transparency;            /* The shadow intensity */
    VMUINT8 border_size;                    /* The size of the border */
    VMUINT8 gradient_direction;             /* The direction of gradient */
    VMUINT8 gradient_transparency;          /* The direction of gradient */
    VMUINT8 outerglow_range;                /* The outer glow range */
    VMUINT8 outerglow_transparency;         /* The shadow intensity */
    VMUINT8 engraved_transparency;          /* The shadow intensity */
    VMUINT8 border_transparency;            /* The shadow intensity */

    VMUINT8 attribute_id;
    VMUINT8 effect_type;
    VMUINT8 node_type;
    void *user_data;
} vm_font_effect_struct;

// Font attribute flags
#define VM_FONT_DESC_ATTR_NORMAL           0           // Normal style
#define VM_FONT_DESC_ATTR_BOLD             (1 << 0)    // Bold style
#define VM_FONT_DESC_ATTR_OBLIQUE          (1 << 1)    // Oblique style
#define VM_FONT_DESC_ATTR_ITALIC           (1 << 2)    // Italic style
#define VM_FONT_DESC_ATTR_UNDERLINE        (1 << 3)    // Underline style
#define VM_FONT_DESC_ATTR_STRIKETHROUGH    (1 << 4)    // Strike through style
#define VM_FONT_DESC_ATTR_MONOSPACE        (1 << 5)    // Monospace style

// Font size enumeration
enum VMFontDescSizeEnum
{
    VM_FONT_DESC_SIZE_SMALL = 0,       // Small font size
    VM_FONT_DESC_SIZE_MEDIUM,          // Medium font size
    VM_FONT_DESC_SIZE_LARGE,           // Large font size
    VM_FONT_DESC_SIZE_SUBLCD,          // font size for sub LCD
    VM_FONT_DESC_SIZE_DIALER,          // font size for dialer
    VM_FONT_DESC_SIZE_NUM_1,
    VM_FONT_DESC_SIZE_NUM_2,
    VM_FONT_DESC_SIZE_VK,
    VM_FONT_DESC_SIZE_VK_LARGE,

    /* Add new enums above this */
    VM_END_OF_ENUM(VMFontDescSizeEnum)
};

#define VM_FONT_DESC_VF 0x80

// Vector font size
#define VM_FONT_DESC_VF_SIZE(_size)    (VM_FONT_DESC_VF | (_size))

// Font effect type enumeration
enum VMFontEffectTypeEnum
{
    VM_FONT_EFFECT_NONE = 0,                            // No effect
    VM_FONT_EFFECT_SHADOW = 2,                          // Drop-shadow effect
    VM_FONT_EFFECT_OUTER_GLOW,                          // Outer-glow effect
    VM_FONT_EFFECT_ENHANCED_ENGRAVE,                    // Enhanced engrave effect
    VM_FONT_EFFECT_GRADIENT,                            // Gradient effect
    VM_FONT_EFFECT_ENHANCED_BORDER,                     // Enhanced Border effect
    VM_FONT_EFFECT_GRADIENT_DROP_SHADOW,                // Gradient and Drop-shadow effect
    VM_FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE,           // Grandient and enhanced engrave effect

    /* Add new enums above this */
    VM_END_OF_ENUM(VMFontEffectTypeEnum)
};

// Pre-defined Effect ID Enum
enum VMFontDescEffectEnum
{
    VM_FONT_DESC_EFFECT_NONE = 0,                       // No effect
    VM_FONT_DESC_EFFECT_STRIKETHROUGH,                  // Strikethrough effect
    VM_FONT_DESC_EFFECT_BORDER,                         // Border effect
    /* Add new enums above this */
    VM_END_OF_ENUM(VMFontDescEffectEnum)
};


/*****************************************************************************
 * String
 *****************************************************************************/
/* string buffer type */
typedef enum _vm_wstring_buf_type_enum
{
    BUF_TYPE_NONE       = 0,
    BUF_TYPE_DYNAMIC    = (1 << 0),
    BUF_TYPE_RESOURCE   = (1 << 1),      // The buffer is from resource
    BUF_TYPE_LOCK       = (1 << 2),      // The buffer has been locked

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_wstring_buf_type_enum)
} vm_wstring_buf_type_enum;

/* string structure */
typedef struct _vm_wstring_struct
{
    vm_wstring_buf_type_enum m_bufType;
    const VMUWCHAR *m_buf;
} vm_wstring_struct;


/*****************************************************************************
 * Image resource
 *****************************************************************************/
/* Image buffer structure */
typedef struct _vm_image_buffer_struct
{
    VMUINT8 *buf_p;                     /* pointer to the begine of image buffer */
    VMUINT32 pitch_bytes;               /* memory address difference of two lines */
    VMUINT32 width;                     /* pixel number of image width */
    VMUINT32 height;                    /* pixel number of image height */
    vm_color_type_enum color_format;    /* the color format of the image buffer */
} vm_image_buffer_struct;

/* Image buffer structure */
typedef struct _vm_file_raw_data_struct
{
    VMUINT8 *ptr;                                  /* Pointer to the image buffer*/
    VMUINT32 image_size;                           /*Image Memoryy size */
    vm_file_raw_data_format_enum image_format;  /* Image Format */
} vm_file_raw_data_struct;

/* Image source type */
typedef enum _vm_image_source_type_enum
{
    VM_IMAGE_SRC_TYPE_NULL = 0,        // Null image
    VM_IMAGE_SRC_TYPE_RES_ID,          // Image from resource ID
    VM_IMAGE_SRC_TYPE_MEM,             // Image from a memory pointer with image resource 8-bytes header
    VM_IMAGE_SRC_TYPE_IMAGE_BUFFER,    // Image from image buffer
    VM_IMAGE_SRC_TYPE_PATH,            // Image from file path
    VM_IMAGE_SRC_TYPE_MRE_RES_ID,      // Image from MRE resource ID
    VM_IMAGE_SRC_TYPE_FILE_RAW_DATA,   // Image data from file raw data

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_image_source_type_enum)
} vm_image_source_type_enum;

/* Image source structure */
typedef struct _vm_image_source_struct
{
    VM_STRUCT_HEADER
    vm_image_source_type_enum m_type;
    vm_size_struct m_proxySize;
    VMINT m_handle;
    union
    {
        VMRESID                 resIdValue;
        const VMUINT8           *memValue;
        vm_image_buffer_struct  imgBuf;
        vm_wstring_struct       path;
        vm_file_raw_data_struct rawData;
    } m_value;
    void *m_fileInfo;
} vm_image_source_struct;

typedef vm_image_source_struct * vm_image_source_struct_p;

/*****************************************************************************
 * Frame
 *****************************************************************************/
// Default frame background color
#define VM_FRAME_DEFAULT_BG_COLOR      VM_COLOR32_TRANSPARENT
// Default frame border color
#define VM_FRAME_DEFAULT_BORDER_COLOR  VM_COLOR32_WHITE

// Frame aligner side enum
typedef enum
{
    VM_FRAME_ALIGNER_SIDE_LEFT,    // left
    VM_FRAME_ALIGNER_SIDE_TOP,     // top
    VM_FRAME_ALIGNER_SIDE_RIGHT,   // right
    VM_FRAME_ALIGNER_SIDE_BOTTOM,  // bottom

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_frame_aligner_side_enum)
} vm_frame_aligner_side_enum;

// Frame aligner mode enum
typedef enum
{
    VM_FRAME_ALIGNER_MODE_NONE,    // Align none
    VM_FRAME_ALIGNER_MODE_SIDE,    // Align side
    VM_FRAME_ALIGNER_MODE_MID,     // Align mid

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_frame_aligner_mode_enum)
} vm_frame_aligner_mode_enum;

/* Text direction type enum */
typedef enum
{
    VM_MG_TEXT_DIR_TYPE_NORMAL = 0,
    VM_MG_TEXT_DIR_TYPE_L2R = VM_MG_TEXT_DIR_TYPE_NORMAL, /* Left to right */
    VM_MG_TEXT_DIR_TYPE_R2L,                           /* Right to left */

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_text_dir_type_enum)
} vm_text_dir_type_enum;

/* Animatable frame properties */
typedef enum
{
    VM_FRAME_PROPERTY_ID_UNKNOWN = 0,

    VM_FRAME_PROPERTY_ID_FPE_USER_0,

    VM_FRAME_PROPERTY_ID_DIRTY,
    VM_FRAME_PROPERTY_ID_POS = VM_FRAME_PROPERTY_ID_DIRTY,
    VM_FRAME_PROPERTY_ID_POS_X,
    VM_FRAME_PROPERTY_ID_POS_Y,
    VM_FRAME_PROPERTY_ID_ANCHOR_POINT,
    VM_FRAME_PROPERTY_ID_ANCHOR_POINT_X,
    VM_FRAME_PROPERTY_ID_ANCHOR_POINT_Y,
    VM_FRAME_PROPERTY_ID_TRANSFORM,
    VM_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_SX,
    VM_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_SY,
    VM_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_RZ,
    VM_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_TX,
    VM_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_TY,
    VM_FRAME_PROPERTY_ID_OPACITY,
    VM_FRAME_PROPERTY_ID_POS_Z,

    VM_FRAME_PROPERTY_ID_CONTENT_DIRTY,
    VM_FRAME_PROPERTY_ID_BOUNDS = VM_FRAME_PROPERTY_ID_CONTENT_DIRTY,
    VM_FRAME_PROPERTY_ID_BOUNDS_ORIGIN,
    VM_FRAME_PROPERTY_ID_BOUNDS_ORIGIN_X,
    VM_FRAME_PROPERTY_ID_BOUNDS_ORIGIN_Y,
    VM_FRAME_PROPERTY_ID_BOUNDS_SIZE,
    VM_FRAME_PROPERTY_ID_BOUNDS_SIZE_WIDTH,
    VM_FRAME_PROPERTY_ID_BOUNDS_SIZE_HEIGHT,
    VM_FRAME_PROPERTY_ID_BACKGROUND_COLOR,
    VM_FRAME_PROPERTY_ID_BORDER_COLOR,
    VM_FRAME_PROPERTY_ID_BORDER_WIDTH,
    VM_FRAME_PROPERTY_ID_FILTER_TIMING,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_frame_property_id_enum)
} vm_frame_property_id_enum;

/* Frame content placement types */
typedef enum
{
    VM_FRAME_CONTENT_PLACEMENT_TYPE_TOP_LEFT = 0,
    VM_FRAME_CONTENT_PLACEMENT_TYPE_TOP,
    VM_FRAME_CONTENT_PLACEMENT_TYPE_TOP_RIGHT,
    VM_FRAME_CONTENT_PLACEMENT_TYPE_LEFT,
    VM_FRAME_CONTENT_PLACEMENT_TYPE_CENTER,
    VM_FRAME_CONTENT_PLACEMENT_TYPE_RIGHT,
    VM_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM_LEFT,
    VM_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM,
    VM_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM_RIGHT,
    VM_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE,
    VM_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT,
    VM_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_frame_content_placement_type_enum)
} vm_frame_content_placement_type_enum;

/* VM dirty types */
typedef enum
{
    VM_RENDER_DIRTY_TYPE_NONE = 0,
    VM_RENDER_DIRTY_TYPE_DIRTY,
    VM_RENDER_DIRTY_TYPE_CONTENT_DIRTY,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_render_dirty_type_enum)
} vm_render_dirty_type_enum;

/* Frame property effect trigger type */
typedef enum
{
    VM_FPE_TRIGGER_TYPE_EVERYTIME          = 0,
    VM_FPE_TRIGGER_TYPE_DIRTY              = 1 << 0,
    VM_FPE_TRIGGER_TYPE_CONTENT_DIRTY      = 1 << 1,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_frame_property_effect_trigger_type_enum)
} vm_frame_property_effect_trigger_type_enum;

/* VM frame content opaque mode */
typedef enum
{
    /* Automatically detect opaque mode by VM */
    VM_FRAME_OPAQUE_MODE_AUTO = 0,
    /* The frame content has source color key */
    VM_FRAME_OPAQUE_MODE_COLOR_KEY,
    /* The frame content has translucent color. Default value.*/
    VM_FRAME_OPAQUE_MODE_TRANSLUCENT,
    /* The frame content is fully opaque */
    VM_FRAME_OPAQUE_MODE_FULLY_OPAQUE,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_frame_opaque_mode_enum)
} vm_frame_opaque_mode_enum;

/* VM render quality */
typedef enum
{
    VM_RENDER_QUALITY_DEFAULT = 0,
    VM_RENDER_QUALITY_NORMAL,
    VM_RENDER_QUALITY_HIGH,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_render_quality_enum)
} vm_render_quality_enum;

/* Frame culling types */
typedef enum
{
    VM_FRAME_CULLING_TYPE_NONE = 0,
    VM_FRAME_CULLING_TYPE_BACK,
    VM_FRAME_CULLING_TYPE_FRONT,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_frame_culling_type_enum)
} vm_frame_culling_type_enum;

/* Frame cache hint */
typedef enum
{
    VM_CACHE_MODE_AUTO = 0,        /* automatically cache by VM */
    VM_CACHE_MODE_PREVENT_PARENTS, /* prevent this and parents to cache */
    VM_CACHE_MODE_PREVENT,         /* prevent to cache */
    VM_CACHE_MODE_FORCE,           /* force to cache */
    VM_CACHE_MODE_RESOURCE,        /* force to cache without clear */
    VM_CACHE_MODE_FREEZE,          /* force to cache with never dirty */
    VM_CACHE_MODE_TEXTURE,         /* texture frame mode, child frame cache will not be set as useless */

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_cache_mode_enum)
} vm_cache_mode_enum;

/* Frame cache hint */
typedef enum
{
    VM_FRAME_HINTS_DEFAULT             = 0,         /* default hints */
    VM_FRAME_HINTS_RARE_TRANSLUCENT    = 1 << 0,    /* frame with rare translucent pixel */
    VM_FRAME_HINTS_SW_OVERLAY          = 1 << 1,    /* prefer software overlay */
    VM_FRAME_HINTS_SW_LINEARTRANSFORM  = 1 << 2,    /* prefer software linear transform */
    VM_FRAME_HINTS_WATCH_FRAME         = 1 << 3,    /* this frame is watched by other frames */
    VM_FRAME_HINTS_SW_IMG_CONTENT_OVERLAY = 1 << 4, /* 2-pass image content uses software overlay */
    VM_FRAME_HINTS_DISABLE_COLOR_KEY   = 1 << 5,    /* this frame will not use color key */
    VM_FRAME_HINTS_PRECACHE_CHILDREN   = 1 << 6,    /* precache invisible child frame if it is suggested */

    VM_FRAME_HINTS_TEXTURE             = 1 << 7,    /* texture frame */
    VM_FRAME_HINTS_TEXTURE_HIDDEN      = 1 << 8,    /* texture frame but hidden */
    VM_FRAME_HINTS_DEPTH_TEST          = 1 << 9,    /* this frame will use depth buffer for depth testing */
    VM_FRAME_HINTS_STENCIL_TEST        = 1 << 10,   /* this frame will use stencil buffer for stencil testing */

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_frame_hints_enum)
} vm_frame_hints_enum;

// The value to get last frame of animation image
#define VM_ANIM_IMAGE_FRAME_MAX_INDEX 0xFFFFFFFF

// The value to play animation image on infinite times
#define VM_ANIM_IMAGE_FRAME_PLAY_COUNT_INFINIT 0xFFFFFFFF

/* frame visual property callback */
typedef struct
{
    vm_point_struct     pos;                /* anchor point to parent's origin */
    VMFLOAT             pos_z;              /* z position */
    vm_rect_struct      bounds;             /* bounds rect */
    vm_fpoint_struct    anchor_point;       /* anchor point */
    VMFLOAT             opacity;            /* frame opacity */
    vm_transform_struct transform;          /* frame transform */
    VMCOLOR32           background_color;   /* frame background color */

    VMCOLOR32           border_color;       /* border color */
    VMINT32             border_width;       /* border width */

    VMFLOAT             filter_timing;      /* timing value for filters */
    VMFLOAT             fpe_user_0;         /* FPE user property 0 */
} vm_frame_visual_property_struct;

/* frame visual property callback function type */
typedef vm_render_dirty_type_enum (*vm_frame_property_effect_funcptr_type)(
    vm_frame_visual_property_struct *target_frame,
    const vm_frame_visual_property_struct *watch_frame,
    void *user_data,
    VMUINT32 user_data_size);

/* filter kernel callback function */
typedef VMBOOL (*vm_image_filter_kernel_callback_funcptr_type)(
    vm_image_buffer_struct *image_buffer,
    VMUINT8 *out_buf_p,
    void *param, VMFLOAT t);

/* filter buffer mode */
typedef enum
{
    /* output buffer pointer = input buffer pointer */
    VM_IMAGE_FILTER_BUFFER_MODE_IN_PLACE,
    /* output buffer is allocated by VM, content is not initialized. */
    VM_IMAGE_FILTER_BUFFER_MODE_OUT_OF_PLACE,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_image_filter_buffer_mode)
} vm_image_filter_buffer_mode;

/* Owner draw callback */
typedef void (*vm_owner_draw_funcptr_type)(
    vm_image_buffer_struct *image_buffer,
    vm_rect_struct *dst_rect,
    vm_rect_struct *src_rect,
    void *user_data);

/* Owner draw dirty type */
typedef enum
{
    VM_RENDER_OWNER_DRAW_DIRTY_TYPE_NONE = 0,
    VM_RENDER_OWNER_DRAW_DIRTY_TYPE_NORMAL,
    VM_RENDER_OWNER_DRAW_DIRTY_TYPE_TIME_LINE_DIRTY,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_render_owner_draw_dirty_type_enum)
} vm_render_owner_draw_dirty_type_enum;


/*****************************************************************************
 * Animation
 *****************************************************************************/
/* timing function prototype, t is in {0, 1} */
typedef VMFLOAT (*vm_timing_funcptr_type)(
    VMFLOAT t,
    void *data,
    VMUINT32 data_size);

/*
 * timeline timing function callback structure,
 *  the user data is appended after the structre.
 */
typedef struct
{
    vm_timing_funcptr_type callback;   /* the callback function */
    VMUINT32 user_data_size;             /* the user data size in bytes */
} vm_timeline_timing_callback_struct;

/* timeline interpolation return value */
typedef enum
{
    VM_TIMELINE_INTERPOLATION_RET_DONE,
    VM_TIMELINE_INTERPOLATION_RET_USE_DEFAULT,
    VM_TIMELINE_INTERPOLATION_RET_MONITOR,
    VM_TIMELINE_INTERPOLATION_RET_MONITOR_FREEZE,
    VM_TIMELINE_INTERPOLATION_RET_FREEZE,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_timeline_interpolation_ret_enum)
} vm_timeline_interpolation_ret_enum;

/* timeline interpolation callback */
typedef vm_timeline_interpolation_ret_enum (*vm_timeline_interpolation_funcptr_type)(
    void *target,
    const void *from_value,
    const void *to_value,
    vm_type_id_enum type,
    VMFLOAT t,
    void *data,
    VMUINT32 data_size);

/*
 * timeline interpolation function callback structure,
 *  the user data is appended after the structre.
 */
typedef struct
{
    vm_timeline_interpolation_funcptr_type callback;   /* the callback function */
    VMUINT32 user_data_size;                             /* the user data size in bytes */
} vm_timeline_interplation_callback_struct;

/* Predefined timing function ID */
typedef enum
{
    /* Linear timing function. Default value */
    VM_TIMING_FUNC_ID_LINEAR = 0,
    /* Ease timing function. */
    VM_TIMING_FUNC_ID_EASE,
    /* Ease-in timing function. */
    VM_TIMING_FUNC_ID_EASE_IN,
    /* Ease-out timing function. */
    VM_TIMING_FUNC_ID_EASE_OUT,
    /* Ease-in ease-out timing function. */
    VM_TIMING_FUNC_ID_EASE_IN_EASE_OUT,
    /* Damping out timing function. */
    VM_TIMING_FUNC_ID_DAMPING_OUT,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_timing_func_id_enum)
} vm_timing_func_id_enum;

/* Predefined interpolate function ID */
typedef enum
{
    /* Step interpolate function. Default value */
    VM_INTERPOLATE_FUNC_ID_STEP = 0,
    /* Step interpolate function. */
    VM_INTERPOLATE_FUNC_ID_LINEAR,
    /* Linear interpolate function. */
    VM_INTERPOLATE_FUNC_ID_SLERP,
    /* Slerp interpolate function. */
    VM_INTERPOLATE_FUNC_ID_SPLINE,
    /* Spline interpolate function. */
    VM_INTERPOLATE_FUNC_ID_SQUAD,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_interpolate_func_id_enum)
} vm_interpolate_func_id_enum;

/* Timeline time wrap type */
typedef enum
{
    VM_TIMELINE_TIME_WRAP_TYPE_NONE = 0,   /* Bypass Do nothing */
    VM_TIMELINE_TIME_WRAP_TYPE_CLAMP,      /* Clamp in the [0, 1] range */
    VM_TIMELINE_TIME_WRAP_TYPE_REPEAT,     /* Fractional part */
    VM_TIMELINE_TIME_WRAP_TYPE_MIRROR,     /* Mirror */

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_timeline_time_wrap_type_enum)
} vm_timeline_time_wrap_type_enum;


/*****************************************************************************
 * Screen
 *****************************************************************************/
/* Screen rotate type */
typedef enum
{
    VM_SYS_SCREEN_ROTATE_0,
    VM_SYS_SCREEN_ROTATE_90,
    VM_SYS_SCREEN_ROTATE_180,
    VM_SYS_SCREEN_ROTATE_270,
    VM_SYS_SCREEN_ROTATE_MIRROR_0,
    VM_SYS_SCREEN_ROTATE_MIRROR_90,
    VM_SYS_SCREEN_ROTATE_MIRROR_180,
    VM_SYS_SCREEN_ROTATE_MIRROR_270,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_sys_screen_rotate_enum)
} vm_sys_screen_rotate_enum;

/* Screen rotate type */
typedef enum
{
    VM_SCR_ROTATE_TYPE_0               = VM_SYS_SCREEN_ROTATE_0,
    VM_SCR_ROTATE_TYPE_NORMAL          = VM_SYS_SCREEN_ROTATE_0,
    VM_SCR_ROTATE_TYPE_90              = VM_SYS_SCREEN_ROTATE_90,
    VM_SCR_ROTATE_TYPE_180             = VM_SYS_SCREEN_ROTATE_180,
    VM_SCR_ROTATE_TYPE_270             = VM_SYS_SCREEN_ROTATE_270,
    VM_SCR_ROTATE_TYPE_LANDSCAPE       = VM_SYS_SCREEN_ROTATE_270,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_scr_rotate_type_enum)
} vm_scr_rotate_type_enum;

/* Screen rotate structure */
typedef struct _vm_screen_rotate_param_struct
{
    VM_STRUCT_HEADER
    vm_scr_rotate_type_enum rotateFrom;
    vm_scr_rotate_type_enum rotateTo;
    VMMSEC durTime;
} vm_screen_rotate_param_struct;

/* Screen transition type */
typedef enum
{
    VM_SCR_TRANSIT_TYPE_DEFAULT = 0,
    VM_SCR_TRANSIT_TYPE_NONE,

    // System transit types start here
    VM_SCR_TRANSIT_TYPE_APP,
    VM_SCR_TRANSIT_TYPE_SCR,
    VM_SCR_TRANSIT_TYPE_CUI,

    // App transit types start here
    VM_SCR_TRANSIT_TYPE_LOCK,
    VM_SCR_TRANSIT_TYPE_3D_BLIND,
    VM_SCR_TRANSIT_TYPE_3D_CIRCLE,
    VM_SCR_TRANSIT_TYPE_3D_CUBE,
    VM_SCR_TRANSIT_TYPE_3D_BRICK,
    VM_SCR_TRANSIT_TYPE_3D_TWIST,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_scr_transit_type_enum)
} vm_scr_transit_type_enum;


/*****************************************************************************
 * Popup struct
 *****************************************************************************/
/* Popup state */
typedef enum
{
    VM_BASE_POPUP_STATE_UNKNOWN = 0,
    VM_BASE_POPUP_BEFORE_START_ANIMATION,
    VM_BASE_POPUP_AFTER_START_ANIMATION,
    VM_BASE_POPUP_BEFORE_END_ANIMATION,
    VM_BASE_POPUP_AFTER_END_ANIMATION,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_base_popup_state_enum)
} vm_base_popup_state_enum;

/* Popup effect type */
typedef enum
{
    VM_EFFECT_NONE,
    VM_EFFECT_FADE_IN,
    VM_EFFECT_FADE_OUT,
    VM_EFFECT_FADE_OUT_WAVE,
    VM_EFFECT_FLIP,
    VM_EFFECT_PHOTOWALL,
    VM_EFFECT_POPUP,
    VM_EFFECT_MORPH_FADE_IN,
    VM_EFFECT_FLY_OUT,
    VM_EFFECT_RECTANGLE_ROTATE_OUT,
    VM_EFFECT_SMALL_FLIP,
    VM_EFFECT_TRANSFORMER,
    VM_EFFECT_TVCLOSE,
    VM_EFFECT_3D_CIRCLE,
    VM_EFFECT_TITLE_BAR_LIGHT,
    VM_EFFECT_3D_BLING,
    VM_EFFECT_3D_BLUR,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_effect_type_enum)
} vm_effect_type_enum;

/* Popup effect direction */
typedef enum
{
    VM_EFFECT_DIRECTION_FROM_NONE,
    VM_EFFECT_DIRECTION_FROM_RIGHT,
    VM_EFFECT_DIRECTION_FROM_LEFT,
    VM_EFFECT_DIRECTION_FROM_UP,
    VM_EFFECT_DIRECTION_FROM_BOTTOM,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_effect_direction_type_enum)
} vm_effect_direction_type_enum;


/*****************************************************************************
 * Input event
 *****************************************************************************/
/* Pen event type */
typedef enum
{
    // Unknown pen event
    VM_PEN_EVENT_TYPE_UNKNOWN = 0,
    // Pen down event
    VM_PEN_EVENT_TYPE_DOWN,
    // Pen log tap event
    VM_PEN_EVENT_TYPE_LONG_TAP,
    // Pen move event
    VM_PEN_EVENT_TYPE_MOVE,
    // Pen up event
    VM_PEN_EVENT_TYPE_UP,
    // Pen abort event
    VM_PEN_EVENT_TYPE_ABORT,

    // Stroke down event
    VM_PEN_EVENT_TYPE_STROKE_DOWN,
    // Stroke move event
    VM_PEN_EVENT_TYPE_STROKE_MOVE,
    // Stroke up event
    VM_PEN_EVENT_TYPE_STROKE_UP,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_pen_event_type_enum)
} vm_pen_event_type_enum;


/* Pen abort reason type */
typedef enum
{
    VM_PEN_ABORT_REASON_DEFAULT,
    VM_PEN_ABORT_REASON_CAPTURE_SWIPE,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_pen_abort_reason_enum)
} vm_pen_abort_reason_enum;

/* DOM-NOT_FOR_SDK-BEGIN */
class IVpiObject;
typedef struct _vm_object_list_entry_struct
{
    IVpiObject *object;
    struct _vm_object_list_entry_struct *next;
    struct _vm_object_list_entry_struct *prev;
} vm_object_list_entry_struct;

typedef struct _vm_object_list_struct
{
    vm_object_list_entry_struct *head;
    vm_object_list_entry_struct *tail;
} vm_object_list_struct;
/* DOM-NOT_FOR_SDK-END */

/* Pen event structure */
typedef struct _vm_pen_event_struct
{
    VM_STRUCT_HEADER

    // Pen input event type.
    VMUINT16 type;

    // Time stemp of the pen input event.
    VMMSEC timeStamp;

    // Time stemp of the previous pen input event.
    VMMSEC prevTimeStamp;

    // Time stemp of the nearest down pen input event.
    VMMSEC downTimeStamp;

    // The position of the pen event, on global coordinate.
    // SEE ALSO: prevPos, downPos, getRelPos
    vm_point_struct pos;

    vm_point_struct predictPos;

    // The position of the previois pen event, on global coordinate.
    // SEE ALSO: pos, downPos, getRelPrevPos
    vm_point_struct prevPos;

    // The position of the nearest down pen event, on global coordinate.
    // SEE ALSO: pos, prevPos, getRelDownPos
    vm_point_struct downPos;

    // Internal used.
    IVpiObject *source;

    // Internal used.
    IVpiObject *target;

    // Internal used.
    vm_object_list_struct relObjList;
} vm_pen_event_struct;

typedef vm_pen_event_struct * vm_pen_event_struct_p;

/* Key code */
typedef enum
{
    VM_KEY_CODE_UNKNOWN = 0xFFFE,

    // We match Venus Key code as the same as pluto, so that we can speed up the dispatch
    VM_KEY_CODE_BEGIN = 0,
    
    VM_KEY_CODE_0 = 0,
    VM_KEY_CODE_1,
    VM_KEY_CODE_2,
    VM_KEY_CODE_3,
    VM_KEY_CODE_4,
    VM_KEY_CODE_5,
    VM_KEY_CODE_6,
    VM_KEY_CODE_7,
    VM_KEY_CODE_8,
    VM_KEY_CODE_9,

    VM_KEY_CODE_LSK,
    VM_KEY_CODE_RSK,
    VM_KEY_CODE_CSK,

    VM_KEY_CODE_ENTER = VM_KEY_CODE_CSK,
    VM_KEY_CODE_WAP = VM_KEY_CODE_ENTER,
    VM_KEY_CODE_IP = VM_KEY_CODE_ENTER,

    VM_KEY_CODE_ARROW_UP,
    VM_KEY_CODE_ARROW_DOWN,
    VM_KEY_CODE_ARROW_LEFT,
    VM_KEY_CODE_ARROW_RIGHT,
    
    VM_KEY_CODE_SEND,
    VM_KEY_CODE_END,
    VM_KEY_CODE_CLEAR,
    VM_KEY_CODE_STAR,
    VM_KEY_CODE_POUND,
    VM_KEY_CODE_VOL_UP,
    VM_KEY_CODE_VOL_DOWN,
    VM_KEY_CODE_CAMERA,

    VM_KEY_CODE_QUICK_ACS = VM_KEY_CODE_CAMERA,
    VM_KEY_CODE_EXTRA_1,
    VM_KEY_CODE_EXTRA_2,
    VM_KEY_CODE_PLAY_STOP,
    VM_KEY_CODE_FWD,
    VM_KEY_CODE_BACK,
    VM_KEY_CODE_POWER,
    VM_KEY_CODE_EXTRA_A,
    VM_KEY_CODE_EXTRA_B,
    VM_KEY_CODE_SEND1,
    VM_KEY_CODE_SEND2,

    VM_KEY_CODE_HOME,

    VM_KEY_CODE_F1,
    VM_KEY_CODE_F2,
    VM_KEY_CODE_F3,
    VM_KEY_CODE_F4,
    VM_KEY_CODE_F5,
    VM_KEY_CODE_F6,
    VM_KEY_CODE_F7,
    VM_KEY_CODE_F8,
    VM_KEY_CODE_F9,
    VM_KEY_CODE_F10,
    VM_KEY_CODE_F11,
    VM_KEY_CODE_F12,
    VM_KEY_CODE_MESSAGE,

    VM_KEY_CODE_A,
    VM_KEY_CODE_B,
    VM_KEY_CODE_C,
    VM_KEY_CODE_D,
    VM_KEY_CODE_E,
    VM_KEY_CODE_F,
    VM_KEY_CODE_G,
    VM_KEY_CODE_H,
    VM_KEY_CODE_I,
    VM_KEY_CODE_J,
    VM_KEY_CODE_K,
    VM_KEY_CODE_L,
    VM_KEY_CODE_M,
    VM_KEY_CODE_N,
    VM_KEY_CODE_O,
    VM_KEY_CODE_P,
    VM_KEY_CODE_Q,
    VM_KEY_CODE_R,
    VM_KEY_CODE_S,
    VM_KEY_CODE_T,
    VM_KEY_CODE_U,
    VM_KEY_CODE_V,
    VM_KEY_CODE_W,
    VM_KEY_CODE_X,
    VM_KEY_CODE_Y,
    VM_KEY_CODE_Z,
    
    VM_KEY_CODE_SPACE,
    VM_KEY_CODE_TAB,
    VM_KEY_CODE_DEL,
    VM_KEY_CODE_ALT,
    VM_KEY_CODE_CTRL,
    VM_KEY_CODE_WIN,
    VM_KEY_CODE_SHIFT,
    VM_KEY_CODE_QUESTION,
    VM_KEY_CODE_PERIOD,
    VM_KEY_CODE_COMMA,
    VM_KEY_CODE_EXCLAMATION,
    VM_KEY_CODE_APOSTROPHE,
    VM_KEY_CODE_AT,
    VM_KEY_CODE_BACKSPACE,
    VM_KEY_CODE_QWERTY_ENTER,
    VM_KEY_CODE_FN,
    VM_KEY_CODE_SYMBOL,
    VM_KEY_CODE_NUM_LOCK,
    VM_KEY_CODE_QWERTY_MENU,
    VM_KEY_CODE_OK,
    VM_KEY_CODE_DOLLAR,
    VM_KEY_CODE_QWERTY = 230,

    VM_KEY_CODE_END_OF_NORMAL,

    /* Special key codes */
    VM_KEY_CODE_START_OF_SPECIAL,
    VM_KEY_CODE_SPECIAL_ALL,
    VM_KEY_CODE_SPECIAL_ALL_SOFT_KEYS,
    VM_KEY_CODE_SPECIAL_ALL_ARROW,
    VM_KEY_CODE_SPECIAL_ALL_NUMBER,
    VM_KEY_CODE_SPECIAL_ALL_IME_SYM_KEYS,
    
	/* Add new enums above this */
    VM_END_OF_ENUM(vm_key_code_enum)
} vm_key_code_enum;

/* Key event type */
typedef enum
{
    VM_KEY_EVENT_TYPE_UNKNOWN          = 0xFFFE,
    VM_KEY_EVENT_TYPE_FULL_PRESS_DOWN  = 0,
    VM_KEY_EVENT_TYPE_DOWN             = VM_KEY_EVENT_TYPE_FULL_PRESS_DOWN,
    VM_KEY_EVENT_TYPE_UP,
    VM_KEY_EVENT_TYPE_LONG_PRESS,
    VM_KEY_EVENT_TYPE_REPEAT,
    VM_KEY_EVENT_TYPE_HALF_PRESS_DOWN,
    VM_KEY_EVENT_TYPE_HALF_PRESS_UP,

	/* Add new enums above this */
    VM_END_OF_ENUM(vm_key_event_type_enum)
} vm_key_event_type_enum;

/* 
 * Special key means, the keys which can be used together with
 * other keys, such Ctrl + C, Alt + Enter.
 * In QWERTY project, the translate key handler will get the special key flag,
 * the flag indicate the special key is down or not at that time.
 * The following macro is the position of the specific special key in the special key flag
 * of the translate key handler.
 * If the applications want to know the special key is down or not in translate key hander,
 * he may use the following code:
 *  VM_BOOL shift_down = 
 *            (special_key_flags & VM_SPECIAL_KEY_FLAG_SHIFT == VM_SPECIAL_KEY_FLAG_SHIFT)
 *  Notes: The special key flag has special meanings for Input Method Module.
 */
#define VM_SPECIAL_KEY_FLAG_SHIFT      (0x00000001)
/* SEE ALSO: VFX_SPECIAL_KEY_FLAG_SHIFT */
#define VM_SPECIAL_KEY_FLAG_ALT        (0x00000002)
/* SEE ALSO: VFX_SPECIAL_KEY_FLAG_SHIFT */
#define VM_SPECIAL_KEY_FLAG_CAPSLOCK   (0x00000004)
/* SEE ALSO: VFX_SPECIAL_KEY_FLAG_SHIFT */
#define VM_SPECIAL_KEY_FLAG_CTRL       (0x00000008)      
/* SEE ALSO: VFX_SPECIAL_KEY_FLAG_SHIFT */
#define VM_SPECIAL_KEY_FLAG_FN         (0x00000010)        
/* SEE ALSO: VFX_SPECIAL_KEY_FLAG_SHIFT */
#define VM_SPECIAL_KEY_FLAG_NUMLOCK    (0x00000020)   
/* SEE ALSO: VFX_SPECIAL_KEY_FLAG_SHIFT */
#define VM_SPECIAL_KEY_FLAG_ACCESSKEY  0x800000

/* Key event structure */
typedef struct _vm_key_event_struct
{
    VM_STRUCT_HEADER

   // Key input event type
   VMUINT16 type;

   // Key code
   VMUINT16 keycode;

   // UCS2
   VMUWCHAR ucs2;

   // Key special flag, see VM_SPECIAL_KEY_FLAG_XXXX.
   VMUINT32 specialKeyFlag;

   // Time stemp of the key input event
   VMMSEC   timeStamp;
} vm_key_event_struct;

typedef vm_key_event_struct * vm_key_event_struct_p;

typedef void (*callback_funcptr_type)(void *data);


/*****************************************************************************
 * Text Frame struct
 *****************************************************************************/
/* Text align mode */
typedef enum
{
    // The natural alignment according to the system language
    VM_ALIGN_MODE_NATURAL = 0,
    // Align text to the left side of frame bounds
    VM_ALIGN_MODE_LEFT,
    // Align text to the right side of frame bounds
    VM_ALIGN_MODE_RIGHT,
    // Align text to the center of frame bounds
    VM_ALIGN_MODE_CENTER,
    // Align text to the ceter of available area within margin
    VM_ALIGN_MODE_CENTER_WITHIN_MARGIN,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_text_frame_align_mode_enum)
} vm_text_frame_align_mode_enum;

/* Text truncate mode */
typedef enum
{
    // If m_propertyAutoResized is VM_FALSE, the text is clipped to the frame bounds.
    VM_TRUNCATE_MODE_NONE = 0,
    // Add the truncate string at end of missing text.
    VM_TRUNCATE_MODE_END,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_text_frame_truncate_mode_enum)
} vm_text_frame_truncate_mode_enum;

/* Text line mode */
typedef enum
{
    // Single line mode
    VM_LINE_MODE_SINGLE = 0,
    // Multiline mode
    VM_LINE_MODE_MULTI,

    /* Add new enums above this */
    VM_END_OF_ENUM(vm_text_frame_line_mode_enum)
} vm_text_frame_line_mode_enum;


/*****************************************************************************
 * Page struct
 *****************************************************************************/
/* Page bar location type */
typedef enum
{
    VM_PAGE_BAR_LOCATION_TOP,      // Top position, like title bar
    VM_PAGE_BAR_LOCATION_BOTTOM,   // Bottom position, like tool bar

    VM_END_OF_ENUM(vm_page_bar_location_enum)
} vm_page_bar_location_enum;


/*****************************************************************************
 * Basemenu struct
 *****************************************************************************/
/* Base menu position structure */
typedef struct _vm_base_menu_pos_struct
{
    VMINT32 group;
    VMINT32 pos;
} vm_base_menu_pos_struct;


/* Base menu region structure */
typedef struct _vm_base_menu_region_struct
{
    vm_base_menu_pos_struct begin;
    vm_base_menu_pos_struct end;
} vm_base_menu_region_struct;


/* Base menu view state structure */
typedef struct _vm_base_menu_view_state_struct
{
    VM_STRUCT_HEADER
    VMINT32 contentXOffset;
    VMINT32 contentYOffset;
    VMINT32 focusGroup;
    VMINT32 focusPos;
} vm_base_menu_view_state_struct;


/*****************************************************************************
 * Error code
 *****************************************************************************/
typedef VMINT32 VM_RESULT;

/* check if result is succeed */
#define VM_RESULT_CHECK_SUCCEEDED(result) ((result) >= 0)

/* check if result is failed */
#define VM_RESULT_CHECK_FAILED(result) ((result) < 0)

/* Error code: no error */
#define VM_RESULT_SUCCESS (0)

/* Error code: failed */
#define VM_RESULT_FAIL    (-1)

/* Error code: not support */
#define VM_RESULT_NOT_SUPPORT (-2)

/* VM_RESULT error code should be smaller than 0 */

#endif /* __VPI_DATATYPE_H__ */

