#include <bits/stdc++.h>
#define d(i) cout << #i << " = " << i << endl
#define int long long
using namespace std;

const int maxn = 2e3+10, maxl = 1e3+10;;

int n, l[maxn], cnt[maxl<<1], sum[maxl<<1], ans;

signed main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> l[i];
		cnt[l[i]]++;
	}
	for (int i = 1; i < maxl<<1; ++i)
		sum[i] = sum[i-1]+cnt[i];
	for (int i = 0; i < maxl; ++i) if (cnt[i]) {
		for (int j = 0; j <= i; ++j) if (cnt[j] > (i==j)) {
			if (i == j) {
				ans += (sum[i+j-1]-sum[i])*cnt[i]*(cnt[i]-1)/2;
				ans += cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
			} else {
				ans += (sum[i+j-1]-sum[i])*cnt[i]*cnt[j];
				ans += cnt[i]*(cnt[i]-1)/2*cnt[j];
			}
		}
	}
	cout << ans << endl;
}
