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
typedef  scalar_t__ v16i8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int /*<<< orphan*/  int32_t ;
typedef  int /*<<< orphan*/  int16_t ;

/* Variables and functions */
 int /*<<< orphan*/  DPADD_SB4_SH (scalar_t__,scalar_t__,scalar_t__,scalar_t__,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  HEVC_BI_RND_CLIP4 (int,int,int,int,int,int,int,int,int,int,int,int,int) ; 
 scalar_t__ LD_SB (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LD_SB2 (int /*<<< orphan*/ *,int,scalar_t__,scalar_t__) ; 
 int LD_SH (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  LD_SH4 (int /*<<< orphan*/ *,int,int,int,int,int) ; 
 int /*<<< orphan*/  PCKEV_B2_SB (int,int,int,int,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  SPLATI_H4_SH (int,int /*<<< orphan*/ ,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  ST_SB2 (scalar_t__,scalar_t__,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  VSHF_B2_SB (scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  XORI_B3_128_SB (scalar_t__,scalar_t__,scalar_t__) ; 
 int __msa_ldi_h (int) ; 
 int /*<<< orphan*/ * ff_hevc_mask_arr ; 

__attribute__((used)) static void hevc_hz_bi_8t_64w_msa(uint8_t *src0_ptr,
                                  int32_t src_stride,
                                  int16_t *src1_ptr,
                                  int32_t src2_stride,
                                  uint8_t *dst,
                                  int32_t dst_stride,
                                  const int8_t *filter,
                                  int32_t height)
{
    uint32_t loop_cnt;
    v16i8 src0, src1, src2, src3, src4, src5, tmp0, tmp1;
    v8i16 filt0, filt1, filt2, filt3;
    v16i8 mask0 = LD_SB(&ff_hevc_mask_arr[0]);
    v16i8 mask1, mask2, mask3, mask4, mask5, mask6, mask7;
    v16i8 vec0, vec1, vec2, vec3;
    v8i16 dst0, dst1, dst2, dst3;
    v8i16 in0, in1, in2, in3;
    v8i16 filter_vec, const_vec;

    src0_ptr -= 3;

    const_vec = __msa_ldi_h(128);
    const_vec <<= 6;

    filter_vec = LD_SH(filter);
    SPLATI_H4_SH(filter_vec, 0, 1, 2, 3, filt0, filt1, filt2, filt3);

    mask1 = mask0 + 2;
    mask2 = mask0 + 4;
    mask3 = mask0 + 6;
    mask4 = mask0 + 8;
    mask5 = mask0 + 10;
    mask6 = mask0 + 12;
    mask7 = mask0 + 14;

    for (loop_cnt = height; loop_cnt--;) {
        LD_SB2(src0_ptr, 16, src0, src1);
        src2 = LD_SB(src0_ptr + 24);
        LD_SB2(src0_ptr + 32, 16, src3, src4);
        src5 = LD_SB(src0_ptr + 56);
        LD_SH4(src1_ptr, 8, in0, in1, in2, in3);
        XORI_B3_128_SB(src0, src1, src2);

        dst0 = const_vec;
        dst1 = const_vec;
        dst2 = const_vec;
        dst3 = const_vec;

        VSHF_B2_SB(src0, src0, src0, src1, mask0, mask4, vec0, vec1);
        VSHF_B2_SB(src1, src1, src2, src2, mask0, mask0, vec2, vec3);
        DPADD_SB4_SH(vec0, vec1, vec2, vec3, filt0, filt0, filt0, filt0, dst0,
                     dst1, dst2, dst3);
        VSHF_B2_SB(src0, src0, src0, src1, mask1, mask5, vec0, vec1);
        VSHF_B2_SB(src1, src1, src2, src2, mask1, mask1, vec2, vec3);
        DPADD_SB4_SH(vec0, vec1, vec2, vec3, filt1, filt1, filt1, filt1, dst0,
                     dst1, dst2, dst3);
        VSHF_B2_SB(src0, src0, src0, src1, mask2, mask6, vec0, vec1);
        VSHF_B2_SB(src1, src1, src2, src2, mask2, mask2, vec2, vec3);
        DPADD_SB4_SH(vec0, vec1, vec2, vec3, filt2, filt2, filt2, filt2, dst0,
                     dst1, dst2, dst3);
        VSHF_B2_SB(src0, src0, src0, src1, mask3, mask7, vec0, vec1);
        VSHF_B2_SB(src1, src1, src2, src2, mask3, mask3, vec2, vec3);
        DPADD_SB4_SH(vec0, vec1, vec2, vec3, filt3, filt3, filt3, filt3, dst0,
                     dst1, dst2, dst3);

        HEVC_BI_RND_CLIP4(in0, in1, in2, in3,
                          dst0, dst1, dst2, dst3, 7,
                          dst0, dst1, dst2, dst3);

        PCKEV_B2_SB(dst1, dst0, dst3, dst2, tmp0, tmp1);
        ST_SB2(tmp0, tmp1, dst, 16);

        src0 = src3;
        src1 = src4;
        src2 = src5;

        LD_SH4(src1_ptr + 32, 8, in0, in1, in2, in3);
        XORI_B3_128_SB(src0, src1, src2);

        dst0 = const_vec;
        dst1 = const_vec;
        dst2 = const_vec;
        dst3 = const_vec;
        VSHF_B2_SB(src0, src0, src0, src1, mask0, mask4, vec0, vec1);
        VSHF_B2_SB(src1, src1, src2, src2, mask0, mask0, vec2, vec3);
        DPADD_SB4_SH(vec0, vec1, vec2, vec3, filt0, filt0, filt0, filt0, dst0,
                     dst1, dst2, dst3);
        VSHF_B2_SB(src0, src0, src0, src1, mask1, mask5, vec0, vec1);
        VSHF_B2_SB(src1, src1, src2, src2, mask1, mask1, vec2, vec3);
        DPADD_SB4_SH(vec0, vec1, vec2, vec3, filt1, filt1, filt1, filt1, dst0,
                     dst1, dst2, dst3);
        VSHF_B2_SB(src0, src0, src0, src1, mask2, mask6, vec0, vec1);
        VSHF_B2_SB(src1, src1, src2, src2, mask2, mask2, vec2, vec3);
        DPADD_SB4_SH(vec0, vec1, vec2, vec3, filt2, filt2, filt2, filt2, dst0,
                     dst1, dst2, dst3);
        VSHF_B2_SB(src0, src0, src0, src1, mask3, mask7, vec0, vec1);
        VSHF_B2_SB(src1, src1, src2, src2, mask3, mask3, vec2, vec3);
        DPADD_SB4_SH(vec0, vec1, vec2, vec3, filt3, filt3, filt3, filt3, dst0,
                     dst1, dst2, dst3);
        HEVC_BI_RND_CLIP4(in0, in1, in2, in3,
                          dst0, dst1, dst2, dst3, 7,
                          dst0, dst1, dst2, dst3);
        PCKEV_B2_SB(dst1, dst0, dst3, dst2, tmp0, tmp1);
        ST_SB2(tmp0, tmp1, dst + 32, 16);
        src1_ptr += src2_stride;
        src0_ptr += src_stride;
        dst += dst_stride;
    }
}