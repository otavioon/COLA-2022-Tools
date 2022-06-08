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
typedef  scalar_t__ v16u8 ;
typedef  int /*<<< orphan*/  v16i8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int int32_t ;

/* Variables and functions */
 int FILT_8TAP_DPADD_S_H (int,int,int,int,int,int,int,int) ; 
 int HORIZ_8TAP_FILT (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,scalar_t__,scalar_t__,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ILVEV_B2_SH (int,int,int,int,int,int) ; 
 int /*<<< orphan*/  INSERT_W4_UB (int,int,int,int,scalar_t__) ; 
 int /*<<< orphan*/  LD_SB4 (int /*<<< orphan*/  const*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LD_SB7 (int /*<<< orphan*/  const*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int LD_SH (int /*<<< orphan*/  const*) ; 
 scalar_t__ LD_UB (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LW4 (int /*<<< orphan*/ *,int,int,int,int,int) ; 
 scalar_t__ PCKEV_XORI128_UB (int,int) ; 
 int /*<<< orphan*/  SAT_SH2_SH (int,int,int) ; 
 int /*<<< orphan*/  SLDI_B2_SH (int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  SPLATI_H4_SB (int,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SPLATI_H4_SH (int,int /*<<< orphan*/ ,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  SRARI_H2_SH (int,int,int) ; 
 int /*<<< orphan*/  ST4x4_UB (scalar_t__,scalar_t__,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  XORI_B4_128_SB (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XORI_B7_128_SB (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int __msa_aver_u_b (scalar_t__,scalar_t__) ; 
 int __msa_ilvev_b (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int __msa_sldi_b (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * mc_filt_mask_arr ; 

__attribute__((used)) static void common_hv_8ht_8vt_and_aver_dst_4w_msa(const uint8_t *src,
                                                  int32_t src_stride,
                                                  uint8_t *dst,
                                                  int32_t dst_stride,
                                                  const int8_t *filter_horiz,
                                                  const int8_t *filter_vert,
                                                  int32_t height)
{
    uint32_t loop_cnt;
    uint32_t tp0, tp1, tp2, tp3;
    v16i8 src0, src1, src2, src3, src4, src5, src6, src7, src8, src9, src10;
    v16u8 dst0, res, mask0, mask1, mask2, mask3;
    v16i8 filt_hz0, filt_hz1, filt_hz2, filt_hz3;
    v8i16 hz_out0, hz_out1, hz_out2, hz_out3, hz_out4, hz_out5, hz_out6;
    v8i16 hz_out7, hz_out8, hz_out9, res0, res1, vec0, vec1, vec2, vec3, vec4;
    v8i16 filt, filt_vt0, filt_vt1, filt_vt2, filt_vt3;

    mask0 = LD_UB(&mc_filt_mask_arr[16]);
    src -= (3 + 3 * src_stride);

    /* rearranging filter */
    filt = LD_SH(filter_horiz);
    SPLATI_H4_SB(filt, 0, 1, 2, 3, filt_hz0, filt_hz1, filt_hz2, filt_hz3);

    mask1 = mask0 + 2;
    mask2 = mask0 + 4;
    mask3 = mask0 + 6;

    LD_SB7(src, src_stride, src0, src1, src2, src3, src4, src5, src6);
    XORI_B7_128_SB(src0, src1, src2, src3, src4, src5, src6);
    src += (7 * src_stride);

    hz_out0 = HORIZ_8TAP_FILT(src0, src1, mask0, mask1, mask2, mask3, filt_hz0,
                              filt_hz1, filt_hz2, filt_hz3);
    hz_out2 = HORIZ_8TAP_FILT(src2, src3, mask0, mask1, mask2, mask3, filt_hz0,
                              filt_hz1, filt_hz2, filt_hz3);
    hz_out4 = HORIZ_8TAP_FILT(src4, src5, mask0, mask1, mask2, mask3, filt_hz0,
                              filt_hz1, filt_hz2, filt_hz3);
    hz_out5 = HORIZ_8TAP_FILT(src5, src6, mask0, mask1, mask2, mask3, filt_hz0,
                              filt_hz1, filt_hz2, filt_hz3);
    SLDI_B2_SH(hz_out2, hz_out4, hz_out0, hz_out2, hz_out1, hz_out3, 8);

    filt = LD_SH(filter_vert);
    SPLATI_H4_SH(filt, 0, 1, 2, 3, filt_vt0, filt_vt1, filt_vt2, filt_vt3);

    ILVEV_B2_SH(hz_out0, hz_out1, hz_out2, hz_out3, vec0, vec1);
    vec2 = (v8i16) __msa_ilvev_b((v16i8) hz_out5, (v16i8) hz_out4);

    for (loop_cnt = (height >> 2); loop_cnt--;) {
        LD_SB4(src, src_stride, src7, src8, src9, src10);
        XORI_B4_128_SB(src7, src8, src9, src10);
        src += (4 * src_stride);

        LW4(dst, dst_stride, tp0, tp1, tp2, tp3);
        INSERT_W4_UB(tp0, tp1, tp2, tp3, dst0);
        hz_out7 = HORIZ_8TAP_FILT(src7, src8, mask0, mask1, mask2, mask3,
                                  filt_hz0, filt_hz1, filt_hz2, filt_hz3);
        hz_out6 = (v8i16) __msa_sldi_b((v16i8) hz_out7, (v16i8) hz_out5, 8);
        vec3 = (v8i16) __msa_ilvev_b((v16i8) hz_out7, (v16i8) hz_out6);
        res0 = FILT_8TAP_DPADD_S_H(vec0, vec1, vec2, vec3, filt_vt0, filt_vt1,
                                   filt_vt2, filt_vt3);

        hz_out9 = HORIZ_8TAP_FILT(src9, src10, mask0, mask1, mask2, mask3,
                                  filt_hz0, filt_hz1, filt_hz2, filt_hz3);
        hz_out8 = (v8i16) __msa_sldi_b((v16i8) hz_out9, (v16i8) hz_out7, 8);
        vec4 = (v8i16) __msa_ilvev_b((v16i8) hz_out9, (v16i8) hz_out8);
        res1 = FILT_8TAP_DPADD_S_H(vec1, vec2, vec3, vec4, filt_vt0, filt_vt1,
                                   filt_vt2, filt_vt3);

        SRARI_H2_SH(res0, res1, 7);
        SAT_SH2_SH(res0, res1, 7);
        res = PCKEV_XORI128_UB(res0, res1);
        res = (v16u8) __msa_aver_u_b(res, dst0);
        ST4x4_UB(res, res, 0, 1, 2, 3, dst, dst_stride);
        dst += (4 * dst_stride);

        hz_out5 = hz_out9;
        vec0 = vec2;
        vec1 = vec3;
        vec2 = vec4;
    }
}