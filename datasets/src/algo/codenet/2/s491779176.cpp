#include <bits/stdc++.h>

using namespace std;

#define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define fst first
#define snd second
#define SZ(u) ((int) (u).size())
#define ALL(u) (u).begin(), (u).end()

inline void proc_status()
{
	ifstream t("/proc/self/status");
	cerr << string(istreambuf_iterator<char>(t), istreambuf_iterator<char>()) << endl;
}

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline T read()
{
	register T sum(0), fg(1);
	register char ch(getchar());
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') fg = -1;
	for(;  isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) + (ch ^ '0');
	return sum * fg;
}

typedef long long LL;
typedef pair<int, int> pii;

const int MAXN = (int) 2e5, MAX_LOG = 30;

// Template-Libs

// END

int n;

int a[MAXN + 5];

inline void input()
{
	n = read<int>();
	for(int i = 1; i <= n; ++i) a[i] = read<int>();
}

inline void solve()
{
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int p = MAX_LOG; p >= 0; --p)
	{
		int d = 1 << p;

		static int vis[MAXN + 5], b[MAXN + 5];
		for(int j = 1; j <= n; ++j) vis[j] = 0;

		for(int i = 1, j = n; i < j; --j)
		{
			while(i + 1 < j && a[i] + a[j] < d) ++i;
			if(a[i] + a[j] == d) vis[i] = vis[j] = 1, ++ans;
		}
		int m = 0;
		for(int i = 1; i <= n; ++i) if(!vis[i]) b[++m] = a[i];
		for(int i = 1; i <= m; ++i) a[i] = b[i];
		n = m;
	}
	printf("%d\n", ans);
}

int main()
{
	input();
	solve();

	return 0;
}

