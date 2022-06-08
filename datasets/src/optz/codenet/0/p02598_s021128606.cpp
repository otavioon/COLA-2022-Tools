#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fr(j,i,n) for(int i=j;i<n;++i)
#define frr(j,i,n) for(int i=j;i<=n;++i)
using namespace std;
void solve()
{
	ll n,k;
	cin>>n>>k;
	ll a[n+1];
	frr(1,i,n)	cin>>a[i];
	ll left=0,right=1e9;
	ll ans=1e10;
	while(left<=right)
	{
		ll moves=k;
		ll mid=(left+right)/2;
		frr(1,i,n)
		{
			if(a[i]%mid==0 and a[i]!=0 and mid!=0)
				moves-=((a[i]/mid)-1ll);
			else if(a[i]!=0 and mid!=0)
				moves-=(a[i]/mid);

			if(moves<0)
				break;
		}
		if(moves>=0)
			ans=min(mid,ans),right=mid-1;
		else
			left=mid+1;
	}
	cout<<ans<<"\n";
}
int main()
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	// t=1;
	// cin>>t;
	while(t--)
	solve();
	return 0;
}

