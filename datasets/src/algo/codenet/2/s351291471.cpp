#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	multiset<int> ms;
	for (int i = 0; i < n; ++i) {
		int u; scanf("%d", &u);
		ms.insert(u);
	}
	int ans = 0;
	while (ms.size()) {
		int u = *ms.rbegin(); ms.erase(ms.find(u));
		int v = 1;
		while (v <= u) v <<= 1;
		if (ms.find(v - u) != ms.end()) {
			++ans; ms.erase(ms.find(v - u));
		}
	}
	printf("%d\n", ans);
}