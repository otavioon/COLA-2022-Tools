#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {scalar_t__ minor; scalar_t__ major; } ;
typedef  int /*<<< orphan*/ * PFNGLGETSTRINGPROC ;
typedef  scalar_t__ (* GLADloadproc ) (char*) ;

/* Variables and functions */
 TYPE_1__ GLVersion ; 
 int /*<<< orphan*/  find_coreGL () ; 
 int /*<<< orphan*/  find_extensionsGL () ; 
 int /*<<< orphan*/ * glGetString ; 
 int /*<<< orphan*/  load_GL_3DFX_tbuffer (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_AMD_debug_output (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_AMD_draw_buffers_blend (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_AMD_interleaved_elements (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_AMD_multi_draw_indirect (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_AMD_name_gen_delete (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_AMD_occlusion_query_event (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_AMD_performance_monitor (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_AMD_sample_positions (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_AMD_sparse_texture (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_AMD_stencil_operation_extended (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_AMD_vertex_shader_tessellator (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_APPLE_element_array (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_APPLE_fence (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_APPLE_flush_buffer_range (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_APPLE_object_purgeable (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_APPLE_texture_range (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_APPLE_vertex_array_object (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_APPLE_vertex_array_range (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_APPLE_vertex_program_evaluators (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_ES2_compatibility (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_base_instance (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_bindless_texture (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_blend_func_extended (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_buffer_storage (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_cl_event (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_clear_buffer_object (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_clear_texture (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_color_buffer_float (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_compute_shader (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_compute_variable_group_size (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_copy_buffer (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_copy_image (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_debug_output (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_draw_buffers (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_draw_buffers_blend (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_draw_elements_base_vertex (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_draw_indirect (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_draw_instanced (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_fragment_program (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_framebuffer_no_attachments (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_framebuffer_object (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_geometry_shader4 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_get_program_binary (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_gpu_shader_fp64 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_imaging (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_indirect_parameters (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_instanced_arrays (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_internalformat_query (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_internalformat_query2 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_invalidate_subdata (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_map_buffer_range (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_matrix_palette (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_multi_bind (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_multi_draw_indirect (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_multisample (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_multitexture (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_occlusion_query (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_point_parameters (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_program_interface_query (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_provoking_vertex (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_robustness (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_sample_shading (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_sampler_objects (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_separate_shader_objects (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_shader_atomic_counters (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_shader_image_load_store (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_shader_objects (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_shader_storage_buffer_object (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_shader_subroutine (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_shading_language_include (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_sparse_texture (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_sync (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_tessellation_shader (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_texture_buffer_object (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_texture_buffer_range (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_texture_compression (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_texture_multisample (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_texture_storage (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_texture_storage_multisample (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_texture_view (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_timer_query (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_transform_feedback2 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_transform_feedback3 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_transform_feedback_instanced (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_transpose_matrix (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_uniform_buffer_object (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_vertex_array_object (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_vertex_attrib_64bit (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_vertex_attrib_binding (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_vertex_blend (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_vertex_buffer_object (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_vertex_program (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_vertex_shader (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_vertex_type_2_10_10_10_rev (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_viewport_array (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ARB_window_pos (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ATI_draw_buffers (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ATI_element_array (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ATI_envmap_bumpmap (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ATI_fragment_shader (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ATI_map_object_buffer (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ATI_pn_triangles (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ATI_separate_stencil (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ATI_vertex_array_object (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ATI_vertex_attrib_array_object (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_ATI_vertex_streams (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_bindable_uniform (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_blend_color (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_blend_equation_separate (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_blend_func_separate (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_blend_minmax (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_color_subtable (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_compiled_vertex_array (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_convolution (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_coordinate_frame (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_copy_texture (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_cull_vertex (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_debug_label (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_debug_marker (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_depth_bounds_test (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_direct_state_access (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_draw_buffers2 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_draw_instanced (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_draw_range_elements (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_fog_coord (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_framebuffer_blit (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_framebuffer_multisample (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_framebuffer_object (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_geometry_shader4 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_gpu_program_parameters (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_gpu_shader4 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_histogram (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_index_func (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_index_material (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_light_texture (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_multi_draw_arrays (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_multisample (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_paletted_texture (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_pixel_transform (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_point_parameters (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_polygon_offset (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_provoking_vertex (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_secondary_color (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_separate_shader_objects (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_shader_image_load_store (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_stencil_clear_tag (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_stencil_two_side (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_subtexture (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_texture3D (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_texture_buffer_object (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_texture_integer (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_texture_object (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_texture_perturb_normal (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_timer_query (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_transform_feedback (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_vertex_array (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_vertex_attrib_64bit (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_vertex_shader (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_vertex_weighting (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_EXT_x11_sync_object (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_GREMEDY_frame_terminator (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_GREMEDY_string_marker (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_HP_image_transform (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_IBM_multimode_draw_arrays (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_IBM_static_data (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_IBM_vertex_array_lists (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_INGR_blend_func_separate (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_INTEL_map_texture (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_INTEL_parallel_arrays (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_INTEL_performance_query (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_KHR_debug (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_MESA_resize_buffers (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_MESA_window_pos (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NVX_conditional_render (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_bindless_multi_draw_indirect (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_bindless_texture (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_blend_equation_advanced (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_conditional_render (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_copy_image (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_depth_buffer_float (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_draw_texture (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_evaluators (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_explicit_multisample (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_fence (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_fragment_program (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_framebuffer_multisample_coverage (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_geometry_program4 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_gpu_program4 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_gpu_program5 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_gpu_shader5 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_half_float (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_occlusion_query (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_parameter_buffer_object (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_path_rendering (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_pixel_data_range (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_point_sprite (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_present_video (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_primitive_restart (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_register_combiners (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_register_combiners2 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_shader_buffer_load (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_texture_barrier (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_texture_multisample (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_transform_feedback (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_transform_feedback2 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_vdpau_interop (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_vertex_array_range (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_vertex_attrib_integer_64bit (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_vertex_buffer_unified_memory (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_vertex_program (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_vertex_program4 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_NV_video_capture (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_OES_byte_coordinates (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_OES_fixed_point (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_OES_query_matrix (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_OES_single_precision (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_PGI_misc_hints (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIS_detail_texture (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIS_fog_function (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIS_multisample (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIS_pixel_texture (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIS_point_parameters (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIS_sharpen_texture (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIS_texture4D (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIS_texture_color_mask (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIS_texture_filter4 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIX_async (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIX_flush_raster (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIX_fragment_lighting (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIX_framezoom (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIX_igloo_interface (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIX_instruments (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIX_list_priority (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIX_pixel_texture (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIX_polynomial_ffd (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIX_reference_plane (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIX_sprite (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGIX_tag_sample_buffer (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SGI_color_table (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SUNX_constant_data (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SUN_global_alpha (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SUN_mesh_array (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SUN_triangle_list (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_SUN_vertex (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_VERSION_1_0 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_VERSION_1_1 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_VERSION_1_2 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_VERSION_1_3 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_VERSION_1_4 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_VERSION_1_5 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_VERSION_2_0 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_VERSION_2_1 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_VERSION_3_0 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_VERSION_3_1 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_VERSION_3_2 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_VERSION_3_3 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_VERSION_4_0 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_VERSION_4_1 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_VERSION_4_2 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_VERSION_4_3 (scalar_t__ (*) (char*)) ; 
 int /*<<< orphan*/  load_GL_VERSION_4_4 (scalar_t__ (*) (char*)) ; 

void gladLoadGLLoader(GLADloadproc load) {
	GLVersion.major = 0; GLVersion.minor = 0;
	glGetString = (PFNGLGETSTRINGPROC)load("glGetString");
	if(glGetString == NULL) return;
	find_coreGL();
	load_GL_VERSION_1_0(load);
	load_GL_VERSION_1_1(load);
	load_GL_VERSION_1_2(load);
	load_GL_VERSION_1_3(load);
	load_GL_VERSION_1_4(load);
	load_GL_VERSION_1_5(load);
	load_GL_VERSION_2_0(load);
	load_GL_VERSION_2_1(load);
	load_GL_VERSION_3_0(load);
	load_GL_VERSION_3_1(load);
	load_GL_VERSION_3_2(load);
	load_GL_VERSION_3_3(load);
	load_GL_VERSION_4_0(load);
	load_GL_VERSION_4_1(load);
	load_GL_VERSION_4_2(load);
	load_GL_VERSION_4_3(load);
	load_GL_VERSION_4_4(load);

	find_extensionsGL();
	load_GL_NV_point_sprite(load);
	load_GL_APPLE_element_array(load);
	load_GL_AMD_multi_draw_indirect(load);
	load_GL_SGIX_tag_sample_buffer(load);
	load_GL_ATI_separate_stencil(load);
	load_GL_EXT_texture_buffer_object(load);
	load_GL_ARB_vertex_blend(load);
	load_GL_ARB_program_interface_query(load);
	load_GL_EXT_index_func(load);
	load_GL_NV_shader_buffer_load(load);
	load_GL_EXT_color_subtable(load);
	load_GL_SUNX_constant_data(load);
	load_GL_EXT_multi_draw_arrays(load);
	load_GL_ARB_shader_atomic_counters(load);
	load_GL_NV_conditional_render(load);
	load_GL_MESA_resize_buffers(load);
	load_GL_ARB_texture_view(load);
	load_GL_ARB_map_buffer_range(load);
	load_GL_EXT_convolution(load);
	load_GL_NV_vertex_attrib_integer_64bit(load);
	load_GL_EXT_paletted_texture(load);
	load_GL_ARB_texture_buffer_object(load);
	load_GL_ATI_pn_triangles(load);
	load_GL_SGIX_flush_raster(load);
	load_GL_EXT_light_texture(load);
	load_GL_AMD_draw_buffers_blend(load);
	load_GL_MESA_window_pos(load);
	load_GL_NV_texture_barrier(load);
	load_GL_ARB_vertex_type_2_10_10_10_rev(load);
	load_GL_3DFX_tbuffer(load);
	load_GL_GREMEDY_frame_terminator(load);
	load_GL_ARB_blend_func_extended(load);
	load_GL_EXT_separate_shader_objects(load);
	load_GL_NV_texture_multisample(load);
	load_GL_ARB_shader_objects(load);
	load_GL_ARB_framebuffer_object(load);
	load_GL_ATI_envmap_bumpmap(load);
	load_GL_ATI_map_object_buffer(load);
	load_GL_ARB_robustness(load);
	load_GL_NV_pixel_data_range(load);
	load_GL_EXT_framebuffer_blit(load);
	load_GL_ARB_gpu_shader_fp64(load);
	load_GL_EXT_vertex_weighting(load);
	load_GL_GREMEDY_string_marker(load);
	load_GL_EXT_subtexture(load);
	load_GL_NV_evaluators(load);
	load_GL_SGIS_texture_filter4(load);
	load_GL_AMD_performance_monitor(load);
	load_GL_EXT_stencil_clear_tag(load);
	load_GL_NV_present_video(load);
	load_GL_EXT_gpu_program_parameters(load);
	load_GL_ARB_draw_elements_base_vertex(load);
	load_GL_NV_transform_feedback(load);
	load_GL_NV_fragment_program(load);
	load_GL_AMD_stencil_operation_extended(load);
	load_GL_ARB_instanced_arrays(load);
	load_GL_EXT_polygon_offset(load);
	load_GL_AMD_sparse_texture(load);
	load_GL_NV_fence(load);
	load_GL_ARB_texture_buffer_range(load);
	load_GL_SUN_mesh_array(load);
	load_GL_ARB_vertex_attrib_binding(load);
	load_GL_ARB_framebuffer_no_attachments(load);
	load_GL_ARB_cl_event(load);
	load_GL_OES_single_precision(load);
	load_GL_NV_primitive_restart(load);
	load_GL_SUN_global_alpha(load);
	load_GL_EXT_texture_object(load);
	load_GL_AMD_name_gen_delete(load);
	load_GL_ARB_buffer_storage(load);
	load_GL_APPLE_vertex_program_evaluators(load);
	load_GL_ARB_multi_bind(load);
	load_GL_SGIX_list_priority(load);
	load_GL_NV_vertex_buffer_unified_memory(load);
	load_GL_NV_blend_equation_advanced(load);
	load_GL_SGIS_sharpen_texture(load);
	load_GL_ARB_vertex_program(load);
	load_GL_ARB_vertex_buffer_object(load);
	load_GL_NV_vertex_array_range(load);
	load_GL_SGIX_fragment_lighting(load);
	load_GL_NV_framebuffer_multisample_coverage(load);
	load_GL_EXT_timer_query(load);
	load_GL_NV_bindless_texture(load);
	load_GL_KHR_debug(load);
	load_GL_ATI_vertex_attrib_array_object(load);
	load_GL_EXT_geometry_shader4(load);
	load_GL_EXT_bindable_uniform(load);
	load_GL_ATI_element_array(load);
	load_GL_SGIX_reference_plane(load);
	load_GL_EXT_stencil_two_side(load);
	load_GL_NV_explicit_multisample(load);
	load_GL_IBM_static_data(load);
	load_GL_EXT_texture_perturb_normal(load);
	load_GL_EXT_point_parameters(load);
	load_GL_PGI_misc_hints(load);
	load_GL_ARB_vertex_shader(load);
	load_GL_ARB_tessellation_shader(load);
	load_GL_EXT_draw_buffers2(load);
	load_GL_ARB_vertex_attrib_64bit(load);
	load_GL_AMD_interleaved_elements(load);
	load_GL_ARB_fragment_program(load);
	load_GL_ARB_texture_storage(load);
	load_GL_ARB_copy_image(load);
	load_GL_SGIS_pixel_texture(load);
	load_GL_SGIX_instruments(load);
	load_GL_ARB_shader_storage_buffer_object(load);
	load_GL_EXT_blend_minmax(load);
	load_GL_ARB_base_instance(load);
	load_GL_EXT_texture_integer(load);
	load_GL_ARB_texture_multisample(load);
	load_GL_AMD_vertex_shader_tessellator(load);
	load_GL_ARB_invalidate_subdata(load);
	load_GL_EXT_index_material(load);
	load_GL_INTEL_parallel_arrays(load);
	load_GL_ATI_draw_buffers(load);
	load_GL_SGIX_pixel_texture(load);
	load_GL_ARB_timer_query(load);
	load_GL_NV_parameter_buffer_object(load);
	load_GL_ARB_uniform_buffer_object(load);
	load_GL_NV_transform_feedback2(load);
	load_GL_EXT_blend_color(load);
	load_GL_EXT_histogram(load);
	load_GL_SGIS_point_parameters(load);
	load_GL_EXT_direct_state_access(load);
	load_GL_AMD_sample_positions(load);
	load_GL_NV_vertex_program(load);
	load_GL_NVX_conditional_render(load);
	load_GL_EXT_vertex_shader(load);
	load_GL_EXT_blend_func_separate(load);
	load_GL_APPLE_fence(load);
	load_GL_OES_byte_coordinates(load);
	load_GL_ARB_transpose_matrix(load);
	load_GL_ARB_provoking_vertex(load);
	load_GL_EXT_fog_coord(load);
	load_GL_EXT_vertex_array(load);
	load_GL_EXT_blend_equation_separate(load);
	load_GL_ARB_multi_draw_indirect(load);
	load_GL_NV_copy_image(load);
	load_GL_ARB_transform_feedback2(load);
	load_GL_ARB_transform_feedback3(load);
	load_GL_EXT_debug_marker(load);
	load_GL_EXT_pixel_transform(load);
	load_GL_ATI_fragment_shader(load);
	load_GL_ARB_vertex_array_object(load);
	load_GL_SUN_triangle_list(load);
	load_GL_ARB_transform_feedback_instanced(load);
	load_GL_SGIX_async(load);
	load_GL_INTEL_performance_query(load);
	load_GL_NV_gpu_shader5(load);
	load_GL_ARB_ES2_compatibility(load);
	load_GL_ARB_indirect_parameters(load);
	load_GL_NV_half_float(load);
	load_GL_EXT_coordinate_frame(load);
	load_GL_EXT_compiled_vertex_array(load);
	load_GL_NV_depth_buffer_float(load);
	load_GL_NV_occlusion_query(load);
	load_GL_APPLE_flush_buffer_range(load);
	load_GL_ARB_imaging(load);
	load_GL_ARB_draw_buffers_blend(load);
	load_GL_ARB_clear_buffer_object(load);
	load_GL_ARB_multisample(load);
	load_GL_EXT_debug_label(load);
	load_GL_ARB_sample_shading(load);
	load_GL_INTEL_map_texture(load);
	load_GL_ARB_compute_shader(load);
	load_GL_IBM_vertex_array_lists(load);
	load_GL_ARB_color_buffer_float(load);
	load_GL_ARB_bindless_texture(load);
	load_GL_ARB_window_pos(load);
	load_GL_ARB_internalformat_query(load);
	load_GL_EXT_shader_image_load_store(load);
	load_GL_EXT_copy_texture(load);
	load_GL_NV_register_combiners2(load);
	load_GL_NV_draw_texture(load);
	load_GL_EXT_draw_instanced(load);
	load_GL_ARB_viewport_array(load);
	load_GL_ARB_separate_shader_objects(load);
	load_GL_EXT_depth_bounds_test(load);
	load_GL_HP_image_transform(load);
	load_GL_NV_video_capture(load);
	load_GL_ARB_sampler_objects(load);
	load_GL_ARB_matrix_palette(load);
	load_GL_SGIS_texture_color_mask(load);
	load_GL_ARB_texture_compression(load);
	load_GL_ARB_shader_subroutine(load);
	load_GL_ARB_texture_storage_multisample(load);
	load_GL_EXT_vertex_attrib_64bit(load);
	load_GL_OES_query_matrix(load);
	load_GL_APPLE_texture_range(load);
	load_GL_ARB_copy_buffer(load);
	load_GL_APPLE_object_purgeable(load);
	load_GL_ARB_occlusion_query(load);
	load_GL_SGI_color_table(load);
	load_GL_EXT_gpu_shader4(load);
	load_GL_NV_geometry_program4(load);
	load_GL_AMD_debug_output(load);
	load_GL_ARB_multitexture(load);
	load_GL_SGIX_polynomial_ffd(load);
	load_GL_EXT_provoking_vertex(load);
	load_GL_ARB_point_parameters(load);
	load_GL_ARB_shader_image_load_store(load);
	load_GL_SGIX_framezoom(load);
	load_GL_NV_bindless_multi_draw_indirect(load);
	load_GL_EXT_transform_feedback(load);
	load_GL_NV_gpu_program4(load);
	load_GL_NV_gpu_program5(load);
	load_GL_ARB_geometry_shader4(load);
	load_GL_SGIX_sprite(load);
	load_GL_ARB_get_program_binary(load);
	load_GL_AMD_occlusion_query_event(load);
	load_GL_SGIS_multisample(load);
	load_GL_EXT_framebuffer_object(load);
	load_GL_APPLE_vertex_array_range(load);
	load_GL_NV_register_combiners(load);
	load_GL_ARB_draw_buffers(load);
	load_GL_ARB_clear_texture(load);
	load_GL_ARB_debug_output(load);
	load_GL_EXT_cull_vertex(load);
	load_GL_IBM_multimode_draw_arrays(load);
	load_GL_APPLE_vertex_array_object(load);
	load_GL_SGIS_detail_texture(load);
	load_GL_ARB_draw_instanced(load);
	load_GL_ARB_shading_language_include(load);
	load_GL_INGR_blend_func_separate(load);
	load_GL_NV_path_rendering(load);
	load_GL_ATI_vertex_streams(load);
	load_GL_NV_vdpau_interop(load);
	load_GL_ARB_internalformat_query2(load);
	load_GL_SUN_vertex(load);
	load_GL_SGIX_igloo_interface(load);
	load_GL_ARB_draw_indirect(load);
	load_GL_NV_vertex_program4(load);
	load_GL_SGIS_fog_function(load);
	load_GL_EXT_x11_sync_object(load);
	load_GL_ARB_sync(load);
	load_GL_ARB_compute_variable_group_size(load);
	load_GL_OES_fixed_point(load);
	load_GL_EXT_framebuffer_multisample(load);
	load_GL_SGIS_texture4D(load);
	load_GL_EXT_texture3D(load);
	load_GL_EXT_multisample(load);
	load_GL_EXT_secondary_color(load);
	load_GL_ATI_vertex_array_object(load);
	load_GL_ARB_sparse_texture(load);
	load_GL_EXT_draw_range_elements(load);

	return;
}