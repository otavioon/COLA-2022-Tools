#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct v4l2_ioctl_ops {int (* vidioc_try_fmt_vid_cap ) (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ;int (* vidioc_try_fmt_vid_cap_mplane ) (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ;int (* vidioc_try_fmt_vid_overlay ) (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ;int (* vidioc_try_fmt_vbi_cap ) (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ;int (* vidioc_try_fmt_sliced_vbi_cap ) (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ;int (* vidioc_try_fmt_vid_out ) (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ;int (* vidioc_try_fmt_vid_out_mplane ) (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ;int (* vidioc_try_fmt_vid_out_overlay ) (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ;int (* vidioc_try_fmt_vbi_out ) (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ;int (* vidioc_try_fmt_sliced_vbi_out ) (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ;int (* vidioc_try_fmt_sdr_cap ) (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ;int (* vidioc_try_fmt_sdr_out ) (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ;int (* vidioc_try_fmt_meta_cap ) (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ;} ;
struct TYPE_5__ {void* priv; } ;
struct TYPE_6__ {TYPE_1__ pix; } ;
struct v4l2_format {int type; TYPE_2__ fmt; } ;
struct file {int dummy; } ;
struct TYPE_7__ {int /*<<< orphan*/  xfer_func; } ;
struct TYPE_8__ {int /*<<< orphan*/  meta; int /*<<< orphan*/  sdr; int /*<<< orphan*/  sliced; int /*<<< orphan*/  vbi; int /*<<< orphan*/  win; TYPE_3__ pix_mp; int /*<<< orphan*/  pix; } ;

/* Variables and functions */
 int /*<<< orphan*/  CLEAR_AFTER_FIELD (struct v4l2_format*,int /*<<< orphan*/ ) ; 
 int EINVAL ; 
#define  V4L2_BUF_TYPE_META_CAPTURE 140 
#define  V4L2_BUF_TYPE_SDR_CAPTURE 139 
#define  V4L2_BUF_TYPE_SDR_OUTPUT 138 
#define  V4L2_BUF_TYPE_SLICED_VBI_CAPTURE 137 
#define  V4L2_BUF_TYPE_SLICED_VBI_OUTPUT 136 
#define  V4L2_BUF_TYPE_VBI_CAPTURE 135 
#define  V4L2_BUF_TYPE_VBI_OUTPUT 134 
#define  V4L2_BUF_TYPE_VIDEO_CAPTURE 133 
#define  V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE 132 
#define  V4L2_BUF_TYPE_VIDEO_OUTPUT 131 
#define  V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE 130 
#define  V4L2_BUF_TYPE_VIDEO_OUTPUT_OVERLAY 129 
#define  V4L2_BUF_TYPE_VIDEO_OVERLAY 128 
 void* V4L2_PIX_FMT_PRIV_MAGIC ; 
 int check_fmt (struct file*,int) ; 
 TYPE_4__ fmt ; 
 int stub1 (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ; 
 int stub10 (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ; 
 int stub11 (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ; 
 int stub12 (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ; 
 int stub13 (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ; 
 int stub2 (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ; 
 int stub3 (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ; 
 int stub4 (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ; 
 int stub5 (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ; 
 int stub6 (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ; 
 int stub7 (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ; 
 int stub8 (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ; 
 int stub9 (struct file*,int /*<<< orphan*/ *,struct v4l2_format*) ; 
 int /*<<< orphan*/  unlikely (int) ; 
 int /*<<< orphan*/  v4l_sanitize_format (struct v4l2_format*) ; 

__attribute__((used)) static int v4l_try_fmt(const struct v4l2_ioctl_ops *ops,
				struct file *file, void *fh, void *arg)
{
	struct v4l2_format *p = arg;
	int ret = check_fmt(file, p->type);

	if (ret)
		return ret;

	v4l_sanitize_format(p);

	switch (p->type) {
	case V4L2_BUF_TYPE_VIDEO_CAPTURE:
		if (unlikely(!ops->vidioc_try_fmt_vid_cap))
			break;
		CLEAR_AFTER_FIELD(p, fmt.pix);
		ret = ops->vidioc_try_fmt_vid_cap(file, fh, arg);
		/* just in case the driver zeroed it again */
		p->fmt.pix.priv = V4L2_PIX_FMT_PRIV_MAGIC;
		return ret;
	case V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE:
		if (unlikely(!ops->vidioc_try_fmt_vid_cap_mplane))
			break;
		CLEAR_AFTER_FIELD(p, fmt.pix_mp.xfer_func);
		return ops->vidioc_try_fmt_vid_cap_mplane(file, fh, arg);
	case V4L2_BUF_TYPE_VIDEO_OVERLAY:
		if (unlikely(!ops->vidioc_try_fmt_vid_overlay))
			break;
		CLEAR_AFTER_FIELD(p, fmt.win);
		return ops->vidioc_try_fmt_vid_overlay(file, fh, arg);
	case V4L2_BUF_TYPE_VBI_CAPTURE:
		if (unlikely(!ops->vidioc_try_fmt_vbi_cap))
			break;
		CLEAR_AFTER_FIELD(p, fmt.vbi);
		return ops->vidioc_try_fmt_vbi_cap(file, fh, arg);
	case V4L2_BUF_TYPE_SLICED_VBI_CAPTURE:
		if (unlikely(!ops->vidioc_try_fmt_sliced_vbi_cap))
			break;
		CLEAR_AFTER_FIELD(p, fmt.sliced);
		return ops->vidioc_try_fmt_sliced_vbi_cap(file, fh, arg);
	case V4L2_BUF_TYPE_VIDEO_OUTPUT:
		if (unlikely(!ops->vidioc_try_fmt_vid_out))
			break;
		CLEAR_AFTER_FIELD(p, fmt.pix);
		ret = ops->vidioc_try_fmt_vid_out(file, fh, arg);
		/* just in case the driver zeroed it again */
		p->fmt.pix.priv = V4L2_PIX_FMT_PRIV_MAGIC;
		return ret;
	case V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE:
		if (unlikely(!ops->vidioc_try_fmt_vid_out_mplane))
			break;
		CLEAR_AFTER_FIELD(p, fmt.pix_mp.xfer_func);
		return ops->vidioc_try_fmt_vid_out_mplane(file, fh, arg);
	case V4L2_BUF_TYPE_VIDEO_OUTPUT_OVERLAY:
		if (unlikely(!ops->vidioc_try_fmt_vid_out_overlay))
			break;
		CLEAR_AFTER_FIELD(p, fmt.win);
		return ops->vidioc_try_fmt_vid_out_overlay(file, fh, arg);
	case V4L2_BUF_TYPE_VBI_OUTPUT:
		if (unlikely(!ops->vidioc_try_fmt_vbi_out))
			break;
		CLEAR_AFTER_FIELD(p, fmt.vbi);
		return ops->vidioc_try_fmt_vbi_out(file, fh, arg);
	case V4L2_BUF_TYPE_SLICED_VBI_OUTPUT:
		if (unlikely(!ops->vidioc_try_fmt_sliced_vbi_out))
			break;
		CLEAR_AFTER_FIELD(p, fmt.sliced);
		return ops->vidioc_try_fmt_sliced_vbi_out(file, fh, arg);
	case V4L2_BUF_TYPE_SDR_CAPTURE:
		if (unlikely(!ops->vidioc_try_fmt_sdr_cap))
			break;
		CLEAR_AFTER_FIELD(p, fmt.sdr);
		return ops->vidioc_try_fmt_sdr_cap(file, fh, arg);
	case V4L2_BUF_TYPE_SDR_OUTPUT:
		if (unlikely(!ops->vidioc_try_fmt_sdr_out))
			break;
		CLEAR_AFTER_FIELD(p, fmt.sdr);
		return ops->vidioc_try_fmt_sdr_out(file, fh, arg);
	case V4L2_BUF_TYPE_META_CAPTURE:
		if (unlikely(!ops->vidioc_try_fmt_meta_cap))
			break;
		CLEAR_AFTER_FIELD(p, fmt.meta);
		return ops->vidioc_try_fmt_meta_cap(file, fh, arg);
	}
	return -EINVAL;
}