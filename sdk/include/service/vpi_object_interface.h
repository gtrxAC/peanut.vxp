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
 *  vpi_object_interface.h
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
#ifndef __VPI_OBJECT_INTERFACE_H__
#define __VPI_OBJECT_INTERFACE_H__

#include "vmsys.h"
#include "vpi_datatype.h"
#include "vpi_interface_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"
#include "vpi_id_range.h"

typedef void* VpiObjectHandle;

typedef void* VMObjectPtr;

// Internal used interface.
class IVpiBase : public GS_IBase
{
public:

    // System use only, set default delegator for VM classes
    virtual void onSetDefaultDelegator(GS_IBase *defaultDelegator) = 0;

    // System use only, set object for VM classes
    virtual void onSetObject(GS_IBase *object) = 0;

    // System use only, don't keep the object handle, call this API to get if need to use it
    virtual VpiObjectHandle getObjectHandle() const = 0;

    // Backdoor methods for multiple purpose
    virtual VM_RESULT sendEvent(VMUINT32 eventID, VMUINT32 param0, void *param1) = 0;
};


/*
 * Interface of object delegator.
 */
class IVpiObjectDelegator : public IVpiBase
{
public:
    // Overridable virtual function. Called after construct the object.
    virtual void onInit() = 0;

    // Overridable virtual function. Called before destruct the object.
    virtual void onDeinit() = 0;
};


/*
 * Internal used interface.
 */
class IVpiCmdHandler
{
public:
    // System use only, receive signal
    virtual void onCmd(GS_IBase* sender, VMUINT32 cmdID, VMUINT32 arg1, VMUINT32 arg2, VMUINT32 arg3, VMUINT32 arg4) = 0;
};


/*
 * Interface of object.
 */
class IVpiObject : public IVpiBase
{
public:

    // Return the parent object of the object
    virtual void getParent(IVpiObject **parentObj) = 0;

    // Internal used.
    virtual void registerCmdHandler(VMUINT32 id, IVpiCmdHandler *handle) = 0;

    // Internal used.
    virtual void unregisterCmdHandler(VMUINT32 id, IVpiCmdHandler *handle) = 0;

    // Internal used. Close the object.
    virtual void close() = 0;

    // Internal used.
    virtual void setVMObjPtr(VMObjectPtr objPtr) = 0;

    // Internal used.
    virtual VMObjectPtr getVMObjPtr() = 0;

	// Checks if native object is valid
	virtual VMBOOL isValid() = 0;
};


#endif /* __VPI_OBJECT_INTERFACE_H__ */

