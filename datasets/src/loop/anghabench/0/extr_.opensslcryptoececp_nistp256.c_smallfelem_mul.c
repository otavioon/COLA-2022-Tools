#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int uint128_t ;
typedef  int u64 ;
typedef  int* smallfelem ;
typedef  int* longfelem ;
typedef  int limb ;

/* Variables and functions */

__attribute__((used)) static void smallfelem_mul(longfelem out, const smallfelem small1,
                           const smallfelem small2)
{
    limb a;
    u64 high, low;

    a = ((uint128_t) small1[0]) * small2[0];
    low = a;
    high = a >> 64;
    out[0] = low;
    out[1] = high;

    a = ((uint128_t) small1[0]) * small2[1];
    low = a;
    high = a >> 64;
    out[1] += low;
    out[2] = high;

    a = ((uint128_t) small1[1]) * small2[0];
    low = a;
    high = a >> 64;
    out[1] += low;
    out[2] += high;

    a = ((uint128_t) small1[0]) * small2[2];
    low = a;
    high = a >> 64;
    out[2] += low;
    out[3] = high;

    a = ((uint128_t) small1[1]) * small2[1];
    low = a;
    high = a >> 64;
    out[2] += low;
    out[3] += high;

    a = ((uint128_t) small1[2]) * small2[0];
    low = a;
    high = a >> 64;
    out[2] += low;
    out[3] += high;

    a = ((uint128_t) small1[0]) * small2[3];
    low = a;
    high = a >> 64;
    out[3] += low;
    out[4] = high;

    a = ((uint128_t) small1[1]) * small2[2];
    low = a;
    high = a >> 64;
    out[3] += low;
    out[4] += high;

    a = ((uint128_t) small1[2]) * small2[1];
    low = a;
    high = a >> 64;
    out[3] += low;
    out[4] += high;

    a = ((uint128_t) small1[3]) * small2[0];
    low = a;
    high = a >> 64;
    out[3] += low;
    out[4] += high;

    a = ((uint128_t) small1[1]) * small2[3];
    low = a;
    high = a >> 64;
    out[4] += low;
    out[5] = high;

    a = ((uint128_t) small1[2]) * small2[2];
    low = a;
    high = a >> 64;
    out[4] += low;
    out[5] += high;

    a = ((uint128_t) small1[3]) * small2[1];
    low = a;
    high = a >> 64;
    out[4] += low;
    out[5] += high;

    a = ((uint128_t) small1[2]) * small2[3];
    low = a;
    high = a >> 64;
    out[5] += low;
    out[6] = high;

    a = ((uint128_t) small1[3]) * small2[2];
    low = a;
    high = a >> 64;
    out[5] += low;
    out[6] += high;

    a = ((uint128_t) small1[3]) * small2[3];
    low = a;
    high = a >> 64;
    out[6] += low;
    out[7] = high;
}