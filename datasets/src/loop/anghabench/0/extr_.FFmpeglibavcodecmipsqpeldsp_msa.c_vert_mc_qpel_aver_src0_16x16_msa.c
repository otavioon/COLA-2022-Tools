#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  v16u8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  APPLY_VERT_QPEL_FILTER (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LD_UB (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  LD_UB2 (int /*<<< orphan*/  const*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LD_UB5 (int /*<<< orphan*/  const*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ST_UB (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  __msa_aver_u_b (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __msa_ldi_b (int) ; 

__attribute__((used)) static void vert_mc_qpel_aver_src0_16x16_msa(const uint8_t *src,
                                             int32_t src_stride,
                                             uint8_t *dst,
                                             int32_t dst_stride)
{
    v16u8 inp0, inp1, inp2, inp3, inp4, inp5, inp6, inp7, inp8;
    v16u8 inp9, inp10, inp11, inp12, inp13, inp14, inp15, inp16;
    v16u8 res0;
    v16u8 const20 = (v16u8) __msa_ldi_b(20);
    v16u8 const6 = (v16u8) __msa_ldi_b(6);
    v16u8 const3 = (v16u8) __msa_ldi_b(3);

    LD_UB5(src, src_stride, inp0, inp1, inp2, inp3, inp4);
    src += (5 * src_stride);
    res0 = APPLY_VERT_QPEL_FILTER(inp0, inp0, inp1, inp2,
                                  inp1, inp2, inp3, inp4,
                                  const20, const6, const3);
    res0 = __msa_aver_u_b(res0, inp0);
    ST_UB(res0, dst);
    dst += dst_stride;

    inp5 = LD_UB(src);
    src += src_stride;
    res0 = APPLY_VERT_QPEL_FILTER(inp1, inp0, inp0, inp1,
                                  inp2, inp3, inp4, inp5,
                                  const20, const6, const3);
    res0 = __msa_aver_u_b(res0, inp1);
    ST_UB(res0, dst);
    dst += dst_stride;

    inp6 = LD_UB(src);
    src += src_stride;
    res0 = APPLY_VERT_QPEL_FILTER(inp2, inp1, inp0, inp0,
                                  inp3, inp4, inp5, inp6,
                                  const20, const6, const3);
    res0 = __msa_aver_u_b(res0, inp2);
    ST_UB(res0, dst);
    dst += dst_stride;

    inp7 = LD_UB(src);
    src += src_stride;
    res0 = APPLY_VERT_QPEL_FILTER(inp3, inp2, inp1, inp0,
                                  inp4, inp5, inp6, inp7,
                                  const20, const6, const3);
    res0 = __msa_aver_u_b(res0, inp3);
    ST_UB(res0, dst);
    dst += dst_stride;

    LD_UB2(src, src_stride, inp8, inp9);
    src += (2 * src_stride);
    res0 = APPLY_VERT_QPEL_FILTER(inp4, inp3, inp2, inp1,
                                  inp5, inp6, inp7, inp8,
                                  const20, const6, const3);
    res0 = __msa_aver_u_b(res0, inp4);
    ST_UB(res0, dst);
    dst += dst_stride;

    res0 = APPLY_VERT_QPEL_FILTER(inp5, inp4, inp3, inp2,
                                  inp6, inp7, inp8, inp9,
                                  const20, const6, const3);
    res0 = __msa_aver_u_b(res0, inp5);
    ST_UB(res0, dst);
    dst += dst_stride;

    LD_UB2(src, src_stride, inp10, inp11);
    src += (2 * src_stride);
    res0 = APPLY_VERT_QPEL_FILTER(inp6, inp5, inp4, inp3,
                                  inp7, inp8, inp9, inp10,
                                  const20, const6, const3);
    res0 = __msa_aver_u_b(res0, inp6);
    ST_UB(res0, dst);
    dst += dst_stride;

    res0 = APPLY_VERT_QPEL_FILTER(inp7, inp6, inp5, inp4,
                                  inp8, inp9, inp10, inp11,
                                  const20, const6, const3);
    res0 = __msa_aver_u_b(res0, inp7);
    ST_UB(res0, dst);
    dst += dst_stride;

    LD_UB2(src, src_stride, inp12, inp13);
    src += (2 * src_stride);
    res0 = APPLY_VERT_QPEL_FILTER(inp8, inp7, inp6, inp5,
                                  inp9, inp10, inp11, inp12,
                                  const20, const6, const3);
    res0 = __msa_aver_u_b(res0, inp8);
    ST_UB(res0, dst);
    dst += dst_stride;

    res0 = APPLY_VERT_QPEL_FILTER(inp9, inp8, inp7, inp6,
                                  inp10, inp11, inp12, inp13,
                                  const20, const6, const3);
    res0 = __msa_aver_u_b(res0, inp9);
    ST_UB(res0, dst);
    dst += dst_stride;

    LD_UB2(src, src_stride, inp14, inp15);
    src += (2 * src_stride);
    res0 = APPLY_VERT_QPEL_FILTER(inp10, inp9, inp8, inp7,
                                  inp11, inp12, inp13, inp14,
                                  const20, const6, const3);
    res0 = __msa_aver_u_b(res0, inp10);
    ST_UB(res0, dst);
    dst += dst_stride;

    res0 = APPLY_VERT_QPEL_FILTER(inp11, inp10, inp9, inp8,
                                  inp12, inp13, inp14, inp15,
                                  const20, const6, const3);
    res0 = __msa_aver_u_b(res0, inp11);
    ST_UB(res0, dst);
    dst += dst_stride;

    inp16 = LD_UB(src);
    res0 = APPLY_VERT_QPEL_FILTER(inp12, inp11, inp10, inp9,
                                  inp13, inp14, inp15, inp16,
                                  const20, const6, const3);
    res0 = __msa_aver_u_b(res0, inp12);
    ST_UB(res0, dst);
    dst += dst_stride;

    res0 = APPLY_VERT_QPEL_FILTER(inp13, inp12, inp11, inp10,
                                  inp14, inp15, inp16, inp16,
                                  const20, const6, const3);
    res0 = __msa_aver_u_b(res0, inp13);
    ST_UB(res0, dst);
    dst += dst_stride;

    res0 = APPLY_VERT_QPEL_FILTER(inp14, inp13, inp12, inp11,
                                  inp15, inp16, inp16, inp15,
                                  const20, const6, const3);
    res0 = __msa_aver_u_b(res0, inp14);
    ST_UB(res0, dst);
    dst += dst_stride;

    res0 = APPLY_VERT_QPEL_FILTER(inp15, inp14, inp13, inp12,
                                  inp16, inp16, inp15, inp14,
                                  const20, const6, const3);
    res0 = __msa_aver_u_b(res0, inp15);
    ST_UB(res0, dst);
}