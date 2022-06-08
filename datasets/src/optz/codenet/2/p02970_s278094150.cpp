#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
const ll MOD=1000000007;
const ll LINF=0x1fffffffffffffff;
const int INF=0x3fffffff;
const vector<pll> dir={{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=b-1;i>=a;i--)
#define range(i) (i).begin(),(i).end()
#define rrange(i) (i).rbegin(),(i).rend()
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll lcm (ll a,ll b) {return a*b/gcd(a,b);}
inline constexpr int intpow(ll a,ll b){
    if(b==0) return 1;
    ll ans=intpow(a,b/2);
    return ans*ans%MOD*(b&1?a:1)%MOD;
}
inline constexpr int modf(ll n){
    ll ans=1;
    rep(i,0,n) {ans=ans*(n-i)%MOD;}
    return ans;
}

vector<ll> func,inv;
void init(ll n){
    func.resize(n+1);inv.resize(n+1);
    func[0]=1;
    rep(i,0,n) {func[i+1]=func[i]*(i+1)%MOD;}
    inv[n]=intpow(func[n],MOD-2);
    rrep(i,1,n+1) {inv[i-1]=inv[i]*i%MOD;}
}
ll comb(ll a,ll b) {return func[a]*inv[b]%MOD*inv[a-b]%MOD;}

inline long double median(vector<ll> v){
    ll size=v.size();
    sort(v.begin(),v.end());
    if (size % 2 == 1) return v[(size - 1) / 2];
    else return v[(size / 2) - 1] ;
}
template<class T> inline bool chmax(T& a,T b) {if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b) {if(a>b){a=b;return 1;} return 0;}

int main(){
  ll n,d;
  cin>>n>>d;
  ll ans=n/(2*d+1);
  if(n%(2*d+1)) ans++;
  cout<<ans;  
}
