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
typedef  int /*<<< orphan*/  v4i32 ;
typedef  scalar_t__ v16u8 ;
typedef  int v16i8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int int32_t ;
typedef  int /*<<< orphan*/  int16_t ;

/* Variables and functions */
 int /*<<< orphan*/  ILVR_B2_SB (int,int,int,int,int,int) ; 
 int /*<<< orphan*/  ILVR_B2_UB (scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int LD_SB (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LD_UB2 (int /*<<< orphan*/ *,int,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  SLDI_B2_0_SB (scalar_t__,scalar_t__,int,int,int) ; 
 int /*<<< orphan*/  SLDI_B2_0_UB (scalar_t__,scalar_t__,scalar_t__,scalar_t__,int) ; 
 int /*<<< orphan*/  SW (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  VSHF_B2_SB (int,int,int,int,int,int,int,int) ; 
 int __msa_adds_s_b (int,int) ; 
 scalar_t__ __msa_bmnz_v (scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  __msa_copy_u_w (int /*<<< orphan*/ ,int) ; 
 int __msa_hadd_u_h (scalar_t__,scalar_t__) ; 
 int __msa_ldi_b (int) ; 
 scalar_t__ __msa_nor_v (scalar_t__,scalar_t__) ; 
 int __msa_pckev_b (int,int) ; 
 int __msa_xori_b (scalar_t__,int) ; 

__attribute__((used)) static void hevc_sao_edge_filter_135degree_4width_msa(uint8_t *dst,
                                                      int32_t dst_stride,
                                                      uint8_t *src,
                                                      int32_t src_stride,
                                                      int16_t *sao_offset_val,
                                                      int32_t height)
{
    uint8_t *src_orig;
    uint32_t dst_val0, dst_val1;
    v16i8 edge_idx = { 1, 2, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    v16u8 const1 = (v16u8) __msa_ldi_b(1);
    v16i8 offset, sao_offset = LD_SB(sao_offset_val);
    v16i8 src_zero0, src_zero1, dst0;
    v16u8 cmp_minus10, diff_minus10, cmp_minus11, diff_minus11;
    v16u8 src_minus10, src10, src_minus11, src11;
    v8i16 offset_mask0, offset_mask1;

    sao_offset = __msa_pckev_b(sao_offset, sao_offset);
    src_orig = src - 1;

    /* load in advance */
    LD_UB2(src_orig - src_stride, src_stride, src_minus10, src_minus11);
    LD_UB2(src_orig + src_stride, src_stride, src10, src11);

    for (height -= 2; height; height -= 2) {
        src_orig += (src_stride << 1);

        SLDI_B2_0_SB(src_minus11, src10, src_zero0, src_zero1, 1);
        SLDI_B2_0_UB(src_minus10, src_minus11, src_minus10, src_minus11, 2);

        ILVR_B2_UB(src10, src_minus10, src11, src_minus11, src_minus10,
                   src_minus11);
        ILVR_B2_SB(src_zero0, src_zero0, src_zero1, src_zero1, src_zero0,
                   src_zero1);

        cmp_minus10 = ((v16u8) src_zero0 == src_minus10);
        diff_minus10 = __msa_nor_v(cmp_minus10, cmp_minus10);
        cmp_minus10 = (src_minus10 < (v16u8) src_zero0);
        diff_minus10 = __msa_bmnz_v(diff_minus10, const1, cmp_minus10);

        cmp_minus11 = ((v16u8) src_zero1 == src_minus11);
        diff_minus11 = __msa_nor_v(cmp_minus11, cmp_minus11);
        cmp_minus11 = (src_minus11 < (v16u8) src_zero1);
        diff_minus11 = __msa_bmnz_v(diff_minus11, const1, cmp_minus11);

        offset_mask0 = (v8i16) (__msa_hadd_u_h(diff_minus10, diff_minus10) + 2);
        offset_mask1 = (v8i16) (__msa_hadd_u_h(diff_minus11, diff_minus11) + 2);

        offset = __msa_pckev_b((v16i8) offset_mask1, (v16i8) offset_mask0);
        dst0 = __msa_pckev_b((v16i8) src_zero1, (v16i8) src_zero0);

        VSHF_B2_SB(edge_idx, edge_idx, sao_offset, sao_offset, offset, offset,
                   offset, offset);

        dst0 = (v16i8) __msa_xori_b((v16u8) dst0, 128);
        dst0 = __msa_adds_s_b(dst0, offset);
        dst0 = (v16i8) __msa_xori_b((v16u8) dst0, 128);

        src_minus10 = src10;
        src_minus11 = src11;

        /* load in advance */
        LD_UB2(src_orig + src_stride, src_stride, src10, src11);

        dst_val0 = __msa_copy_u_w((v4i32) dst0, 0);
        dst_val1 = __msa_copy_u_w((v4i32) dst0, 2);

        SW(dst_val0, dst);
        dst += dst_stride;
        SW(dst_val1, dst);

        dst += dst_stride;
    }

    SLDI_B2_0_SB(src_minus11, src10, src_zero0, src_zero1, 1);
    SLDI_B2_0_UB(src_minus10, src_minus11, src_minus10, src_minus11, 2);

    ILVR_B2_UB(src10, src_minus10, src11, src_minus11, src_minus10,
               src_minus11);
    ILVR_B2_SB(src_zero0, src_zero0, src_zero1, src_zero1, src_zero0,
               src_zero1);

    cmp_minus10 = ((v16u8) src_zero0 == src_minus10);
    diff_minus10 = __msa_nor_v(cmp_minus10, cmp_minus10);
    cmp_minus10 = (src_minus10 < (v16u8) src_zero0);
    diff_minus10 = __msa_bmnz_v(diff_minus10, const1, cmp_minus10);

    cmp_minus11 = ((v16u8) src_zero1 == src_minus11);
    diff_minus11 = __msa_nor_v(cmp_minus11, cmp_minus11);
    cmp_minus11 = (src_minus11 < (v16u8) src_zero1);
    diff_minus11 = __msa_bmnz_v(diff_minus11, const1, cmp_minus11);

    offset_mask0 = (v8i16) (__msa_hadd_u_h(diff_minus10, diff_minus10) + 2);
    offset_mask1 = (v8i16) (__msa_hadd_u_h(diff_minus11, diff_minus11) + 2);

    offset = __msa_pckev_b((v16i8) offset_mask1, (v16i8) offset_mask0);
    dst0 = __msa_pckev_b((v16i8) src_zero1, (v16i8) src_zero0);

    VSHF_B2_SB(edge_idx, edge_idx, sao_offset, sao_offset, offset, offset,
               offset, offset);

    dst0 = (v16i8) __msa_xori_b((v16u8) dst0, 128);
    dst0 = __msa_adds_s_b(dst0, offset);
    dst0 = (v16i8) __msa_xori_b((v16u8) dst0, 128);

    dst_val0 = __msa_copy_u_w((v4i32) dst0, 0);
    dst_val1 = __msa_copy_u_w((v4i32) dst0, 2);

    SW(dst_val0, dst);
    dst += dst_stride;
    SW(dst_val1, dst);
    dst += dst_stride;
}