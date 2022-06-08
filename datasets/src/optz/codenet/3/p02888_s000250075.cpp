#include<bits/stdc++.h>
using namespace std;
int n, ans;
int len[2010];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &len[i]);
	}
	sort(len + 1, len + n + 1);
	for(int i = 1; i <= n; i ++) {
		for(int j = i + 1; j <= n; j ++) {
			int k = len[i] + len[j];
			int pos = lower_bound(len + 1, len + n + 1, k) - len - 1;
			if(pos > j) {
				ans += pos - j;
			}
		}
	}
	printf("%d", ans);
	return 0;
}