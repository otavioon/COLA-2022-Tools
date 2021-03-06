#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
typedef  scalar_t__ u16 ;
struct ci_power_info {int mclk_activity_target; scalar_t__ mclk_stutter_mode_threshold; scalar_t__ mclk_strobe_mode_threshold; scalar_t__ mclk_edc_enable_threshold; scalar_t__ mclk_edc_wr_enable_threshold; int dll_default_on; int /*<<< orphan*/  uvd_enabled; scalar_t__ vddc_phase_shed_control; } ;
struct TYPE_12__ {scalar_t__ vram_type; } ;
struct TYPE_14__ {scalar_t__ entries; } ;
struct TYPE_9__ {int /*<<< orphan*/  phase_shedding_limits_table; TYPE_7__ mvdd_dependency_on_mclk; TYPE_7__ vddci_dependency_on_mclk; TYPE_7__ vddc_dependency_on_mclk; } ;
struct TYPE_10__ {int new_active_crtc_count; TYPE_1__ dyn_state; } ;
struct TYPE_11__ {TYPE_2__ dpm; } ;
struct amdgpu_device {TYPE_4__ gmc; TYPE_3__ pm; } ;
struct TYPE_13__ {int MinVddc; int MinVddci; int MinMvdd; int MinVddcPhases; int EnabledForActivity; int EnabledForThrottle; int DownH; int StutterEnable; int StrobeEnable; int EdcReadEnable; int EdcWriteEnable; int RttEnable; int StrobeRatio; int MclkFrequency; int MpllFuncCntl; int MpllFuncCntl_1; int MpllFuncCntl_2; int MpllAdFuncCntl; int MpllDqFuncCntl; int MclkPwrmgtCntl; int DllCntl; int MpllSs1; int MpllSs2; scalar_t__ ActivityLevel; int /*<<< orphan*/  DisplayWatermark; scalar_t__ VoltageDownH; scalar_t__ UpH; } ;
typedef  TYPE_5__ SMU7_Discrete_MemoryLevel ;

/* Variables and functions */
 scalar_t__ AMDGPU_VRAM_TYPE_GDDR5 ; 
 int DPG_PIPE_STUTTER_CONTROL__STUTTER_ENABLE_MASK ; 
 int /*<<< orphan*/  PPSMC_DISPLAY_WATERMARK_LOW ; 
 int RREG32 (int /*<<< orphan*/ ) ; 
 int VOLTAGE_SCALE ; 
 int ci_calculate_mclk_params (struct amdgpu_device*,scalar_t__,TYPE_5__*,int,int) ; 
 int ci_get_ddr3_mclk_frequency_ratio (scalar_t__) ; 
 int ci_get_dependency_volt_by_clk (struct amdgpu_device*,TYPE_7__*,scalar_t__,int*) ; 
 int ci_get_mclk_frequency_ratio (scalar_t__,int) ; 
 struct ci_power_info* ci_get_pi (struct amdgpu_device*) ; 
 int /*<<< orphan*/  ci_populate_phase_value_based_on_mclk (struct amdgpu_device*,int /*<<< orphan*/ *,scalar_t__,int*) ; 
 scalar_t__ cpu_to_be16 (scalar_t__) ; 
 void* cpu_to_be32 (int) ; 
 int /*<<< orphan*/  mmDPG_PIPE_STUTTER_CONTROL ; 
 int /*<<< orphan*/  mmMC_SEQ_MISC5 ; 
 int /*<<< orphan*/  mmMC_SEQ_MISC6 ; 
 int /*<<< orphan*/  mmMC_SEQ_MISC7 ; 

__attribute__((used)) static int ci_populate_single_memory_level(struct amdgpu_device *adev,
					   u32 memory_clock,
					   SMU7_Discrete_MemoryLevel *memory_level)
{
	struct ci_power_info *pi = ci_get_pi(adev);
	int ret;
	bool dll_state_on;

	if (adev->pm.dpm.dyn_state.vddc_dependency_on_mclk.entries) {
		ret = ci_get_dependency_volt_by_clk(adev,
						    &adev->pm.dpm.dyn_state.vddc_dependency_on_mclk,
						    memory_clock, &memory_level->MinVddc);
		if (ret)
			return ret;
	}

	if (adev->pm.dpm.dyn_state.vddci_dependency_on_mclk.entries) {
		ret = ci_get_dependency_volt_by_clk(adev,
						    &adev->pm.dpm.dyn_state.vddci_dependency_on_mclk,
						    memory_clock, &memory_level->MinVddci);
		if (ret)
			return ret;
	}

	if (adev->pm.dpm.dyn_state.mvdd_dependency_on_mclk.entries) {
		ret = ci_get_dependency_volt_by_clk(adev,
						    &adev->pm.dpm.dyn_state.mvdd_dependency_on_mclk,
						    memory_clock, &memory_level->MinMvdd);
		if (ret)
			return ret;
	}

	memory_level->MinVddcPhases = 1;

	if (pi->vddc_phase_shed_control)
		ci_populate_phase_value_based_on_mclk(adev,
						      &adev->pm.dpm.dyn_state.phase_shedding_limits_table,
						      memory_clock,
						      &memory_level->MinVddcPhases);

	memory_level->EnabledForActivity = 1;
	memory_level->EnabledForThrottle = 1;
	memory_level->UpH = 0;
	memory_level->DownH = 100;
	memory_level->VoltageDownH = 0;
	memory_level->ActivityLevel = (u16)pi->mclk_activity_target;

	memory_level->StutterEnable = false;
	memory_level->StrobeEnable = false;
	memory_level->EdcReadEnable = false;
	memory_level->EdcWriteEnable = false;
	memory_level->RttEnable = false;

	memory_level->DisplayWatermark = PPSMC_DISPLAY_WATERMARK_LOW;

	if (pi->mclk_stutter_mode_threshold &&
	    (memory_clock <= pi->mclk_stutter_mode_threshold) &&
	    (!pi->uvd_enabled) &&
	    (RREG32(mmDPG_PIPE_STUTTER_CONTROL) & DPG_PIPE_STUTTER_CONTROL__STUTTER_ENABLE_MASK) &&
	    (adev->pm.dpm.new_active_crtc_count <= 2))
		memory_level->StutterEnable = true;

	if (pi->mclk_strobe_mode_threshold &&
	    (memory_clock <= pi->mclk_strobe_mode_threshold))
		memory_level->StrobeEnable = 1;

	if (adev->gmc.vram_type == AMDGPU_VRAM_TYPE_GDDR5) {
		memory_level->StrobeRatio =
			ci_get_mclk_frequency_ratio(memory_clock, memory_level->StrobeEnable);
		if (pi->mclk_edc_enable_threshold &&
		    (memory_clock > pi->mclk_edc_enable_threshold))
			memory_level->EdcReadEnable = true;

		if (pi->mclk_edc_wr_enable_threshold &&
		    (memory_clock > pi->mclk_edc_wr_enable_threshold))
			memory_level->EdcWriteEnable = true;

		if (memory_level->StrobeEnable) {
			if (ci_get_mclk_frequency_ratio(memory_clock, true) >=
			    ((RREG32(mmMC_SEQ_MISC7) >> 16) & 0xf))
				dll_state_on = ((RREG32(mmMC_SEQ_MISC5) >> 1) & 0x1) ? true : false;
			else
				dll_state_on = ((RREG32(mmMC_SEQ_MISC6) >> 1) & 0x1) ? true : false;
		} else {
			dll_state_on = pi->dll_default_on;
		}
	} else {
		memory_level->StrobeRatio = ci_get_ddr3_mclk_frequency_ratio(memory_clock);
		dll_state_on = ((RREG32(mmMC_SEQ_MISC5) >> 1) & 0x1) ? true : false;
	}

	ret = ci_calculate_mclk_params(adev, memory_clock, memory_level, memory_level->StrobeEnable, dll_state_on);
	if (ret)
		return ret;

	memory_level->MinVddc = cpu_to_be32(memory_level->MinVddc * VOLTAGE_SCALE);
	memory_level->MinVddcPhases = cpu_to_be32(memory_level->MinVddcPhases);
	memory_level->MinVddci = cpu_to_be32(memory_level->MinVddci * VOLTAGE_SCALE);
	memory_level->MinMvdd = cpu_to_be32(memory_level->MinMvdd * VOLTAGE_SCALE);

	memory_level->MclkFrequency = cpu_to_be32(memory_level->MclkFrequency);
	memory_level->ActivityLevel = cpu_to_be16(memory_level->ActivityLevel);
	memory_level->MpllFuncCntl = cpu_to_be32(memory_level->MpllFuncCntl);
	memory_level->MpllFuncCntl_1 = cpu_to_be32(memory_level->MpllFuncCntl_1);
	memory_level->MpllFuncCntl_2 = cpu_to_be32(memory_level->MpllFuncCntl_2);
	memory_level->MpllAdFuncCntl = cpu_to_be32(memory_level->MpllAdFuncCntl);
	memory_level->MpllDqFuncCntl = cpu_to_be32(memory_level->MpllDqFuncCntl);
	memory_level->MclkPwrmgtCntl = cpu_to_be32(memory_level->MclkPwrmgtCntl);
	memory_level->DllCntl = cpu_to_be32(memory_level->DllCntl);
	memory_level->MpllSs1 = cpu_to_be32(memory_level->MpllSs1);
	memory_level->MpllSs2 = cpu_to_be32(memory_level->MpllSs2);

	return 0;
}