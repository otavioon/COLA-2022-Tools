/*_BELIEVE_*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

#include<bits/stdc++.h>
using namespace std;

#define     int          long long int
#define     fast()       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)       x.begin(),x.end()
#define     mem(a,b)     memset(a,b,sizeof(a))
#define     gcd(a,b)     __gcd((a),(b))
#define     lcm(a,b)     ((a)*(b))/gcd((a),(b))
#define     pb           push_back
#define     ins          insert
#define     F            first
#define     S            second

const int inf=1e18,M=1e9+7;
const int N=2e5+5;

vector<int> v[N],dp(N,0);

void dfs(int x,int p)
{
    if(p!=-1)
        dp[x]+=dp[p];
        
    for(auto u:v[x])
    {
        if(u==p)
            continue;
            
        dfs(u,x);
    }
}

void solve()
{
    int n,q;
    cin>>n>>q;
    
    int a,b;
    for(int i=1;i<n;++i)
    {   
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    
    int x,y;
    for(;q;--q)
    {
        cin>>x>>y;
        
        dp[x]+=y;
    }
    
    dfs(1,-1);
    
    for(int i=1;i<=n;++i)
        cout<<dp[i]<<" ";
}

int32_t main()
{
    fast();

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
