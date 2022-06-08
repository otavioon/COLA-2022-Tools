#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n; cin >> n;
	int a[n];
	int b[n];
	int c[n];
	int ans = 0;
	for (int j = 0; j < n; j++) cin >> a[j];
	for (int j = 0; j < n; j++) cin >> b[j];
	for (int j = 0; j < n; j++) cin >> c[j];
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			if (a[x] >= b[y]) break;
			for (int z = 0; z < n; z++)
			{
				if (a[x] < b[y] && b[y] < c[z]) ans++;
				else
				{
					break;
				}
			}
		}
	}
	cout << ans << endl;
}