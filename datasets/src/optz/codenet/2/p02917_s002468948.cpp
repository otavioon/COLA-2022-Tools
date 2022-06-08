#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int b[120], a[120], n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> b[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			a[i] = b[0];
		}
		else if (i == n - 1) {
			a[i] = b[n - 2];
		}
		else {
			a[i] = min(b[i - 1], b[i]);
		}
		ans += a[i];
	}
	cout << ans << endl;
	return 0;
}