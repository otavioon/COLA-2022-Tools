/* When Talent doesn't work, Hard work beats Talent*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include"bits/stdc++.h"

using namespace std;

#define Fast_D cout<<fixed<<setprecision(13);
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define nl "\n"
#define int long long
#define double long double
#define all(v) v.begin(),v.end()
#define scanstr(s) cin>>ws; getline(cin,s);

const double PI = 3.141592653589793;

void solve()
{
	int inf = 1e16;
	int n;
	cin >> n;
	int b[n];
	for(int i=0;i<n-1;i++)
	{
		cin >> b[i];
	}
	b[n-1] = inf;
	int ans = 0;
	ans += b[0];
	for(int i=0;i<n-1;i++)
	{
		ans += min(b[i],b[i+1]);
	}
	cout << ans ;
}

int32_t main()
{
	FastIO;
	Fast_D;
	int T;
	T=1;
	while(T--) solve();
	return 0;
}

