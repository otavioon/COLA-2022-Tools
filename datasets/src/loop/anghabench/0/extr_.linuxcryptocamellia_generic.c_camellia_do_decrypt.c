#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 int /*<<< orphan*/  CAMELLIA_FLS (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CAMELLIA_ROUNDSM (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SUBKEY_L (int) ; 
 int /*<<< orphan*/  SUBKEY_R (int) ; 

__attribute__((used)) static void camellia_do_decrypt(const u32 *subkey, u32 *io, unsigned i)
{
	u32 il, ir, t0, t1;            /* temporary variables */

	/* pre whitening but absorb kw2 */
	io[0] ^= SUBKEY_L(i);
	io[1] ^= SUBKEY_R(i);

	/* main iteration */
#define ROUNDS(i) ({ \
	CAMELLIA_ROUNDSM(io[0], io[1], \
			 SUBKEY_L(i + 7), SUBKEY_R(i + 7), \
			 io[2], io[3], il, ir); \
	CAMELLIA_ROUNDSM(io[2], io[3], \
			 SUBKEY_L(i + 6), SUBKEY_R(i + 6), \
			 io[0], io[1], il, ir); \
	CAMELLIA_ROUNDSM(io[0], io[1], \
			 SUBKEY_L(i + 5), SUBKEY_R(i + 5), \
			 io[2], io[3], il, ir); \
	CAMELLIA_ROUNDSM(io[2], io[3], \
			 SUBKEY_L(i + 4), SUBKEY_R(i + 4), \
			 io[0], io[1], il, ir); \
	CAMELLIA_ROUNDSM(io[0], io[1], \
			 SUBKEY_L(i + 3), SUBKEY_R(i + 3), \
			 io[2], io[3], il, ir); \
	CAMELLIA_ROUNDSM(io[2], io[3], \
			 SUBKEY_L(i + 2), SUBKEY_R(i + 2), \
			 io[0], io[1], il, ir); \
})
#define FLS(i) ({ \
	CAMELLIA_FLS(io[0], io[1], io[2], io[3], \
		     SUBKEY_L(i + 1), SUBKEY_R(i + 1), \
		     SUBKEY_L(i + 0), SUBKEY_R(i + 0), \
		     t0, t1, il, ir); \
})

	if (i == 32) {
		ROUNDS(24);
		FLS(24);
	}
	ROUNDS(16);
	FLS(16);
	ROUNDS(8);
	FLS(8);
	ROUNDS(0);

#undef ROUNDS
#undef FLS

	/* post whitening but kw4 */
	io[2] ^= SUBKEY_L(0);
	io[3] ^= SUBKEY_R(0);
	/* NB: 0,1 should be swapped with 2,3 by caller! */
}