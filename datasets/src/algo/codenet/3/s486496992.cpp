#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
typedef long long ll;

int n;
ll a[110000];
ll b[110000];
ll c[110000];

bool isOK(ll index, ll key, ll a[110000]) {
	if (a[index] > key) return true;
	else return false;
}

ll nibutan(ll k, ll a[110000]) {
	ll left = -1;
	ll right = n;
	while (right - left > 1) {
		ll mid = left + (right - left) / 2;
		if (isOK(mid, k, a)) right = mid;
		else left = mid;
	}
	return right;
}

int main() {
	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(i, n) cin >> c[i];
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	ll ans = 0;
	for (int i=0;i<n;i++) {
		ll Q = nibutan(a[i], b);
		if (Q == n) continue;
		for (int j = Q; j < n; j++) {
			ll T = nibutan(b[j], c);
			ans += n - T;
		}
	}
	cout << ans << endl;
	return 0;
}
