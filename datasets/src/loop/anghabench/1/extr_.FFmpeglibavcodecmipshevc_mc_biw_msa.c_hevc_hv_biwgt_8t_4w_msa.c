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
typedef  int v4i32 ;
typedef  int /*<<< orphan*/  v2i64 ;
typedef  scalar_t__ v16u8 ;
typedef  scalar_t__ v16i8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int int32_t ;
typedef  int /*<<< orphan*/  int16_t ;

/* Variables and functions */
 int /*<<< orphan*/  CLIP_SW4_0_255_MAX_SATU (int,int,int,int) ; 
 int HEVC_FILT_8TAP (int,int,int,int,int,int,int,int) ; 
 int HEVC_FILT_8TAP_SH (scalar_t__,scalar_t__,scalar_t__,scalar_t__,int,int,int,int) ; 
 int /*<<< orphan*/  ILVRL_H2_SH (int,int,int,int) ; 
 int /*<<< orphan*/  INSERT_D2_SH (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  LD2 (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ LD_SB (scalar_t__) ; 
 int /*<<< orphan*/  LD_SB4 (int /*<<< orphan*/ *,int,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  LD_SB7 (int /*<<< orphan*/ *,int,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int LD_SH (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  PCKEV_H2_SH (int,int,int,int,int,int) ; 
 int /*<<< orphan*/  SPLATI_H4_SH (int,int /*<<< orphan*/ ,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  SPLATI_W4_SH (int,int,int,int,int) ; 
 int /*<<< orphan*/  SRAR_W4_SW (int,int,int,int,int) ; 
 int /*<<< orphan*/  SRA_4V (int,int,int,int,int) ; 
 int /*<<< orphan*/  ST4x4_UB (scalar_t__,scalar_t__,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  UNPCK_R_SB_SH (int,int) ; 
 int /*<<< orphan*/  VSHF_B4_SB (scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  XORI_B4_128_SB (scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  XORI_B7_128_SB (scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int __msa_dpadd_s_w (int,int,int) ; 
 int __msa_fill_w (int) ; 
 int __msa_ilvr_h (int,int) ; 
 int __msa_pckev_b (scalar_t__,scalar_t__) ; 
 int __msa_splati_d (int /*<<< orphan*/ ,int) ; 
 scalar_t__ ff_hevc_mask_arr ; 

__attribute__((used)) static void hevc_hv_biwgt_8t_4w_msa(uint8_t *src0_ptr,
                                    int32_t src_stride,
                                    int16_t *src1_ptr,
                                    int32_t src2_stride,
                                    uint8_t *dst,
                                    int32_t dst_stride,
                                    const int8_t *filter_x,
                                    const int8_t *filter_y,
                                    int32_t height,
                                    int32_t weight0,
                                    int32_t weight1,
                                    int32_t offset0,
                                    int32_t offset1,
                                    int32_t rnd_val)
{
    uint32_t loop_cnt;
    uint64_t tp0, tp1;
    int32_t offset, weight;
    v16u8 out;
    v16i8 src0, src1, src2, src3, src4, src5, src6, src7, src8, src9, src10;
    v8i16 in0 = { 0 }, in1 = { 0 };
    v8i16 filt0, filt1, filt2, filt3;
    v8i16 filt_h0, filt_h1, filt_h2, filt_h3;
    v16i8 mask1, mask2, mask3;
    v8i16 filter_vec, weight_vec;
    v16i8 vec0, vec1, vec2, vec3, vec4, vec5, vec6, vec7;
    v16i8 vec8, vec9, vec10, vec11, vec12, vec13, vec14, vec15;
    v8i16 dst30, dst41, dst52, dst63, dst66, dst87;
    v8i16 tmp0, tmp1, tmp2, tmp3;
    v8i16 dst10, dst32, dst54, dst76;
    v8i16 dst21, dst43, dst65, dst97, dst108, dst109, dst98;
    v4i32 offset_vec, rnd_vec, const_vec, dst0, dst1, dst2, dst3;
    v16i8 mask0 = LD_SB(ff_hevc_mask_arr + 16);

    src0_ptr -= ((3 * src_stride) + 3);

    filter_vec = LD_SH(filter_x);
    SPLATI_H4_SH(filter_vec, 0, 1, 2, 3, filt0, filt1, filt2, filt3);

    filter_vec = LD_SH(filter_y);
    UNPCK_R_SB_SH(filter_vec, filter_vec);

    SPLATI_W4_SH(filter_vec, filt_h0, filt_h1, filt_h2, filt_h3);

    mask1 = mask0 + 2;
    mask2 = mask0 + 4;
    mask3 = mask0 + 6;

    offset = (offset0 + offset1) << rnd_val;
    weight0 = weight0 & 0x0000FFFF;
    weight = weight0 | (weight1 << 16);

    const_vec = __msa_fill_w((128 * weight1));
    const_vec <<= 6;
    offset_vec = __msa_fill_w(offset);
    rnd_vec = __msa_fill_w(rnd_val + 1);
    offset_vec += const_vec;
    weight_vec = (v8i16) __msa_fill_w(weight);

    LD_SB7(src0_ptr, src_stride, src0, src1, src2, src3, src4, src5, src6);
    src0_ptr += (7 * src_stride);

    XORI_B7_128_SB(src0, src1, src2, src3, src4, src5, src6);

    VSHF_B4_SB(src0, src3, mask0, mask1, mask2, mask3, vec0, vec1, vec2, vec3);
    VSHF_B4_SB(src1, src4, mask0, mask1, mask2, mask3, vec4, vec5, vec6, vec7);
    VSHF_B4_SB(src2, src5, mask0, mask1, mask2, mask3,
               vec8, vec9, vec10, vec11);
    VSHF_B4_SB(src3, src6, mask0, mask1, mask2, mask3,
               vec12, vec13, vec14, vec15);

    dst30 = HEVC_FILT_8TAP_SH(vec0, vec1, vec2, vec3, filt0, filt1, filt2,
                              filt3);
    dst41 = HEVC_FILT_8TAP_SH(vec4, vec5, vec6, vec7, filt0, filt1, filt2,
                              filt3);
    dst52 = HEVC_FILT_8TAP_SH(vec8, vec9, vec10, vec11, filt0, filt1, filt2,
                              filt3);
    dst63 = HEVC_FILT_8TAP_SH(vec12, vec13, vec14, vec15, filt0, filt1, filt2,
                              filt3);

    ILVRL_H2_SH(dst41, dst30, dst10, dst43);
    ILVRL_H2_SH(dst52, dst41, dst21, dst54);
    ILVRL_H2_SH(dst63, dst52, dst32, dst65);

    dst66 = (v8i16) __msa_splati_d((v2i64) dst63, 1);

    for (loop_cnt = height >> 2; loop_cnt--;) {
        LD_SB4(src0_ptr, src_stride, src7, src8, src9, src10);
        src0_ptr += (4 * src_stride);
        XORI_B4_128_SB(src7, src8, src9, src10);

        LD2(src1_ptr, src2_stride, tp0, tp1);
        INSERT_D2_SH(tp0, tp1, in0);
        src1_ptr += (2 * src2_stride);
        LD2(src1_ptr, src2_stride, tp0, tp1);
        INSERT_D2_SH(tp0, tp1, in1);
        src1_ptr += (2 * src2_stride);

        VSHF_B4_SB(src7, src9, mask0, mask1, mask2, mask3,
                   vec0, vec1, vec2, vec3);
        VSHF_B4_SB(src8, src10, mask0, mask1, mask2, mask3,
                   vec4, vec5, vec6, vec7);
        dst97 = HEVC_FILT_8TAP_SH(vec0, vec1, vec2, vec3, filt0, filt1, filt2,
                                  filt3);
        dst108 = HEVC_FILT_8TAP_SH(vec4, vec5, vec6, vec7, filt0, filt1, filt2,
                                   filt3);

        dst76 = __msa_ilvr_h(dst97, dst66);
        ILVRL_H2_SH(dst108, dst97, dst87, dst109);
        dst66 = (v8i16) __msa_splati_d((v2i64) dst97, 1);
        dst98 = __msa_ilvr_h(dst66, dst108);

        dst0 = HEVC_FILT_8TAP(dst10, dst32, dst54, dst76, filt_h0, filt_h1,
                              filt_h2, filt_h3);
        dst1 = HEVC_FILT_8TAP(dst21, dst43, dst65, dst87, filt_h0, filt_h1,
                              filt_h2, filt_h3);
        dst2 = HEVC_FILT_8TAP(dst32, dst54, dst76, dst98, filt_h0, filt_h1,
                              filt_h2, filt_h3);
        dst3 = HEVC_FILT_8TAP(dst43, dst65, dst87, dst109, filt_h0, filt_h1,
                              filt_h2, filt_h3);
        SRA_4V(dst0, dst1, dst2, dst3, 6);
        PCKEV_H2_SH(dst1, dst0, dst3, dst2, tmp1, tmp3);
        ILVRL_H2_SH(tmp1, in0, tmp0, tmp1);
        ILVRL_H2_SH(tmp3, in1, tmp2, tmp3);
        dst0 = __msa_dpadd_s_w(offset_vec, tmp0, weight_vec);
        dst1 = __msa_dpadd_s_w(offset_vec, tmp1, weight_vec);
        dst2 = __msa_dpadd_s_w(offset_vec, tmp2, weight_vec);
        dst3 = __msa_dpadd_s_w(offset_vec, tmp3, weight_vec);
        SRAR_W4_SW(dst0, dst1, dst2, dst3, rnd_vec);
        CLIP_SW4_0_255_MAX_SATU(dst0, dst1, dst2, dst3);
        PCKEV_H2_SH(dst1, dst0, dst3, dst2, tmp0, tmp1);
        out = (v16u8) __msa_pckev_b((v16i8) tmp1, (v16i8) tmp0);
        ST4x4_UB(out, out, 0, 1, 2, 3, dst, dst_stride);
        dst += (4 * dst_stride);

        dst10 = dst54;
        dst32 = dst76;
        dst54 = dst98;
        dst21 = dst65;
        dst43 = dst87;
        dst65 = dst109;
        dst66 = (v8i16) __msa_splati_d((v2i64) dst108, 1);
    }
}