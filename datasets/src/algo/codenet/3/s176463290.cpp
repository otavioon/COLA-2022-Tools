#include <iostream>
#include <algorithm>

using namespace std;

long long data1[100000] = {};
long long data2[100000] = {};
long long data3[100000] = {};

int main()
{
	long long n, cnt = 0;
	cin >> n;
	for (long long i = 0; i < n; i++)
	{
		cin >> data1[i];
	}
	for (long long i = 0; i < n; i++)
	{
		cin >> data2[i];
	}
	for (long long i = 0; i < n; i++)
	{
		cin >> data3[i];
	}
	//
	sort(data1, data1 + n);
	sort(data2, data2 + n);
	sort(data3, data3 + n);
	//
	for (long long i = 0; i < n; i++)
	{
		long long min = 0, max = n - 1;
		long long x = -1;
		long long min2 = 0, max2 = n - 1;
		long long x2 = -1;
		long long ans, ans2;
		while (min <= max)
		{
			x = ((max + min) / 2);
			if (data2[i] > data1[x])
			{
				min = x + 1;
			}
			else
			{
				max = x - 1;
			}
		}
		ans = min;
		while (min2 <= max2)
		{
			x2 = ((max2 - min2) / 2) + min2;
			if (data2[i] >= data3[x2])
			{
				min2 = x2 + 1;
			}
			else
			{
				max2 = x2 - 1;
			}
		}
		ans2 = min2;
		cnt += ans * (n - ans2);
	}
	cout << cnt;
	return 0;
}