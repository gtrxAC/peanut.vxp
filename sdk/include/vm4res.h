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
#ifndef _VRE4RES_SDK_H_
#define	_VRE4RES_SDK_H_
/* Resource Module SDK header file */

#ifdef __cplusplus
extern "C" {
#endif

#define VM_RES_SUCCESS          0
#define VM_RES_OUT_OF_MEM       -1
#define VM_RES_PARAM_ERROR      -2
#define VM_RES_ITEM_NOT_FOUND   -3

#undef __VM_RES_DEBUG_DATA__

#ifdef __MRE_SDK__
#define GetString(x) vm_res_get_string((VMUINT32)x)
#define GetImage(x) vm_res_get_image((VMUINT32)x)
#define GetAudio(x) vm_res_get_audio((VMUINT32)x)

#define FreeRes(x) vm_res_delete((VMUINT32)x);
#endif

/*****************************************************************************
 * FUNCTION
 *  vm_res_init
 * DESCRIPTION
 *  Init MRE 2.0 resource, will load current language table into RAM
 *  Need to be called before use MRE 2.0 Resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  VM_RES_SUCCESS
 *****************************************************************************/
extern VMINT32 vm_res_init(void);


/*****************************************************************************
 * FUNCTION
 *  vm_res_init_with_language
 * DESCRIPTION
 *  Init VRE 4.0 resource, will load language table into RAM
 *  Need to be called before use VRE 4.0 Resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  VM_RES_SUCCESS
 *****************************************************************************/
extern VMINT32 vm_res_init_with_language(VMUINT32 language);


/*****************************************************************************
 * FUNCTION
 *  vm_res_deinit
 * DESCRIPTION
 *  Release all MRE 2.0 resource, will free all memory of resource
 *  Could be called after use MRE 2.0 Resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  VM_RES_SUCCESS
 *****************************************************************************/
extern VMINT32 vm_res_deinit(void);


/*****************************************************************************
 * FUNCTION
 *  vm_res_get_string
 * DESCRIPTION
 *  Get the string by ID. 
 * PARAMETERS
 *  string_id         [IN]      ID to get.
 * RETURNS
 *  VMUINT8 *                   String pointer of the ID, only current language, NULL for not found
 *****************************************************************************/
extern VMUINT8 *vm_res_get_string(VMUINT32 string_id);


/*****************************************************************************
 * FUNCTION
 *  vm_res_load_image_start
 * DESCRIPTION
 *  This interface to reduce the image/audio loading time.
 *  When you need to get image more than 1, you can call vm_res_get_image_start() at first, then
 *  get image one by one, at last call vm_res_get_image_end(). it will help you to save lots of 
 *  file I/O time.
 * PARAMETERS
 *  void
 * RETURNS
 *  VMINT32                   VM_RES_SUCCESS, others fail
 *****************************************************************************/
extern VMINT32 vm_res_load_image_start(void);


/*****************************************************************************
 * FUNCTION
 *  vm_res_load_image_end
 * DESCRIPTION
 *  This interface to reduce the image/audio loading time.
 *  When you need to get image more than 1, you can call vm_res_get_image_start() at first, then
 *  get image one by one, at last call vm_res_get_image_end(). it will help you to save lots of 
 *  file I/O time.
 * PARAMETERS
 *  void
 * RETURNS
 *  VMINT32                   VM_RES_SUCCESS, others fail
 *****************************************************************************/
extern VMINT32 vm_res_load_image_end(void);


/*****************************************************************************
 * FUNCTION
 *  vm_res_get_image
 * DESCRIPTION
 *  Get Image data by ID. Will alloc memory, need to use FreeRes/vm_res_delete to free.
 *  Only alloc 1 time for the same ID. Will return Image size at the same time.
 * PARAMETERS
 *  image_id :        [IN]      ID to get.
 *  size :            [OUT]     Image size
 * RETURNS
 *  VMUINT8 *                  Image pointer of the ID
 *****************************************************************************/
extern VMUINT8 *vm_res_get_image_and_size(VMUINT32 image_id, VMUINT32 *size);


/*****************************************************************************
 * FUNCTION
 *  vm_res_get_image_with_header
 * DESCRIPTION
 *  this is use for vpp file, get Image data by ID. Will alloc memory, need to use FreeRes/vm_res_delete to free.
 *  Only alloc 1 time for the same ID.
 * PARAMETERS
 *  image_id         [IN]      ID to get.
 * RETURNS
 *  VMUINT8 *                  Image pointer of the ID
 *****************************************************************************/
extern VMUINT8 *vm_res_get_image_with_header(VMUINT32 image_id);


/*****************************************************************************
 * FUNCTION
 *  vm_res_get_image_and_size_with_header
 * DESCRIPTION
 *  this is use for vpp file, get Image data by ID. Will alloc memory, need to use FreeRes/vm_res_delete to free.
 *  Only alloc 1 time for the same ID. Will return Image size at the same time.
 * PARAMETERS
 *  image_id :        [IN]      ID to get.
 *  size :            [OUT]     Image size
 * RETURNS
 *  VMUINT8 *                  Image pointer of the ID
 *****************************************************************************/
extern VMUINT8 *vm_res_get_image_and_size_with_header(VMUINT32 image_id, VMUINT32 *size);


/*****************************************************************************
 * FUNCTION
 *  vm_res_get_image_and_size_from_file
 * DESCRIPTION
 *  Get other file's image data by ID. this api need application to alloc memory.
 * PARAMETERS
 *  filename :        [IN]        File full path
 *  image_id :       [IN]     ID to get.
 *  buff :               [IN]     Buffer to put image data,  if the is NULL, the function will return image size
 *  size :              [IN/OUT]     when buff is NULL, this is output parameter, will get image size; when buff is not NULL, this is input parameter
 * RETURNS
 *  VMINT                 1 is ok, o is error
 *****************************************************************************/
extern VMINT vm_res_get_image_and_size_from_file(VMWSTR filename, VMUINT32 image_id, void* buff, VMUINT32 *size);


/*****************************************************************************
 * FUNCTION
 *  vm_res_get_audio_and_size_from_file
 * DESCRIPTION
 *  Get file's audio data by ID. this api need application to alloc memory.
 * PARAMETERS
 *  filename :        [IN]      File full path
 *  image_id :       [IN]     ID to get.
 *  buff :               [IN]     Buffer to put audio data,  if the is NULL, the function will return audio size
 *  size :              [IN/OUT]     when buff is NULL, this is output parameter, will get audio size; when buff is not NULL, this is input parameter
 * RETURNS
 *  VMINT                 1 is ok, o is error
 *****************************************************************************/
extern VMINT vm_res_get_audio_and_size_from_file(VMWSTR filename, VMUINT32 audio_id, void *buff, VMUINT32 *size);


/*****************************************************************************
 * FUNCTION
 *  vm_res_get_string_and_size_from_file
 * DESCRIPTION
 *  Get file's string data by ID. this api need application to alloc memory.
 * PARAMETERS
 *  filename :        [IN]        File full path
 *  image_id :       [IN]     ID to get.
 *  buff :               [IN]     Buffer to put string data,  if the is NULL, the function will return string size
 *  size :              [IN/OUT]     when buff is NULL, this is output parameter, will get string size; when buff is not NULL, this is input parameter
 * RETURNS
 *  VMINT                 1 is ok, o is error
 *****************************************************************************/
extern VMINT vm_res_get_string_and_size_from_file(VMWSTR filename, VMUINT32 string_id, void *buff, VMUINT32 *size);


/*****************************************************************************
 * FUNCTION
 *  vm_res_get_image_and_size_from_rom
 * DESCRIPTION
 *  Get rom app's image data by ID. this api no need application to alloc memory.
 * PARAMETERS
 *  filename :        [IN]        File full path
 *  image_id :       [IN]     ID to get.
 *  buff :               [OUT]     image data pointer
 *  size :              [OUT]     image size
 * RETURNS
 *  VMINT                 1 is ok, o is error
 *****************************************************************************/
extern VMINT vm_res_get_image_and_size_from_rom(VMWSTR filename, VMUINT32 image_id, void **buff, VMUINT32 *size);


/*****************************************************************************
 * FUNCTION
 *  vm_res_get_audio_and_size_from_rom
 * DESCRIPTION
 *  Get rom app's  audio data by ID. this api no need application to alloc memory.
 * PARAMETERS
 *  filename :        [IN]        File full path
 *  image_id :       [IN]     ID to get.
 *  buff :               [OUT]     audio data pointer
 *  size :              [OUT]     audio size
 * RETURNS
 *  VMINT                 1 is ok, o is error
 *****************************************************************************/
extern VMINT vm_res_get_audio_and_size_from_rom(VMWSTR filename, VMUINT32 audio_id, void **buff, VMUINT32 *size);


/*****************************************************************************
 * FUNCTION
 *  vm_res_get_string_and_size_from_rom
 * DESCRIPTION
 *  Get rom app's  string data by ID. this api no need application to alloc memory.
 * PARAMETERS
 *  filename :        [IN]        File full path
 *  image_id :       [IN]     ID to get.
 *  buff :               [OUT]     string data pointer
 *  size :              [OUT]     string size
 * RETURNS
 *  VMINT                 1 is ok, o is error
 *****************************************************************************/
extern VMINT vm_res_get_string_and_size_from_rom(VMWSTR filename, VMUINT32 string_id, void **buff, VMUINT32 *size);


/*****************************************************************************
 * FUNCTION
 *  vm_res_get_image
 * DESCRIPTION
 *  Get Image data by ID. Will alloc memory, need to use FreeRes/vm_res_delete to free.
 *  Only alloc 1 time for the same ID.
 * PARAMETERS
 *  image_id         [IN]      ID to get.
 * RETURNS
 *  VMUINT8 *                  Image pointer of the ID
 *****************************************************************************/
extern VMUINT8 *vm_res_get_image(VMUINT32 image_id);


/*****************************************************************************
 * FUNCTION
 *  vm_res_get_audio
 * DESCRIPTION
 *  Get audio data by ID. Will alloc memory, need to use FreeRes/vm_res_delete to free.
 *  Only alloc 1 time for the same ID.
 * PARAMETERS
 *  audio_id         [IN]      ID to get.
 * RETURNS
 *  VMUINT8 *                  Audio pointer of the ID
 *****************************************************************************/
extern VMUINT8 *vm_res_get_audio(VMUINT32 audio_id);


/*****************************************************************************
 * FUNCTION
 *  vm_res_delete
 * DESCRIPTION
 *  Management the list of current allocated resource. This is the delete node func
 * PARAMETERS
 *  id         [IN]      ID of the resource
 * RETURNS
 *  VM_RES_SUCCESS
 *  VM_RES_PARAM_ERROR
 *  VM_RES_ITEM_NOT_FOUND
 *****************************************************************************/
extern VMINT32 vm_res_delete(VMUINT32 id);


/*****************************************************************************
 * FUNCTION
 *  vm_res_get_virtual_image
 * DESCRIPTION
 *  Get virtual image file
 * PARAMETERS
 *  image_id         [IN]      ID of the resource
 * RETURNS
 *  NULL: resource error
 *  VMUINT8 *                  virtual struct pointer
 *****************************************************************************/
extern VMUINT8 *vm_res_get_virtual_image(VMUINT32 image_id);


#ifdef __cplusplus
}
#endif

#endif /* _VRE4RES_SDK_H_ */

