#include <cstdio>
#include <algorithm>
#include <tr1/unordered_map>

std::tr1::unordered_map<int,int> f;
int n, ans, a[200005], b[35];

int read() {
	int x = 0; char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x;
}

int main() {
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read(), ++f[a[i]];
	std::sort(a + 1, a + n + 1);
	for (int i = 1, j = 0; j <= 30; ++j) {
		while (a[i] <= 1 << j && i < n) ++i;
		b[j] = i;
	}
	for (int j = 30, i = 1 << j; ~j; --j, i = 1 << j) {
		for (int k = b[j]; k >= 1; --k)
			if ((a[k] != i - a[k] && f[a[k]] && f[i-a[k]]) || (a[k] == i - a[k] && f[a[k]] > 1)) ++ans, --f[a[k]], --f[i-a[k]];
	}
	printf("%d\n", ans);
	return 0;
}