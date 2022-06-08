#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, a[200500];

bool check(ll x) {
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += a[i] / x - (a[i] % x == 0);
	}
	return cnt <= k;
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll l = 0, r = 1e9;
	while (r - l > 1) {
		ll mid = l + (r - l) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	cout << r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}