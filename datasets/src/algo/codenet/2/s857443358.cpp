#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	multiset<int> st;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		st.insert(x);
	}
	int cnt = 0;
	while (st.size() >= 2) {
		int x = *st.begin();
		st.erase(st.begin());
		for (int sum = 1 << 30; sum >= x + 1; sum >>= 1) {
			int y = sum - x;
			if (st.count(y)) {
				cnt++;
				st.erase(st.find(y));
				break;
			}
		}
	}
	cout << cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	solve();
}
