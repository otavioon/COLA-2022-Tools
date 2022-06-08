#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n], b[n], c[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	sort (a, a + n);
	sort (b, b + n);
	sort (c, c + n);

	int a_i = 0, b_i = 0, c_i = 0;
	long long altar_count = 0;
	for (; a_i < n; ++a_i) {
		while (b[b_i] <= a[a_i]) {
			++b_i;
		}
		int temp_b = b_i;
		while (c[c_i] <= b[b_i]) {
			++c_i;
		}
		int temp_c = c_i;
		for (; b_i < n; ++b_i) {
			while (c[c_i] <= b[b_i]) {
				++c_i;
			}
			altar_count += (n - c_i);
		}

		b_i = temp_b;
		c_i = temp_c;
	}
	cout << altar_count;
	return 0;
}