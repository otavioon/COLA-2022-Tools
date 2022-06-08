#include <algorithm>
#include <stdio.h>
#include <deque>
#include <set>
using namespace std;
using ll = long long;

ll next(ll x) {
	for (ll i = 1; true; i *= 2)
		if (x < i)
			return i;
}
int main() {
	ll n, t, p;
	scanf("%lld", &n);
	set<ll> a;
	for (int i = 0; i < n; i++)
		scanf("%lld", &t), a.emplace(t);

	ll c = 0;
	while (2 <= a.size()) {
		t = *(--a.end());
		p = next(t) - t;
		a.erase(--a.end());

		auto lower = a.lower_bound(p);
		if (lower != a.end() && *lower == p)
			c++, a.erase(lower);
	}
	printf("%lld\n", c);
}