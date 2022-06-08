#include <cstdio>
#include <cstring>

#define maxn 1010
typedef long long ll;
char s[maxn];
bool vis[maxn];
int main()
{
	scanf("%s", s + 1);
	int K, n; scanf("%d", &K); n = strlen(s + 1);
	int l = 1;
	while (l <= n && s[l] == s[1]) ++l;
	if (l > n) printf("%lld\n", 1ll * n / 2 * K);
	else
	{
		int r = n;
		while (s[r] == s[1]) --r;
		memcpy(s + n + 1, s + 1, n);
		ll ans = 0;
		for (int i = l, j = l; i <= n; i = j)
		{
			while (s[j] == s[i]) ++j;
			ans += 1ll * (j - i) / 2 * K;
			// printf("%d %d\n", i, j);
			if (j > n + 1) ans -= (j - i) / 2;
		} 
		ans += (l - 1) / 2;
		ans += (n - r) / 2;
		printf("%lld\n", ans);
	}
	return 0;
}