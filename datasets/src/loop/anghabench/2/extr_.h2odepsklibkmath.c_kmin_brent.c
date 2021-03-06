#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  double (* kmin1_f ) (double,int /*<<< orphan*/ *) ;

/* Variables and functions */
 double fabs (double) ; 

double kmin_brent(kmin1_f func, double a, double b, void *data, double tol, double *xmin)
{
	double bound, u, r, q, fu, tmp, fa, fb, fc, c;
	const double gold1 = 1.6180339887;
	const double gold2 = 0.3819660113;
	const double tiny = 1e-20;
	const int max_iter = 100;

	double e, d, w, v, mid, tol1, tol2, p, eold, fv, fw;
	int iter;

	fa = func(a, data); fb = func(b, data);
	if (fb > fa) { // swap, such that f(a) > f(b)
		tmp = a; a = b; b = tmp;
		tmp = fa; fa = fb; fb = tmp;
	}
	c = b + gold1 * (b - a), fc = func(c, data); // golden section extrapolation
	while (fb > fc) {
		bound = b + 100.0 * (c - b); // the farthest point where we want to go
		r = (b - a) * (fb - fc);
		q = (b - c) * (fb - fa);
		if (fabs(q - r) < tiny) { // avoid 0 denominator
			tmp = q > r? tiny : 0.0 - tiny;
		} else tmp = q - r;
		u = b - ((b - c) * q - (b - a) * r) / (2.0 * tmp); // u is the parabolic extrapolation point
		if ((b > u && u > c) || (b < u && u < c)) { // u lies between b and c
			fu = func(u, data);
			if (fu < fc) { // (b,u,c) bracket the minimum
				a = b; b = u; fa = fb; fb = fu;
				break;
			} else if (fu > fb) { // (a,b,u) bracket the minimum
				c = u; fc = fu;
				break;
			}
			u = c + gold1 * (c - b); fu = func(u, data); // golden section extrapolation
		} else if ((c > u && u > bound) || (c < u && u < bound)) { // u lies between c and bound
			fu = func(u, data);
			if (fu < fc) { // fb > fc > fu
				b = c; c = u; u = c + gold1 * (c - b);
				fb = fc; fc = fu; fu = func(u, data);
			} else { // (b,c,u) bracket the minimum
				a = b; b = c; c = u;
				fa = fb; fb = fc; fc = fu;
				break;
			}
		} else if ((u > bound && bound > c) || (u < bound && bound < c)) { // u goes beyond the bound
			u = bound; fu = func(u, data);
		} else { // u goes the other way around, use golden section extrapolation
			u = c + gold1 * (c - b); fu = func(u, data);
		}
		a = b; b = c; c = u;
		fa = fb; fb = fc; fc = fu;
	}
	if (a > c) u = a, a = c, c = u; // swap

	// now, a<b<c, fa>fb and fb<fc, move on to Brent's algorithm
	e = d = 0.0;
	w = v = b; fv = fw = fb;
	for (iter = 0; iter != max_iter; ++iter) {
		mid = 0.5 * (a + c);
		tol2 = 2.0 * (tol1 = tol * fabs(b) + tiny);
		if (fabs(b - mid) <= (tol2 - 0.5 * (c - a))) {
			*xmin = b; return fb; // found
		}
		if (fabs(e) > tol1) {
			// related to parabolic interpolation
			r = (b - w) * (fb - fv);
			q = (b - v) * (fb - fw);
			p = (b - v) * q - (b - w) * r;
			q = 2.0 * (q - r);
			if (q > 0.0) p = 0.0 - p;
			else q = 0.0 - q;
			eold = e; e = d;
			if (fabs(p) >= fabs(0.5 * q * eold) || p <= q * (a - b) || p >= q * (c - b)) {
				d = gold2 * (e = (b >= mid ? a - b : c - b));
			} else {
				d = p / q; u = b + d; // actual parabolic interpolation happens here
				if (u - a < tol2 || c - u < tol2)
					d = (mid > b)? tol1 : 0.0 - tol1;
			}
		} else d = gold2 * (e = (b >= mid ? a - b : c - b)); // golden section interpolation
		u = fabs(d) >= tol1 ? b + d : b + (d > 0.0? tol1 : -tol1);
		fu = func(u, data);
		if (fu <= fb) { // u is the minimum point so far
			if (u >= b) a = b;
			else c = b;
			v = w; w = b; b = u; fv = fw; fw = fb; fb = fu;
		} else { // adjust (a,c) and (u,v,w)
			if (u < b) a = u;
			else c = u;
			if (fu <= fw || w == b) {
				v = w; w = u;
				fv = fw; fw = fu;
			} else if (fu <= fv || v == b || v == w) {
				v = u; fv = fu;
			}
		}
	}
	*xmin = b;
	return fb;
}