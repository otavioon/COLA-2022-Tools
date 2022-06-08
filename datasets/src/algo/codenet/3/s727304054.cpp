#include <iostream>
#include <algorithm>

using namespace std;

long n;
long a[100005];
long b[100005];
long c[100005];
long long res;

long findlow(long n)
{
	long i, j, mid;

	i = 1; j = n;

	while (i <= j)
	{
		mid = (i + j) >> 1;
		if (a[mid] < n)
			i = mid + 1;
		else
			j = mid - 1;
	}

	return i;
}

long findup(long n)
{
	long i, j, mid;

	i = 1; j = n;

	while (i <= j)
	{
		mid = (i + j) >> 1;
		if (c[mid] > n)
			j = mid - 1;
		else
			i = mid + 1;
	}

	return j;
}

int main()
{
	long res1, res2;

	cin >> n;

	for (long i = 1; i <= n; ++i)
		cin >> a[i];

	for (long i = 1; i <= n; ++i)
		cin >> b[i];

	for (long i = 1; i <= n; ++i)
		cin >> c[i];

	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	sort(c + 1, c + n + 1);

	a[0] = c[0] = -100000005;
	a[n+1] = c[n+1] = 1000000005;

	for (long i = 1; i <= n; ++i)
	{
		res1 = findlow(b[i]);
		res2 = findup(b[i]);
		res += (res1 - 1) * (n - res2);
	}

	cout << res << endl;

	return 0;
}