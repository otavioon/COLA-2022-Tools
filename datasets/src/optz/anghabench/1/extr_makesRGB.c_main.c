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
typedef  int png_uint_16 ;
typedef  int png_byte ;

/* Variables and functions */
 unsigned int PNG_sRGB_FROM_LINEAR (unsigned int) ; 
 int abs (unsigned int) ; 
 int /*<<< orphan*/  exit (int) ; 
 double finvsRGB (unsigned int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 double fsRGB (int) ; 
 int invsRGB (unsigned int) ; 
 unsigned int max_input ; 
 unsigned int nearbyint (int) ; 
 int* png_sRGB_base ; 
 int* png_sRGB_delta ; 
 int* png_sRGB_table ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int sRGB (unsigned int) ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ strcmp (char*,char*) ; 

int
main(int argc, char **argv)
{
   unsigned int i, i16, ibase;
   double min_error = 0;
   double max_error = 0;
   double min_error16 = 0;
   double max_error16 = 0;
   double adjust;
   double adjust_lo = 0.4, adjust_hi = 0.6, adjust_mid = 0.5;
   unsigned int ec_lo = 0, ec_hi = 0, ec_mid = 0;
   unsigned int error_count = 0;
   unsigned int error_count16 = 0;
   int test_only = 0;

   if (argc > 1)
      test_only = strcmp("--test", argv[1]) == 0;

   /* Initialize the encoding table first. */
   for (i=0; i<256; ++i)
   {
      png_sRGB_table[i] = invsRGB(i);
   }

   /* Now work out the decoding tables (this is where the error comes in because
    * there are 512 set points and 512 straight lines between them.)
    */
   for (;;)
   {
      if (ec_lo == 0)
         adjust = adjust_lo;

      else if (ec_hi == 0)
         adjust = adjust_hi;

      else if (ec_mid == 0)
         adjust = adjust_mid;

      else if (ec_mid < ec_hi)
         adjust = (adjust_mid + adjust_hi)/2;

      else if (ec_mid < ec_lo)
         adjust = (adjust_mid + adjust_lo)/2;

      else
      {
         fprintf(stderr, "not reached: %u .. %u .. %u\n", ec_lo, ec_mid, ec_hi);
         exit(1);
      }

      /* Calculate the table using the current 'adjust' */
      for (i=0; i<=511; ++i)
      {
         double lo = 255 * sRGB(i << 15);
         double hi = 255 * sRGB((i+1) << 15);
         unsigned int calc;

         calc = nearbyint((lo+adjust) * 256);
         if (calc > 65535)
         {
            fprintf(stderr, "table[%d][0]: overflow %08x (%d)\n", i, calc,
               calc);
            exit(1);
         }
         png_sRGB_base[i] = calc;

         calc = nearbyint((hi-lo) * 32);
         if (calc > 255)
         {
            fprintf(stderr, "table[%d][1]: overflow %08x (%d)\n", i, calc,
               calc);
            exit(1);
         }
         png_sRGB_delta[i] = calc;
      }

      /* Check the 16-bit linear values alone: */
      error_count16 = 0;
      for (i16=0; i16 <= 65535; ++i16)
      {
         unsigned int i = 255*i16;
         unsigned int iexact = nearbyint(255*sRGB(i));
         unsigned int icalc = PNG_sRGB_FROM_LINEAR(i);

         if (icalc != iexact)
            ++error_count16;
      }

      /* Now try changing the adjustment. */
      if (ec_lo == 0)
         ec_lo = error_count16;

      else if (ec_hi == 0)
         ec_hi = error_count16;

      else if (ec_mid == 0)
      {
         ec_mid = error_count16;
         printf("/* initial error counts: %u .. %u .. %u */\n", ec_lo, ec_mid,
            ec_hi);
      }

      else if (error_count16 < ec_mid)
      {
         printf("/* adjust (mid ): %f: %u -> %u */\n", adjust, ec_mid,
            error_count16);
         ec_mid = error_count16;
         adjust_mid = adjust;
      }

      else if (adjust < adjust_mid && error_count16 < ec_lo)
      {
         printf("/* adjust (low ): %f: %u -> %u */\n", adjust, ec_lo,
            error_count16);
         ec_lo = error_count16;
         adjust_lo = adjust;
      }

      else if (adjust > adjust_mid && error_count16 < ec_hi)
      {
         printf("/* adjust (high): %f: %u -> %u */\n", adjust, ec_hi,
            error_count16);
         ec_hi = error_count16;
         adjust_hi = adjust;
      }

      else
      {
         adjust = adjust_mid;
         printf("/* adjust: %f: %u */\n", adjust, ec_mid);
         break;
      }
   }

   /* For each entry in the table try to adjust it to minimize the error count
    * in that entry.  Each entry corresponds to 128 input values.
    */
   for (ibase=0; ibase<65536; ibase+=128)
   {
      png_uint_16 base = png_sRGB_base[ibase >> 7], trybase = base, ob=base;
      png_byte delta = png_sRGB_delta[ibase >> 7], trydelta = delta, od=delta;
      unsigned int ecbase = 0, eco;

      for (;;)
      {
         png_sRGB_base[ibase >> 7] = trybase;
         png_sRGB_delta[ibase >> 7] = trydelta;

         /* Check the 16-bit linear values alone: */
         error_count16 = 0;
         for (i16=ibase; i16 < ibase+128; ++i16)
         {
            unsigned int i = 255*i16;
            unsigned int iexact = nearbyint(255*sRGB(i));
            unsigned int icalc = PNG_sRGB_FROM_LINEAR(i);

            if (icalc != iexact)
               ++error_count16;
         }

         if (error_count16 == 0)
            break;

         if (ecbase == 0)
         {
            eco = ecbase = error_count16;
            ++trybase; /* First test */
         }

         else if (error_count16 < ecbase)
         {
            if (trybase > base)
            {
               base = trybase;
               ++trybase;
            }
            else if (trybase < base)
            {
               base = trybase;
               --trybase;
            }
            else if (trydelta > delta)
            {
               delta = trydelta;
               ++trydelta;
            }
            else if (trydelta < delta)
            {
               delta = trydelta;
               --trydelta;
            }
            else
            {
               fprintf(stderr, "makesRGB: impossible\n");
               exit(1);
            }
            ecbase = error_count16;
         }

         else
         {
            if (trybase > base)
               trybase = base-1;
            else if (trybase < base)
            {
               trybase = base;
               ++trydelta;
            }
            else if (trydelta > delta)
               trydelta = delta-1;
            else if (trydelta < delta)
               break; /* end of tests */
         }
      }

      png_sRGB_base[ibase >> 7] = base;
      png_sRGB_delta[ibase >> 7] = delta;
      if (base != ob || delta != od)
      {
         printf("/* table[%u]={%u,%u} -> {%u,%u} %u -> %u errors */\n",
            ibase>>7, ob, od, base, delta, eco, ecbase);
      }
      else if (0)
         printf("/* table[%u]={%u,%u} %u errors */\n", ibase>>7, ob, od,
            ecbase);
   }

   /* Only do the full (slow) test at the end: */
   min_error = -.4999;
   max_error = .4999;
   error_count = 0;

   for (i=0; i <= max_input; ++i)
   {
      unsigned int iexact = nearbyint(255*sRGB(i));
      unsigned int icalc = PNG_sRGB_FROM_LINEAR(i);

      if (icalc != iexact)
      {
         double err = 255*sRGB(i) - icalc;

         if (err > (max_error+.001) || err < (min_error-.001))
         {
            printf(
               "/* 0x%08x: exact: %3d, got: %3d [tables: %08x, %08x] (%f) */\n",
               i, iexact, icalc, png_sRGB_base[i>>15],
               png_sRGB_delta[i>>15], err);
         }

         ++error_count;
         if (err > max_error)
            max_error = err;
         else if (err < min_error)
            min_error = err;
      }
   }

   /* Re-check the 16-bit cases too, including the warning if there is an error
    * bigger than 1.
    */
   error_count16 = 0;
   max_error16 = 0;
   min_error16 = 0;
   for (i16=0; i16 <= 65535; ++i16)
   {
      unsigned int i = 255*i16;
      unsigned int iexact = nearbyint(255*sRGB(i));
      unsigned int icalc = PNG_sRGB_FROM_LINEAR(i);

      if (icalc != iexact)
      {
         double err = 255*sRGB(i) - icalc;

         ++error_count16;
         if (err > max_error16)
            max_error16 = err;
         else if (err < min_error16)
            min_error16 = err;

         if (abs(icalc - iexact) > 1)
            printf(
               "/* 0x%04x: exact: %3d, got: %3d [tables: %08x, %08x] (%f) */\n",
               i16, iexact, icalc, png_sRGB_base[i>>15],
               png_sRGB_delta[i>>15], err);
      }
   }

   /* Check the round trip for each 8-bit sRGB value. */
   for (i16=0; i16 <= 255; ++i16)
   {
      unsigned int i = 255 * png_sRGB_table[i16];
      unsigned int iexact = nearbyint(255*sRGB(i));
      unsigned int icalc = PNG_sRGB_FROM_LINEAR(i);

      if (i16 != iexact)
      {
         fprintf(stderr, "8-bit rounding error: %d -> %d\n", i16, iexact);
         exit(1);
      }

      if (icalc != i16)
      {
         double finv = finvsRGB(i16);

         printf("/* 8-bit roundtrip error: %d -> %f -> %d(%f) */\n",
            i16, finv, icalc, fsRGB(255*finv));
      }
   }


   printf("/* error: %g - %g, %u (%g%%) of readings inexact */\n",
      min_error, max_error, error_count, (100.*error_count)/max_input);
   printf("/* 16-bit error: %g - %g, %u (%g%%) of readings inexact */\n",
      min_error16, max_error16, error_count16, (100.*error_count16)/65535);

   if (!test_only)
   {
      printf("PNG_CONST png_uint_16 png_sRGB_table[256] =\n{\n   ");
      for (i=0; i<255; )
      {
         do
         {
            printf("%d,", png_sRGB_table[i++]);
         }
         while ((i & 0x7) != 0 && i<255);
         if (i<255) printf("\n   ");
      }
      printf("%d\n};\n\n", png_sRGB_table[i]);


      printf("PNG_CONST png_uint_16 png_sRGB_base[512] =\n{\n   ");
      for (i=0; i<511; )
      {
         do
         {
            printf("%d,", png_sRGB_base[i++]);
         }
         while ((i & 0x7) != 0 && i<511);
         if (i<511) printf("\n   ");
      }
      printf("%d\n};\n\n", png_sRGB_base[i]);

      printf("PNG_CONST png_byte png_sRGB_delta[512] =\n{\n   ");
      for (i=0; i<511; )
      {
         do
         {
            printf("%d,", png_sRGB_delta[i++]);
         }
         while ((i & 0xf) != 0 && i<511);
         if (i<511) printf("\n   ");
      }
      printf("%d\n};\n\n", png_sRGB_delta[i]);
   }

   return 0;
}