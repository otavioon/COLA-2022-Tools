#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	string s;
	Int K;
	cin >> s >> K;

	Int l = 0, r = s.size() - 1;
	while (l + 1 < s.size() && s[l] == s[l+1]) { ++l; }
	while (r - 1 >= 0 && s[r] == s[r-1]) { --r; }

	Int cnt = 0;
	for (int i = l + 1; i < r; ++i) {
		if (s[i] == s[i - 1]) {
			s[i] = '#';
			++cnt;
		}
	}
	Int ans = cnt * K;

	Int N = s.size();
	if (l < r) {
		l += 1;
		r = s.size() - r;
		ans += (l / 2 + r / 2);
		if (s[0] == s.back()) {
			ans += ((l + r) / 2) * (K - 1);
		} else {
			ans += (l / 2 + r / 2) * (K - 1);
		}
	} else {
		ans = (N * K / 2);
	}

	cout << ans << endl;

	return 0;
}
