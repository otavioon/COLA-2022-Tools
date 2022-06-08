#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;

	multiset<int> S;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		S.insert(x);
	}
	
	int ans = 0;
	while (S.size()) {
		int t = *S.rbegin();
		S.erase(--S.end());
		
		int p = 1;
		while (p <= t) p *= 2;
		
		if (S.find(p - t) != S.end()) {
			ans++;
			S.erase(S.find(p - t));
		}
	}
	cout << ans << "\n";
	return 0;
}
