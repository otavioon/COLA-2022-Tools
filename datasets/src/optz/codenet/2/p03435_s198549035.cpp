#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <functional>
#include <unordered_map> 
#include <map> 
#include <numeric>
#include <limits>
#include <utility>
#include <queue>
#include <random>
#include <bitset>
using namespace std;
typedef long long LL;

int main(void) {
	LL i, j, k, n, ans;
	vector<int> a(3);
	vector<int> b(3);
	vector<vector<int>> c(3, vector<int>(3));

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cin >> c[i][j];
		}
	}
	/*
	for (i = 0; i <= min(c[0][0], min(c[0][1], c[0][2])); i++) {
		for (j = 0; j <= min(c[1][0], min(c[1][1], c[1][2])); j++) {
			for (k = 0; k <= min(c[2][0], min(c[2][1], c[2][2])); k++) {
				if ((c[0][0] - i == c[1][0] - j) && (c[1][0] - j == c[2][0] - k)) {
				} else {
					break;
				}
				if ((c[0][1] - i == c[1][1] - j) && (c[1][1] - j == c[2][1] - k)) {
				} else {
					break;
				}
				if ((c[0][2] - i == c[1][2] - j) && (c[1][2] - j == c[2][2] - k)) {
				} else {
					break;
				}
				cout << "Yes" << endl;
				return 0;
			}
		}
	}*/

	cout << "No" << endl;


	return 0;
}