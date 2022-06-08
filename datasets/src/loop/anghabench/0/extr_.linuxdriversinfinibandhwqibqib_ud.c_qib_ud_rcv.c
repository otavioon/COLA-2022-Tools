#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  int u16 ;
struct TYPE_12__ {int qp_num; scalar_t__ qp_type; int /*<<< orphan*/  recv_cq; } ;
struct rvt_qp {int qkey; int r_flags; int r_len; TYPE_4__ ibqp; int /*<<< orphan*/  port_num; int /*<<< orphan*/  r_wr_id; int /*<<< orphan*/  r_aflags; int /*<<< orphan*/  r_sge; int /*<<< orphan*/  s_pkey_index; } ;
struct TYPE_9__ {int /*<<< orphan*/  n_pkt_drops; int /*<<< orphan*/  n_vl15_dropped; } ;
struct qib_ibport {TYPE_1__ rvp; } ;
struct TYPE_15__ {scalar_t__ imm_data; } ;
struct ib_wc {int byte_len; int src_qp; int slid; int sl; int dlid_path_bits; int /*<<< orphan*/  port_num; int /*<<< orphan*/  pkey_index; TYPE_4__* qp; scalar_t__ vendor_err; int /*<<< orphan*/  opcode; int /*<<< orphan*/  status; int /*<<< orphan*/  wr_id; int /*<<< orphan*/  wc_flags; TYPE_7__ ex; } ;
struct ib_smp {scalar_t__ mgmt_class; } ;
struct TYPE_13__ {scalar_t__ imm_data; int /*<<< orphan*/ * deth; } ;
struct TYPE_14__ {TYPE_5__ ud; } ;
struct ib_other_headers {int /*<<< orphan*/ * bth; TYPE_6__ u; } ;
struct TYPE_10__ {int /*<<< orphan*/  grh; struct ib_other_headers oth; } ;
struct TYPE_11__ {TYPE_2__ l; struct ib_other_headers oth; } ;
struct ib_header {int /*<<< orphan*/ * lrh; TYPE_3__ u; } ;
struct ib_grh {int dummy; } ;
struct TYPE_16__ {int lmc; } ;

/* Variables and functions */
 int /*<<< orphan*/  IB_LID_PERMISSIVE ; 
 scalar_t__ IB_MGMT_CLASS_SUBN_DIRECTED_ROUTE ; 
 int /*<<< orphan*/  IB_MULTICAST_LID_BASE ; 
 int IB_OPCODE_UD_SEND_ONLY ; 
 int IB_OPCODE_UD_SEND_ONLY_WITH_IMMEDIATE ; 
 scalar_t__ IB_QPT_GSI ; 
 int /*<<< orphan*/  IB_WC_GRH ; 
 int /*<<< orphan*/  IB_WC_LOC_QP_OP_ERR ; 
 int /*<<< orphan*/  IB_WC_RECV ; 
 int /*<<< orphan*/  IB_WC_SUCCESS ; 
 int /*<<< orphan*/  IB_WC_WITH_IMM ; 
 int RVT_QPN_MASK ; 
 int RVT_R_REUSE_SGE ; 
 int /*<<< orphan*/  RVT_R_WRID_VALID ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 int be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ib_bth_is_solicited (struct ib_other_headers*) ; 
 int /*<<< orphan*/  ibcq_to_rvtcq (int /*<<< orphan*/ ) ; 
 TYPE_8__* ppd_from_ibp (struct qib_ibport*) ; 
 int /*<<< orphan*/  qib_bad_pkey (struct qib_ibport*,int,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  qib_copy_sge (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int) ; 
 int qib_get_pkey (struct qib_ibport*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  qib_lookup_pkey (struct qib_ibport*,int) ; 
 int /*<<< orphan*/  qib_pkey_ok (int,int) ; 
 int /*<<< orphan*/  rvt_cq_enter (int /*<<< orphan*/ ,struct ib_wc*,int /*<<< orphan*/ ) ; 
 int rvt_get_rwqe (struct rvt_qp*,int) ; 
 int /*<<< orphan*/  rvt_put_ss (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rvt_rc_error (struct rvt_qp*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rvt_skip_sge (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  test_and_clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ unlikely (int) ; 

void qib_ud_rcv(struct qib_ibport *ibp, struct ib_header *hdr,
		int has_grh, void *data, u32 tlen, struct rvt_qp *qp)
{
	struct ib_other_headers *ohdr;
	int opcode;
	u32 hdrsize;
	u32 pad;
	struct ib_wc wc;
	u32 qkey;
	u32 src_qp;
	u16 dlid;

	/* Check for GRH */
	if (!has_grh) {
		ohdr = &hdr->u.oth;
		hdrsize = 8 + 12 + 8;   /* LRH + BTH + DETH */
	} else {
		ohdr = &hdr->u.l.oth;
		hdrsize = 8 + 40 + 12 + 8; /* LRH + GRH + BTH + DETH */
	}
	qkey = be32_to_cpu(ohdr->u.ud.deth[0]);
	src_qp = be32_to_cpu(ohdr->u.ud.deth[1]) & RVT_QPN_MASK;

	/*
	 * Get the number of bytes the message was padded by
	 * and drop incomplete packets.
	 */
	pad = (be32_to_cpu(ohdr->bth[0]) >> 20) & 3;
	if (unlikely(tlen < (hdrsize + pad + 4)))
		goto drop;

	tlen -= hdrsize + pad + 4;

	/*
	 * Check that the permissive LID is only used on QP0
	 * and the QKEY matches (see 9.6.1.4.1 and 9.6.1.5.1).
	 */
	if (qp->ibqp.qp_num) {
		if (unlikely(hdr->lrh[1] == IB_LID_PERMISSIVE ||
			     hdr->lrh[3] == IB_LID_PERMISSIVE))
			goto drop;
		if (qp->ibqp.qp_num > 1) {
			u16 pkey1, pkey2;

			pkey1 = be32_to_cpu(ohdr->bth[0]);
			pkey2 = qib_get_pkey(ibp, qp->s_pkey_index);
			if (unlikely(!qib_pkey_ok(pkey1, pkey2))) {
				qib_bad_pkey(ibp,
					     pkey1,
					     (be16_to_cpu(hdr->lrh[0]) >> 4) &
						0xF,
					     src_qp, qp->ibqp.qp_num,
					     hdr->lrh[3], hdr->lrh[1]);
				return;
			}
		}
		if (unlikely(qkey != qp->qkey))
			return;

		/* Drop invalid MAD packets (see 13.5.3.1). */
		if (unlikely(qp->ibqp.qp_num == 1 &&
			     (tlen != 256 ||
			      (be16_to_cpu(hdr->lrh[0]) >> 12) == 15)))
			goto drop;
	} else {
		struct ib_smp *smp;

		/* Drop invalid MAD packets (see 13.5.3.1). */
		if (tlen != 256 || (be16_to_cpu(hdr->lrh[0]) >> 12) != 15)
			goto drop;
		smp = (struct ib_smp *) data;
		if ((hdr->lrh[1] == IB_LID_PERMISSIVE ||
		     hdr->lrh[3] == IB_LID_PERMISSIVE) &&
		    smp->mgmt_class != IB_MGMT_CLASS_SUBN_DIRECTED_ROUTE)
			goto drop;
	}

	/*
	 * The opcode is in the low byte when its in network order
	 * (top byte when in host order).
	 */
	opcode = be32_to_cpu(ohdr->bth[0]) >> 24;
	if (qp->ibqp.qp_num > 1 &&
	    opcode == IB_OPCODE_UD_SEND_ONLY_WITH_IMMEDIATE) {
		wc.ex.imm_data = ohdr->u.ud.imm_data;
		wc.wc_flags = IB_WC_WITH_IMM;
	} else if (opcode == IB_OPCODE_UD_SEND_ONLY) {
		wc.ex.imm_data = 0;
		wc.wc_flags = 0;
	} else
		goto drop;

	/*
	 * A GRH is expected to precede the data even if not
	 * present on the wire.
	 */
	wc.byte_len = tlen + sizeof(struct ib_grh);

	/*
	 * Get the next work request entry to find where to put the data.
	 */
	if (qp->r_flags & RVT_R_REUSE_SGE)
		qp->r_flags &= ~RVT_R_REUSE_SGE;
	else {
		int ret;

		ret = rvt_get_rwqe(qp, false);
		if (ret < 0) {
			rvt_rc_error(qp, IB_WC_LOC_QP_OP_ERR);
			return;
		}
		if (!ret) {
			if (qp->ibqp.qp_num == 0)
				ibp->rvp.n_vl15_dropped++;
			return;
		}
	}
	/* Silently drop packets which are too big. */
	if (unlikely(wc.byte_len > qp->r_len)) {
		qp->r_flags |= RVT_R_REUSE_SGE;
		goto drop;
	}
	if (has_grh) {
		qib_copy_sge(&qp->r_sge, &hdr->u.l.grh,
			     sizeof(struct ib_grh), 1);
		wc.wc_flags |= IB_WC_GRH;
	} else
		rvt_skip_sge(&qp->r_sge, sizeof(struct ib_grh), true);
	qib_copy_sge(&qp->r_sge, data, wc.byte_len - sizeof(struct ib_grh), 1);
	rvt_put_ss(&qp->r_sge);
	if (!test_and_clear_bit(RVT_R_WRID_VALID, &qp->r_aflags))
		return;
	wc.wr_id = qp->r_wr_id;
	wc.status = IB_WC_SUCCESS;
	wc.opcode = IB_WC_RECV;
	wc.vendor_err = 0;
	wc.qp = &qp->ibqp;
	wc.src_qp = src_qp;
	wc.pkey_index = qp->ibqp.qp_type == IB_QPT_GSI ?
		qib_lookup_pkey(ibp, be32_to_cpu(ohdr->bth[0])) : 0;
	wc.slid = be16_to_cpu(hdr->lrh[3]);
	wc.sl = (be16_to_cpu(hdr->lrh[0]) >> 4) & 0xF;
	dlid = be16_to_cpu(hdr->lrh[1]);
	/*
	 * Save the LMC lower bits if the destination LID is a unicast LID.
	 */
	wc.dlid_path_bits = dlid >= be16_to_cpu(IB_MULTICAST_LID_BASE) ? 0 :
		dlid & ((1 << ppd_from_ibp(ibp)->lmc) - 1);
	wc.port_num = qp->port_num;
	/* Signal completion event if the solicited bit is set. */
	rvt_cq_enter(ibcq_to_rvtcq(qp->ibqp.recv_cq), &wc,
		     ib_bth_is_solicited(ohdr));
	return;

drop:
	ibp->rvp.n_pkt_drops++;
}