#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#include<tuple>
#include<string.h>
#include<iomanip>
#include<stack>
#include<queue>

using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define ALLOF(c) (c).begin(), (c).end()
#define Pa pair<ll,ll>
const ll mod=1000000007;
const ll INF=10e12;
const ll inf=-1;
ll ABS(ll a){return max(a,-a);}


int main(void){
    ll N,K;
    cin>>N>>K;
    vector<ll> A(K);
    rep(i,K) cin>>A.at(i);
    ll ans=N,look=N%10;
    rep(i,K){
        if(look==A.at(i)) {
            ans+=1;
            look+=1;
        }
        if(look==10){
            look=0;
            i=0;
        }
    }
    if(ans<10){
        cout<<ans<<endl;
        return 0;
    }
    
    look=(ans%100)/10;
    rep(i,K){
        if(look==A.at(i)) {
            ans+=10;
            look+=1;
        }
        if(look==10){
            look=0;
            i=0;
        }
    }
    if(ans<100){
        cout<<ans<<endl;
        return 0;
    }
    
    look=(ans%1000)/100;
    rep(i,K){
        if(look==A.at(i)) {
            ans+=100;
            look+=1;
        }
        if(look==10){
            look=0;
            i=0;
        }
    }
    if(ans<1000){
        cout<<ans<<endl;
        return 0;
    }
    
    look=(ans%10000)/1000;
    rep(i,K){
        if(look==A.at(i)) {
            ans+=1000;
            look+=1;
        }
        if(look==10){
            look=0;
            i=0;
        }
    }
    if(ans<10000){
        cout<<ans<<endl;
        return 0;
    }
    
    look=(ans%100000)/10000;
    rep(i,K){
        if(look==A.at(i)) {
            ans+=10000;
            look+=1;
        }
        if(look==10){
            look=0;
            i=0;
        }
    }
    if(ans<100000){
        cout<<ans<<endl;
        return 0;
    }
}
