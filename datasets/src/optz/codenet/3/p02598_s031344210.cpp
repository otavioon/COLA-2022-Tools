#include <bits/stdc++.h>
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define FSP(x) fixed << setprecision(x)
using namespace std;
using ll = long long;
constexpr ll INF = LLONG_MAX;
const long double PI = acosl(-1);
void Yes() {cout << "Yes\n";}
void No() {cout << "No\n";}
void YES() {cout << "YES\n";}
void NO() {cout << "NO\n";}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//constexpr ll P = 1e9 + 7;
	//constexpr ll P = 998244353;

	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	sort(ALL(a));
	if (k == 0) {
		cout << a[n - 1] << endl;
		return 0;
	}
	if (a[n - 1] == 1) {
		cout << 1 << endl;
		return 0;
	}

	ll l = 1, r = 1e9;
	auto is_ok = [&] (ll x) {
		ll cnt = 0;
		for (auto i : a) {
			cnt += (i + x - 1) / x - 1;
		}
		return (cnt <= k);
	};
	while (l + 1 < r) {
		ll mid = (l + r) / 2;
		if (is_ok(mid)) r = mid;
		else l = mid;
	}
	cout << r << endl;
}