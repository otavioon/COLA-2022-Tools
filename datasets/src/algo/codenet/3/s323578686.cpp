#include <algorithm> 
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n;
int a[100005], b[100005], c[100005];
int jsq1, jsq2;
long long ans;

int main() {
	scanf("%d", &n); jsq1 = jsq2 = n;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]); sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]); sort(b + 1, b + 1 + n);
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]); sort(c + 1, c + 1 + n);
	for(int i = n; i >= 1; i--) {
		jsq2 = n;
		for(int j = jsq1; j >= 1; j--) {
			if(c[i] <= b[j]) {
				jsq1 = min(j + 1, n);
				continue;
			}
			for(int k = jsq2; k >= 1; k--) {
				if(b[j] <= a[k]) {
					jsq2 = min(k + 1, n);
					continue;
				}
				ans += k;
				break;
			}
		}
	}
	printf("%lld\n", ans);
	return 0; 
}