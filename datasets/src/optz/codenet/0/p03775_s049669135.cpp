#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
const int INF=1e15;
const int MAX=200001;
const int MOD=1e9+7;
int fac[MAX],finv[MAX],inv[MAX];

void COMinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
 
int COM(int n,int k){
    if(n<k)return 0;
    if(n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

int keta(int x){
    int ret=1;
    while(x>=10){
        x/=10;
        ret++;
    }
    return ret;
}

signed main(){
    int N;cin>>N;
    int MA=1;
    for(int i=1;i<=sqrt(N);i++){
        if(N%i==0)MA=i;
    }
    cout<<max(keta(MA),keta(N/MA))<<endl;
}