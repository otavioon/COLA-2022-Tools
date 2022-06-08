#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<functional>
#include<map>
using namespace std;
int main()
{
	int a[100005] = { 0 }, b[100005] = { 0 }, c[100005] = { 0 };
	int i, j, k,n,sum=0;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	for (i = 0; i < n; i++)
		cin >> b[i];
	sort(b, b+n);
	for (i = 0; i < n; i++)
		cin >> c[i];
	sort(c, c+n);
	for (i = 0; i < n; i++)
	{
		j = n - 1;
		while (b[j] > a[i])
		{
			k = n - 1;
			while (c[k] > b[j])
			{
				sum++; k--;
			}
			j--;
		}
	}
	cout << sum << endl;
	return 0;
}



/*int *b1 = upper_bound(b, b + n, a[i]);
		for (int *i1 = b1; i1 <= b + n; i1 ++)
		{
			int *c1 = upper_bound(c, c + n, b[(i1-b)/4]);
			sum += (c1 - c)/4;
		}*/