#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct timespec64 {int tv_sec; unsigned int tv_nsec; } ;
struct comedi_subdevice {scalar_t__ type; int (* busy ) (struct comedi_device*,struct comedi_insn*,unsigned int*,int /*<<< orphan*/ *) ;int (* insn_read ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;size_t index; unsigned int* maxdata_list; unsigned int maxdata; int (* insn_write ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int n_chan; int (* insn_bits ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int (* insn_config ) (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ;int /*<<< orphan*/ * lock; TYPE_1__* async; } ;
struct comedi_insn {int insn; int n; size_t subdev; int /*<<< orphan*/  chanspec; } ;
struct comedi_device {size_t n_subdevices; int /*<<< orphan*/  class_dev; struct comedi_subdevice* subdevices; } ;
struct TYPE_2__ {int (* inttrig ) (struct comedi_device*,struct comedi_subdevice*,unsigned int) ;} ;

/* Variables and functions */
 scalar_t__ COMEDI_SUBD_UNUSED ; 
 size_t CR_CHAN (int /*<<< orphan*/ ) ; 
 int EACCES ; 
 int EAGAIN ; 
 int EBUSY ; 
 int EINVAL ; 
 int EIO ; 
 int ETIMEDOUT ; 
#define  INSN_BITS 134 
#define  INSN_CONFIG 133 
#define  INSN_GTOD 132 
#define  INSN_INTTRIG 131 
 int INSN_MASK_SPECIAL ; 
#define  INSN_READ 130 
#define  INSN_WAIT 129 
#define  INSN_WRITE 128 
 unsigned int NSEC_PER_USEC ; 
 int check_insn_config_length (struct comedi_insn*,unsigned int*) ; 
 int comedi_check_chanlist (struct comedi_subdevice*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  ktime_get_real_ts64 (struct timespec64*) ; 
 int stub1 (struct comedi_device*,struct comedi_subdevice*,unsigned int) ; 
 int stub2 (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ; 
 int stub3 (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ; 
 int stub4 (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ; 
 int stub5 (struct comedi_device*,struct comedi_subdevice*,struct comedi_insn*,unsigned int*) ; 
 int /*<<< orphan*/  udelay (unsigned int) ; 

__attribute__((used)) static int parse_insn(struct comedi_device *dev, struct comedi_insn *insn,
		      unsigned int *data, void *file)
{
	struct comedi_subdevice *s;
	int ret = 0;
	int i;

	if (insn->insn & INSN_MASK_SPECIAL) {
		/* a non-subdevice instruction */

		switch (insn->insn) {
		case INSN_GTOD:
			{
				struct timespec64 tv;

				if (insn->n != 2) {
					ret = -EINVAL;
					break;
				}

				ktime_get_real_ts64(&tv);
				/* unsigned data safe until 2106 */
				data[0] = (unsigned int)tv.tv_sec;
				data[1] = tv.tv_nsec / NSEC_PER_USEC;
				ret = 2;

				break;
			}
		case INSN_WAIT:
			if (insn->n != 1 || data[0] >= 100000) {
				ret = -EINVAL;
				break;
			}
			udelay(data[0] / 1000);
			ret = 1;
			break;
		case INSN_INTTRIG:
			if (insn->n != 1) {
				ret = -EINVAL;
				break;
			}
			if (insn->subdev >= dev->n_subdevices) {
				dev_dbg(dev->class_dev,
					"%d not usable subdevice\n",
					insn->subdev);
				ret = -EINVAL;
				break;
			}
			s = &dev->subdevices[insn->subdev];
			if (!s->async) {
				dev_dbg(dev->class_dev, "no async\n");
				ret = -EINVAL;
				break;
			}
			if (!s->async->inttrig) {
				dev_dbg(dev->class_dev, "no inttrig\n");
				ret = -EAGAIN;
				break;
			}
			ret = s->async->inttrig(dev, s, data[0]);
			if (ret >= 0)
				ret = 1;
			break;
		default:
			dev_dbg(dev->class_dev, "invalid insn\n");
			ret = -EINVAL;
			break;
		}
	} else {
		/* a subdevice instruction */
		unsigned int maxdata;

		if (insn->subdev >= dev->n_subdevices) {
			dev_dbg(dev->class_dev, "subdevice %d out of range\n",
				insn->subdev);
			ret = -EINVAL;
			goto out;
		}
		s = &dev->subdevices[insn->subdev];

		if (s->type == COMEDI_SUBD_UNUSED) {
			dev_dbg(dev->class_dev, "%d not usable subdevice\n",
				insn->subdev);
			ret = -EIO;
			goto out;
		}

		/* are we locked? (ioctl lock) */
		if (s->lock && s->lock != file) {
			dev_dbg(dev->class_dev, "device locked\n");
			ret = -EACCES;
			goto out;
		}

		ret = comedi_check_chanlist(s, 1, &insn->chanspec);
		if (ret < 0) {
			ret = -EINVAL;
			dev_dbg(dev->class_dev, "bad chanspec\n");
			goto out;
		}

		if (s->busy) {
			ret = -EBUSY;
			goto out;
		}
		/* This looks arbitrary.  It is. */
		s->busy = parse_insn;
		switch (insn->insn) {
		case INSN_READ:
			ret = s->insn_read(dev, s, insn, data);
			if (ret == -ETIMEDOUT) {
				dev_dbg(dev->class_dev,
					"subdevice %d read instruction timed out\n",
					s->index);
			}
			break;
		case INSN_WRITE:
			maxdata = s->maxdata_list
			    ? s->maxdata_list[CR_CHAN(insn->chanspec)]
			    : s->maxdata;
			for (i = 0; i < insn->n; ++i) {
				if (data[i] > maxdata) {
					ret = -EINVAL;
					dev_dbg(dev->class_dev,
						"bad data value(s)\n");
					break;
				}
			}
			if (ret == 0) {
				ret = s->insn_write(dev, s, insn, data);
				if (ret == -ETIMEDOUT) {
					dev_dbg(dev->class_dev,
						"subdevice %d write instruction timed out\n",
						s->index);
				}
			}
			break;
		case INSN_BITS:
			if (insn->n != 2) {
				ret = -EINVAL;
			} else {
				/*
				 * Most drivers ignore the base channel in
				 * insn->chanspec.  Fix this here if
				 * the subdevice has <= 32 channels.
				 */
				unsigned int orig_mask = data[0];
				unsigned int shift = 0;

				if (s->n_chan <= 32) {
					shift = CR_CHAN(insn->chanspec);
					if (shift > 0) {
						insn->chanspec = 0;
						data[0] <<= shift;
						data[1] <<= shift;
					}
				}
				ret = s->insn_bits(dev, s, insn, data);
				data[0] = orig_mask;
				if (shift > 0)
					data[1] >>= shift;
			}
			break;
		case INSN_CONFIG:
			ret = check_insn_config_length(insn, data);
			if (ret)
				break;
			ret = s->insn_config(dev, s, insn, data);
			break;
		default:
			ret = -EINVAL;
			break;
		}

		s->busy = NULL;
	}

out:
	return ret;
}