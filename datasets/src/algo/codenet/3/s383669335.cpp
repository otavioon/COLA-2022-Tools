#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

static const int N = 1e5 + 10;
int n;
int a[N], b[N], c[N], cnt1[N], cnt2[N];

int main ()
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &b[i]);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &c[i]);
	sort (a + 1, a + n + 1);
	sort (b + 1, b + n + 1);
	sort (c + 1, c + n + 1);
	int k = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (; c[k] <= b[i] && k <= n ;)
			++k;
		cnt1[i] = n - k + 1;
	}
	k = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (; a[k] < b[i] && k <= n ;)
			++k;
		cnt2[i] = k - 1;
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += cnt1[i] * cnt2[i];
	printf ("%lld", ans);
}