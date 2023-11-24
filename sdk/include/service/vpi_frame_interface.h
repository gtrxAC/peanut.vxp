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
 *  vpi_frame_interface.h
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
#ifndef __VPI_FRAME_INTERFACE_H__
#define __VPI_FRAME_INTERFACE_H__

#include "vmsys.h"
#include "vpi_interface_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"
#include "vpi_object_interface.h"
#include "vpi_owner_draw_interface.h"
#include "vpi_frame_filter_interface.h"

class IVpiFrame;

/*
 * Interface of draw context.
 */
class IVpiDrawContext
{
public:

    // Set clipping rectangle of draw conext.
	virtual void setClip(const vm_rect_struct &clipRect) = 0;

    // Set fill color of draw conext.
    virtual void setFillColor(const VMCOLOR32 &color) = 0;

    // Set stroke color of draw conext.
    virtual void setStrokeColor(const VMCOLOR32 &color) = 0;

    // Set the current font to draw text
    virtual void setFont(const vm_font_desc_struct &fontDesc) = 0;
    
    // Set the truncate string
    virtual void setEllipsis(const vm_wstring_struct &ellipsis) = 0;

    // Draw a image with a VMImageSrc
    //
    // SEE ALSO: VMImageSrc
	virtual void drawImage(VMINT32 x, VMINT32 y, const vm_image_source_struct &imgSrc) = 0;

    // Draw a resized image with a VMImageSrc
    //
    // SEE ALSO: VMImageSrc
	virtual void drawResizedImage(const vm_rect_struct &rect, const vm_image_source_struct &imgSrc) = 0;

    // Draw a text
    //
    // NOTE: The text color is fill color, and the border color is stroke color.
    //
    // SEE ALSO: setFont
	virtual void drawText(VMINT32 x, VMINT32 y, const vm_wstring_struct &string) = 0;

    // Draw a text with truncated width
    //
    // NOTE: The text color is fill color, and the border color is stroke color.
    //
    // SEE ALSO: setFont, setEllipsis
	virtual void drawTextTruncated(VMINT32 x, VMINT32 y, const VMWCHAR *string, VMINT32 width) = 0;

    // Backdoor methods for multiple purpose
    virtual VM_RESULT sendEvent(VMUINT32 eventID, VMUINT32 param0, void *param1) = 0;

    // System use only, don't keep the object handle, call this API to get if need to use it
    virtual VpiObjectHandle getObjectHandle() const = 0;
};

/*
 * Interface of frame delegator.
 */
class IVpiFrameDelegator : public IVpiBase
{
public:
    // The frame position in it's parent frame coordinate system. Animatable. 
    //
    // NOTE: The default value is (0, 0).
    virtual void setPos(const vm_point_struct &value)  = 0;

    // The z-position of the frame. Animatable.
    //
    // NOTE: The default value is 0.0.
    virtual void setPosZ(VMFLOAT value)  = 0;

    // The bounds rectangle of the frame. Animatable. 
    //
    // NOTE: The defualt value is (0, 0, 0, 0).
    virtual void setBounds(const vm_rect_struct &value)  = 0;

    // Set background color of the frame.
    virtual void setBgColor(const VMCOLOR32 &value)  = 0;

    // Set opacity of the frame. Opacity value is from 0 to 1.0.
    virtual void setOpacity(VMFLOAT value)  = 0;

    // Set frame transform.
    virtual void setTransform(const vm_transform_struct &value)  = 0;

    // Set color of frame border.
    virtual void setBorderColor(const VMCOLOR32 &value)  = 0;

    // Set image source of frame.
    virtual void setImgContent(const vm_image_source_struct &value)  = 0;

    // Set frame filter.
    virtual void setFilter(IVpiFrameFilter *value)  = 0;

    // Set frame visibility.
    virtual void setHidden(VMBOOL value)  = 0;

    // Set frame to be hittable or not.
    virtual void setIsUnhittable(VMBOOL value)  = 0;

    // Test if the frame contains the specified point
    // RETURNS:
    //  Return VM_TRUE if the clip bound of the frame contains the point
    virtual VMBOOL onContainPoint(const vm_point_struct &point)  = 0;

    // Test if the frame or fuzzy region of the frame contains the specified point
    // RETURNS:
    //  Return VM_TRUE if the clip bound of the frame contains the point
    virtual VMBOOL onContainPointFuzzy(const vm_point_struct &point)  = 0;

    // Overrde to provide the content of the frame.
    //
    // SEE ALSO: IVpiDrawContext
	virtual void onDraw(IVpiDrawContext *drawContext) = 0;
};


/*
 * Interface of frame.
 */
class IVpiFrame : public IVpiBase
{
public:
    // The frame position in it's parent frame coordinate system. Animatable. 
    //
    // NOTE: The default value is (0, 0).
    virtual void getPos(vm_point_struct *point) = 0;

    // The z-position of the frame. Animatable.
    //
    // NOTE: The default value is 0.0.
    virtual VMFLOAT getPosZ() = 0;

    // The bounds rectangle of the frame. Animatable. 
    //
    // NOTE: The defualt value is (0, 0, 0, 0).
    virtual void getBounds(vm_rect_struct *bounds) = 0;

    // The Anchor point of the bounds rectangle. Animatable.
    //
    // NOTE: The default value is (0, 0).
    virtual void getAnchor(vm_fpoint_struct *anchorPoint) = 0;

    // The background color of the frame. Animatable.
    //
    // NOTE: The default value is VFX_COLOR_TRANSPARENT.
    virtual const VMCOLOR32 getBgColor() = 0;

    // The opacity of the frmae. Animatable.
    //
    // NOTE: The defualt value is 1.0.
    virtual VMFLOAT getOpacity() = 0;

    // The trasform of the frame, relative to the anchor point. Animatable.
    //
    // NOTE: The default value is a identy transfrom.
    virtual void getTransform(vm_transform_struct *transform) = 0;

    // The color of frame border. Animatable.
    //
    // NOTE: The default value is VFX_COLOR_WHITE.
    virtual const VMCOLOR32 getBorderColor() = 0;

    // The width of frame border. Animatable.
    //
    // NOTE: The border is drawn inside from the frame bounds. 
    //  The default value is 0.
    virtual VMINT32 getBorderWidth() = 0;

    // The image that provides the frame content.
    //
    // NOTE: The default value is NULL Image Source.
    virtual void getImgContent(vm_image_source_struct *imgContent) = 0;

    // The image content placement rule in the frame bounds.
    //
    // NOTE: The default value is VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER.
    virtual vm_frame_content_placement_type_enum getContentPlacement() = 0;

    // The filter apply to the frame.
    //
    // NOTE: The default value is NULL.
    virtual void getFilter(IVpiFrameFilter **frameFilter) = 0;

    // The owner draw apply to the frame.
    //
    // NOTE: The default value is NULL.
    virtual void getOwnerDraw(IVpiOwnerDraw **ownerDraw) = 0;

    // The filter timing. Animatable.
    //
    // NOTE: The default value is 0.0.
    virtual VMFLOAT getFilterTiming() = 0;

    // The FPE user property 0. Animatable.
    //
    // NOTE: The default value is 0.0.
    virtual VMFLOAT getFpeUser0() = 0;

    // Whether the frame is hidden.
    //
    // NOTE: The default value is VFX_FALSE.
    virtual VMBOOL getHidden() = 0;

    // Whether auto animation is enabled
    //
    // NOTE: The default value is VFX_FALSE.
    virtual VMBOOL getAutoAnimate() = 0;

    // Whether the frame is unhittable
    //
    // NOTE: The default value is VFX_FALSE.
    virtual VMBOOL getIsUnhittable() = 0;

    // A hint marking that the frame rendering quality.
    //
    // NOTE: The hint is applied when the transform is not identity.
    //  The default value is VFX_FALSE.
    virtual vm_render_quality_enum getQuality() = 0;

    // A hint marking that the frame cache mode.
    //
    // NOTE: The default value is VFX_CACHE_MODE_AUTO.
    virtual vm_cache_mode_enum getCacheMode() = 0;

    // The opaque mode of the frame.
    //
    // SEE ALSO: VfxFrameOpaqueModeEnum
    virtual vm_frame_opaque_mode_enum getOpaqueMode() = 0;

    // The culling type of the frame.
    //
    // SEE ALSO: VfxFrameCullingTypeEnum
    virtual vm_frame_culling_type_enum getCullingType() = 0;

    // Whether the frame sort child frames by z-position.
    //
    // NOTE: The default value is VFX_FALSE.
    virtual VMBOOL getIsZSortChild() = 0;

    // The hints of the frame.
    //
    // SEE ALSO: VfxFrameCullingTypeEnum
    virtual vm_frame_hints_enum getHints() = 0;

    // Set frame position.
    virtual void setPos(const vm_point_struct &value) = 0;

    // Set frame z order.
    virtual void setPosZ(VMFLOAT value) = 0;

    // Set frame bounds.
    virtual void setBounds(const vm_rect_struct &value) = 0;

    // Set frame anchor.
    virtual void setAnchor(const vm_fpoint_struct &value) = 0;

    // Set width of frame border.
    virtual void setBgColor(const VMCOLOR32 &value) = 0;

    // Set opacity of the frame. Opacity value is from 0 to 1.0.
    virtual void setOpacity(VMFLOAT value) = 0;

    // Set frame transform.
    virtual void setTransform(const vm_transform_struct &value) = 0;

    // Set color of frame border.
    virtual void setBorderColor(const VMCOLOR32 &value) = 0;

    // Set width of frame border.
    virtual void setBorderWidth(VMINT32 value) = 0;

    // Set image source of frame.
    virtual void setImgContent(const vm_image_source_struct &value) = 0;

    // Set placement of frame content.
    virtual void setContentPlacement(vm_frame_content_placement_type_enum value) = 0;

    // Set owner draw.
    virtual void setOwnerDraw(IVpiOwnerDraw *value) = 0;

    // Set frame filter.
    virtual void setFilter(IVpiFrameFilter *value) = 0;

    // Set filter timing.
    virtual void setFilterTiming(VMFLOAT value) = 0;

    // Set FPE user property 0
    virtual void setFpeUser0(VMFLOAT value) = 0;

    // Set frame visibility.
    virtual void setHidden(VMBOOL value) = 0;

    // Enable auto animation or not.
    virtual void setAutoAnimate(VMBOOL value) = 0;

    // Set frame to be hittable or not.
    virtual void setIsUnhittable(VMBOOL value) = 0;

    // Set frame quality.
    virtual void setQuality(vm_render_quality_enum value) = 0;

    // Set cache mode.
    virtual void setCacheMode(vm_cache_mode_enum value) = 0;

    // Set opaque mode.
    virtual void setOpaqueMode(vm_frame_opaque_mode_enum value) = 0;

    // Set culling mode.
    virtual void setCullingType(vm_frame_culling_type_enum value) = 0;

    // Set whether sort children frame by z order.
    virtual void setIsZSortChild(VMBOOL value) = 0;

    // Set hints
    virtual void setHints(vm_frame_hints_enum value) = 0;

// Frame parent-child hierarchy method
public:
    // Return the parent frame.
    //
    // RETURNS: The parent frame. Return NULL if the frame has no parent frame.
    virtual void getParentFrame(IVpiFrame **frame) = 0;

    // Return the first child frame.
    //
    // RETURNS: The first child frame. Return NULL if the frame has no child frame.
    virtual void getFirstChildFrame(IVpiFrame **frame) = 0;

    // Return the last child frame.
    //
    // RETURNS: The last child frame. Return NULL if the frame has no child frame.
    virtual void getLastChildFrame(IVpiFrame **frame) = 0;

    // Return the next frame.
    //
    // RETURNS: The next frame. Return NULL if the frame has no next frame.
    virtual void getNextFrame(IVpiFrame **frame) = 0;

    // Return the previois frame.
    //
    // RETURNS: The previois frame. Return NULL if the frame has no previois frame.
    virtual void getPrevFrame(IVpiFrame **frame) = 0;

    // Return the focus child frame.
    //
    // RETURNS: The focused child frame. Return NULL if the frame has no focused child frame.
    virtual void getFocusChildFrame(IVpiFrame **frame) = 0;

    // add a child frame into the frame
    virtual void addChildFrame(IVpiFrame *newFrame) = 0;
    
    // Remove the frame from it's parent frame
    virtual void removeFromParentFrame() = 0;
    
    // Insert a frame after a child frame
    virtual void insertChildFrameAfter(IVpiFrame *childFrame, IVpiFrame *newFrame) = 0;
    
    // Insert a frame bofore a child frame
    virtual void insertChildFrameBefore(IVpiFrame *childFrame, IVpiFrame *newFrame) = 0;
    
    // Replace a child frame with a given frame
    virtual void replaceChildFrameWith(IVpiFrame *oldFrame, IVpiFrame *newFrame) = 0;

    // Change the frame to the last one of parent's child frame.
    virtual void bringToFront() = 0;

    // Change the frame to the first one of parent's child frame.
    virtual void sendToBack() = 0;

// Hit testing method
public:
    // Returns the frame contains the specified point, including this frame.
    // RETURNS:
    //  The frame that is located at the given position.
    virtual void hitTest(const vm_point_struct &point, IVpiFrame **frame) = 0;

    // Test if the frame contains the specified point
    // RETURNS:
    //  Return VFX_TRUE if the clip bound of the frame contains the point
    virtual VMBOOL containPoint(const vm_point_struct &point, const VMBOOL isFuzzy = VM_FALSE) = 0;

    // Set if this frame has fuzzy area
    virtual void setFuzzy(VMBOOL value) = 0;

// Frame geometry method
public:
    // Set the frame position in it's parent frame coordinate system. 
    virtual void setPos(VMINT32 x, VMINT32 y) = 0;

    // Set the bounds rectangle of the frame
    virtual void setBounds(VMINT32 x, VMINT32 y, VMINT32 width, VMINT32 height) = 0;

    // Set the Anchor point of the bounds rectangle.
    virtual void setAnchor(VMFLOAT x, VMFLOAT y) = 0;
    
    // Return the frame bounds size
    //
    // RETURNS: The frame bounds size
    virtual void getSize(vm_size_struct *size) = 0;

    // Set the frame bounds size
    virtual void setSize(const vm_size_struct &value) = 0;

    // Set the frame bounds size
    virtual void setSize(VMINT32 width, VMINT32 height) = 0;

    // Return the frame coverage rectangle in its parent frame coordinate system.
    //
    // RETURNS: The frame coverage rectangle.
    virtual void getRect(vm_rect_struct *rect) = 0;
    
    // Set the frame coverage rectangle in its parent frame coordinate system.
    virtual void setRect(const vm_rect_struct &rect) = 0;

    // Set the frame coverage rectangle in its parent frame coordinate system
    virtual void setRect(VMINT32 x, VMINT32 y, VMINT32 width, VMINT32 height) = 0;

// Helper method
public:
    // Set color and width of the frame border.
    virtual void setBorder(const VMCOLOR32 &borderColor, VMINT32 borderWidth = 1) = 0;

// Coordinate convert method
public:
    // Convert the given point from a given frame coordinate system to this frame
    // coordinate system.
    //
    // NOTE: The given frame and this frame must have a same parent frame.
    //
    // RETURNS: The point converted to this frame coordinate system
    //
    // SEE ALSO: convertPointTo
    virtual void convertPointFrom(
        const vm_point_struct &point,     // [IN] A point in the coordinate system of given frame
        const IVpiFrame *frame,           // [IN] The frame that the given point be converted from
        vm_point_struct *convertedPoint   // [OUT] The converted point
        ) = 0;

    // Convert the given point from a this frame coordinate system to the given frame
    // coordinate system.
    //
    // NOTE: The given frame and this frame must have a same parent frame.
    //
    // RETURNS: The point converted to the given frame coordinate system
    //
    // SEE ALSO: convertPointTo
    virtual void convertPointTo(
        const vm_point_struct &point,      // [IN] A point in the coordinate system of this frame
        const IVpiFrame *frame,            // [IN] The frame that the given point be converted to
        vm_point_struct *convertedPoint    // [OUT] The converted point
    ) = 0;
    
    // Convert the given rectangle from a given frame coordinate system to this frame
    // coordinate system.
    //
    // NOTE: The given frame and this frame must have a same parent frame.
    //
    // RETURNS: The rectangle converted to this frame coordinate system
    //
    // SEE ALSO: convertRectTo
    virtual void convertRectFrom(
        const vm_rect_struct &rect,        // [IN] A rectangle in the coordinate system of given frame
        const IVpiFrame *frame,          // [IN] The frame that the given rectangle be converted from
        vm_rect_struct *convertedRect    // [OUT] The converted rectangle
    ) = 0;
    
    // Convert the given rectangle from a this frame coordinate system to the given frame
    // coordinate system.
    //
    // NOTE: The given frame and this frame must have a same parent frame.
    //
    // RETURNS: The rectangle converted to the given frame coordinate system
    //
    // SEE ALSO: convertRectTo
    virtual void convertRectTo(
        const vm_rect_struct &rect,        // [IN] A rectangle in the coordinate system of this frame
        const IVpiFrame *frame,            // [IN] The frame that the given rectangle be converted to
        vm_rect_struct *convertedRect      // [OUT] The converted rectangle
    ) = 0;

// Updating display method
public:
    // Mark that the frame needs redraw in next committing.
    //
    // SEE ALSO: onDraw
    virtual void invalidate() = 0;

    // Try to precache this frame
    virtual void preCache() = 0;

    // Try to precache all child frames
    virtual void preCacheChildren() = 0;

// ***Experimental method
public:
    // Force VRT to update frame position immediately.
    virtual void forcePos(
        const vm_point_struct &pos     // [IN] Frame position.
    ) = 0;

    // Force VRT to update frame image content immediately.
    //  Only support image source type is image buffer.
    virtual void forceImgContent(
        const vm_image_source_struct &value // [IN] New image content
    ) = 0;
    
    // Force to get VRT frame position immediately.
    virtual void forceGetPos(vm_point_struct *point) = 0;
    // Force to get VRT frame bounds immediately.
    virtual void forceGetBounds(vm_rect_struct *bounds) = 0;
    // Force to get VRT frame opacity immediately.
    virtual VMFLOAT forceGetOpacity() = 0;
    // Force to get VRT frame anchor immediately.
    virtual void forceGetAnchor(vm_fpoint_struct *anchorPoint) = 0;
    // Force to get VRT frame transform immediately.
    virtual void forceGetTransform(vm_transform_struct *transform) = 0;
    // Force to get VRT frame bg color immediately.
    virtual VMCOLOR32 forceGetBgColor() = 0;
    // Force to get VRT frame border color immediately.
    virtual VMCOLOR32 forceGetBorderColor() = 0;
    // Force to get VRT frame border width immediately.
    virtual VMINT32 forceGetBorderWidth() = 0;
    // Force to get VRT frame filter timing immediately.
    virtual VMFLOAT forceGetFilterTiming() = 0;
    // Force to get VRT FPE user property immediately.
    virtual VMFLOAT forceGetFpeUser0() = 0;
    
    // Set property effect.
    virtual void setPropertyEffectCallback(
        IVpiFrame *watchFrame,                               // [IN] Watched frame.
        vm_frame_property_effect_funcptr_type callback,    // [IN] Callback funtion to update frame property.
        void *userData,                                     // [IN] User data.
        VMUINT32 userDataSize,                                // [IN] Size of user data.
        vm_frame_property_effect_trigger_type_enum trigger_type = VM_FPE_TRIGGER_TYPE_DIRTY) = 0;

    // Get the user data pointer of frame property effect callback
    //
    // NOTE: The return data pointer may not same as the setting one
    virtual void *getPropertyEffectCallbackUserDataPtr() = 0;

    // Get the data size of frame property effect callback
    virtual VMUINT32 getPropertyEffectCallbackUserDataSize() = 0;

// Alignment method
public:
    // Set alignment information
    virtual void setAlignParent(
        vm_frame_aligner_side_enum side,   // side
        vm_frame_aligner_mode_enum mode    // mode
    ) = 0;

    // Set alignment information
    virtual void setAlignParent(
        vm_frame_aligner_mode_enum modeLeft,   // mode for left side
        vm_frame_aligner_mode_enum modeTop,    // mode for top side
        vm_frame_aligner_mode_enum modeRight,  // mode for right side
        vm_frame_aligner_mode_enum modeBottom  // mode for bottom side
    ) = 0;

    // Reset alignment information
    virtual void resetAlignParent() = 0;
};


VPI_CMD_ID_DECLARE_BEGIN(FRAME)

    CMD_ID_FRAME_BOUNDS_CHANGED,

/* NOTE. The new IDs must be added at the end */
VPI_CMD_ID_DECLARE_END(FRAME)


VPI_EVENT_ID_DECLARE_BEGIN(FRAME)

    EVT_ID_FRAME_SET_CONTENT_DIRTY,

/* NOTE. The new IDs must be added at the end */
VPI_EVENT_ID_DECLARE_END(FRAME)

#endif /* __VPI_FRAME_INTERFACE_H__ */

