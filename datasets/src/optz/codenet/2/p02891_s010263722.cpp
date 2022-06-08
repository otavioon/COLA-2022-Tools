#include <bits/stdc++.h>

namespace function_by_Lsk {

// fast io
#define Wt write
#define Wtn(x) (Wt(x), putchar('\n'))
template <typename T> inline void read(T &x) {
	x = 0; bool sgn = false; char ch = getchar();
	while(!isdigit(ch)) (ch == '-') && (sgn = true), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	if(sgn) x = -x;
}
inline int Rd() { static int x; return read(x), x; }
template <typename T> inline void write(T x) {
	if(x < 0) {
		putchar('-'), write(-x);
	} else {
		if(x > 9) write(x / 10);
		putchar(x % 10 + '0');
	}
}

// cmin / cmax
template <typename T> inline void cmax(T &u, const T v) { if(u < v) u = v; }
template <typename T> inline void cmin(T &u, const T v) { if(u > v) u = v; }

// min / max
template <typename T> inline T max(const T u, const T v) { return u > v ? u : v; }
template <typename T> inline T min(const T u, const T v) { return u < v ? u : v; }

// math
template <typename T> inline T gcd(T u, T v) {
	return v ? gcd(v, u % v) : u;
}
inline long long fpm(long long base, int mi, int _mod) {
	long long res = 1;
	while(mi) {
		if(mi & 1) res = res * base % _mod;
		base = base * base % _mod, mi >>= 1;
	}
	return res;
}

} using namespace function_by_Lsk;

int n;
char S[105];
long long K, f[105][2][2], ans;

int main() {
	std :: cin >> (S + 1) >> K;
	n = strlen(S + 1);
	memset(f, 16, sizeof f);
	f[1][1][1] = 1, f[1][0][0] = 0;
	for(int i = 2; i <= n; ++i) {
		if(S[i] == S[i - 1]) {
			f[i][0][0] = f[i - 1][1][0];
			f[i][0][1] = f[i - 1][1][1];
			f[i][1][0] = min(f[i - 1][1][0], f[i - 1][0][0]) + 1;
			f[i][1][1] = min(f[i - 1][1][1], f[i - 1][0][1]) + 1;
		} else {
			f[i][0][0] = min(f[i - 1][0][0], f[i - 1][1][0]);
			f[i][0][1] = min(f[i - 1][0][1], f[i - 1][1][1]);
			f[i][1][0] = min(f[i - 1][1][0], f[i - 1][0][0]) + 1;
			f[i][1][1] = min(f[i - 1][1][1], f[i - 1][0][1]) + 1;
		}
		//Wtn(f[i][0][0]), Wtn(f[i][0][1]), Wtn(f[i][1][0]), Wtn(f[i][1][1]);
	}
	if(S[1] == S[n]) {
		ans = min(f[n][1][1], min(f[n][0][1], f[n][1][0])) * K;
	} else {
		ans = min(min(f[n][1][1], f[n][0][1]), min(f[n][1][0], f[n][0][0])) * K;
	}
	Wtn(ans);
	return 0;
}