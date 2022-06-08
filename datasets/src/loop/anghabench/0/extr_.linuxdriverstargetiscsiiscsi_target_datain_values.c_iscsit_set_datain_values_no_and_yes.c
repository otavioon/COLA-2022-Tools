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
typedef  scalar_t__ u32 ;
struct iscsi_seq {int sent; scalar_t__ next_burst_len; scalar_t__ offset; int /*<<< orphan*/  last_datasn; int /*<<< orphan*/  first_datasn; } ;
struct iscsi_datain_req {scalar_t__ recovery; scalar_t__ read_data_done; scalar_t__ seq_send_order; scalar_t__ data_sn; scalar_t__ runlength; scalar_t__ begrun; void* dr_complete; scalar_t__ generate_recovery_values; } ;
struct iscsi_datain {scalar_t__ length; scalar_t__ offset; int flags; int /*<<< orphan*/  data_sn; } ;
struct iscsi_conn {TYPE_3__* sess; TYPE_1__* conn_ops; } ;
struct TYPE_8__ {scalar_t__ data_length; } ;
struct iscsi_cmd {scalar_t__ read_data_done; scalar_t__ seq_send_order; int /*<<< orphan*/  data_sn; TYPE_4__ se_cmd; int /*<<< orphan*/  init_task_tag; struct iscsi_conn* conn; } ;
struct TYPE_7__ {TYPE_2__* sess_ops; } ;
struct TYPE_6__ {scalar_t__ ErrorRecoveryLevel; scalar_t__ MaxBurstLength; } ;
struct TYPE_5__ {scalar_t__ MaxRecvDataSegmentLength; } ;

/* Variables and functions */
 void* DATAIN_COMPLETE_CONNECTION_RECOVERY ; 
 void* DATAIN_COMPLETE_NORMAL ; 
 void* DATAIN_COMPLETE_WITHIN_COMMAND_RECOVERY ; 
 scalar_t__ DATAIN_WITHIN_COMMAND_RECOVERY ; 
 int ISCSI_FLAG_CMD_FINAL ; 
 int ISCSI_FLAG_DATA_ACK ; 
 int ISCSI_FLAG_DATA_STATUS ; 
 scalar_t__ iscsit_create_recovery_datain_values_datasequenceinorder_no (struct iscsi_cmd*,struct iscsi_datain_req*) ; 
 struct iscsi_datain_req* iscsit_get_datain_req (struct iscsi_cmd*) ; 
 struct iscsi_seq* iscsit_get_seq_holder_for_datain (struct iscsi_cmd*,scalar_t__) ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct iscsi_datain_req *iscsit_set_datain_values_no_and_yes(
	struct iscsi_cmd *cmd,
	struct iscsi_datain *datain)
{
	u32 offset, read_data_done, read_data_left, seq_send_order;
	struct iscsi_conn *conn = cmd->conn;
	struct iscsi_datain_req *dr;
	struct iscsi_seq *seq;

	dr = iscsit_get_datain_req(cmd);
	if (!dr)
		return NULL;

	if (dr->recovery && dr->generate_recovery_values) {
		if (iscsit_create_recovery_datain_values_datasequenceinorder_no(
					cmd, dr) < 0)
			return NULL;

		dr->generate_recovery_values = 0;
	}

	read_data_done = (!dr->recovery) ?
			cmd->read_data_done : dr->read_data_done;
	seq_send_order = (!dr->recovery) ?
			cmd->seq_send_order : dr->seq_send_order;

	read_data_left = (cmd->se_cmd.data_length - read_data_done);
	if (!read_data_left) {
		pr_err("ITT: 0x%08x read_data_left is zero!\n",
				cmd->init_task_tag);
		return NULL;
	}

	seq = iscsit_get_seq_holder_for_datain(cmd, seq_send_order);
	if (!seq)
		return NULL;

	seq->sent = 1;

	if (!dr->recovery && !seq->next_burst_len)
		seq->first_datasn = cmd->data_sn;

	offset = (seq->offset + seq->next_burst_len);

	if ((offset + conn->conn_ops->MaxRecvDataSegmentLength) >=
	     cmd->se_cmd.data_length) {
		datain->length = (cmd->se_cmd.data_length - offset);
		datain->offset = offset;

		datain->flags |= ISCSI_FLAG_CMD_FINAL;
		if (conn->sess->sess_ops->ErrorRecoveryLevel > 0)
			datain->flags |= ISCSI_FLAG_DATA_ACK;

		seq->next_burst_len = 0;
		seq_send_order++;
	} else {
		if ((seq->next_burst_len +
		     conn->conn_ops->MaxRecvDataSegmentLength) <
		     conn->sess->sess_ops->MaxBurstLength) {
			datain->length =
				conn->conn_ops->MaxRecvDataSegmentLength;
			datain->offset = (seq->offset + seq->next_burst_len);

			seq->next_burst_len += datain->length;
		} else {
			datain->length = (conn->sess->sess_ops->MaxBurstLength -
					  seq->next_burst_len);
			datain->offset = (seq->offset + seq->next_burst_len);

			datain->flags |= ISCSI_FLAG_CMD_FINAL;
			if (conn->sess->sess_ops->ErrorRecoveryLevel > 0)
				datain->flags |= ISCSI_FLAG_DATA_ACK;

			seq->next_burst_len = 0;
			seq_send_order++;
		}
	}

	if ((read_data_done + datain->length) == cmd->se_cmd.data_length)
		datain->flags |= ISCSI_FLAG_DATA_STATUS;

	datain->data_sn = (!dr->recovery) ? cmd->data_sn++ : dr->data_sn++;
	if (!dr->recovery) {
		cmd->seq_send_order = seq_send_order;
		cmd->read_data_done += datain->length;
	} else {
		dr->seq_send_order = seq_send_order;
		dr->read_data_done += datain->length;
	}

	if (!dr->recovery) {
		if (datain->flags & ISCSI_FLAG_CMD_FINAL)
			seq->last_datasn = datain->data_sn;
		if (datain->flags & ISCSI_FLAG_DATA_STATUS)
			dr->dr_complete = DATAIN_COMPLETE_NORMAL;

		return dr;
	}

	if (!dr->runlength) {
		if (datain->flags & ISCSI_FLAG_DATA_STATUS) {
			dr->dr_complete =
			    (dr->recovery == DATAIN_WITHIN_COMMAND_RECOVERY) ?
				DATAIN_COMPLETE_WITHIN_COMMAND_RECOVERY :
				DATAIN_COMPLETE_CONNECTION_RECOVERY;
		}
	} else {
		if ((dr->begrun + dr->runlength) == dr->data_sn) {
			dr->dr_complete =
			    (dr->recovery == DATAIN_WITHIN_COMMAND_RECOVERY) ?
				DATAIN_COMPLETE_WITHIN_COMMAND_RECOVERY :
				DATAIN_COMPLETE_CONNECTION_RECOVERY;
		}
	}

	return dr;
}