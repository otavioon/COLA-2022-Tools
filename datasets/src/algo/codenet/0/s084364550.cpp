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
	if (l > n) printf("%lld\n", 1ll * n * K / 2);
	else
	{
		int r = n;
		while (s[r] == s[1]) --r;
		ll ans = 0;
		for (int i = 1, j = 1; i <= n; i = j)
		{
			while (j <= n && s[j] == s[i]) ++j;
			ans += 1ll * (j - i) / 2 * K;
		}
		int a = l - 1, b = n - r;
		ans -= 1ll * a / 2 * (K - 1);
		ans -= 1ll * b / 2 * (K - 1);
		ans += 1ll * (a + b) / 2 * (K - 1);
		printf("%lld\n", ans);
	}
	return 0;
}