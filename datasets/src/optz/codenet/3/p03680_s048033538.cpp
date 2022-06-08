//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define NP next_permutation
#define pb push_back
#define eb emplace_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
#define fi first
#define se second
#define pi M_PI
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef multiset<ll> S;
typedef priority_queue<ll> PQ;
typedef priority_queue<P,vector<P>,greater<P>> SPQ;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;

const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;

template<class T> bool chmin(T&a,T b){if(a>b){a=b; return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b; return true;}return false;}
template<class T> void decimal(T a){cout<<fixed<<setprecision(a);}
template<class T> void out(T a){cout<<a<<endl;}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<endl;}
template<class T> void outvp(T v){rep(i,v.size())outp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<endl;}
template<class T> void outvv(T v){rep(i,v.size()){rep(j,v[i].size()){if(j)cout<<' ';cout<<v[i][j];}cout<<endl;}}

void YesNo(bool a){if(a) out("Yes"); else out("No");}
void yesno(bool a){if(a) out("yes"); else out("no");}
void YESNO(bool a){if(a) out("YES"); else out("NO");}
ll GCD(ll a,ll b){if(b==0) return a; return GCD(b,a%b);}
ll LCM(ll a,ll b){return(a/GCD(a,b))*(b/GCD(a,b))*GCD(a,b);}
ll POW(ll a,ll b){ll c=1; while(b>0){if(b&1){c=a*c %mod;}a=a*a %mod;b>>=1;}return c;}
vi calc(ll x){vi res; while(x>0){res.pb(x%10);x/=10;}reverse(all(res)); return res;}

void solve() {
  int n; cin>>n;
  vi a(n); rep(i,n) cin>>a[i];
  int i=1,cnt=0;
  while(i!=2){
    cnt++;
    i=a[i-1];
    if(cnt>n){
      out(-1);
      return;
    }
  }
  out(cnt);
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
