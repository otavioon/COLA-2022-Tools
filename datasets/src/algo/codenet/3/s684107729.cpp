#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;

const int MaxN = 1e5;
int a[MaxN + 5], b[MaxN + 5], c[MaxN + 5];
int n;

int main()
{
	while(~scanf("%d", &n)){
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n);
		sort(c + 1, c + 1 + n);
		LL ans = 0;
		int pa = 0, pc = 0;
		for(int i = 1; i <= n; i++){
			while(a[pa + 1] < b[i] && pa < n) pa++;
			while(c[pc + 1] <= b[i] && pc < n) pc++;
			ans += 1LL * pa * (n - pc);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
