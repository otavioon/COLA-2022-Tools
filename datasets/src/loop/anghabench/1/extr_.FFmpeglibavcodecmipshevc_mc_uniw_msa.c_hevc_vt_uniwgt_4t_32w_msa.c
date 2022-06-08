#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  v8i16 ;
typedef  int /*<<< orphan*/  v4i32 ;
typedef  int /*<<< orphan*/  v16u8 ;
typedef  int /*<<< orphan*/  v16i8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  HEVC_FILT_4TAP_SH (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HEVC_UNIW_RND_CLIP4_MAX_SATU_H (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ILVL_B2_SB (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ILVRL_B2_SB (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ILVR_B2_SB (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LD_SB2 (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LD_SB3 (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LD_SH (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  PCKEV_B4_UB (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SPLATI_H2_SH (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ST_UB2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  XORI_B4_128_SB (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XORI_B6_128_SB (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __msa_adds_s_h (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __msa_fill_h (int) ; 
 int /*<<< orphan*/  __msa_fill_w (int) ; 
 int /*<<< orphan*/  __msa_srar_h (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void hevc_vt_uniwgt_4t_32w_msa(uint8_t *src,
                                      int32_t src_stride,
                                      uint8_t *dst,
                                      int32_t dst_stride,
                                      const int8_t *filter,
                                      int32_t height,
                                      int32_t weight,
                                      int32_t offset,
                                      int32_t rnd_val)
{
    uint32_t loop_cnt;
    v16u8 out0, out1, out2, out3;
    v16i8 src0, src1, src2, src3, src4, src5, src6, src7, src8, src9;
    v16i8 src10_r, src32_r, src76_r, src98_r;
    v16i8 src21_r, src43_r, src65_r, src87_r;
    v8i16 dst0, dst1, dst2, dst3, dst4, dst5, dst6, dst7;
    v16i8 src10_l, src32_l, src76_l, src98_l;
    v16i8 src21_l, src43_l, src65_l, src87_l;
    v8i16 filt0, filt1;
    v8i16 filter_vec, weight_vec_h, offset_vec, denom_vec;
    v4i32 weight_vec, rnd_vec;

    src -= src_stride;

    weight = weight & 0x0000FFFF;

    weight_vec = __msa_fill_w(weight);
    rnd_vec = __msa_fill_w(rnd_val);

    weight *= 128;
    rnd_val -= 6;

    weight_vec_h = __msa_fill_h(weight);
    offset_vec = __msa_fill_h(offset);
    denom_vec = __msa_fill_h(rnd_val);

    weight_vec_h = __msa_srar_h(weight_vec_h, denom_vec);
    offset_vec = __msa_adds_s_h(offset_vec, weight_vec_h);

    filter_vec = LD_SH(filter);
    SPLATI_H2_SH(filter_vec, 0, 1, filt0, filt1);

    LD_SB3(src, src_stride, src0, src1, src2);
    LD_SB3(src + 16, src_stride, src5, src6, src7);
    src += (3 * src_stride);
    XORI_B6_128_SB(src0, src1, src2, src5, src6, src7);
    ILVR_B2_SB(src1, src0, src2, src1, src10_r, src21_r);
    ILVL_B2_SB(src1, src0, src2, src1, src10_l, src21_l);
    ILVR_B2_SB(src6, src5, src7, src6, src65_r, src76_r);
    ILVL_B2_SB(src6, src5, src7, src6, src65_l, src76_l);

    for (loop_cnt = (height >> 1); loop_cnt--;) {
        LD_SB2(src, src_stride, src3, src4);
        LD_SB2(src + 16, src_stride, src8, src9);
        src += (2 * src_stride);
        XORI_B4_128_SB(src3, src4, src8, src9);
        ILVR_B2_SB(src3, src2, src4, src3, src32_r, src43_r);
        ILVL_B2_SB(src3, src2, src4, src3, src32_l, src43_l);
        ILVRL_B2_SB(src8, src7, src87_r, src87_l);
        ILVRL_B2_SB(src9, src8, src98_r, src98_l);
        dst0 = HEVC_FILT_4TAP_SH(src10_r, src32_r, filt0, filt1);
        dst1 = HEVC_FILT_4TAP_SH(src21_r, src43_r, filt0, filt1);
        dst2 = HEVC_FILT_4TAP_SH(src10_l, src32_l, filt0, filt1);
        dst3 = HEVC_FILT_4TAP_SH(src21_l, src43_l, filt0, filt1);
        dst4 = HEVC_FILT_4TAP_SH(src65_r, src87_r, filt0, filt1);
        dst5 = HEVC_FILT_4TAP_SH(src76_r, src98_r, filt0, filt1);
        dst6 = HEVC_FILT_4TAP_SH(src65_l, src87_l, filt0, filt1);
        dst7 = HEVC_FILT_4TAP_SH(src76_l, src98_l, filt0, filt1);
        HEVC_UNIW_RND_CLIP4_MAX_SATU_H(dst0, dst1, dst2, dst3, weight_vec,
                                       offset_vec, rnd_vec, dst0, dst1, dst2,
                                       dst3);
        HEVC_UNIW_RND_CLIP4_MAX_SATU_H(dst4, dst5, dst6, dst7, weight_vec,
                                       offset_vec, rnd_vec, dst4, dst5, dst6,
                                       dst7);
        PCKEV_B4_UB(dst2, dst0, dst3, dst1, dst6, dst4, dst7, dst5, out0, out1,
                    out2, out3);
        ST_UB2(out0, out2, dst, 16);
        dst += dst_stride;
        ST_UB2(out1, out3, dst, 16);
        dst += dst_stride;

        src2 = src4;
        src7 = src9;
        src10_r = src32_r;
        src21_r = src43_r;
        src10_l = src32_l;
        src21_l = src43_l;
        src65_r = src87_r;
        src76_r = src98_r;
        src65_l = src87_l;
        src76_l = src98_l;
    }
}