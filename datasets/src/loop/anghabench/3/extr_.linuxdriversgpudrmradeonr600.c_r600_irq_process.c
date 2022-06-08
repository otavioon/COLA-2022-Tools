#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_10__ {int rptr; int ptr_mask; int /*<<< orphan*/  lock; int /*<<< orphan*/ * ring; int /*<<< orphan*/  enabled; } ;
struct TYPE_8__ {int high_to_low; int /*<<< orphan*/  work; } ;
struct TYPE_9__ {TYPE_1__ thermal; } ;
struct TYPE_14__ {int vblank_sync; TYPE_2__ dpm; scalar_t__ dpm_enabled; } ;
struct TYPE_11__ {int disp_int; int disp_int_cont; int disp_int_cont2; int hdmi0_status; int hdmi1_status; } ;
struct TYPE_12__ {TYPE_4__ r600; } ;
struct TYPE_13__ {TYPE_5__ stat_regs; int /*<<< orphan*/ * pflip; int /*<<< orphan*/  vblank_queue; int /*<<< orphan*/ * crtc_vblank_int; } ;
struct radeon_device {TYPE_3__ ih; TYPE_7__ pm; int /*<<< orphan*/  audio_work; int /*<<< orphan*/  hotplug_work; TYPE_6__ irq; int /*<<< orphan*/  ddev; int /*<<< orphan*/  msi_enabled; scalar_t__ shutdown; } ;

/* Variables and functions */
 int DC_HPD1_INTERRUPT ; 
 int DC_HPD2_INTERRUPT ; 
 int DC_HPD3_INTERRUPT ; 
 int DC_HPD4_INTERRUPT ; 
 int DC_HPD5_INTERRUPT ; 
 int DC_HPD6_INTERRUPT ; 
 int /*<<< orphan*/  DRM_DEBUG (char*,...) ; 
 int /*<<< orphan*/  DRM_ERROR (char*,int,int) ; 
 int HDMI0_AZ_FORMAT_WTRIG ; 
 int /*<<< orphan*/  IH_RB_RPTR ; 
 int /*<<< orphan*/  IH_RB_WPTR ; 
 int IRQ_HANDLED ; 
 int IRQ_NONE ; 
 int LB_D1_VBLANK_INTERRUPT ; 
 int LB_D1_VLINE_INTERRUPT ; 
 int LB_D2_VBLANK_INTERRUPT ; 
 int LB_D2_VLINE_INTERRUPT ; 
 int /*<<< orphan*/  R600_RING_TYPE_DMA_INDEX ; 
 int /*<<< orphan*/  R600_RING_TYPE_UVD_INDEX ; 
 int /*<<< orphan*/  RADEON_RING_TYPE_GFX_INDEX ; 
 int /*<<< orphan*/  RREG32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WREG32 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ atomic_xchg (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  drm_handle_vblank (int /*<<< orphan*/ ,int) ; 
 int le32_to_cpu (int /*<<< orphan*/ ) ; 
 int r600_get_ih_wptr (struct radeon_device*) ; 
 int /*<<< orphan*/  r600_irq_ack (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_crtc_handle_flip (struct radeon_device*,int) ; 
 int /*<<< orphan*/  radeon_crtc_handle_vblank (struct radeon_device*,int) ; 
 int /*<<< orphan*/  radeon_fence_process (struct radeon_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  radeon_use_pflipirq ; 
 int /*<<< orphan*/  rmb () ; 
 int /*<<< orphan*/  schedule_delayed_work (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  schedule_work (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

int r600_irq_process(struct radeon_device *rdev)
{
	u32 wptr;
	u32 rptr;
	u32 src_id, src_data;
	u32 ring_index;
	bool queue_hotplug = false;
	bool queue_hdmi = false;
	bool queue_thermal = false;

	if (!rdev->ih.enabled || rdev->shutdown)
		return IRQ_NONE;

	/* No MSIs, need a dummy read to flush PCI DMAs */
	if (!rdev->msi_enabled)
		RREG32(IH_RB_WPTR);

	wptr = r600_get_ih_wptr(rdev);

restart_ih:
	/* is somebody else already processing irqs? */
	if (atomic_xchg(&rdev->ih.lock, 1))
		return IRQ_NONE;

	rptr = rdev->ih.rptr;
	DRM_DEBUG("r600_irq_process start: rptr %d, wptr %d\n", rptr, wptr);

	/* Order reading of wptr vs. reading of IH ring data */
	rmb();

	/* display interrupts */
	r600_irq_ack(rdev);

	while (rptr != wptr) {
		/* wptr/rptr are in bytes! */
		ring_index = rptr / 4;
		src_id = le32_to_cpu(rdev->ih.ring[ring_index]) & 0xff;
		src_data = le32_to_cpu(rdev->ih.ring[ring_index + 1]) & 0xfffffff;

		switch (src_id) {
		case 1: /* D1 vblank/vline */
			switch (src_data) {
			case 0: /* D1 vblank */
				if (!(rdev->irq.stat_regs.r600.disp_int & LB_D1_VBLANK_INTERRUPT))
					DRM_DEBUG("IH: D1 vblank - IH event w/o asserted irq bit?\n");

				if (rdev->irq.crtc_vblank_int[0]) {
					drm_handle_vblank(rdev->ddev, 0);
					rdev->pm.vblank_sync = true;
					wake_up(&rdev->irq.vblank_queue);
				}
				if (atomic_read(&rdev->irq.pflip[0]))
					radeon_crtc_handle_vblank(rdev, 0);
				rdev->irq.stat_regs.r600.disp_int &= ~LB_D1_VBLANK_INTERRUPT;
				DRM_DEBUG("IH: D1 vblank\n");

				break;
			case 1: /* D1 vline */
				if (!(rdev->irq.stat_regs.r600.disp_int & LB_D1_VLINE_INTERRUPT))
				    DRM_DEBUG("IH: D1 vline - IH event w/o asserted irq bit?\n");

				rdev->irq.stat_regs.r600.disp_int &= ~LB_D1_VLINE_INTERRUPT;
				DRM_DEBUG("IH: D1 vline\n");

				break;
			default:
				DRM_DEBUG("Unhandled interrupt: %d %d\n", src_id, src_data);
				break;
			}
			break;
		case 5: /* D2 vblank/vline */
			switch (src_data) {
			case 0: /* D2 vblank */
				if (!(rdev->irq.stat_regs.r600.disp_int & LB_D2_VBLANK_INTERRUPT))
					DRM_DEBUG("IH: D2 vblank - IH event w/o asserted irq bit?\n");

				if (rdev->irq.crtc_vblank_int[1]) {
					drm_handle_vblank(rdev->ddev, 1);
					rdev->pm.vblank_sync = true;
					wake_up(&rdev->irq.vblank_queue);
				}
				if (atomic_read(&rdev->irq.pflip[1]))
					radeon_crtc_handle_vblank(rdev, 1);
				rdev->irq.stat_regs.r600.disp_int &= ~LB_D2_VBLANK_INTERRUPT;
				DRM_DEBUG("IH: D2 vblank\n");

				break;
			case 1: /* D1 vline */
				if (!(rdev->irq.stat_regs.r600.disp_int & LB_D2_VLINE_INTERRUPT))
					DRM_DEBUG("IH: D2 vline - IH event w/o asserted irq bit?\n");

				rdev->irq.stat_regs.r600.disp_int &= ~LB_D2_VLINE_INTERRUPT;
				DRM_DEBUG("IH: D2 vline\n");

				break;
			default:
				DRM_DEBUG("Unhandled interrupt: %d %d\n", src_id, src_data);
				break;
			}
			break;
		case 9: /* D1 pflip */
			DRM_DEBUG("IH: D1 flip\n");
			if (radeon_use_pflipirq > 0)
				radeon_crtc_handle_flip(rdev, 0);
			break;
		case 11: /* D2 pflip */
			DRM_DEBUG("IH: D2 flip\n");
			if (radeon_use_pflipirq > 0)
				radeon_crtc_handle_flip(rdev, 1);
			break;
		case 19: /* HPD/DAC hotplug */
			switch (src_data) {
			case 0:
				if (!(rdev->irq.stat_regs.r600.disp_int & DC_HPD1_INTERRUPT))
					DRM_DEBUG("IH: HPD1 - IH event w/o asserted irq bit?\n");

				rdev->irq.stat_regs.r600.disp_int &= ~DC_HPD1_INTERRUPT;
				queue_hotplug = true;
				DRM_DEBUG("IH: HPD1\n");
				break;
			case 1:
				if (!(rdev->irq.stat_regs.r600.disp_int & DC_HPD2_INTERRUPT))
					DRM_DEBUG("IH: HPD2 - IH event w/o asserted irq bit?\n");

				rdev->irq.stat_regs.r600.disp_int &= ~DC_HPD2_INTERRUPT;
				queue_hotplug = true;
				DRM_DEBUG("IH: HPD2\n");
				break;
			case 4:
				if (!(rdev->irq.stat_regs.r600.disp_int_cont & DC_HPD3_INTERRUPT))
					DRM_DEBUG("IH: HPD3 - IH event w/o asserted irq bit?\n");

				rdev->irq.stat_regs.r600.disp_int_cont &= ~DC_HPD3_INTERRUPT;
				queue_hotplug = true;
				DRM_DEBUG("IH: HPD3\n");
				break;
			case 5:
				if (!(rdev->irq.stat_regs.r600.disp_int_cont & DC_HPD4_INTERRUPT))
					DRM_DEBUG("IH: HPD4 - IH event w/o asserted irq bit?\n");

				rdev->irq.stat_regs.r600.disp_int_cont &= ~DC_HPD4_INTERRUPT;
				queue_hotplug = true;
				DRM_DEBUG("IH: HPD4\n");
				break;
			case 10:
				if (!(rdev->irq.stat_regs.r600.disp_int_cont2 & DC_HPD5_INTERRUPT))
					DRM_DEBUG("IH: HPD5 - IH event w/o asserted irq bit?\n");

				rdev->irq.stat_regs.r600.disp_int_cont2 &= ~DC_HPD5_INTERRUPT;
				queue_hotplug = true;
				DRM_DEBUG("IH: HPD5\n");
				break;
			case 12:
				if (!(rdev->irq.stat_regs.r600.disp_int_cont2 & DC_HPD6_INTERRUPT))
					DRM_DEBUG("IH: HPD6 - IH event w/o asserted irq bit?\n");

				rdev->irq.stat_regs.r600.disp_int_cont2 &= ~DC_HPD6_INTERRUPT;
				queue_hotplug = true;
				DRM_DEBUG("IH: HPD6\n");

				break;
			default:
				DRM_DEBUG("Unhandled interrupt: %d %d\n", src_id, src_data);
				break;
			}
			break;
		case 21: /* hdmi */
			switch (src_data) {
			case 4:
				if (!(rdev->irq.stat_regs.r600.hdmi0_status & HDMI0_AZ_FORMAT_WTRIG))
					DRM_DEBUG("IH: HDMI0 - IH event w/o asserted irq bit?\n");

				rdev->irq.stat_regs.r600.hdmi0_status &= ~HDMI0_AZ_FORMAT_WTRIG;
				queue_hdmi = true;
				DRM_DEBUG("IH: HDMI0\n");

				break;
			case 5:
				if (!(rdev->irq.stat_regs.r600.hdmi1_status & HDMI0_AZ_FORMAT_WTRIG))
					DRM_DEBUG("IH: HDMI1 - IH event w/o asserted irq bit?\n");

				rdev->irq.stat_regs.r600.hdmi1_status &= ~HDMI0_AZ_FORMAT_WTRIG;
				queue_hdmi = true;
				DRM_DEBUG("IH: HDMI1\n");

				break;
			default:
				DRM_ERROR("Unhandled interrupt: %d %d\n", src_id, src_data);
				break;
			}
			break;
		case 124: /* UVD */
			DRM_DEBUG("IH: UVD int: 0x%08x\n", src_data);
			radeon_fence_process(rdev, R600_RING_TYPE_UVD_INDEX);
			break;
		case 176: /* CP_INT in ring buffer */
		case 177: /* CP_INT in IB1 */
		case 178: /* CP_INT in IB2 */
			DRM_DEBUG("IH: CP int: 0x%08x\n", src_data);
			radeon_fence_process(rdev, RADEON_RING_TYPE_GFX_INDEX);
			break;
		case 181: /* CP EOP event */
			DRM_DEBUG("IH: CP EOP\n");
			radeon_fence_process(rdev, RADEON_RING_TYPE_GFX_INDEX);
			break;
		case 224: /* DMA trap event */
			DRM_DEBUG("IH: DMA trap\n");
			radeon_fence_process(rdev, R600_RING_TYPE_DMA_INDEX);
			break;
		case 230: /* thermal low to high */
			DRM_DEBUG("IH: thermal low to high\n");
			rdev->pm.dpm.thermal.high_to_low = false;
			queue_thermal = true;
			break;
		case 231: /* thermal high to low */
			DRM_DEBUG("IH: thermal high to low\n");
			rdev->pm.dpm.thermal.high_to_low = true;
			queue_thermal = true;
			break;
		case 233: /* GUI IDLE */
			DRM_DEBUG("IH: GUI idle\n");
			break;
		default:
			DRM_DEBUG("Unhandled interrupt: %d %d\n", src_id, src_data);
			break;
		}

		/* wptr/rptr are in bytes! */
		rptr += 16;
		rptr &= rdev->ih.ptr_mask;
		WREG32(IH_RB_RPTR, rptr);
	}
	if (queue_hotplug)
		schedule_delayed_work(&rdev->hotplug_work, 0);
	if (queue_hdmi)
		schedule_work(&rdev->audio_work);
	if (queue_thermal && rdev->pm.dpm_enabled)
		schedule_work(&rdev->pm.dpm.thermal.work);
	rdev->ih.rptr = rptr;
	atomic_set(&rdev->ih.lock, 0);

	/* make sure wptr hasn't changed while processing */
	wptr = r600_get_ih_wptr(rdev);
	if (wptr != rptr)
		goto restart_ih;

	return IRQ_HANDLED;
}