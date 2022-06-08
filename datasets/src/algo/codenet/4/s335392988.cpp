#include <bits/stdc++.h>

using namespace std;

bool has_only_allowed(int num, set<int> &allowed) {
	while (num > 0) {
		if (allowed.find(num % 10) == allowed.end()) {
			return false;
		}
		num /= 10;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	set<int> allowed;
	for (int i = 0; i < 10; i++) {
		allowed.insert(i);
	}
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		allowed.erase(a);
	}
	while (true) {
		if (has_only_allowed(n, allowed)) {
			cout << n;
			break;
		}
		n++;
	}
	cout << '\n';
	return 0;
}