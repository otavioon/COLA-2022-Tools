// In the name of God

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;
const int mod = 1e9+7;

long long fac[N], pw[N];

long long fast_exp(long long x, long long y) {
	long long ret=1;
	for(;y;y>>=1) {
		if(y&1) ret=(ret*x)%mod;
		x=(x*x)%mod;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fac[0] = 1;
	pw[0] = 1;
	for(int i=1;i<N;i++) {
		fac[i] = (fac[i-1]*i)%mod;
		pw[i] = (2*pw[i-1])%mod;
	}
	int n;	
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	long long ans = 0;
	for(int i=0;i<v.size();i++) {
		long long c = pw[i];
		c = (c*v[i])%mod;
		
		int top = (int)v.size()-i-1;
		c = (c*(top+2))%mod;
		c = (c*pw[top]*fast_exp(2, mod-2))%mod;
		
		ans = (ans+c)%mod;
	}
	ans = (ans*pw[n])%mod;
	cout << ans;
	return 0;
}
