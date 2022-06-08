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
#define M6 5000009
#define M5 500009
#define pi 3.14159265
#define epsilon 1e-6

ll n,m,A[M5];
ll prime[M6];
void sieve(){
    for(int i=2;i<M6;i++) prime[i]=1;
    for(int i=2;i*i<M6;i++){
        if(prime[i]==0) continue;
        for(int j=i*2;j<M6;j+=i) prime[j]=0;
    }
}

ll power(ll x,ll n,ll m){
    ll res=1;
    while(n>0){
        if(n&1) res=(res*x)%m;
        n/=2;
        x=(x*x)%m;
    }
    return res;
}
ll fac[M5];
ll nCr(ll n, ll r) {
    return (((fac[n]*power(fac[r],M-2,M))%M)*power(fac[n-r],M-2,M))%M;
}
int  main()
{
    ios_base::sync_with_stdio (0), cin.tie (0);
    //sieve();

    ll tc=1,t=0,i,j,k,a,b,c;
    //cin>>tc;
    while(t++<tc){
        string s;
        cin>>s>>n;
        ll ans=0,c=1;
        std::vector<ll> v;
        for(i=1;i<s.size();i++) {
            if(s[i]==s[i-1] ) c++;
            else {
                v.pb(c);
                a+=c/2;
                c=1;
            }
        }
        v.pb(c);
        //for(auto u:v) cout<<u<<" "; cout<<"\n";
        if(s[0]==s[s.size()-1]) {
            if(v.size()==1) ans=(n*s.size())/2;
            else {
                for(i=1;i<v.size()-1;i++) ans+=v[i]/2;
                ans=ans*n; //cout<<ans<<" ";
                ans+=v[0]/2;  //cout<<ans<<" ";

                ans+=((v[0]+v[v.size()-1])/2)*(n-1); //cout<<ans<<" ";
                ans+=v[v.size()-1]/2;
            }
        }
        else ans=a*n;
        cout<<ans;
    }
    return 0;
}