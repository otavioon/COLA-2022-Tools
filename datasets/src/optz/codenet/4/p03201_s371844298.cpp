#include <cstdio>
#include <algorithm>
#include <tr1/unordered_map>

std::tr1::unordered_map<int,int> f; int n, ans, a[1000000];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), ++f[a[i]];
	std::sort(a + 1, a + n + 1);
	for (int j = 30, i = 1 << j; ~j; --j, i = 1 << j) {
		for (int k = n; k >= 1; --k)
			if ((a[k] != i - a[k] && f[a[k]] && f[i-a[k]]) || (a[k] == i - a[k] && f[a[k]] > 1)) ++ans, --f[a[k]], --f[i-a[k]];
	}
	printf("%d\n", ans);
	return 0;
}