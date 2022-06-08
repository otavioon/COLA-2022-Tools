#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */

/* Variables and functions */
 unsigned long DELTA_SIZE_MIN ; 
 int /*<<< orphan*/  error (char*) ; 
 int /*<<< orphan*/  free (unsigned char*) ; 
 unsigned long get_delta_hdr_size (unsigned char const**,unsigned char const*) ; 
 int /*<<< orphan*/  memcpy (unsigned char*,...) ; 
 scalar_t__ unsigned_add_overflows (unsigned long,unsigned long) ; 
 unsigned char* xmallocz (unsigned long) ; 

void *patch_delta(const void *src_buf, unsigned long src_size,
		  const void *delta_buf, unsigned long delta_size,
		  unsigned long *dst_size)
{
	const unsigned char *data, *top;
	unsigned char *dst_buf, *out, cmd;
	unsigned long size;

	if (delta_size < DELTA_SIZE_MIN)
		return NULL;

	data = delta_buf;
	top = (const unsigned char *) delta_buf + delta_size;

	/* make sure the orig file size matches what we expect */
	size = get_delta_hdr_size(&data, top);
	if (size != src_size)
		return NULL;

	/* now the result size */
	size = get_delta_hdr_size(&data, top);
	dst_buf = xmallocz(size);

	out = dst_buf;
	while (data < top) {
		cmd = *data++;
		if (cmd & 0x80) {
			unsigned long cp_off = 0, cp_size = 0;
#define PARSE_CP_PARAM(bit, var, shift) do { \
			if (cmd & (bit)) { \
				if (data >= top) \
					goto bad_length; \
				var |= ((unsigned) *data++ << (shift)); \
			} } while (0)
			PARSE_CP_PARAM(0x01, cp_off, 0);
			PARSE_CP_PARAM(0x02, cp_off, 8);
			PARSE_CP_PARAM(0x04, cp_off, 16);
			PARSE_CP_PARAM(0x08, cp_off, 24);
			PARSE_CP_PARAM(0x10, cp_size, 0);
			PARSE_CP_PARAM(0x20, cp_size, 8);
			PARSE_CP_PARAM(0x40, cp_size, 16);
#undef PARSE_CP_PARAM
			if (cp_size == 0) cp_size = 0x10000;
			if (unsigned_add_overflows(cp_off, cp_size) ||
			    cp_off + cp_size > src_size ||
			    cp_size > size)
				goto bad_length;
			memcpy(out, (char *) src_buf + cp_off, cp_size);
			out += cp_size;
			size -= cp_size;
		} else if (cmd) {
			if (cmd > size || cmd > top - data)
				goto bad_length;
			memcpy(out, data, cmd);
			out += cmd;
			data += cmd;
			size -= cmd;
		} else {
			/*
			 * cmd == 0 is reserved for future encoding
			 * extensions. In the mean time we must fail when
			 * encountering them (might be data corruption).
			 */
			error("unexpected delta opcode 0");
			goto bad;
		}
	}

	/* sanity check */
	if (data != top || size != 0) {
		bad_length:
		error("delta replay has gone wild");
		bad:
		free(dst_buf);
		return NULL;
	}

	*dst_size = out - dst_buf;
	return dst_buf;
}