#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

#define mem(dp,a)           memset(dp,a,sizeof dp)
#define rep(i,a,b)          for(ll i=a;i<b;i++)
#define pb(x)               push_back(x)
#define mp(x,y)             make_pair(x,y)
#define fastio              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F                   first
#define S                   second
#define all(v)              (v).begin(),(v).end()
#define pi					3.14159265359
ll INF=1e18+10;
ll MOD=1000000007;

int main()
{
    int n;cin>>n;
    ll f[1010];mem(f,0);
    rep(i,0,n)
    {
        int a;cin>>a;
        f[a]++;
    }
    ll spref[2010];mem(spref,0);
    rep(i,0,1010)
    spref[i]=(f[i]>0) ? 1 : 0;
    rep(i,2,2010)
    spref[i]+=spref[i-1];

    ll ans=0;
    rep(i,0,1001)
    ans=(ans+(f[i]/3));

    rep(i,1,1001)
    ans=(ans+(f[i]>=2 ? (spref[2*i-1]-1) : 0));

    rep(i,1,1001)
    {
        rep(j,1,i)
        {
            if(f[i]>0 && f[j]>0)
            ans+=(spref[i+j-1]-spref[i]);
        }
    }
    cout<<ans;
}
