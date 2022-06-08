#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, tmp;
	cin >> n;
	
	long long ans = 0;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			for (int k = j+1; k < n; ++k) {
				ans += (v[i] + v[j] + v[k] - 2 * max({v[i], v[j], v[k]}) > 0);
			}
		}
	}
	
	cout << ans << "\n";
	
	/*
	vector<long long> v(1005, 0);
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		++v[tmp];
	}
	
	long long ans = 0;
	for (long long i = 1; i <= 1000; ++i) {
		ans += v[i] * (v[i] - 1) * (v[i] - 2) / 6;
		for (long long j = i+1; j <= 1000; ++j) {
			if (i + i > j) ans += v[i] * (v[i] - 1) * v[j] / 2;
			ans += v[i] * v[j] * (v[j] - 1) / 2;
			for (long long k = j+1; k < j+i and k <= 1000; ++k) {
				ans += v[i] * v[j] * v[k];
			}
		}
	}
	
	cout << ans << "\n";
	*/
	
	return 0;
}