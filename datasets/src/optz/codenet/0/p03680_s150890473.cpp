#include "bits/stdc++.h"
using namespace std;

#define print(n) cout  << n << "\n"

int main() {
	int n;
	cin >> n;
	vector<int>a;
	a.push_back(-1);
	for (int i = 0; i< n; i++) {
		int aa;
		cin >> aa;
		a.push_back(aa);
	}
	int nowButton = 1;
	int nowStep = 0;
	while (nowButton != 2 && nowStep <= n) {
		nowStep++;
		nowButton = a[nowButton];
	}
	if (nowStep > n) {
		nowStep = -1;
	}
	print(nowStep);

	return 0;
}