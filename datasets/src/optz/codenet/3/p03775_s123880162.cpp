#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<ll> divisor(ll n) {
	vector<ll> div;
	for(ll i=1;i*i<n;++i) {
		if (n % i == 0) {
			div.push_back(i);
			if (i * i != n)	div.push_back(n/i);
		}
	}
	sort(div.begin(), div.end());
	return div;
}

ll cnt_digit(ll n) {
	return to_string(n).length();
}

int main() {
	ll n;
	cin >> n;
	vector<ll> div = divisor(n);
	ll size_div = div.size();
	ll ans = cnt_digit(n);
	rep(i,size_div) {
		ans = min(ans, max(cnt_digit(div[i]), cnt_digit(div[size_div-1-i])));
	}
	cout << ans << endl;
	return 0;
}
