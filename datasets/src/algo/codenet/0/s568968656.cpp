#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
 
const int MOD = 1e9 + 7;

class Task {
public:

	void solve() {
		string s;
		cin >> s;
		int k;
		cin >> k;
		
		int n = s.length();
		
		bool same = true;
		for (int i = 0; i < n; ++i) {
			if (s[i] != s[0])
				same = false;
		}
		if (same) {
			cout << (LL) n * k / 2;
			return;
		}
		
		int x = 0;
		while (x < n && s[x] == s[0]) ++x;
		int y = n - 1;
		while (y >= 0 && s[y] == s[n - 1]) --y;
		
		LL result = 0;
		
		for (int i = x; i <= y; ) {
			int j = i + 1;
			while (j <= y && s[j] == s[i]) ++j;
			result += (j - i) / 2;
			i = j;
		}
		
		result *= k;
		
		y = n - y - 1;
		
		result += x / 2 + y / 2;
		
		if (s[0] != s[n - 1]) {
			result += (LL) (x / 2 + y / 2) * (k - 1);
		} else {
			result += (LL) (x + y) / 2 * (k - 1);
		}
		
		cout << result << '\n';
	}
};
 
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
 
	Task *task = new Task();
	task->solve();
	return 0;
}
