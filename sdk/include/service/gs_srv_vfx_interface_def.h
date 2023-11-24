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

/*****************************************************************************
 * Include
 *****************************************************************************/
 
#include "vfx_datatype.h"

#ifdef __cplusplus
extern "C"
{
#endif

//	#include "vfx_srv_dt_adp.h"
//	#include "vfx_srv_misc_adp.h"

#ifdef __cplusplus
}
#endif

#include "gs_idef.h"
#include "gs_srv_vfx_framework.h"


/*****************************************************************************
 * Define
 *****************************************************************************/

#define DEF_METHODS_IVfxService(IOBJ) \
    DEF_METHODS_GS_IBase(IOBJ)  \

#define DEF_IVfxService_misc(IOBJ)  \
    DEF_METHOD0(IOBJ, VfxS32, vfx_srv_get_lcd_width)    \
    DEF_METHOD0(IOBJ, VfxS32, vfx_srv_get_lcd_height)   \
    DEF_METHOD0(IOBJ, VfxS32, vfx_srv_get_base_layer_bit_per_pixel) \
    DEF_METHOD0(IOBJ, VfxS32, vfx_srv_get_vrt_mem_unit_size)    \

#if 1
#define DEF_IVfxService_FW(IOBJ)    \
    DEF_METHOD0(IOBJ, MMI_BOOL, IsMainLCDHistoryBack)    \
    DEF_METHOD0(IOBJ, VfxU32, srv_mre_get_res_base)    \
    DEF_METHOD0(IOBJ, VfxU32, srv_mre_get_group_id)    \
    DEF_METHOD0(IOBJ, void, srv_mre_set_venus_flag)    \
    DEF_METHOD0(IOBJ, VfxS32, mmi_is_redrawing_bk_screens)    \
    DEF_METHOD0(IOBJ, MMI_ID, mmi_frm_scrn_get_active_id)    \
    DEF_METHOD0(IOBJ, MMI_BOOL, mmi_frm_is_in_backward_scenario)    \
    DEF_METHOD0(IOBJ, MMI_ID, mmi_frm_group_get_active_id)    \
    DEF_METHOD1(IOBJ, VfxU16, mmi_res_get_app_max, VfxU16, app_res_id) \
    DEF_METHOD1(IOBJ, mmi_ret, mmi_frm_group_close, MMI_ID, group_id) \
    DEF_METHOD1(IOBJ, MMI_ID, mmi_frm_group_get_top_parent_group_id, MMI_ID, group_id) \
    DEF_METHOD1(IOBJ, void *, mmi_frm_group_get_user_data, MMI_ID, group_id) \
    DEF_METHOD1(IOBJ, VfxU32, mmi_frm_scrn_get_count, MMI_ID, group_id) \
    DEF_METHOD2(IOBJ, MMI_BOOL, mmi_frm_create_new_screen, entry_func_ptr, entry_func, void*, arg) \
    DEF_METHOD2(IOBJ, MMI_ID, mmi_frm_group_enter, MMI_ID, group_id, mmi_group_enter_flag, flag) \
    DEF_METHOD2(IOBJ, mmi_ret, mmi_frm_scrn_close, MMI_ID, parent_id, MMI_ID, scrn_id) \
    DEF_METHOD2(IOBJ, mmi_ret, mmi_frm_group_set_caller, MMI_ID, group_id, MMI_ID, caller_id) \
    DEF_METHOD2(IOBJ, void *, mmi_frm_scrn_get_user_data, MMI_ID, parent_id, MMI_ID, scrn_id) \
    DEF_METHOD2(IOBJ, mmi_ret, mmi_frm_group_get_info, MMI_ID, group_id, mmi_group_node_struct *, node_info) \
    DEF_METHOD4(IOBJ, MMI_ID, mmi_frm_group_create, MMI_ID, parent_id, MMI_ID, group_id, mmi_proc_func, proc, void *, user_data) \
    DEF_METHOD2(IOBJ, mmi_ret, mmi_frm_group_send_to_parent, MMI_ID, self_gid, mmi_group_event_struct *, evt) \
    DEF_METHOD3(IOBJ, mmi_ret, mmi_frm_group_set_proc_data, MMI_ID, group_id, mmi_proc_func, proc, void *, data) \
    DEF_METHOD5(IOBJ, MMI_BOOL, mmi_frm_scrn_enter, MMI_ID, parent_id, MMI_ID, scrn_id, FuncPtr, exit_proc, FuncPtr, entry_proc, mmi_frm_scrn_type_enum, scrn_type) \
    DEF_METHOD4(IOBJ, void, mmi_frm_scrn_first_enter, MMI_ID, parent_id, MMI_ID, scrn_id, FuncPtr, entry_proc, void *, user_data) \
    DEF_METHOD3(IOBJ, MMI_ID, mmi_frm_scrn_get_neighbor_id, MMI_ID, parent_id, MMI_ID, base_id, mmi_scenario_node_flag, flag) \
    DEF_METHOD4(IOBJ, mmi_ret, mmi_frm_scrn_insert, MMI_ID, parent_id, MMI_ID, base_id, mmi_frm_node_struct *, new_node_info, mmi_scenario_node_flag, flag) \
    DEF_METHOD3(IOBJ, MMI_BOOL, mmi_frm_scrn_is_present, MMI_ID, parent_id, MMI_ID, scrn_id, mmi_node_present_flag, flag) \
    DEF_METHOD3(IOBJ, mmi_ret, mmi_frm_scrn_set_leave_proc, MMI_ID, parent_id, MMI_ID, scrn_id, mmi_proc_func, proc) \
    DEF_METHOD3(IOBJ, void, mmi_frm_post_event, mmi_event_struct *, evt, mmi_proc_func, proc, void *, user_data) \
    DEF_METHOD5(IOBJ, void, mmi_frm_post_event_ex, mmi_event_struct *, evt, mmi_proc_func, proc, void *, user_data, mmi_post_event_result_proc_func, result_cb, void *, result_cb_user_data) \
    DEF_METHOD3(IOBJ, mmi_ret, mmi_frm_group_set_caller_proc, MMI_ID, group_id, mmi_proc_func, caller_proc, void *, caller_user_data) \
    DEF_METHOD2(IOBJ, mmi_ret, mmi_frm_group_send_to_caller, MMI_ID, self_gid, mmi_group_event_struct *, evt)   \
    DEF_METHOD2(IOBJ, void, mmi_frm_group_post_to_caller, MMI_ID, self_gid, mmi_group_event_struct *, evt)  \
    DEF_METHOD1(IOBJ, MMI_BOOL, mmi_frm_suspend_handle_key_process, MMI_BOOL, enable)   \
    DEF_METHOD1(IOBJ, void, mmi_frm_group_hide, MMI_ID, group_id)   \
    DEF_METHOD1(IOBJ, mmi_scenario_state_enum, mmi_frm_group_get_state, MMI_ID, group_id)   \
    //DEF_METHOD2(IOBJ, void, mmi_frm_set_translate_key_handler, mmi_frm_trans_key_handle_enum, layer, mmi_frm_translate_keyhandler_func_ptr, func_ptr)   \
    //DEF_METHOD1(IOBJ, void, mmi_pen_register_down_handler, mmi_pen_hdlr, pen_fp)    \
    //DEF_METHOD1(IOBJ, void, mmi_pen_register_move_handler, mmi_pen_hdlr, pen_fp)    \
    //DEF_METHOD1(IOBJ, void, mmi_pen_register_up_handler, mmi_pen_hdlr, pen_fp)    
#endif

#if 0
#endif    

DEF_INTERFACE(IVfxService, GS_IBase)
    DEF_METHODS_IVfxService(IVfxService)
    DEF_IVfxService_misc(IVfxService)
    DEF_IVfxService_FW(IVfxService)
DEF_INTERFACE_END(IVfxService)

