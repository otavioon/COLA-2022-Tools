#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int v8i16 ;
typedef  int /*<<< orphan*/  v4i32 ;
struct TYPE_9__ {int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ v16u8 ;
typedef  scalar_t__ v16i8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int ptrdiff_t ;
typedef  int int16_t ;

/* Variables and functions */
 int AVC_DOT_SH3_SH (scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  DPADD_SH2_SW (int,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ILVL_B4_SB (scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  ILVR_B4_SB (scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  INSERT_W4_UB (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__) ; 
 int /*<<< orphan*/  LD_SB4 (int /*<<< orphan*/  const*,int,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  LD_SB5 (int /*<<< orphan*/  const*,int,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  LW4 (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PCKEV_H2_SH (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 TYPE_1__ PCKEV_XORI128_UB (int,int) ; 
 int /*<<< orphan*/  SAT_SH2_SH (int,int,int) ; 
 int /*<<< orphan*/  SAT_SW2_SW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  SRARI_W2_SW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ST4x4_UB (TYPE_1__,TYPE_1__,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  VSHF_H3_SH (int,int,int,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  XORI_B4_128_SB (scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  XORI_B5_128_SB (scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  __msa_aver_s_w (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_1__ __msa_aver_u_b (TYPE_1__,TYPE_1__) ; 
 int __msa_fill_h (int const) ; 
 int /*<<< orphan*/  __msa_hadd_s_w (int,int) ; 
 int __msa_ilvod_h (int,int) ; 
 int __msa_ldi_h (int) ; 
 int __msa_srari_h (int,int) ; 

void ff_avg_h264_qpel4_mc32_msa(uint8_t *dst, const uint8_t *src,
                                ptrdiff_t stride)
{
    uint32_t tp0, tp1, tp2, tp3;
    const int16_t filt_const0 = 0xfb01;
    const int16_t filt_const1 = 0x1414;
    const int16_t filt_const2 = 0x1fb;
    v16u8 out, dstv = { 0 };
    v16i8 src0, src1, src2, src3, src4, src5, src6, src7, src8;
    v16i8 src10_r, src21_r, src32_r, src43_r, src54_r, src65_r, src76_r;
    v16i8 src87_r, src10_l, src21_l, src32_l, src43_l, src54_l, src65_l;
    v16i8 src76_l, src87_l, filt0, filt1, filt2;
    v8i16 vt_res0, vt_res1, vt_res2, vt_res3, dst0, dst1, dst2, dst3, shf_vec7;
    v8i16 shf_vec0, shf_vec1, shf_vec2, shf_vec3, shf_vec4, shf_vec5, shf_vec6;
    v4i32 hz_res0, hz_res1, hz_res2, hz_res3;
    v8i16 mask0 = { 0, 5, 1, 6, 2, 7, 3, 8 };
    v8i16 mask1 = { 1, 4, 2, 5, 3, 6, 4, 7 };
    v8i16 mask2 = { 2, 3, 3, 4, 4, 5, 5, 6 };
    v8i16 minus5h = __msa_ldi_h(-5);
    v8i16 plus20h = __msa_ldi_h(20);
    v8i16 zeros = { 0 };

    filt0 = (v16i8) __msa_fill_h(filt_const0);
    filt1 = (v16i8) __msa_fill_h(filt_const1);
    filt2 = (v16i8) __msa_fill_h(filt_const2);

    src -= ((2 * stride) + 2);

    LD_SB5(src, stride, src0, src1, src2, src3, src4);
    src += (5 * stride);
    XORI_B5_128_SB(src0, src1, src2, src3, src4);
    LD_SB4(src, stride, src5, src6, src7, src8);
    XORI_B4_128_SB(src5, src6, src7, src8);

    ILVR_B4_SB(src1, src0, src2, src1, src3, src2, src4, src3, src10_r, src21_r,
               src32_r, src43_r);
    ILVR_B4_SB(src5, src4, src6, src5, src7, src6, src8, src7, src54_r, src65_r,
               src76_r, src87_r);
    ILVL_B4_SB(src1, src0, src2, src1, src3, src2, src4, src3, src10_l, src21_l,
               src32_l, src43_l);
    ILVL_B4_SB(src5, src4, src6, src5, src7, src6, src8, src7, src54_l, src65_l,
               src76_l, src87_l);
    vt_res0 = AVC_DOT_SH3_SH(src10_r, src32_r, src54_r, filt0, filt1, filt2);
    vt_res1 = AVC_DOT_SH3_SH(src10_l, src32_l, src54_l, filt0, filt1, filt2);
    vt_res2 = AVC_DOT_SH3_SH(src21_r, src43_r, src65_r, filt0, filt1, filt2);
    vt_res3 = AVC_DOT_SH3_SH(src21_l, src43_l, src65_l, filt0, filt1, filt2);
    VSHF_H3_SH(vt_res0, vt_res1, vt_res0, vt_res1, vt_res0, vt_res1, mask0,
               mask1, mask2, shf_vec0, shf_vec1, shf_vec2);
    VSHF_H3_SH(vt_res2, vt_res3, vt_res2, vt_res3, vt_res2, vt_res3, mask0,
               mask1, mask2, shf_vec3, shf_vec4, shf_vec5);
    hz_res0 = __msa_hadd_s_w(shf_vec0, shf_vec0);
    DPADD_SH2_SW(shf_vec1, shf_vec2, minus5h, plus20h, hz_res0, hz_res0);
    hz_res1 = __msa_hadd_s_w(shf_vec3, shf_vec3);
    DPADD_SH2_SW(shf_vec4, shf_vec5, minus5h, plus20h, hz_res1, hz_res1);

    vt_res0 = AVC_DOT_SH3_SH(src32_r, src54_r, src76_r, filt0, filt1, filt2);
    vt_res1 = AVC_DOT_SH3_SH(src32_l, src54_l, src76_l, filt0, filt1, filt2);
    vt_res2 = AVC_DOT_SH3_SH(src43_r, src65_r, src87_r, filt0, filt1, filt2);
    vt_res3 = AVC_DOT_SH3_SH(src43_l, src65_l, src87_l, filt0, filt1, filt2);
    VSHF_H3_SH(vt_res0, vt_res1, vt_res0, vt_res1, vt_res0, vt_res1, mask0,
               mask1, mask2, shf_vec0, shf_vec1, shf_vec6);
    VSHF_H3_SH(vt_res2, vt_res3, vt_res2, vt_res3, vt_res2, vt_res3, mask0,
               mask1, mask2, shf_vec3, shf_vec4, shf_vec7);
    hz_res2 = __msa_hadd_s_w(shf_vec0, shf_vec0);
    DPADD_SH2_SW(shf_vec1, shf_vec6, minus5h, plus20h, hz_res2, hz_res2);
    hz_res3 = __msa_hadd_s_w(shf_vec3, shf_vec3);
    DPADD_SH2_SW(shf_vec4, shf_vec7, minus5h, plus20h, hz_res3, hz_res3);

    SRARI_W2_SW(hz_res0, hz_res1, 10);
    SAT_SW2_SW(hz_res0, hz_res1, 7);
    SRARI_W2_SW(hz_res2, hz_res3, 10);
    SAT_SW2_SW(hz_res2, hz_res3, 7);

    dst0 = __msa_srari_h(shf_vec2, 5);
    dst1 = __msa_srari_h(shf_vec5, 5);
    dst2 = __msa_srari_h(shf_vec6, 5);
    dst3 = __msa_srari_h(shf_vec7, 5);

    SAT_SH2_SH(dst0, dst1, 7);
    SAT_SH2_SH(dst2, dst3, 7);

    dst0 = __msa_ilvod_h(zeros, dst0);
    dst1 = __msa_ilvod_h(zeros, dst1);
    dst2 = __msa_ilvod_h(zeros, dst2);
    dst3 = __msa_ilvod_h(zeros, dst3);

    hz_res0 = __msa_aver_s_w(hz_res0, (v4i32) dst0);
    hz_res1 = __msa_aver_s_w(hz_res1, (v4i32) dst1);
    hz_res2 = __msa_aver_s_w(hz_res2, (v4i32) dst2);
    hz_res3 = __msa_aver_s_w(hz_res3, (v4i32) dst3);

    LW4(dst, stride, tp0, tp1, tp2, tp3);
    INSERT_W4_UB(tp0, tp1, tp2, tp3, dstv);
    PCKEV_H2_SH(hz_res1, hz_res0, hz_res3, hz_res2, dst0, dst2);
    out = PCKEV_XORI128_UB(dst0, dst2);
    out = __msa_aver_u_b(out, dstv);
    ST4x4_UB(out, out, 0, 1, 2, 3, dst, stride);
}