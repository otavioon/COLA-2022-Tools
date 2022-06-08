#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
typedef  int u16 ;
struct TYPE_7__ {void* addr_low; void* addr_high; } ;
struct TYPE_8__ {TYPE_2__ generic; } ;
struct ice_sq_cd {struct ice_sq_cd* wb_desc; int /*<<< orphan*/  retval; int /*<<< orphan*/  datalen; TYPE_3__ params; int /*<<< orphan*/  flags; } ;
struct ice_hw {int dummy; } ;
struct ice_dma_mem {struct ice_sq_cd* va; int /*<<< orphan*/  pa; } ;
struct TYPE_6__ {struct ice_dma_mem* sq_bi; } ;
struct TYPE_9__ {size_t count; size_t next_to_use; int /*<<< orphan*/  tail; TYPE_1__ r; int /*<<< orphan*/  head; } ;
struct ice_ctl_q_info {int sq_last_status; int sq_buf_size; scalar_t__ num_sq_entries; scalar_t__ sq_cmd_timeout; int /*<<< orphan*/  sq_lock; TYPE_4__ sq; } ;
struct ice_aq_desc {struct ice_aq_desc* wb_desc; int /*<<< orphan*/  retval; int /*<<< orphan*/  datalen; TYPE_3__ params; int /*<<< orphan*/  flags; } ;
typedef  enum ice_status { ____Placeholder_ice_status } ice_status ;
typedef  enum ice_aq_err { ____Placeholder_ice_aq_err } ice_aq_err ;

/* Variables and functions */
 int ICE_AQ_FLAG_BUF ; 
 int ICE_AQ_FLAG_LB ; 
 int ICE_AQ_LG_BUF ; 
 int ICE_AQ_RC_OK ; 
 struct ice_sq_cd* ICE_CTL_Q_DESC (TYPE_4__,size_t) ; 
 struct ice_sq_cd* ICE_CTL_Q_DETAILS (TYPE_4__,size_t) ; 
 int /*<<< orphan*/  ICE_DBG_AQ_CMD ; 
 int /*<<< orphan*/  ICE_DBG_AQ_MSG ; 
 int ICE_ERR_AQ_EMPTY ; 
 int ICE_ERR_AQ_ERROR ; 
 int ICE_ERR_AQ_FULL ; 
 int ICE_ERR_AQ_TIMEOUT ; 
 int ICE_ERR_INVAL_SIZE ; 
 int ICE_ERR_PARAM ; 
 int /*<<< orphan*/  cpu_to_le16 (int) ; 
 void* cpu_to_le32 (int /*<<< orphan*/ ) ; 
 scalar_t__ ice_clean_sq (struct ice_hw*,struct ice_ctl_q_info*) ; 
 int /*<<< orphan*/  ice_debug (struct ice_hw*,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  ice_debug_cq (struct ice_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct ice_sq_cd*,int) ; 
 scalar_t__ ice_sq_done (struct ice_hw*,struct ice_ctl_q_info*) ; 
 int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lower_32_bits (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  memcpy (struct ice_sq_cd*,struct ice_sq_cd*,int) ; 
 int /*<<< orphan*/  memset (struct ice_sq_cd*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ rd32 (struct ice_hw*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  upper_32_bits (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wr32 (struct ice_hw*,int /*<<< orphan*/ ,size_t) ; 

enum ice_status
ice_sq_send_cmd(struct ice_hw *hw, struct ice_ctl_q_info *cq,
		struct ice_aq_desc *desc, void *buf, u16 buf_size,
		struct ice_sq_cd *cd)
{
	struct ice_dma_mem *dma_buf = NULL;
	struct ice_aq_desc *desc_on_ring;
	bool cmd_completed = false;
	enum ice_status status = 0;
	struct ice_sq_cd *details;
	u32 total_delay = 0;
	u16 retval = 0;
	u32 val = 0;

	mutex_lock(&cq->sq_lock);

	cq->sq_last_status = ICE_AQ_RC_OK;

	if (!cq->sq.count) {
		ice_debug(hw, ICE_DBG_AQ_MSG,
			  "Control Send queue not initialized.\n");
		status = ICE_ERR_AQ_EMPTY;
		goto sq_send_command_error;
	}

	if ((buf && !buf_size) || (!buf && buf_size)) {
		status = ICE_ERR_PARAM;
		goto sq_send_command_error;
	}

	if (buf) {
		if (buf_size > cq->sq_buf_size) {
			ice_debug(hw, ICE_DBG_AQ_MSG,
				  "Invalid buffer size for Control Send queue: %d.\n",
				  buf_size);
			status = ICE_ERR_INVAL_SIZE;
			goto sq_send_command_error;
		}

		desc->flags |= cpu_to_le16(ICE_AQ_FLAG_BUF);
		if (buf_size > ICE_AQ_LG_BUF)
			desc->flags |= cpu_to_le16(ICE_AQ_FLAG_LB);
	}

	val = rd32(hw, cq->sq.head);
	if (val >= cq->num_sq_entries) {
		ice_debug(hw, ICE_DBG_AQ_MSG,
			  "head overrun at %d in the Control Send Queue ring\n",
			  val);
		status = ICE_ERR_AQ_EMPTY;
		goto sq_send_command_error;
	}

	details = ICE_CTL_Q_DETAILS(cq->sq, cq->sq.next_to_use);
	if (cd)
		memcpy(details, cd, sizeof(*details));
	else
		memset(details, 0, sizeof(*details));

	/* Call clean and check queue available function to reclaim the
	 * descriptors that were processed by FW/MBX; the function returns the
	 * number of desc available. The clean function called here could be
	 * called in a separate thread in case of asynchronous completions.
	 */
	if (ice_clean_sq(hw, cq) == 0) {
		ice_debug(hw, ICE_DBG_AQ_MSG,
			  "Error: Control Send Queue is full.\n");
		status = ICE_ERR_AQ_FULL;
		goto sq_send_command_error;
	}

	/* initialize the temp desc pointer with the right desc */
	desc_on_ring = ICE_CTL_Q_DESC(cq->sq, cq->sq.next_to_use);

	/* if the desc is available copy the temp desc to the right place */
	memcpy(desc_on_ring, desc, sizeof(*desc_on_ring));

	/* if buf is not NULL assume indirect command */
	if (buf) {
		dma_buf = &cq->sq.r.sq_bi[cq->sq.next_to_use];
		/* copy the user buf into the respective DMA buf */
		memcpy(dma_buf->va, buf, buf_size);
		desc_on_ring->datalen = cpu_to_le16(buf_size);

		/* Update the address values in the desc with the pa value
		 * for respective buffer
		 */
		desc_on_ring->params.generic.addr_high =
			cpu_to_le32(upper_32_bits(dma_buf->pa));
		desc_on_ring->params.generic.addr_low =
			cpu_to_le32(lower_32_bits(dma_buf->pa));
	}

	/* Debug desc and buffer */
	ice_debug(hw, ICE_DBG_AQ_MSG,
		  "ATQ: Control Send queue desc and buffer:\n");

	ice_debug_cq(hw, ICE_DBG_AQ_CMD, (void *)desc_on_ring, buf, buf_size);

	(cq->sq.next_to_use)++;
	if (cq->sq.next_to_use == cq->sq.count)
		cq->sq.next_to_use = 0;
	wr32(hw, cq->sq.tail, cq->sq.next_to_use);

	do {
		if (ice_sq_done(hw, cq))
			break;

		mdelay(1);
		total_delay++;
	} while (total_delay < cq->sq_cmd_timeout);

	/* if ready, copy the desc back to temp */
	if (ice_sq_done(hw, cq)) {
		memcpy(desc, desc_on_ring, sizeof(*desc));
		if (buf) {
			/* get returned length to copy */
			u16 copy_size = le16_to_cpu(desc->datalen);

			if (copy_size > buf_size) {
				ice_debug(hw, ICE_DBG_AQ_MSG,
					  "Return len %d > than buf len %d\n",
					  copy_size, buf_size);
				status = ICE_ERR_AQ_ERROR;
			} else {
				memcpy(buf, dma_buf->va, copy_size);
			}
		}
		retval = le16_to_cpu(desc->retval);
		if (retval) {
			ice_debug(hw, ICE_DBG_AQ_MSG,
				  "Control Send Queue command completed with error 0x%x\n",
				  retval);

			/* strip off FW internal code */
			retval &= 0xff;
		}
		cmd_completed = true;
		if (!status && retval != ICE_AQ_RC_OK)
			status = ICE_ERR_AQ_ERROR;
		cq->sq_last_status = (enum ice_aq_err)retval;
	}

	ice_debug(hw, ICE_DBG_AQ_MSG,
		  "ATQ: desc and buffer writeback:\n");

	ice_debug_cq(hw, ICE_DBG_AQ_CMD, (void *)desc, buf, buf_size);

	/* save writeback AQ if requested */
	if (details->wb_desc)
		memcpy(details->wb_desc, desc_on_ring,
		       sizeof(*details->wb_desc));

	/* update the error if time out occurred */
	if (!cmd_completed) {
		ice_debug(hw, ICE_DBG_AQ_MSG,
			  "Control Send Queue Writeback timeout.\n");
		status = ICE_ERR_AQ_TIMEOUT;
	}

sq_send_command_error:
	mutex_unlock(&cq->sq_lock);
	return status;
}