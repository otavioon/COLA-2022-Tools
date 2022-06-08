#include <bits/stdc++.h>
using namespace std;
#define ll          long long int
#define pb          push_back
#define pll         pair<ll,ll>
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mode        998244353
#define mod         1000000007
#define inf         1000000000000000000LL
#define vl          vector<ll>
#define F           first
#define S           second
#define db          long double
#define sz(x)       (ll)x.size()
#define fix(n)      cout<<fixed<<setprecision(n)
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define all(x)      x.begin(),x.end()
#define mset(x)     memset(x,0,sizeof x)
#define pi          3.14159265358979323

//ashishgup

const int N = 2e5+5;

ll n, ans=0;
ll a[N];
map<ll,ll>m;

void solve()
{
       cin>>n;
       rep(i,1,n+1) { cin>>a[i]; m[a[i]]++; }
       //sort(a+1, a+1+n);
       for(ll i=32; i>=0; i--)
       {
              for(auto &it:m)
              {
                     ll other = (1LL<<i)-it.F;
                     if(other == it.F)
                     {
                            ll take = it.S/2;
                            it.S%=2;
                            ans+=take;
                            continue;
                     }
                     if(m.find(other)!=m.end())
                     {
                            ll take = min(it.S, m[other]);
                            ans += take;
                            it.S -= take;
                            m[other] -= take;
                     }
              }
       }
       cout<<ans;
}


int main()
{
    speed_up
    ll T=1;
    //cin>>T;
    while(T--)
        solve();
    return 0;
}
