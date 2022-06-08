// When you are hungry for something and you're determined and you're focused 
// and you're committed to something it's hard to surrender, isn't it?

#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define ll long long 
#define int ll
#define mod 1000000007
#define mod1 1000000006
#define modi 998244353
#define setbit(x) __builtin_popcount(x)
#define fff(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
#define pb push_back
vector<ll> vi[300005];
int color[100005];
ll pa[500005];
ll si[500005];
#define pb push_back
bool visi[1000005]={false};
bool is[100005];
ll fac[10000001];
ll prime[400005];
ll bit[100005];
const long double eps = 1.0e-14;      // allowable error
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
 
 
void fact(){
    fac[0]=1;
    for(int i=1;i<=10000000;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    return ;
}
void sieve(){
    prime[0]=0;
    prime[1]=0;
    for(int i=2;i<400005;i++){
        prime[i]=1;
    }
    for(int i=2;i*i<400005;i++){
        if(prime[i]==1){
            for(int j=i*i;j<400005;j+=i){
                prime[j]=0;
            }
        }
    }
    
}
 
ll power(ll n , ll p ){
    if(p==0)
        return 1;
    
    ll res = power((n*n)%mod,p/2);
    if(p%2==1)
        res = (n*res)%mod;
    
    return res;
}
 
 
void upd(ll i,ll val,ll n) {
    for(;i<=n;i+=i&(-i))
        bit[i]+=val;
}
 
ll qry(ll i) {
    ll sum=0;
    for(;i>0;i-=i&(-i))
        sum+=bit[i];
    return sum;
}
 
 
ll fin(ll u) {
    if(pa[u]==u)
        return u;
    return fin(pa[u]);
}
 
void uni(ll u,ll v) {
    ll p1=fin(u);
    ll p2=fin(v);
    if(p1==p2)
        return;
    if(si[p1]<si[p2])
        swap(p1,p2);
    si[p1]+=si[p2];
    pa[p2]=p1;
    return;
}
 
int32_t main() {
    fio
    
    int n;
    cin >> n;
    int a[n];//,b[n],c[n-1];
    
    fff(i,n-1)
    cin >> a[i];
    
    int ans=0;
    fff(i,n-1)
    ans+=a[i];
    
    cout << ans+a[0];
    
	return 0;
    
}