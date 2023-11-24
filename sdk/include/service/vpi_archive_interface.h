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
 *  vpi_archive_interface.h
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
#ifndef __VPI_ARCHIVE_INTERFACE_H__
#define __VPI_ARCHIVE_INTERFACE_H__

#include "vmsys.h"
#include "vpi_interface_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"
#include "vpi_object_interface.h"

/*
 * Interface of Archive
 */
class IVpiArchive : public IVpiBase
{
public:
    // write data to archive source
    virtual void write(VMUINT8 *data, VMUINT32 size) = 0;

    // write 1 byte to archive source
    virtual void writeU8(VMUINT8 data) = 0;

    // write 2 bytes to archive source
    virtual void writeU16(VMUINT16 data) = 0;

    // write 4 bytes to archive source
    virtual void writeU32(VMUINT32 data) = 0;

    // write vm_wstring_struct to archive source
    virtual void writeWString(const vm_wstring_struct &str) = 0;

    // write vm_point_struct to archive source
    virtual void writePoint(const vm_point_struct &pt) = 0;

    // write vm_fpoint_struct to archive source
    virtual void writeFPoint(const vm_fpoint_struct &fpt) = 0;

    // write vm_size_struct to archvie source
    virtual void writeSize(const vm_size_struct &size) = 0;

    // write vm_rect_struct to archive source
    virtual void writeRect(const vm_rect_struct &rect) = 0;

    // write VMCOLOR32 to archive source
    virtual void writeColor(const VMCOLOR32 &color) = 0;

    // read data from archive source
    // RETURNS: actual size read
    virtual VMUINT32 read(VMUINT8 *data, VMUINT32 size) = 0; 

    // read 1 byte from archive source
    // RETURNS: data read
    virtual VMUINT8 readU8() = 0;

    // read 2 bytes from archive source
    // RETURNS: data read
    virtual VMUINT16 readU16() = 0;

    // read 4 bytes from archive source
    // RETURNS: data read
    virtual VMUINT32 readU32() = 0;

    // read vm_wstring_struct from archive source
    virtual void readWString(vm_wstring_struct &str) = 0;

    // read vm_point_struct from archive source
    virtual void readPoint(vm_point_struct &pt) = 0;

    // read vm_fpoint_struct from archive source
    virtual void readFPoint(vm_fpoint_struct &fpt) = 0;

    // read vm_size_struct from archvie source
    virtual void readSize(vm_size_struct &size) = 0;

    // read vm_rect_struct from archive source
    virtual void readRect(vm_rect_struct &rect) = 0;

    // read VMCOLOR32 from archive source
    virtual void readColor(VMCOLOR32 &color) = 0;
};

#endif /* __VPI_ARCHIVE_INTERFACE_H__ */

