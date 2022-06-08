#include <iostream>
#include <algorithm>

using namespace std;

long n;
long a[100005];
long b[100005];
long c[100005];
long long res;

int main()
{
	long long i, k;

	cin >> n;

	for (long i = 0; i < n; ++i)
		cin >> a[i];

	for (long i = 0; i < n; ++i)
		cin >> b[i];

	for (long i = 0; i < n; ++i)
		cin >> c[i];

	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);

	i = k = 0;
	for (long j = 0; j < n; ++j)
	{
		while (a[i] < b[j] && i < n) ++i;
		while (c[k] <= b[j] && k < n) ++k;
		if (b[j] > c[n-1]) break;
		res += i * (n - k);
	}

	cout << res << endl;

	return 0;
}