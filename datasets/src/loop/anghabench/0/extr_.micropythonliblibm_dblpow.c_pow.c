#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int uint32_t ;
typedef  int int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  EXTRACT_WORDS (int,int,double) ; 
 int /*<<< orphan*/  GET_HIGH_WORD (int,double) ; 
 double L1 ; 
 double L2 ; 
 double L3 ; 
 double L4 ; 
 double L5 ; 
 double L6 ; 
 double P1 ; 
 double P2 ; 
 double P3 ; 
 double P4 ; 
 double P5 ; 
 int /*<<< orphan*/  SET_HIGH_WORD (double,int) ; 
 int /*<<< orphan*/  SET_LOW_WORD (double,int /*<<< orphan*/ ) ; 
 double* bp ; 
 double cp ; 
 double cp_h ; 
 double cp_l ; 
 double* dp_h ; 
 double* dp_l ; 
 double fabs (double) ; 
 double huge ; 
 double ivln2 ; 
 double ivln2_h ; 
 double ivln2_l ; 
 double lg2 ; 
 double lg2_h ; 
 double lg2_l ; 
 double ovt ; 
 double scalbn (double,int) ; 
 double sqrt (double) ; 
 double tiny ; 
 double two53 ; 

double pow(double x, double y)
{
	double z,ax,z_h,z_l,p_h,p_l;
	double y1,t1,t2,r,s,t,u,v,w;
	int32_t i,j,k,yisint,n;
	int32_t hx,hy,ix,iy;
	uint32_t lx,ly;

	EXTRACT_WORDS(hx, lx, x);
	EXTRACT_WORDS(hy, ly, y);
	ix = hx & 0x7fffffff;
	iy = hy & 0x7fffffff;

	/* x**0 = 1, even if x is NaN */
	if ((iy|ly) == 0)
		return 1.0;
	/* 1**y = 1, even if y is NaN */
	if (hx == 0x3ff00000 && lx == 0)
		return 1.0;
	/* NaN if either arg is NaN */
	if (ix > 0x7ff00000 || (ix == 0x7ff00000 && lx != 0) ||
	    iy > 0x7ff00000 || (iy == 0x7ff00000 && ly != 0))
		return x + y;

	/* determine if y is an odd int when x < 0
	 * yisint = 0       ... y is not an integer
	 * yisint = 1       ... y is an odd int
	 * yisint = 2       ... y is an even int
	 */
	yisint = 0;
	if (hx < 0) {
		if (iy >= 0x43400000)
			yisint = 2; /* even integer y */
		else if (iy >= 0x3ff00000) {
			k = (iy>>20) - 0x3ff;  /* exponent */
			if (k > 20) {
				uint32_t j = ly>>(52-k);
				if ((j<<(52-k)) == ly)
					yisint = 2 - (j&1);
			} else if (ly == 0) {
				uint32_t j = iy>>(20-k);
				if ((j<<(20-k)) == iy)
					yisint = 2 - (j&1);
			}
		}
	}

	/* special value of y */
	if (ly == 0) {
		if (iy == 0x7ff00000) {  /* y is +-inf */
			if (((ix-0x3ff00000)|lx) == 0)  /* (-1)**+-inf is 1 */
				return 1.0;
			else if (ix >= 0x3ff00000) /* (|x|>1)**+-inf = inf,0 */
				return hy >= 0 ? y : 0.0;
			else                       /* (|x|<1)**+-inf = 0,inf */
				return hy >= 0 ? 0.0 : -y;
		}
		if (iy == 0x3ff00000) {    /* y is +-1 */
			if (hy >= 0)
				return x;
			y = 1/x;
#if FLT_EVAL_METHOD!=0
			{
				union {double f; uint64_t i;} u = {y};
				uint64_t i = u.i & -1ULL/2;
				if (i>>52 == 0 && (i&(i-1)))
					FORCE_EVAL((float)y);
			}
#endif
			return y;
		}
		if (hy == 0x40000000)    /* y is 2 */
			return x*x;
		if (hy == 0x3fe00000) {  /* y is 0.5 */
			if (hx >= 0)     /* x >= +0 */
				return sqrt(x);
		}
	}

	ax = fabs(x);
	/* special value of x */
	if (lx == 0) {
		if (ix == 0x7ff00000 || ix == 0 || ix == 0x3ff00000) { /* x is +-0,+-inf,+-1 */
			z = ax;
			if (hy < 0)   /* z = (1/|x|) */
				z = 1.0/z;
			if (hx < 0) {
				if (((ix-0x3ff00000)|yisint) == 0) {
					z = (z-z)/(z-z); /* (-1)**non-int is NaN */
				} else if (yisint == 1)
					z = -z;          /* (x<0)**odd = -(|x|**odd) */
			}
			return z;
		}
	}

	s = 1.0; /* sign of result */
	if (hx < 0) {
		if (yisint == 0) /* (x<0)**(non-int) is NaN */
			return (x-x)/(x-x);
		if (yisint == 1) /* (x<0)**(odd int) */
			s = -1.0;
	}

	/* |y| is huge */
	if (iy > 0x41e00000) { /* if |y| > 2**31 */
		if (iy > 0x43f00000) {  /* if |y| > 2**64, must o/uflow */
			if (ix <= 0x3fefffff)
				return hy < 0 ? huge*huge : tiny*tiny;
			if (ix >= 0x3ff00000)
				return hy > 0 ? huge*huge : tiny*tiny;
		}
		/* over/underflow if x is not close to one */
		if (ix < 0x3fefffff)
			return hy < 0 ? s*huge*huge : s*tiny*tiny;
		if (ix > 0x3ff00000)
			return hy > 0 ? s*huge*huge : s*tiny*tiny;
		/* now |1-x| is tiny <= 2**-20, suffice to compute
		   log(x) by x-x^2/2+x^3/3-x^4/4 */
		t = ax - 1.0;       /* t has 20 trailing zeros */
		w = (t*t)*(0.5 - t*(0.3333333333333333333333-t*0.25));
		u = ivln2_h*t;      /* ivln2_h has 21 sig. bits */
		v = t*ivln2_l - w*ivln2;
		t1 = u + v;
		SET_LOW_WORD(t1, 0);
		t2 = v - (t1-u);
	} else {
		double ss,s2,s_h,s_l,t_h,t_l;
		n = 0;
		/* take care subnormal number */
		if (ix < 0x00100000) {
			ax *= two53;
			n -= 53;
			GET_HIGH_WORD(ix,ax);
		}
		n += ((ix)>>20) - 0x3ff;
		j = ix & 0x000fffff;
		/* determine interval */
		ix = j | 0x3ff00000;   /* normalize ix */
		if (j <= 0x3988E)      /* |x|<sqrt(3/2) */
			k = 0;
		else if (j < 0xBB67A)  /* |x|<sqrt(3)   */
			k = 1;
		else {
			k = 0;
			n += 1;
			ix -= 0x00100000;
		}
		SET_HIGH_WORD(ax, ix);

		/* compute ss = s_h+s_l = (x-1)/(x+1) or (x-1.5)/(x+1.5) */
		u = ax - bp[k];        /* bp[0]=1.0, bp[1]=1.5 */
		v = 1.0/(ax+bp[k]);
		ss = u*v;
		s_h = ss;
		SET_LOW_WORD(s_h, 0);
		/* t_h=ax+bp[k] High */
		t_h = 0.0;
		SET_HIGH_WORD(t_h, ((ix>>1)|0x20000000) + 0x00080000 + (k<<18));
		t_l = ax - (t_h-bp[k]);
		s_l = v*((u-s_h*t_h)-s_h*t_l);
		/* compute log(ax) */
		s2 = ss*ss;
		r = s2*s2*(L1+s2*(L2+s2*(L3+s2*(L4+s2*(L5+s2*L6)))));
		r += s_l*(s_h+ss);
		s2 = s_h*s_h;
		t_h = 3.0 + s2 + r;
		SET_LOW_WORD(t_h, 0);
		t_l = r - ((t_h-3.0)-s2);
		/* u+v = ss*(1+...) */
		u = s_h*t_h;
		v = s_l*t_h + t_l*ss;
		/* 2/(3log2)*(ss+...) */
		p_h = u + v;
		SET_LOW_WORD(p_h, 0);
		p_l = v - (p_h-u);
		z_h = cp_h*p_h;        /* cp_h+cp_l = 2/(3*log2) */
		z_l = cp_l*p_h+p_l*cp + dp_l[k];
		/* log2(ax) = (ss+..)*2/(3*log2) = n + dp_h + z_h + z_l */
		t = (double)n;
		t1 = ((z_h + z_l) + dp_h[k]) + t;
		SET_LOW_WORD(t1, 0);
		t2 = z_l - (((t1 - t) - dp_h[k]) - z_h);
	}

	/* split up y into y1+y2 and compute (y1+y2)*(t1+t2) */
	y1 = y;
	SET_LOW_WORD(y1, 0);
	p_l = (y-y1)*t1 + y*t2;
	p_h = y1*t1;
	z = p_l + p_h;
	EXTRACT_WORDS(j, i, z);
	if (j >= 0x40900000) {                      /* z >= 1024 */
		if (((j-0x40900000)|i) != 0)        /* if z > 1024 */
			return s*huge*huge;         /* overflow */
		if (p_l + ovt > z - p_h)
			return s*huge*huge;         /* overflow */
	} else if ((j&0x7fffffff) >= 0x4090cc00) {  /* z <= -1075 */  // FIXME: instead of abs(j) use unsigned j
		if (((j-0xc090cc00)|i) != 0)        /* z < -1075 */
			return s*tiny*tiny;         /* underflow */
		if (p_l <= z - p_h)
			return s*tiny*tiny;         /* underflow */
	}
	/*
	 * compute 2**(p_h+p_l)
	 */
	i = j & 0x7fffffff;
	k = (i>>20) - 0x3ff;
	n = 0;
	if (i > 0x3fe00000) {  /* if |z| > 0.5, set n = [z+0.5] */
		n = j + (0x00100000>>(k+1));
		k = ((n&0x7fffffff)>>20) - 0x3ff;  /* new k for n */
		t = 0.0;
		SET_HIGH_WORD(t, n & ~(0x000fffff>>k));
		n = ((n&0x000fffff)|0x00100000)>>(20-k);
		if (j < 0)
			n = -n;
		p_h -= t;
	}
	t = p_l + p_h;
	SET_LOW_WORD(t, 0);
	u = t*lg2_h;
	v = (p_l-(t-p_h))*lg2 + t*lg2_l;
	z = u + v;
	w = v - (z-u);
	t = z*z;
	t1 = z - t*(P1+t*(P2+t*(P3+t*(P4+t*P5))));
	r = (z*t1)/(t1-2.0) - (w + z*w);
	z = 1.0 - (r-z);
	GET_HIGH_WORD(j, z);
	j += n<<20;
	if ((j>>20) <= 0)  /* subnormal output */
		z = scalbn(z,n);
	else
		SET_HIGH_WORD(z, j);
	return s*z;
}