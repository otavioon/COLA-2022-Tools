#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>

using namespace std;
typedef long long ll;
#define rep(i,s,n)for(ll i = s;i<n;i++)
#define repe(i,s,n)for(ll i = s;i<=n;i++)
static const ll maxLL = (ll)1 << 62;

ll a[100001] = {};
ll b[100001] = {};
ll c[100001] = {};
ll N;

ll upper_bs(ll b) {
	ll lb = -1;
	ll ub = N;
	ll m;
	while (ub - lb != 1) {
		m = (lb + ub) / 2;
		if (c[m] > b) {
			ub = m;
		}
		else {
			lb = m;
		}
	}
	return lb;
}
ll lower_bs(ll b) {
	ll lb = -1;
	ll ub = N;
	ll m;
	while (ub - lb != 1) {
		m = (lb + ub) / 2;
		if (a[m] >= b) {
			ub = m;
		}
		else {
			lb = m;
		}
	}
	return lb;
}

int main() {
	cin >> N;
	rep(i, 0, N)cin >> a[i];
	rep(i, 0, N)cin >> b[i];
	rep(i, 0, N)cin >> c[i];
	sort(a, a + N);
	sort(b, b + N);
	sort(c, c + N);

	ll cnt = 0;
	rep(i, 0, N) {
		ll A = lower_bs(b[i]) + 1;
		ll C = N - (upper_bs(b[i]) + 1);
		cnt += A * C;
	}
	cout << cnt << endl;
	return 0;
}