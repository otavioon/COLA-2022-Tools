#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int v8u16 ;
typedef  int v16u8 ;
typedef  int /*<<< orphan*/  v16i8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  AVER_UB2_UB (int,int,int,int,int,int) ; 
 int /*<<< orphan*/  DOTP_UB4_UH (int,int,int,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  INSERT_D2_UB (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  LD4 (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LD_SB (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LD_UB4 (int /*<<< orphan*/ *,int,int,int,int,int) ; 
 int /*<<< orphan*/  LD_UB5 (int /*<<< orphan*/ *,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  MUL4 (int,int,int,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  PCKEV_B2_UB (int,int,int,int,int,int) ; 
 int /*<<< orphan*/  SAT_UH4_UH (int,int,int,int,int) ; 
 int /*<<< orphan*/  SRARI_H4_UH (int,int,int,int,int) ; 
 int /*<<< orphan*/  ST8x8_UB (int,int,int,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  VSHF_B2_UB (int,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int __msa_dotp_u_h (int,int) ; 
 int /*<<< orphan*/  __msa_fill_b (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __msa_fill_h (int /*<<< orphan*/ ) ; 
 int __msa_ilvr_b (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int __msa_vshf_b (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * chroma_mask_arr ; 

__attribute__((used)) static void avc_chroma_hv_and_aver_dst_8x8_msa(uint8_t *src, uint8_t *dst,
                                               int32_t stride,
                                               uint32_t coef_hor0,
                                               uint32_t coef_hor1,
                                               uint32_t coef_ver0,
                                               uint32_t coef_ver1)
{
    uint64_t tp0, tp1, tp2, tp3;
    v16u8 src0, src1, src2, src3, src4, src5, src6, src7, src8;
    v16u8 out0, out1, out2, out3;
    v16u8 dst0 = { 0 }, dst1 = { 0 }, dst2 = { 0 }, dst3 = { 0 };
    v8u16 res_hz0, res_hz1, res_hz2, res_hz3, res_hz4;
    v8u16 res_hz5, res_hz6, res_hz7, res_hz8;
    v8u16 res_vt0, res_vt1, res_vt2, res_vt3;
    v8u16 res_vt4, res_vt5, res_vt6, res_vt7;
    v16i8 mask;
    v16i8 coeff_hz_vec0 = __msa_fill_b(coef_hor0);
    v16i8 coeff_hz_vec1 = __msa_fill_b(coef_hor1);
    v16u8 coeff_hz_vec = (v16u8) __msa_ilvr_b(coeff_hz_vec0, coeff_hz_vec1);
    v8u16 coeff_vt_vec0 = (v8u16) __msa_fill_h(coef_ver0);
    v8u16 coeff_vt_vec1 = (v8u16) __msa_fill_h(coef_ver1);

    mask = LD_SB(&chroma_mask_arr[32]);

    LD_UB5(src, stride, src0, src1, src2, src3, src4);
    src += (5 * stride);
    LD_UB4(src, stride, src5, src6, src7, src8);
    src0 = (v16u8) __msa_vshf_b(mask, (v16i8) src0, (v16i8) src0);
    VSHF_B2_UB(src1, src1, src2, src2, mask, mask, src1, src2);
    VSHF_B2_UB(src3, src3, src4, src4, mask, mask, src3, src4);
    VSHF_B2_UB(src5, src5, src6, src6, mask, mask, src5, src6);
    VSHF_B2_UB(src7, src7, src8, src8, mask, mask, src7, src8);
    res_hz0 = __msa_dotp_u_h(src0, coeff_hz_vec);
    DOTP_UB4_UH(src1, src2, src3, src4, coeff_hz_vec, coeff_hz_vec,
                coeff_hz_vec, coeff_hz_vec, res_hz1, res_hz2, res_hz3,
                res_hz4);
    DOTP_UB4_UH(src5, src6, src7, src8, coeff_hz_vec, coeff_hz_vec,
                coeff_hz_vec, coeff_hz_vec, res_hz5, res_hz6, res_hz7, res_hz8);
    MUL4(res_hz1, coeff_vt_vec0, res_hz2, coeff_vt_vec0, res_hz3,
         coeff_vt_vec0, res_hz4, coeff_vt_vec0, res_vt0, res_vt1, res_vt2,
         res_vt3);
    MUL4(res_hz5, coeff_vt_vec0, res_hz6, coeff_vt_vec0, res_hz7,
         coeff_vt_vec0, res_hz8, coeff_vt_vec0, res_vt4, res_vt5, res_vt6,
         res_vt7);
    LD4(dst, stride, tp0, tp1, tp2, tp3);
    INSERT_D2_UB(tp0, tp1, dst0);
    INSERT_D2_UB(tp2, tp3, dst1);
    LD4(dst + 4 * stride, stride, tp0, tp1, tp2, tp3);
    INSERT_D2_UB(tp0, tp1, dst2);
    INSERT_D2_UB(tp2, tp3, dst3);
    res_vt0 += (res_hz0 * coeff_vt_vec1);
    res_vt1 += (res_hz1 * coeff_vt_vec1);
    res_vt2 += (res_hz2 * coeff_vt_vec1);
    res_vt3 += (res_hz3 * coeff_vt_vec1);
    res_vt4 += (res_hz4 * coeff_vt_vec1);
    res_vt5 += (res_hz5 * coeff_vt_vec1);
    res_vt6 += (res_hz6 * coeff_vt_vec1);
    res_vt7 += (res_hz7 * coeff_vt_vec1);
    SRARI_H4_UH(res_vt0, res_vt1, res_vt2, res_vt3, 6);
    SRARI_H4_UH(res_vt4, res_vt5, res_vt6, res_vt7, 6);
    SAT_UH4_UH(res_vt0, res_vt1, res_vt2, res_vt3, 7);
    SAT_UH4_UH(res_vt4, res_vt5, res_vt6, res_vt7, 7);
    PCKEV_B2_UB(res_vt1, res_vt0, res_vt3, res_vt2, out0, out1);
    PCKEV_B2_UB(res_vt5, res_vt4, res_vt7, res_vt6, out2, out3);
    AVER_UB2_UB(out0, dst0, out1, dst1, out0, out1);
    AVER_UB2_UB(out2, dst2, out3, dst3, out2, out3);
    ST8x8_UB(out0, out1, out2, out3, dst, stride);
}