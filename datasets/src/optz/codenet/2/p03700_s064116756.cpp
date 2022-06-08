//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
#define pb push_back
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};
struct edge2{ll from,to,cost;};

ll N,A,B;
vl h(1e5);

ll floor(ll x,ll y){
  	return (x+y-1)/y;
}
bool BN(ll x){
    ll cnt=0;
    rep(i,N){
        if(x*B>=h[i]){
            continue;
        }
        else{
            cnt+=floor(h[i]-x*B,(A-B));
        }
    }
    return (cnt<=x ? true : false );
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> A >> B;
    h.resize(N);
    rep(i,N){
        cin >> h[i];
    }
    ll ok=1e9,ng=0;
    while(abs(ok-ng)>1){
        ll mid=(ok+ng)/2;
        if(BN(mid)){
            ok=mid;
        }
        else{
            ng=mid;
        }
    }
    cout << ok << endl;
}