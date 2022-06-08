#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int k = ri();
	std::vector<int> a(n);
	for (auto &i : a) i = ri();
	
	auto ok = [&] (int x) {
		int64_t cnt = 0;
		for (int i = 0; i < n; i++) cnt += (a[i] - 1) / x + 1;
		return cnt - n <= k;
	};
	
	int l = 0;
	int r = 1000000001;
	while (r - l > 1) {
		int m = l + ((r - l) >> 1);
		if (ok(m)) r = m;
		else l = m;
	}
	printf("%d\n", r);
	return 0;
}
