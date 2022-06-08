#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int ut8 ;
typedef  void* ut64 ;
typedef  int ut32 ;
typedef  int ut16 ;
typedef  int /*<<< orphan*/  st8 ;
typedef  int /*<<< orphan*/  st16 ;
struct TYPE_4__ {int jump; int fail; int ptr; int val; int size; void* type; void* addr; } ;
typedef  TYPE_1__ RAnalOp ;
typedef  int /*<<< orphan*/  RAnal ;

/* Variables and functions */
 void* R_ANAL_OP_TYPE_CALL ; 
 void* R_ANAL_OP_TYPE_CJMP ; 
 void* R_ANAL_OP_TYPE_JMP ; 
 void* R_ANAL_OP_TYPE_NOP ; 
 void* R_ANAL_OP_TYPE_RET ; 
 void* R_ANAL_OP_TYPE_UCALL ; 
 void* R_ANAL_OP_TYPE_UNK ; 
 int get_ins_len (int const) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 

int tms320_c55x_plus_op(RAnal *anal, RAnalOp *op, ut64 addr, const ut8 *buf, int len) {
	ut16 *ins = (ut16*)buf;
	ut32 ins_len;

	if (!buf || len <= 0) {
		return 0;
	}

	ins_len = get_ins_len(buf[0]);
	if (ins_len == 0) {
		return 0;
	}

	memset (op, 0, sizeof (RAnalOp));
	op->type = R_ANAL_OP_TYPE_UNK;
	op->addr = addr;
	op->jump = op->fail = -1;
	op->ptr = op->val = -1;
        op->size = ins_len;

	if (ins_len == 1) {
		if (*ins == 0x20) {
			op->type = R_ANAL_OP_TYPE_NOP;
		} else if (*ins == 0x21) {
			op->type = R_ANAL_OP_TYPE_RET;
		}
	} else if (ins_len >= 4 && buf[0] == 0xD8) {
		//  BCC conditional absolute jump
		op->type = R_ANAL_OP_TYPE_CJMP;
		op->jump = (buf[1] << 16) | (buf[2] << 8) | buf[3];
	} else if (ins_len >= 2 && buf[0] == 0x6A) {
		//  BCC conditional relative jump
		op->type = R_ANAL_OP_TYPE_CJMP;
		op->jump = addr + ((st8)buf[1]) + ins_len;
	} else if (ins_len >= 3 && buf[0] == 0x9A) {
		// BCC conditional relative jump
		op->type = R_ANAL_OP_TYPE_CJMP;
		op->jump = addr + (st16)((buf[1] << 8) | buf[2]) + ins_len;
	} else if (ins_len >= 4 && buf[0] == 0x9C) {
		// B unconditional absolute jump
		op->type = R_ANAL_OP_TYPE_JMP;
		op->jump = (buf[1] << 16) | (buf[2] << 8) | buf[3];
	} else if (ins_len >= 3 && buf[0] == 0x68) {
		// B unconditional relative jump
		op->type = R_ANAL_OP_TYPE_JMP;
		op->jump = addr + (st16)((buf[1] << 8) | buf[2]) + ins_len;
 	} else if (ins_len == 2 && buf[0] == 0x02) {
		// CALL unconditional absolute call with acumulator register ACx

		op->type = R_ANAL_OP_TYPE_UCALL;
		op->fail = addr + ins_len;
 	} else if (ins_len >= 3 && buf[0] == 0x69) {
		// CALL unconditional relative call
		op->type = R_ANAL_OP_TYPE_CALL;
		op->jump = addr + (st16)((buf[1] << 8) | buf[2]) + ins_len;
 	} else if (ins_len >= 3 && buf[0] == 0x9D) {
		// CALL unconditional absolute call
		op->type = R_ANAL_OP_TYPE_CALL;
		op->jump = (buf[1] << 16) | (buf[2] << 8) | buf[3];
 	} else if (ins_len >= 3 && buf[0] == 0x9B) {
		// CALLCC conditional relative call
		op->type = R_ANAL_OP_TYPE_CALL;
		op->jump = addr + (st16)((buf[1] << 8) | buf[2]) + ins_len;
 	} else if (ins_len >= 4 && buf[0] == 0xD9) {
		// CALLCC conditional absolute call
		op->type = R_ANAL_OP_TYPE_CALL;
		op->jump = (buf[1] << 16) | (buf[2] << 8) | buf[3];
	} else {
		op->type = R_ANAL_OP_TYPE_UNK;
	}
	return op->size;
}