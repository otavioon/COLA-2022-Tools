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

/* Variables and functions */

regp() {     /*   pointer to register assignment   */
/*   Testing a variable whose storage class has been spec-
ified as "register" is somewhat tricky, but it can be done in a 
fairly reliable fashion by taking advantage of our knowledge of the
ways in which compilers operate. If we declare a collection of vari-
ables of the same storage class, we would expect that, when storage
for these variables is actually allocated, the variables will be 
bunched together and ordered according to one of the following
criteria:

     (a) the order in which they were defined.
     (b) the order in which they are used.
     (c) alphabetically.
     (d) the order in which they appear in the compiler's
         symbol table.
     (e) some other way.

     Hence, if we define a sequence of variables in close alpha-
betical order, and use them in the same order in which we define
them, we would expect the differences between the addresses of
successive variables to be constant, except in case (d) where the
symbol table is a hash table, or in case (e). If a subsequence in
the middle of this sequence is selected, and for this subsequence,
every other variable is specified to be "register", and address
differences are taken between adjacent nonregister variables, we would
still expect to find constant differences if the "register" vari-
ables were actually assigned to registers, and some other diff-
erences if they were not. Specifically, if we had N variables 
specified as "register" of which the first n were actually ass-
igned to registers, we would expect the sequence of differences
to consist of a number of occurrences of some number, followed by
N-n occurrences of some other number, followed by several occurr-
ences of the first number. If we get a sequence like this, we can
determine, by simple subtraction, how many (if any) variables are
being assigned to registers. If we get some other sequence, we know
that the test is invalid.                                     */


            int *r00;
            int *r01;
            int *r02;
            int *r03;
   register int *r04;
            int *r05;
   register int *r06;
            int *r07;
   register int *r08;
            int *r09;
   register int *r10;
            int *r11;
   register int *r12;
            int *r13;
   register int *r14;
            int *r15;
   register int *r16;
            int *r17;
   register int *r18;
            int *r19;
   register int *r20;
            int *r21;
   register int *r22;
            int *r23;
   register int *r24;
            int *r25;
   register int *r26;
            int *r27;
   register int *r28;
            int *r29;
   register int *r30;
            int *r31;
   register int *r32;
            int *r33;
   register int *r34;
            int *r35;
            int *r36;
            int *r37;
            int *r38;

   int s, n1, n2, nr, j, d[22];

   r00 = (int *)&r00;
   r01 = (int *)&r01;
   r02 = (int *)&r02;
   r03 = (int *)&r03;
   r04 = (int *)&r05;
   r05 = (int *)&r05;
   r06 = (int *)&r07;
   r07 = (int *)&r07;
   r08 = (int *)&r09;
   r09 = (int *)&r09;
   r10 = (int *)&r11;
   r11 = (int *)&r11;
   r12 = (int *)&r13;
   r13 = (int *)&r13;
   r14 = (int *)&r15;
   r15 = (int *)&r15;
   r16 = (int *)&r17;
   r17 = (int *)&r17;
   r18 = (int *)&r19;
   r19 = (int *)&r19;
   r20 = (int *)&r21;
   r21 = (int *)&r21;
   r22 = (int *)&r23;
   r23 = (int *)&r23;
   r24 = (int *)&r25;
   r25 = (int *)&r25;
   r26 = (int *)&r27;
   r27 = (int *)&r27;
   r28 = (int *)&r29;
   r29 = (int *)&r29;
   r30 = (int *)&r31;
   r31 = (int *)&r31;
   r32 = (int *)&r33;
   r33 = (int *)&r33;
   r34 = (int *)&r35;
   r35 = (int *)&r35;
   r36 = (int *)&r36;
   r37 = (int *)&r37;
   r38 = (int *)&r38;

   d[0] = &r01 - &r00;
   d[1] = &r02 - &r01;
   d[2] = &r03 - &r02;
   d[3] = &r05 - &r03;
   d[4] = &r07 - &r05;
   d[5] = &r09 - &r07;
   d[6] = &r11 - &r09;
   d[7] = &r13 - &r11;
   d[8] = &r15 - &r13;
   d[9] = &r17 - &r15;
   d[10] = &r19 - &r17;
   d[11] = &r21 - &r19;
   d[12] = &r23 - &r21;
   d[13] = &r25 - &r23;
   d[14] = &r27 - &r25;
   d[15] = &r29 - &r27;
   d[16] = &r31 - &r29;
   d[17] = &r33 - &r31;
   d[18] = &r35 - &r33;
   d[19] = &r36 - &r35;
   d[20] = &r37 - &r36;
   d[21] = &r38 - &r37;


/*   The following FSM analyzes the string of differences. It accepts
strings of the form a+b+a+ and returns 16 minus the number of bs, 
which is the number of variables that actually got into registers.
Otherwise it signals rejection by returning -1., indicating that the
test is unreliable.              */

   n1 = d[0];
   s = 1;
   for (j=0; j<22; j++)
     switch (s) {
       case 1: if (d[j] != n1) {
                n2 = d[j];
                s = 2;
                nr = 1;
               }
               break;
       case 2: if (d[j] == n1) {
                s = 3;
                break;
               }
               if (d[j] == n2) {
                nr = nr+1;
                break;
               }
               s = 4;
               break;
       case 3: if (d[j] != n1) s = 4;
               break;
     }
   ;

   if (s == 3) return 16-nr;
   else return -1;
}