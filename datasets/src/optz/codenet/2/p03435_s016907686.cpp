#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
 
#define BIG 2000000007
#define VERYBIG 200000000000007LL
 
#define MOD 1000000007
typedef uint64_t ull;
typedef  int64_t sll;
 
#define N_MAX 300000
#define M_MAX 200000
 
#ifdef __cplusplus
#include <queue>
#include <stack>
// #include <tuple>
#include <set>
 
// using namespace std; // HELL
using std::queue;
using std::priority_queue;
using std::stack;
// using std::tuple;
using std::set;
using std::vector;
using std::greater;
using std::pair;
 
typedef priority_queue<ull, vector<ull>, greater<ull> > upque123;
typedef priority_queue<ull, vector<ull> > upque321;
typedef priority_queue<sll, vector<sll>, greater<sll> > spque123;
typedef priority_queue<sll, vector<sll> > spque321;
 
#endif
 
typedef struct {
	int32_t a;
	int32_t b;
} hw;
 
typedef struct {
	sll a;
	sll b;
} hwll;
 
typedef struct {
	hwll a;
	hwll b;
} linell;
 
 
typedef struct {
	ull s;
	ull t;
	int32_t c;
} struct_a;
 
typedef struct {
	int32_t from;
	int32_t to;
	sll cost;
} struct_b;
 
 
 
const hw vector8[8] = {
	{-1, -1},
	{-1,  0},
	{-1, +1},
	{ 0, -1},
	{ 0, +1},
	{+1, -1},
	{+1,  0},
	{+1, +1}
};
 
ull n, m;
ull h, w;
ull k;
ull q;
ull vua, vub, vuc, vud, vue, vuf;
sll vsa, vsb, vsc, vsd, vse, vsf;
long double vra, vrb, vrc;
double vda, vdb, vdc;
size_t slen;
size_t tlen;
char ch, dh;
 
void swap_adj (ull *a, ull *b) {
	if (*a != *b) {
		ull tmp = *b;
		*b = *a;
		*a = tmp;
	}
	return;
}
 
int32_t digits (ull x) {
	int32_t i = 1;
	while (x >= 10) {
		x /= 10;
		i++;
	}
	return i;
}
 
ull umin (ull x, ull y) {
	return (x < y) ? x : y;
}
 
ull umax (ull x, ull y) {
	return (x > y) ? x : y;
}
 
sll smin (sll x, sll y) {
	return (x < y) ? x : y;
}
 
sll smax (sll x, sll y) {
	return (x > y) ? x : y;
}
 
ull gcd (ull x, ull y) {
	if (x < y) {
		return gcd(y, x);
	} else if (y == 0) {
		return x;
	} else {
		return gcd(y, x % y);
	}
}
 
ull bitpow (ull a, ull x, ull modulo) {
	ull result = 1;
	while (x) {
		if (x & 1) {
			result *= a;
			result %= modulo;
		}
		x /= 2;
		a = (a * a) % modulo;
	}
	return result;
}
 
ull divide (ull a, ull b, ull modulo) {
	return (a * bitpow(b, modulo - 2, modulo)) % modulo;
}
 
ull ullabs (ull a, ull b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}
 
sll sllabs (sll a, sll b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}
 
sll nibutanlobo (bool (*func)(sll arg), sll ok, sll ng) {
	while (sllabs(ok, ng) > 1) {
		sll med = (ok + ng) / 2;
		if (func(med)) {
			ok = med;
		} else {
			ng = med;
		}
 
		// printf("debug: [%lld %lld)\n", ok, ng);
	}
 
	if (!func(ok)) return ok * 2 - ng;
	return ok;
}
 
void printUquotient (ull left, ull right) {
	const int32_t digits = 20;
 
	printf("%llu.", left / right);
	left %= right;
	for (int32_t i = 0; i < digits; i++) {
		left *= 10;
		printf("%1d", left / right);
		left %= right;
	}
	puts("");
 
	return;
}
 
void printSquotient (sll left, sll right) {
	if (left * right < 0) putchar('-');
	printUquotient(sllabs(left, 0), sllabs(right, 0));
 
	return;
}
 
int bitcount (ull n) {
	int result = 0;
	while (n) {
		if (n & 1) result++;
		n /= 2;
	}
	return result;
}
 
#ifdef __cplusplus
 
typedef struct {
	int32_t to;
	sll cost;
} edge;
typedef pair<sll, int32_t> P;
 
std::vector<edge> g[N_MAX];
void dijk_init (ull n, struct_b arr[]) {
	edge x;
	for (int32_t i = 0; i < n; i++) {
		x.to = arr[i].to;
		x.cost = arr[i].cost;
		g[arr[i].from].push_back(x);
	}
}
 
bool dijkstra (int s, sll distance[]) {
	priority_queue<P, std::vector<P>, greater<P> > que; // (最短距離, 頂点番号)
	que.push(P(distance[s], s));
 
	bool ischanged = false;
	while (!que.empty()) {
		P p = que.top();
		que.pop();
 
		sll v = p.second;
		if (distance[v] < p.first) continue;
 
		int32_t maxsize = g[v].size();
		for (int32_t i = 0; i < maxsize; i++) {
			edge e = g[v][i];
			if (distance[e.to] > distance[v] + e.cost) {
				distance[e.to] = distance[v] + e.cost;
				ischanged = true;
				que.push(P(distance[e.to], e.to));
			}
		}
	}
 
	return ischanged;
}
 
#endif
 
sll dist[N_MAX];
struct_b path[M_MAX * 2];
 
// ull a[N_MAX];
// ull a[M_MAX];
sll a[N_MAX];
// ull a[N_MAX][N_MAX];
// ull a[M_MAX][M_MAX];
// sll a[N_MAX][N_MAX];
// ull b[N_MAX];
// ull b[M_MAX];
sll b[N_MAX];
// ull c[N_MAX];
sll c[M_MAX];
// char c[N_MAX];
char s[N_MAX + 1];
// char s[N_MAX + 1][N_MAX + 1];
// char s[N_MAX + 1][M_MAX + 1];
char t[N_MAX + 1];
 
// ull alphabets[26];
// ull blphabets[26];
// char alphabets[26];
 
// ull dp[N_MAX + 1];
// sll dp[N_MAX + 1];
// ull dp[N_MAX + 1][N_MAX + 1];
// sll dp[N_MAX + 1][N_MAX + 1];
// bool dp[N_MAX + 1];
// bool dp[N_MAX + 1][N_MAX + 1];
hwll arr[N_MAX];
// hwll arr[M_MAX];
// hwll brr[M_MAX];
 
ull dp[N_MAX + 1][26];
 
double distance (sll x1, sll y1, sll x2, sll y2) {
	double xdist2, ydist2, origindist, dist;
 
	xdist2 = (x1 - x2) * (x1 - x2);
	ydist2 = (y1 - y2) * (y1 - y2);
	return sqrt(xdist2 + ydist2);
}
 
int32_t pullcomp (const void *left, const void *right) {
	ull l = *(ull*)left;
	ull r = *(ull*)right;
	if (l < r) {
		return -1;
	}
	if (l > r) {
		return +1;
	}
	return 0;
}
 
int32_t phwllABcomp (const void *left, const void *right) {
	hwll l = *(hwll*)left;
	hwll r = *(hwll*)right;
	if (l.a < r.a) {
		return -1;
	}
	if (l.a > r.a) {
		return +1;
	}
	if (l.b < r.b) {
		return -1;
	}
	if (l.b > r.b) {
		return +1;
	}
	return 0;
}
 
ull mergeteq (sll array[], ull n) {
	if (n == 1) return 0;
 
	ull left = n / 2;
	ull right = n - left;
 
	ull result = mergeteq(array, left) + mergeteq(array + left, right);
 
	sll tmparr[n];
	sll i = 0, j = 0;
	while (i < left || j < right) {
		if (i == left) {
			tmparr[i + j] = array[left + j];
			j++;
			continue;
		}
		if (j == right) {
			tmparr[i + j] = array[i];
			i++;
			continue;
		}
 
 
		if (array[i] > array[left + j]) {
			result += (left - i);
 
			tmparr[i + j] = array[left + j];
			j++;
		} else {
			tmparr[i + j] = array[i];
			i++;
		}
	}
 
	for (i = 0; i < n; i++) {
		array[i] = tmparr[i];
	}
 
	return result;
}
 
ull solve () {
	sll i, j, ki;
	// ull result = 0;
	sll result = 0;
	// double result = 0;
	ull maybe = 0;
	// sll maybe = 0;
	ull sum = 0;
	// sll sum = 0;
	ull item;
	ull *dpcell;
 
	sll x[3][3];
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%lld", &x[i][j]);
		}
	}
 
	sll diffa12 = x[1][0] - x[0][0];
	sll diffa23 = x[2][0] - x[1][0];
 
	sll diffb12 = x[0][1] - x[0][0];
	sll diffb23 = x[0][2] - x[0][1];
 
	if (x[1][1] != x[0][0] + diffb12 + diffa12) goto fail;
	if (x[1][2] != x[0][1] + diffb23 + diffa12) goto fail;
	if (x[2][1] != x[1][0] + diffb12 + diffa23) goto fail;
	if (x[2][2] != x[1][1] + diffb23 + diffa23) goto fail;
	goto success;
 
	printf("%llu\n", result);
	// printf("%.12lf\n", (double)result);
	// puts(s);
 
	return 0;
 
	success:
	// puts("YES");
	puts("Yes");
	// printf("%llu\n", result);
	// puts("0");
	// puts("CONTINUE");
	return 0;
 
	fail:
	// puts("NO");
	puts("No");
	// puts("0");
	// puts("-1");
	// puts("-1 -1 -1");
	// puts("Impossible");
	return 1;
}
 
int32_t main (void) {
	int32_t i, j;
	int32_t x, y;
 
	solve();
	return 0;
}