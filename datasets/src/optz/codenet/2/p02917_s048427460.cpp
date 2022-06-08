#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inf 9223372036854775807
#define mini 9223372036854775807
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
pair<ll,ll>s4[4]={{-1,0},{1,0},{0,-1},{0,1}};
pair<ll,ll>s8[8]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,1},{1,0},{1,-1}};
ll power(ll a,ll b)
{
	if(b==0)
		return 1;
	ll c=power(a,b/2);
	if(b%2==0)
		return ((c%mod)*(c%mod))%mod;
	else
		return ((((c%mod)*(c%mod))%mod)*a)%mod;
}
int main()
{
	boost
	ll n;
	cin>>n;
	vector<ll>v;
	for(ll i=1; i<n; i++)
	{
		ll x;
		cin>>x;
		v.pb(x);
	}
	ll ans=v[0]+v[n-2];
	for(ll i=1; i<n; i++)
		ans+=min(v[i],v[i-1]);
	cout<<ans<<endl;
	return 0;
}