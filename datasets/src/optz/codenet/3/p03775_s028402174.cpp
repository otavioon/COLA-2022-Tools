#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
inline int getInt() { int x; scanf("%d",&x); return x;}
template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>inline ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
template<typename T>inline ll suma(const v(T)& a) { ll res(0); for (auto&& x : a) res += x; return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MX = 200005;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
//---------------------------------------------------------------
#define fastio std::ios::sync_with_stdio(false);
#define myio ifstream iofi; if(argc>1){iofi.open(argv[1]); std::cin.rdbuf(iofi.rdbuf());}
using u32 = int32_t ;
using u64 = int64_t ;
//--------------------------------------------------------------
vector<long long> divisor(long long n){
  vector<long long> ret;
  for(long long i=1; i*i <=n; ++i){
    if(n%i == 0){
      ret.push_back(i);
      if(i*i!=n) ret.push_back(n /i);
    }
  }
  sort(ret.begin(),ret.end());
  return ret;
}



int main(int argc,char** argv){ fastio; myio;
  ll n;
  cin>>n;
  auto a = divisor(n);
  rep(i,a.size())
    a[i] = ((ll)log10(a[i])+1);
  ll ans = 11;
  rep(i,dup(sz(a),2)){
    mins(ans, max( a[i], a[a.size()-1-i] ) );
  }
  cout<<ans<<endl;
}