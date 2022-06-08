#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair
#define mt make_tuple


signed main() {
#ifdef LC
	assert(freopen("input.txt", "r", stdin));
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	multiset<int> s;
	while (n--) {
		int x;
		cin >> x;
		s.insert(x);
	}
	int ans = 0;
	while (s.size()) {
		int x = *s.rbegin();
		s.erase(s.find(x));
		for (int t = 62; t >= 1; --t) {
			int y = (1LL << t) - x;
			if (s.find(y) != s.end()) {
				s.erase(s.find(y));
				++ans;
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
