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
 *  vpi_control_interface.h
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
#ifndef __VPI_MAIN_SCR_INTERFACE_H__
#define __VPI_MAIN_SCR_INTERFACE_H__

#include "vmsys.h"
#include "vpi_object_interface.h"
#include "vpi_page_interface.h"
#include "vpi_control_interface.h"

class IVpiPage;

/*
 * Interface of Venus main screen.
 */
class IVpiMainScr : public IVpiBase
{
public:
    // Push a page, with animated transition effect.
    // The page pointer must be valid (cannot be NULL). 
    // RETURNS: id of this page.
    virtual VMID pushPage(VMID pageId, IVpiPage *page) = 0;

//    VMID pushPageEx(VMID pageId, const VfxClassInfo *info) = 0;

    // Insert a page above another page, specified by insert_above.
    // If insert_above is 0 (VFX_ID_NULL), it will be insert to bottom.
    // The page pointer must be valid (cannot be NULL). 
    // Note. You can use pushPageEx to archive lazy creation.
    // RETURNS: id of this page.
    virtual VMID insertPage(VMID pageId, IVpiPage *page, VMID insert_above) = 0;

    // Pop current(top) page, with animated transition effect.
    virtual void popPage() = 0;

    // Close page by page id. If the input page is current one, the 
    // behavior is eqaul to popPage(), else it will close the page 
    // directly without any update.
    virtual void closePage(VMID pageId) = 0;

    // Query page pointer by page id, it will return NULL if the id
    // is not in page stack or if it is not created yet.   
    // RETURNS: page pointer.
    virtual void getPage(VMID pageId, IVpiPage **page) = 0; 

    // Check if an page id is in page stack or not
    // RETURNS: if the id is in page stack
    virtual VMBOOL isPageIdValid(VMID pageId) = 0;

    // Query id of a page pointer
    // RETURNS: id of given page, or VFX_ID_NULL if it is not in stack
    virtual VMID getPageId(const IVpiPage *page) = 0;

    // Query number of pages in stack
    // RETURNS: number of pages in stack
    virtual VMINT32 getPageCount() = 0;

    // Query id of all pages in the stack. 
    // If top_down is true, Id of current(top) page will be stored at index 0, 
    // and id of bottom page will be put at index N-1. If top_down is false, 
    // bottom ones will be at index 0, and top ones at index N-1.
    // If the buffer is not enough, only first N page will be return.
    // RETURNS: number of id written into buffer.
    virtual VMINT32 getPageIds(VMID *buffer, VMINT32 bufferCount, VMBOOL topDown = VM_TRUE) = 0;

    // Query id of current(top) page in the stack. If stack is empty, return 
    // VFX_ID_NULL. 
    // Use with getPrevPageId to traverse stack top-down.
    // RETURNS: page id
    virtual VMID getTopPageId() = 0;

    // Query id of bottom page in the stack. If stack is empty, return VFX_ID_NULL
    // Use with getNextPageId to traverse stack bottom-up.
    // RETURNS: page id
    virtual VMID getBottomPageId() = 0;

    // Query id of page next to given page id. 'Next' means toward top.
    // It will return VFX_ID_NULL if the given page id not exist or it 
    // is current page.
    // Use with getBottomPageId to traverse stack bottom-up.
    // RETURNS: page id
    virtual VMID getNextPageId(VMID pageId) = 0;

    // Query id of page previous to given page id. 'Prev' means toward 
    // bottom. It will return VFX_ID_NULL if the given page id not exist 
    // or it is already bottom page.
    // Use with getTopPageId to traverse stack top-down.
    // RETURNS: page id
    virtual VMID getPrevPageId(VMID pageId) = 0;

    // When there is no page, and auto close is on, MainScr will close itself.
    // Auto close is on by default.
    virtual void setAutoClose(VMBOOL autoClose) = 0;

    // Query if auto close is on
    // Auto close is on by default.
    // RETURNS: if page is auto close or not.
    virtual VMBOOL getAutoClose() = 0;

    // Query client rectangle of a given page.
    // The coordination of return rectangle is relative to main screen.
    // RETURNS: the client area.
    virtual void getClient(IVpiPage *page, vm_rect_struct *rect) = 0;

    // Recalucate layout, current page will be repositioned (and resized) 
    // based on its bar setting.
    virtual void recalcLayout(VMBOOL bUpdateNow = VM_FALSE) = 0;

    // Recalucate layout, current page will be repositioned (and resized) 
    // based on its bar setting.
    virtual void getStatusBar(IVpiControl **bar) = 0;

    /* check if enable allowDelete */
    virtual VMBOOL getAllowDelete() = 0;
};

/* DOM-NOT_FOR_SDK-BEGIN */

/*
 * Internal used interface.
 */
class IVpiMainScrStatic : public IVpiBase
{
public:

    virtual void findMainScr(IVpiFrame *f, IVpiMainScr **screen) = 0;
};

/* DOM-NOT_FOR_SDK-END */

#endif /* __VPI_MAIN_SCR_INTERFACE_H__ */

