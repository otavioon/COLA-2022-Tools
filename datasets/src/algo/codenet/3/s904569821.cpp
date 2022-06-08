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
		for(int j = jsq1; j >= 1; j--) {
			if(c[i] <= b[j]) {
				jsq1 = min(j + 1, n);
				continue;
			}
			int l = 1, r = n + 1;
			while(l + 1 < r) {
				int mid = l + r + 1 >> 1;
				if(a[mid] >= b[j]) r = mid;
				else l = mid;
			}
			ans += l;
		}
	}
	printf("%lld\n", ans);
	return 0; 
}