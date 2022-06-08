#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int integer ;
struct TYPE_9__ {float r; float i; } ;
typedef  TYPE_1__ complex ;

/* Variables and functions */
 int c__1 ; 
 int /*<<< orphan*/  clarf_ (char*,int*,int*,TYPE_1__*,int*,TYPE_1__*,TYPE_1__*,int*,TYPE_1__*) ; 
 int max (int,int) ; 
 int /*<<< orphan*/  xerbla_ (char*,int*) ; 

int cung2r_(integer *m, integer *n, integer *k, complex *a,
	integer *lda, complex *tau, complex *work, integer *info)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3;
    complex q__1;

    /* Local variables */
    static integer i__, j, l;
    extern /* Subroutine */ int cscal_(integer *, complex *, complex *,
	    integer *), clarf_(char *, integer *, integer *, complex *,
	    integer *, complex *, complex *, integer *, complex *),
	    xerbla_(char *, integer *);


/*
    -- LAPACK routine (version 3.2) --
    -- LAPACK is a software package provided by Univ. of Tennessee,    --
    -- Univ. of California Berkeley, Univ. of Colorado Denver and NAG Ltd..--
       November 2006


    Purpose
    =======

    CUNG2R generates an m by n complex matrix Q with orthonormal columns,
    which is defined as the first n columns of a product of k elementary
    reflectors of order m

          Q  =  H(1) H(2) . . . H(k)

    as returned by CGEQRF.

    Arguments
    =========

    M       (input) INTEGER
            The number of rows of the matrix Q. M >= 0.

    N       (input) INTEGER
            The number of columns of the matrix Q. M >= N >= 0.

    K       (input) INTEGER
            The number of elementary reflectors whose product defines the
            matrix Q. N >= K >= 0.

    A       (input/output) COMPLEX array, dimension (LDA,N)
            On entry, the i-th column must contain the vector which
            defines the elementary reflector H(i), for i = 1,2,...,k, as
            returned by CGEQRF in the first k columns of its array
            argument A.
            On exit, the m by n matrix Q.

    LDA     (input) INTEGER
            The first dimension of the array A. LDA >= max(1,M).

    TAU     (input) COMPLEX array, dimension (K)
            TAU(i) must contain the scalar factor of the elementary
            reflector H(i), as returned by CGEQRF.

    WORK    (workspace) COMPLEX array, dimension (N)

    INFO    (output) INTEGER
            = 0: successful exit
            < 0: if INFO = -i, the i-th argument has an illegal value

    =====================================================================


       Test the input arguments
*/

    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --tau;
    --work;

    /* Function Body */
    *info = 0;
    if (*m < 0) {
	*info = -1;
    } else if (*n < 0 || *n > *m) {
	*info = -2;
    } else if (*k < 0 || *k > *n) {
	*info = -3;
    } else if (*lda < max(1,*m)) {
	*info = -5;
    }
    if (*info != 0) {
	i__1 = -(*info);
	xerbla_("CUNG2R", &i__1);
	return 0;
    }

/*     Quick return if possible */

    if (*n <= 0) {
	return 0;
    }

/*     Initialise columns k+1:n to columns of the unit matrix */

    i__1 = *n;
    for (j = *k + 1; j <= i__1; ++j) {
	i__2 = *m;
	for (l = 1; l <= i__2; ++l) {
	    i__3 = l + j * a_dim1;
	    a[i__3].r = 0.f, a[i__3].i = 0.f;
/* L10: */
	}
	i__2 = j + j * a_dim1;
	a[i__2].r = 1.f, a[i__2].i = 0.f;
/* L20: */
    }

    for (i__ = *k; i__ >= 1; --i__) {

/*        Apply H(i) to A(i:m,i:n) from the left */

	if (i__ < *n) {
	    i__1 = i__ + i__ * a_dim1;
	    a[i__1].r = 1.f, a[i__1].i = 0.f;
	    i__1 = *m - i__ + 1;
	    i__2 = *n - i__;
	    clarf_("Left", &i__1, &i__2, &a[i__ + i__ * a_dim1], &c__1, &tau[
		    i__], &a[i__ + (i__ + 1) * a_dim1], lda, &work[1]);
	}
	if (i__ < *m) {
	    i__1 = *m - i__;
	    i__2 = i__;
	    q__1.r = -tau[i__2].r, q__1.i = -tau[i__2].i;
	    cscal_(&i__1, &q__1, &a[i__ + 1 + i__ * a_dim1], &c__1);
	}
	i__1 = i__ + i__ * a_dim1;
	i__2 = i__;
	q__1.r = 1.f - tau[i__2].r, q__1.i = 0.f - tau[i__2].i;
	a[i__1].r = q__1.r, a[i__1].i = q__1.i;

/*        Set A(1:i-1,i) to zero */

	i__1 = i__ - 1;
	for (l = 1; l <= i__1; ++l) {
	    i__2 = l + i__ * a_dim1;
	    a[i__2].r = 0.f, a[i__2].i = 0.f;
/* L30: */
	}
/* L40: */
    }
    return 0;

/*     End of CUNG2R */

}