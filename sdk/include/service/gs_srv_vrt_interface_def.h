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
 
#if defined(__cplusplus)
extern "C"
{
#endif

#include "vrt_datatype.h"
#include "vrt_srv_adp_base.h"
#include "vrt_srv_adp_gdi.h"
#include "vrt_srv_adp_str.h"
#include "vrt_srv_adp_sys.h"
#include "vrt_system.h"

typedef void *vrt_cache_allocator_handle;

typedef struct _vrt_frame_cache_struct vrt_frame_cache_struct;

#if defined(__cplusplus)
}
#endif

#include "gs_idef.h"


/*****************************************************************************
 * Define
 *****************************************************************************/
 
DEF_INTERFACE(IVrtService, GS_IBase)
    DEF_METHODS_GS_IBase(IVrtService)  
    DEF_METHOD0(IVrtService, vrt_bool, gdi_lt_projective_transform_hw_support)   
    DEF_METHOD1(IVrtService, void, gdi_layer_push_and_set_active, gdi_handle, handle)   
    DEF_METHOD1(IVrtService, gdi_result, gdi_layer_get_buffer_ptr, vrt_u8 **, buf_ptr) 
    DEF_METHOD2(IVrtService, gdi_result, gdi_layer_get_dimension, vrt_s32 *, width, vrt_s32 *, height) 
    DEF_METHOD0(IVrtService, void, gdi_layer_pop_and_restore_active)   
    DEF_METHOD0(IVrtService, int, gdi_layer_get_bit_per_pixel)   
    DEF_METHOD1(IVrtService, void, gdi_layer_set_active, gdi_handle, handle)   
    DEF_METHOD8(IVrtService, gdi_result, gdi_layer_create_cf_using_outside_memory, gdi_color_format, cf, vrt_s32, offset_x, vrt_s32, offset_y, vrt_s32, width, vrt_s32, height, gdi_handle *, handle_ptr, vrt_u8 *, outside_memory, vrt_s32, outside_memory_size)                       
    DEF_METHOD5(IVrtService, void, gdi_draw_line, vrt_s32, x1, vrt_s32, y1, vrt_s32, x2, vrt_s32, y2, gdi_color, line_color)    
    DEF_METHOD4(IVrtService, void, gdi_layer_get_clip, vrt_s32 *, x1, vrt_s32 *, y1, vrt_s32 *, x2, vrt_s32 *, y2)    
    DEF_METHOD5(IVrtService, void, gdi_draw_rect, vrt_s32, x1, vrt_s32, y1, vrt_s32, x2, vrt_s32, y2, gdi_color, frame_color)   
    DEF_METHOD2(IVrtService, gdi_result, gdi_layer_set_position, vrt_s32, offset_x, vrt_s32, offset_y) 
    DEF_METHOD2(IVrtService, gdi_result, gdi_layer_set_source_key, vrt_bool, source_key_enable, gdi_color, source_key_value) 
    DEF_METHOD2(IVrtService, gdi_result, gdi_layer_set_opacity, vrt_bool, opacity_enable, vrt_u8, opacity_value) 
    DEF_METHOD0(IVrtService, void, gdi_layer_push_clip) 
    DEF_METHOD2(IVrtService, gdi_result, gdi_layer_get_source_key, vrt_u8 *, source_key_enable, gdi_color *, source_key_value) 
    DEF_METHOD0(IVrtService, void, gdi_layer_pop_clip)  
    DEF_METHOD8(IVrtService, void, mre_gdi_layer_blt, gdi_handle, h1, gdi_handle, h2, gdi_handle, h3, gdi_handle, h4, vrt_s32, x1, vrt_s32, y1, vrt_s32, x2, vrt_s32, y2) 
    DEF_METHOD1(IVrtService, void, gdi_push_and_set_alpha_blending_source_layer, gdi_handle, handle) 
    DEF_METHOD3(IVrtService, gdi_result, mre_gdi_image_draw, vrt_s32, x, vrt_s32, y, vrt_u8 *, img_src) 
    DEF_METHOD3(IVrtService, gdi_result, mre_gdi_image_draw_file, vrt_s32, x, vrt_s32, y, vrt_u8 *, img_name) 
    DEF_METHOD0(IVrtService, void, gdi_pop_and_restore_alpha_blending_source_layer) 
    DEF_METHOD1(IVrtService, gdi_result, gdi_layer_free, gdi_handle, handle) 
    DEF_METHOD0(IVrtService, void, gdi_layer_reset_clip) 
    DEF_METHOD1(IVrtService, void, gdi_get_alpha_blending_source_layer, gdi_handle *, src_layer_handle) 
    DEF_METHOD2(IVrtService, void, gdi_layer_resize, vrt_s32, width, vrt_s32, height) 
    DEF_METHOD1(IVrtService, gdi_handle, gdi_set_alpha_blending_source_layer, gdi_handle, src_layer_handle) 
    DEF_METHOD1(IVrtService, void, gdi_layer_get_active, gdi_handle *, handle_ptr) 
    DEF_METHOD3(IVrtService, void, gdi_act_put_pixel, vrt_s32, x, vrt_s32, y, gdi_color, c) 
    DEF_METHOD5(IVrtService, void, gdi_draw_antialiasing_line, vrt_s32, x1, vrt_s32, y1, vrt_s32, x2, vrt_s32, y2, gdi_color, line_color) 
    DEF_METHOD3(IVrtService, gdi_result, gdi_image_get_dimension, vrt_u8 *, image_ptr, vrt_s32 *, width, vrt_s32 *, height) 
    DEF_METHOD3(IVrtService, gdi_result, gdi_image_get_dimension_file, vrt_s8  *, image_name, vrt_s32 *, width, vrt_s32 *, height) 
    DEF_METHOD1(IVrtService, gdi_result, gdi_layer_get_base_handle, gdi_handle *, handle_ptr) 
    DEF_METHOD0(IVrtService, vrt_u8, gdi_lcd_get_rotate) 
    DEF_METHOD1(IVrtService, void, gdi_lcd_set_rotate_by_layer, vrt_bool, rotate_by_layer) 
    DEF_METHOD4(IVrtService, gdi_result, mre_gdi_layer_set_blt_layer, gdi_handle, handle0, gdi_handle, handle1, gdi_handle, handle2, gdi_handle, handle3) 
    DEF_METHOD1(IVrtService, void, gdi_image_codec_set_flag_begin, vrt_u32, flag) 
    DEF_METHOD2(IVrtService, gdi_result, gdi_image_get_frame_count_file, vrt_u8 *, image_ptr, vrt_s32 *, frame_count) 
    DEF_METHOD2(IVrtService, gdi_result, gdi_image_get_frame_count, vrt_u8 *, image_ptr, vrt_s32 *, frame_count) 
    DEF_METHOD6(IVrtService, gdi_result, mre_gdi_image_draw_resized_file_frames, vrt_s32, x, vrt_s32, y, vrt_s32, width, vrt_s32, height, vrt_u8*, image_name, vrt_u32, frame_no) 
    DEF_METHOD4(IVrtService, gdi_result, mre_gdi_image_draw_file_frames, vrt_s32, x, vrt_s32, y, vrt_u8*, image_name, vrt_u32, frame_no) 
    DEF_METHOD6(IVrtService, gdi_result, mre_gdi_image_draw_resized_frames, vrt_s32, x, vrt_s32, y, vrt_s32, width, vrt_s32, height, vrt_u8*, image_ptr, vrt_u32, frame_no)  
    DEF_METHOD4(IVrtService, gdi_result, mre_gdi_image_draw_frames, vrt_s32, x, vrt_s32, y, vrt_u8*, image_ptr, vrt_u32, frame_no) 
    DEF_METHOD0(IVrtService, vrt_u8, gdi_anim_get_delay) 
    DEF_METHOD0(IVrtService, void, gdi_image_codec_set_flag_end) 
    DEF_METHOD2(IVrtService, gdi_result, gdi_layer_get_opacity, vrt_u8 *, opacity_enable, vrt_u8 *, opacity_value) 
    DEF_METHOD2(IVrtService, gdi_result, gdi_layer_get_position, vrt_s32 *, offset_x, vrt_s32 *, offset_y) 
    DEF_METHOD1(IVrtService, vrt_u16, gdi_image_get_type_from_file, vrt_s8 *, file_name) 
    DEF_METHOD1(IVrtService, gdi_result, gdi_layer_clear, gdi_color, bg_color) 
    DEF_METHOD5(IVrtService, void, gdi_draw_solid_rect, vrt_s32, x1, vrt_s32, y1, vrt_s32, x2, vrt_s32, y2, gdi_color, rect_color) 
    DEF_METHOD4(IVrtService, void, gdi_layer_set_clip, vrt_s32, x1, vrt_s32, y1, vrt_s32, x2, vrt_s32, y2) 
    DEF_METHOD14(IVrtService, gdi_result, gdi_2d_linear_transfrom,    
                                  float *, matrix, 
                                  gdi_handle, src_layer_handle, 
                                  vrt_s32, src_rect_x,  
                                  vrt_s32, src_rect_y,  
                                  vrt_s32, src_rect_w,  
                                  vrt_s32, src_rect_h,  
                                  vrt_s32, dst_rect_x, 
                                  vrt_s32, dst_rect_y, 
                                  vrt_s32, dst_rect_w, 
                                  vrt_s32, dst_rect_h, 
                                  GDI_LT_SRC_KEY_EDGE_FILTER_ENUM, edge_filter_mode, 
                                  vrt_u32, edge_filter_color, 
                                  GDI_LT_SAMPLE_MODE_ENUM, sample_mode, 
                                  vrt_u32, flag) 
    DEF_METHOD9(IVrtService, gdi_result, gdi_lt_projective_transform, gdi_lt_matrix_struct *, matrix,  
                gdi_handle, src_layer_handle, 
                vrt_s32, src_rect_x, 
                vrt_s32, src_rect_y, 
                vrt_s32, src_rect_w, 
                vrt_s32, src_rect_h, 
                GDI_LT_SRC_KEY_EDGE_FILTER_ENUM, edge_filter_mode, 
                vrt_u32, edge_filter_color, 
                GDI_LT_SAMPLE_MODE_ENUM, sample_mode) 
    DEF_METHOD1(IVrtService, vrt_bool, gdi_layer_set_background, gdi_color, c) 
    DEF_METHOD4(IVrtService, gdi_result, mre_gdi_layer_flatten_with_clipping, gdi_handle, handle0, gdi_handle, handle1, gdi_handle, handle2, gdi_handle, handle3) 
    
    DEF_METHOD1(IVrtService, void, gdi_lcd_set_active, gdi_handle, lcd_handle) 
    DEF_METHOD1(IVrtService, void, gdi_lcd_get_active, gdi_handle*, lcd_handle_ptr) 

    DEF_METHOD2(IVrtService, vrt_u32, gdi_image_abm_get_info, vrt_u8*, data_ptr, vrt_bool, is_file)
    DEF_METHOD2(IVrtService, vrt_u32, gdi_image_ab2_get_info, vrt_u8*, data_ptr, vrt_bool, is_file)
    DEF_METHOD0(IVrtService, vrt_bool, gdi_layer_flatten_is_ready) 
    DEF_METHOD4(IVrtService, gdi_result, mre_gdi_layer_get_blt_layer, gdi_handle*, handle0, gdi_handle*, handle1, gdi_handle*, handle2, gdi_handle*, handle3)
    DEF_METHOD4(IVrtService, gdi_result, mre_gdi_layer_flatten, gdi_handle, handle0, gdi_handle, handle1, gdi_handle, handle2, gdi_handle, handle3)
    DEF_METHOD1(IVrtService, vrt_bool, gdi_2d_query_hw_capability, GDI_G2D_CAPABILITY_ENUM, capability)

    DEF_METHOD1(IVrtService, void, mmi_fe_set_text_color, mmi_fe_color, c) 
    DEF_METHOD2(IVrtService, vrt_u8, SetFont, stFontAttribute, Font, vrt_u8, arrCount) 
    DEF_METHOD1(IVrtService, void, mmi_fe_set_text_border_color, mmi_fe_color, c) 
    DEF_METHOD5(IVrtService, vrt_u32, mmi_fe_show_string_bordered_n_baseline, 
                               vrt_u32, x_unsigned, 
                               vrt_u32, y_unsigned, 
                               vrt_u8 *, string, 
                               vrt_s32, len, 
                               vrt_s32, baseline) 
    DEF_METHOD6(IVrtService, mmi_font_engine_error_message_enum, mmi_font_engine_show_truncated_text, vrt_s32, x, vrt_s32, y, vrt_s32, xwidth, vrt_u8 *, st, vrt_u8 *, truncated_symbol, vrt_bool, bordered) 
    DEF_METHOD6(IVrtService, vrt_u32, ShowStringBordered, vrt_s32, x, vrt_s32, y, stFontAttribute, gdi_font, vrt_u32, bg, vrt_u8 *, str, vrt_u32, lh) 
    DEF_METHOD6(IVrtService, vrt_u32, ShowString, vrt_s32, x, vrt_s32, y, stFontAttribute, gdi_font, vrt_u32, bg, vrt_u8 *, str, vrt_u32, lh) 
    DEF_METHOD5(IVrtService, vrt_u32, mmi_fe_show_string_n_baseline, vrt_u32, x_unsigned, vrt_u32, y_unsigned, vrt_u8 *, string, vrt_s32, len, vrt_s32, baseline) 
    DEF_METHOD9(IVrtService, void, gdi_util_fit_box, 
                                vrt_s32, mode, 
                                vrt_s32, bbox_width, 
                                vrt_s32, bbox_height, 
                                vrt_s32, src_width, 
                                vrt_s32, src_height, 
                                vrt_s32 *, offset_x, 
                                vrt_s32 *, offset_y, 
                                vrt_s32 *, dest_width, 
                                vrt_s32 *, dest_height) 
    DEF_METHOD0(IVrtService, void, gdi_lock) 
    DEF_METHOD0(IVrtService, void, gdi_unlock) 
    DEF_METHOD0(IVrtService, vrt_u32, get_max_med_jpg_dec_ext_mem_size) 
    DEF_METHOD4(IVrtService, void, font_measure_str, const vrt_font_struct *, font, const vrt_wchar *, string, vrt_s32 *, width, vrt_s32 *, height) 
    DEF_METHOD5(IVrtService, void, gdi_act_color_to_rgb, vrt_u32 *, a, vrt_u32 *, r, vrt_u32 *, g, vrt_u32 *, b, gdi_color, c) 
    DEF_METHOD4(IVrtService, gdi_color, gdi_act_color_from_rgb, vrt_u32, a, vrt_u32, r, vrt_u32, g, vrt_u32, b) 
    DEF_METHOD1(IVrtService, vrt_wchar, app_ucs2_towupper, vrt_wchar, wc)
    DEF_METHOD1(IVrtService, vrt_s32, app_ucs2_strlen, const vrt_s8 *, arrOut)
    DEF_METHOD2(IVrtService, vrt_s32, app_ucs2_strcmp, const vrt_s8 *, string1, const vrt_s8 *, string2)
    DEF_METHOD2(IVrtService, vrt_s8 *, app_ucs2_strcpy, vrt_s8 *, strDestination, const vrt_s8 *, strSource)
    //DEF_METHOD1(IVrtService, vrt_s32, mmi_ucs2strlen, const vrt_char *, arrOut)
    //DEF_METHOD2(IVrtService, vrt_s32, mmi_ucs2cmp, const vrt_char *, string1, const vrt_char *, string2)
    //DEF_METHOD2(IVrtService, vrt_char *, mmi_ucs2cpy, vrt_char *, strDestination, const vrt_char *, strSource)
    //DEF_METHOD3(IVrtService, vrt_u16, mmi_asc_n_to_ucs2, vrt_char *, pOutBuffer, vrt_char *, pInBuffer, vrt_u32, len)
    DEF_METHOD3(IVrtService, void *, vrt_srv_kal_adm_alloc_cacheable, void *, adm_id, vrt_u32, size, vrt_u32, option)
    DEF_METHOD3(IVrtService, void *, vrt_srv_kal_adm_alloc_c_topmost, void *, adm_id, vrt_u32, size, vrt_u32, a)
    DEF_METHOD2(IVrtService, void *, vrt_srv_kal_adm_alloc, void *, adm_id, vrt_u32, size)
    DEF_METHOD3(IVrtService, void *, vrt_srv_kal_adm_alloc_topmost, void *, adm_id, vrt_u32, size, vrt_u32, a)
    DEF_METHOD2(IVrtService, void, vrt_srv_kal_adm_free, void *, adm_id, void *, mem_addr)
    DEF_METHOD2(IVrtService, kal_status, kal_take_sem, kal_semid, ext_sem_id_ptr, kal_wait_mode, wait_mode)
    DEF_METHOD4(IVrtService, void *, mre_kal_adm_create, void *, mem_addr, vrt_u32, size, vrt_u32 *, subpool_size, vrt_bool, islogging)
    DEF_METHOD1(IVrtService, void, kal_give_sem, kal_semid, ext_sem_id_ptr)
    DEF_METHOD1(IVrtService, kal_status, mre_kal_adm_delete, void *, adm_id)
    DEF_METHOD1(IVrtService, vrt_u32, kal_adm_get_max_alloc_size, void *, adm_id)
    DEF_METHOD1(IVrtService, vrt_u32, kal_adm_get_total_left_size, void *, adm_id)
    DEF_METHOD1(IVrtService, vrt_u32, kal_milli_secs_to_ticks, vrt_u32, ms)
    DEF_METHOD1(IVrtService, void, kal_get_time, vrt_u32 *, ticks_ptr)
    DEF_METHOD1(IVrtService, vrt_u32, kal_ticks_to_milli_secs, vrt_u32, ticks)
    DEF_METHOD0(IVrtService, void *, kal_get_task_self_id)
    DEF_METHOD1(IVrtService, void *, kal_adm_check_integrity, void*, adm_id)
    DEF_METHOD1(IVrtService, void, vrt_srv_mmi_frm_scrmem_free, void *, mem_ptr)
    DEF_METHOD1(IVrtService, void *, vrt_srv_med_alloc_ext_mem, vrt_s32, size)
    DEF_METHOD1(IVrtService, void *, vrt_srv_med_alloc_ext_mem_cacheable, vrt_s32, size)
    // DEF_METHOD2(IVrtService, void *, vrt_srv_med_alloc_temp_ext_mem, vrt_s32, size, med_callback, callback)
    DEF_METHOD1(IVrtService, void *, vrt_srv_med_alloc_int_mem, vrt_s32, size)
    DEF_METHOD1(IVrtService, void,  vrt_srv_med_free_ext_mem, void **, pointer)
    DEF_METHOD1(IVrtService, void, vrt_srv_med_free_temp_ext_mem, void **, pointer)
    DEF_METHOD1(IVrtService, void, vrt_srv_med_free_int_mem, void **, pointer)
    DEF_METHOD0(IVrtService, unsigned long int, vrt_srv_med_ext_left_size)
    DEF_METHOD2(IVrtService, vrt_bool, vrt_srv_INT_QueryIsCachedRAM, vrt_u32, addr, vrt_u32, len)
    // DEF_METHOD2(IVrtService, void, vrt_srv_set_protocol_event_handler, void *, func, vrt_u16, event)
    DEF_METHOD0(IVrtService, mmi_frm_screen_rotate_enum, mmi_frm_get_screen_rotate)
    DEF_METHOD1(IVrtService, void, mmi_frm_screen_rotate, mmi_frm_screen_rotate_enum, rotation)
    DEF_METHOD0(IVrtService, vrt_bool, vrt_srv_check_mmi_has_gdi_lock)
    DEF_METHOD0(IVrtService, vrt_msec_type, vrt_srv_get_sys_time)
    DEF_METHOD2(IVrtService, void, vrt_srv_get_main_screen_info, vrt_size_struct *, dimension, vrt_color_type_enum *, color_format)
    DEF_METHOD1(IVrtService, vrt_u8 *, vrt_srv_get_image, vrt_s32, res_id)
    DEF_METHOD0(IVrtService, vrt_bool, vrt_srv_is_r2l_mode)
    DEF_METHOD1(IVrtService, void *, vrt_srv_get_env_info, vrt_sys_env_info_id_enum, info_id)
    DEF_METHOD0(IVrtService, vrt_bool, vrt_srv_mdi_tvout_is_enable)
    DEF_METHOD3(IVrtService, void, mre_vrt_init, vrt_flag_type, flags, vrt_u16, app_id, vrt_u32, asm_cache_size)
    DEF_METHOD1(IVrtService, void, mre_vrt_deinit, vrt_flag_type, flags)
    DEF_METHOD2(IVrtService, void, mre_vrt_init_instance, void*, cntx, vrt_render_draw_frame_func_ptr_type, draw_frame_func_ptr)
    DEF_METHOD1(IVrtService, void, mre_vrt_request_rsp, void*, msg)
    DEF_METHOD1(IVrtService, void, mre_vrt_resume, vrt_bool, is_blocking)
    DEF_METHOD0(IVrtService, void, mre_vrt_suspend)
    DEF_METHOD0(IVrtService, vrt_bool, mre_vrt_is_running)
    DEF_METHOD0(IVrtService, vrt_bool, mre_vrt_is_idle)
    DEF_METHOD1(IVrtService, void, mre_vrt_deinit_instance, void*, cntx)
    DEF_METHOD2(IVrtService, void, mre_vrt_set_draw_cmd_queue, void*, cntx, void*, cmd_queue)
    DEF_METHOD3(IVrtService, void, mre_vrt_set_timeline_array, void*, cntx, void**, timeline_array, vrt_u32, size)
    DEF_METHOD3(IVrtService, void, mre_vrt_set_resource_array, void*, cntx, void**, resource_array, vrt_u32, size)
    DEF_METHOD5(IVrtService, void, mre_vrt_set_frame_property_array, void*, cntx, void**, frame_property_array, vrt_u32, size, vrt_u32, free_size, vrt_u32, total_size)
    DEF_METHOD1(IVrtService, void, mre_vrt_add_dirty_rect, vrt_rect_struct*, dirty_rect)
    DEF_METHOD1(IVrtService, void, mre_vrt_init_cache_pool, vrt_u32, mem_pool_size)
    DEF_METHOD2(IVrtService, vrt_frame_cache_struct *, mre_vrt_cache_alloc, vrt_cache_allocator_handle, allocator, vrt_u32, size)
    DEF_METHOD2(IVrtService, void, mre_vrt_cache_free, vrt_cache_allocator_handle, allocator, vrt_frame_cache_struct*, frame_cache)
    DEF_METHOD3(IVrtService, void, mre_vrt_cache_asm_attach, vrt_cache_allocator_handle, allocator, void*, mem_pool_ptr, vrt_u32, size)
    DEF_METHOD3(IVrtService, void, mre_vrt_cache_user_attach, vrt_cache_allocator_handle, allocator, void*, mem_pool_ptr, vrt_u32, size)
    DEF_METHOD2(IVrtService, void, mre_vrt_cache_user_detach, vrt_cache_allocator_handle, allocator, void*, mem_pool_ptr)
    DEF_METHOD3(IVrtService, vrt_cache_allocator_handle, mre_vrt_create_cache_allocator, vrt_u32, request_size, vrt_u16, app_id, vrt_u32, asm_pool_size)
    DEF_METHOD1(IVrtService, void, mre_vrt_destroy_cache_allocator, vrt_cache_allocator_handle, allocator)
    DEF_METHOD2(IVrtService, vrt_frame_cache_struct *, mre_vrt_cache_find_by_key, vrt_cache_allocator_handle, allocator, vrt_u32, key)
    DEF_METHOD1(IVrtService, void, mre_vrt_cache_free_all, vrt_cache_allocator_handle, allocator)
    DEF_METHOD1(IVrtService, vrt_u32, mre_vrt_cache_med_get_pool_size, vrt_cache_allocator_handle, allocator)
    DEF_METHOD1(IVrtService, vrt_u32, mre_vrt_cache_get_max_alloc_size, vrt_cache_allocator_handle, allocator)
    DEF_METHOD1(IVrtService, vrt_u32, mre_vrt_cache_get_total_alloc_size, vrt_cache_allocator_handle, allocator)
    DEF_METHOD0(IVrtService, void, mre_vrt_check_and_restore_cache_pool)
    DEF_METHOD0(IVrtService, vrt_mem_provider_handle, mre_vrt_cahce_alloc_get_provider)
    DEF_METHOD4(IVrtService, void, mre_vrt_timer_start, vrt_msec_type, time, vrt_timer_callback_funcptr_type, timer_callback, void *, arg0, void *, arg1)
    DEF_METHOD1(IVrtService, void, mre_vrt_timer_stop, void *, arg)
    DEF_METHOD1(IVrtService, void, mre_vrt_adjust_current_frame_time, vrt_msec_type, time)
    DEF_METHOD0(IVrtService, vrt_msec_type, mre_vrt_get_current_frame_time)

    DEF_METHOD1(IVrtService, vrt_u32, vrt_cache_get_main_cache_pool_size, vrt_cache_allocator_handle, allocator)

    DEF_METHOD1(IVrtService, vrt_u32, iul_x_sin_rad, vrt_u32, rad)
    DEF_METHOD1(IVrtService, vrt_u32, iul_x_cos_rad, vrt_u32, rad)

    /* callback */
    DEF_METHOD3(IVrtService, void *, mre_vrt_register_draw_frame_callback, void *, canvas_cntx, void *, callback, void **, user_data)
    DEF_METHOD1(IVrtService, void *, mre_mmi_frm_asm_alloc_anonymous_nc, vrt_u32, size)
    DEF_METHOD1(IVrtService, void, mre_mmi_frm_asm_free_anonymous, void *, ptr)
DEF_INTERFACE_END(IVrtService)
