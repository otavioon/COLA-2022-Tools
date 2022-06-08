#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}

const int mod = 1e9 + 7;
inline int mul(int x, int y) {return (ll)x * y % mod;}
inline int inc(int x, int y) {int t = x + y; return t >= mod ? t - mod : t;}
inline int qpow(int x, int y)
{
	int res = 1;
	for (; y; y >>= 1, x = (ll)x * x % mod)
		if (y & 1) res = (ll)res * x % mod;
	return res;
}

const int maxn = 2e5 + 10;
int n, a[maxn], p[35];
bool vis[maxn];
int main()
{
	n = read();
	for (int i = 1; i <= n; i ++)
		a[i] = read();
	sort (a + 1, a + 1 + n);
	for (int i = 0; i <= 30; i ++)
		p[i] = 1;
	int ans = 0;
	for (int i = n; i >= 1; i --)
		if (!vis[i])
		{
			vis[i] = 1;
			for (int j = 0; j <= 30; j ++)
			{
				if (p[j] >= i)
					continue;
				int now = 1 << j;
				while (p[j] < i && (vis[p[j]] || a[p[j]] < now - a[i]))
					++ p[j];
				if (p[j] >= i)
					continue;
				if (a[p[j]] == now - a[i])
				{
					vis[p[j]] = 1, ++ ans;
					break;
				}
			}
		}
	printf ("%d\n", ans);
	return 0;
}