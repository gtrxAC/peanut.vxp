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

#ifndef VFX_MRE_SERVICE_IMPL_H
#define VFX_MRE_SERVICE_IMPL_H

#include "gs_id.h"
#include "gs_base.h"
#include "gs_cbase.h"
#include "vmpromng.h"

#include "vfx_cpp_base.h"


#define GS_GEN_INTERFACE
#include "gs_srv_vfx_interface_def.h"

typedef void (*scrFuncPtr) (mmi_scrn_essential_struct* scrn_info);

class VfxService : public GS_CBase, public IVfxService
{
    GS_CBASE_IMPLEMENT

public:
    virtual S32 CALLCC queryInterface(S32 iid, GS_IBase **pptr);

    VfxService(U32 handle) : GS_CBase(handle)
    {
    }
    
    virtual ~VfxService()
    {
        // Release all internal unreleased resources
    }

    ////////////////////////////////////////////////////////////////////////////////////
    //
    //  Framework
    //
    ////////////////////////////////////////////////////////////////////////////////////
public:
    virtual VfxU16 CALLCC mmi_res_get_app_max(VfxU16 app_res_id);
    virtual MMI_BOOL CALLCC IsMainLCDHistoryBack(void);
    virtual MMI_BOOL CALLCC mmi_frm_create_new_screen(entry_func_ptr entry_func, void* arg);
    virtual mmi_ret CALLCC mmi_frm_group_close(MMI_ID group_id);
    virtual MMI_ID CALLCC mmi_frm_group_create(MMI_ID parent_id, MMI_ID group_id, mmi_proc_func proc, void *user_data);
    virtual MMI_ID CALLCC mmi_frm_group_enter(MMI_ID group_id, mmi_group_enter_flag flag);
    virtual MMI_ID CALLCC mmi_frm_group_get_active_id(void);
    virtual mmi_ret CALLCC mmi_frm_group_get_info(MMI_ID group_id, mmi_group_node_struct *node_info);
    virtual MMI_ID CALLCC mmi_frm_group_get_top_parent_group_id(MMI_ID group_id);
    virtual void * CALLCC mmi_frm_group_get_user_data(MMI_ID group_id);
    virtual mmi_ret CALLCC mmi_frm_group_send_to_parent(MMI_ID self_gid, mmi_group_event_struct *evt);
    virtual mmi_ret CALLCC mmi_frm_group_set_caller(MMI_ID group_id, MMI_ID caller_id);
    virtual mmi_ret CALLCC mmi_frm_group_set_proc_data(MMI_ID group_id, mmi_proc_func proc, void *data);
    virtual MMI_BOOL CALLCC mmi_frm_is_in_backward_scenario(void);
    virtual mmi_ret CALLCC mmi_frm_scrn_close(MMI_ID parent_id, MMI_ID scrn_id);
    virtual MMI_BOOL CALLCC mmi_frm_scrn_enter(MMI_ID parent_id, MMI_ID scrn_id, FuncPtr exit_proc, FuncPtr entry_proc, mmi_frm_scrn_type_enum scrn_type);
    virtual void CALLCC mmi_frm_scrn_first_enter(MMI_ID parent_id, MMI_ID scrn_id, FuncPtr entry_proc, void *user_data);
    virtual MMI_ID CALLCC mmi_frm_scrn_get_active_id(void);
    virtual VfxU32 CALLCC mmi_frm_scrn_get_count(MMI_ID group_id);
    virtual MMI_ID CALLCC mmi_frm_scrn_get_neighbor_id(MMI_ID parent_id, MMI_ID base_id, mmi_scenario_node_flag flag);
    virtual void * CALLCC mmi_frm_scrn_get_user_data(MMI_ID parent_id, MMI_ID scrn_id);
    virtual mmi_ret CALLCC mmi_frm_scrn_insert(MMI_ID parent_id, MMI_ID base_id, mmi_frm_node_struct *new_node_info, mmi_scenario_node_flag flag);
    virtual MMI_BOOL CALLCC mmi_frm_scrn_is_present(MMI_ID parent_id, MMI_ID scrn_id, mmi_node_present_flag flag);
    virtual mmi_ret CALLCC mmi_frm_scrn_set_leave_proc(MMI_ID parent_id, MMI_ID scrn_id, mmi_proc_func proc);
    virtual VfxS32 CALLCC mmi_is_redrawing_bk_screens();
    virtual void CALLCC mmi_frm_post_event(mmi_event_struct *evt, mmi_proc_func proc, void *user_data);
    virtual void CALLCC mmi_frm_post_event_ex(mmi_event_struct *evt, mmi_proc_func proc, void *user_data, mmi_post_event_result_proc_func result_cb, void *result_cb_user_data);
    virtual VfxU32 CALLCC srv_mre_get_group_id(void);
    virtual VfxU32 CALLCC srv_mre_get_res_base(void);
    virtual void CALLCC srv_mre_set_venus_flag();
    virtual mmi_ret CALLCC mmi_frm_group_set_caller_proc(MMI_ID group_id, mmi_proc_func caller_proc, void *caller_user_data);
    virtual void CALLCC mmi_frm_group_post_to_caller(MMI_ID self_gid, mmi_group_event_struct *evt);
    virtual mmi_ret CALLCC mmi_frm_group_send_to_caller(MMI_ID self_gid, mmi_group_event_struct *evt);
    virtual MMI_BOOL CALLCC mmi_frm_suspend_handle_key_process(MMI_BOOL enable);
    virtual void CALLCC mmi_frm_group_hide(MMI_ID group_id);
    virtual mmi_scenario_state_enum CALLCC mmi_frm_group_get_state(MMI_ID group_id);
    virtual void CALLCC mmi_frm_set_translate_key_handler(mmi_frm_trans_key_handle_enum layer, mmi_frm_translate_keyhandler_func_ptr func_ptr);
    
    ////////////////////////////////////////////////////////////////////////////////////
    //
    //  UI core
    //
    ////////////////////////////////////////////////////////////////////////////////////
    /* FS service */
    virtual VfxS32 CALLCC FS_Open(const WCHAR* filename, VfxU32 flag);
    virtual void CALLCC FS_Close(FS_HANDLE FileHandle);
    virtual VfxS32 CALLCC FS_Seek(FS_HANDLE FileHandle, VfxS32 Offset, VfxS32 Whence);
    virtual VfxS32 CALLCC FS_GetFilePosition(FS_HANDLE FileHandle, VfxU32 * Position);
    virtual VfxS32 CALLCC FS_Read(FS_HANDLE FileHandle, void * DataPtr, VfxU32 Length, VfxU32 * Read);
    virtual VfxS32 CALLCC FS_Write(FS_HANDLE FileHandle, void * DataPtr, VfxU32 Length, VfxU32 * Written);

    /* misc service, LCD related */
    virtual VfxS32 CALLCC vfx_srv_get_lcd_width();
    virtual VfxS32 CALLCC vfx_srv_get_lcd_height();
    virtual VfxS32 CALLCC vfx_srv_get_base_layer_bit_per_pixel();
    virtual VfxS32 CALLCC vfx_srv_get_vrt_mem_unit_size();

#if 0
#endif

#if 0
#endif

#if 0
#endif

private:
    static mmi_ret postExCallbackHelper(mmi_post_result_event_struct *result_evt);
    static mmi_ret setProcDataHelp(mmi_event_struct *param);
    static MMI_BOOL processKeyInput(VfxS16 mmi_key_code, VfxS16 mmi_key_type, VfxU16 ucs2_value, VfxU32 special_key_flag);
    static void processPenDown(mmi_pen_point_struct pos);
    static void processPenMove(mmi_pen_point_struct pos);
    static void processPenUp(mmi_pen_point_struct pos); 

    /* for mmi_frm_scrn_enter */
    static void exitProcHelper(mmi_scrn_essential_struct* scrn_info);
    static void entryProcHelper(mmi_scrn_essential_struct* scrn_info);

private:
    static VM_P_HANDLE m_phandle;
    static mmi_frm_translate_keyhandler_func_ptr m_keyHandler;
    static mmi_pen_hdlr m_penDownHdlr;
    static mmi_pen_hdlr m_penMoveHdlr;
    static mmi_pen_hdlr m_penUpHdlr;

    static scrFuncPtr m_exitProc;
    static scrFuncPtr m_entryProc;
};

//	extern IVfxService *vfx_get_mre_srv(void);

#endif
