/*
Look at the star
Look at the shine for U
*/
#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
#define sl(x) scanf("%lld",&x)
using namespace std;
const int N = 1e6+5;
const int mod = 998244353;
const int INF = 0x3f3f3f3f;
ll inv(ll b){if(b==1)return 1; return (mod-mod/b)*inv(mod%b)%mod;}
ll fpow(ll n,ll k){ll r=1;for(;k;k>>=1){if(k&1)r=r*n%mod;n=n*n%mod;}return r;}
ll s[N],pre[N];

int main()
{
	ll a,b;
	sl(a);sl(b);
	cout<<(a-1)*(b-1)<<endl;
}