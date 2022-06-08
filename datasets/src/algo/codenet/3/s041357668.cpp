#include <bits/stdc++.h>
using namespace std;

const int nm = 1e5;
int n, a[nm], b[nm], c[nm];
long long d[nm];

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
		while (j < n && a[j] < b[i])
			j++;
		d[i] = j + (i > 0 ? d[i - 1] : 0);
	}
	long long rv = 0;
	for (int i = 0, j = 0; i < n; i++) {
		while (j < n && b[j] < c[i])
			j++;
		rv += d[j - 1];
	}
	cout << rv << endl;
}
