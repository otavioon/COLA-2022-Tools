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
typedef  int /*<<< orphan*/  v16u8 ;
typedef  int v16i8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int int32_t ;
typedef  int /*<<< orphan*/  int16_t ;

/* Variables and functions */
 int /*<<< orphan*/  DPADD_SB4_SH (int,int,int,int,int,int,int,int,int,int,int,int) ; 
 int HEVC_FILT_8TAP (int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  ILVRL_H2_SH (int,int,int,int) ; 
 int LD_SB (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LD_SB7 (int /*<<< orphan*/ *,int,int,int,int,int,int,int,int) ; 
 int LD_SH (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  SPLATI_H4_SH (int,int /*<<< orphan*/ ,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  SPLATI_W4_SH (int,int,int,int,int) ; 
 int /*<<< orphan*/  ST_SW (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  UNPCK_R_SB_SH (int,int) ; 
 int /*<<< orphan*/  VSHF_B4_SB (int,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  XORI_B7_128_SB (int,int,int,int,int,int,int) ; 
 int __msa_ldi_h (int) ; 
 int __msa_pckev_h (int,int) ; 
 int __msa_xori_b (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void hevc_hv_8t_8multx1mult_msa(uint8_t *src,
                                       int32_t src_stride,
                                       int16_t *dst,
                                       int32_t dst_stride,
                                       const int8_t *filter_x,
                                       const int8_t *filter_y,
                                       int32_t height, int32_t width)
{
    uint32_t loop_cnt, cnt;
    uint8_t *src_tmp;
    int16_t *dst_tmp;
    v16i8 src0, src1, src2, src3, src4, src5, src6, src7;
    v8i16 filt0, filt1, filt2, filt3;
    v8i16 filt_h0, filt_h1, filt_h2, filt_h3;
    v16i8 mask1, mask2, mask3;
    v8i16 filter_vec, const_vec;
    v16i8 vec0, vec1, vec2, vec3, vec4, vec5, vec6, vec7;
    v16i8 vec8, vec9, vec10, vec11, vec12, vec13, vec14, vec15;
    v8i16 dst0, dst1, dst2, dst3, dst4, dst5, dst6, dst7;
    v4i32 dst0_r, dst0_l;
    v8i16 dst10_r, dst32_r, dst54_r, dst76_r;
    v8i16 dst10_l, dst32_l, dst54_l, dst76_l;
    v16i8 mask0 = { 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8 };

    src -= ((3 * src_stride) + 3);
    filter_vec = LD_SH(filter_x);
    SPLATI_H4_SH(filter_vec, 0, 1, 2, 3, filt0, filt1, filt2, filt3);

    filter_vec = LD_SH(filter_y);
    UNPCK_R_SB_SH(filter_vec, filter_vec);

    SPLATI_W4_SH(filter_vec, filt_h0, filt_h1, filt_h2, filt_h3);

    mask1 = mask0 + 2;
    mask2 = mask0 + 4;
    mask3 = mask0 + 6;

    const_vec = __msa_ldi_h(128);
    const_vec <<= 6;

    for (cnt = width >> 3; cnt--;) {
        src_tmp = src;
        dst_tmp = dst;

        LD_SB7(src_tmp, src_stride, src0, src1, src2, src3, src4, src5, src6);
        src_tmp += (7 * src_stride);
        XORI_B7_128_SB(src0, src1, src2, src3, src4, src5, src6);

        /* row 0 row 1 row 2 row 3 */
        VSHF_B4_SB(src0, src0, mask0, mask1, mask2, mask3,
                   vec0, vec1, vec2, vec3);
        VSHF_B4_SB(src1, src1, mask0, mask1, mask2, mask3,
                   vec4, vec5, vec6, vec7);
        VSHF_B4_SB(src2, src2, mask0, mask1, mask2, mask3,
                   vec8, vec9, vec10, vec11);
        VSHF_B4_SB(src3, src3, mask0, mask1, mask2, mask3,
                   vec12, vec13, vec14, vec15);
        dst0 = const_vec;
        DPADD_SB4_SH(vec0, vec1, vec2, vec3, filt0, filt1, filt2, filt3,
                     dst0, dst0, dst0, dst0);
        dst1 = const_vec;
        DPADD_SB4_SH(vec4, vec5, vec6, vec7, filt0, filt1, filt2, filt3,
                     dst1, dst1, dst1, dst1);
        dst2 = const_vec;
        DPADD_SB4_SH(vec8, vec9, vec10, vec11, filt0, filt1, filt2, filt3,
                     dst2, dst2, dst2, dst2);
        dst3 = const_vec;
        DPADD_SB4_SH(vec12, vec13, vec14, vec15, filt0, filt1, filt2, filt3,
                     dst3, dst3, dst3, dst3);

        /* row 4 row 5 row 6 */
        VSHF_B4_SB(src4, src4, mask0, mask1, mask2, mask3,
                   vec0, vec1, vec2, vec3);
        VSHF_B4_SB(src5, src5, mask0, mask1, mask2, mask3,
                   vec4, vec5, vec6, vec7);
        VSHF_B4_SB(src6, src6, mask0, mask1, mask2, mask3,
                   vec8, vec9, vec10, vec11);
        dst4 = const_vec;
        DPADD_SB4_SH(vec0, vec1, vec2, vec3, filt0, filt1, filt2, filt3,
                     dst4, dst4, dst4, dst4);
        dst5 = const_vec;
        DPADD_SB4_SH(vec4, vec5, vec6, vec7, filt0, filt1, filt2, filt3,
                     dst5, dst5, dst5, dst5);
        dst6 = const_vec;
        DPADD_SB4_SH(vec8, vec9, vec10, vec11, filt0, filt1, filt2, filt3,
                     dst6, dst6, dst6, dst6);

        for (loop_cnt = height; loop_cnt--;) {
            src7 = LD_SB(src_tmp);
            src7 = (v16i8) __msa_xori_b((v16u8) src7, 128);
            src_tmp += src_stride;

            VSHF_B4_SB(src7, src7, mask0, mask1, mask2, mask3,
                       vec0, vec1, vec2, vec3);
            dst7 = const_vec;
            DPADD_SB4_SH(vec0, vec1, vec2, vec3, filt0, filt1, filt2, filt3,
                         dst7, dst7, dst7, dst7);

            ILVRL_H2_SH(dst1, dst0, dst10_r, dst10_l);
            ILVRL_H2_SH(dst3, dst2, dst32_r, dst32_l);
            ILVRL_H2_SH(dst5, dst4, dst54_r, dst54_l);
            ILVRL_H2_SH(dst7, dst6, dst76_r, dst76_l);
            dst0_r = HEVC_FILT_8TAP(dst10_r, dst32_r, dst54_r, dst76_r,
                                    filt_h0, filt_h1, filt_h2, filt_h3);
            dst0_l = HEVC_FILT_8TAP(dst10_l, dst32_l, dst54_l, dst76_l,
                                    filt_h0, filt_h1, filt_h2, filt_h3);
            dst0_r >>= 6;
            dst0_l >>= 6;

            dst0_r = (v4i32) __msa_pckev_h((v8i16) dst0_l, (v8i16) dst0_r);
            ST_SW(dst0_r, dst_tmp);
            dst_tmp += dst_stride;

            dst0 = dst1;
            dst1 = dst2;
            dst2 = dst3;
            dst3 = dst4;
            dst4 = dst5;
            dst5 = dst6;
            dst6 = dst7;
        }

        src += 8;
        dst += 8;
    }
}