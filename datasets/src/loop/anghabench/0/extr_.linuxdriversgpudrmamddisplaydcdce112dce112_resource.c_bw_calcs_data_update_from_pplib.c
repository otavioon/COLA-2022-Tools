#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct dm_pp_wm_sets_with_clock_ranges {int num_wm_sets; TYPE_2__* wm_clk_ranges; int /*<<< orphan*/  member_0; } ;
struct dm_pp_clock_levels_with_latency {int num_levels; TYPE_1__* data; int /*<<< orphan*/  member_0; } ;
struct dm_pp_clock_levels {int* clocks_in_khz; int num_levels; int /*<<< orphan*/  member_0; } ;
struct dc {int /*<<< orphan*/  ctx; TYPE_3__* bw_vbios; } ;
struct TYPE_6__ {void* high_yclk; void* mid_yclk; void* low_yclk; void* low_sclk; void* mid6_sclk; void* mid5_sclk; void* mid4_sclk; void* mid3_sclk; void* mid2_sclk; void* mid1_sclk; void* high_sclk; } ;
struct TYPE_5__ {int wm_min_eng_clk_in_khz; int wm_max_eng_clk_in_khz; int wm_min_mem_clk_in_khz; int wm_max_mem_clk_in_khz; int /*<<< orphan*/  wm_set_id; } ;
struct TYPE_4__ {int clocks_in_khz; } ;

/* Variables and functions */
 int /*<<< orphan*/  DM_PP_CLOCK_TYPE_ENGINE_CLK ; 
 int /*<<< orphan*/  DM_PP_CLOCK_TYPE_MEMORY_CLK ; 
 int MEMORY_TYPE_MULTIPLIER ; 
 int /*<<< orphan*/  WM_SET_A ; 
 int /*<<< orphan*/  WM_SET_B ; 
 int /*<<< orphan*/  WM_SET_C ; 
 int /*<<< orphan*/  WM_SET_D ; 
 void* bw_frc_to_fixed (int,int) ; 
 int /*<<< orphan*/  dm_pp_get_clock_levels_by_type (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct dm_pp_clock_levels*) ; 
 int /*<<< orphan*/  dm_pp_get_clock_levels_by_type_with_latency (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct dm_pp_clock_levels_with_latency*) ; 
 int /*<<< orphan*/  dm_pp_notify_wm_clock_changes (int /*<<< orphan*/ ,struct dm_pp_wm_sets_with_clock_ranges*) ; 

__attribute__((used)) static void bw_calcs_data_update_from_pplib(struct dc *dc)
{
	struct dm_pp_clock_levels_with_latency eng_clks = {0};
	struct dm_pp_clock_levels_with_latency mem_clks = {0};
	struct dm_pp_wm_sets_with_clock_ranges clk_ranges = {0};
	struct dm_pp_clock_levels clks = {0};

	/*do system clock  TODO PPLIB: after PPLIB implement,
	 * then remove old way
	 */
	if (!dm_pp_get_clock_levels_by_type_with_latency(
			dc->ctx,
			DM_PP_CLOCK_TYPE_ENGINE_CLK,
			&eng_clks)) {

		/* This is only for temporary */
		dm_pp_get_clock_levels_by_type(
				dc->ctx,
				DM_PP_CLOCK_TYPE_ENGINE_CLK,
				&clks);
		/* convert all the clock fro kHz to fix point mHz */
		dc->bw_vbios->high_sclk = bw_frc_to_fixed(
				clks.clocks_in_khz[clks.num_levels-1], 1000);
		dc->bw_vbios->mid1_sclk  = bw_frc_to_fixed(
				clks.clocks_in_khz[clks.num_levels/8], 1000);
		dc->bw_vbios->mid2_sclk  = bw_frc_to_fixed(
				clks.clocks_in_khz[clks.num_levels*2/8], 1000);
		dc->bw_vbios->mid3_sclk  = bw_frc_to_fixed(
				clks.clocks_in_khz[clks.num_levels*3/8], 1000);
		dc->bw_vbios->mid4_sclk  = bw_frc_to_fixed(
				clks.clocks_in_khz[clks.num_levels*4/8], 1000);
		dc->bw_vbios->mid5_sclk  = bw_frc_to_fixed(
				clks.clocks_in_khz[clks.num_levels*5/8], 1000);
		dc->bw_vbios->mid6_sclk  = bw_frc_to_fixed(
				clks.clocks_in_khz[clks.num_levels*6/8], 1000);
		dc->bw_vbios->low_sclk  = bw_frc_to_fixed(
				clks.clocks_in_khz[0], 1000);

		/*do memory clock*/
		dm_pp_get_clock_levels_by_type(
				dc->ctx,
				DM_PP_CLOCK_TYPE_MEMORY_CLK,
				&clks);

		dc->bw_vbios->low_yclk = bw_frc_to_fixed(
			clks.clocks_in_khz[0] * MEMORY_TYPE_MULTIPLIER, 1000);
		dc->bw_vbios->mid_yclk = bw_frc_to_fixed(
			clks.clocks_in_khz[clks.num_levels>>1] * MEMORY_TYPE_MULTIPLIER,
			1000);
		dc->bw_vbios->high_yclk = bw_frc_to_fixed(
			clks.clocks_in_khz[clks.num_levels-1] * MEMORY_TYPE_MULTIPLIER,
			1000);

		return;
	}

	/* convert all the clock fro kHz to fix point mHz  TODO: wloop data */
	dc->bw_vbios->high_sclk = bw_frc_to_fixed(
		eng_clks.data[eng_clks.num_levels-1].clocks_in_khz, 1000);
	dc->bw_vbios->mid1_sclk  = bw_frc_to_fixed(
		eng_clks.data[eng_clks.num_levels/8].clocks_in_khz, 1000);
	dc->bw_vbios->mid2_sclk  = bw_frc_to_fixed(
		eng_clks.data[eng_clks.num_levels*2/8].clocks_in_khz, 1000);
	dc->bw_vbios->mid3_sclk  = bw_frc_to_fixed(
		eng_clks.data[eng_clks.num_levels*3/8].clocks_in_khz, 1000);
	dc->bw_vbios->mid4_sclk  = bw_frc_to_fixed(
		eng_clks.data[eng_clks.num_levels*4/8].clocks_in_khz, 1000);
	dc->bw_vbios->mid5_sclk  = bw_frc_to_fixed(
		eng_clks.data[eng_clks.num_levels*5/8].clocks_in_khz, 1000);
	dc->bw_vbios->mid6_sclk  = bw_frc_to_fixed(
		eng_clks.data[eng_clks.num_levels*6/8].clocks_in_khz, 1000);
	dc->bw_vbios->low_sclk  = bw_frc_to_fixed(
			eng_clks.data[0].clocks_in_khz, 1000);

	/*do memory clock*/
	dm_pp_get_clock_levels_by_type_with_latency(
			dc->ctx,
			DM_PP_CLOCK_TYPE_MEMORY_CLK,
			&mem_clks);

	/* we don't need to call PPLIB for validation clock since they
	 * also give us the highest sclk and highest mclk (UMA clock).
	 * ALSO always convert UMA clock (from PPLIB)  to YCLK (HW formula):
	 * YCLK = UMACLK*m_memoryTypeMultiplier
	 */
	dc->bw_vbios->low_yclk = bw_frc_to_fixed(
		mem_clks.data[0].clocks_in_khz * MEMORY_TYPE_MULTIPLIER, 1000);
	dc->bw_vbios->mid_yclk = bw_frc_to_fixed(
		mem_clks.data[mem_clks.num_levels>>1].clocks_in_khz * MEMORY_TYPE_MULTIPLIER,
		1000);
	dc->bw_vbios->high_yclk = bw_frc_to_fixed(
		mem_clks.data[mem_clks.num_levels-1].clocks_in_khz * MEMORY_TYPE_MULTIPLIER,
		1000);

	/* Now notify PPLib/SMU about which Watermarks sets they should select
	 * depending on DPM state they are in. And update BW MGR GFX Engine and
	 * Memory clock member variables for Watermarks calculations for each
	 * Watermark Set
	 */
	clk_ranges.num_wm_sets = 4;
	clk_ranges.wm_clk_ranges[0].wm_set_id = WM_SET_A;
	clk_ranges.wm_clk_ranges[0].wm_min_eng_clk_in_khz =
			eng_clks.data[0].clocks_in_khz;
	clk_ranges.wm_clk_ranges[0].wm_max_eng_clk_in_khz =
			eng_clks.data[eng_clks.num_levels*3/8].clocks_in_khz - 1;
	clk_ranges.wm_clk_ranges[0].wm_min_mem_clk_in_khz =
			mem_clks.data[0].clocks_in_khz;
	clk_ranges.wm_clk_ranges[0].wm_max_mem_clk_in_khz =
			mem_clks.data[mem_clks.num_levels>>1].clocks_in_khz - 1;

	clk_ranges.wm_clk_ranges[1].wm_set_id = WM_SET_B;
	clk_ranges.wm_clk_ranges[1].wm_min_eng_clk_in_khz =
			eng_clks.data[eng_clks.num_levels*3/8].clocks_in_khz;
	/* 5 GHz instead of data[7].clockInKHz to cover Overdrive */
	clk_ranges.wm_clk_ranges[1].wm_max_eng_clk_in_khz = 5000000;
	clk_ranges.wm_clk_ranges[1].wm_min_mem_clk_in_khz =
			mem_clks.data[0].clocks_in_khz;
	clk_ranges.wm_clk_ranges[1].wm_max_mem_clk_in_khz =
			mem_clks.data[mem_clks.num_levels>>1].clocks_in_khz - 1;

	clk_ranges.wm_clk_ranges[2].wm_set_id = WM_SET_C;
	clk_ranges.wm_clk_ranges[2].wm_min_eng_clk_in_khz =
			eng_clks.data[0].clocks_in_khz;
	clk_ranges.wm_clk_ranges[2].wm_max_eng_clk_in_khz =
			eng_clks.data[eng_clks.num_levels*3/8].clocks_in_khz - 1;
	clk_ranges.wm_clk_ranges[2].wm_min_mem_clk_in_khz =
			mem_clks.data[mem_clks.num_levels>>1].clocks_in_khz;
	/* 5 GHz instead of data[2].clockInKHz to cover Overdrive */
	clk_ranges.wm_clk_ranges[2].wm_max_mem_clk_in_khz = 5000000;

	clk_ranges.wm_clk_ranges[3].wm_set_id = WM_SET_D;
	clk_ranges.wm_clk_ranges[3].wm_min_eng_clk_in_khz =
			eng_clks.data[eng_clks.num_levels*3/8].clocks_in_khz;
	/* 5 GHz instead of data[7].clockInKHz to cover Overdrive */
	clk_ranges.wm_clk_ranges[3].wm_max_eng_clk_in_khz = 5000000;
	clk_ranges.wm_clk_ranges[3].wm_min_mem_clk_in_khz =
			mem_clks.data[mem_clks.num_levels>>1].clocks_in_khz;
	/* 5 GHz instead of data[2].clockInKHz to cover Overdrive */
	clk_ranges.wm_clk_ranges[3].wm_max_mem_clk_in_khz = 5000000;

	/* Notify PP Lib/SMU which Watermarks to use for which clock ranges */
	dm_pp_notify_wm_clock_changes(dc->ctx, &clk_ranges);
}