#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,a[100005],b[100005],c[100005],ok,ng,m,p,cnt[100005],cntz[100005],ans=0;
    cin>>n;
    rep(i,n){
        cin>>a[i];
    }
    rep(i,n){
        cin>>b[i];
    }
    rep(i,n){
        cin>>c[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    rep(i,n){
        ng=-1;
        ok=n;
        while(ok-ng>1){
            m=(ok+ng)/2;
            if(c[m]>b[i]){
                ok=m;
            }else{
                ng=m;
            }
        }
        cnt[i]=n-ok;
    }
    cntz[n]=0;
    rep(i,n){
        cntz[n-i-1]=cntz[n-i]+cnt[n-i-1];
    }
    rep(i,n){
        ng=-1;
        ok=n;
        while(ok-ng>1){
            m=(ok+ng)/2;
            if(b[m]>a[i]){
                ok=m;
            }else{
                ng=m;
            }
        }
        ans+=cntz[ok];
    }
    cout<<ans;
}