#include<bits/stdc++.h>
typedef long long ll;
inline ll read() {ll x = 0;char ch = getchar(), w = 1;while(ch < '0' || ch > '9') {
if(ch == '-') w = -1;ch = getchar();}while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0';
ch = getchar();}return x * w;}
void write(ll x) {if(x < 0) putchar('-'), x = -x;if(x > 9) write(x / 10);putchar(x % 10 + '0');}
inline void writeln(ll x) {write(x);puts("");}
void setIO() {
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
using namespace std;
const int N = 3e5;

int n, Q;
struct Edge {
	int u, v, nxt;
}e[N * 2];
int head[N], en;
void addl(int x, int y) {
	e[++en].u = x, e[en].v = y, e[en].nxt = head[x], head[x] = en;
}
int L[N], R[N], tot;
void dfs(int x,  int F) {
	L[x] = ++tot;
//	printf("x=%d\n", x);
	for(int i = head[x]; i;i = e[i].nxt) {
		int y = e[i].v;
		if(y == F) continue;
		dfs(y, x);
	}
	R[x] = tot;
}
ll c[N];
void add(int x, int v) {
	for(; x <= n; x += x & -x)
		c[x] += v;
}
ll query(int x) {
	ll res = 0;
	for(; x; x -= x & -x)
		res += c[x];
	return res;
}
int main() {
	n = read(), Q = read();
	for(int i = 1; i < n; ++i) {
		int x = read(), y = read();
		addl(x, y);
		addl(y, x);
	}
	dfs(1, 0);
	for(int i = 1; i <= Q; ++i) {
		int x = read(), y = read();
		add(L[x], y);
		add(R[x] + 1, -y);
	}
	for(int i = 1; i <= n; ++i)
		printf("%lld ", query(L[i]));
	puts("");
	return 0;
}