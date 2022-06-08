#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int v8i16 ;
typedef  int /*<<< orphan*/  v16i8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int int32_t ;
typedef  int int16_t ;

/* Variables and functions */
 int /*<<< orphan*/  ILVL_B2_SH (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  ILVRL_H2_SH (int,int,int,int) ; 
 int /*<<< orphan*/  ILVR_B2_SH (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  LD_SB (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  LD_SB2 (int /*<<< orphan*/  const*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int LW (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  MUL4 (int,int,int,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  PCKEV_B4_SB (int,int,int,int,int,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SLDI_B2_SB (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  SRARI_H4_SH (int,int,int,int,int) ; 
 int /*<<< orphan*/  ST4x8_UB (int,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ST_SB (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SW (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  UNPCK_UB_SH (int /*<<< orphan*/ ,int,int) ; 
 int __msa_fill_h (int) ; 
 int* intra_pred_angle_low ; 

__attribute__((used)) static void hevc_intra_pred_angular_lower_16width_msa(const uint8_t *src_top,
                                                      const uint8_t *src_left,
                                                      uint8_t *dst,
                                                      int32_t stride,
                                                      int32_t mode)
{
    int16_t inv_angle[] = { -4096, -1638, -910, -630, -482, -390, -315 };
    int32_t h_cnt, v_cnt, idx0, fact_val0, idx1, fact_val1;
    int32_t idx2, fact_val2, idx3, fact_val3, tmp0;
    v16i8 top0, top1, dst_val0, top2, top3, dst_val1;
    v16i8 top4, top5, dst_val2, top6, top7, dst_val3;
    v8i16 fact0, fact1, fact2, fact3, fact4, fact5, fact6, fact7;
    v8i16 diff0, diff1, diff2, diff3, diff4, diff5, diff6, diff7;
    v8i16 diff8, diff9, diff10, diff11, diff12, diff13, diff14, diff15;
    int32_t angle, angle_loop, inv_angle_val, offset;
    uint8_t ref_array[3 * 32 + 4];
    uint8_t *ref_tmp = ref_array + 16;
    const uint8_t *ref, *src_top_tmp = src_top - 1;
    uint8_t *dst_org;
    int32_t last;

    angle = intra_pred_angle_low[mode - 2];
    last = (angle) >> 1;
    angle_loop = angle;

    ref = src_left - 1;
    if (last < -1) {
        inv_angle_val = inv_angle[mode - 11];

        top0 = LD_SB(ref);
        tmp0 = LW(ref + 16);
        ST_SB(top0, ref_tmp);
        SW(tmp0, ref_tmp + 16);

        for (h_cnt = last; h_cnt <= -1; h_cnt++) {
            offset = (h_cnt * inv_angle_val + 128) >> 8;
            ref_tmp[h_cnt] = src_top_tmp[offset];
        }

        ref = ref_tmp;
    }

    for (v_cnt = 0; v_cnt < 4; v_cnt++) {
        dst_org = dst;

        idx0 = angle_loop >> 5;
        fact_val0 = angle_loop & 31;
        angle_loop += angle;

        idx1 = angle_loop >> 5;
        fact_val1 = angle_loop & 31;
        angle_loop += angle;

        idx2 = angle_loop >> 5;
        fact_val2 = angle_loop & 31;
        angle_loop += angle;

        idx3 = angle_loop >> 5;
        fact_val3 = angle_loop & 31;
        angle_loop += angle;

        LD_SB2(ref + idx0 + 1, 16, top0, top1);
        LD_SB2(ref + idx1 + 1, 16, top2, top3);
        LD_SB2(ref + idx2 + 1, 16, top4, top5);
        LD_SB2(ref + idx3 + 1, 16, top6, top7);

        fact0 = __msa_fill_h(fact_val0);
        fact1 = __msa_fill_h(32 - fact_val0);
        fact2 = __msa_fill_h(fact_val1);
        fact3 = __msa_fill_h(32 - fact_val1);
        fact4 = __msa_fill_h(fact_val2);
        fact5 = __msa_fill_h(32 - fact_val2);
        fact6 = __msa_fill_h(fact_val3);
        fact7 = __msa_fill_h(32 - fact_val3);

        SLDI_B2_SB(top1, top3, top0, top2, top1, top3, 1);
        SLDI_B2_SB(top5, top7, top4, top6, top5, top7, 1);

        UNPCK_UB_SH(top0, diff0, diff1);
        UNPCK_UB_SH(top1, diff2, diff3);
        UNPCK_UB_SH(top2, diff4, diff5);
        UNPCK_UB_SH(top3, diff6, diff7);
        UNPCK_UB_SH(top4, diff8, diff9);
        UNPCK_UB_SH(top5, diff10, diff11);
        UNPCK_UB_SH(top6, diff12, diff13);
        UNPCK_UB_SH(top7, diff14, diff15);

        MUL4(diff2, fact0, diff3, fact0, diff6, fact2, diff7, fact2,
             diff2, diff3, diff6, diff7);
        MUL4(diff10, fact4, diff11, fact4, diff14, fact6, diff15, fact6,
             diff10, diff11, diff14, diff15);

        diff2 += diff0 * fact1;
        diff3 += diff1 * fact1;
        diff6 += diff4 * fact3;
        diff7 += diff5 * fact3;
        diff10 += diff8 * fact5;
        diff11 += diff9 * fact5;
        diff14 += diff12 * fact7;
        diff15 += diff13 * fact7;

        SRARI_H4_SH(diff2, diff3, diff6, diff7, 5);
        SRARI_H4_SH(diff10, diff11, diff14, diff15, 5);
        PCKEV_B4_SB(diff3, diff2, diff7, diff6, diff11, diff10, diff15, diff14,
                    dst_val0, dst_val1, dst_val2, dst_val3);
        ILVR_B2_SH(dst_val1, dst_val0, dst_val3, dst_val2, diff0, diff1);
        ILVL_B2_SH(dst_val1, dst_val0, dst_val3, dst_val2, diff2, diff3);
        ILVRL_H2_SH(diff1, diff0, diff4, diff5);
        ILVRL_H2_SH(diff3, diff2, diff6, diff7);
        ST4x8_UB(diff4, diff5, dst_org, stride);
        dst_org += (8 * stride);
        ST4x8_UB(diff6, diff7, dst_org, stride);
        dst += 4;
    }
}