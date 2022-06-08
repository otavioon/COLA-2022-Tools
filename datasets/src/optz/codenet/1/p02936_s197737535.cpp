#include<bits/stdc++.h>
using namespace std;
#define TRACE
#define M 1000000007
#define oo 1000000000000000007
#define F first
#define S second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pll;
#define pb push_back
#define M6 1000009
#define M5 500009
#define pi 3.14159265
#define epsilon 1e-6

#ifdef TRACE
    #define trace1(x)                cerr << #x << ": " << x << endl;
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
    #define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
    #define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
    #define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
 
#else
 
    #define trace1(x)
    #define trace2(x, y)
    #define trace3(x, y, z)
    #define trace4(a, b, c, d)
    #define trace5(a, b, c, d, e)
    #define trace6(a, b, c, d, e, f)
 
#endif
ll power(ll x,ll n,ll m){
    ll res=1;
    while(n>0){
        if(n&1) res=(res*x)%m;
        n/=2;
        x=(x*x)%m;
    }
    return res;
}

ll n,m,A[M5],timer=0,st[M5],en[M5],sum[M5],id[M5];
vector<ll> g[M5];
void dfs(ll cur,ll par){
    st[cur] = ++timer;
    id[timer] = cur;
    for(auto u:g[cur]) if(u!=par) dfs(u,cur);
    en[cur] = timer;
}
int  main()
{   //ios_base::sync_with_stdio (0), cin.tie (0);
    //sieve();
    //init();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll tc=1,t=0,i,j,k,a,b,c,d,l,r;
    //cin>>tc;
    while(t++<tc){
        //cout<<"Case #"<<t<<": ";
        cin>>n>>m;
        for(i=1;i<n;i++){
            cin>>a>>b;
            g[a].pb(b);
            g[b].pb(a);
        }
        dfs(1,0);
        while(m--){
            cin>>a>>b;
            sum[st[a]]+=b;
            sum[en[a]+1]-=b;
        }
        for(i=1;i<=n;i++) sum[i] += sum[i-1];
        for(i=1;i<=n;i++) cout<<sum[id[i]]<<" ";
    }
    return 0;
}