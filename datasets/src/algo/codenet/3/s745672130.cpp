#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[114514], b[114514], c[114514];
	long long d[114514];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(b, b + n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	sort(c, c + n);
	d[0] = 0;
	long long x = 0;
	for (int i = 0, j = 0; j < n;) {
		if (i == n || a[i] >= b[j])
			d[j + 1] = x + d[j], j++;
		else
			i++, x++;
	}
	x = 0;
	for (int i = 0, j = 0; j < n;) {
		if (i == n || b[i] >= c[j])
			x += d[i], j++;
		else
			i++;
	}
	cout << x << endl;
	return 0;
}
