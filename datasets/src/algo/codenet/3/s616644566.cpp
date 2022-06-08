#include <bits/stdc++.h>
using namespace std;

const int nm = 1e5;
int n, a[nm], b[nm], c[nm], d[nm];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	sort(a, a + n), sort(b, b + n), sort(c, c + n);
	for (int i = 0, j = 0; i < n; i++) {
		while (a[j] < b[i] && j < n)
			j++;
		d[i] = j + (i > 0 ? d[i - 1] : 0);
	}
	int rv = 0;
	for (int i = 0, j = 0; i < n; i++) {
		while (b[j] < c[i] && j < n)
			j++;
		rv += d[j - 1];
	}
	cout << rv << endl;
}
