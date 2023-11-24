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
 
#ifndef VMRES_SDK_H
#define VMRES_SDK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
typedef struct _vm_res_read_hint_struct
{
	VMINT res_offset;
	VMINT res_size;
}vm_res_read_hint_struct;

/*****************************************************************************
 * FUNCTION
 *    vm_load_resource
 * DESCRIPTION
 *  load resource from current file, system will alloc memory and read the 
 *  res from file to memory,need to call vm_free after use.
 * PARAMETERS
 *  res_name : [IN]  Resource name, not include path.
 *  res_size : [OUT] Resource size, bytes.
 * RETURNS
 *  Resource pointer
*****************************************************************************/
VMUINT8* vm_load_resource(char* res_name, VMINT* res_size);


 /*****************************************************************************
 * FUNCTION
 *  vm_load_resource_from_file
 * DESCRIPTION
 *  Load Resource from one filesystem will alloc memory and read the 
 *  res from file to memory,need to call vm_free after use.
 * PARAMETERS
 *  filename : [IN] The file need to read the resource.
 *  res_name : [IN] Resource name, not include path.
 *  res_size : [OUT] Resource size, bytes.
 * RETURNS
 *  Resource pointer
*****************************************************************************/
VMUINT8* vm_load_resource_from_file(VMWSTR filename, char *res_name, VMINT *res_size);


/*****************************************************************************
 * FUNCTION
 *  vm_resource_get_data
 * DESCRIPTION
 *  Function to Get data from current app's file.
 * PARAMETERS
 *  data    [OUT]    Buffer of data
 *  offset  [OUT]    Offset of the file
 *  size    [OUT]    Size of the data
 * RETURNS
 *  0 successful
 *****************************************************************************/
extern VMINT32 vm_resource_get_data(VMUINT8 *data, VMUINT32 offset, VMUINT32 size);

/*****************************************************************************
 * FUNCTION
 *  vm_resource_get_data_from_file
 * DESCRIPTION
 *  Function to Get data from file.
 * PARAMETERS
 *  filename[IN]     File full path
 *  data    [OUT]    Buffer of data
 *  offset  [OUT]    Offset of the file
 *  size    [OUT]    Size of the data
 * RETURNS
 *  0 successful
 *****************************************************************************/
VMINT32 vm_resource_get_data_from_file(VMWSTR filename, VMUINT8 *data, VMUINT32 offset, VMUINT32 size);

/*****************************************************************************
 * FUNCTION
 *    vm_get_resource_offset
 * DESCRIPTION
 *  get resource offset from current file
 * PARAMETERS
 *  res_name : [IN]  Resource name, not include path.
 * RETURNS
 *  Resource offset
 *  0 is error
*****************************************************************************/
VMUINT vm_get_resource_offset(char *res_name);

 /*****************************************************************************
 * FUNCTION
 *  vm_get_resource_offset_from_file
 * DESCRIPTION
 *  get resource offset from one file
 * PARAMETERS
 *  filename : [IN] The file need to read the resource.
 *  res_name : [IN] Resource name, not include path.
 * RETURNS
 *  Resource offset
 *  0 is error
*****************************************************************************/
VMUINT vm_get_resource_offset_from_file(VMWSTR filename, char *res_name);


/*****************************************************************************
 * FUNCTION
 *  vm_load_resource_use_outside_memory
 * DESCRIPTION
 *  get resource use outside memory
 * PARAMETERS
 *  filename : [IN] The file need to read the resource.
 *  res_name : [IN] Resource name, not include path.
 *  buffer : [IN] buffer to put resource data.
 *  buffer_size : [IN] buffer size. 
 *  hint : [OUT] buffer size and offset. 
 * RETURNS
 *  Resource offset
 *  0 is error
*****************************************************************************/
VMBOOL vm_load_resource_use_outside_memory(VMWSTR filename, char *res_name, void* buffer, VMINT buffer_size, vm_res_read_hint_struct* hint);

#ifdef __cplusplus
}
#endif

#endif /* VMRES_SDK_H */
