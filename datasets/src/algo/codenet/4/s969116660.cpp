#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

int main(void) {
	int n, k; cin >> n >> k;
	vector<int> dislike(k);
	for (int i = 0; i < k; i++) cin >> dislike[i];

	for (int x = n; x < 100000; x++) {
		int tmp = x;
		set<int> s;
		while (tmp != 0) {
			s.insert(tmp % 10);
			tmp /= 10;
		}

		bool flag = true;

		for (int i = 0; i < k; i++) {
			if (s.count(dislike[i])) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << x << endl;
			break;
		}
	}

	return 0;
}