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
#ifndef __VPI_ANIMATION_INTERFACE_H__
#define __VPI_ANIMATION_INTERFACE_H__

#include "vmsys.h"
#include "vpi_interface_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"
#include "vpi_object_interface.h"
#include "vpi_frame_interface.h"


// The value to repeat timeline on infinite times
#define VM_TIMELINE_REPEAT_INFINITE 0xFFFFFFFF

/*
 * Interface of BaseTimeline
 */
class IVpiBaseTimeline : public IVpiBase
{
public:

    // The repeat duration time of the timeline, in milisecond.
    //
    // NOTE: Default value is 0. 
    virtual VMMSEC getRepeatDuration() = 0;

    // The repeat count
    //
    // NOTE: Default value is 1. 
    virtual VMMSEC getRepeatCount() = 0;

    // Whether the timeline is auto reversed
    //
    // NOTE: Default value is VM_FALSE. 
    virtual VMBOOL getAutoReversed() = 0;

    // Whether the timeline is from current value
    //
    // NOTE: Default value is VM_TRUE. 
    virtual VMBOOL getIsFromCurrent() = 0;

    // Set durtaion time to start repeat.
    //
    // NOTE: Default value is 0.
    virtual void setRepeatDuration(
        VMMSEC value           // [IN] time(millisecond) to repeat animation.
    ) = 0;

    // Set repeat count of timeline.
    //
    // NOTE: Default value is 1.
    virtual void setRepeatCount(
        VMINT32  value           // [IN] repeat count, VM_TIMELINE_REPEAT_INFINITE means infinite times.
    ) = 0;

    // Whether the timeline will automatically reverse at each repeat duration time.
    //    
    // NOTE: Default value is VFX_False
    virtual void setAutoReversed(VMBOOL value) = 0;

    // Whether the value of time line will start from current value.
    //
    // NOTE: Default value is VM_TRUE.
    virtual void setIsFromCurrent(VMBOOL value) = 0;

    // Whether the timeline is enabled
    virtual VMBOOL getIsEnabled() = 0;

    // An alias to getStartTime
    //
    // RETURNS: The start delay of the timeline
    virtual VMMSEC getStartDelay() = 0;
    
    // An alias to setStartTime
    virtual void setStartDelay(
        VMMSEC value   // [IN] The start delay of the timeline
    ) = 0;

    // An alias to getDurationTime
    //
    // RETURNS: The duration time of the timeline
    virtual VMMSEC getDuration() = 0;

    // An alias to setDurationTime
    virtual void setDuration(
        VMMSEC value   // [IN] The duration time of the timeline
    ) = 0;

    // The data type of target value.
    //
    // NOTE: Default value is 0.
    virtual vm_type_id_enum getTargetType() = 0;

    // Return the target object.
    //
    // RETURNS: The target object.
    virtual void getTarget(IVpiFrame **target) = 0;
    
    // Assign the target object.
    virtual void setTarget(
        IVpiFrame *value             // [IN] The frame to assign
    ) = 0;
    
    // Return the target property ID.
    //
    // RETURNS: The target property ID. 
    virtual vm_frame_property_id_enum getTargetPropertyId() = 0;
    
    // Assign the target property ID.
    virtual void setTargetPropertyId(
        vm_frame_property_id_enum value    // [IN] The property ID to assign
    ) = 0;

    // Assign the timing function with timing function ID.
    //
    // SEE ALSO: VfxTimingFuncIdEnum
    virtual void setTimingFunc(
        vm_timing_func_id_enum value
    ) = 0;

    // Assign the timing function with customized timing function.
    // 
    // SEE ALSO: vm_timing_funcptr_type
    virtual void setCustomTimingFunc(
        vm_timing_funcptr_type callback,  // [IN] The callback function to assign
        const void *userData,             // [IN] The user data of timing function
        VMUINT32 userDataSize             // [IN] The size of user data 
    ) = 0;                 

    // Assign the interpolation function.
    // 
    // SEE ALSO: vm_timeline_interpolation_funcptr_type
    virtual void setCustomInterpolateFunc(
        vm_timeline_interpolation_funcptr_type callback, // [IN] The callback function to assign
        const void *userData,                   // [IN] The user data of callback function
        VMUINT32 userDataSize                     // [IN] The size of user data 
    ) = 0;

    // Assign the VfxFloatTimeline object as time of timeline.    
    //
    // SEE ALSO: VfxFloatTimeline
    virtual void setTimelineTime(
        IVpiBaseTimeline *time,
        VMFLOAT scale = 1.0f,
        VMFLOAT bias = 0.0f,
        vm_timeline_time_wrap_type_enum wrapType = VM_TIMELINE_TIME_WRAP_TYPE_NONE
    ) = 0;

    // Start the timeline.
    virtual void start() = 0;

    // Stop the timeline.
    virtual void stop() = 0;
};


/*
 * Interface of S32Timeline
 */
class IVpiS32Timeline : public IVpiBase
{
public:

    // Get from value.
    virtual VMINT32 getFromValue() = 0;

    // Get to value.
    virtual VMINT32 getToValue() = 0;

    // Set from value.
    virtual void setFromValue(VMINT32 value) = 0;

    // Set to value.    
    virtual void setToValue(VMINT32 value) = 0;
};


/*
 * Interface of FloatTimeline
 */
class IVpiFloatTimeline : public IVpiBase
{
public:

    // Get from value.
    virtual VMFLOAT getFromValue() = 0;

    // Get to value.
    virtual VMFLOAT getToValue() = 0;

    // Set from value.
    virtual void setFromValue(VMFLOAT value) = 0;

    // Set to value.    
    virtual void setToValue(VMFLOAT value) = 0;
};


/*
 * Interface of ColorTimeline
 */
class IVpiColorTimeline : public IVpiBase
{
public:

    // Get from value.
    virtual VMCOLOR32 getFromValue() = 0;

    // Get to value.
    virtual VMCOLOR32 getToValue() = 0;

    // Set from value.
    virtual void setFromValue(VMCOLOR32 value) = 0;

    // Set to value.    
    virtual void setToValue(VMCOLOR32 value) = 0;
};


/*
 * Interface of PointTimeline
 */
class IVpiPointTimeline : public IVpiBase
{
public:

    // Get from value.
    virtual void getFromValue(vm_point_struct *point) = 0;

    // Get to value.
    virtual void getToValue(vm_point_struct *point) = 0;

    // Set from value.
    virtual void setFromValue(const vm_point_struct &value) = 0;

    // Set to value.    
    virtual void setToValue(const vm_point_struct &value) = 0;
};


/*
 * Interface of FPointTimeline
 */
class IVpiFPointTimeline : public IVpiBase
{
public:

    // Get from value.
    virtual void getFromValue(vm_fpoint_struct *point) = 0;

    // Get to value.
    virtual void getToValue(vm_fpoint_struct *point) = 0;

    // Set from value.
    virtual void setFromValue(const vm_fpoint_struct &value) = 0;

    // Set to value.    
    virtual void setToValue(const vm_fpoint_struct &value) = 0;
};


/*
 * Interface of SizeTimeline
 */
class IVpiSizeTimeline : public IVpiBase
{
public:

    // Get from value.
    virtual void getFromValue(vm_size_struct *size) = 0;

    // Get to value.
    virtual void getToValue(vm_size_struct *size) = 0;

    // Set from value.
    virtual void setFromValue(const vm_size_struct &value) = 0;

    // Set to value.    
    virtual void setToValue(const vm_size_struct &value) = 0;
};


/*
 * Interface of RectTimeline
 */
class IVpiRectTimeline : public IVpiBase
{
public:

    // Get from value.
    virtual void getFromValue(vm_rect_struct *rect) = 0;

    // Get to value.
    virtual void getToValue(vm_rect_struct *rect) = 0;

    // Set from value.
    virtual void setFromValue(const vm_rect_struct &value) = 0;

    // Set to value.    
    virtual void setToValue(const vm_rect_struct &value) = 0;
};


/*
 * Interface of TransformTimeline
 */
class IVpiTransformTimeline : public IVpiBase
{
public:

    // Get from value.
    virtual void getFromValue(vm_transform_struct *transform) = 0;

    // Get to value.
    virtual void getToValue(vm_transform_struct *transform) = 0;

    // Set from value.
    virtual void setFromValue(const vm_transform_struct &value) = 0;

    // Set to value.    
    virtual void setToValue(const vm_transform_struct &value) = 0;
};


VPI_CMD_ID_DECLARE_BEGIN(TIMELINE)

    CMD_ID_TIMELINE_STARTED,

    CMD_ID_TIMELINE_STOPPED,

/* NOTE. The new IDs must be added at the end */
VPI_CMD_ID_DECLARE_END(TIMELINE)


#endif /* __VPI_ANIMATION_INTERFACE_H__ */

