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

#ifndef VMTAG_SDK_H_
#define VMTAG_SDK_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "vmio.h"
#include "vmsys.h"

#define		MULTI_TAG_MAX			10

#define PPID		1
#define USAGE_MODE	2
#define PARAM		3
#define PRICE		4
#define TRIAL		5
#define CN_NAME		6
#define DEVELOPER	7
#define SERIAL_NUM	8
#define VERSION		9
#define ICON		10

#define CHECK_MD5_OK		1
#define CHECK_MD5_ERROR		0

#define GET_TAG_TRUE		1
#define GET_TAG_ERROR		0


#define	GET_TAG_INSUFFICIENT_BUF	(-1)
#define	GET_TAG_NULL_BUF					(-2)
	
#define	GET_TAG_NOT_FOUND 				(-3)
#define	GET_TAG_FILE_ERROR				(-4)

#define GET_TAG_NOT_A_LIST_TAG		(-5)
#define GET_TAG_LANG_NOT_FOUND		(-6)
#define GET_TAG_CACHE_ERROR		(-7)


typedef struct main_sign_t {
	char sign[8];
	int size;
	char md5[16];
	char reserved[8];
} main_sign_t;


typedef struct multi_tag_t{
	VMINT		tag_id[MULTI_TAG_MAX];
	VMINT		tag_len[MULTI_TAG_MAX];
	VMUCHAR *	tag_content[MULTI_TAG_MAX];
} MULTI_TAG;

/*****************************************************************************
 * FUNCTION
 *    vm_get_vm_tag
 * DESCRIPTION
 *  get a tag from file or rom.
 * PARAMETERS
 *  filename : [IN] file name, if it is rom file, it should be xx.rom format.
 *  tag_num : [IN] tag id.
 *  buf : [OUT] tag value.
 *  buf_size : [OUT] tag value size.
 * RETURNS
 *  get tag success or not.
 * RETURN VALUES
 *  GET_TAG_TRUE : get tag success.
 *  GET_TAG_NOT_FOUND : not find this tag.
 *  GET_TAG_ERROR : read tag error.
 *  GET_TAG_INSUFFICIENT_BUF : buffer size is error.
*****************************************************************************/
VMINT vm_get_vm_tag(short* filename,int tag_num, void* buf ,int* buf_size);


VMINT vm_check_md5(short* filename);


/*****************************************************************************
 * FUNCTION
 *    vm_get_multi_tags
 * DESCRIPTION
 *  get some tags from file or rom.
 * PARAMETERS
 *  filename : [IN] file name, if it is rom file, it should be xx.rom format.
 *  tag_req : [IN & OUT] tag id and value.
 * RETURNS
 *  get tags success or not.
 * RETURN VALUES
 *  GET_TAG_TRUE : get tag success.
 *  GET_TAG_NOT_FOUND : not find this tag.
 *  GET_TAG_ERROR : read tag error.
*****************************************************************************/
VMINT vm_get_multi_tags( short* filename,   MULTI_TAG * tag_req);


/*****************************************************************************
 * FUNCTION
 *    vm_get_tag_by_lang_id
 * DESCRIPTION
 *  get a tag from tag id and language id.
 * PARAMETERS
 *  filename : [IN] file name, if it is rom file, it should be xx.rom format.
 *  tag_num : [IN] tag id.
 *  lang_id : [IN] lang id.
 *  buf : [OUT] tag value.
 *  buf_size : [OUT] tag value size.
 * RETURNS
 *  get a tag success or not.
 * RETURN VALUES
 *  GET_TAG_TRUE : get tag success.
 *  GET_TAG_ERROR : get tag error.
 *  GET_TAG_NOT_FOUND : not find this tag.
 *  GET_TAG_LANG_NOT_FOUND : not find language id.
 *  GET_TAG_NOT_A_LIST_TAG : tag id is not corrent.
 *  GET_TAG_FILE_ERROR : read tag error from file.
 *  GET_TAG_INSUFFICIENT_BUF : buffer size is error.
 *  GET_TAG_NULL_BUF : buffer size is zero
*****************************************************************************/
VMINT vm_get_tag_by_lang_id( short* filename, int tag_num, void* buf, int* buf_size, int lang_id );


/*****************************************************************************
 * FUNCTION
 *    vm_get_multi_tags_by_lang_id
 * DESCRIPTION
 *  get tags from tag id and language id.
 * PARAMETERS
 *  filename : [IN] file name, if it is rom file, it should be xx.rom format.
 *  lang_id : [IN] lang id.
 *  tag_req : [IN & OUT] tag id and value.
 * RETURNS
 *  get tags success or not.
 * RETURN VALUES
 *  GET_TAG_TRUE : get tag success.
 *  GET_TAG_ERROR : get tag error.
 *  GET_TAG_LANG_NOT_FOUND : not find language id.
 *  GET_TAG_INSUFFICIENT_BUF : there is no enough memroy.
*****************************************************************************/
VMINT vm_get_multi_tags_by_lang_id( short* filename,   MULTI_TAG * tag_req, int lang_id );


/*****************************************************************************
 * FUNCTION
 *    vm_get_vm_tag_from_rom
 * DESCRIPTION
 *  get a tag from rom.
 * PARAMETERS
 *  rom : [IN] rom file, it should be xx.rom format.
 *  tag_num : [IN] tag id.
 *  buf : [OUT] tag value.
 *  buf_size : [OUT] tag value size.
 * RETURNS
 *  get tag success or not.
 * RETURN VALUES
 *  GET_TAG_TRUE : get tag success.
 *  GET_TAG_NOT_FOUND : not find this tag.
 *  GET_TAG_ERROR : read tag error.
 *  GET_TAG_INSUFFICIENT_BUF : buffer size is error.
*****************************************************************************/
VMINT vm_get_vm_tag_from_rom(VMUINT8* rom, int tag_num, void* buf , int* buf_size);


#ifdef __cplusplus
}
#endif

#endif /* VMTAG_SDK_H_ */
