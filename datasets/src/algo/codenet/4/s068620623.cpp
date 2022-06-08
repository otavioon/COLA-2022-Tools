#include <bits/stdc++.h>
#define pb push_back

typedef long long int ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	set<ll> se;
	ll n, k;
	cin >> n >> k;
	for (ll i = 0; i < k; i++) {
		ll x;
		cin >> x;
		se.insert(x);
	}
	ll tmp = n;
	while (true) {
		bool ya = true;
		ll tmp2 = tmp;
		while (tmp2) {
			if (se.count(tmp2%10)) {
				ya = false;
			}
			tmp2 /= 10;
		}
		if (ya) {
			cout << tmp;
			return 0;
		}
		tmp++;
	}
	
	return 0;
}
