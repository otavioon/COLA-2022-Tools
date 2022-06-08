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
typedef  int v16u8 ;
typedef  int /*<<< orphan*/  v16i8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int int32_t ;
typedef  int /*<<< orphan*/  int16_t ;

/* Variables and functions */
 int /*<<< orphan*/  ADD2 (int,int,int,int,int,int) ; 
 int /*<<< orphan*/  BUTTERFLY_4 (int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  CLIP_SH2_0_255 (int,int) ; 
 int CLIP_SH_0_255 (int) ; 
 int /*<<< orphan*/  ILVEV_H2_SH (int,int,int,int,int,int) ; 
 int /*<<< orphan*/  ILVRL_H2_SH (int,int,int,int) ; 
 int /*<<< orphan*/  ILVR_B2_SH (int,int,int,int,int,int) ; 
 int /*<<< orphan*/  LD_SH8 (int /*<<< orphan*/ *,int,int,int,int,int,int,int,int,int) ; 
 int LD_UB (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  PCKEV_B2_SH (int,int,int,int,int,int) ; 
 int /*<<< orphan*/  SRARI_H2_SH (int,int,int) ; 
 int /*<<< orphan*/  ST8x1_UB (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ST_SH8 (int,int,int,int,int,int,int,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  TRANSPOSE8x8_SH_SH (int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  VP9_ADST8 (int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  VP9_DOT_ADD_SUB_SRARI_PCK (int,int,int,int,int,int,int,int,int,int,int,int) ; 
 int VP9_DOT_SHIFT_RIGHT_PCK_H (int,int,int) ; 
 int __msa_fill_h (int /*<<< orphan*/ ) ; 
 int __msa_ilvev_h (int,int) ; 
 int __msa_ilvr_b (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int __msa_pckev_b (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cospi_10_64 ; 
 int /*<<< orphan*/  cospi_14_64 ; 
 int /*<<< orphan*/  cospi_16_64 ; 
 int /*<<< orphan*/  cospi_18_64 ; 
 int /*<<< orphan*/  cospi_22_64 ; 
 int /*<<< orphan*/  cospi_24_64 ; 
 int /*<<< orphan*/  cospi_26_64 ; 
 int /*<<< orphan*/  cospi_2_64 ; 
 int /*<<< orphan*/  cospi_30_64 ; 
 int /*<<< orphan*/  cospi_6_64 ; 
 int /*<<< orphan*/  cospi_8_64 ; 

__attribute__((used)) static void vp9_iadst8x8_colcol_addblk_msa(int16_t *input, uint8_t *dst,
                                           int32_t dst_stride)
{
    v8i16 in0, in1, in2, in3, in4, in5, in6, in7;
    v8i16 res0, res1, res2, res3, res4, res5, res6, res7;
    v16u8 dst0, dst1, dst2, dst3, dst4, dst5, dst6, dst7;
    v8i16 out0, out1, out2, out3, out4, out5, out6, out7;
    v8i16 cnst0, cnst1, cnst2, cnst3, cnst4;
    v8i16 temp0, temp1, temp2, temp3, s0, s1;
    v8i16 zero = { 0 };

    /* load vector elements of 8x8 block */
    LD_SH8(input, 8, in0, in1, in2, in3, in4, in5, in6, in7);
    ST_SH8(zero, zero, zero, zero, zero, zero, zero, zero, input, 8);

    /* 1D adst8x8 */
    VP9_ADST8(in0, in1, in2, in3, in4, in5, in6, in7,
              in0, in1, in2, in3, in4, in5, in6, in7);

    /* columns transform */
    TRANSPOSE8x8_SH_SH(in0, in1, in2, in3, in4, in5, in6, in7,
                       in0, in1, in2, in3, in4, in5, in6, in7);

    cnst0 = __msa_fill_h(cospi_2_64);
    cnst1 = __msa_fill_h(cospi_30_64);
    cnst2 = -cnst0;
    ILVEV_H2_SH(cnst0, cnst1, cnst1, cnst2, cnst0, cnst1);
    cnst2 = __msa_fill_h(cospi_18_64);
    cnst3 = __msa_fill_h(cospi_14_64);
    cnst4 = -cnst2;
    ILVEV_H2_SH(cnst2, cnst3, cnst3, cnst4, cnst2, cnst3);

    ILVRL_H2_SH(in0, in7, temp1, temp0);
    ILVRL_H2_SH(in4, in3, temp3, temp2);
    VP9_DOT_ADD_SUB_SRARI_PCK(temp0, temp1, temp2, temp3, cnst0, cnst1, cnst2,
                              cnst3, in7, in0, in4, in3);

    cnst0 = __msa_fill_h(cospi_10_64);
    cnst1 = __msa_fill_h(cospi_22_64);
    cnst2 = -cnst0;
    ILVEV_H2_SH(cnst0, cnst1, cnst1, cnst2, cnst0, cnst1);
    cnst2 = __msa_fill_h(cospi_26_64);
    cnst3 = __msa_fill_h(cospi_6_64);
    cnst4 = -cnst2;
    ILVEV_H2_SH(cnst2, cnst3, cnst3, cnst4, cnst2, cnst3);

    ILVRL_H2_SH(in2, in5, temp1, temp0);
    ILVRL_H2_SH(in6, in1, temp3, temp2);
    VP9_DOT_ADD_SUB_SRARI_PCK(temp0, temp1, temp2, temp3, cnst0, cnst1, cnst2,
                              cnst3, in5, in2, in6, in1);
    BUTTERFLY_4(in7, in0, in2, in5, s1, s0, in2, in5);
    out7 = -s0;
    out0 = s1;
    SRARI_H2_SH(out0, out7, 5);
    dst0 = LD_UB(dst + 0 * dst_stride);
    dst7 = LD_UB(dst + 7 * dst_stride);

    res0 = (v8i16) __msa_ilvr_b((v16i8) zero, (v16i8) dst0);
    res0 += out0;
    res0 = CLIP_SH_0_255(res0);
    res0 = (v8i16) __msa_pckev_b((v16i8) res0, (v16i8) res0);
    ST8x1_UB(res0, dst);

    res7 = (v8i16) __msa_ilvr_b((v16i8) zero, (v16i8) dst7);
    res7 += out7;
    res7 = CLIP_SH_0_255(res7);
    res7 = (v8i16) __msa_pckev_b((v16i8) res7, (v16i8) res7);
    ST8x1_UB(res7, dst + 7 * dst_stride);

    cnst1 = __msa_fill_h(cospi_24_64);
    cnst0 = __msa_fill_h(cospi_8_64);
    cnst3 = -cnst1;
    cnst2 = -cnst0;

    ILVEV_H2_SH(cnst3, cnst0, cnst1, cnst2, cnst3, cnst2);
    cnst0 = __msa_ilvev_h(cnst1, cnst0);
    cnst1 = cnst0;

    ILVRL_H2_SH(in4, in3, temp1, temp0);
    ILVRL_H2_SH(in6, in1, temp3, temp2);
    VP9_DOT_ADD_SUB_SRARI_PCK(temp0, temp1, temp2, temp3, cnst0, cnst2, cnst3,
                              cnst1, out1, out6, s0, s1);
    out1 = -out1;
    SRARI_H2_SH(out1, out6, 5);
    dst1 = LD_UB(dst + 1 * dst_stride);
    dst6 = LD_UB(dst + 6 * dst_stride);
    ILVR_B2_SH(zero, dst1, zero, dst6, res1, res6);
    ADD2(res1, out1, res6, out6, res1, res6);
    CLIP_SH2_0_255(res1, res6);
    PCKEV_B2_SH(res1, res1, res6, res6, res1, res6);
    ST8x1_UB(res1, dst + dst_stride);
    ST8x1_UB(res6, dst + 6 * dst_stride);

    cnst0 = __msa_fill_h(cospi_16_64);
    cnst1 = -cnst0;
    cnst1 = __msa_ilvev_h(cnst1, cnst0);

    ILVRL_H2_SH(in2, in5, temp1, temp0);
    ILVRL_H2_SH(s0, s1, temp3, temp2);
    out3 = VP9_DOT_SHIFT_RIGHT_PCK_H(temp0, temp1, cnst0);
    out4 = VP9_DOT_SHIFT_RIGHT_PCK_H(temp0, temp1, cnst1);
    out3 = -out3;
    SRARI_H2_SH(out3, out4, 5);
    dst3 = LD_UB(dst + 3 * dst_stride);
    dst4 = LD_UB(dst + 4 * dst_stride);
    ILVR_B2_SH(zero, dst3, zero, dst4, res3, res4);
    ADD2(res3, out3, res4, out4, res3, res4);
    CLIP_SH2_0_255(res3, res4);
    PCKEV_B2_SH(res3, res3, res4, res4, res3, res4);
    ST8x1_UB(res3, dst + 3 * dst_stride);
    ST8x1_UB(res4, dst + 4 * dst_stride);

    out2 = VP9_DOT_SHIFT_RIGHT_PCK_H(temp2, temp3, cnst0);
    out5 = VP9_DOT_SHIFT_RIGHT_PCK_H(temp2, temp3, cnst1);
    out5 = -out5;
    SRARI_H2_SH(out2, out5, 5);
    dst2 = LD_UB(dst + 2 * dst_stride);
    dst5 = LD_UB(dst + 5 * dst_stride);
    ILVR_B2_SH(zero, dst2, zero, dst5, res2, res5);
    ADD2(res2, out2, res5, out5, res2, res5);
    CLIP_SH2_0_255(res2, res5);
    PCKEV_B2_SH(res2, res2, res5, res5, res2, res5);
    ST8x1_UB(res2, dst + 2 * dst_stride);
    ST8x1_UB(res5, dst + 5 * dst_stride);
}