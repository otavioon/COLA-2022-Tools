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
 int /*<<< orphan*/  ILVL_B2_SH (int,int,int,int,int,int) ; 
 int /*<<< orphan*/  ILVRL_B2_SH (int,int,int,int) ; 
 int /*<<< orphan*/  ILVRL_H2_SH (int,int,int,int) ; 
 int /*<<< orphan*/  ILVR_B2_SH (int,int,int,int,int,int) ; 
 int /*<<< orphan*/  ILVR_B8_UH (int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LD_UB8 (int /*<<< orphan*/ *,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  LPF_MASK_HEV (int,int,int,int,int,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  PCKEV_B2_SH (int,int,int,int,int,int) ; 
 int /*<<< orphan*/  PCKEV_B4_SH (int,int,int,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  ST2x4_UB (int,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ST4x4_UB (int,int,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ST4x8_UB (int,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  TRANSPOSE16x8_UB_UB (int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  VP9_FILTER8 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  VP9_FLAT4 (int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  VP9_LPF_FILTER4_4W (int,int,int,int,int,int,int,int,int,int) ; 
 int __msa_bmnz_v (int,int,int) ; 
 int __msa_fill_b (int) ; 
 int __msa_ilvr_d (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ __msa_test_bz_v (int) ; 

void ff_loop_filter_h_84_16_msa(uint8_t *src, ptrdiff_t pitch,
                                int32_t b_limit_ptr,
                                int32_t limit_ptr,
                                int32_t thresh_ptr)
{
    uint8_t *temp_src;
    v16u8 p3, p2, p1, p0, q3, q2, q1, q0;
    v16u8 p1_out, p0_out, q0_out, q1_out;
    v16u8 flat, mask, hev, thresh, b_limit, limit;
    v16u8 row4, row5, row6, row7, row12, row13, row14, row15;
    v8u16 p3_r, p2_r, p1_r, p0_r, q0_r, q1_r, q2_r, q3_r;
    v8i16 p2_filt8_r, p1_filt8_r, p0_filt8_r;
    v8i16 q0_filt8_r, q1_filt8_r, q2_filt8_r;
    v16u8 zero = { 0 };
    v8i16 vec0, vec1, vec2, vec3, vec4, vec5, vec6, vec7;

    temp_src = src - 4;

    LD_UB8(temp_src, pitch, p0, p1, p2, p3, row4, row5, row6, row7);
    temp_src += (8 * pitch);
    LD_UB8(temp_src, pitch, q3, q2, q1, q0, row12, row13, row14, row15);

    /* transpose 16x8 matrix into 8x16 */
    TRANSPOSE16x8_UB_UB(p0, p1, p2, p3, row4, row5, row6, row7,
                        q3, q2, q1, q0, row12, row13, row14, row15,
                        p3, p2, p1, p0, q0, q1, q2, q3);

    thresh = (v16u8) __msa_fill_b(thresh_ptr);
    vec0 = (v8i16) __msa_fill_b(thresh_ptr >> 8);
    thresh = (v16u8) __msa_ilvr_d((v2i64) vec0, (v2i64) thresh);

    b_limit = (v16u8) __msa_fill_b(b_limit_ptr);
    vec0 = (v8i16) __msa_fill_b(b_limit_ptr >> 8);
    b_limit = (v16u8) __msa_ilvr_d((v2i64) vec0, (v2i64) b_limit);

    limit = (v16u8) __msa_fill_b(limit_ptr);
    vec0 = (v8i16) __msa_fill_b(limit_ptr >> 8);
    limit = (v16u8) __msa_ilvr_d((v2i64) vec0, (v2i64) limit);

    /* mask and hev */
    LPF_MASK_HEV(p3, p2, p1, p0, q0, q1, q2, q3, limit, b_limit, thresh,
                 hev, mask, flat);
    /* flat4 */
    VP9_FLAT4(p3, p2, p0, q0, q2, q3, flat);
    /* filter4 */
    VP9_LPF_FILTER4_4W(p1, p0, q0, q1, mask, hev, p1_out, p0_out, q0_out,
                       q1_out);

    flat = (v16u8) __msa_ilvr_d((v2i64) zero, (v2i64) flat);

    /* if flat is zero for all pixels, then no need to calculate other filter */
    if (__msa_test_bz_v(flat)) {
        ILVR_B2_SH(p0_out, p1_out, q1_out, q0_out, vec0, vec1);
        ILVRL_H2_SH(vec1, vec0, vec2, vec3);
        ILVL_B2_SH(p0_out, p1_out, q1_out, q0_out, vec0, vec1);
        ILVRL_H2_SH(vec1, vec0, vec4, vec5);

        src -= 2;
        ST4x8_UB(vec2, vec3, src, pitch);
        src += 8 * pitch;
        ST4x8_UB(vec4, vec5, src, pitch);
    } else {
        ILVR_B8_UH(zero, p3, zero, p2, zero, p1, zero, p0, zero, q0, zero, q1,
                   zero, q2, zero, q3, p3_r, p2_r, p1_r, p0_r, q0_r, q1_r, q2_r,
                   q3_r);
        VP9_FILTER8(p3_r, p2_r, p1_r, p0_r, q0_r, q1_r, q2_r, q3_r, p2_filt8_r,
                    p1_filt8_r, p0_filt8_r, q0_filt8_r, q1_filt8_r, q2_filt8_r);

        /* convert 16 bit output data into 8 bit */
        PCKEV_B4_SH(p2_filt8_r, p2_filt8_r, p1_filt8_r, p1_filt8_r,
                    p0_filt8_r, p0_filt8_r, q0_filt8_r, q0_filt8_r,
                    p2_filt8_r, p1_filt8_r, p0_filt8_r, q0_filt8_r);
        PCKEV_B2_SH(q1_filt8_r, q1_filt8_r, q2_filt8_r, q2_filt8_r,
                    q1_filt8_r, q2_filt8_r);

        /* store pixel values */
        p2 = __msa_bmnz_v(p2, (v16u8) p2_filt8_r, flat);
        p1 = __msa_bmnz_v(p1_out, (v16u8) p1_filt8_r, flat);
        p0 = __msa_bmnz_v(p0_out, (v16u8) p0_filt8_r, flat);
        q0 = __msa_bmnz_v(q0_out, (v16u8) q0_filt8_r, flat);
        q1 = __msa_bmnz_v(q1_out, (v16u8) q1_filt8_r, flat);
        q2 = __msa_bmnz_v(q2, (v16u8) q2_filt8_r, flat);

        ILVR_B2_SH(p1, p2, q0, p0, vec0, vec1);
        ILVRL_H2_SH(vec1, vec0, vec3, vec4);
        ILVL_B2_SH(p1, p2, q0, p0, vec0, vec1);
        ILVRL_H2_SH(vec1, vec0, vec6, vec7);
        ILVRL_B2_SH(q2, q1, vec2, vec5);

        src -= 3;
        ST4x4_UB(vec3, vec3, 0, 1, 2, 3, src, pitch);
        ST2x4_UB(vec2, 0, src + 4, pitch);
        src += (4 * pitch);
        ST4x4_UB(vec4, vec4, 0, 1, 2, 3, src, pitch);
        ST2x4_UB(vec2, 4, src + 4, pitch);
        src += (4 * pitch);
        ST4x4_UB(vec6, vec6, 0, 1, 2, 3, src, pitch);
        ST2x4_UB(vec5, 0, src + 4, pitch);
        src += (4 * pitch);
        ST4x4_UB(vec7, vec7, 0, 1, 2, 3, src, pitch);
        ST2x4_UB(vec5, 4, src + 4, pitch);
    }
}