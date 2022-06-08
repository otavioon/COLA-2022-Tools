#include <bits/stdc++.h>
#define ll int
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define deb(x) cout<<#x<<"="<<x<<endl;
#define endl '\n'
#define M 1000000007
// #define int long long
#define INF 1e18
#define max_n 1000000
// #define double long double

using namespace std;

void solve()
{
   ll n,k;
   cin>>n>>k;
   double a[n];
   double ans=0;
   for(ll i=0;i<n;++i)
   {
       cin>>a[i];
       ans=max(ans,a[i]);
   }
   double l=1,r=2e9;
   while(l<=r)
   {
       double mid=l+(r-l)/2;
       ll b=0;
       for(int i=0;i<n;++i)
       {
           b+=(a[i]/mid);
       }
       if(b<=k)
       {
           ans=mid;
           r=mid-1;
       }
       else l=mid+1;
   }
   ll an=round(ans);
   cout<<an<<endl;
}

int32_t main()
{
	IOS
	ll T = 1;
// 	cin >> T;
	for (ll i = 1; i <= T; ++i)
	{
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
