#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  scalar_t__ v16u8 ;
typedef  int v16i8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  scalar_t__ int32_t ;
typedef  int /*<<< orphan*/  int16_t ;

/* Variables and functions */
 int LD_SB (int /*<<< orphan*/ *) ; 
 scalar_t__ LD_UB (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LD_UB4 (int /*<<< orphan*/ *,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  ST_UB4 (scalar_t__,scalar_t__,scalar_t__,scalar_t__,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  VSHF_B2_SB (int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  XORI_B4_128_SB (int,int,int,int) ; 
 int /*<<< orphan*/  XORI_B4_128_UB (scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int __msa_adds_s_b (int,int) ; 
 scalar_t__ __msa_bmnz_v (scalar_t__,scalar_t__,scalar_t__) ; 
 int __msa_ldi_b (int) ; 
 scalar_t__ __msa_nor_v (scalar_t__,scalar_t__) ; 
 int __msa_pckev_b (int,int) ; 
 int __msa_sldi_b (int,int,int) ; 

__attribute__((used)) static void hevc_sao_edge_filter_135degree_16multiple_msa(uint8_t *dst,
                                                          int32_t dst_stride,
                                                          uint8_t *src,
                                                          int32_t src_stride,
                                                          int16_t *
                                                          sao_offset_val,
                                                          int32_t width,
                                                          int32_t height)
{
    uint8_t *src_orig, *dst_orig;
    int32_t v_cnt;
    v16i8 edge_idx = { 1, 2, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    v16u8 const1 = (v16u8) __msa_ldi_b(1);
    v16u8 dst0, dst1, dst2, dst3;
    v16u8 cmp_minus10, cmp_minus11, cmp_minus12, cmp_minus13, cmp_plus10;
    v16u8 cmp_plus11, cmp_plus12, cmp_plus13, diff_minus10, diff_minus11;
    v16u8 diff_minus12, diff_minus13, diff_plus10, diff_plus11, diff_plus12;
    v16u8 diff_plus13, src10, src11, src12, src13, src_minus10, src_minus11;
    v16u8 src_plus10, src_plus11, src_plus12, src_plus13;
    v16i8 src_minus12, src_minus13, src_zero0, src_zero1, src_zero2, src_zero3;
    v16i8 offset_mask0, offset_mask1, offset_mask2, offset_mask3, sao_offset;

    sao_offset = LD_SB(sao_offset_val);
    sao_offset = __msa_pckev_b(sao_offset, sao_offset);

    for (; height; height -= 4) {
        src_orig = src - 1;
        dst_orig = dst;

        LD_UB4(src_orig, src_stride, src_minus11, src_plus10, src_plus11,
               src_plus12);

        for (v_cnt = 0; v_cnt < width; v_cnt += 16) {
            src_minus10 = LD_UB(src_orig + 2 - src_stride);
            LD_UB4(src_orig + 16, src_stride, src10, src11, src12, src13);
            src_plus13 = LD_UB(src_orig + (src_stride << 2));
            src_orig += 16;

            src_zero0 = __msa_sldi_b((v16i8) src10, (v16i8) src_minus11, 1);
            cmp_minus10 = ((v16u8) src_zero0 == src_minus10);
            cmp_plus10 = ((v16u8) src_zero0 == src_plus10);

            src_zero1 = __msa_sldi_b((v16i8) src11, (v16i8) src_plus10, 1);
            src_minus11 = (v16u8) __msa_sldi_b((v16i8) src10,
                                               (v16i8) src_minus11, 2);
            cmp_minus11 = ((v16u8) src_zero1 == src_minus11);
            cmp_plus11 = ((v16u8) src_zero1 == src_plus11);

            src_zero2 = __msa_sldi_b((v16i8) src12, (v16i8) src_plus11, 1);
            src_minus12 = __msa_sldi_b((v16i8) src11, (v16i8) src_plus10, 2);
            cmp_minus12 = ((v16u8) src_zero2 == (v16u8) src_minus12);
            cmp_plus12 = ((v16u8) src_zero2 == src_plus12);

            src_zero3 = __msa_sldi_b((v16i8) src13, (v16i8) src_plus12, 1);
            src_minus13 = __msa_sldi_b((v16i8) src12, (v16i8) src_plus11, 2);
            cmp_minus13 = ((v16u8) src_zero3 == (v16u8) src_minus13);
            cmp_plus13 = ((v16u8) src_zero3 == src_plus13);

            diff_minus10 = __msa_nor_v(cmp_minus10, cmp_minus10);
            diff_plus10 = __msa_nor_v(cmp_plus10, cmp_plus10);
            diff_minus11 = __msa_nor_v(cmp_minus11, cmp_minus11);
            diff_plus11 = __msa_nor_v(cmp_plus11, cmp_plus11);
            diff_minus12 = __msa_nor_v(cmp_minus12, cmp_minus12);
            diff_plus12 = __msa_nor_v(cmp_plus12, cmp_plus12);
            diff_minus13 = __msa_nor_v(cmp_minus13, cmp_minus13);
            diff_plus13 = __msa_nor_v(cmp_plus13, cmp_plus13);

            cmp_minus10 = (src_minus10 < (v16u8) src_zero0);
            cmp_plus10 = (src_plus10 < (v16u8) src_zero0);
            cmp_minus11 = (src_minus11 < (v16u8) src_zero1);
            cmp_plus11 = (src_plus11 < (v16u8) src_zero1);
            cmp_minus12 = ((v16u8) src_minus12 < (v16u8) src_zero2);
            cmp_plus12 = (src_plus12 < (v16u8) src_zero2);
            cmp_minus13 = ((v16u8) src_minus13 < (v16u8) src_zero3);
            cmp_plus13 = (src_plus13 < (v16u8) src_zero3);

            diff_minus10 = __msa_bmnz_v(diff_minus10, const1, cmp_minus10);
            diff_plus10 = __msa_bmnz_v(diff_plus10, const1, cmp_plus10);
            diff_minus11 = __msa_bmnz_v(diff_minus11, const1, cmp_minus11);
            diff_plus11 = __msa_bmnz_v(diff_plus11, const1, cmp_plus11);
            diff_minus12 = __msa_bmnz_v(diff_minus12, const1, cmp_minus12);
            diff_plus12 = __msa_bmnz_v(diff_plus12, const1, cmp_plus12);
            diff_minus13 = __msa_bmnz_v(diff_minus13, const1, cmp_minus13);
            diff_plus13 = __msa_bmnz_v(diff_plus13, const1, cmp_plus13);

            offset_mask0 = 2 + (v16i8) diff_minus10 + (v16i8) diff_plus10;
            offset_mask1 = 2 + (v16i8) diff_minus11 + (v16i8) diff_plus11;
            offset_mask2 = 2 + (v16i8) diff_minus12 + (v16i8) diff_plus12;
            offset_mask3 = 2 + (v16i8) diff_minus13 + (v16i8) diff_plus13;

            VSHF_B2_SB(edge_idx, edge_idx, sao_offset, sao_offset,
                       offset_mask0, offset_mask0, offset_mask0, offset_mask0);
            VSHF_B2_SB(edge_idx, edge_idx, sao_offset, sao_offset,
                       offset_mask1, offset_mask1, offset_mask1, offset_mask1);
            VSHF_B2_SB(edge_idx, edge_idx, sao_offset, sao_offset,
                       offset_mask2, offset_mask2, offset_mask2, offset_mask2);
            VSHF_B2_SB(edge_idx, edge_idx, sao_offset, sao_offset,
                       offset_mask3, offset_mask3, offset_mask3, offset_mask3);

            XORI_B4_128_SB(src_zero0, src_zero1, src_zero2, src_zero3);

            dst0 = (v16u8) __msa_adds_s_b((v16i8) src_zero0, offset_mask0);
            dst1 = (v16u8) __msa_adds_s_b((v16i8) src_zero1, offset_mask1);
            dst2 = (v16u8) __msa_adds_s_b((v16i8) src_zero2, offset_mask2);
            dst3 = (v16u8) __msa_adds_s_b((v16i8) src_zero3, offset_mask3);

            XORI_B4_128_UB(dst0, dst1, dst2, dst3);

            src_minus11 = src10;
            src_plus10 = src11;
            src_plus11 = src12;
            src_plus12 = src13;

            ST_UB4(dst0, dst1, dst2, dst3, dst_orig, dst_stride);
            dst_orig += 16;
        }

        src += (src_stride << 2);
        dst += (dst_stride << 2);
    }
}