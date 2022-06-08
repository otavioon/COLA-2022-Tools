#include <bits/stdc++.h>
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
using namespace std;
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
//inline int in() { int x; scanf("%d",&x); return x;}
inline ll in() { ll x; cin >> x; return x; }
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
#define dame { puts("-1"); return 0;}
#define yn {puts("YES");}else{puts("NO");}
const int MX = 200005;

vector<int> to[2505];
vector<int> rto[2505];
bool reachablefrom1[2505];
bool reachableToN[2505];
bool ok[2505];

void dfs(int v) {
  if (reachablefrom1[v]) return;
  reachablefrom1[v] = true;
  for (int u : to[v]) {
    dfs(u);
  }
}
void rdfs(int v) {
  if (reachableToN[v]) return;
  reachableToN[v] = true;
  for (int u : rto[v]) {
    rdfs(u);
  }
}

int main() {
  int n=in(), q=in();
  vp ab(n-1);
  rep(i,n-1) {
    cin>>ab[i].se>>ab[i].fi;
    ab[i].se-=1;
    ab[i].fi-=1;
  }
  vp px(q);
  rep(i,q) {
    cin>>px[i].fi>>px[i].se;
    px[i].fi-=1;
  }
  sort(ab.rbegin(),ab.rend());
  vvi abchild(n);
  rep(i,n-1) {
    abchild[ab[i].se].pb(ab[i].fi);
    if (abchild[ab[i].fi].size()!=0)
      rep(j,abchild[ab[i].fi].size())
        abchild[ab[i].se].pb(abchild[ab[i].fi][j]);
  }
  vi ans(n);
  rep(i,n)ans[i]=0;
  rep(i,q) {
    rep(j,abchild[px[i].fi].size()) {
      ans[abchild[px[i].fi][j]] += px[i].se;
    }
  }
  //rep(i,n-1)cout<<ab[i].se<<" "<<ab[i].fi<<endl;
  //rep(i,q)cout<<px[i].fi<<" "<<px[i].se<<endl;
  rep(i,n){
    rep(j,abchild[i].size())
      cout<<abchild[i][j]<<" "; // 0-indexで出力される
    cout<<endl;
  }
  return 0;
}
