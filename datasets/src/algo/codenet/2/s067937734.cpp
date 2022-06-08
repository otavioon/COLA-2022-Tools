#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 10;

int n, vis[maxn], Ans;
ll a[maxn], mx;

inline void solve(ll k) {
	vis[0] = 0;
  for(int i = 1, j = n;i <= n;i ++) {
	  if(vis[i]) continue;
		while(j > 0 && (vis[j] || a[i] + a[j] > k)) j --;
		if(j && a[i] + a[j] == k) {
		  vis[i] = 1;
			vis[j] = 1;
			Ans ++;
		}
	}
}

int main() {
	scanf("%d", &n);
	mx = - 1;
	for(int i = 1;i <= n;i ++) scanf("%lld", &a[i]), mx = max(mx,a[i]);
	int len = 1;
	while((1LL << (len + 1)) <= mx) len ++;
	len ++;
	Ans = 0;
	memset(vis,0,sizeof(vis));
	sort(a + 1,a + n + 1);
	for(int i = len;i >= 0;i --) {
		solve(1LL << i);
	}
	printf("%d\n", Ans);
  return 0;
}
