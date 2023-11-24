
#ifndef __GS_SRV_VFX_FRAMEWORK_H__
#define __GS_SRV_VFX_FRAMEWORK_H__

#ifdef __MRE_SDK__

typedef VfxU16 mmi_id;
typedef VfxU16  mmi_event_id;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define MMI_BOOL        VfxS32
#ifndef MMI_FALSE
#define MMI_FALSE       (0)
#endif

#ifndef MMI_TRUE
#define MMI_TRUE        (!0)
#endif

#define MMI_RET_OK          (0)         /* the return value of mmi_ret */
#define MMI_RET_DONT_CARE   (-499)      /* the return value of mmi_ret */
#define MMI_RET_ERR         (-500)      /* the return value of mmi_ret */

#define SCR_ID_INVALID                  (0)
/* the invalid group id */
#define GRP_ID_INVALID                  (0)

#define MMI_RET_STOP_END_KEY_FLOW       (1)

#define MMI_FRM_INIT_EVENT(_evt, _evt_id)  \
        do {    \
            memset((_evt), 0, sizeof(*(_evt)));   \
            (_evt)->evt_id = (_evt_id);    \
            (_evt)->size = sizeof(*(_evt));    \
        } while(0)

#define MMI_FRM_POST_EVENT(_evt, _proc, _user_data)    \
                VFX_SRV_CALL3(mmi_frm_post_event, (mmi_event_struct *)(_evt), (mmi_proc_func)(_proc), (void *)(_user_data))

#define MMI_FRM_POST_EVENT_EX(_evt, _proc, _user_data, _rst_cb, _rst_cb_user_data)    \
                VFX_SRV_CALL5(mmi_frm_post_event_ex, (mmi_event_struct *)(_evt), (mmi_proc_func)(_proc), (void *)(_user_data), (mmi_post_event_result_proc_func)(_rst_cb), (void *)(_rst_cb_user_data))

#define MMI_EVT_PARAM_HEADER    \
    VfxU16 evt_id;                 \
    VfxU16 size;                   \
    void *user_data;

#define MMI_EVT_GROUP_PARAM_HEADER    \
    MMI_EVT_PARAM_HEADER            \
    mmi_id sender_id;

typedef VfxS32 mmi_ret;
typedef VfxU16 MMI_ID;

#define FRM_RESERVED_GROUP_NUMBER   	(64)
#define GLOBAL_BASE                     (1)
    
#define VENUS_FW_BASE                   (0)
#define VENUS_FW_BASE_MAX               (0xFFFFFFFF)

typedef enum
{
    /* SYS: this layer is used to handle END, VOL_DOWN, VOL_UP key in call */
    MMI_FRM_TRANS_KEY_SYS = 0,
    MMI_FRM_TRANS_KEY_VENUS,
    /* APP: used for application, JAVA only now. */
    MMI_FRM_TRANS_KEY_APP,
    /* EDITOR: used for IME */
    MMI_FRM_TRANS_KEY_EDITOR,
    /* Translate Key handler end */
    MMI_FRM_TRANS_KEY_HANDLE_END
} mmi_frm_trans_key_handle_enum;


typedef enum _mmi_scenario_state_enum
{
    MMI_SCENARIO_STATE_NONE = 0,                /* It is none state */
    MMI_SCENARIO_STATE_ACTIVE = 0x1,            /* at active state, The node is active group or active screen. */
    MMI_SCENARIO_STATE_INACTIVE = 0x2,          /* at inactive state */
    MMI_SCENARIO_STATE_CREATE = 0x4,            /* at create state. It is only for the group. */
    MMI_SCENARIO_STATE_FIRST_ENTRY = 0x8,       /* at group first entry state. */
    MMI_SCENARIO_STATE_FORWARD = 0x10,          /* at forward state. */
    MMI_SCENARIO_STATE_FORWARD_ACTIVE = 0x11,   /* at forward-active state. the new node will be in forward-active state */
    MMI_SCENARIO_STATE_FORWARD_INACTIVE = 0x12, /* at forward-inactive state. the current node will be in forward-inactive state */
    MMI_SCENARIO_STATE_BACKWARD = 0x20,         /* at backward state. the active group/screen was closed and it invokes the goback process */
    MMI_SCENARIO_STATE_BACKWARD_ACTIVE = 0x21,  /* at backward-active state. the target node will be in backward-active state */
    MMI_SCENARIO_STATE_BACKWARD_INACTIVE = 0x22,/* at backward-inactive state. the current node will be in backward-inactive state */
    MMI_SCENARIO_STATE_REDRAW = 0x40,           /* at redraw state; it is in goback process */
    MMI_SCENARIO_STATE_CLOSE_IND = 0x80,        /* indicate to close the active group/screen; at the beginning of the goback process */
    MMI_SCENARIO_STATE_DELETE_REQ = 0x100,      /* request to delete the inactive group/screen; at the beginning of the delete process */
    MMI_SCENARIO_STATE_EXIT = 0x200,            /* at exit state */
    MMI_SCENARIO_STATE_DEINIT = 0x400,          /* at deinit state */
    MMI_SCENARIO_STATE_HIDE = 0x800,
    MMI_SCENARIO_STATE_UNHIDE =0x1000,
    MMI_SCENARIO_STATE_HIDING = 0x2000,
    MMI_SCENARIO_STATE_UNHIDING = 0x4000,

    MMI_SCENARIO_STATE_MAX                      /* scenario state max */
}mmi_scenario_state_enum/*, mmi_frm_scenario_state_enum*/;


typedef enum _mmi_scenario_evt_enum
{
    EVT_ID_POST_CB_RST = GLOBAL_BASE + 1,
    EVT_ID_POST_DEREG_CB,
    
    EVT_ID_SCENARIO_CHANGE,
    EVT_ID_GROUP_ENTER,                 /* Enter new group */
    EVT_ID_GROUP_ACTIVE,                /* active group */
    EVT_ID_GROUP_INACTIVE,              /* inactive group */
    EVT_ID_GROUP_FOCUSED,               /* focus a topest group */
    EVT_ID_GROUP_DEFOCUSED,             /* defocus a topest group */
    EVT_ID_GROUP_GOBACK,                /* close the active group; invoke the goback process:
                                         * We will send EVT_ID_GROUP_GOBACK to group proc first. 
                                         * send EVT_ID_SCRN_GOBACK/EVT_ID_GROUP_DELETE_REQ to the children (screens), 
                                         * and send EVT_ID_GROUP_INACTIVE to group proc.
                                         * Then finding the active group/screen and invoke the active process.
                                         * At last, we send EVT_ID_SCRN_DEINIT/EVT_ID_GROUP_DEINIT to all closed screens and groups.
                                         */
    EVT_ID_GROUP_GOBACK_IN_END_KEY,     /* close the active group; invoke the goback process:
                                         * We will send EVT_ID_GROUP_GOBACK to group proc first. 
                                         * send EVT_ID_SCRN_GOBACK/EVT_ID_GROUP_DELETE_REQ to the children (screens), 
                                         * and send EVT_ID_GROUP_INACTIVE to group proc.
                                         * Then finding the active group/screen and invoke the active process.
                                         * At last, we send EVT_ID_SCRN_DEINIT/EVT_ID_GROUP_DEINIT to all closed screens and groups.
                                         */
    EVT_ID_GROUP_DELETE_REQ,            /* close the inactive group; invoke the delete process only:
                                         * We will send EVT_ID_GROUP_DELETE_REQ to group proc. 
                                         * send EVT_ID_SCRN_DELETE_REQ to the children (screens),
                                         * and send EVT_ID_SCRN_DEINIT/EVT_ID_GROUP_DEINIT to all closed screens and groups.
                                         * We will abort the delete process if group proc or screen leave_proc don't return MMI_RET_OK.
                                         */
    EVT_ID_GROUP_DELETE_REQ_IN_END_KEY, /* close the inactive group; invoke the delete process only:
                                         * We will send EVT_ID_GROUP_DELETE_REQ to group proc. 
                                         * send EVT_ID_SCRN_DELETE_REQ to the children (screens),
                                         * and send EVT_ID_SCRN_DEINIT/EVT_ID_GROUP_DEINIT to all closed screens and groups.
                                         * We will abort the delete process if group proc or screen leave_proc don't return MMI_RET_OK.
                                         */
    EVT_ID_GROUP_EXIT,                  /* Exit the group */
    EVT_ID_GROUP_DEINIT,                /* deinint group */

    EVT_ID_GROUP_REDRAW_START,          /* Notificaiton for start to redraw a group */
    EVT_ID_GROUP_REDRAW_DONE,           /* Notification for finish the group redrawing */

    EVT_ID_SCRN_ACTIVE,
    EVT_ID_SCRN_INACTIVE,
    EVT_ID_SCRN_GOBACK,                 /* close the active screen; invoke the goback process: 
                                         * We will send EVT_ID_SCRN_GOBACK to screen leave_proc and then executing the exit_proc.
                                         * At last, we send EVT_ID_SCRN_DEINIT active screen leave_proc.
                                         */
    EVT_ID_SCRN_GOBACK_IN_END_KEY,      /* close the active screen; invoke the goback process: 
                                         * We will send EVT_ID_SCRN_GOBACK to screen leave_proc and then executing the exit_proc.
                                         * At last, we send EVT_ID_SCRN_DEINIT active screen leave_proc.
                                         */
    EVT_ID_SCRN_DELETE_REQ,             /* delete the inactive screen; invoke the delete process only:
                                         * We will send EVT_ID_SCRN_DELETE_REQ to screen leave_proc. If there are many screens,
                                         * we will send this event to each screen. At last, we EVT_ID_SCRN_DEINIT to all screen leave_proc.
                                         */
    EVT_ID_SCRN_DELETE_REQ_IN_END_KEY,  /* delete the inactive screen; invoke the delete process only:
                                         * We will send EVT_ID_SCRN_DELETE_REQ to screen leave_proc. If there are many screens,
                                         * we will send this event to each screen. At last, we EVT_ID_SCRN_DEINIT to all screen leave_proc.
                                         */
    EVT_ID_SCRN_DEINIT,                 /* deinit the screen */

    EVT_ID_GROUP_POST_CALLER_NOTIFY,
    EVT_ID_GROUP_POST_PARENT_NOTIFY,
    EVT_ID_SCRN_POST_PARENT_NOTIFY,

    EVT_ID_GOBACK_HISTORY,

    EVT_ID_TAB_POST_LEFT_ARROW_NOTIFY,
    EVT_ID_TAB_POST_RIGHT_ARROW_NOTIFY,

    EVT_ID_PRE_KEY,
    EVT_ID_ON_KEY,
    EVT_ID_POST_KEY,
    EVT_ID_PRE_KEY_EVT_ROUTING,
    EVT_ID_POST_KEY_EVT_ROUTING,
    EVT_ID_KEY_DEFAULT_HANDLER,
    EVT_ID_PRE_TOUCH_EVT_ROUTING,
    EVT_ID_POST_TOUCH_EVT_ROUTING,
    EVT_ID_ON_TOUCH,
    EVT_ID_NMGR_DEFER,
    EVT_ID_NMGR_PLAY_TONE,
    EVT_ID_NMGR_PLAY_VIB,
	EVT_ID_NMGR_IDLE_CANCEL,
    EVT_ID_ROOT_SCRN_FIRST_ENTER,
    EVT_ID_ROOT_SCRN_COMM_ENTER,
    EVT_ID_ROOT_SCRN_COMM_POST_ENTER,
    EVT_ID_SCRN_ENTER_SUCCESS_NOFITY,
    EVT_ID_NMGR_SUBLCD_NOTIFY,
    EVT_ID_SRV_INIT,
    EVT_ID_SRV_DEINIT,
    EVT_ID_GROUP_HIDE,
    EVT_ID_GROUP_UNHIDE,
    EVT_ID_SCRN_HIDE,
    EVT_ID_SCRN_UNHIDE,
    EVT_ID_POST_TO_GROUP,
    EVT_ID_POST_TO_SRV,
    EVT_ID_SCENARIO_END,
    EVT_ID_APP_GROUP_POST_NOTIFY,
    EVT_ID_APP_CONFIG,
    EVT_ID_DELETE_DANGLE_GROUP_REQ,
    
    EVT_ID_SCENARIO_MAX
}mmi_scenario_evt_enum;


typedef enum _mmi_group_enter_flag
{
	MMI_FRM_NODE_NONE_FLAG = 0,
    MMI_FRM_NODE_SMART_CLOSE_FLAG,
    MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG,
	MMI_FRM_GROUP_ENTER_MAX
}mmi_group_enter_flag, mmi_group_attrib_enum;

typedef enum
{
    MMI_FRM_UNKNOW_SCRN,
    MMI_FRM_IDLE_SCRN,
    MMI_FRM_FULL_SCRN,
    MMI_FRM_SMALL_SCRN,
    MMI_FRM_TAB_PAGE,
    MMI_FRM_TAB,
    MMI_FRM_SCRN_GROUP,
    MMI_FRM_FG_ONLY_SCRN,
    MMI_FRM_SCRN_TYPE_MAX
} mmi_frm_scrn_type_enum;


typedef enum _mmi_scenario_node_flag
{
	MMI_FRM_NODE_BEFORE_FLAG,
	MMI_FRM_NODE_AFTER_FLAG,
	MMI_FRM_NODE_AT_BEGINNING_FLAG,
	MMI_FRM_NODE_AT_LATEST_FLAG,
	MMI_FRM_NODE_MAX
}mmi_scenario_node_flag;

typedef enum _mmi_node_present_flag
{
    MMI_FRM_NODE_ALL_FLAG,
    MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG,
	MMI_FRM_NODE_PRESENT_MAX
}mmi_node_present_flag;


typedef enum _GLOBAL_SCR_ENUM
{
    SCR_ID_GLOBAL_DUMMY = GLOBAL_BASE + 1,   /* all screen id shall be put below this one */
    SCR_ID_DUMMY = SCR_ID_GLOBAL_DUMMY,
    SCR_ID_DUMMY_INTERNAL,
    GRP_ID_AUTO_GEN,                        /* the auto-gen id, framework will genearte the group id automatically */
    GRP_ID_ROOT,                            /* the scenario root id */
    GRP_ID_AUTO_GEN_BASE,
    GRP_ID_AUTO_GEN_MAX = GRP_ID_AUTO_GEN_BASE + FRM_RESERVED_GROUP_NUMBER,
    GRP_ID_ORIG_MECH,
    GRP_ID_DANGLE,
    SRV_ID_ROOT,
    GRP_ID_BK,

    GLOBAL_SCR_MAX
}GLOBAL_SCR_ENUM;


typedef struct
{
    /* Event id */
    VfxU16 evt_id; 
    /* Event structure size */
    VfxU16 size; 
    /* User data pointer */
    void *user_data;
}mmi_event_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    mmi_ret result;
    mmi_event_struct *evt_p;
} mmi_post_result_event_struct;

typedef void (*FuncPtr) (void);
typedef void (*entry_func_ptr) (void *arg);
typedef mmi_ret (*mmi_proc_func) (mmi_event_struct *param);
typedef mmi_ret (*mmi_post_event_result_proc_func)(mmi_post_result_event_struct *result_evt);
typedef MMI_BOOL ( *mmi_frm_translate_keyhandler_func_ptr)(VfxS16 mmi_key_code, VfxS16 mmi_key_type, VfxU16 ucs2_value, VfxU32 special_key_flag);


typedef struct _mmi_frm_node_struct
{
    MMI_ID          id;             /* the group id from mmi_frm_group_create or the screen id */
    mmi_proc_func   entry_proc;     /* the group proc or the screen's entry function */
    void            *user_data;     /* the group user_data or the screen's user_data */

}mmi_frm_node_struct;

typedef struct _mmi_group_node_struct
{
    MMI_ID          parent;           /* the parent of the group */
    MMI_ID          caller;           /* the caller of the group */
    VfxU32          priority;         /* the priority of the group */
    void*           user_data;        /* the user_data of the group */
    mmi_proc_func   proc;             /* the proc of the group */
    mmi_proc_func   caller_proc;      /* the caller proc */
    void*           caller_user_data; /* the caller user data */
    VfxU32          state;            /* the screen state */
}mmi_group_node_struct;

typedef struct _mmi_group_event_struct
{
    MMI_EVT_GROUP_PARAM_HEADER
}mmi_group_event_struct;

typedef struct _mmi_scrn_essential_struct
{
    MMI_ID  group_id;       /* the current screen's group id */
    MMI_ID  tab_id;         /* the current tab-page's tab id */
    MMI_ID  scrn_id;        /* the current screen's id */
    void    *user_data;     /* the current screen's user_data */

}mmi_scrn_essential_struct;


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MRE_SDK__ */

#endif /* __GS_SRV_VFX_FRAMEWORK_H__ */

