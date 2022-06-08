#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int a[100005], b[100005], c[100005];

int checka(int p)
{
	int l = 0, r = n;
	while(l <= r) {
		int mid  = (l + r) / 2;
		if(a[mid] >= p) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return r;
}

int checkc(int p)
{
	int l = 0, u = n;
	while(l <= u) {
		int mid  = (l + u) / 2;
		if(c[mid] <= p) {
			l = mid + 1;
		}
		else {
			u = mid - 1;
		}
	}
	return l;
}

int main()
{
	while(~scanf("%d", &n))
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		long long sum = 0;
		a[0] = b[0] = c[0] = -1000000;
		a[n + 1] = b[n + 1] = c[n + 1] = 1000000000;
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n);
		sort(c + 1, c + 1 + n);
		for(int i = 1; i <= n; i++)
		{
			long long ans = 1;
			int ca = checka(b[i]);
			int cc = checkc(b[i]);
			if(ca == 0) ca = 1;
			if(cc == 0) cc = 1;
			sum = sum + ca * (n - cc + 1);
		}
		printf("%lld\n", sum);
	}
	return 0;
}