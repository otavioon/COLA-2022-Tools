#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int32_t N = 3;
	int32_t _MAX = 100;

	vector<vector<int32_t>> c;
	c.resize(N);
	for (int32_t row = 0; row < N; row++) {
		c[row].resize(N);
		for (int32_t col = 0; col < N; col++) {
			cin >> c[row][col];
		}
	}

	vector<int32_t> a(3), b(3);
	for (a[0] = 0; a[0] <= _MAX; a[0]++) {
		for (a[1] = 0; a[1] <= _MAX; a[1]++) {
			for (a[2] = 0; a[2] <= _MAX; a[2]++) {
				bool found = true;
				for (int32_t col = 0; col < N; col++) {
					b[col] = c[0][col] - a[0];
					if (b[col] < 0 || b[col] != c[1][col] - a[1] || b[col] != c[2][col] - a[2]) {
						found = false;
						break;
					}
				}
				if (found) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}

	cout << "No" << endl;

	return 0;
}