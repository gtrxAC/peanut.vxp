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

#ifndef VM_SOCK_SDK_H
#define VM_SOCK_SDK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

/* connected status */
#define VM_TCP_EVT_CONNECTED	1

/* write status */
#define VM_TCP_EVT_CAN_WRITE	2

/* read status */
#define VM_TCP_EVT_CAN_READ		3

/* broken status */
#define VM_TCP_EVT_PIPE_BROKEN	4

/* not find host */
#define VM_TCP_EVT_HOST_NOT_FOUND	5

/* tcp pipe closed */
#define VM_TCP_EVT_PIPE_CLOSED	6

/* no enough resource to create tcp connection */
#define VM_TCP_ERR_NO_ENOUGH_RES	-1

/* create tcp connection failed */
#define VM_TCP_ERR_CREATE_FAILED	-2

/* use cmnet to connect */
#define VM_TCP_APN_CMNET		(1)

/* use cmwap to connect */
#define VM_TCP_APN_CMWAP		(2)

/* use wifi to connect */
#define VM_TCP_APN_WIFI		(3)

/* only use cmnet to connect */
#define VM_TCP_APN_CMNET_ONLY (4)

/* only use cmwap to connect */
#define VM_TCP_APN_CMWAP_ONLY (5)

/* only use when conbined with vm_dtacct_set */
#define VM_APN_USER_DEFINE (6)



/* write status */
#define VM_UDP_EVT_WRITE	2

/* read status */
#define VM_UDP_EVT_READ		3

/* broken status */
#define VM_UDP_EVT_PIPE_BROKEN	4

/* udp pipe closed */
#define VM_UDP_EVT_PIPE_CLOSED	6


typedef struct  
{
	VMINT		apn_info_id;
	VMINT		proxy_port;
	VMCHAR     operator_id[8];
	VMCHAR     operator_name[64];
	VMCHAR     proxy_ip[16];
	VMCHAR     apn_proxy[32];
	VMCHAR     apn_no_proxy[32];
	VMCHAR     user_name[16];
	VMCHAR     pass_word[16];
}vm_apn_info_ext;

/*****************************************************************************
 * FUNCTION
 *    vm_tcp_connect
 * DESCRIPTION
 *  create tcp connection.
 * PARAMETERS
 *  host : [IN] dest host ip.
 *  port : [IN] dest host port.
 *  apn : [IN] apn id, only support VM_TCP_APN_CMNET,VM_TCP_APN_CMWAP,VM_TCP_APN_WIFI.
 *  callback : [IN] callback function for tcp connection.
 * RETURNS
 *  create tcp success or not.
 * RETURN VALUES
 *  tcp handle, if value >=0, that is right, else is wrong
*****************************************************************************/
VMINT vm_tcp_connect(const char* host, const VMINT port, const VMINT apn,
	void (*callback)(VMINT handle, VMINT event));

/*****************************************************************************
 * FUNCTION
 *    vm_tcp_close
 * DESCRIPTION
 *  close tcp connection.
 * PARAMETERS
 *  handle : [IN] tcp handle.
*****************************************************************************/
void vm_tcp_close(VMINT handle);

#define VM_TCP_READ_EOF				(-1)

/*****************************************************************************
 * FUNCTION
 *    vm_tcp_read
 * DESCRIPTION
 *  read data from tcp connection.
 * PARAMETERS
 *  handle : [IN] tcp handle.
 *  buf : [OUT] data buffer.
 *  len : [OUT] data length.
 * RETURNS
 *  read data size.
 * RETURN VALUES
 *  read size, if value = VM_TCP_READ_EOF, means finishing reading.
*****************************************************************************/
VMINT vm_tcp_read(VMINT handle, void* buf, VMINT len);

/*****************************************************************************
 * FUNCTION
 *    vm_tcp_write
 * DESCRIPTION
 *  write data to tcp connection.
 * PARAMETERS
 *  handle : [IN] tcp handle.
 *  buf : [IN] data to write.
 *  len : [IN] data length.
 * RETURNS
 *  write data success or not.
 * RETURN VALUES
 *  if value >= 0 , it is right, else is wrong.
*****************************************************************************/
VMINT vm_tcp_write(VMINT handle, void* buf, VMINT len);


/*****************************************************************************
 * FUNCTION
 *    vm_is_support_wifi
 * DESCRIPTION
 *  query wifi support.
 * RETURNS
 *  support or not support wifi.
 * RETURN VALUES
 *  TRUE : support wifi
 *  FALSE : not support wifi
*****************************************************************************/
VMINT vm_is_support_wifi(void);


/*****************************************************************************
 * FUNCTION
 *    vm_wifi_is_connected
 * DESCRIPTION
 *  query wifi contect.
 * RETURNS
 *  contected or not contected wifi.
 * RETURN VALUES
 *  TRUE : wifi contect.
 *  FALSE : wifi not contected.
*****************************************************************************/
VMINT vm_wifi_is_connected(void);


/*****************************************************************************
 * FUNCTION
 *  vm_get_apn_info
 * DESCRIPTION
 *  Get Apn info after network connected
 * PARAMETERS
 *  current_apn_info : [OUT] apn info of current connection
 * RETURNS
 *  0 means successful
 * RETURN VALUES
 *  0 : successful
*****************************************************************************/
VMINT vm_get_apn_info(vm_apn_info_ext *current_apn_info);

/*****************************************************************************
 * FUNCTION
 *    vm_get_default_apn_info
 * DESCRIPTION
 *  get current default apn infomation.
 * RETURNS
 *  avaliable or not.
 * RETURN VALUES
 *  0 sucess, else failure
*****************************************************************************/
VMINT vm_get_default_apn_info( vm_apn_info_ext *apn_info);


#define VM_SOC_DNS_MAX_ADDR 5

/* Socket return codes, negative values stand for errors */
typedef enum
{
    VM_E_SOC_SUCCESS           = 0,     /* success */
    VM_E_SOC_ERROR             = -1,    /* error */
    VM_E_SOC_WOULDBLOCK        = -2,    /* not done yet */
    VM_E_SOC_LIMIT_RESOURCE    = -3,    /* limited resource */
    VM_E_SOC_INVALID_SOCKET    = -4,    /* invalid socket */
    VM_E_SOC_INVALID_ACCOUNT   = -5,    /* invalid account id */
    VM_E_SOC_NAMETOOLONG       = -6,    /* address too long */
    VM_E_SOC_ALREADY           = -7,    /* operation already in progress */
    VM_E_SOC_OPNOTSUPP         = -8,    /* operation not support */
    VM_E_SOC_CONNABORTED       = -9,    /* Software caused connection abort */
    VM_E_SOC_INVAL             = -10,   /* invalid argument */
    VM_E_SOC_PIPE              = -11,   /* broken pipe */
    VM_E_SOC_NOTCONN           = -12,   /* socket is not connected */
    VM_E_SOC_MSGSIZE           = -13,   /* msg is too long */
    VM_E_SOC_BEARER_FAIL       = -14,   /* bearer is broken */
    VM_E_SOC_CONNRESET         = -15,   /* TCP half-write close, i.e., FINED */
    VM_E_SOC_DHCP_ERROR        = -16,   /* DHCP error */
    VM_E_SOC_IP_CHANGED        = -17,   /* IP has changed */
    VM_E_SOC_ADDRINUSE         = -18,   /* address already in use */
    VM_E_SOC_CANCEL_ACT_BEARER = -19    /* cancel the activation of bearer */
} vm_soc_error_enum;


typedef struct
{
    VMUINT address[VM_SOC_DNS_MAX_ADDR];
    VMINT num;
    VMINT error_cause; /* vm_ps_cause_enum */
}vm_soc_dns_result;

/*****************************************************************************
 * FUNCTION
 *    vm_soc_get_last_error
 * DESCRIPTION
 *  get the error cause of socket. it is prefer to be called during socket callback.
 * RETURN VALUES
 *  refer to vm_soc_error_enum
*****************************************************************************/
VMINT vm_soc_get_last_error(void);

/*
VMINT vm_soc_get_host_by_name(const VMCHAR * host,
                                                            VMBYTE * addr,
                                                            VMBYTE * addr_len,
                                                            VMINT (*callback)(VMBYTE * addr, VMINT addr_len));
*/          
    
/*****************************************************************************
 * FUNCTION
 *  vm_soc_get_host_by_name
 * DESCRIPTION
 *  this function retrieves IP addresses associated with the specified host name. 
 * PARAMETERS
 * apn : [IN] 
 * host : [IN] domain to be resolved.
 * result : [OUT] DNS parsed result.
 * callback : [IN] point to the callback.
 * RETURNS
 *  success if 0, else failure.
 * RETURN VALUES
 *  VM_E_SOC_SUCCESS :			     Get IP address successfully, result is filled.
 *  VM_E_SOC_WOULDBLOCK :		     wait response from network, result could be gotten from callback.
 *  VM_E_SOC_INVAL :			         invalid arguments: null domain_name, etc.
 *  VM_E_SOC_ERROR :			         unspecified error
 *  VM_E_SOC_LIMIT_RESOURCE :		 socket resources not available
 *  VM_E_SOC_INVALID_ACCOUNT :      invalid data account id
*****************************************************************************/
VMINT vm_soc_get_host_by_name(VMINT apn, 
                                                                            const VMCHAR * host, 
                                                                            vm_soc_dns_result * result, 
                                                                            VMINT (*callback)(vm_soc_dns_result *));
                                                                            
/*****************************************************************************
 * FUNCTION
 *  vm_get_encoded_dtacct_id
 * DESCRIPTION
 *  this function retrieves data account id. 
 * PARAMETERS
 * apn : [IN] apn id, only support VM_TCP_APN_CMNET, VM_TCP_APN_WIFI
 * dtacct_id : [OUT] point to data account id.
 * RETURNS
 *  success if 0, else failure.
 * RETURN VALUES
*  VM_E_SOC_SUCCESS :               Get IP address successfully, result is filled.
*  VM_E_SOC_INVAL :                     invalid arguments: null domain_name, etc.
*  VM_E_SOC_INVALID_ACCOUNT :      invalid data account id
*****************************************************************************/
VMINT vm_get_encoded_dtacct_id(VMINT apn, VMUINT * dtacct_id);







#define VM_WLAN_LOC_MAC_ADDR_LEN 6
#define VM_WLAN_LOC_MAX_AP_LIST_NUM 30

typedef enum
{
    VM_WLAN_LOC_ERR_LOGICAL = -7,
    VM_WLAN_LOC_ERR_INTERNAL, 
    VM_WLAN_LOC_ERR_BUSY,
    VM_WLAN_LOC_ERR_BAD_PARAM,
    VM_WLAN_LOC_ERR_NO_RESOURCE,
    VM_WLAN_LOC_ERR_NOT_SUPPORT,
    VM_WLAN_LOC_ERR_NO_AUTHORIZATION,
    VM_WLAN_LOC_ERR_SUCCESS = 0
}vm_wlan_loc_error_t;

typedef enum
{
    VM_WLAN_LOC_SCAN_RESULT_SUCCESS = 0,   /* WLAN scan success */
    VM_WLAN_LOC_SCAN_RESULT_FAILED,        /* WLAN scan failed */
    VM_WLAN_LOC_SCAN_RESULT_ABORTED,       /* WLAN scan service is aborted */
    VM_WLAN_LOC_SCAN_RESULT_TOTAL
} vm_wlan_loc_scan_result_enum;

typedef struct
{
    VMUINT8 bssid[VM_WLAN_LOC_MAC_ADDR_LEN]; /* MAC address */
    VMINT rssi;
}vm_wlan_loc_supc_abm_bss_info_struct;

typedef struct
{
    const vm_wlan_loc_supc_abm_bss_info_struct * ap_list[VM_WLAN_LOC_MAX_AP_LIST_NUM]; /* bss info array */
    VMINT handle;
    vm_wlan_loc_scan_result_enum result;     /* scan result enum */
    VMUINT8 ap_list_num;/* total num of searched ap list */
}vm_wlan_loc_data_t;


/*****************************************************************************
 * FUNCTION
 *  vm_wlan_loc_search
 * DESCRIPTION
 *  The function is used to scan the AP list for applications.
 * PARAMETERS
 *  callback    :   [IN]    scan result callback notify function for APP
 *  user_data   :   [IN]    application piggyback data
 * RETURNS
 *  return value >= 0 : search handle id created successfully.
 *  return value < 0 : failure
 * RETURN VALUES
 *  VM_WLAN_LOC_ERR_BUSY : busy, could retry later
 *  VM_WLAN_LOC_ERR_NO_RESOURCE : no avalible resource
 *  VM_WLAN_LOC_ERR_NOT_SUPPORT : platform dose not support
*****************************************************************************/
VMINT vm_wlan_loc_search(void (*callback)(vm_wlan_loc_data_t * data, void * user_data), void * user_data);

/*****************************************************************************
 * FUNCTION
 *  vm_wlan_loc_search_abort
 * DESCRIPTION
 *  The function is used to abort the scanning AP list process for applications.
 * PARAMETERS
 *  handle  :   [IN]    created handle id from calling vm_wlan_loc_search
 * RETURNS
 *  success if 0, else failure.
 * RETURN VALUES
 *  VM_WLAN_LOC_ERR_BAD_PARAM : invalid input param
 *  VM_WLAN_LOC_ERR_NO_RESOURCE : no avalible resource
 *  VM_WLAN_LOC_ERR_NOT_SUPPORT : platform dose not support
 *****************************************************************************/
VMINT vm_wlan_loc_search_abort(VMINT handle);

/*****************************************************************************
 * FUNCTION
 *  vm_wlan_loc_get_connected_info
 * DESCRIPTION
 *  The function get info form ap which connected already
 * PARAMETERS
 * rssi : [OUT] rssi
 * bssid : [OUT] bssid
 * RETURNS
 *  success if 0, else failure.
 * RETURN VALUES
 *  VM_WLAN_LOC_ERR_BAD_PARAM : invalid input param
 *  VM_WLAN_LOC_ERR_NOT_SUPPORT : platform dose not support
 *  VM_WLAN_LOC_ERR_LOGICAL : maybe not connected
*****************************************************************************/
VMINT vm_wlan_loc_get_connected_info(vm_wlan_loc_supc_abm_bss_info_struct * info);

typedef enum
{
    E_PRELOAD_QUERYING,
    E_PRELOAD_AVAILABLE_UPDATE,
    E_PRELOAD_NO_UPDATE,
    E_PRELOAD_CONNECTING,
    E_PRELOAD_CONNECTED,
    E_PRELOAD_DOWNLOADING,
    E_PRELOAD_DOWNLOADED,
    E_PRELOAD_HOST_NOT_FOUND,
    E_PRELOAD_PIPE_CLOSED,
    E_PRELOAD_PIPE_BROKEN,
    E_PRELOAD_FAILURE,
    E_PRELOAD_ERR_PATH,
    E_PRELOAD_ABORT,
}vm_preload_state_e;

typedef struct
{
    VMUINT app_id;
//    VMCHAR ver[8];
//    VMCHAR imsi[32];
//    VMCHAR imei[32];
    VMCHAR * ua;
    /*
    VMCHAR sc[16];
    VMBYTE skb;
    VMBYTE stch;
    VMBYTE sgs;
    VMBYTE scs;
    VMINT w;
    VMINT h;
    */
}vm_preload_query_info_t;

typedef struct
{
    vm_preload_state_e state;
    void * user_data;
}vm_common_t;


/*
state in below
E_PRELOAD_DOWNLOADING,
E_PRELOAD_DOWNLOADED,
*/
typedef struct
{
    vm_common_t head;
    VMINT received;
    VMINT total;
}vm_preload_recv_data_t;

VMINT vm_preload_query(VMINT apn,
                       const VMCHAR * url, 
                       VMINT port,
                       const vm_preload_query_info_t * info,
                       void (*callback)(VMINT hdl, void * para), 
                       void * user_data);
                              
VMINT vm_preload_download_ex(VMINT hdl, const VMWCHAR * data, VMBOOL bDLA,void (*callback)(VMINT hdl, void * para), void * user_data);

VMINT vm_preload_download(VMINT hdl, const VMWCHAR * data, void (*callback)(VMINT hdl, void * para), void * user_data);

VMINT vm_preload_cancel(VMINT hdl);


#define VM_MAX_SOCK_ADDR_LEN 28

typedef struct 
{
    VMINT16	addr_len; /* address length */
    VMUINT16	port; /* port number */
    VMUINT8	addr[VM_MAX_SOCK_ADDR_LEN];
} vm_sockaddr_struct;

/*****************************************************************************
 * FUNCTION
 *    vm_udp_create
 * DESCRIPTION
 *  create udp socket.
 * PARAMETERS
 *  port : [IN] port number for binding.
 *  apn : [IN] apn id.
 *  callback : [IN] callback function for udp notification.
 *  loopback : [IN] loopback flag, non-zero: loopback; zero: no loopback.
 * RETURNS
 *  create udp success or not.
 * RETURN VALUES
 *  udp handle, if value >= 0; failue if < 0
*****************************************************************************/
VMINT vm_udp_create(VMINT port, VMINT apn, void (*callback)(VMINT hdl, VMINT event), VMINT loopback);
/*****************************************************************************
 * FUNCTION
 *    vm_udp_sendto
 * DESCRIPTION
 *  send data to the destination.
 * PARAMETERS
 *  hdl : [IN] udp handle.
 *  buf : [IN] buf.
 *  len : [IN] buf len.
 *  addr : [IN] the address of destination.
 * RETURNS
 *  size of sent data.
 * RETURN VALUES
 *  udp handle, if value >= 0; failue if < 0
*****************************************************************************/
VMINT vm_udp_sendto(VMINT hdl, const void * buf, VMINT32 len, const vm_sockaddr_struct * addr);
/*****************************************************************************
 * FUNCTION
 *    vm_udp_recvfrom
 * DESCRIPTION
 *  receive data from the destination.
 * PARAMETERS
 *  hdl : [IN] udp handle.
 *  buf : [OUT] buf.
 *  len : [IN] buf len.
 *  addr : [OUT] the address of destination.
 * RETURNS
 *  size of received data.
 * RETURN VALUES
 *  udp handle, if value >= 0; failue if < 0
*****************************************************************************/
VMINT vm_udp_recvfrom(VMINT hdl, void * buf, VMINT32 len, vm_sockaddr_struct * addr);
/*****************************************************************************
 * FUNCTION
 *    vm_udp_close
 * DESCRIPTION
 *  create udp socket.
 * PARAMETERS
 *  port : [IN] dest host port.
 *  apn : [IN] apn id.
 *  callback : [IN] callback function for udp notification.
 * RETURNS
 *  create udp success or not.
 * RETURN VALUES
 *  udp handle, if value >= 0; failue if < 0
*****************************************************************************/
VMINT vm_udp_close(VMINT hdl);



typedef enum
{
    VM_NETWORK_NONE = 0, /* No bit-wise operation for none case */
    VM_GSM = 0x0100, /* GSM protocol */
    VM_WCDMA = 0x0200, /* WCDMA protocol */
    VM_NETWORK_END_OF_ENUM /* reserved */
}vm_network_enum_t;

/*****************************************************************************
 * FUNCTION
 *  vm_srv_nw_info_get_protocol
 * DESCRIPTION
 *  Get the protocol of current network.
 * PARAMETERS
 *  sim_card : [IN] SIM index, eg: 0x1-SIM1, 0x2-SIM2
 * RETURNS
 *  vm_network_enum_t
 * RETURN VALUES
 *  VM_GSM, VM_WCDMA, failure if less than 0
 *****************************************************************************/
VMINT vm_srv_nw_info_get_protocol(VMINT sim_card);

/*****************************************************************************
 * FUNCTION
 *  vm_dtacct_set
 * DESCRIPTION
 *  set the current data account info that got from vm_dtacct_select. if app need to do connection 
 *  use this data account of the sim_id, VM_APN_USER_DEFINE should be passed as apn param. eg, 
 *  vm_tcp_connect(xx, xxx, VM_APN_USER_DEFINE, xxxx);
 * PARAMETERS
 *  sim_id : [IN] SIM index, eg: 0-SIM1, 1-SIM2, ...
 *  dtacct : [IN] account id
 * RETURN VALUES
 *  success if 0, else failure.
 *****************************************************************************/
VMINT vm_dtacct_set(VMINT sim_id, VMUINT32 dtacct);

/*****************************************************************************
 * FUNCTION
 *  vm_dtacct_select
 * DESCRIPTION
 *  show the current available data account list of the required sim_id. call back app when user selected
 *  one of them. app may record this data account value, for the vm_dtacct_set if necessary.
 * PARAMETERS
 *  sim_id : [IN] SIM index, eg: 0-SIM1, 1-SIM2, ...
 *  dtacct : [IN] account id
 * RETURN VALUES
 *  success if 0, else failure.
 *****************************************************************************/
VMINT vm_dtacct_select(VMINT sim_id, VMINT (*callback)(VMUINT32 dtacct));



typedef enum 
{
    VM_RES_TYPE_TCP,
    VM_RES_TYPE_UDP,
    VM_RES_TYPE_HTTP,
    VM_RES_TYPE_HTTPS
}vm_res_type_t;

/*****************************************************************************
 * FUNCTION
 *  vm_cbm_hold_bearer
 * DESCRIPTION
 *  hold the bearer.
 * PARAMETERS
 *  type : [IN] vm_res_type_t
 *  hdl : [IN] TCP : hdl = vm_tcp_connect
 *               UDP : hdl = vm_udp_create
 *               HTTP : hdl = vm_http_get_current_handle
 *                         hdl = vm_http_fetch_handle
 *               HTTPS : channel id
 * RETURN VALUES
 *  success if 0, failure if less than 0
 *****************************************************************************/
VMINT vm_cbm_hold_bearer(vm_res_type_t type, VMINT hdl);

/*****************************************************************************
 * FUNCTION
 *  vm_cbm_release_bearer
 * DESCRIPTION
 *  hold the bearer.
 * RETURN VALUES
 *  success if 0, failure if less than 0
 *****************************************************************************/
VMINT vm_cbm_release_bearer(void);


#define VM_SRV_DTCNT_PROF_MAX     (32)
#define VM_SRV_DTCNT_IP_MAX     (64)

typedef struct
{
    VMUINT8 APN[VM_SRV_DTCNT_PROF_MAX];    /* account name */
    VMUINT8 PrimaryAddr[VM_SRV_DTCNT_IP_MAX];    /* Primary DNS IP Address (ASCII) */
    VMUINT8 use_proxy;   /* use proxy flag */
    VMUINT8 UserName[VM_SRV_DTCNT_PROF_MAX];         /* User string of a Data Account (ASCII) */
    VMUINT8 Passwd[VM_SRV_DTCNT_PROF_MAX];             /* Password for a Data Account (ASCII) */
    VMUINT8 px_addr[VM_SRV_DTCNT_IP_MAX];         /* proxy addr string IP format (ASCII)*/
    VMUINT16 px_port;                                        /* proxy port */
}vm_dtcnt_info_t;

/*****************************************************************************
 * FUNCTION
 *  vm_set_cust_apn_info
 * DESCRIPTION
 *  set customized apn info. if successful, it will output data account(*dtacct) which value could be 
 * passed to 'vm_dtacct_set'. VM_APN_USER_DEFINE should be the param when do operation of network.
 * PARAMETERS
 *  info : [IN] refer to vm_dtcnt_info_t
 *  dtacct : [OUT] data account id
 * RETURN VALUES
 *  success if 0, else failure.
 *****************************************************************************/
VMINT vm_set_cust_apn_info(const vm_dtcnt_info_t * info, VMUINT32 * dtacct);

/*****************************************************************************
 * FUNCTION
 *  vm_get_cust_apn_info
 * DESCRIPTION
 *  get customized apn info. 
 * PARAMETERS
 *  info : [IN] refer to vm_dtcnt_info_t
 * RETURN VALUES
 *  success if 0, else failure.
 *****************************************************************************/
VMINT vm_get_cust_apn_info(vm_dtcnt_info_t * info);


/*****************************************************************************
 * FUNCTION
 *  vm_wlan_perfer
 * DESCRIPTION
 *  disable wlan perfer. 
 * PARAMETERS
 *  disable : [IN] disable if no-zero, or else is default.
 * RETURN VALUES
 *  success if 0, else failure.
 *****************************************************************************/
VMINT vm_wlan_perfer(VMINT disable);


/* This enum is used to define bearer status */
typedef enum
{
    VM_CBM_DEACTIVATED             = 0x01, /* bearer deactivated */
    VM_CBM_ACTIVATING              = 0x02, /* bearer activating */
    VM_CBM_ACTIVATED               = 0x04, /* bearer activated */
    VM_CBM_DEACTIVATING            = 0x08, /* bearer deactivating */
    VM_CBM_CSD_AUTO_DISC_TIMEOUT   = 0x10, /* csd auto disconnection timeout */
    VM_CBM_GPRS_AUTO_DISC_TIMEOUT  = 0x20, /* gprs auto disconnection timeout */
    VM_CBM_NWK_NEG_QOS_MODIFY      = 0x040, /* negotiated network qos modify notification */
    VM_CBM_BEARER_STATE_TOTAL
} vm_cbm_bearer_state_enum;

/* error cause */
typedef enum
{
    VM_CBM_OK                  = 0,  /* success */
    VM_CBM_ERROR               = -1, /* error */
    VM_CBM_WOULDBLOCK          = -2, /* would block */
    VM_CBM_LIMIT_RESOURCE      = -3, /* limited resource */
    VM_CBM_INVALID_ACCT_ID     = -4, /* invalid account id*/
    VM_CBM_INVALID_AP_ID       = -5, /* invalid application id*/
    VM_CBM_INVALID_SIM_ID      = -6, /* invalid SIM id */
    VM_CBM_BEARER_FAIL         = -7, /* bearer fail */
    VM_CBM_DHCP_ERROR          = -8, /* DHCP get IP error */
    VM_CBM_CANCEL_ACT_BEARER   = -9, /* cancel the account query screen, such as always ask or bearer fallback screen */
    VM_CBM_DISC_BY_CM          = -10,/* bearer is deactivated by the connection management */
    VM_CBM_IPV6_ERROR          = -11,/* IP get V6 address error */  
} vm_cbm_result_error_enum;




/* ip type */
typedef enum
{
    VM_CBM_IP_NONE = 0,
    VM_CBM_IPV4    = 0x01,  /* IPv4 */
    VM_CBM_IPV6    = 0x02,  /* IPv6 */
    VM_CBM_IPV4V6  = VM_CBM_IPV4 | VM_CBM_IPV6, /* IPv4v6 */
    VM_CBM_IP_TYPE_TOTAL,
} vm_cbm_ip_type_enum;



typedef struct
{
    VMUINT account_id; /* network account id */
    vm_cbm_bearer_state_enum state; /* bearer state */
    vm_cbm_result_error_enum error; /* error */
    VMINT error_cause; /* network error cause */
    vm_cbm_ip_type_enum ip_type; /* IP type */
}vm_cbm_bearer_info_struct;


/*****************************************************************************
 * FUNCTION
 *  vm_bearer_open_ex
 * DESCRIPTION
 *  Open the bearer.
 *
 *  P.S. We assume applications shall set its module id or register the application id 
 *  before calling this API.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  apn      : [IN] apn index
 *  user_data      : [IN]   user data
 *  callback_ex : [IN] callback function
 *  ip : [IN] ip type vm_cbm_ip_type_enum
 * RETURN VALUES
 *  VM_CBM_OK : bearer is in activated state.
 *  VM_CBM_INVALID_AP_ID : invalid application id.
 *  VM_CBM_INVALID_ACCT_ID : invalid network account id.
 *  VM_CBM_WOULDBLOCK : the bearer is in deactivating state and the bearer info 
 *                   will be reported later.
 *****************************************************************************/
VMINT vm_bearer_open_ex(VMINT apn, void *user_data, void (*callback_ex)(VMINT handle, VMINT event, void *param, void *user_data), vm_cbm_ip_type_enum ip);

/* The structure for DNS A RR entry */
typedef struct
{
    VMUINT8 address[4];   /* resolved IP address for queried domain name */
}vm_soc_dns_a_struct;

typedef struct
{
	VMUINT8 addr[16];   /* resolved IP address for queried domain name of ipv6*/
}vm_soc_dns_aaaa_struct;

typedef struct
{
    vm_soc_dns_aaaa_struct address[VM_SOC_DNS_MAX_ADDR]; /* address set */
    VMINT num; /* the numbers of address */
    VMINT error_cause; /* vm_ps_cause_enum */
}vm_soc_dns_v6_result;



/*****************************************************************************
 * FUNCTION
 *  vm_soc_gethostbynamev6
 * DESCRIPTION
 *  this function retrieves IPv6 addresses associated with the specified host name. 
 * PARAMETERS
 * apn : [IN] 
 * host : [IN] domain to be resolved.
 * result : [OUT] DNS parsed result.
 * callback : [IN] point to the callback.
 * user_data : [IN] user data.
 * RETURNS
 *  success if 0, else failure.
 * RETURN VALUES
 *  VM_E_SOC_SUCCESS :			     Get IP address successfully, result is filled.
 *  VM_E_SOC_WOULDBLOCK :		     wait response from network, result could be gotten from callback.
 *  VM_E_SOC_INVAL :			         invalid arguments: null domain_name, etc.
 *  VM_E_SOC_ERROR :			         unspecified error
 *  VM_E_SOC_LIMIT_RESOURCE :		 socket resources not available
 *  VM_E_SOC_INVALID_ACCOUNT :      invalid data account id
*****************************************************************************/
VMINT vm_soc_gethostbynamev6(VMINT apn, 
                                 const VMCHAR * host, 
                                 vm_soc_dns_v6_result * result, 
                                 VMINT (*callback)(VMINT, vm_soc_dns_v6_result *, void *), void *user_data);


/*****************************************************************************
 * FUNCTION
 *  vm_bearer_open
 * DESCRIPTION
 *  Open the bearer.
 *
 *  P.S. We assume applications shall set its module id or register the application id 
 *  before calling this API.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  account_id      : [IN]   account id which contains the application id. 
 *                                  App id must to be encoded in the account id
 * RETURN VALUES
 *  VM_CBM_OK : bearer is in activated state.
 *  VM_CBM_INVALID_AP_ID : invalid application id.
 *  VM_CBM_INVALID_ACCT_ID : invalid network account id.
 *  VM_CBM_WOULDBLOCK : the bearer is in deactivating state and the bearer info 
 *                   will be reported later.
 *****************************************************************************/
VMINT vm_bearer_open(VMINT apn, void *user_data, void (*callback)(VMINT handle, VMINT event, VMUINT param, void *user_data));

/*****************************************************************************
 * FUNCTION
 *  cbm_release_bearer
 * DESCRIPTION
 *  This API is used to release all bearers which are opened by this application. 
 *  The bearer will be released only when all sockets are closed. 
 *  If the sockets are all closed and this API is called, the bearer will be 
 *  deactivated. Otherwise, the bearer will be deactivated only when 
 *  all sockets which belong to this application are closed.
 *  If the bearer is opened by application directly through the API 
 *  "cbm_open_bearer", the bearer can be directly deactivated when 
 *  application calls the API cbm_release_bearer.  
 *
 *  P.S. We assume applications shall set its module id or register the application id 
 *  before calling this API.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  app_id      : [IN]    application id
 * RETURN VALUES
 *  CBM_OK : bearer is in deactivated state.
 *  CBM_INVALID_AP_ID : invalid application id.
 *  CBM_WOULDBLOCK : the bearer is in deactivating state and the bearer info 
 *                   will be reported later.
 * SEE ALSO
 *   cbm_hold_bearer
 * EXAMPLE
 *  <code>
 *  kal_uint8 ap_id;
 *  kal_int8 ret;
 *  ap_id = cbm_get_app_id ((kal_uint32)account_id); 
 *  ...
 *  if ((ret = cbm_release_bearer (ap_id)) == CBM_OK)
 *  {
 *    //bearer is deactivated
 *  }
 *  else
 *  {
 *      if (ret == CBM_WOULDBLOCK)
 *      {
 *          //bearer is not completely deactivated yet
 *      }
 *  }
 *  </code>
 *  After the bearer is deactivated:
 *  <code>
 *  app_cbm_bearer_info_ind_hdlr(local_para_struct *msg)
 *  {
 *      app_cbm_bearer_info_ind_struct *ind_ptr;
 *      ind_ptr = (app_cbm_bearer_info_ind_struct *)local_para_ptr;
 *      switch (ind_ptr->state)
 *      {
 *          case CBM_DEACTIVATED:
 *               app_bearer_deactivated_hdlr();
 *               break;
 *          ...
 *      }
 *  }
 *  </code>
 *****************************************************************************/
VMINT vm_bearer_close(VMINT hdl);



#define PF_INET         (0)  /* ipv4 */
#define PF_INET6         (1)  /* ipv6 */


#define SOCK_STREAM     (0)  /* stream socket, TCP */
#define SOCK_DGRAM      (1)  /* datagram socket, UDP */


/*
 * <GROUP  Macro_Consts>
 * 
 * Control message protocol. Currently, only allow applicaion to set this type when RAW_SOCKET is used 
 */
#define IPPROTO_ICMP    (1)

/* for SOC/TCP/IP internal use, application shall NOT use */

/*
 * <GROUP  Macro_Consts>
 * 
 * dummy for IP 
 */
#define IPPROTO_IP      (0)

/*
 * <GROUP  Macro_Consts>
 * 
 * IP6 hop-by-hop options 
 */
#define IPPROTO_HOPOPTS (0)     

/*
 * <GROUP  Macro_Consts>
 * 
 * group mgmt protocol 
 */
#define IPPROTO_IGMP    (2)  

/*
 * <GROUP  Macro_Consts>
 * 
 * IPv4 encapsulation 
 */
#define IPPROTO_IPV4    (4)     

/*
 * <GROUP  Macro_Consts>
 * 
 * for compatibility 
 */
#define IPPROTO_IPIP    IPPROTO_IPV4    

/*
 * <GROUP  Macro_Consts>
 * 
 * tcp protocol  
 */
#define IPPROTO_TCP     (6)             

/*
 * <GROUP  Macro_Consts>
 * 
 * user datagram protocol 
 */
#define IPPROTO_UDP     (17)    

/*
 * <GROUP  Macro_Consts>
 * 
 * raw IP packet 
 */
#define IPPROTO_RAW     (255)   

/// Generic Socket Address structure
typedef struct sockaddr {
    VMUINT16 sa_family;                   ///< Address family
    VMINT8   sa_data[14];                 ///< Direct address (up to 14 bytes)
} SOCKADDR;

/// Generic IPv4 Address structure
typedef struct in_addr {
  union {
    struct {
      VMUINT8 s_b1;
      VMUINT8 s_b2;
      VMUINT8 s_b3;
      VMUINT8 s_b4;      ///< IP address, byte access
    }S_un_b;
    struct {
      VMUINT16 s_w1;
      VMUINT16 s_w2;               ///< IP address, short int access
    }S_un_w;
    VMUINT32 s_addr;                    ///< IP address in network byte order
  }S_un;
} IN_ADDR;


/// IPv4 Socket Address structure
typedef struct sockaddr_in {
    VMINT16  sin_family;                  ///< Socket domain
    VMUINT16 sin_port;                    ///< Port
    IN_ADDR  sin_addr;                    ///< IP address
    VMINT8   sin_zero[8];                 ///< reserved
} SOCKADDR_IN;

/// Generic IPv6 Address structure
typedef struct in6_addr {
  union {
    VMUINT8 s6_u8[16];
    VMUINT32 s6_u32[4];
    VMUINT64 s6_u64[2];
  }S_all;
} IN6_ADDR;

/// IPv6 Socket Address structure
typedef struct sockaddr_in6 {
    VMINT16   sin_family;                  ///< Socket domain
    VMUINT16  sin_port;                    ///< Port
    VMUINT32  sin6_flowinfo;                /// IPv6 traffic class & flow info 
    IN6_ADDR  sin6_addr;                    ///< IP address
    VMUINT32  sin6_scop_id;                 /// set of interfaces for a scope
} SOCKADDR_IN6;


/*=================================================== 
 *
 * Socket APIs prototypes
 *
 *===================================================*/

/*****************************************************************************
* FUNCTION
*  socket
* DESCRIPTION
*  This function creates a socket. 
*  note: here is an advice for API usage. please use BSD socket API all in one sub thread. 
* PARAMETERS 
*  family             : [IN] Address family specification. PF_INET / PF_INET6
*  type               : [IN] Type specification for the new socket. 
*                           SOCK_STREAM    = connection based type,
*                           SOCK_DGRAM     = datagram connectionless type.
*  protocol         : [IN]  Particular protocol to be used with the socket that is specific to the indicated address family
* RETURN VALUES
*  A descriptor referencing the new socket indicates that no error occurred.
*  >=0 : socket id
*  VM_SOC_INVAL :           wrong parameters, domain, type, protocol
*  VM_SOC_LIMIT_RESOURCE :  no socket available
*  VM_SOC_BEARER_FAIL :     bearer broken
*****************************************************************************/
int vm_socket(int family, int type, int protocol);

/*****************************************************************************
* FUNCTION
*  socket_ex
* DESCRIPTION
*  This function creates a socket. 
*  note: here is an advice for API usage. please use BSD socket API all in one sub thread. 
* PARAMETERS 
*  family             : [IN] Address family specification. PF_INET / PF_INET6
*  type               : [IN] Type specification for the new socket. 
*                           SOCK_STREAM    = connection based type,
*                           SOCK_DGRAM     = datagram connectionless type.
*  protocol         : [IN]  Particular protocol to be used with the socket that is specific to the indicated address family
*  data_account  : [IN] data account for network which get from the callback param of vm_open_bearer.
* RETURN VALUES
*  A descriptor referencing the new socket indicates that no error occurred.
*  >=0 : socket id
*  VM_SOC_INVAL :           wrong parameters, domain, type, protocol
*  VM_SOC_LIMIT_RESOURCE :  no socket available
*  VM_SOC_BEARER_FAIL :     bearer broken
*****************************************************************************/
int vm_socket_ex(int family, int type, int protocol, VMUINT32 data_account);

/*****************************************************************************
* FUNCTION
*  closesocket
* DESCRIPTION
*  Receive data from endpoint node. 
* PARAMETERS 
*  sock               : [IN] Descriptor that identifies an unbound socket. 
* RETURN VALUES
*  VM_E_SOC_SUCCESS : success
*  VM_E_SOC_INVALID_SOCKET : invalid socket id
*****************************************************************************/
int vm_closesocket(int sock);

/*****************************************************************************
* FUNCTION
*  bind
* DESCRIPTION
* This function associates a local address with a socket.
* PARAMETERS 
*  sock               : [IN] Descriptor that identifies an unbound socket. 
*  addr               : [IN] Address to assign to the socket from the SOCKADDR structure. 
*  addrlen          : [IN] Length of the name. 
*  type               : [IN] Type specification for the new socket. 
*                           SOCK_STREAM    = connection based type,
*                           SOCK_DGRAM     = datagram connectionless type.
* RETURN VALUES
*  A descriptor referencing the new socket indicates that no error occurred.
*  VM_E_SOC_SUCCESS : success
*  VM_E_SOC_INVALID_SOCKET : invalid socket id
*  VM_E_SOC_BEARER_FAIL : bearer broken
*  VM_E_SOC_ERROR : unspecified error
*  VM_E_SOC_ADDRINUSE : the local port has been bound by other socket
*****************************************************************************/
int vm_bind(int sock, const SOCKADDR *addr, int addrlen, int type);

/*****************************************************************************
* FUNCTION
*  listen
* DESCRIPTION
*  This function prepares a socket to listen for incoming connections. 
* PARAMETERS 
*  sock               : [IN] Descriptor that identifies an unbound socket. 
*  backlog          : [IN] number of connection requests that can be queued 
* RETURN VALUES
*  A descriptor referencing the new socket indicates that no error occurred.
*   VM_E_SOC_SUCCESS : success
*   VM_E_SOC_INVALID_SOCKET : invalid socket id
*   VM_E_SOC_BEARER_FAIL : bearer broken
*   VM_E_SOC_OPNOTSUPP : only TCP can be listened
*   VM_E_SOC_ALREADY : already listened
*   VM_E_SOC_ERROR : unspecified error
*   VM_E_SOC_BEARER_FAIL : bearer broken
*****************************************************************************/
int vm_listen(int sock, int backlog);

/*****************************************************************************
* FUNCTION
*  accept
* DESCRIPTION
*  This function accepts a connection on a socket. 
* PARAMETERS 
*  sock               : [IN] Descriptor that identifies an unbound socket. 
*  addr               : [IN] Address to assign to the socket from the SOCKADDR structure. 
*  addrlen          : [IN] Length of the name. 
* RETURN VALUES
*  A descriptor referencing the new socket indicates that no error occurred.
*  >=0 : socket id of new connection
*  VM_E_SOC_INVALID_SOCKET : invalid socket id
*  VM_E_SOC_INVAL : socket is not calling soc_listen
*  VM_E_SOC_WOULDBLOCK : non-blocking
*  VM_E_SOC_CONNABORTED : server socket cannot receive anymore 
*  VM_E_SOC_BEARER_FAIL : bearer broken
*  VM_E_SOC_ERROR : unspecified error
*****************************************************************************/
int vm_accept(int sock, SOCKADDR *addr, int *addrlen);

/*****************************************************************************
* FUNCTION
*  connect
* DESCRIPTION
*  Connect a socket to a remote host. 
* PARAMETERS 
*  sock               : [IN] Descriptor that identifies an unbound socket. 
*  addr               : [IN] Address to assign to the socket from the SOCKADDR structure. 
*  addrlen          : [IN] Length of the name. 
* RETURN VALUES
*  A descriptor referencing the new socket indicates that no error occurred.
*  >=0 : socket id of new connection
*  VM_E_SOC_INVALID_SOCKET : invalid socket id
*  VM_E_SOC_INVAL : socket is not calling soc_listen
*  VM_E_SOC_WOULDBLOCK : non-blocking
*  VM_E_SOC_CONNABORTED : server socket cannot receive anymore 
*  VM_E_SOC_BEARER_FAIL : bearer broken
*  VM_E_SOC_ERROR : unspecified error
*****************************************************************************/

int vm_connect(int sock, SOCKADDR *addr, int addrlen);
/*****************************************************************************
* FUNCTION
*  send
* DESCRIPTION
*  Send data on already connected socket. 
* PARAMETERS 
*  sock               : [IN] Descriptor that identifies an unbound socket. 
*  buf                 : [IN] pointer to application data buffer to transmit.
*  len                 : [IN]length of data (in bytes).
*  flags              : [IN]message flags:
* RETURN VALUES
*  A descriptor referencing the new socket indicates that no error occurred.
*  >=0 : socket id of new connection
*  VM_E_SOC_INVALID_SOCKET : invalid socket id
*  VM_E_SOC_INVAL : socket is not calling soc_listen
*  VM_E_SOC_WOULDBLOCK : non-blocking
*  VM_E_SOC_CONNABORTED : server socket cannot receive anymore 
*  VM_E_SOC_BEARER_FAIL : bearer broken
*  VM_E_SOC_ERROR : unspecified error
*****************************************************************************/

int vm_send(int sock, const char *buf, int len, int flags);
/*****************************************************************************
* FUNCTION
*  sendto
* DESCRIPTION
*  Send data to endpoint node. 
* PARAMETERS 
*  sock               : [IN] Descriptor that identifies an unbound socket. 
*  buf                 : [IN] pointer to application data buffer to transmit.
*  len                 : [IN]length of data (in bytes).
*  flags              : [IN]message flags:
*  to                   : [IN] structure containing remote IP address and port. 
*  tolen              : [IN] length of \ref SOCKADDR structure. 
* RETURN VALUES
*  >=0 : SUCCESS
*  VM_E_SOC_INVALID_SOCKET : invalid socket id
*  VM_E_SOC_INVAL : buf is NULL or len equals to zero
*  VM_E_SOC_WOULDBLOCK : buffer not available or bearer is establishing
*  VM_E_SOC_BEARER_FAIL : bearer broken
*  VM_E_SOC_NOTCONN : socket is not connected in case of TCP
*  VM_E_SOC_PIPE : socket is already been shutdown
*  VM_E_SOC_MSGSIZE : message is too long
*  VM_E_SOC_ERROR : unspecified error
*  VM_E_SOC_NOTBIND : in case of sending ICMP Echo Request, shall bind before
*****************************************************************************/
int vm_sendto(int sock, const char *buf, int len, int flags, const SOCKADDR *to, int tolen);
/*****************************************************************************
* FUNCTION
*  recv
* DESCRIPTION
*  Receive data on already connected socket. 
* PARAMETERS 
*  sock               : [IN] Descriptor that identifies an unbound socket. 
*  buf                 : [OUT] pointer to application data buffer to transmit.
*  len                 : [IN]length of data (in bytes).
*  flags              : [IN]message flags:
* RETURN VALUES
*  >0 : number of bytes received
*   0 : receive the FIN from the server
*  VM_E_SOC_INVALID_SOCKET : invalid socket id
*  VM_E_SOC_INVAL : buf is NULL or len equals to zero
*  VM_E_SOC_WOULDBLOCK : no data available 
*  VM_E_SOC_BEARER_FAIL : bearer broken
*  VM_E_SOC_NOTCONN : socket is not connected in case of TCP
*  VM_E_SOC_PIPE : socket is already been shutdown
*  VM_E_SOC_ERROR : unspecified error
*****************************************************************************/
int vm_recv(int sock, char *buf, int len, int flags);

/*****************************************************************************
* FUNCTION
*  recvfrom
* DESCRIPTION
*  Receive data from endpoint node. 
* PARAMETERS 
*  sock               : [IN] Descriptor that identifies an unbound socket. 
*  buf                 : [OUT] pointer to application data buffer to transmit.
*  len                 : [IN]length of data (in bytes).
*  flags              : [IN]message flags:
*  from                 : [OUT]structure containing remote IP address and port
*  fromlen              : [IN/OUT]length of \ref SOCKADDR structure:
* RETURN VALUES
*  0 :                   receive the FIN from the server
*  VM_E_SOC_INVALID_SOCKET :  invalid socket id
*  VM_E_SOC_INVAL :           buf is NULL or len equals to zero
*  VM_E_SOC_WOULDBLOCK :      no data available
*  VM_E_SOC_BEARER_FAIL :     bearer broken
*  VM_E_SOC_NOTCONN :         socket is not connected in case of TCP
*  VM_E_SOC_PIPE :            socket is already been shutdown
*  VM_E_SOC_ERROR :           unspecified error
*****************************************************************************/
int vm_recvfrom(int sock, char *buf, int len, int flags, SOCKADDR *from, int *fromlen);

#define VM_FD_SETSIZE 25

/* Macros for SOC_SELECT */
typedef struct
{
    VMUINT8	fds_bits[VM_FD_SETSIZE]; /* select set based on socket id */
} vm_fd_set;

#ifdef fd_set
#undef fd_set
#define fd_set vm_fd_set
#else
#define fd_set vm_fd_set
#endif

/*
 * <GROUP  Macro_Funcs>
 * 
 * set the socket id which you want to select 
 */

#ifdef FD_SET
#undef FD_SET
#define	FD_SET(s, p)            ((p)->fds_bits[s] |= 0x01)
#else
#define	FD_SET(s, p)            ((p)->fds_bits[s] |= 0x01)
#endif

/*
 * <GROUP  Macro_Funcs>
 * 
 * clear the socket id which you don't want to select 
 */

#ifdef FD_CLR
#undef FD_CLR
#define	FD_CLR(s, p)            ((p)->fds_bits[s] &= ~(0x01))
#else
#define	FD_CLR(s, p)            ((p)->fds_bits[s] &= ~(0x01))
#endif

/*
 * <GROUP  Macro_Funcs>
 * 
 * check if the socket id is selected 
 */
#ifdef FD_ISSET
#undef FD_ISSET
#define	FD_ISSET(s, p)          ((p)->fds_bits[s] & 0x02)
#else
#define	FD_ISSET(s, p)          ((p)->fds_bits[s] & 0x02)
#endif

/*
 * <GROUP  Macro_Funcs>
 *  
 * clear the select set 
 */
#ifdef FD_ZERO
#undef FD_ZERO
#define FD_ZERO(p)              memset(p, 0x00, sizeof(*(p)))
#else
#define FD_ZERO(p)              memset(p, 0x00, sizeof(*(p)))
#endif



/* select timeout structure */
typedef struct 
{
    VMUINT32 tv_sec;  /* select timeout: no. of second */
    VMUINT32 tv_usec; /* select timeout: no. of microsecond */
} timeval;


/*****************************************************************************
 * <GROUP  Berkley_API>
 *
 * FUNCTION
 *  select
 * DESCRIPTION
 *  Allow the application to query the status of multiple sockets.
 *  If tv is null, soc_select will wait indefinitely until the first socket is ready. 
 *  If both tv_sec and tv_msec are zero, soc_select will timeout immediately for 
 *  polling the sockets in the set.
 *  in: 
 *  1. If listen has been called and a connection is pending, accept will succeed. 
 *  2. Data is available for reading (includes OOB data if VM_SOC_OOBINLINE is enabled). 
 *  3. Connection has been closed/reset/terminated
 *  out: 
 *  1. If processing a connect request (non-blocking mode), connection has succeeded. 
 *  2. Data can be sent. 
 *  ex: 
 *  If processing a connect request (non-blocking mode), connection attempt failed. 
 *  OOB data is available for reading (only if VM_SOC_OOBINLINE is disabled).
 *  Useful Macros:
 *   FD_ZERO(fd_set)		 reset fd_set
 *   FD_SET(s, fd_set)		 add a particular socket with id of s to fd_set
 *   FD_CLR(s, fd_set)		 remove a particular socket with id of s from fd_set
 *   FD_ISSET(s, fd_set)	 Nonzero if s is a member of the fd_set (s is ready). 
 *                                   Otherwise, zero 
 * PARAMETERS
 *  nfds       : [IN]            max selected socket id plus 1
 *  readfds          : [IN]        input fd_set (readfds)
 *  writefds         : [IN]        output fd_set (writefds)
 *  exceptfds          : [IN]        exception fd_set (exceptfds)
 *  timeout          : [IN]            specify the timeout value,
 *                              timeout == NULL: block until ready
 *                              timeout != NULL && value == 0: return immediately
 *                              timeout != NULL && value != 0: return after timeout
 * RETURN VALUES
 *  >0 :                     number of ready sockets
 *   0 :                     timeout expires before anything interesting happens
 *  VM_E_SOC_INVALID_SOCKET :	 selected sockets are not belong to this module
 *  VM_E_SOC_INVAL : 			 invalid arguments: ndesc, in, out, ex
 *  VM_E_SOC_WOULDBLOCK :		 non-blocking
 *  VM_E_SOC_BEARER_FAIL :		 bearer broken
 *  VM_E_SOC_ERROR :	    		 unspecified error
 * EXAMPLE
 * <code>
 *  timeval timeout;
 *  fd_set writefds;
 *  timeout.tv_sec = 0;
 *  timeout.tv_usec = 2000;
 *  FD_ZERO(&writefds);
 *  FD_SET((bf_u32)sockIds[sock].id, &writefds);
 *  if (select(sockIds[sock].id+1, 0, &writefds, 0, &timeout) >= 0)
 *  {
 *     if (FD_ISSET(sockIds[sock].id, &writefds))
 *     {
 *         //socket is ready for writting data
 *     }
 *  }
 * </code>   
 *****************************************************************************/
int vm_select(int nfds,
                           fd_set *readfds,
                           fd_set *writefds,
                           fd_set *exceptfds,
                           const timeval *timeout);


/* howto arguments for shutdown(2), specified by Posix.1g. */
typedef enum
{
    VM_SHUT_RD   = 0x01,         /* shut down the reading side */
    VM_SHUT_WR   = 0x02,         /* shut down the writing side */
    VM_SHUT_RDWR = VM_SHUT_RD | VM_SHUT_WR   /* shut down both sides */
} vm_shutdown_enum;

/*****************************************************************************
 * FUNCTION
 *  shutdown
 * DESCRIPTION
 *  This function shutdowns the connection in aspects of reading, writing
 *  or both. 
 *  For the read-half, soc_shutdown discards the received data that applications haven't yet 
 *  and any incoming data. For the write-half of TCP, the remaining data will be sent first, 
 *  then FIN will be sent to close the connection.
 * PARAMETERS
 *  sock           : [IN]        socket id
 *  how         : [IN]        specify shutdown read/write/both
 * RETURN VALUES
 *  VM_E_SOC_SUCCESS : success
 *  VM_E_SOC_INVALID_SOCKET : invalid socket id
 *  VM_E_SOC_INVAL : invalid how
 *  VM_E_SOC_ERROR : unspecified error
 * EXAMPLE
 * <code>
 * INT handle;
 * shutdown((kal_int8) handle, SHUT_WR);
 * </code>
 *****************************************************************************/
int vm_shutdown(int sock,  int how);


/* Socket Options */
typedef enum
{
    VM_SOC_OOBINLINE     = 0x01 << 0,  /* not support yet */
    VM_SOC_LINGER        = 0x01 << 1,  /* linger on close */
    VM_SOC_NBIO          = 0x01 << 2,  /* Nonblocking */
    VM_SOC_ASYNC         = 0x01 << 3,  /* Asynchronous notification */   

    VM_SOC_NODELAY       = 0x01 << 4,  /* disable Nagle algorithm or not */
    VM_SOC_KEEPALIVE     = 0x01 << 5,  /* enable/disable the keepalive */
    VM_SOC_RCVBUF        = 0x01 << 6,  /* set the socket receive buffer size */
    VM_SOC_SENDBUF       = 0x01 << 7,  /* set the socket send buffer size */

    VM_SOC_NREAD         = 0x01 << 8,  /* no. of bytes for read, only for soc_getsockopt */
    VM_SOC_PKT_SIZE      = 0x01 << 9,  /* datagram max packet size */
    VM_SOC_SILENT_LISTEN = 0x01 << 10, /* SOC_SOCK_SMS property */
    VM_SOC_QOS           = 0x01 << 11, /* set the socket qos */

    VM_SOC_TCP_MAXSEG    = 0x01 << 12, /* set the max segmemnt size */
    VM_SOC_IP_TTL        = 0x01 << 13, /* set the IP TTL value */
    VM_SOC_LISTEN_BEARER = 0x01 << 14, /* enable listen bearer */
    VM_SOC_UDP_ANY_FPORT = 0x01 << 15, /* enable UDP any foreign port */

    VM_SOC_WIFI_NOWAKEUP = 0x01 << 16, /* send packet in power saving mode */
    VM_SOC_UDP_NEED_ICMP = 0x01 << 17, /* deliver NOTIFY(close) for ICMP error */
    VM_SOC_IP_HDRINCL    = 0x01 << 18,  /* IP header included for raw sockets */
    VM_SOC_IPSEC_POLICY      = 0x01 << 19, /* ip security policy */
    VM_SOC_TCP_ACKED_DATA  = 0x01 << 20,  /* TCPIP acked data */
    VM_SOC_TCP_DELAYED_ACK = 0x01 << 21, /* TCP delayed ack */
    VM_SOC_TCP_SACK        = 0x01 << 22, /* TCP selective ack */
    VM_SOC_TCP_TIME_STAMP  = 0x01 << 23,  /* TCP time stamp */
    VM_SOC_TCP_ACK_MSEG  = 0x01 << 24   /* TCP ACK multiple segment */
} option_enum;


/*****************************************************************************
 * FUNCTION
 *  setsockopt
 * DESCRIPTION
 *  This function sets the socket options.
 * PARAMETERS
 *  sock               : [IN]        socket id
 *  option          : [IN]        option type (soc_option_enum)
 *  val             : [IN]         option value (soc_event_enum for SOC_ASYNC)
 *  val_size        : [IN]        option value size
 * RETURN VALUES
 *  VM_E_SOC_SUCCESS :            success
 *  VM_E_SOC_INVALID_SOCKET :	 invalid socket id
 *  VM_E_SOC_INVAL :			     invalid arguments: option, val and val_size
 *  VM_E_SOC_ERROR :			     unspecified error
 * SEE ALSO
 *   getsockopt
 * EXAMPLE
 * VM_SOC_NBIO:
 * this option must to be set if you want to use the non-blocking mode or
 * non-blocking plus asyn mode.
 * val contains KAL_TRUE indicates non-blocking shall be adopted, 
 * KAL_FALSE indicates blocking mode shall be adopted. 
 * For example, set a socket to non-blocking mode:
 * kal_bool val = KAL_TRUE;
 * setsockopt(sock,  SOC_NBIO, &val, sizeof(kal_bool));
 *
 * VM_SOC_SILENT_LISTEN:
 * val contains KAL_TRUE indicates the silent listen shall be adopted, 
 * KAL_FALSE indicates non-silent listen shall be adopted. 
 * This is SOC_SOCK_SMS property. For example, if you want to let the socket be 
 * the passive to activate the bear, you can set a socket to silent listen mode:
 * For example:
 * kal_bool val = KAL_TRUE;
 * setsockopt(sock,  VM_SOC_SILENT_LISTEN, &val, sizeof(kal_bool))
 *
 * VM_SOC_UDP_NEED_ICMP:
 * This option is used to deliver NOTIFY(close) for ICMP error.
 * val contains KAL_TRUE indicates this option shall be enabled, 
 * KAL_FALSE indicates this option shall be disabled. 
 * For example, if you want to let set a socket to UDP NEED ICMP mode:
 * kal_bool val = KAL_TRUE;
 * setsockopt(sock,  VM_SOC_UDP_NEED_ICMP, &val, sizeof(kal_bool))
 *
 * VM_SOC_ASYNC:
 * this option needs to be set if you want to use the non-blocking plus asyn mode.
 * val contains the events application wants to receive. 
 * For example, if application wants to receive 
 * READ/WRITE/CLOSE/CONNECT events, 
 * it shall call soc_setsockopt like the following:
 * kal_uint8 val = 0;
 * val = SOC_READ | SOC_WRITE | SOC_CLOSE | SOC_CONNECT;
 * setsockopt(sock,  VM_SOC_ASYNC, &val, sizeof(kal_uint8));
 * P.S. if you are using the server socket, please remember to set the SOC_ACCPET event.
 *
 * VM_SOC_TCP_MAXSEG:
 * A process can only decrease the MSS. When a TCP socket is created, 
 * the default MSS is set to 512. The MSS is updated according to the value announced 
 * from peer TCP after the socket completes TCP three-way handshake. 
 * Therefore, after a socket is created but before connected, a process can only decrease 
 * the MSS from its default of 512. After a connection is established, 
 * the process can decrease the MSS from the new updated value.
 *
 * The value of TCP MSS is reduced to fit the interface MTU if the application set an 
 * unacceptable large value.
 * For example:
 * kal_uint8 val = 512;
 * setsockopt(sock,  VM_SOC_TCP_MAXSEG, &val, sizeof(kal_uint8)); 
 *
 * VM_SOC_LISTEN_BEARER:
 * val contains bear type indicates which kind of bear we want to receive packets from. 
 * For example, set a socket to receive the WiFi bear:
 * kal_uint8 val = SOC_BEARER_WIFI;
 * setsockopt(sock,  VM_SOC_LISTEN_BEARER, &val, sizeof(kal_uint8));
 *
 * VM_SOC_WIFI_NOWAKEUP:
 * val contains KAL_TRUE indicates this option shall be enabled, 
 * KAL_FALSE indicates this option shall be disabled. 
 * This option is to make WNDRV sends outgoing packet to in power saving mode. 
 * For example:
 * kal_bool val = KAL_TRUE;
 * setsockopt(sock,  VM_SOC_WIFI_NOWAKEUP, &val, sizeof(kal_bool))
 *
 * VM_SOC_IP_HDRINCL:
 * val contains KAL_TRUE indicates this option shall be enabled, 
 * KAL_FALSE indicates this option shall be disabled. If this option is set for a raw IP socket, 
 * we must build our own IP header for all the datagrams that we send on the raw socket. 
 * We can only set this socket option if the socket type in soc_create is 
 * SOC_SOCK_RAW(raw socket) and protocol in soc_create is not SOC_IPPROTO_ICMP.
 * For example:
 * kal_bool val = KAL_TRUE;
 * setsockopt(sock,  VM_SOC_IP_HDRINCL, &val, sizeof(kal_bool))
 *
 * VM_SOC_UDP_ANY_FPORT:
 * val contains KAL_TRUE indicates this option shall be enabled, 
 * KAL_FALSE indicates this option shall be disabled. For a connected UDP socket, 
 * this option makes socket deliver incoming packet from the same remote 
 * address but different remote port. 
 * For example:
 * kal_bool val = KAL_TRUE;
 * setsockopt(sock,  VM_SOC_UDP_ANY_FPORT, &val, sizeof(kal_bool))
 *
 * VM_SOC_IP_TTL:
 * val contains the TTL values . If you want to change the default TTL (64), 
 * you can set this option. For example:
 * kal_uint8 val = 128;
 * setsockopt(sock,  VM_SOC_IP_TTL, &val, sizeof(kal_uint8))
 *
 * VM_SOC_QOS:
 * val contains the TOS values . If you want to set the TOS values, you can set this option. 
 * For example:
 * kal_uint8 val = 0x80;
 * setsockopt(sock,  VM_SOC_QOS, &val, sizeof(kal_uint8))
 *
 * VM_SOC_KEEPALIVE:
 * val contains KAL_TRUE indicates this option shall be enabled, 
 * KAL_FALSE indicates this option shall be disabled. 
 * You can use this option to enable or disable the keep-alive timer in TCP. 
 * For example:
 * kal_bool val = KAL_TRUE;
 * setsockopt(sock,  VM_SOC_KEEPALIVE, &val, sizeof(kal_bool))
 *
 * VM_SOC_NODELAY:
 * val contains KAL_TRUE indicates this option shall be enabled, 
 * KAL_FALSE indicates this option shall be disabled. 
 * If you want to send the packet directly without waiting a packet size larger than MSS, 
 * you can set this option. For example:
 * kal_bool val = KAL_TRUE;
 * soc_setsockopt(sock,  VM_SOC_NODELAY, &val, sizeof(kal_bool))
 *
 * VM_SOC_SENDBUF:
 * val contains the value of send buffer's high water mark.  
 * If you want to set the high water mark, you can set this option. 
 * If the value you set is smaller than the MSS, the mss would be adjusted to this value. 
 * The value must be greater than 0 and smaller than the SSPDU + SSPDU_GROW. 
 * For example:
 * kal_uint32 val = 1024;
 * setsockopt(sock,  VM_SOC_SENDBUF, &val, sizeof(kal_uint32))
 *
 * VM_SOC_RECVBUF:
 * val contains the value of receive buffer's high water mark.  
 * If you want to set the high water mark, you can set this option. 
 * This value must be greater than 0 and smaller than the SRPDU size.  
 * For example:
 * kal_uint32 val = 4096;
 * soc_setsockopt(sock,  VM_SOC_RECVBUF, &val, sizeof(kal_uint32))
 *
 * VM_SOC_LINGER:
 * val contains the value of enable/diable LINGER option and the value of LINGER time. 
 * This option is used in linger on close. 
 * For example:
 * soc_linger_struct val; 
 * val.onoff = KAL_TRUE; val.
 * linger_time = 3; (sec)
 * setsockopt(sock,  VM_SOC_LINGER, &val, sizeof(soc_linger_struct_val));
 *
 * VM_SOC_IPSEC_POLICY:
 * val contains sadb_x_policy structure content.
 * You can set this option to set the IPSEC policy.
 * If you want to get the IPSEC policy, 
 * you can set this option. For example:
 * struct sadb_x_policy policy;
 * policy.sadb_x_policy_len = PFKEY_UNIT64(sizeof(policy));
 * policy.sadb_x_policy_exttype = SADB_X_EXT_POLICY;
 * policy.sadb_x_policy_type = 4;  // IPSEC_POLICY_BYPASS;
 * policy.sadb_x_policy_dir = 1;   // IPSEC_DIR_INBOUND;
 * setsockopt(sock,  VM_SOC_IPSEC_POLICY, &policy, sizeof(sadb_x_policy))
 *
 * VM_SOC_TCP_DELAYED_ACK:
 * The VM_SOC_TCP_DELAYED_ACK function is enable by default. That is to say, 
 * if you don't set this option. The default VM_SOC_TCP_DELAYED_ACK value is TRUE.
 * val contains KAL_TRUE indicates this option shall be enabled, 
 * KAL_FALSE indicates this option shall be disabled. 
 * If you want to enable the "TCP no delay" function, 
 * you can set this option. For example:
 * kal_bool val = KAL_TRUE;
 * setsockopt(sock,  VM_SOC_TCP_DELAYED_ACK, &val, sizeof(kal_bool))
 *
 * VM_SOC_TCP_SACK:
 * The VM_SOC_TCP_SACK function is enable by default. That is to say, 
 * if you don't set this option. The default VM_SOC_TCP_SACK value is TRUE.
 * val contains KAL_TRUE indicates this option shall be enabled, 
 * KAL_FALSE indicates this option shall be disabled. 
 * If you want to enable the "TCP SACK" function, 
 * you can set this option. For example:
 * kal_bool val = KAL_TRUE;
 * setsockopt(sock,  VM_SOC_TCP_SACK, &val, sizeof(kal_bool)) 
 *
 * VM_SOC_TCP_TIME_STAMP:
 * The VM_SOC_TCP_TIME_STAMP function is enable by default. That is to say, 
 * if you don't set this option. The default VM_SOC_TCP_TIME_STAMP value is TRUE.
 * val contains KAL_TRUE indicates this option shall be enabled, 
 * KAL_FALSE indicates this option shall be disabled. 
 * If you want to enable the "TCP TIME STAMP" function, 
 * you can set this option. For example:
 * kal_bool val = KAL_TRUE;
 * setsockopt(sock,  VM_SOC_TCP_TIME_STAMP, &val, sizeof(kal_bool)) 
 *
 *****************************************************************************/
int vm_setsockopt(int sock,  VMUINT32 option, void *val, VMUINT8 val_size);

/*****************************************************************************
 * FUNCTION
 *  getsockopt
 * DESCRIPTION
 *  This function gets the socket options.
 * PARAMETERS
 *  sock               : [IN]        socket id
 *  option          : [IN]        option type (soc_option_enum)
 *  val             : [IN]    option value
 *  val_size        : [IN]        option value size
 * RETURN VALUES
 *  VM_E_SOC_SUCCESS :        get the socket option successfully
 *  VM_E_SOC_INVALID_SOCKET : invalid socket id
 *  VM_E_SOC_INVAL :			 invalid arguments: option, val and val_size
 *  VM_E_SOC_ERROR :			 unspecified error
 * SEE ALSO
 *   setsockopt
 * EXAMPLE
 *  
 * VM_SOC_TCP_DELAYED_ACK:
 * val contains kal_bool to hold the option behavior.
 * If you don't set this option, the default value you get is KAL_TRUE.
 * If you to get this option, you can do:
 * <code>
 * kal_bool val;
 * getsockopt(sock,  SOC_TCP_DELAYED_ACK, &val, sizeof(kal_bool))
 * </code>
 *
 * VM_SOC_TCP_SACK:
 * val contains kal_bool to hold the option behavior.
 * If you don't set this option, the default value you get is KAL_TRUE.
 * If you to get this option, you can do:
 * <code>
 * kal_bool val;
 * getsockopt(sock,  SOC_TCP_SACK, &val, sizeof(kal_bool))
 * </code>
 *
 * VM_SOC_TCP_TIME_STAMP:
 * val contains kal_bool to hold the option behavior.
 * If you don't set this option, the default value you get is KAL_TRUE.
 * If you to get this option, you can do:
 *  <code>
 *  kal_bool val;
 *  getsockopt(sock,  SOC_TCP_TIME_STAMP, &val, sizeof(kal_bool))
 *  </code>  
 *****************************************************************************/
 int vm_getsockopt(int sock,  VMUINT32 option, void *val, VMUINT8 val_size);

/*****************************************************************************
 * FUNCTION
 *  getsockname
 * DESCRIPTION
 *  Retrieve local IP address and port number.
 * PARAMETERS
 *  sock [IN]         socket descriptor obtained with  socket.
 *  addr [OUT]      structure that will receive IP address and port number.
 *  len [OUT]        length of SOCKADDR structure.
 * RETURNS
 *  refer to vm_soc_error_enum
 *****************************************************************************/
int vm_getsockname(int s,  SOCKADDR *addr, int *len);

/*****************************************************************************
 * FUNCTION
 *  getpeername
 * DESCRIPTION
 *  Retrieve IP address and port number of the endpoint node.
 * PARAMETERS
 *  sock [IN]          socket descriptor obtained with socket.
 *  addr [OUT]      addr that will receive IP address and port number.
 *  len [OUT]         length of SOCKADDR structure.
 * RETURNS
 *  refer to vm_soc_error_enum
 *****************************************************************************/
int vm_getpeername(int s,  SOCKADDR *addr, int *len);


/*****************************************************************************
 * FUNCTION
 *  htonl
 * DESCRIPTION
 *  Convert long integer (32 bits) from host byte order to network byte order  
 * PARAMETERS
 *  a      : [IN]        
 * RETURNS
 *  converted result in unsigned integer
 * EXAMPLE
 * <code>
 * loopback = htonl(0x7f000001);
 * </code>
 *****************************************************************************/
VMUINT32 vm_htonl(VMUINT32 a);


/*****************************************************************************
 * FUNCTION
 *  htons
 * DESCRIPTION
 *  Convert short integer (16 bits) from host byte order to network byte order  
 * PARAMETERS
 *  a      : [IN]        
 * RETURNS
 *  converted result in unsigned integer
 * EXAMPLE
 * <code>
 * sockaddr sock_addr;
 * ((struct SOCKADDR_IN *) sock_addr)->sin_port = htons(port);
 * </code>
 *****************************************************************************/
VMUINT16 vm_htons(VMUINT16 a);


/*****************************************************************************
 * FUNCTION
 *  inet_addr
 * DESCRIPTION
 *  This function converts a string containing a dotted address into a network address in the format of an IN_ADDR structure.
 * PARAMETERS
 *  addr      : [IN]        
 * RETURNS
 *  VMUINT
 *****************************************************************************/
VMUINT vm_inet_addr(const char* addr);

/*****************************************************************************
 * FUNCTION
 *  inet_ntoa
 * DESCRIPTION
 *  This function converts a network address into a string in dotted format.
 * PARAMETERS
 *  in      : [IN]        
 * RETURNS
 *  char *
 *****************************************************************************/
char* vm_inet_ntoa(IN_ADDR in);



/*****************************************************************************
 * FUNCTION
 *  inet_pton
 * DESCRIPTION
 *  Convert an IPV4 or IPV6 address in its standard text presentation form into 
 *  its numeric binary form in network byte order. 
 *  Format of 'x:x:x:x:x:x:d.d.d.d' is not supported.
 * PARAMETERS
 *  af      : [IN]    0 - IPV4; 1 - IPV6
 *  src       : [IN]    IP address with standard text presentation form ends with '\0'.
 *  dst       : [OUT]   IP address with numeric binary form in network byte order
 *                      For IPV4, it's a kal_uint8 array with size of at least 4.
 *                      For IPV6, it's an ipv6_addr_struct variable or compatible
 *                      kal_uint8 array with size of at least 16.
 * RETURNS
 *  no-zero: converted successfully.
 * EXAMPLE
 * // IPV4
 * <code>
 * kal_char ipv4[] = {"192.168.1.1"};
 * kal_uint8 ipv4_dst[4] = {0};
 * kal_bool ret = KAL_FALSE;
 * ret = soc_inet_pton(0, ipv4, ipv4_dst);
 * if (ret)
 * {
 *      // successfully
 * }
 * </code>
 * // IPV6
 * <code>
 * VMCHAR ipv6[] = {"FF::EE"};
 * VMUINT8 ipv6_dst[16] = {0};
 * VMINT ret;
 * ret = soc_inet_pton(1, ipv6, ipv6_dst);
 * if (ret)
 * {
 *      // successfully
 * }
 * </code>
 *****************************************************************************/
int vm_inet_pton(int af, const char *src, void *dst);


/*****************************************************************************
 *  inet_ntop
 * DESCRIPTION
 *  Convert an IPV4 or IPV6 address in its numeric binary form in network byte order 
 *  into its standard text presentation form.
 *  Format of 'x:x:x:x:x:x:d.d.d.d' is not supported.
 * PARAMETERS
 *  af      : [IN]    0 - IPV4; 1 - IPV6
 *  src       : [IN]    IP address with numeric binary form in network byte order
 *                      For IPV4, it's a kal_uint8 array with size of at least 4.
 *                      For IPV6, it's an ipv6_addr_struct variable or compatible
 *                      kal_uint8 array with size of at least 16. And src should obey 
 *                      4-byte alignment.
 *  dst       : [OUT]   IP address with standard text presentation form ends with '\0'.
 *                      The memory that dst provided should be big enough to contain the
 *                      whole IP address. Otherwise, conversion will fail.
 *                      For IPV4, safe size is 16.
 *                      For IPV6, safe size is 40.
 *  size      : [IN]    The size of memory in bytes dst provided.
 * RETURNS
 *  dst:  converted successfully.
 *  NULL: failed.
 * EXAMPLE
 * // IPV4
 * <code>
 * VMUINT8 ipv4[] = {192, 168, 0, 1};
 * VMCHAR ipv4_addr[16] = {0}, *addr = NULL;
 * addr = inet_ntop(0, ipv4, ipv4_addr, 16);
 * if (addr)
 * {
 *      // successfully
 * } 
 * </code>
 * // IPV6
 * <code>
 * VMUINT8 ipv6[] = {0xff, 0xee, 0xdd, 0xcc, 0xaa, 99, 88, 77, 66, 55, 44, 33, 22, 11, 00, 00};
 * VMCHAR ipv6_addr[16] = {0};
 * const VMCHAR *addr = NULL;
 * addr = soc_inet_ntop(1, ipv6, ipv6_addr, 40);
 * if (addr)
 * {
 *      // successfully
 * } 
 * </code> 
 *****************************************************************************/
const char *vm_inet_ntop(int af, const void *src, char *dst, VMUINT8 size);


/*****************************************************************************
 * FUNCTION
 *  vm_soc_get_account_localip
 * DESCRIPTION
 *  This function is used to get the local IP held by this socket id.
 * PARAMETERS
 *  sock               : [IN]            Socket id
 *  local_ip        : [OUT]        copy the IP address, used as return
 * RETURN VALUES
 *  VM_E_SOC_SUCCESS :		    Get IP address successfully
 *  VM_E_SOC_INVAL :			    invalid argument: null local_ip.
 *  VM_E_SOC_BEARER_FAIL :	    bearer is not activated
 *  VM_E_SOC_INVALID_SOCKET :    invalid socket
 *  VM_E_SOC_INVALID_ACCOUNT :   invalid account
 * EXAMPLE
 * <code>
 * static VMUINT8 ip[4];
 * VMINT result;
 * result = vm_soc_get_account_localip(fd, ip);
 * if (result == VM_E_SOC_SUCCESS)
 * { 
 *     //get the local IP address successfully 
 * }
 * </code>
 *****************************************************************************/
VMINT vm_soc_get_account_localip(VMINT8 sock, VMUINT8 *local_ip);


/*****************************************************************************
 * FUNCTION
 *  vm_soc_get_account_localipv6
 * DESCRIPTION
 *  This function is used to get local IPv6 address held by specific socket id.
 *  The IPv6 address obtained is in numeric binary form with network byte order.
 *  Only socket id for IPv6 is valid for this function.
 * PARAMETERS
 *  sock               : [IN]         Socket id
 *  local_ipv6        : [OUT]        copy the IP address, used as return
 * RETURN VALUES
 *  VM_E_SOC_SUCCESS :		    Get IP address successfully
 *  VM_E_SOC_INVAL :			    invalid argument: null local_ip.
 *  VM_E_SOC_BEARER_FAIL :	    bearer is not activated
 *  VM_E_SOC_INVALID_SOCKET :    invalid socket
 *  VM_E_SOC_INVALID_ACCOUNT :   invalid account
 * EXAMPLE
 * <code>
 * static VMUINT8 ip[16];
 * VMINT result;
 * result = vm_soc_get_account_localipv6(fd, ip);
 * if (result == VM_E_SOC_SUCCESS)
 * { 
 *     //get the local IP address successfully 
 * }
 * </code>
 *****************************************************************************/
VMINT vm_soc_get_account_localipv6(VMINT8 sock, VMUINT8 *local_ipv6);




typedef struct
{
	VMUSHORT		sa_family;
	VMCHAR 		    sa_data[16];
}vm_soc_addr;

/* this struct is for getaddrinfo function only */
typedef struct 
{
	VMINT32 		ai_flags;
	VMINT32 		ai_family;
	VMINT32 		ai_socktype;
	VMINT32 		ai_protocol;
	VMUINT16 		ai_addrlen;
	VMCHAR			*ai_canonname;
	VMBOOL		    ai_ipv6_first;
	vm_soc_addr		*ai_addr;
	
}vm_soc_addrinfo;

typedef enum
{
	VM_DNS_AF_INET = 0,		/* INET QUERY */
	VM_DNS_AF_INET6,			/* IPV6 QUERY */
	VM_DNS_AF_UNSPEC,			/* UNSPEC QUERY */
	VM_DNS_AF_END
}vm_soc_dns_family_enum;

typedef enum
{
	VM_DNS_NO_RESPONSE_YET = 0,
	VM_DNS_IPV4_WAIT 		= 0x01,
	VM_DNS_IPV4_COMPLETE 	= 0x02,
	VM_DNS_IPV6_WAIT		= 0x04,
	VM_DNS_IPV6_COMPLETE   = 0x08,
	VM_DNS_IPV4_FAILED		= 0x10,
	VM_DNS_IPV6_FAILED		= 0x20,
	VM_DNS_STATUS_SUCCESS,
	VM_DNS_STATUS_END
}vm_dns_getaddrinfo_status_enum;

#define VM_SOC_MAX_A_ENTRY              (5)


/* For vm_soc_getaddrinfo() */
typedef struct vm_soc_addrinfo_struct
{
    VMINT32 ai_flags; /* soc_ai_flags_enum */
    VMINT32 ai_family;
    VMINT32 ai_socktype;
    VMINT32 ai_protocol;
    VMUINT32 ai_addrlen;
    VMCHAR *ai_canonname;
    vm_sockaddr_struct *ai_addr;
    struct vm_soc_addrinfo_struct *ai_next;    
}vm_soc_addrinfo_struct;

typedef struct
{
    VMUINT8   ref_count;
    VMUINT16  msg_len;
    VMINT8    error_cause;   /* bearer fail */
    VMINT32   detail_cause;  	/* refer to vm_ps_cause_enum if error_cause
                                			* is VM_E_SOC_BEARER_FAIL */    
    VMINT32	request_id; /* request id */
    VMUINT32  account_id; /* network account id */    
    VMUINT8   access_id;  /* access id */
    VMBOOL    result;     /* the result of soc_gethostbyname */
    void *res;  /* vm_soc_addrinfo_struct */
} vm_app_soc_get_addr_info_ind_struct;


typedef void (*FP_dns_cb)(vm_app_soc_get_addr_info_ind_struct *ind);


/*****************************************************************************
 * FUNCTION
 *  vm_soc_getaddrinfo
 * DESCRIPTION
 *  This function gets the address information (both ipv6 and ipv4 address) of the given domain name.
 *  Get a host address (i.e., IP address) by its domain name. 
 *  If the bearer is not activated when this API is called, 
 *  the bearer activation would be triggered. However, 
 *  if the account id is not specified in soc_gethostbyname, 
 *  an account query would be displayed to ask the user which account 
 *  s/he wants to use.
 *  
 *  This API only supports the non-blokcing mode, i.e., 
 *  is_blocking shall be set to KAL_FALSE.
 *  Thus, soc_getaddrinfo will be returned immediately instead of 
 *  blocking and waiting for the result. 
 *  If user doesn't get the returned value directly after it calls this API,
 *  the returned value "VM_E_SOC_WOULDBLOCK" will be returned normally.
 *  SOC will send a notification to application when it gets the response 
 *  of previous DNS query later.
 *  On the contrary, if user gets the result directly, the result will be 
 *  returned directly in the parameter "addr".
 *
 *	this api can query ipv4 and ipv6 at same time and also can query ipv4 or ipv6 single. 
 *	hits->ai_family = VM_DNS_AF_UNSPEC; query ipv4 and ipv6 same time
 *	hits->ai_family = VM_DNS_AF_INET6; only query ipv6
 *	hits->ai_family = VM_DNS_AF_INET; only query ipv4
 *
 * PARAMETERS
 *  is_blocking         : [IN]        whether block or non-block mode are used,
 *                                  currently only support non-block mode
 *  mod_id              : [IN]        module id
 *  request_id          : [IN]        embedded in response message
 *  nodename         : [IN]        Domain_name
 *  servicename      : [IN]        pass NULL now
 *  hits			  : [IN]		set some query method
 *  addr                : [IN]        resolved address
 *  addr_len            : [IN/OUT]    address length     
 *  access_id           : [IN]        embedded in response message
 *  res                    : [IN]        pass NULL now
 *  nwk_account_id      : [IN]        Nwk_account_id
 * RETURN VALUES
 *  VM_E_SOC_INVAL :			         invalid arguments: null domain_name, etc.
 *  VM_E_SOC_ERROR :			         unspecified error
 *  VM_E_SOC_WOULDBLOCK :		     wait response from network
 *  VM_E_SOC_LIMIT_RESOURCE :		 socket resources not available
 * EXAMPLE
 * <code>
 * vm_soc_addrinfo info;
 * vm_soc_addrinfo *hits = &info;
 * memset(hits, 0, sizeof(vm_soc_addrinfo));
 * hits->ai_family = VM_DNS_AF_UNSPEC;   // query ipv4 and ipv6 at same time.
 * hits->ai_ipv6_first = KAL_TRUE;	   // if query both ipv4 and ipv6, app can decide which query first
 * ret = soc_getaddrinfo(
 *           KAL_FALSE,
 *           soc_id,
 *           (const kal_char*)domain_name,
 *		 hits
 *           ch->stun_ip_addr.addr,
 *           (kal_uint8*) & ch->stun_ip_addr.addr_len,
 *           0,
 *           ch->data_account_id);
 *
 *   if (ret == VM_E_SOC_WOULDBLOCK)
 *   {
 *      //processing the wouldblock state
 *      ¡K..
 *   }
 *
 * </code>
 *****************************************************************************/
VMINT vm_soc_getaddrinfo(VMBOOL is_blocking,
                                VMINT32      request_id,
                                const VMCHAR *nodename,
                                const VMCHAR *servicename,
                                const vm_soc_addrinfo_struct *hits,
                                vm_soc_addrinfo_struct    **res,
                                VMINT32      access_id,
                                VMUINT32     nwk_account_id,
                                FP_dns_cb dns_cb);



/* refer to vm_socket */
#define socket(family, type, protocol)                  vm_socket(family, type, protocol)
/* refer to vm_socket_ex */
#define socket_ex(family, type, protocol, account)      vm_socket_ex(family, type, protocol, account)
/* refer to vm_closesocket */
#define closesocket(s)                                  vm_closesocket(s)
/* refer to vm_bind */
#define bind(s, addr, len, type)                        vm_bind(s, addr, len, type)
/* refer to vm_listen */
#define listen(s, bl)                                   vm_listen(s, bl)
/* refer to vm_accept */
#define accept(s, addr, len)                            vm_accept(s, addr, len)
/* refer to vm_connect */
#define connect(s, addr, len)                           vm_connect(s, addr, len)
/* refer to vm_send */
#define send(s, buf, len, flags)                        vm_send(s, buf, len, flags)
/* refer to vm_sendto */
#define sendto(s, buf, len, flags, to, tlen)            vm_sendto(s, buf, len, flags, to, tlen)
/* refer to vm_recv */
#define recv(s, buf, len, flags)                        vm_recv(s, buf, len, flags)
/* refer to vm_recvfrom */
#define recvfrom(s, buf, len, flags, from, flen)        vm_recvfrom(s, buf, len, flags, from, flen)
/* refer to vm_select */
#define select(fds, reads, writes, except, timeout)     vm_select(fds, reads, writes, except, timeout)
/* refer to vm_shutdown */
#define shutdowns(s, how)                               vm_shutdown(s, how)
/* refer to vm_setsockopt */
#define setsockopt(s, opt, val, size)                   vm_setsockopt(s, opt, val, size)
/* refer to vm_getsockopt */
#define getsockopt(s, opt, val, size)                   vm_getsockopt(s, opt, val, size)
/* refer to vm_getsockname */
#define getsockname(s, addr, len)                       vm_getsockname(s, addr, len)
/* refer to vm_getpeername */
#define getpeername(s, addr, len)                       vm_getpeername(s, addr, len)

/* refer to vm_htonl */
#define htonl(a)                                        vm_htonl(a)
/* refer to vm_htons */
#define htons(a)                                        vm_htons(a)
/* refer to vm_htonl */
#define ntohl(a)                                        vm_htonl(a)
/* refer to vm_htons */
#define ntohs(a)                                        vm_htons(a)

/* refer to vm_inet_addr */
#define inet_addr(a)                                    vm_inet_addr(a)
/* refer to vm_inet_ntoa */
#define inet_ntoa(in)                                   vm_inet_ntoa(in)
/* refer to vm_inet_pton */
#define inet_pton(af, src, dst)                         vm_inet_pton(af, src, dst)
/* refer to vm_inet_ntop */
#define inet_ntop(af, src, dst, size)                   vm_inet_ntop(af, src, dst, size)

#ifdef __cplusplus
}
#endif

#endif /* VM_SOCK_SDK_H */
