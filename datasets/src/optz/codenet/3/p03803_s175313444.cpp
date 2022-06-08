// think twice code once
// Start:[]
// End  :[]
/*{{{*/
#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = (x), _ = (y); i <= _; ++ i)
#define per(i, x, y) for(int i = (x), _ = (y); i >= _; -- i)
#define dprintf(...) fprintf(stderr, __VA_ARGS__)
#define disp(x) cout << #x << " = " << x << "; "
#ifdef __linux__
#define getchar getchar_unlocked
#define LLFORMAT "%lld"
#else
#define LLFORMAT "%I64d"
#endif

typedef long long LL;

template <class T> bool chkmin(T& a, T b) { return a > b ? a = b, true : false; }
template <class T> bool chkmax(T& a, T b) { return a < b ? a = b, true : false; }

template <class T> void read(T& a) {
	char c = getchar(); T f = 1; a = 0;
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c = getchar()) a = a * 10 + c - '0';
	a *= f;
}
/*}}}*/

int a, b;

int main()
{
#ifdef Leeson
	freopen("tmp.in", "r", stdin);
	freopen("tmp.out", "w", stdout);
#endif

	read(a); read(b);
	if(a == 1) a = 14;
	if(b == 1) b = 14;
	if(a > b) puts("Alice");
	else if(a == b) puts("Draw");
	else puts("Bob");
	return 0;
}
