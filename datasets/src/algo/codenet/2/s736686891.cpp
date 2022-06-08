#include <bits/stdc++.h>
using namespace std;

//https://atcoder.jp/contests/agc029/tasks/agc029_b

int n, ans = 0;
multiset<int> s;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		s.insert(a);
	}
	while (!s.empty()) {
		auto a = s.end();
		--a;
		s.erase(a);
		int b = 1;
		while (b < *a)
			b <<= 1;
		auto c = s.find(b - *a);
		if (c != s.end()) {
			++ans;
			s.erase(c);
		}
	}
	cout << ans << endl;
}
