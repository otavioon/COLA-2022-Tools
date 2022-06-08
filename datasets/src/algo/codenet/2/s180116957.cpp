#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

typedef long long ll;
ll n, s, x;
multiset<ll> v;
int main()
{
	ll i, t;
	multiset<ll>::iterator it;
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf ("%lld", &t);
		v.insert(t);
	}
	while (!v.empty()) {
		x = *v.rbegin();
		v.erase(v.find(x));
		for (i = 1; i < x; i *= 2);
		it = v.find(i - x);
		if (it != v.end()) {
			s++;
			v.erase(it);
		}
	}
	cout << s;
    return 0;
}
