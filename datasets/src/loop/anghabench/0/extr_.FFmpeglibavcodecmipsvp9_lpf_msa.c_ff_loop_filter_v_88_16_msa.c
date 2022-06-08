#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  v8u16 ;
typedef  int v8i16 ;
typedef  int /*<<< orphan*/  v2i64 ;
typedef  int v16u8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int ptrdiff_t ;
typedef  int int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  ILVL_B4_UH (int,int,int,int,int,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ILVR_B8_UH (int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LD_UB8 (int /*<<< orphan*/ *,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  LPF_MASK_HEV (int,int,int,int,int,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  PCKEV_B2_SH (int,int,int,int,int,int) ; 
 int /*<<< orphan*/  PCKEV_B4_SH (int,int,int,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  ST_UB2 (int,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ST_UB4 (int,int,int,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  VP9_FILTER8 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  VP9_FLAT4 (int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  VP9_LPF_FILTER4_4W (int,int,int,int,int,int,int,int,int,int) ; 
 int __msa_bmnz_v (int,int,int) ; 
 int __msa_fill_b (int) ; 
 int __msa_ilvr_d (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ __msa_test_bz_v (int) ; 

void ff_loop_filter_v_88_16_msa(uint8_t *src, ptrdiff_t pitch,
                                int32_t b_limit_ptr,
                                int32_t limit_ptr,
                                int32_t thresh_ptr)
{
    v16u8 p3, p2, p1, p0, q3, q2, q1, q0;
    v16u8 p2_out, p1_out, p0_out, q0_out, q1_out, q2_out;
    v16u8 flat, mask, hev, tmp, thresh, b_limit, limit;
    v8u16 p3_r, p2_r, p1_r, p0_r, q0_r, q1_r, q2_r, q3_r;
    v8u16 p3_l, p2_l, p1_l, p0_l, q0_l, q1_l, q2_l, q3_l;
    v8i16 p2_filt8_r, p1_filt8_r, p0_filt8_r;
    v8i16 q0_filt8_r, q1_filt8_r, q2_filt8_r;
    v8i16 p2_filt8_l, p1_filt8_l, p0_filt8_l;
    v8i16 q0_filt8_l, q1_filt8_l, q2_filt8_l;
    v16u8 zero = { 0 };

    /* load vector elements */
    LD_UB8(src - (4 * pitch), pitch, p3, p2, p1, p0, q0, q1, q2, q3);

    thresh = (v16u8) __msa_fill_b(thresh_ptr);
    tmp = (v16u8) __msa_fill_b(thresh_ptr >> 8);
    thresh = (v16u8) __msa_ilvr_d((v2i64) tmp, (v2i64) thresh);

    b_limit = (v16u8) __msa_fill_b(b_limit_ptr);
    tmp = (v16u8) __msa_fill_b(b_limit_ptr >> 8);
    b_limit = (v16u8) __msa_ilvr_d((v2i64) tmp, (v2i64) b_limit);

    limit = (v16u8) __msa_fill_b(limit_ptr);
    tmp = (v16u8) __msa_fill_b(limit_ptr >> 8);
    limit = (v16u8) __msa_ilvr_d((v2i64) tmp, (v2i64) limit);

    /* mask and hev */
    LPF_MASK_HEV(p3, p2, p1, p0, q0, q1, q2, q3, limit, b_limit, thresh,
                 hev, mask, flat);
    VP9_FLAT4(p3, p2, p0, q0, q2, q3, flat);
    VP9_LPF_FILTER4_4W(p1, p0, q0, q1, mask, hev, p1_out, p0_out, q0_out,
                       q1_out);

    /* if flat is zero for all pixels, then no need to calculate other filter */
    if (__msa_test_bz_v(flat)) {
        ST_UB4(p1_out, p0_out, q0_out, q1_out, (src - 2 * pitch), pitch);
    } else {
        ILVR_B8_UH(zero, p3, zero, p2, zero, p1, zero, p0, zero, q0, zero, q1,
                   zero, q2, zero, q3, p3_r, p2_r, p1_r, p0_r, q0_r, q1_r,
                   q2_r, q3_r);
        VP9_FILTER8(p3_r, p2_r, p1_r, p0_r, q0_r, q1_r, q2_r, q3_r, p2_filt8_r,
                    p1_filt8_r, p0_filt8_r, q0_filt8_r, q1_filt8_r, q2_filt8_r);

        ILVL_B4_UH(zero, p3, zero, p2, zero, p1, zero, p0, p3_l, p2_l, p1_l,
                   p0_l);
        ILVL_B4_UH(zero, q0, zero, q1, zero, q2, zero, q3, q0_l, q1_l, q2_l,
                   q3_l);
        VP9_FILTER8(p3_l, p2_l, p1_l, p0_l, q0_l, q1_l, q2_l, q3_l, p2_filt8_l,
                    p1_filt8_l, p0_filt8_l, q0_filt8_l, q1_filt8_l, q2_filt8_l);

        /* convert 16 bit output data into 8 bit */
        PCKEV_B4_SH(p2_filt8_l, p2_filt8_r, p1_filt8_l, p1_filt8_r, p0_filt8_l,
                    p0_filt8_r, q0_filt8_l, q0_filt8_r, p2_filt8_r, p1_filt8_r,
                    p0_filt8_r, q0_filt8_r);
        PCKEV_B2_SH(q1_filt8_l, q1_filt8_r, q2_filt8_l, q2_filt8_r,
                    q1_filt8_r, q2_filt8_r);

        /* store pixel values */
        p2_out = __msa_bmnz_v(p2, (v16u8) p2_filt8_r, flat);
        p1_out = __msa_bmnz_v(p1_out, (v16u8) p1_filt8_r, flat);
        p0_out = __msa_bmnz_v(p0_out, (v16u8) p0_filt8_r, flat);
        q0_out = __msa_bmnz_v(q0_out, (v16u8) q0_filt8_r, flat);
        q1_out = __msa_bmnz_v(q1_out, (v16u8) q1_filt8_r, flat);
        q2_out = __msa_bmnz_v(q2, (v16u8) q2_filt8_r, flat);

        src -= 3 * pitch;

        ST_UB4(p2_out, p1_out, p0_out, q0_out, src, pitch);
        src += (4 * pitch);
        ST_UB2(q1_out, q2_out, src, pitch);
        src += (2 * pitch);
    }
}