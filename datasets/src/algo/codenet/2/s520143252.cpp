#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;


int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int n;	cin >> n;

	int ans = 0;

	multiset <ll> m;

	for (int i = 0; i < n; i++) {
		ll take;	cin >> take;
		m.insert(take);
	}

	while (!m.empty()) {
		auto x = *m.rbegin();
		m.erase(m.find(x));
		ll stepval = pow(2, logb(x) + 1);
		auto it = m.find(stepval - x);
		if (it == m.end())
			continue;

		m.erase(it);
		ans++;
	}

	cout << ans << endl;

	return 0;
}