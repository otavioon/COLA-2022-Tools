#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#pragma warning(disable:4996)
using namespace std;
const int maxn = 200005;
typedef long long ll;
multiset<ll>q;
int n;
ll ans;
ll a[maxn];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		q.insert(a[i]);
	}
	while (!q.empty()) {
		ll v = *--q.end();
		q.erase(q.end());
		for (int i = 0; i <= 32; i++) {
			ll t = (1 << i) - v;
			if (q.find(t) != q.end()) {
				ans++;
				q.erase(q.find(t));
				break;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}