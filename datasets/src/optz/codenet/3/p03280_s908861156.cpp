#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <regex>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using dbl = double;
using pii = pair<int,int>;
using pl4 = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vvs = vector<vs>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpl4 = vector<pl4>;
using vvpl4 = vector<vpl4>;
using vd = vector<dbl>;
using vvd = vector<vd>;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pob pop_back()
#define sz size()
#define be begin()
#define en end()
#define asn assign
#define emp empty()
#define ft front()
#define bk back()
#define clr clear()
#define ins insert
#define ers erase
#define res resize

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rFOR(i,a,b) for(int i=(b);i>=(a);i--)
#define SORT(a) sort((a).be,(a).en)
#define rSORT(a) sort((a).rbegin(),(a).rend())
#define UNIQUE(a) (a).erase(unique((a).be,(a).en),(a).en)
#define PREVP(a) prev_permutation((a).be,(a).en)
#define NEXTP(a) next_permutation((a).be,(a).en)
#define BINS(a,b) binary_search((a).be,(a).en,(b))
#define LOWB(a,b) (lower_bound((a).be,(a).en,(b))-(a).be)
#define UPB(a,b) (upper_bound((a).be,(a).en,(b))-(a).be)
#define CNT(a,b) count((a).be,(a).en,b)
#define SUM(a) accumulate((a).be,(a).en,0)
#define REV(a) reverse((a).be,(a).en)
#define REGS(a,b) regex_search((a),regex(b))
#define REGM(a,b) regex_match((a),regex(b))
#define yn(a) cout <<((a)?"yes":"no")<<endl;
#define Yn(a) cout <<((a)?"Yes":"No")<<endl;
#define YN(a) cout <<((a)?"YES":"NO")<<endl;
#define say(a) cout <<(a);
#define sal(a) cout <<(a)<<endl;
#define sak cout <<endl;
#define dbg(a) cout <<(#a)<<": "<<(a)<<endl;
#define a2l(a) ((ll)(a-97))
#define A2l(a) ((ll)(a-65))
#define l2a(a) ((char)(a+97))
#define l2A(a) ((char)(a+65))
#define DigN2(a) ((llabs(a)==0)?(1):((ll)(log2(double(llabs(a))))+1))
#define DigN10(a) ((llabs(a)==0)?(1):((ll)(log10(double(llabs(a))))+1))
#define Dig2(a,b) (((a)>>(b))&1)
#define Dig10(a,b) (ll)(((a)/((ll)(pow(10.0,(double)(b)))))%10)
#define Pow2(a) (1<<(a))
#define llin(a) ll (a);cin >>(a);
#define stin(a) string (a);cin >>(a);
#define rdn(a,b) ((a)/(b))
#define rou(a,b) ((((double(a)/double(b))-((a)/(b)))<0.5)?((a)/(b)):(((a)/(b))+1))
#define rup(a,b) ((((a)%(b))==0)?((a)/(b)):(((a)/(b))+1))
#define min(a,b) ((a<b)?(a):(b))
#define max(a,b) ((a>b)?(a):(b))
#define powll(a,b) (ll)(pow((double)(a),(double)(b)))

#define int ll

const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const string alp = "abcdefghijklmnopqrstuvwxyz";
const string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

void salv(vll v){
    say("{");
    FOR(i,0,v.sz-1){
        say(v[i]);
        if(i!=v.sz-1) say(",");
    }
    sal("}")
}

ll DigS10(ll n){
    ll m=0;
    FOR(i,0,DigN10(n)-1){
        m+=(ll)((llabs(n)%(ll)(pow(10.0,(double)(i+1))))/(ll)(pow(10.0,(double)i)));
    }
    return m;
}

ll isP(ll n){
    if(n<=1) return 0;
    FOR(i,2,(ll)sqrt(n)){
        if(n%i==0) return 0;
    }
    return 1;
}

vll FactM(1,1);
vll FactMI(1,1);

ll PowM(ll a,ll b){
    ll ans=1,x=(a%MOD);
    FOR(i,0,DigN2(b)-1){
        if(Dig2(b,i)==1) ans=(ans*x)%MOD;
        if(i!=(DigN2(b)-1)) x=(x*x)%MOD;
    }
    return ans;
}

void CFactM(ll n){
    if(FactM.sz<=n){
        FOR(i,FactM.sz,n){
            FactM.pb((FactM[i-1]*(i%MOD))%MOD);
        }
    }
    return;
}

void CFactMI(ll n){
    CFactM(n);
    if(FactMI.sz<(n+1)) FactMI.res(n+1,-1);
    if(FactMI[n]==-1) FactMI[n]=PowM(FactM[n],MOD-2);
    rFOR(i,1,n-1){
        if(FactMI[i]!=-1) break;
        FactMI[i]=((FactMI[i+1]*((i+1)%MOD))%MOD);
    }
    return;
}

ll CombM(ll n,ll k){
    if((n<0)||(k<0)) return 0;
    if(n<k) return 0;
    if(n+1>FactMI.sz) CFactMI(n);
    return ((((FactMI[k]*FactMI[n-k])%MOD)*FactM[n])%MOD);
}

signed main() {

    llin(N);
    llin(M);
    llin(Q);
    vpl4 tra(M);
    ll ta,tb;
    vvll dp1(N+2,vll(N+2,0));
    vvll dp2(N+2,vll(N+2,0));
    FOR(i,0,M-1){
        cin >>ta>>tb;
        tra[i].fi=ta;
        tra[i].se=tb;
    }
    SORT(tra);
    FOR(i,0,M-1){
        FOR(j,tra[i].se,N){
            dp1[tra[i].fi][j]++;
        }
    }
    FOR(i,1,N){
        rFOR(j,1,i){
            dp2[j][i]=dp2[j+1][i]+dp1[j][i];
        }
    }
    ll p,q;
    FOR(i,0,Q-1){
        cin >>p>>q;
        sal(dp2[p][q]);
    }

}


