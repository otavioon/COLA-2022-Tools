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
typedef  int u32 ;
struct rvt_mmap_info {int /*<<< orphan*/  pending_mmaps; int /*<<< orphan*/  offset; } ;
struct TYPE_4__ {int max_cqe; } ;
struct TYPE_5__ {int /*<<< orphan*/  node; TYPE_1__ props; } ;
struct rvt_dev_info {int /*<<< orphan*/  pending_lock; int /*<<< orphan*/  pending_mmaps; TYPE_2__ dparms; } ;
struct rvt_cq_wc {int head; int tail; int /*<<< orphan*/ * kqueue; int /*<<< orphan*/ * uqueue; } ;
struct TYPE_6__ {int cqe; } ;
struct rvt_cq {int /*<<< orphan*/  lock; struct rvt_mmap_info* ip; struct rvt_cq_wc* queue; TYPE_3__ ibcq; struct rvt_dev_info* rdi; } ;
struct ib_wc {int dummy; } ;
struct ib_uverbs_wc {int dummy; } ;
struct ib_udata {int outlen; } ;
struct ib_cq {int dummy; } ;
typedef  int /*<<< orphan*/  offset ;
typedef  int /*<<< orphan*/  __u64 ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int ib_copy_to_udata (struct ib_udata*,int /*<<< orphan*/ *,int) ; 
 struct rvt_cq* ibcq_to_rvtcq (struct ib_cq*) ; 
 int /*<<< orphan*/  list_add (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ list_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rvt_update_mmap_info (struct rvt_dev_info*,struct rvt_mmap_info*,int,struct rvt_cq_wc*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  vfree (struct rvt_cq_wc*) ; 
 struct rvt_cq_wc* vmalloc_user (int) ; 
 struct rvt_cq_wc* vzalloc_node (int,int /*<<< orphan*/ ) ; 

int rvt_resize_cq(struct ib_cq *ibcq, int cqe, struct ib_udata *udata)
{
	struct rvt_cq *cq = ibcq_to_rvtcq(ibcq);
	struct rvt_cq_wc *old_wc;
	struct rvt_cq_wc *wc;
	u32 head, tail, n;
	int ret;
	u32 sz;
	struct rvt_dev_info *rdi = cq->rdi;

	if (cqe < 1 || cqe > rdi->dparms.props.max_cqe)
		return -EINVAL;

	/*
	 * Need to use vmalloc() if we want to support large #s of entries.
	 */
	sz = sizeof(*wc);
	if (udata && udata->outlen >= sizeof(__u64))
		sz += sizeof(struct ib_uverbs_wc) * (cqe + 1);
	else
		sz += sizeof(struct ib_wc) * (cqe + 1);
	wc = udata ?
		vmalloc_user(sz) :
		vzalloc_node(sz, rdi->dparms.node);
	if (!wc)
		return -ENOMEM;

	/* Check that we can write the offset to mmap. */
	if (udata && udata->outlen >= sizeof(__u64)) {
		__u64 offset = 0;

		ret = ib_copy_to_udata(udata, &offset, sizeof(offset));
		if (ret)
			goto bail_free;
	}

	spin_lock_irq(&cq->lock);
	/*
	 * Make sure head and tail are sane since they
	 * might be user writable.
	 */
	old_wc = cq->queue;
	head = old_wc->head;
	if (head > (u32)cq->ibcq.cqe)
		head = (u32)cq->ibcq.cqe;
	tail = old_wc->tail;
	if (tail > (u32)cq->ibcq.cqe)
		tail = (u32)cq->ibcq.cqe;
	if (head < tail)
		n = cq->ibcq.cqe + 1 + head - tail;
	else
		n = head - tail;
	if (unlikely((u32)cqe < n)) {
		ret = -EINVAL;
		goto bail_unlock;
	}
	for (n = 0; tail != head; n++) {
		if (cq->ip)
			wc->uqueue[n] = old_wc->uqueue[tail];
		else
			wc->kqueue[n] = old_wc->kqueue[tail];
		if (tail == (u32)cq->ibcq.cqe)
			tail = 0;
		else
			tail++;
	}
	cq->ibcq.cqe = cqe;
	wc->head = n;
	wc->tail = 0;
	cq->queue = wc;
	spin_unlock_irq(&cq->lock);

	vfree(old_wc);

	if (cq->ip) {
		struct rvt_mmap_info *ip = cq->ip;

		rvt_update_mmap_info(rdi, ip, sz, wc);

		/*
		 * Return the offset to mmap.
		 * See rvt_mmap() for details.
		 */
		if (udata && udata->outlen >= sizeof(__u64)) {
			ret = ib_copy_to_udata(udata, &ip->offset,
					       sizeof(ip->offset));
			if (ret)
				return ret;
		}

		spin_lock_irq(&rdi->pending_lock);
		if (list_empty(&ip->pending_mmaps))
			list_add(&ip->pending_mmaps, &rdi->pending_mmaps);
		spin_unlock_irq(&rdi->pending_lock);
	}

	return 0;

bail_unlock:
	spin_unlock_irq(&cq->lock);
bail_free:
	vfree(wc);
	return ret;
}