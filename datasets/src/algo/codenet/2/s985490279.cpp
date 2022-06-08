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
			int x = (1 << i) - a[n];
			if (x <= 0) continue;
			int j = lower_bound(a, a + n, x) - a;
			if (j >= n || a[j] != x || b[j])
				continue;
			c++;
			int k = upper_bound(a, a + n, x) - a;
			while (b[--k]);
			b[k] = 1;
			break;
		}
	}
	cout << c << endl;
	return 0;
}
