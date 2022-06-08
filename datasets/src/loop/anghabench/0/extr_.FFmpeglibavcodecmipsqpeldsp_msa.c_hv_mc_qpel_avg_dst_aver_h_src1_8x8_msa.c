#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  v2i64 ;
typedef  int v16u8 ;
typedef  int /*<<< orphan*/  v16i8 ;
typedef  int /*<<< orphan*/  const uint8_t ;
typedef  int int32_t ;

/* Variables and functions */
 int APPLY_HORIZ_QPEL_FILTER_8BYTE (int,int,int,int,int,int,int,int,int) ; 
 int APPLY_HORIZ_QPEL_FILTER_8BYTE_1ROW (int,int,int,int,int,int,int,int) ; 
 int APPLY_VERT_QPEL_FILTER_8BYTE (int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int) ; 
 int LD_UB (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  LD_UB2 (int /*<<< orphan*/  const*,int,int,int) ; 
 int /*<<< orphan*/  SLDI_B2_UB (int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  ST8x2_UB (int,int /*<<< orphan*/  const*,int) ; 
 int __msa_aver_u_b (int,int) ; 
 int __msa_ilvr_d (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int __msa_ldi_b (int) ; 
 int __msa_sldi_b (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int __msa_splati_d (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void hv_mc_qpel_avg_dst_aver_h_src1_8x8_msa(const uint8_t *src,
                                                   int32_t src_stride,
                                                   uint8_t *dst,
                                                   int32_t dst_stride)
{
    v16u8 inp0, inp1, inp2, inp3;
    v16u8 res0, res1, avg0, avg1;
    v16u8 horiz0, horiz1, horiz2, horiz3;
    v16u8 horiz4, horiz5, horiz6, horiz7, horiz8;
    v16u8 dst0, dst1;
    v16u8 mask0 = { 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8 };
    v16u8 mask1 = { 0, 2, 0, 3, 1, 4, 2, 5, 3, 6, 4, 7, 5, 8, 6, 8 };
    v16u8 mask2 = { 1, 3, 0, 4, 0, 5, 1, 6, 2, 7, 3, 8, 4, 8, 5, 7 };
    v16u8 mask3 = { 2, 4, 1, 5, 0, 6, 0, 7, 1, 8, 2, 8, 3, 7, 4, 6 };
    v16u8 const20 = (v16u8) __msa_ldi_b(20);
    v16u8 const6 = (v16u8) __msa_ldi_b(6);
    v16u8 const3 = (v16u8) __msa_ldi_b(3);

    LD_UB2(src, src_stride, inp0, inp1);
    src += (2 * src_stride);
    res0 = APPLY_HORIZ_QPEL_FILTER_8BYTE(inp0, inp1, mask0, mask1, mask2, mask3,
                                         const20, const6, const3);
    LD_UB2(src, src_stride, inp2, inp3);
    src += (2 * src_stride);
    SLDI_B2_UB(inp0, inp1, inp0, inp1, inp0, inp1, 1);

    inp0 = (v16u8) __msa_ilvr_d((v2i64) inp1, (v2i64) inp0);
    horiz0 = __msa_aver_u_b(inp0, res0);
    horiz1 = (v16u8) __msa_splati_d((v2i64) horiz0, 1);
    res1 = APPLY_HORIZ_QPEL_FILTER_8BYTE(inp2, inp3, mask0, mask1, mask2, mask3,
                                         const20, const6, const3);
    LD_UB2(src, src_stride, inp0, inp1);
    src += (2 * src_stride);
    SLDI_B2_UB(inp2, inp3, inp2, inp3, inp2, inp3, 1);

    inp2 = (v16u8) __msa_ilvr_d((v2i64) inp3, (v2i64) inp2);
    horiz2 = __msa_aver_u_b(inp2, res1);
    horiz3 = (v16u8) __msa_splati_d((v2i64) horiz2, 1);
    res0 = APPLY_HORIZ_QPEL_FILTER_8BYTE(inp0, inp1, mask0, mask1, mask2, mask3,
                                         const20, const6, const3);

    SLDI_B2_UB(inp0, inp1, inp0, inp1, inp0, inp1, 1);

    inp0 = (v16u8) __msa_ilvr_d((v2i64) inp1, (v2i64) inp0);
    horiz4 = __msa_aver_u_b(inp0, res0);
    horiz5 = (v16u8) __msa_splati_d((v2i64) horiz4, 1);
    LD_UB2(dst, dst_stride, dst0, dst1);
    res0 = APPLY_VERT_QPEL_FILTER_8BYTE(horiz0, horiz0, horiz1, horiz2,
                                        horiz1, horiz2, horiz3, horiz4,
                                        horiz1, horiz0, horiz0, horiz1,
                                        horiz2, horiz3, horiz4, horiz5,
                                        const20, const6, const3);
    avg0 = (v16u8) __msa_ilvr_d((v2i64) dst1, (v2i64) dst0);
    res0 = __msa_aver_u_b(avg0, res0);
    ST8x2_UB(res0, dst, dst_stride);
    dst += (2 * dst_stride);

    LD_UB2(src, src_stride, inp2, inp3);
    src += (2 * src_stride);
    res1 = APPLY_HORIZ_QPEL_FILTER_8BYTE(inp2, inp3, mask0, mask1, mask2, mask3,
                                         const20, const6, const3);

    SLDI_B2_UB(inp2, inp3, inp2, inp3, inp2, inp3, 1);

    inp2 = (v16u8) __msa_ilvr_d((v2i64) inp3, (v2i64) inp2);
    horiz6 = __msa_aver_u_b(inp2, res1);
    horiz7 = (v16u8) __msa_splati_d((v2i64) horiz6, 1);
    LD_UB2(dst, dst_stride, dst0, dst1);
    res1 = APPLY_VERT_QPEL_FILTER_8BYTE(horiz2, horiz1, horiz0, horiz0,
                                        horiz3, horiz4, horiz5, horiz6,
                                        horiz3, horiz2, horiz1, horiz0,
                                        horiz4, horiz5, horiz6, horiz7,
                                        const20, const6, const3);
    avg1 = (v16u8) __msa_ilvr_d((v2i64) dst1, (v2i64) dst0);
    res1 = __msa_aver_u_b(avg1, res1);
    ST8x2_UB(res1, dst, dst_stride);
    dst += (2 * dst_stride);

    inp0 = LD_UB(src);
    res0 = APPLY_HORIZ_QPEL_FILTER_8BYTE_1ROW(inp0, mask0, mask1, mask2, mask3,
                                              const20, const6, const3);
    inp0 = (v16u8) __msa_sldi_b((v16i8) inp0, (v16i8) inp0, 1);
    horiz8 = __msa_aver_u_b(inp0, res0);
    LD_UB2(dst, dst_stride, dst0, dst1);
    res0 = APPLY_VERT_QPEL_FILTER_8BYTE(horiz4, horiz3, horiz2, horiz1,
                                        horiz5, horiz6, horiz7, horiz8,
                                        horiz5, horiz4, horiz3, horiz2,
                                        horiz6, horiz7, horiz8, horiz8,
                                        const20, const6, const3);
    avg0 = (v16u8) __msa_ilvr_d((v2i64) dst1, (v2i64) dst0);
    res0 = __msa_aver_u_b(avg0, res0);
    ST8x2_UB(res0, dst, dst_stride);
    dst += (2 * dst_stride);

    LD_UB2(dst, dst_stride, dst0, dst1);
    res1 = APPLY_VERT_QPEL_FILTER_8BYTE(horiz6, horiz5, horiz4, horiz3,
                                        horiz7, horiz8, horiz8, horiz7,
                                        horiz7, horiz6, horiz5, horiz4,
                                        horiz8, horiz8, horiz7, horiz6,
                                        const20, const6, const3);
    avg1 = (v16u8) __msa_ilvr_d((v2i64) dst1, (v2i64) dst0);
    res1 = __msa_aver_u_b(avg1, res1);
    ST8x2_UB(res1, dst, dst_stride);
}