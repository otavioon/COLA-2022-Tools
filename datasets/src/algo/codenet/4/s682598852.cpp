#include <bits/stdc++.h>
using namespace std;

set<char> digits;

bool check(int n) {
	stringstream ss;
	ss << n;
	string s = ss.str();
	for (int i = 0; i < s.size(); i++) {
		if(digits.count(s[i])) return 1;
	}
	return 0;
}

int main() {
#ifdef _DEBUG
	freopen("in" , "r", stdin );
	freopen("out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 0; i < k; i++) {
		char c; cin >> c;
		digits.insert(c);
	}
	while(check(n)) n++;
	cout << n << '\n';
}
