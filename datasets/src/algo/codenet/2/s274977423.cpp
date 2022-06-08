#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = (int)1e9 + 7;
const int MaxN = (int)1e5 + 10;
const long long INF = (int)1e18;

int main() {
//	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	multiset <int> s;
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		s.insert(x);
	}
	int ans = 0;
	while (!s.empty()) {
		int x = *s.begin();
		s.erase(s.begin());
		for (int bit = 30; bit >= 0; --bit) {
			if (s.count((1 << bit) - x)) {
				s.erase(s.find((1 << bit) - x));
				++ans;
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
