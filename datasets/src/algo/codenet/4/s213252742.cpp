#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K; cin >> N >> K;

	auto seen = set<int>{};
	while (K--) {
		int D; cin >> D;

		seen.insert(D);
	}

	auto search = true;
	auto i = N;
	while (search) {
		auto haha = true;
		for (auto j = i; j > 0; j /= 10) {
			if (seen.count(j % 10)) {
				haha = false;
				break;
			}
		}

		search = !haha;
		++i;
	}

	cout << i - 1 << endl;
}