#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int a[n];
	for (int i = 0; i < n; i++) a[i] = ri();
	std::sort(a, a + n);
	int res = 0;
	for (int i = 0; i < n; i++) {
		std::vector<int> all;
		int head = 0;
		int tail = 0;
		for (int j = 0; j < i; j++) {
			int upper = a[i] + a[j];
			int lower = a[i] - a[j];
			while (head < (int) all.size() && all[head] < upper) head++;
			while (tail < (int) all.size() && all[tail] <= lower) tail++;
			while (tail && all[tail - 1] > lower) tail--;
			res += head - tail;
			all.push_back(a[j]);
		}
	}
	printf("%d\n", res);
	return 0;
}

