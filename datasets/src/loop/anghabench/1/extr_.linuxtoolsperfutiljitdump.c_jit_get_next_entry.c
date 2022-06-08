#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int pid; int tid; size_t vma; size_t old_code_addr; size_t new_code_addr; size_t code_size; size_t code_index; } ;
struct TYPE_10__ {int pid; int tid; size_t vma; size_t code_addr; size_t code_size; size_t code_index; } ;
struct TYPE_9__ {size_t unwinding_size; size_t eh_frame_hdr_size; size_t mapped_size; } ;
struct TYPE_8__ {size_t code_addr; size_t nr_entry; TYPE_2__* entries; } ;
union jr_entry {TYPE_1__ move; TYPE_5__ load; TYPE_4__ unwinding; TYPE_3__ info; } ;
typedef  size_t uint64_t ;
struct jr_prefix {int id; int total_size; size_t timestamp; } ;
struct jit_buf_desc {size_t bufsize; scalar_t__ needs_bswap; int /*<<< orphan*/  code_load_count; struct jr_prefix* buf; int /*<<< orphan*/  in; } ;
struct TYPE_7__ {size_t addr; int lineno; int discrim; } ;

/* Variables and functions */
#define  JIT_CODE_CLOSE 133 
#define  JIT_CODE_DEBUG_INFO 132 
#define  JIT_CODE_LOAD 131 
#define  JIT_CODE_MAX 130 
#define  JIT_CODE_MOVE 129 
#define  JIT_CODE_UNWINDING_INFO 128 
 void* bswap_32 (int) ; 
 void* bswap_64 (size_t) ; 
 int fread (struct jr_prefix*,size_t,int,int /*<<< orphan*/ ) ; 
 size_t getpagesize () ; 
 struct jr_prefix* malloc (size_t) ; 
 int /*<<< orphan*/  pr_warning (char*,int) ; 
 struct jr_prefix* realloc (struct jr_prefix*,size_t) ; 

__attribute__((used)) static union jr_entry *
jit_get_next_entry(struct jit_buf_desc *jd)
{
	struct jr_prefix *prefix;
	union jr_entry *jr;
	void *addr;
	size_t bs, size;
	int id, ret;

	if (!(jd && jd->in))
		return NULL;

	if (jd->buf == NULL) {
		size_t sz = getpagesize();
		if (sz < sizeof(*prefix))
			sz = sizeof(*prefix);

		jd->buf = malloc(sz);
		if (jd->buf == NULL)
			return NULL;

		jd->bufsize = sz;
	}

	prefix = jd->buf;

	/*
	 * file is still locked at this point
	 */
	ret = fread(prefix, sizeof(*prefix), 1, jd->in);
	if (ret  != 1)
		return NULL;

	if (jd->needs_bswap) {
		prefix->id   	   = bswap_32(prefix->id);
		prefix->total_size = bswap_32(prefix->total_size);
		prefix->timestamp  = bswap_64(prefix->timestamp);
	}
	id   = prefix->id;
	size = prefix->total_size;

	bs = (size_t)size;
	if (bs < sizeof(*prefix))
		return NULL;

	if (id >= JIT_CODE_MAX) {
		pr_warning("next_entry: unknown record type %d, skipping\n", id);
	}
	if (bs > jd->bufsize) {
		void *n;
		n = realloc(jd->buf, bs);
		if (!n)
			return NULL;
		jd->buf = n;
		jd->bufsize = bs;
	}

	addr = ((void *)jd->buf) + sizeof(*prefix);

	ret = fread(addr, bs - sizeof(*prefix), 1, jd->in);
	if (ret != 1)
		return NULL;

	jr = (union jr_entry *)jd->buf;

	switch(id) {
	case JIT_CODE_DEBUG_INFO:
		if (jd->needs_bswap) {
			uint64_t n;
			jr->info.code_addr = bswap_64(jr->info.code_addr);
			jr->info.nr_entry  = bswap_64(jr->info.nr_entry);
			for (n = 0 ; n < jr->info.nr_entry; n++) {
				jr->info.entries[n].addr    = bswap_64(jr->info.entries[n].addr);
				jr->info.entries[n].lineno  = bswap_32(jr->info.entries[n].lineno);
				jr->info.entries[n].discrim = bswap_32(jr->info.entries[n].discrim);
			}
		}
		break;
	case JIT_CODE_UNWINDING_INFO:
		if (jd->needs_bswap) {
			jr->unwinding.unwinding_size = bswap_64(jr->unwinding.unwinding_size);
			jr->unwinding.eh_frame_hdr_size = bswap_64(jr->unwinding.eh_frame_hdr_size);
			jr->unwinding.mapped_size = bswap_64(jr->unwinding.mapped_size);
		}
		break;
	case JIT_CODE_CLOSE:
		break;
	case JIT_CODE_LOAD:
		if (jd->needs_bswap) {
			jr->load.pid       = bswap_32(jr->load.pid);
			jr->load.tid       = bswap_32(jr->load.tid);
			jr->load.vma       = bswap_64(jr->load.vma);
			jr->load.code_addr = bswap_64(jr->load.code_addr);
			jr->load.code_size = bswap_64(jr->load.code_size);
			jr->load.code_index= bswap_64(jr->load.code_index);
		}
		jd->code_load_count++;
		break;
	case JIT_CODE_MOVE:
		if (jd->needs_bswap) {
			jr->move.pid           = bswap_32(jr->move.pid);
			jr->move.tid           = bswap_32(jr->move.tid);
			jr->move.vma           = bswap_64(jr->move.vma);
			jr->move.old_code_addr = bswap_64(jr->move.old_code_addr);
			jr->move.new_code_addr = bswap_64(jr->move.new_code_addr);
			jr->move.code_size     = bswap_64(jr->move.code_size);
			jr->move.code_index    = bswap_64(jr->move.code_index);
		}
		break;
	case JIT_CODE_MAX:
	default:
		/* skip unknown record (we have read them) */
		break;
	}
	return jr;
}