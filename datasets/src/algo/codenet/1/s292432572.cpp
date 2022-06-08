#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int n, m;

	for (int i = 0; i < 3; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (!i) {
			n = abs(a - b);
			m = abs(b - c);
		}
		else {
			if ((n != abs(a - b)) || (m != abs(b - c))) {
				cout << "No" << endl;
				return 0;
			}
		}
	}

	cout << "Yes" << endl;
}