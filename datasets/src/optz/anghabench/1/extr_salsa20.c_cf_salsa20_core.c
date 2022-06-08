#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  scalar_t__ uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  COLUMN ; 
 int /*<<< orphan*/  ROW ; 
 scalar_t__ read32_le (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  write32_le (scalar_t__,int /*<<< orphan*/ *) ; 

void cf_salsa20_core(const uint8_t key0[16],
                     const uint8_t key1[16],
                     const uint8_t nonce[16],
                     const uint8_t constant[16],
                     uint8_t out[64])
{
  /* unpack sequence is:
   *
   * c0
   * key0
   * c1
   * nonce
   * c2
   * key1
   * c3
   *
   * where c0, c1, c2, c3 = constant
   */
  
  uint32_t z0, z1, z2, z3, z4, z5, z6, z7,
           z8, z9, za, zb, zc, zd, ze, zf;

  uint32_t x0 = z0 = read32_le(constant + 0),
           x1 = z1 = read32_le(key0 + 0),
           x2 = z2 = read32_le(key0 + 4),
           x3 = z3 = read32_le(key0 + 8),
           x4 = z4 = read32_le(key0 + 12),
           x5 = z5 = read32_le(constant + 4),
           x6 = z6 = read32_le(nonce + 0),
           x7 = z7 = read32_le(nonce + 4),
           x8 = z8 = read32_le(nonce + 8),
           x9 = z9 = read32_le(nonce + 12),
           xa = za = read32_le(constant + 8),
           xb = zb = read32_le(key1 + 0),
           xc = zc = read32_le(key1 + 4),
           xd = zd = read32_le(key1 + 8),
           xe = ze = read32_le(key1 + 12),
           xf = zf = read32_le(constant + 12);

#define QUARTER(v0, v1, v2, v3) \
  v1 ^= rotl32(v0 + v3, 7); \
  v2 ^= rotl32(v1 + v0, 9); \
  v3 ^= rotl32(v2 + v1, 13);\
  v0 ^= rotl32(v3 + v2, 18)

#define ROW \
  QUARTER(z0, z1, z2, z3); \
  QUARTER(z5, z6, z7, z4); \
  QUARTER(za, zb, z8, z9); \
  QUARTER(zf, zc, zd, ze)

#define COLUMN\
  QUARTER(z0, z4, z8, zc); \
  QUARTER(z5, z9, zd, z1); \
  QUARTER(za, ze, z2, z6); \
  QUARTER(zf, z3, z7, zb)

  for (int i = 0; i < 10; i++)
  {
    COLUMN;
    ROW;
  }

  x0 += z0;
  x1 += z1;
  x2 += z2;
  x3 += z3;
  x4 += z4;
  x5 += z5;
  x6 += z6;
  x7 += z7;
  x8 += z8;
  x9 += z9;
  xa += za;
  xb += zb;
  xc += zc;
  xd += zd;
  xe += ze;
  xf += zf;

  write32_le(x0, out + 0);
  write32_le(x1, out + 4);
  write32_le(x2, out + 8);
  write32_le(x3, out + 12);
  write32_le(x4, out + 16);
  write32_le(x5, out + 20);
  write32_le(x6, out + 24);
  write32_le(x7, out + 28);
  write32_le(x8, out + 32);
  write32_le(x9, out + 36);
  write32_le(xa, out + 40);
  write32_le(xb, out + 44);
  write32_le(xc, out + 48);
  write32_le(xd, out + 52);
  write32_le(xe, out + 56);
  write32_le(xf, out + 60);
}