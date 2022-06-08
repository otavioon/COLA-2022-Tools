#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define ppb pop_back()
#define fi first
#define se second
#define pi pair<int, int>
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define REP(i, a, n) for(int i = a; i < n; i++)
#define Y "Yes"
#define N "No"
using namespace std;

ll n, k, sum, x[200001], mi, ma;

bool p(ll a) {
	ll cnt = 0;
	REP(i, 0, n) {
		if (x[i] > a) {
			ll y = x[i] - a;
			cnt += (y - 1) / a + 1;
		}
	}
	return cnt <= k;
}

ll search(ll a, ll b) {
	if (b - a <= 1) {
		if (a > b) swap(a, b);
		if (p(a)) return a;
		return a + 1;
	}
	ll m = (a + b) / 2;
	if (p(m)) return search(a, m);
	return search(m, b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//freopen("in.txt", "r", stdin);

	cin >> n >> k >> x[0];
	mi = x[0];
	ma = x[0];
	REP(i, 1, n) {
		cin >> x[i];
		mi = min(mi, x[i]);
		ma = max(ma, x[i]);
	}
	if (k == 0) cout << ma;
	else cout << search(mi / k, ma);
}
