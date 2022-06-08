#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
const int maxn = 10005;
int n;
int a[maxn], b[maxn], c[maxn];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	sort(a, a + n); sort(b, b + n); sort(c, c + n);
	long long sum = 0;
	long long temp1=0, temp2 = 0;
	for (int i = 0; i < n; i++)
	{
		while (a[temp1] < b[i] && temp1 < n)
			temp1++;
		while (c[temp2] <= b[i] && temp2 < n)
			temp2++;
		sum += temp1*(n - temp2);
	}
	cout << sum << endl;
	return 0;
}