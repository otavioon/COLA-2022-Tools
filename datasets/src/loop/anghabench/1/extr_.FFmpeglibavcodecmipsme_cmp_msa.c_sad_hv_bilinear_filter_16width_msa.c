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
typedef  scalar_t__ v16u8 ;
typedef  int /*<<< orphan*/  v16i8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  HADD_UH_U32 (int) ; 
 int /*<<< orphan*/  ILVRL_B2_UB (scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  LD_UB4 (int /*<<< orphan*/ *,int,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  LD_UB5 (int /*<<< orphan*/ *,int,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  SRARI_H2_UH (int,int,int) ; 
 scalar_t__ __msa_asub_u_b (scalar_t__,scalar_t__) ; 
 int __msa_hadd_u_h (scalar_t__,scalar_t__) ; 
 int __msa_pckev_b (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static uint32_t sad_hv_bilinear_filter_16width_msa(uint8_t *src,
                                                   int32_t src_stride,
                                                   uint8_t *ref,
                                                   int32_t ref_stride,
                                                   int32_t height)
{
    int32_t ht_cnt;
    v16u8 src0, src1, src2, src3, comp, diff;
    v16u8 temp0, temp1, temp2, temp3;
    v16u8 ref00, ref01, ref02, ref03, ref04, ref10, ref11, ref12, ref13, ref14;
    v8u16 comp0, comp1, comp2, comp3;
    v8u16 sad = { 0 };

    for (ht_cnt = (height >> 3); ht_cnt--;) {
        LD_UB4(src, src_stride, src0, src1, src2, src3);
        src += (4 * src_stride);
        LD_UB5(ref, ref_stride, ref04, ref00, ref01, ref02, ref03);
        LD_UB5(ref + 1, ref_stride, ref14, ref10, ref11, ref12, ref13);
        ref += (5 * ref_stride);

        ILVRL_B2_UB(ref14, ref04, temp0, temp1);
        comp0 = __msa_hadd_u_h(temp0, temp0);
        comp1 = __msa_hadd_u_h(temp1, temp1);
        ILVRL_B2_UB(ref10, ref00, temp2, temp3);
        comp2 = __msa_hadd_u_h(temp2, temp2);
        comp3 = __msa_hadd_u_h(temp3, temp3);
        comp0 += comp2;
        comp1 += comp3;
        SRARI_H2_UH(comp0, comp1, 2);
        comp = (v16u8) __msa_pckev_b((v16i8) comp1, (v16i8) comp0);
        diff = __msa_asub_u_b(src0, comp);
        sad += __msa_hadd_u_h(diff, diff);

        ILVRL_B2_UB(ref11, ref01, temp0, temp1);
        comp0 = __msa_hadd_u_h(temp0, temp0);
        comp1 = __msa_hadd_u_h(temp1, temp1);
        comp2 += comp0;
        comp3 += comp1;
        SRARI_H2_UH(comp2, comp3, 2);
        comp = (v16u8) __msa_pckev_b((v16i8) comp3, (v16i8) comp2);
        diff = __msa_asub_u_b(src1, comp);
        sad += __msa_hadd_u_h(diff, diff);

        ILVRL_B2_UB(ref12, ref02, temp2, temp3);
        comp2 = __msa_hadd_u_h(temp2, temp2);
        comp3 = __msa_hadd_u_h(temp3, temp3);
        comp0 += comp2;
        comp1 += comp3;
        SRARI_H2_UH(comp0, comp1, 2);
        comp = (v16u8) __msa_pckev_b((v16i8) comp1, (v16i8) comp0);
        diff = __msa_asub_u_b(src2, comp);
        sad += __msa_hadd_u_h(diff, diff);

        ILVRL_B2_UB(ref13, ref03, temp0, temp1);
        comp0 = __msa_hadd_u_h(temp0, temp0);
        comp1 = __msa_hadd_u_h(temp1, temp1);
        comp2 += comp0;
        comp3 += comp1;
        SRARI_H2_UH(comp2, comp3, 2);
        comp = (v16u8) __msa_pckev_b((v16i8) comp3, (v16i8) comp2);
        diff = __msa_asub_u_b(src3, comp);
        sad += __msa_hadd_u_h(diff, diff);

        LD_UB4(src, src_stride, src0, src1, src2, src3);
        src += (4 * src_stride);
        LD_UB4(ref, ref_stride, ref00, ref01, ref02, ref03);
        LD_UB4(ref + 1, ref_stride, ref10, ref11, ref12, ref13);
        ref += (3 * ref_stride);

        ILVRL_B2_UB(ref10, ref00, temp2, temp3);
        comp2 = __msa_hadd_u_h(temp2, temp2);
        comp3 = __msa_hadd_u_h(temp3, temp3);
        comp0 += comp2;
        comp1 += comp3;
        SRARI_H2_UH(comp0, comp1, 2);
        comp = (v16u8) __msa_pckev_b((v16i8) comp1, (v16i8) comp0);
        diff = __msa_asub_u_b(src0, comp);
        sad += __msa_hadd_u_h(diff, diff);

        ILVRL_B2_UB(ref11, ref01, temp0, temp1);
        comp0 = __msa_hadd_u_h(temp0, temp0);
        comp1 = __msa_hadd_u_h(temp1, temp1);
        comp2 += comp0;
        comp3 += comp1;
        SRARI_H2_UH(comp2, comp3, 2);
        comp = (v16u8) __msa_pckev_b((v16i8) comp3, (v16i8) comp2);
        diff = __msa_asub_u_b(src1, comp);
        sad += __msa_hadd_u_h(diff, diff);

        ILVRL_B2_UB(ref12, ref02, temp2, temp3);
        comp2 = __msa_hadd_u_h(temp2, temp2);
        comp3 = __msa_hadd_u_h(temp3, temp3);
        comp0 += comp2;
        comp1 += comp3;
        SRARI_H2_UH(comp0, comp1, 2);
        comp = (v16u8) __msa_pckev_b((v16i8) comp1, (v16i8) comp0);
        diff = __msa_asub_u_b(src2, comp);
        sad += __msa_hadd_u_h(diff, diff);

        ILVRL_B2_UB(ref13, ref03, temp0, temp1);
        comp0 = __msa_hadd_u_h(temp0, temp0);
        comp1 = __msa_hadd_u_h(temp1, temp1);
        comp2 += comp0;
        comp3 += comp1;
        SRARI_H2_UH(comp2, comp3, 2);
        comp = (v16u8) __msa_pckev_b((v16i8) comp3, (v16i8) comp2);
        diff = __msa_asub_u_b(src3, comp);
        sad += __msa_hadd_u_h(diff, diff);
    }

    return (HADD_UH_U32(sad));
}