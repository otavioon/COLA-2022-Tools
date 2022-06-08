#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
using ll = long long;
using namespace std;

int main(){
    ll n;
    cin>>n;
    ll a[n],b[n],c[n];
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>b[i];
    rep(i,0,n)cin>>c[i];
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    ll ans=0,tmp1=0;
    rep(i,0,n){
        rep(j,0,n){
            if(b[j]<=a[i])continue;
            rep(k,0,n) {
                if(c[k]<=b[j])continue;
                else {ans+=(n-k);break;}
            }
        }
    }
    cout<<ans;
}