
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//#include<boost/multiprecision/cpp_int.hpp>

//#include <boost/math/common_factor.hpp>
//namespace mp=boost::multiprecision;
#define ll long long
#define mod 1000000007
#define fi first
#define se second
#define inf 4e18
#define lim 1000000000000
#define pll pair<ll,ll>
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define el "\n"
#define vll vector<ll>
#define vpll vector<pll>
#define vppll vector<pair<ll,pll> >
#define vvpll vector<vector<pair<ll,ll> > >
#define vvll vector<vector<ll> >
#define vvc vector<vector<char> >
#define vc vector<char>
//#define mod 998244353
ll gcd(ll a,ll b){if(b==0)return a;else return gcd(b,a%b);}
ll xpow(ll a,ll b,ll m)
{
    if(!b)
        return 1%m;
    if(b==1)
        return a%m;
    if(b&1)
    {
        return(((a%m)*xpow(a,b-1,m))%m);
    }
    else
    {
        ll p=xpow(a,b/2,m);
        return((p*p)%m);
    }
}
/*double xpow(double a,ll b)
{
    if(!b)
        return 1;
    if(b==1)
        return a;
    if(b&1)
    {
        return((a*xpow(a,b-1)));
    }
    else
    {
        p=xpow(a,b/2);
        return((p*p));
    }
}
void dfs(ll v,vector<vector<ll> > &edge,vector<bool> &vis)
{
    vis[v]=1;
    for(ll i=0;i<edge[v].size();i++)
    {
        ll v1=edge[v][i];
        if(!vis[v1])
        {
            dfs(v1,edge,vis;
        }
    }
}
ll parent(ll x,vector<ll> &par)
{
    if(par[x]==x)
        return(x);
    par[x]=parent(par[x],par);
    return(par[x]);
}
bool uni(ll a,ll b,vector<ll> &par)
{
    ll pa=parent(a,par);
    ll pb=parent(b,par);
    if(pa==pb)
        return 0;
    else
    {
        par[pa]=pb;
        return 1;
    }
}
void seive(vector<bool> &v)
{
    ll n=v.size();
    for(ll i=2;i*i<n;i++)
    {
        if(v[i])
        {
            for(ll j=i*i;j<n;j+=i)
                v[j]=0;
        }
    }
}
void bfs(ll v,vector<vector<ll> > &edge,vector<bool> &vis,vector<ll> &level)
{
    queue<ll> q;
    q.push(v);
    vis[v]=1;
    level[v]=0;
    while(!q.empty())
    {
        ll ve=q.front();q.pop();
        for(ll i=0;i<edge[ve].size();i++)
        {
            ll vee=edge[ve][i];
            if(!vis[vee])
            {
                vis[vee]=1;
                level[vee]=level[ve]+1;
                q.push(vee);
            }
        }
    }
}
ll solve(ll x,ll n)
{
    ll low=0,high=2e9,mid;
    ll ans=x;
    while(low<high)
    {
        mid=low+(high-low)/2;
        ll val=(mid*(mid+1))/2;
        if(val>=x)
        {
            ans=mid;
            high=mid;
        }
        else
        {
            low=mid+1;
        }
    }
    return(ans);
}
bool chk(ll vv,vector<ll> &v)
{
    for(auto p:v)
    {
        if(p==vv)
            return 0;
    }
    return 1;
}
ll phi(ll n)
{
    ll ans=n;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i)
            continue;
        while(n%i==0)
        {
            n/=i;
        }
        ans=ans-ans/i;
    }
    if(n>1)
        ans-=ans/n;
    return(ans);
}
ll tr[800005];
void build(ll node,ll l,ll r,vector<ll> &v)
{
    if(l==r)
    {
        tr[node]=v[l];
        return;
    }
    ll mid=(l+r)/2;
    build(2*node+1,l,mid,v);
    build(2*node+2,mid+1,r,v);
    tr[node]=max(tr[2*node+1],tr[2*node+2]);
}
ll query(ll node,ll s,ll e,ll l,ll r)
{
    if(e<l || s>r)
        return 0;
    if(s>=l&&e<=r)
    return(tr[node]);
    ll mid=(s+e)/2;
    ll m1=query(2*node+1,s,mid,l,r);
    ll m2=query(2*node+2,mid+1,e,l,r);
    return(max(m1,m2));
}
ll nCr(ll n,ll r)
{
    ll ans=1;
    for(ll i=1;i<=n-r;i++)
    {
        ans=(ans*((r+i)));
        ans/=i;
        ans%=mod;
        //ans/=i;
    }
    ans%=mod;
    return(ans);
}
void djks(ll v,vvll &edge,vvll &dist)
{
    ll n=edge.size()-1;
    vll dis(n+1,inf);
    priority_queue<pll> pq;
    dis[v]=0;
    pq.push({0,v});
    while(!pq.empty())
    {
        pll p=pq.top();pq.pop();
        p.fi*=-1;
        for(ll i=1;i<=n;i++)
        {
            if(edge[p.se][i])
            {
                if(dis[i]>(dis[p.se]+edge[p.se][i]))
                {
                    dis[i]=dis[p.se]+edge[p.se][i];
                    pq.push({-dis[i],i});
                }
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        dist[v][i]=dis[i];
    }
}

ll kmp(string &s)
{
    string t=s;
    reverse(all(t));
    string a=s+"#"+t;
    ll n=a.size();
    vll nxt(n);
    nxt[0]=0;
    ll i=0,j=1;
    while(j<n)
    {
        if(a[i]==a[j])
        {
            nxt[j]=i+1;
            i++;j++;
        }
        else
        {
            if(i)
            i=nxt[i-1];
            else
            {
                nxt[j]=0;
                j++;
            }
        }
    }
    return(nxt[n-1]);
}
string sadd(string a,string b)
{
    string t;
    ll la=a.length(),lb=b.length();
    ll d=0;
    ll i=la-1,j=lb-1;
    while(i>=0 && j>=0)
    {
        ll x=a[i]-'0',y=b[j]-'0';
        t.pb((x+y+d)%10+'0');
        d=(x+y+d)/10;
        i--;j--;
    }
    while(i>=0)
    {
        ll x=a[i]-'0';
        t.pb((x+d)%10+'0');
        d=(x+d)/10;i--;
    }
    while(j>=0)
    {
        ll y=b[j]-'0';
        t.pb((y+d)%10+'0');
        d=(y+d)/10;j--;
    }
    while(d)
    {
        t.pb(d%10+'0');
        d/=10;
    }
    //cout<<a<<" "<<b<<el;
    reverse(all(t));
    return(t);
}*/
const ll zzz=1e3+5;
ll nCr[zzz][zzz];
void cal()
{
    nCr[0][0]=1;
    for(ll i=1;i<zzz;i++)
    {
        nCr[i][0]=1;
        for(ll j=1;j<zzz;j++)
        {
            nCr[i][j]=(nCr[i-1][j]+nCr[i-1][j-1])%mod;
        }
    }
}
const ll N=1e5+5;
bool check_prime(ll n)
{
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
bool chk(ll &l,vll &v,ll &k)
{
    ll c=0;
    for(auto p:v)
    {
        c+=(p-1)/l;
    }
    if(c<=k)
        return 1;
    else
        return 0;
}
void doit()
{
    ll n,k;cin>>n>>k;
    vll v(n);
    for(ll i=0;i<n;i++)
        cin>>v[i];
    ll low=1,high=2e9,mid;
    ll ans=0;
    while(low<=high)
    {
        mid=low+(high-low)/2;
    //    cout<<mid<<" "<<chk(mid,v,k)<<el;
        if(chk(mid,v,k))
        {
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    cout<<ans;
    cout<<el;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cal();//For nCr;
    //Array of length 5e6 can be made...and I think questions are also within range
    //2^17>10^5 and 2^16<10^5
    ll t;
    t=1;
    //cin>>t;
    while(t--)
    {
        doit();
    }
    return 0;
}
