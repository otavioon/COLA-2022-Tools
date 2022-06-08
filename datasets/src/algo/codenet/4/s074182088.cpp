#include <bits/stdc++.h>
using namespace std;

bool ok(int n, set<int>& s) {
	while(n) {
		if(s.count(n % 10)) return false;
		n /= 10;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	set<int> s;
	for(int i = 0; i < k; i++) {
		int a;
		cin >> a;
		s.insert(a);
	}
	for(;;n++) {
		if(ok(n, s)) {
			cout << n << endl;
			return 0;
		}
	}
	return 0;
}