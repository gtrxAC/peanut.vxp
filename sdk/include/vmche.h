/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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

#ifndef VMCHE_SDK_H_
#define VMCHE_SDK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

/** The structure vm_stche is defined to record and maintain the context of CHE */
typedef struct _vm_stche_t 
{
    VMUINT cheLastLength; /* last block length */
    VMUINT8 *cheLastDstAddr; /* last destination address */
    VMUINT8 *cheWorkBuf;  /* pointe to a space used by each algorithm */
    VMUINT cheBufLen;   /* the length of cheWorkBuf. It depends on the encrypt algorithm */
    VMUINT cipher_type; /* cipher type */
    VMUINT8 *cheKey; /* key stream */
    VMUINT8 *cheIV; /* initial vector */
    VMUINT cheKeyLength; /* key stream length */
    VMUINT cheIVLength; /* initial vector length */
    VMUINT8 cheFirstFlag; /* first block flag */
 } vm_stche;


typedef enum
{
    VM_CHE_MD5 = 1, /* MD5 hash algorithm. The output length is fixed 16 bytes */
    VM_CHE_SHA1, /* SHA1 hash algorithm. The output length is fixed 20 bytes */
    VM_CHE_DES, /* DES block cipher algorithm. The CHE will do auto padding in DES type.
                The maximum padding length is 8 bytes */
    VM_CHE_3DES, /* 3DES block cipher algorithm. The CHE will do auto padding in 3DES type.
                 The maximum padding length is 8 bytes */
    VM_CHE_AES, /* AES block cipher algorithm. The CHE will do auto padding in AES(ECB, CBC) type.
                The maximum padding length is 16 bytes */

    VM_CHE_MD4, /* MD4 hash algorithm. The output length is fixed 16 bytes */
    VM_CHE_MAC_MD5, /* HMAC_MD5 hash algorithm. The output length is fixed 16 bytes */
    VM_CHE_MAC_SHA1, /* HMAC_SHA1 hash algorithm. The output length is fixed 20 bytes */
    VM_CHE_RC4, /* RC4 stream cipher algorithm. No padding */

    VM_CHE_RSA, /* RSA asym cipher algorithm. */
    VM_CHE_DH, /* Diffie Hellman cipher algorithm used to generate the key. No padding */
    VM_CHE_MAC_SHA224, /* HMAC_SHA224 hash algorithm. The output length is fixed 28 bytes */
    VM_CHE_MAC_SHA256, /* HMAC_SHA256 hash algorithm. The output length is fixed 32 bytes */
    VM_CHE_SHA224, /* SHA 224 algorithm */
    VM_CHE_SHA256, /* SHA 256 algorithm */
    VM_CHE_TYPE_END
} vm_che_type;

/* vm_che_operation_mode define the cipher function mode. For hash function, it could be set VM_CHE_MODE_NULL */
typedef enum
{
    VM_CHE_MODE_NULL = 0, /* null mode. This mode is used when there is no mode operation */
    VM_CHE_ECB, /* AES/DES ECB mode */
    VM_CHE_CBC, /* AES/DES CBC mode */
    VM_CHE_CTR, /* AES CTR(counter) mode */
    VM_CHE_F8, /* AES F8 mode */

    VM_CHE_SKIP, /* RC4 Skip mode */
    VM_CHE_KEY_WRAP, /* AES key wrap mode */
    VM_CHE_KEY_UNWRAP /* AES key unwrap mode */

} vm_che_operation_mode;

/* vm_che_action define this CHE process should run hash, encipher or decipher */
typedef enum
{
    VM_CHE_HASH, /* generate hash value */
    VM_CHE_ENC, /* encryption data */
    VM_CHE_DEC, /* decryption data */
    VM_CHE_MAC_HASH, /* generate HMAC value */

    VM_DH_INIT, /* initialize the Diffie-Hellman */
    VM_DH_MAKE_PARAMS, /* Suppose A=G^a mod p. generate discrete logarithms(a) and A */
    VM_DH_MAKE_PUBLIC, /* Suppose A=G^a mod p. generate discrete logarithms(a) and A */
    VM_DH_CALC_SECRET, /* Suppose B=G^b mod p. Calculate the shared secret (G^b)^a mod P */
    VM_DH_FREE /* finialize the Diffie-Hellman */
} vm_che_action;

typedef enum
{
    VM_CHE_GEN_KEY, /* generate the key exclude asynmetry and RC4 algirhtm */
    VM_CHE_SET_KEY, /* set the key exclude asynmetry and RC4 algirhtm */
    VM_CHE_GET_KEY, /* get the key exclude asynmetry and RC4 algirhtm*/
    VM_CHE_DEL_KEY, /* delete the key exclude asynmetry and RC4 algirhtm */

    VM_CHE_SET_RC4_KEY, /* set the RC4 key */

    VM_CHE_SET_RSA_N, /* set the RSA modulus N. N=P*Q. N is prime number. 
                      The input N is a binary data */
    VM_CHE_SET_RSA_E, /* set the RSA public exponent: E. 
                      The input E is a binary data */
    VM_CHE_SET_RSA_D, /* set the RSA private exponent: D. 
                      The input D is a binary data */
    VM_CHE_SET_RSA_P, /* set the RSA modulus P(CRT format). 
                      The input P is a binary data */
    VM_CHE_SET_RSA_Q, /* set the RSA modulus Q(CRT format). 
                      The input Q is the binary data */
    VM_CHE_SET_RSA_dModPm1, /* set the RSA private exponent(CRT format): DP. 
                            The input DP is a binary data */
    VM_CHE_SET_RSA_dModQm1, /* set the RSA private exponent(CRT format): DQ. 
                            The input DQ is a binary data */
    VM_CHE_SET_RSA_qInvModP, /* set the coefficient Integer(CRT format): inverse Q. 
                             The input InvQ is a binary data */

    VM_CHE_SET_DH_P, /* set the DH modulus: P. The input P is a binary data. */
    VM_CHE_SET_DH_G, /* set the DH prime root: G. The input G is a binary data */
    VM_CHE_SET_DH_SELF_PUBLIC, /* set the self public value. G^X mod P. The input is a binary data. */
    VM_CHE_SET_DH_PEER_PUBLIC, /* set the peer public value. G^Y mod P. The input is a binary data. */
    VM_CHE_SET_DH_PRIVATE, /* set the discrete logarithms(private key): X. 
                           The input X is a binary data. */

    VM_CHE_GET_DH_SELF_PUBLIC_LEN, /* get the self public length */
    VM_CHE_GET_DH_PRIVATE_LEN, /* get the discrete logarithm length */
    VM_CHE_GET_DH_SECRET_LEN, /* get the secret length */

    VM_CHE_GET_DH_SELF_PUBLIC, /* get self public value */
    VM_CHE_GET_DH_PRIVATE, /* get the discrete logarithm */
    VM_CHE_GET_DH_SECRET, /* get the shared key,i.e. key. key = GY^X mod P */

    VM_CHE_GET_RSA_N, /* get the RSA modulus N. N=P*Q. N is prime number. The output N is binary data */
    VM_CHE_GET_RSA_E, /* get the RSA public exponent: E. The output E is a binary data */
    VM_CHE_GET_RSA_D, /* get the RSA private exponent: D. The output D is a binary data */
    VM_CHE_GET_RSA_P, /* get the RSA modulus P(CRT format). The output P is a binary data */
    VM_CHE_GET_RSA_Q, /* get the RSA modulus Q(CRT format). The output Q is the binary data */
    VM_CHE_GET_RSA_dModPm1, /* get the RSA private exponent(CRT format): DP. The output DP is a binary data */
    VM_CHE_GET_RSA_dModQm1, /* get the RSA private exponent(CRT format): DQ. The output DQ is a binary data */
    VM_CHE_GET_RSA_qInvModP, /* get the coefficient Integer(CRT format): inverse Q. The output InvQ is a binary data */

    VM_CHE_GET_RSA_N_LEN, /* get the RSA modulus N. N=P*Q. N is prime number. The output N is binary data */
    VM_CHE_GET_RSA_E_LEN, /* get the RSA public exponent: E. The output E is a binary data */
    VM_CHE_GET_RSA_D_LEN, /* get the RSA private exponent: D. The output D is a binary data */
    VM_CHE_GET_RSA_P_LEN, /* get the RSA modulus P(CRT format). The output P is a binary data */
    VM_CHE_GET_RSA_Q_LEN, /* get the RSA modulus Q(CRT format). The output Q is the binary data */
    VM_CHE_GET_RSA_dModPm1_LEN, /* get the RSA private exponent(CRT format): DP. The output DP is a binary data */
    VM_CHE_GET_RSA_dModQm1_LEN, /* get the RSA private exponent(CRT format): DQ. The output DQ is a binary data */
    VM_CHE_GET_RSA_qInvModP_LEN, /* get the coefficient Integer(CRT format): inverse Q. The output InvQ is a binary data */
	VM_CHE_ACTION_TYPE_END
}vm_che_key_action_type;

/* che_rsa_padding_mode_enum define the RSA padding mode. */
typedef enum
{
    VM_CHE_RSA_MODE_NULL = 0, /* null mode. This mode is used when there is no padding */
    VM_CHE_RSA_PKCS1_V15, /* RSA PKCS#1 v1.5 padding mode  */
    VM_CHE_RSA_MODE_TOTAL
} vm_che_rsa_padding_mode_enum;

/* CHE error cause */
typedef enum
{
    VM_CHE_OK                    = 0,  /* success */
    VM_CHE_ERROR                 = -1, /* error occurs */
    VM_CHE_KEY_CHK_FAIL          = -2, /* public or private key check fail */
    VM_CHE_INVALID_LENGTH        = -3, /* buffer length too small or too long */
    VM_CHE_OPERATION_FAIL        = -4  /* che operation fails, such as cipher fail */
} vm_che_result_error_enum;

/*****************************************************************************
 * FUNCTION
 *  vm_che_init
 * DESCRIPTION
 *  Initialize the vm_stche data structure created from AP
 * PARAMETERS
 *  che_context_p  : [IN]   CHE context
 *  type         : [IN]   CHE type (CHE_TYPE)
 * RETURN VALUES
 *  void
 * SEE ALSO
 *  vm_che_deinit
 * 
 *****************************************************************************/
 extern void vm_che_init(vm_stche *che_context_p, VMUINT type);

/*****************************************************************************
 * FUNCTION
 *  vm_che_deinit
 * DESCRIPTION
 *  Deinitialize the CHE_CONTEXT
 * PARAMETERS
 *  che_context_p  : [IN]   CHE context
 * RETURN VALUES
 *  void
 * SEE ALSO
 *  vm_che_init
*
 *****************************************************************************/
extern void vm_che_deinit(vm_stche *che_context_p);

/*****************************************************************************
 * FUNCTION
 *  vm_che_set_iv
 * DESCRIPTION
 *  Set initial vector for CBC or CTR or AES_F8 mode. CHE only stores the pointer address.
 *  The iv buffer should be kept by the user until the first block is computed.
 *  To avoid confusion, user can keep the buffer until the che_deinit is called.
 * PARAMETERS
 *  che_context_p  : [IN]   CHE context
 *  iv           : [IN]   initial vector. 
 *                        the input has to be 4-byte alignment on ARM platform
 *  iv_len       : [IN]   initial vector length
 * RETURN VALUES
 *  void
*
 *****************************************************************************/
extern void vm_che_set_iv(vm_stche *che_context_p, VMUINT8 *iv, VMUINT iv_len);

/*****************************************************************************
 * DESCRIPTION
 *    API used to execute cipher and hash process function.
 *    Since using Marco to reduce linkage code size, please pass the "type" parameter 
 *    as the constant announced in CHE_TYPE enum. It doesn't allow passing variable.
 *    The dest buffer size should be refer to the RFC standard specification.
 *    The DES/AES in CBC/ECB mode will do the auto padding if application uses the CHE's auto padding, 
 *    the destination buffer address has to be at least source_length + 1 DES block size(8 bytes) . 
 *    Otherwise, there will be a memory corruption. If application doesn't want to use auto padding,
 *    it cannot set the last_block to "TRUE". That is to say, as long as the last_block is not set to
 *    TRUE, there will no auto padding. The auto padding CHE uses is PKCS#1 v15. This padding is standard 
 *    padding used in PCKS#5.
 *    P.S. The input and output buffer should be different buffer. Don't use the same buffer.
 *
 * PARAMETERS 
 *    che_context_p   : [IN]        che context
 *    type          : [IN]        che type (CHE_TYPE)
 *    mode          : [IN]        che operation mode (VM_CHE_OPERATION_MODE)
 *    act           : [IN]        che action (CHE_ACTION)
 *    source        : [IN]        source input data buffer (it has to be 4-byte alignment for DES and AES)
 *    dest          : [OUT]       destination buffer (it has to be 4-byte alignment for DES)
 *    source_length : [IN]        source input buffer length
 *    final         : [IN]        KAL_TRUE: do the standard auto padding(PKCS#5). 
 *                                KAL_FLASE: don't do the standard auto padding(PKCS#5).
 *                                If user wants the auto padding, s/he has to set the final to TRUE in its final block
 *                                operation. On the contrary, if s/he doesn't want the auto padding, please do not set 
 *                                final to TRUE.
 * RETURN VALUES
 *    1  : CHE process successful
 *    0  : CHE process fail
 * SEE ALSO
 *  
 *
 *****************************************************************************/
extern VMUINT8 vm_che_process(vm_stche *che_context_p,vm_che_type type,vm_che_operation_mode mode,
						vm_che_action act, VMUINT8 *source,VMUINT8 *dest,VMUINT source_length,VMUINT8 last_block);

/*****************************************************************************
 * DESCRIPTION
 * API used to set, get, delete, generate the key value.
 * If user uses this API to get the key, CHE only stores the pointer of the key.
 * Thus, the key has to be kept until the che_deinit is called. There is only 
 * One exception, in the RSA, we will allocate another space to store the key.
 * Thus, user doesn't have to care if they can release the buffer of key.
 * PARAMETERS 
 *    che_context_p : [IN]        che context
 *    type :     [IN]        key action (vm_che_key_action_type)
 *    key :         [IN/OUT]    key stream
 *    key_ley :     [IN]        key stream length
 *
 *****************************************************************************/
extern void vm_che_key_action(vm_stche *che_context_p, vm_che_key_action_type type, VMUINT8 *key, VMINT key_len);

/*****************************************************************************
 * FUNCTION
 *  vm_che_rsa_public_encrypt
 * DESCRIPTION
 *  This API is used when we want to use public key to encrypt the data.
 *  Application can specify the way of padding based PKCS#1 standard.
 *  If application doesn't want to do the padding, s/he can set the padding to 
 *  VM_CHE_RSA_MODE_NULL.
 *
 *  Based on PKCS#1v1.5 standard, the smallest padding size is 11 bytes.
 *  Thus, the destination buffer should be:
 *  Destination_buffer_len = input_data_len + 11(smallest padding data)
 *  In addition, the output buffer size is equal to the size of N.
 *  If the input data length is too large or destination buffer is too small,
 *  the error cause will be returned. The output buffer length will be checked only
 *  If the passed in length is not 0. If it is 0, this means user doesn't want to check
 *  the destination buffer length.
 *  The input and output buffer can be the same one.
 *
 *  RSA valid public key length:
 *  128 bits < Modulus (N) < 4096 bits
 *  2 bits < public exponent (E) < 64  bits
 * PARAMETERS
 *  ctx      : [IN]     CHE context
 *  src      : [IN]     source buffer
 *  src_len  : [IN]     source buffer length (the length sould < length of N)
 *  dst      : [OUT]    destination buffer (must pass in)
 *  dst_len  : [IN/OUT] encrypted destination length. If user pass in non zero value,
 *                      CHE will do the destination buffer length check. If the length
 *                      smaller than the length of N. The error is returned. However,
 *                      If user pass in value 0, che will not do the length checking.
 *  padding  : [IN]     the way of padding. Currently we only support PKCS#1v1.5 padding.
 *                      If user doesn't want any padding, s/he can pass in VM_CHE_RSA_MODE_NULL.
 *                      Please take reference of the enum vm_che_rsa_padding_mode_enum
 *                       
 * RETURN VALUES
 *  take the reference of vm_che_result_error_enum.
 *  VM_CHE_OK : success
 *  VM_CHE_ERROR : parameter error
 *  VM_CHE_KEY_CHK_FAIL : input key is not correct
 *  VM_CHE_INVALID_LENGTH : the input data length is too large or 
 *                       destination buffer is too small
 *  VM_CHE_OPERATION_FAIL : algorithm operation is failed
 * SEE ALSO
 *  vm_che_rsa_private_encrypt
 *
 *****************************************************************************/
extern VMINT vm_che_rsa_public_encrypt(vm_stche *ctx, VMUINT8 *src, VMUINT src_len, VMUINT8 *dst, 
										VMUINT *dst_len, vm_che_rsa_padding_mode_enum padding);


/*****************************************************************************
 * FUNCTION
 *  vm_che_rsa_private_encrypt
 * DESCRIPTION
 *  This API is used when we want to use private key to encrypt the data.
 *  Application can specify the way of padding based PKCS#1 standard.
 *  If users don't want to do the padding, they can set the padding to 
 *  VM_CHE_RSA_MODE_NULL.
 *
 *  Based on PKCS#1v1.5 standard, the smallest padding size is 11 bytes.
 *  Thus, the destination buffer should be:
 *  Destination_buffer_len = input_data_len + 11(smallest padding data)
 *  In addition, the output buffer size is equal to the size of N.
 *  If the input data length is too large or destination buffer is too small,
 *  the error cause will be returned. The output buffer length will be checked only
 *  If the passed in length is not 0. If it is 0, this means user doesn't want to check
 *  the destination buffer length.
 *  The input and output buffer can be the same one.
 *
 * PARAMETERS
 *  ctx      : [IN]     CHE context
 *  src      : [IN]     source buffer
 *  src_len  : [IN]     source buffer length (the length sould < length of N)
 *  dst      : [OUT]    destination buffer (must pass in)
 *  dst_len  : [IN/OUT] encrypted destination length. If user pass in non zero value,
 *                      CHE will do the destination buffer length check. If the length
 *                      smaller than the length of N. The error is returned. However,
 *                      If user pass in value 0, che will not do the length checking.
 *  padding  : [IN]     the way of padding. Currently we only support PKCS#1v1.5 padding.
 *                      If users don't want any padding, they can pass in VM_CHE_RSA_MODE_NULL.
 *                      (vm_che_rsa_padding_mode_enum)
 *                       
 * RETURN VALUES
 *  take the reference of vm_che_result_error_enum.
 *  VM_CHE_OK : success
 *  VM_CHE_ERROR : parameter error
 *  VM_CHE_KEY_CHK_FAIL : input key is not correct
 *  VM_CHE_INVALID_LENGTH : the input data length is too large or 
 *                       destination buffer is too small
 *  VM_CHE_OPERATION_FAIL : algorithm operation is failed
 * SEE ALSO
 *  vm_che_rsa_public_encrypt
 *
 *****************************************************************************/
extern VMINT vm_che_rsa_private_encrypt(vm_stche *ctx, VMUINT8 *src, VMUINT src_len, VMUINT8 *dst, 
										VMUINT *dst_len, vm_che_rsa_padding_mode_enum padding);


/*****************************************************************************
 * FUNCTION
 *  vm_che_rsa_public_decrypt
 * DESCRIPTION
 *  This API is used when we want to use public key to decrypt the data.
 *  Application can specify the way of padding based PCKS#1 standard.
 *  If users don't want to do the padding, they can set the padding to 
 *  VM_CHE_RSA_MODE_NULL.
 *  If the input data is too large (> size of N), the error will be returned.
 *  If the input data is too small ( < smallest padding length(11)), 
 *  the error will be returned as well. 
 *  The input and output buffer can be the same one.
 *
 *  RSA valid public key length:
 *  128 bits < Modulus (N) < 4096 bits
 *  2 bits < public exponent (E) < 64  bits
 * PARAMETERS
 *  ctx      : [IN]     CHE context
 *  src      : [IN]     source buffer
 *  src_len  : [IN]     source buffer length (the length sould < length of N)
 *  dst      : [OUT]    destination buffer (must pass in)
 *  dst_len  : [IN/OUT] encrypted destination length. If user pass in non zero value,
 *                      CHE will do the destination buffer length check. If the length
 *                      smaller than the length of N. The error is returned. However,
 *                      If user pass in value 0, che will not do the length checking.
 *  padding  : [IN]     the way of padding. Currently we only support PKCS#1v1.5 padding.
 *                      If users don't want any padding, they can pass in VM_CHE_RSA_MODE_NULL.
 *                      (vm_che_rsa_padding_mode_enum)
 *                       
 * RETURN VALUES
 *  take the reference of vm_che_result_error_enum.
 *  VM_CHE_OK : success
 *  VM_CHE_ERROR : parameter error
 *  VM_CHE_KEY_CHK_FAIL : input key is not correct
 *  VM_CHE_INVALID_LENGTH : input data is too small or too long
 *  VM_CHE_OPERATION_FAIL : algorithm operation is failed
 * SEE ALSO
 *  che_rsa_private_encrypt
 *
 *****************************************************************************/
extern VMINT vm_che_rsa_public_decrypt(vm_stche *ctx, VMUINT8 *src, VMUINT src_len, VMUINT8 *dst, 
										VMUINT *dst_len, vm_che_rsa_padding_mode_enum padding);


/*****************************************************************************
 * FUNCTION
 *  vm_che_rsa_private_decrypt
 * DESCRIPTION
 *  This API is used when we want to use private key to decrypt the data.
 *  Application can specify the way of padding based PCKS#1 standard.
 *  If users don't want to do the padding, they can set the padding to 
 *  VM_CHE_RSA_MODE_NULL.
 *
 *  If the input data is too large (> size of N), the error will be returned.
 *  If the input data is too small ( < smallest padding length(11)), 
 *  the error will be returned as well. 
 *  The input and output buffer can be the same one.
 *
 * PARAMETERS
 *  ctx      : [IN]     CHE context
 *  src      : [IN]     source buffer
 *  src_len  : [IN]     source buffer length (the length sould < length of N)
 *  dst      : [OUT]    destination buffer (must pass in)
 *  dst_len  : [IN/OUT] encrypted destination length. If user pass in non zero value,
 *                      CHE will do the destination buffer length check. If the length
 *                      smaller than the length of N. The error is returned. However,
 *                      If user pass in value 0, che will not do the length checking.
 *  padding  : [IN]     the way of padding. Currently we only support PKCS#1v1.5 padding.
 *                      If users don't want any padding, they can pass in VM_CHE_RSA_MODE_NULL.
 *                      (vm_che_rsa_padding_mode_enum)
 *                       
 * RETURN VALUES
 *  take the reference of vm_che_result_error_enum.
 *  VM_CHE_OK : success
 *  VM_CHE_ERROR : parameter error
 *  VM_CHE_KEY_CHK_FAIL : input key is not correct
 *  VM_CHE_INVALID_LENGTH : input data is too small or too long
 *  VM_CHE_OPERATION_FAIL : algorithm operation is failed
 * SEE ALSO
 *  vm_che_rsa_public_encrypt
 *
 *****************************************************************************/	
extern VMINT vm_che_rsa_private_decrypt(vm_stche *ctx, VMUINT8 *src, VMUINT src_len, VMUINT8 *dst, 
										VMUINT *dst_len, vm_che_rsa_padding_mode_enum padding);

#ifdef __cplusplus
}
#endif

#endif /* VMCHE_SDK_H_ */

