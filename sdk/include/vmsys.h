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

#ifndef VMSYS_SDK_H_
#define VMSYS_SDK_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif


/* start MRE environment normally */
#define VM_NORMAL_START_MRE_ENV 1


typedef unsigned char VMUINT8;
typedef unsigned short VMUINT16;
typedef unsigned int VMUINT;
typedef unsigned long VMUINT32;


typedef  unsigned long long VMUINT64 ;
typedef  long long VMINT64 ;


typedef char VMINT8;
typedef short VMINT16;
typedef int  VMINT;
typedef long  VMINT32;

typedef VMUINT8 VMUCHAR;
typedef VMUINT16 VMUWCHAR;
typedef VMUINT8 * VMUSTR;
typedef VMUINT16 * VMUWSTR;

typedef VMINT8 VMCHAR;
typedef VMINT16 VMWCHAR;
typedef VMINT8 * VMSTR;
typedef VMINT16 * VMWSTR;

typedef unsigned char VMBYTE;
typedef unsigned short VMUSHORT;
typedef short VMSHORT;

typedef VMINT VMFILE;
typedef VMINT VMBOOL;
#define VM_PROF_NORMAL_MODE     0   /* normal mode */
#define VM_PROF_MEETING_MODE    1   /* Meeting mode */
#define VM_PROF_SILENT_MODE     2   /* Silnet mode */
#define VM_PROF_HEADSET_MODE    3   /* Headset mode */
#define VM_PROF_BLUETOOTH_MODE  4   /* Bluetooth profile */

typedef struct vm_time_t {
	VMINT year;		
	VMINT mon;		/* month, begin from 1	*/
	VMINT day;		/* day,begin from  1 */
	VMINT hour;		/* house, 24-hour	*/
	VMINT min;		/* minute	*/
	VMINT sec;		/* second	*/
} vm_time_t;

typedef enum
{
   VM_TOUCH_FEEDBACK_DOWN,
    VM_TOUCH_FEEDBACK_DOWN_VIBRATE,
    VM_TOUCH_FEEDBACK_DOWN_TONE,
    VM_TOUCH_FEEDBACK_HOLD,
    VM_TOUCH_FEEDBACK_SPECIAL,
    VM_TOUCH_FEEDBACK_TOTAL
} vm_touch_feedback_enum;


typedef enum
{
	VM_MAINLCD_BRIGHTNESS_LEVEL0   =0  ,  /* TURN OFF*/
    VM_MAINLCD_BRIGHTNESS_LEVEL1  ,
    VM_MAINLCD_BRIGHTNESS_LEVEL2  ,
    VM_MAINLCD_BRIGHTNESS_LEVEL3  ,
    VM_MAINLCD_BRIGHTNESS_LEVEL4  ,
    VM_MAINLCD_BRIGHTNESS_LEVEL5  ,
	VM_MAINLCD_BRIGHTNESS_LEVEL6	,
    VM_MAINLCD_BRIGHTNESS_LEVEL7  ,
    VM_MAINLCD_BRIGHTNESS_LEVEL8  ,
    VM_MAINLCD_BRIGHTNESS_LEVEL9	,
    VM_MAINLCD_BRIGHTNESS_LEVEL10	,
    VM_MAINLCD_BRIGHTNESS_LEVEL11 ,
    VM_MAINLCD_BRIGHTNESS_LEVEL12 ,
    VM_MAINLCD_BRIGHTNESS_LEVEL13 ,
    VM_MAINLCD_BRIGHTNESS_LEVEL14 ,
    VM_MAINLCD_BRIGHTNESS_LEVEL15 ,
    VM_MAINLCD_BRIGHTNESS_LEVEL16 ,
    VM_MAINLCD_BRIGHTNESS_LEVEL17 ,
    VM_MAINLCD_BRIGHTNESS_LEVEL18 ,
    VM_MAINLCD_BRIGHTNESS_LEVEL19 ,
    VM_MAINLCD_BRIGHTNESS_LEVEL20 ,
    VM_MAINLCD_BRIGHTNESS_20LEVEL_MAX /* DO NOT USE THIS */
} vm_mainlcd_brightness_level_enum;


/*****************************************************************************
 * FUNCTION
 *  vm_get_time
 * DESCRIPTION
 *  get current system time 
 * PARAMETERS
 *  time : [OUT] time structure
 * RETURNS
 *  if succeed, return 0, otherwise return -1
 *****************************************************************************/ 
VMINT vm_get_time(vm_time_t* time);

/*****************************************************************************
 * FUNCTION
 *  vm_get_curr_utc
 * DESCRIPTION
 * Get the time since the Epoch (00:00:00 UTC, January 1, 1970),
 * measured in seconds.not utc, but rtc
 * PARAMETERS
 *  utc : [OUT] point to the time in seconds.
 * RETURNS
 *  if succeed, return 0, otherwise failure.
 *****************************************************************************/
VMINT vm_get_curr_utc(VMUINT * utc);

/*****************************************************************************
 * FUNCTION
 *  vm_get_utc
 * DESCRIPTION
 * Get the time since the Epoch (00:00:00 UTC, January 1, 1970),
 * measured in seconds.
 * PARAMETERS
 *  utc : [OUT] point to the time in seconds.
 * RETURNS
 *  if succeed, return 0, otherwise failure.
 *****************************************************************************/
VMINT vm_get_utc(VMUINT * utc);

/*the statistic of memory using status */
typedef struct malloc_stat_t {
	/* the number if the malloc memory API is called, including vm_malloc(),vm_realloc(), * vm_calloc()   */
	VMINT malloc_count;

	/*the number of free memory API is called	 */
	VMINT free_count;

	/*current used memory */
	VMINT current;

	/*peak memory*/
	VMINT peak;

	/*the number of memory malloc fail*/
	VMINT fail_times;

	/* the max size that malloc memory failed */
	VMINT max_fail_size;

	/* current avail heap size  */
	VMINT avail_heap_size;
} malloc_stat_t;

typedef void (*AppASMStopCBPtr) (void );
typedef void (*AppASMSuccessCBPtr) (void);


typedef enum vm_mutex_state
{
    VM_MUTEX_STATE_TAKEN = 0,
    VM_MUTEX_STATE_GIVEN,
} vm_mutex_state;

typedef struct vm_mutex_struct
{
    volatile int state;
} vm_mutex_struct;


/* MRE application memory structure */
typedef struct
{
    VMUINT8* mem_base;
    VMINT   mem_size;
    AppASMStopCBPtr stop_cb;
    VMINT p_handle;
	VMINT index;
    void* adm_id;
    VMUWSTR name_buf[3]; /* support English, SC, and TC, and maxium size of tag is 256 */
	VMUWCHAR p_name[260];
	VMINT multiname;
#ifdef MRE_ENABLE_MEM_DEBUG
    malloc_stat_t mem_stat;
#endif
    VMINT heap_size;
    VMINT user_mem; // the memory is passed to MRE from preload app APP
    vm_mutex_struct mutex;
}vm_app_mem_struct;


typedef VMUINT32      VMCOLOR32;

typedef float         VMFLOAT;

typedef VMINT32       VMMSEC;

typedef VMINT32       VMRESID;

typedef VMINT32       VMID;

#define VM_TRUE       TRUE
#define VM_FALSE      FALSE

#ifdef WIN32
#define VM_ASSERT(__expr__) \
do {                        \
    if (!(__expr__))        \
    {                       \
        _asm {int 3}        \
    }                       \
} while (0)
#else
#define VM_ASSERT(expr)
#endif

#define VM_PI         3.1415926f

/* General color type methods */
#define VM_COLOR32_MAKE(a, r, g, b)      ((VMCOLOR32)((VMUINT32)(a) << 24 | (VMUINT32)(r) << 16 | (VMUINT32)(g) << 8 | (VMUINT32)(b)))
#define VM_COLOR32_GET_A(c)              ((c) >> 24)
#define VM_COLOR32_GET_R(c)              ((c) << 8 >> 24)
#define VM_COLOR32_GET_G(c)              ((c) << 16 >> 24)
#define VM_COLOR32_GET_B(c)              ((c) << 24 >> 24)

/* default colors */
#define VM_COLOR32_BLACK                 VM_COLOR32_MAKE(255, 0, 0, 0)
#define VM_COLOR32_WHITE                 VM_COLOR32_MAKE(255, 255, 255, 255)
#define VM_COLOR32_RED                   VM_COLOR32_MAKE(255, 255, 0, 0)
#define VM_COLOR32_GREEN                 VM_COLOR32_MAKE(255, 0, 255, 0)
#define VM_COLOR32_BLUE                  VM_COLOR32_MAKE(255, 0, 0, 255)
#define VM_COLOR32_AQUA                  VM_COLOR32_MAKE(255, 0, 255, 255)
#define VM_COLOR32_FUCHSIA               VM_COLOR32_MAKE(255, 255, 0, 255)
#define VM_COLOR32_YELLOW                VM_COLOR32_MAKE(255, 255, 255, 0)
#define VM_COLOR32_GREY                  VM_COLOR32_MAKE(255, 128, 128, 128)
#define VM_COLOR32_TEAL                  VM_COLOR32_MAKE(255, 0, 128, 128)
#define VM_COLOR32_PURPLE                VM_COLOR32_MAKE(255, 128, 0, 128)
#define VM_COLOR32_OLIVE                 VM_COLOR32_MAKE(255, 128, 128, 0)
#define VM_COLOR32_SILVER                VM_COLOR32_MAKE(255, 192, 192, 192)
#define VM_COLOR32_TRANSPARENT           VM_COLOR32_MAKE(0, 0, 0, 255)

/* Redian convert macros */
#define VM_DEG_TO_RAD(x)               ((VMFLOAT)((VMFLOAT)(x)) * VM_PI / 180.0f)
#define VM_RAD_TO_DEG(x)               ((VMFLOAT)((VMFLOAT)(x)) * 180.0f / VM_PI)

/* Float, Fixed conversion */
#define VM_X_TO_F(x)                   ((VMFLOAT)x / 65536.0f)
#define VM_F_TO_X(x)                   (VMINT32)((x) * 65536.0f)


/* MRE module structure */
typedef struct
{
    VMUINT   mod_core_base       : 1;
    VMUINT   mod_core_sandbox    : 1;
    VMUINT   mod_core_resmgr     : 1;
    VMUINT   mod_core_safety     : 1;
    VMUINT   mod_core_commu      : 1;
    VMUINT   mod_core_sm         : 1;
    VMUINT   mod_core_so         : 1;
    VMUINT   mod_lib_appres      : 1;
    VMUINT   mod_lib_c           : 1;
    VMUINT   mod_lib_chset       : 1;
    VMUINT   mod_lib_defgame     : 1;
    VMUINT   mod_lib_ddraw       : 1;
    VMUINT   mod_lib_gfxold      : 1;
    VMUINT   mod_lib_image       : 1;
    VMUINT   mod_lib_http        : 1;
    VMUINT   mod_lib_ime         : 1;
    VMUINT   mod_lib_ini         : 1;
    VMUINT   mod_lib_log         : 1;
    VMUINT   mod_lib_mullang     : 1;
    VMUINT   mod_lib_network     : 1;
    VMUINT   mod_lib_vip         : 1;
    VMUINT   mod_lib_vip_vg      : 1;
    VMUINT   mod_lib_xml         : 1;
    VMUINT   mod_sal_audio       : 1;
    VMUINT   mod_sal_bitstream   : 1;
    VMUINT   mod_sal_camera      : 1;
    VMUINT   mod_sal_cell        : 1;
    VMUINT   mod_sal_che_des     : 1;
    VMUINT   mod_sal_che_md5     : 1;
    VMUINT   mod_sal_che_sha1    : 1;
    VMUINT   mod_sal_gps         : 1;
    VMUINT   mod_sal_mms         : 1;
    VMUINT   mod_sal_phonebook   : 1;
    VMUINT   mod_sal_sensor      : 1;
    VMUINT   mod_sal_sim         : 1;
    VMUINT   mod_sal_sms         : 1;
    VMUINT   mod_sal_socket      : 1;
    VMUINT   mod_sal_status      : 1;
    VMUINT   mod_sal_tele        : 1;
    VMUINT   mod_sal_timer       : 1;
    VMUINT   mod_sal_video       : 1;
    VMUINT   mod_sal_wallpaper   : 1;
    VMUINT   mod_sal_wps         : 1;
    VMUINT   mod_app_launch      : 1;
    VMUINT   mod_sal_payment     : 1;
}vm_module_struct;

typedef enum
{
    VM_SCREEN_ROTATE_0,   /* Normal screen */
    VM_SCREEN_ROTATE_90,  /* Rotate 90 clockwise */
    VM_SCREEN_ROTATE_180, /* Rotate 180 */
    VM_SCREEN_ROTATE_270, /* Rotate 270 clockwise */

	/*Add new enums above this*/
	VM_SCREEN_ROTATE_END = 0XFFFF
} vm_screen_rotate_enum;

/*****************************************************************************
 * FUNCTION
 *  vm_get_malloc_stat
 * DESCRIPTION
 *  get current memory management data after the memory management is available 
 * PARAMETERS
 *  void
 * RETURNS
 *  the memory status structure pointer
 *****************************************************************************/ 
malloc_stat_t* vm_get_malloc_stat(void);

/*****************************************************************************
* FUNCTION
 *    vm_malloc
 * DESCRIPTION
 *  allocate specified size of memory 
 * PARAMETERS
 *  size : [IN]  size of byte to be allocated.
 * RETURNS
 *  memory pointer allocated, NULL means allocation failed.
*****************************************************************************/
void *vm_malloc(int size);

/*****************************************************************************
* FUNCTION
 *    vm_calloc
 * DESCRIPTION
 *  allocate specified size of memory and clean as zero.
 * PARAMETERS
 *  size : [IN]  size of byte to be allocated.
 * RETURNS
 *  memory pointer allocated, NULL means allocation failed.
*****************************************************************************/
void *vm_calloc(int size);

/*****************************************************************************
* FUNCTION
 *    vm_realloc
 * DESCRIPTION
 *  reallocate specified size of memory for the memory already allocated before.
 * PARAMETERS
 *  p : [IN] memory pointer to be realloced.
 *  size : [IN]  size of byte to be allocated.
 * RETURNS
 *  memory pointer allocated; NULL means allocation failed, but the original pointer will not free.
*****************************************************************************/
void *vm_realloc(void* p, int size);

/*****************************************************************************
* FUNCTION
 *    vm_free
 * DESCRIPTION
 *  free memory allocated by vm_malloc(), vm_calloc(), or vm_realloc().
 * PARAMETERS
 *  ptr : [IN]  memory pointer to be free.
*****************************************************************************/
void vm_free(void* ptr);

/*****************************************************************************
* FUNCTION
 *    vm_global_malloc
 * DESCRIPTION
 *  allocate extra memory excluding the size announced when packing, size must larger than 10KB. 
 * PARAMETERS
 *  size : [IN]  size of byte to be allocated.
 * RETURNS
 *  memory pointer allocated, NULL means allocation failed.
*****************************************************************************/
void *vm_global_malloc(unsigned int size);


/*****************************************************************************
* FUNCTION
 *    vm_free
 * DESCRIPTION
 *  free memory allocated by vm_global_malloc();
 * PARAMETERS
 *  ptr : [IN]  memory pointer to be free.
*****************************************************************************/
void vm_global_free(void* ptr);


/*****************************************************************************
* FUNCTION
 *    vm_global_get_max_alloc_size
 * DESCRIPTION
 *  Get the max possible size of single allocation from app-based ASM. 
 *
 *  Remark: we can use this function to dynamically decide the allocation size 
 *  (for example, use larger image cache when there is more memory)
 *  
 *  However, sometimes we cannot allocate 2 * 10KB blocks if the maximum allocation size 
 *  is 20KB because of the overheads of memory management bookkeeping. 
 *
 *  It is suggested to use "fail-safe" allocation regardless the internal 
 *  implementation of ASM if we want to allocate more memory adaptively according
 *  to the free space
 *  Step 1. Decide the size of free space => e.g. 100KB
 *  Step 2. Allocate 100KB
 *  Step 3. If failed, allocate 95 KB
 *  Step 4. If failed, allocate 90 KB
 *  Step 5. ...
 * PARAMETERS
 *  void
 * RETURNS
 *  memory size
*****************************************************************************/
VMINT vm_global_get_max_alloc_size(void);


/*****************************************************************************
* FUNCTION
*    vm_main
* DESCRIPTION
*  This is entry function of application and application must implement it.
*****************************************************************************/
void vm_main(void);

/**
 * the message of asking for application to repaint screen.
 */
#define VM_MSG_PAINT			1

/**
 * the message of application state from inactive to active.
 */
#define VM_MSG_ACTIVE			2

/**
 * the message of application state from active to inactive.
 */
#define VM_MSG_INACTIVE		3

/**
 * the message of creation of application
 */
#define VM_MSG_CREATE			4

/**
 * the message of quit of application
 */
#define VM_MSG_QUIT			5

/**
 * the message of application state from foreground running to background running.
 */
#define VM_MSG_HIDE			6

/**
 * the message to notify application memory card has been plug out.
 */
#define VM_MSG_CARD_PLUG_OUT		7

/**
 * the message when screen rotate.
 */
#define VM_MSG_SCREEN_ROTATE 8

/**
 * the message of application when foreground running and receive PUSH Message.
 */
#define VM_MSG_PUSH			9

#define VM_MSG_RESTART_PARENT  100


/*****************************************************************************
* FUNCTION
 *    vm_reg_sysevt_callback
 * DESCRIPTION
 *  register system message callback function.
 * PARAMETERS
 *  f : [IN] callback function.
*****************************************************************************/
void vm_reg_sysevt_callback(void (*f)(VMINT message, VMINT param));

/* DOM-NOT_FOR_SDK-BEGIN */

#define VM_MSG_CONFIRM_EXIT     1001
/**
 *  The reason of HIDE or PAINT Event
 */
enum {
	SCREEN_POPUP = 0, 	/* HIDE or PAINT cause of POPUP£¬like incoming call, sms, input method, etc. */
	USER_END_KEY		/* HIDE cause of END key */
};

/**
 * System event structure
 */
typedef struct _vm_sysevt_param_t
{
	VMINT evt_cause; 	/* Reason of the event */
	void * evt_detail; 	/* reserved */
} vm_sysevt_param_t;

/*****************************************************************************
* FUNCTION
 *    vm_malloc
 * DESCRIPTION
 *  allocate non-cacheable  memory 
 * PARAMETERS
 *  size : [IN]  size of byte to be allocated.
 * RETURNS
 *  memory pointer allocated, NULL means allocation failed.
*****************************************************************************/
void *vm_malloc_nc(int size);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
* FUNCTION
*    vm_exit_app
* DESCRIPTION
*  MRE application call this function to quit. 
*****************************************************************************/
void vm_exit_app(void);

/* DOM-NOT_FOR_SDK-BEGIN */
// do not support this function
/*****************************************************************************
* FUNCTION
*    vm_exit_and_update_app
* DESCRIPTION
*  MRE application call this function to quit and update application itself.
*****************************************************************************/
void vm_exit_and_update_app(void);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  vm_get_tick_count
 * DESCRIPTION
 *  get millisecond number from the system power on till now
 * PARAMETERS
 *  void
 * RETURNS
 *  millisecond number from the system power on till now
 *****************************************************************************/ 
VMINT vm_get_tick_count(void);

/*****************************************************************************
* FUNCTION
 *    vm_get_exec_filename
 * DESCRIPTION
 *  get current application file name
 * PARAMETERS
 *  filename: [OUT] output file name string encoding with UCS2 format.
 * RETURNS
 *  if 0, file name will output to the parameter filename, else means there is no application running.
*****************************************************************************/
VMINT vm_get_exec_filename(VMWSTR filename);


/*mre user ID, corresponding to the value : a string with max length 20(unit:VMCHAR)    e.g. 100973*/
#define MRE_SYS_SUBSCRIBER_ID		(1) 

/*mre system user agent, corresponding to the value : a string with max length 20(unit:VMCHAR)    e.g. Gionee-A10*/
#define MRE_SYS_EQUIPMENT_ID		(2)

/*mre version,corresponding to the value : a string with max length 12(unit:VMCHAR) 
 *naming rule :"main version number.sub-version number.release number",e.g. 1.2.6 */
#define MRE_SYS_VERSION				(3)

/*platform version,corresponding to the value :a string with max length 30(unit:VMCHAR). e.g. MT6225_08A_VERSION*/
#define MRE_SYS_HOST_VERSION		(4)

/*Max memory that MRE can get,corresponding to the value :a string with max length 6(unit:VMCHAR), it can be change to
*number by atoi function(unit:KB), the memory is the sum of MRE system memory and app memory. e.g. 800*/
#define MRE_SYS_HOST_MAX_MEM		(5)

/*MRE system home path,corresponding to the value :a string with max length 30(unit:VMCHAR),e.g. C:\MRE*/
#define MRE_SYS_HOME_DIR			(6)

/*platform build date and time :a string with max length 30(unit:VMCHAR). e.g. 2012/02/09 11:47*/
#define MRE_SYS_BUILD_DATE_TIME		(7)

/*platform release branch and info. e.g. 11B NEUTRON52_12864*/
#define MRE_SYS_RELEASE_BRANCH		(8)



/*****************************************************************************
 * FUNCTION
 *  vm_get_sys_property
 * DESCRIPTION
 *  get MRE system property. Property is defined as group of key and value. The property is maintained by MRE internal and APP can not 
 *  modify it or delete it.
 * PARAMETERS
 *  key : [IN] the key to get the system property
 *  value : [OUT] point to continuous memory,store the gotten system property. if value ==NULL, it shows that no data writing operation.
 *  len : [IN] the max length that value storing data. unit: VMCHAR
 *              e.g. if len =12 and actual written length is 10,  value[10] = 0x00
 *                      if len =12 and actual written length is 12,  value string will not include 0x00
 *                      if len =12 and actual need to be written length is 15, only the first 12 character will be written to value region
 * RETURNS
 *  the actual written length, not including 0x00
 * EXAMPLE
 *	VMCHAR value[20] = {0};
 *    VMUINT valueNum = vm_get_sys_property(MRE_SYS_SUBSCRIBER_ID, value, 20);
 *****************************************************************************/ 
VMUINT vm_get_sys_property(const VMINT key, VMCHAR* value, VMUINT len);



/*****************************************************************************
 * FUNCTION
 *  vm_get_sys_time_zone
 * DESCRIPTION
 *  get system time zone 
 * PARAMETERS
 *  void
 * RETURNS
 *  GMT value
 *****************************************************************************/ 
float vm_get_sys_time_zone(void);



/*****************************************************************************
 * FUNCTION
 *  vm_get_sys_scene
 * DESCRIPTION
 *  get system setting profile
 * PARAMETERS
 *  void
 * RETURNS
 *  0 : standard mode
 *  1: meeting mode
 *  2: outside mode
 *  3: indoor mode
 *  4: earphone mode
 *  5: silent mode
 *  6: bluetooth mode
 *****************************************************************************/ 
VMINT vm_get_sys_scene(void);



/*****************************************************************************
 * FUNCTION
 *  vm_get_battery_level
 * DESCRIPTION
 *  get handset battery level 
 * PARAMETERS
 *  void
 * RETURNS
 *  battery level  .depend on the target config, return value maybe one of 0,25,50,75,100
 * or one of 0,33,66,100
 *****************************************************************************/ 
VMINT vm_get_battery_level(void) ;


/*****************************************************************************
 * FUNCTION
 *  vm_set_mainlcd_brightness
 * DESCRIPTION
 *  set handset main LCD brightness 
 * PARAMETERS
 *  vm_mainlcd_brightness_level_enum 
 * RETURNS
 * NO 
 *****************************************************************************/ 
void vm_set_mainlcd_brightness(vm_mainlcd_brightness_level_enum brighness_level);

/*****************************************************************************
 * FUNCTION
 *  vm_get_mainlcd_brightness
 * DESCRIPTION
 *  get handset main LCD brightness 
 * PARAMETERS
 *  NULL 
 * RETURNS
 * an unsigned int value
 *****************************************************************************/ 
VMINT vm_get_mainlcd_brightness(void);


typedef enum {
	turn_on_mode = 0, 				/*turn on saving mode */
	turn_off_mode					/*turn off saving mode*/
} power_saving_mode_enum;


/* builtin sm struct */
typedef struct _vm_sm_builtin_struct
{
    VMINT8 file_name[32]; /* sm file name */
    VMUINT address;        /* sm memory address */
} vm_sm_builtin_struct;


/*****************************************************************************
 * FUNCTION
 *  vm_switch_power_saving_mode
 * DESCRIPTION
 *  settign saving mode.
 *	MRE default value is turn_on_mode, when app is set to background running or 
 *	exit, or receives INACTIVE message, the mode also should be set as turn_on_mode.
 *  turn_on_mode: LCD will off when no action occurs in a period time.
 *  turn_off_mode: LCD will keep on,only when app is on fore-ground running, can 
 *					it set the mode. 
 * PARAMETERS
 *  mode : whether open the saving mode
 * RETURNS
 *  if succeed ,return 0, otherwise,return error code
 *****************************************************************************/ 
VMINT vm_switch_power_saving_mode(power_saving_mode_enum mode);

void vm_set_touch_feedback ( vm_touch_feedback_enum type);


/*****************************************************************************
 * FUNCTION
 *  vm_get_mre_modules
 * DESCRIPTION
 *  get mre modules information 
 * PARAMETERS
 *  modules : module structure
 *  size : module structure's size
 * RETURNS
 *  if succeed ,return 0, otherwise,return error code
 *****************************************************************************/
VMINT vm_get_mre_modules(vm_module_struct *modules, VMUINT size);

/*****************************************************************************
 * FUNCTION
 *  vm_get_mre_version
 * DESCRIPTION
 *  get mre version  
 * PARAMETERS
 *  
 * RETURNS
 *  version
 *****************************************************************************/
VMUINT vm_get_mre_version(void);

/*****************************************************************************
 * FUNCTION
 *  vm_get_mre_total_mem_size
 * DESCRIPTION
 *  get mre total memory size  
 * PARAMETERS
 *  
 * RETURNS
 *  memory size
 *****************************************************************************/
VMUINT vm_get_mre_total_mem_size(void);



#define VM_UPDATE_OK_ALREADY_DOWNLOADED         1
#define VM_UPDATE_OK                            0
#define VM_UPDATE_ERROR                         -2
#define VM_UPDATE_ERROR_GET_VERSION_FAIL        -3
#define VM_UPDATE_ERROR_GET_APP_ID_FAIL         -4
#define VM_UPDATE_ERROR_GET_SC_FAIL             -5
#define VM_UPDATE_ERROR_PATH_NOT_EXIST          -6
#define VM_UPDATE_ERROR_NO_MEMORY               -7
#define VM_UPDATE_ERROR_NO_UPDATE_FILE          -8
#define VM_UPDATE_ERROR_INTER                   -9

typedef void (*vm_update_mre_app_callback)(VMINT hdl, void * para);

/*****************************************************************************
 * FUNCTION
 *  vm_update_check_version
 * DESCRIPTION
 *  check new version is avaliable or not through service.  
 * PARAMETERS
 *  
 * RETURNS
 *  error code, VM_UPDATE_OK means success, can get result from callback
 *                   VM_UPDATE_OK_ALREADY_DOWNLOADED means new version already downloaded   
 *****************************************************************************/
VMINT vm_update_check_version(VMSTR URL, VMINT port, VMINT apn, vm_update_mre_app_callback callback, void* user_data);

/*****************************************************************************
 * FUNCTION
 *  vm_update_download
 * DESCRIPTION
 *  after check version, can use this to download new version app
 * PARAMETERS
 *  
 * RETURNS
 *  error code, VM_UPDATE_OK means success, can get result from callback
 *****************************************************************************/
VMINT vm_update_download(VMINT handle, VMINT bOnCard, vm_update_mre_app_callback callback, void* user_data);


/*****************************************************************************
 * FUNCTION
 *  vm_update_update_file
 * DESCRIPTION
 *  if downloaded, can use this to update to new version app. This will exit the running app.
 * PARAMETERS
 *  
 * RETURNS
 *****************************************************************************/
VMINT vm_update_update_file(void);

/*****************************************************************************
 * FUNCTION
 *  vm_update_cancel
 * DESCRIPTION
 *  cancel the downloading process
 * PARAMETERS
 *  
 * RETURNS
 *****************************************************************************/
VMINT vm_update_cancel(VMINT handle);

VMINT vm_update_check_launch(VMWSTR path, VMWSTR new_path);

#define VM_INSTALL_ID_LEN 60
#define VM_APPMGR_DEVELOPER_NAME_LEN    30
#define VM_APPMGR_TEL_NUM_LEN   20
#define VM_APPMGR_APP_NAME_LEN  15
#define VM_APPMGR_FILEPATH_LEN  260

#define VM_APPMGR_MRE_ALL_FLAG              0x0001
#define VM_APPMGR_MRE_INSTALLED_FLAG        0x0002
#define VM_APPMGR_MRE_SHORTCUT_FLAG         0x0004

#define VM_APPMGR_WIDGET_PACKAGE_FLAG       (0x8001) /* mre widget app */
#define VM_APPMGR_WALLPAPER_PACKAGE_FLAG       (0x8002) /* mre wallpaper app */
#define VM_APPMGR_LAUNCHER_PACKAGE_FLAG       (0x8004) /* mre launcher app */
#define VM_APPMGR_SCRLOCK_PACKAGE_FLAG       (0x8008) /* mre screen lock app */

#define VM_APPMGR_VPP_PACKAGE_FLAG \
                (VM_APPMGR_WIDGET_PACKAGE_FLAG |\
                 VM_APPMGR_WALLPAPER_PACKAGE_FLAG |\
                 VM_APPMGR_LAUNCHER_PACKAGE_FLAG |\
                 VM_APPMGR_SCRLOCK_PACKAGE_FLAG)


typedef VMCHAR vm_install_id[VM_INSTALL_ID_LEN];

typedef enum
{
    VM_APPMGR_INSTALL_TYPE_UNKNOWN = 0,    /* UNKNOWN */
    VM_APPMGR_INSTALL_TYPE_DOWNLOAD,       /* dwonload from server */
    VM_APPMGR_INSTALL_TYPE_ROM,            /* build-in app */
    VM_APPMGR_INSTALL_TYPE_LOCAL_INSTALL,  /* install from local */
    VM_APPMGR_INSTALL_TYPE_SHORTCUT,       /* shortcut app */
    VM_APPMGR_INSTALL_TYPE_END_OF_ENUM
}vm_appmgr_install_type;

/* Application storage position type */
typedef enum
{
    VM_APPMGR_APP_POSITION_UNKNOWN = 0,    /* UNKNOWN */
    VM_APPMGR_APP_POSITION_PHONE,          /* Phone */
    VM_APPMGR_APP_POSITION_CARD,           /* Memory card */
    VM_APPMGR_APP_POSITION_ROM,            /* build-in app */
    VM_APPMGR_APP_POSITION_END_OF_ENUM
} vm_appmgr_app_storage_position;

typedef struct
{
    VMUINT app_id;
    VMUINT app_size;
    vm_appmgr_install_type install_type; 
    vm_appmgr_app_storage_position store_pos;
    vm_time_t installed_time; 
    VMUINT16 developer[VM_APPMGR_DEVELOPER_NAME_LEN];  
    VMUINT16 tel[VM_APPMGR_TEL_NUM_LEN]; 
    VMUINT16 app_name[VM_APPMGR_APP_NAME_LEN]; 
    VMUINT16 app_path[VM_APPMGR_FILEPATH_LEN]; 
}vm_install_info;


typedef enum 
{
   VM_SLA_STOP,
   VM_SLA_START,
   VM_SLA_LABEL
} vm_sla_action_type;

typedef enum 
{
   VM_WALLPAPER_SRC_HOME_SCREEN,
   VM_WALLPAPER_SRC_LOCK_SCREEN
} vm_app_mgr_wallpaper_src_enum;


/*****************************************************************************
 * FUNCTION
 *  vm_appmgr_install
 * DESCRIPTION
 *  install mre app 
 * PARAMETERS
 *  path : [IN] path of app
 *  flag : [IN] reserved, please fill 0
 *  install_id : [OUT] identification of installed app
 * RETURNS
 *  error code 0 means success
 *****************************************************************************/
VMINT vm_appmgr_install(VMWSTR path, VMINT flag, vm_install_id install_id);

/*****************************************************************************
 * FUNCTION
 *  vm_appmgr_uninstall
 * DESCRIPTION
 *  uninstall mre app 
 * PARAMETERS
 *  install_id : [IN] identification of installed app, can get 
 *                            by using vm_appmgr_get_installed_list or vm_appmgr_is_installed
 * RETURNS
 *  error code 0 means success
 *****************************************************************************/
VMINT vm_appmgr_uninstall(vm_install_id install_id);

/*****************************************************************************
 * FUNCTION
 *  vm_appmgr_is_installed
 * DESCRIPTION
 *  check the mre app is intalled or not
 * PARAMETERS
 *  path : [IN] path of app
 *  install_id : [OUT] identification of installed app
 * RETURNS
 *  error code 0 means success
 *****************************************************************************/
VMBOOL vm_appmgr_is_installed(VMWSTR path, vm_install_id install_id);

/*****************************************************************************
 * FUNCTION
 *  vm_appmgr_get_installed_list
 * DESCRIPTION
 *  get installed app list. set install_id_list to NULL to get number of installed app.
 * PARAMETERS
 *  flag : [IN] 
 *  install_id_list : [OUT] identifications of installed app
 *  num :[IN/OUT] number of installed app
 * RETURNS
 *  error code 0 means success
 *****************************************************************************/
VMINT vm_appmgr_get_installed_list(VMINT flag ,vm_install_id* install_id_list, VMUINT* num);

/*****************************************************************************
 * FUNCTION
 *  vm_appmgr_get_install_info
 * DESCRIPTION
 *  get installed app detail information
 * PARAMETERS
 *  vm_install_id : [IN] identification of installed app
 *  vm_install_info : [OUT] detail information
 * RETURNS
 *  error code 0 means success
 *****************************************************************************/
VMINT vm_appmgr_get_install_info(vm_install_id install_id, vm_install_info* install_info);

/*****************************************************************************
 * FUNCTION
 *  vm_appmgr_activate_launcher
 * DESCRIPTION
 *  Active launcher plug-in
 * PARAMETERS
 *  install_id : [IN] identification of installed app, can get 
 *                            by using vm_appmgr_get_installed_list or vm_appmgr_is_installed
 * RETURNS
 *  error code 0 means success
 *****************************************************************************/
VMINT vm_appmgr_activate_launcher(vm_install_id install_id);

/*****************************************************************************
 * FUNCTION
 *  vm_appmgr_activate_screen_lock
 * DESCRIPTION
 *  Active Screen-Lock plug-in 
 * PARAMETERS
 *  install_id : [IN] identification of installed app, can get 
 *                            by using vm_appmgr_get_installed_list or vm_appmgr_is_installed
 * RETURNS
 *  error code 0 means success
 *****************************************************************************/
VMINT vm_appmgr_activate_screen_lock(vm_install_id install_id);

/*****************************************************************************
 * FUNCTION
 *  vm_appmgr_activate_wallpaper
 * DESCRIPTION
 *  Active wallpaper plug-in
 * PARAMETERS
 *  install_id : [IN] identification of installed app, can get 
 *                            by using vm_appmgr_get_installed_list or vm_appmgr_is_installed
 * RETURNS
 *  error code 0 means success
 *****************************************************************************/
VMINT vm_appmgr_activate_wallpaper(vm_install_id install_id, vm_app_mgr_wallpaper_src_enum src);

/******************************************************************************
 * FUNCTION
 *  vm_appmgr_get_mem_size
 * DESCRIPTION
 *  Get Memory size of DLUI components
 * PARAMETERS
 *  Package  :   [IN]       VM_APPMGR_WIDGET_PACKAGE_FLAG
 *                          VM_APPMGR_LAUNCHER_PACKAGE_FLAG
 *                          VM_APPMGR_WALLPAPER_PACKAGE_FLAG
 *                          VM_APPMGR_SCRLOCK_PACKAGE_FLAG
 * RETURNS
 *  Memory Size requirement, -1 means not support.
 ******************************************************************************/
VMINT vm_appmgr_get_mem_size(VMUINT32 package);



/*****************************************************************************
* FUNCTION
 *    vm_reg_func_callback
 * DESCRIPTION
 *  register get function pointer callback.
 * PARAMETERS
 *  f : [IN] callback function.
*****************************************************************************/
void vm_reg_func_callback(VMINT (*f)(VMSTR symbol));

/*****************************************************************************
* FUNCTION
 *    vm_sla_custom_logging
 * DESCRIPTION
 *  SWLA custom logging function
 * PARAMETERS
 *  custom_label : [IN] the custom label.
 *  action       : [IN] the logging action
*****************************************************************************/
void vm_sla_custom_logging(VMSTR custom_label, vm_sla_action_type action);

/* DOM-NOT_FOR_SDK-BEGIN */

/******************************************************************************
 * FUNCTION
 *	vm_get_customer_name
 * DESCRIPTION
 *	get customer name
 * PARAMETERS
 *	value : [OUT] string to store customer name.
 *	len : [IN] length of value.
 * RETURNS
 *	length of customer name.
 ******************************************************************************/
VMUINT vm_get_customer_name(VMCHAR *value, VMUINT len);

/******************************************************************************
 * FUNCTION
 *	vm_get_origin_release_verno
 * DESCRIPTION
 *	get origin release verno.
 * PARAMETERS
 *	value : [OUT] string to store origin release verno.
 *	len : [IN] length of value.
 * RETURNS
 *	length of origin release verno.
 ******************************************************************************/
VMUINT vm_get_origin_release_verno(VMCHAR *value, VMUINT len);

/* DOM-NOT_FOR_SDK-END */

/******************************************************************************
 * FUNCTION
 *  vm_is_support_downloadable_app_icon
 * DESCRIPTION
 *  check whether downloadable app icon is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means support, FALSE means NOT support.
 ******************************************************************************/
VMINT vm_is_support_downloadable_app_icon(void);

/******************************************************************************
 * FUNCTION
 *  vm_appmgr_is_launcher_activated
 * DESCRIPTION
 *  check whether launcher is activated.
 * PARAMETERS
 *  install_id  :   [IN]    identification of installed app, can get by using
 *                          vm_appmgr_get_installed_list or vm_appmgr_is_installed.
 * RETURNS
 *  TRUE means activated, FALSE means NOT activated.
 ******************************************************************************/
VMINT vm_appmgr_is_launcher_activated(vm_install_id install_id);

/******************************************************************************
 * FUNCTION
 *  vm_appmgr_is_wallpaper_activated
 * DESCRIPTION
 *  check whether wallpaper is activated.
 * PARAMETERS
 *  install_id  :   [IN]    identification of installed app, can get by using
 *                          vm_appmgr_get_installed_list or vm_appmgr_is_installed.
 *  src :   [IN]    wallpaper src.
 * RETURNS
 *  TRUE means activated, FALSE means NOT activated.
 ******************************************************************************/
VMINT vm_appmgr_is_wallpaper_activated(
            vm_install_id install_id,
            VMINT src);

/******************************************************************************
 * FUNCTION
 *  vm_appmgr_is_screen_lock_activated
 * DESCRIPTION
 *  check whether screen lock is activated.
 * PARAMETERS
 *  install_id  :   [IN]    identification of installed app, can get by using
 *                          vm_appmgr_get_installed_list or vm_appmgr_is_installed.
 * RETURNS
 *  TRUE means activated, FALSE means NOT activated.
 ******************************************************************************/
VMINT vm_appmgr_is_screen_lock_activated(vm_install_id install_id);

/******************************************************************************
 * FUNCTION
 *	vm_appmgr_is_support_launcher
 * DESCRIPTION
 *	check whether launcher is supported.
 * PARAMETERS
 *	void.
 * RETURNS
 *	TRUE means support, FALSE means NOT support.
 ******************************************************************************/
VMINT vm_appmgr_is_support_launcher(void);

/******************************************************************************
 * FUNCTION
 *	vm_appmgr_is_support_wallpaper
 * DESCRIPTION
 *	check whether wallpaper is supported.
 * PARAMETERS
 *	void.
 * RETURNS
 *	TRUE means support, FALSE means NOT support.
 ******************************************************************************/
VMINT vm_appmgr_is_support_wallpaper(void);

/******************************************************************************
 * FUNCTION
 *	vm_appmgr_is_support_screen_lock
 * DESCRIPTION
 *	check whether screen_lock is supported.
 * PARAMETERS
 *	void.
 * RETURNS
 *	TRUE means support, FALSE means NOT support.
 ******************************************************************************/
VMINT vm_appmgr_is_support_screen_lock(void);

/******************************************************************************
 * FUNCTION
 *	vm_appmgr_is_support_widget
 * DESCRIPTION
 *	check whether widget is supported.
 * PARAMETERS
 *	void.
 * RETURNS
 *	TRUE means support, FALSE means NOT support.
 ******************************************************************************/
VMINT vm_appmgr_is_support_widget(void);


/*****************************************************************************
* FUNCTION
 *    vm_malloc_nc_topmost
 * DESCRIPTION
 *  allocate specified size of non-cachable memory from topmost address
 * PARAMETERS
 *  size : [IN]  size of byte to be allocated.
 * RETURNS
 *  memory pointer allocated, NULL means allocation failed.
*****************************************************************************/
void *vm_malloc_nc_topmost(int size);

/*****************************************************************************
* FUNCTION
 *    vm_malloc_nc_topmost
 * DESCRIPTION
 *  allocate specified size of  memory from topmost address
 * PARAMETERS
 *  size : [IN]  size of byte to be allocated.
 * RETURNS
 *  memory pointer allocated, NULL means allocation failed.
*****************************************************************************/
void *vm_malloc_topmost(int size);

/*****************************************************************************
* FUNCTION
 *    vm_malloc_nc_topmost
 * DESCRIPTION
 *  re-allocate specified size of  memory from topmost address
 * PARAMETERS
 *  size : [IN]  size of byte to be allocated.
 * RETURNS
 *  memory pointer allocated, NULL means allocation failed.
*****************************************************************************/
void *vm_realloc_topmost(void * p,int size);


typedef enum
{
    VM_DEV_INFO_MODEL_NUMBER, //11
    VM_DEV_INFO_FW_NUMBER, //22
    VM_DEV_INFO_LANG_PACK //33
}VM_MRE_SYS_DEV_INFO_ENUM;

/*****************************************************************************
* FUNCTION
 *    vm_get_device_info
 * DESCRIPTION
 *    m_get_device_info
 * PARAMETERS
 *  type : [IN]  VM_SYS_DEV_INFO_ENUM
 *  buffer : [OUT] buffer, MUST NOT LESS than  256 bytes
 * RETURNS
 *  0 sucess, others fail.
*****************************************************************************/
VMINT vm_get_device_info(VMINT type, VMCHAR* buffer);

#ifdef __cplusplus
}
#endif 

#endif /* VMSYS_SDK_H_ */
