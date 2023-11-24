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

#ifndef VMGPS_SDK_H_
#define VMGPS_SDK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

#define VM_GPS_NMEA_MAX_SVVIEW             20
#define VM_GPS_GSA_SATE_MAX			12

/*UTC time structure*/
typedef struct{
	VMINT8 hour; /* hour */
	VMINT8 minute; /* minute */
	VMINT8 second; /* second */
	VMINT8 millisecond; /* millisecond */
} vm_gps_nmea_utc_time_struct;

/*UTC date structure*/
typedef struct{
	VMINT8 year;  /* year */
	VMINT8 month; /* month */
	VMINT8 day;   /* day */
} vm_gps_nmea_utc_date_struct;

/*GPGGA -- Global Positioning System Fix Data*/
typedef struct{
	double gga_latitude;                                      /*Latitude South<0  North>0*/
    	double gga_longitude;                                   /*Longitude West<0 east>0*/
    	float gga_h_precision;                                   /*Horizontal Dilution of precision*/
    	double gga_altitude;                                      /*Antenna Altitude above/below mean-sea-level (geoid)*/
    	float gga_unit_of_altitude;                            /*Units of antenna altitude, meters*/
    	float gga_geoidal ;                                         /*Geoidal separation, the difference between the WGS-84 earth*/
    	float gga_unit_of_geoidal;                            /*Units of geoidal separation, meters*/
    	float gga_gps_age;                                        /*Age of differential GPS data, time in seconds since last SC104*/
    	VMUINT16 gga_station_id;                             /*Differential reference station ID, 0000-1023*/
    	VMUINT8 gga_sat_in_view;                            /*Number of satellites in view*/
    	vm_gps_nmea_utc_time_struct gga_utc_time;       /*Time (UTC)*/
    	VMINT8 gga_north_south;			              /*north or south*/
    	VMINT8 gga_east_west;			              /*east or west*/
    	VMINT8 gga_quality;                                      /*GPS Quality Indicator*/
}vm_gps_gga_data_struct;

/*GPRMC -- Recommended Minimum Specific GNSS Data*/
typedef struct{
	double rmc_latitude;                                      /* latitude */   
    	double rmc_longitude;                                  /* longitude */   
    	float rmc_ground_speed;                               /*Speed over ground, knots*/
    	float rmc_trace_degree;                               /*Track mode degrees,north is 0*/
    	float rmc_magnetic;                                   /* trace defree */     
    	vm_gps_nmea_utc_time_struct rmc_utc_time;           /*Time (UTC)*/
    	vm_gps_nmea_utc_date_struct rmc_utc_date;           /*Date (UTC)*/
    	VMINT8 rmc_status;                                   /* status */     
    	VMINT8 rmc_north_south;                              /* north or south */
    	VMINT8 rmc_east_west;                                /* east or west */ 
    	VMINT8 rmc_magnetic_e_w;                          /* magnetic east or west */
    	VMINT8 rmc_cmode;					               /* mandatory checksum */
}vm_gps_rmc_data_struct;

/*GPGLL -- Geographic Position - Latitude/Longitude*/
typedef struct{
	double gll_latitude;                                  /* latitude */     
    	double gll_longitude;                              /* longitude */      
    	vm_gps_nmea_utc_time_struct gll_utc_time;        /* utc time */
    	VMINT8 gll_north_south;                           /* north or south */   
    	VMINT8 gll_east_west;                              /* east or west */  
    	VMINT8 gll_status;                                 /*Status A - Data Valid, V - Data Invalid*/
    	VMINT8 gll_mode;                                 /* mode */
}vm_gps_gll_data_struct;

/*GPGSV -- GNSS Satellites in View*/
typedef struct{
	VMINT16 gsv_msg_sum;         	                     /* Number of sentences for full data */
    	VMINT16 gsv_msg_index;      	                 /* message index */ 
    	VMINT16 gsv_sates_in_view;	                     /* Number of satellites in view */
    	VMINT16 gsv_max_snr;		                     /* max snr */
    	VMINT16 gsv_min_snr;		                     /* min snr */
    	VMINT16 gsv_num_sv_trk;	                         /* number of satellite */
    	struct
    	{
       	VMUINT8 sate_id;			                     /* Satellite PRN number */
        	VMUINT8 elevation;		                     /* Elevation, degrees */
        	VMINT16 azimuth;		                     /* Azimuth, degrees */
        	VMUINT8 snr;				                 /* Signal strength - higher is better */
    	}gsv_rsv[VM_GPS_NMEA_MAX_SVVIEW];                /* There my be up to three GSV sentences in a data packet*/
}vm_gps_gsv_data_struct;

/*GPGSA -- GNSS DOP and Active Satellites*/
typedef struct{
	float gsa_pdop;                                      /* PDOP (dilution of precision) */
    	float gsa_hdop;                                  /* Horizontal dilution of precision (HDOP) */
    	float gsa_vdop;                                  /* Vertical dilution of precision (VDOP) */
    	VMUINT16 gsa_sate_id[VM_GPS_GSA_SATE_MAX];       /* PRNs of satellites used for fix (space for 12) */
    	VMINT8 gsa_op_mode;                              /* selection of 2D or 3D fix, 0-Auto, 1-Manual */
    	VMINT8 gsa_fix_mode;                             /* 3D fix */
}vm_gps_gsa_data_struct;

/*GPVTG -- VTG Data*/
typedef struct{
	float vtg_hspeed_knot;  /* Ground speed, knots */
	float vtg_hspeed_km;    /*Ground speed, Kilometers per hour */
	float vtg_true_heading; /*True track made good */
	float vtg_mag_heading; /*Magnetic track made good */
	VMINT8 vtg_mode;   	    /* VTG mode */
}vm_gps_vtg_data_struct;

/*NMEA data structure*/
typedef struct{
	vm_gps_rmc_data_struct rmc_data; /* RMC data */
	vm_gps_vtg_data_struct vtg_data; /* VTG data */
	vm_gps_gll_data_struct gll_data; /* GLL data */
	vm_gps_gga_data_struct gga_data; /* GGA data */
	vm_gps_gsa_data_struct gsa_data; /* GSA data */
	vm_gps_gsv_data_struct gsv_data; /* GSV data */
}vm_gps_info_struct;

/*GPS open status*/
typedef enum{
	VM_GPS_OPEN_RES_LESS = -3	,				/*lack of resource*/
	VM_GPS_OPEN_PORT_HANDLE_WRONG = -2,	/*Open UART handle error*/
	VM_GPS_OPEN_PORT_NUMBER_WRONG = -1,	/*Open UART port number error*/
	VM_GPS_OPEN_SUCCESS = 0,					/*Open successfully*/
	VM_GPS_OPEN_ALREADY_OPEN = 1			/*Already open*/
} vm_gps_open_state_enum;

/*GPS close status*/
typedef enum{
	VM_GPS_CLOSE_FAILED = -1,					/*Close failed*/
	VM_GPS_CLOSE_SUCCESS = 0,					/*Close successfully*/
	VM_GPS_CLOSE_STILL_APP_USE_DATA = 1		/*GPS information still used by other application*/
} vm_gps_close_state_enum;


/*****************************************************************************
* FUNCTION
 *    vm_gps_open
 * DESCRIPTION
 *  Open GPS. This funtion will also open UART port. 
 * RETURNS
 *  result of open operation.
 * RETURN VALUES  
 *  VM_GPS_OPEN_SUCCESS : Open successfully.
 *  VM_GPS_OPEN_ALREADY_OPEN : Already open.
 *  VM_GPS_OPEN_PORT_NUMBER_WRONG : Open UART port number error
 *  VM_GPS_OPEN_PORT_HANDLE_WRONG : Open UART handle error
 *
*****************************************************************************/
VMINT vm_gps_open(void);

/*****************************************************************************
* FUNCTION
 *    vm_gps_close
 * DESCRIPTION
 *  Close GPS. This funtion will close GPS if there is no other application use GPS. 
 * RETURNS
 *  result of close operation.
 * RETURN VALUES   
 *  VM_GPS_CLOSE_SUCCESS : Close successfully.
 *  VM_GPS_CLOSE_STILL_APP_USE_DATA : GPS information still used by other application
 *  VM_GPS_CLOSE_FAILED : Close failed.
 *
*****************************************************************************/
VMINT vm_gps_close(void);


/*****************************************************************************
* FUNCTION
 *    vm_gps_get_gga_data
 * DESCRIPTION
 *  Get GGA information of GPS. This funtion will return NULL if vm_gps_open() is not invoked before. 
 * RETURNS
 *  Pointer of GGA information or NULL.
 *
*****************************************************************************/
 vm_gps_gga_data_struct*  vm_gps_get_gga_data( void );

/*****************************************************************************
* FUNCTION
 *    vm_gps_get_rmc_data
 * DESCRIPTION
 *  Get RMC information of GPS. This funtion will return NULL if vm_gps_open() is not invoked before. 
 * RETURNS
 *  Pointer of RMC information or NULL.
 *
*****************************************************************************/
 vm_gps_rmc_data_struct* vm_gps_get_rmc_data( void );

/*****************************************************************************
* FUNCTION
 *    vm_gps_get_gll_data
 * DESCRIPTION
 *  Get GLL information of GPS. This funtion will return NULL if vm_gps_open() is not invoked before. 
 * RETURNS
 *  Pointer of GLL information or NULL.
 *
*****************************************************************************/
 vm_gps_gll_data_struct* vm_gps_get_gll_data( void );

/*****************************************************************************
* FUNCTION
 *    vm_gps_get_gsv_data
 * DESCRIPTION
 *  Get GSV information of GPS. This funtion will return NULL if vm_gps_open() is not invoked before. 
 * RETURNS
 *  Pointer of GSV information or NULL.
 *
*****************************************************************************/
 vm_gps_gsv_data_struct* vm_gps_get_gsv_data( void );

/*****************************************************************************
* FUNCTION
 *    vm_gps_get_gsa_data
 * DESCRIPTION
 *  Get GSA information of GPS. This funtion will return NULL if vm_gps_open() is not invoked before. 
 * RETURNS
 *  Pointer of GSA information or NULL.
 *
*****************************************************************************/
vm_gps_gsa_data_struct* vm_gps_get_gsa_data(  void );

/*****************************************************************************
* FUNCTION
 *    vm_gps_get_vtg_data
 * DESCRIPTION
 *  Get VTG information of GPS. This funtion will return NULL if vm_gps_open() is not invoked before. 
 * RETURNS
 *  Pointer of VTG information or NULL.
 *
*****************************************************************************/
vm_gps_vtg_data_struct* vm_gps_get_vtg_data( void );

#ifdef __cplusplus
}
#endif 

#endif /* VMGPS_SDK_H_ */

