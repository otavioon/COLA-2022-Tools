#include <bits/stdc++.h>

using namespace std;

int a[222222], b[222222];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	sort(a, a + n);
	int c = 0;
	while (n--) {
		if (b[n]) continue;
		for (int i = 1; i < 31; i++) {
			if ((1 << i) <= a[n])
				continue;
			int j = lower_bound(a, a + n, (1 << i) - a[n]) - a;
			if (j >= n || a[j] != (1 << i) - a[n] || b[j])
				continue;
			c++;
			b[j] = 1;
			break;
		}
	}
	cout << c << endl;
	return 0;
}
