#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
 
/*@@@@@@@@@@@@@@@@@@@@O:8:O@@@@@@@@@c cCCCco@@@C  o@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@8:88Cc@@@@@@C.cCCCCCCC:@O.CCCC:c@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@cC888:@@@@o.CCCCCCCCCCc cCCCCCCC:o@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@8:8888cO@o.CCCCCo:CCCCC:cCCCCCCCCCo.@@@@@@@@@@@@@@@Oc
@@@@@@@@@@@@@@@@@@@@oo8888C :CCCCCCc.CCCCC:cCCCCCCCCCCCC.O@@@@@@@@@8c:C88
@@@@@@@@@@@@@@@@@@@@cO8888O:CCCCCCc.CCCCC:cCCCCCCCCCCCCCC:O@@@@@O:cO88888
@@@@@@@@@@@@@@@@@@@@:O88888:oCCCCo.CCCCCc:CCCccCCCCCCCCCCC:C@8:cO88888888
@@@@@@@@@@@@@@@@@@@8c888888ccCCCC.cCCCCo.oCCC::CCCCCCCCCCCC.:O888888888C.
@@@@@@@@@@@@@@@@@@@Oc888888ocCCoc.CCCCC:cCCCoc.oCCCCCCCCc.C8888888888O:c@
@@@@@@@@@@@@@@@@@@8 c888888C:Coo:cCCCCo:CCCoo. oCCCCCCc:O8888888888Oc:@@@
@@@@@@@@@@@@@@@@@:coc888888C:ooo.oCCCC.oCCCoc.:coCCC:c88888888888Oc:8@@@@
@@@@@@@@@@@@@@@C:CCo:888888O:ooo.CCCCc:CCCoo.co.oo:c88888888888Oc.8@@@@@@
@@@@@@@@@@@@@@:oCCCC:O88888O:oo..CCCC.oCCCoc.CC..c8888888888OCc..@@@@@@@@
@@@@@@@@@@@@O.CCCC.. O888888:c.c:CCCc:CCCoo:cC::8888888888OCc.oCcc@@@@@@@
@@@@@@@@@@@C:CCCCco8oc888888.:C:cCCC.oCCCooc .O888888888Oo..CCCCC:O@@@@@@
@@@@@@@@@@ccCCCCCc:8O:O88888:.cooCo.oCCCCoo.C888888888o.cO8c:CCCCo:@@@@@@
@@@@@@@@@:cCCCCCCC.C8oo88888:oCCCc:CCCCCo::888888888C:88Oo.cCCCCCCcc@@@@@
@@@@@@@@:oCCCCCCCCc.O8888888:oCCo:CCCCCo.C88888888888OCc.cCCCCCCCCC:C@@@@
@@@@@@@:cCCCCCCCCooc.O88888O:CCCCCCCCCc:88888888888Oo:.oCCCCCCCCCCCo.:O@@
@@@@@@ccCCCCCCCooooo. oO888C:CCCCCCCC:o88888888OOC:. ooooCCCCCCCCCCC:oO:8
@@@@@ocCCCCCCCooooc.oo cCCC:cCCCCCCC.C88888OOCo: c88o.oooCCCCCCCCCCCC:O8o
@@@@C:CCCCCCCoooo.:OO:oo.::.CCCCCCCc:OOOCCoc:.cCco888o:oooCCCCCCCCCCCcc88
@@@8.CCCCCCCCoo::O88C ..oCCCCCCCCCCCc.:::coCCCCCo:8888o.ooooCCCCCCCCCC:O8
@@@:oCCCCCCCoc.C8888o ..:CCCCCCCCCCCCCCCCc .: cCo.O8888o.oooCCCCCCCCCCcc8
@@C:CCCCCCCo.o888888o . :CCCCCCCCCCCCCCC. co c.co.o88888C.ooooCCCCCCCCo:O
@8.oCCCCCC:o88888888C   :CCCCCCCCCCCCCC:     c.:o::O88888O.ooooCCCCCCCC:o
::cCCCCC.c88888888888:coCCCCCCCCCCCCCCC   :.cc.ooc.O888888O:coooCCCCCCCcc
8:oCCc.o88888888888888:oCCoCCCCCCCCCCCo.    .:oooo.oO8888888c:ooooCCCCCo:
8o..cO88888888888888888o::..oooooooooooooooooooo:cccC88888888C.oooooCCCC:
8888888888888888888888888c..cooooooo:oooooooc:cO@@O:CO888888888::ooooooC:
88888888888888888888888OCoCCC::ccc..:::....8@@@@@@@:oCO888888888C.cooooo:
888888888888888888888OCCCCo:::cccC@@8.:cco:@@@@@@@@C:CC88888888888O::coc.
888888888888888888OC::cc..c8888888OooooO8o.C@@@@@@@@:ooO8888888888888OOO8
888888888888888OOCcc88O:C:cc:C8888c CccC:o8O:ccoO@@@ccCoO8888888888888888
888888888888OCooCo:888:c.oCcco:O8:oo:Cc:o.C888888oc@8:CooO888888888888888
8888888OOCooCCoCCc:888C.:oo:co:CO:oo:oo.cO8888888Ooc@ccCCoO88888888888888
CCCCoooCCCCCCCCo:oCO8888c:oc::C88C.:oooO8888888OCoC:88:CCCoC88888888888*/
 
using namespace std;
typedef long long ll;
using gra = vector<vector<ll>>;
 
typedef unsigned long long ull;
 
template <class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template <class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
 
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template <class T> T dup(T a, T b) { return (a + b - 1) / b; }
template <class T> T modpow(T x, T p, T m) { T a=1; while(p){ if(p%2)a =a*x%m; x = x+x%m; p/=2; } return a; }
// template <class T> void prim(T a) { for(ll i=0;i<a.size();++i) { cout << a[i]; } cout << "\n"; }
 
#define mod 1000000007LL
#define INF 10000000000000000LL
 
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i <= n; ++i)
#define rrep(i, n) for (int i = (n - 1); i >= 0; --i)
#define rrep1(i, n) for (int i = n; i > 0; --i)
 
#define pri(x) cout << (x) << "\n"
#define pri2(x, y) cout << (x) << " " << (y) << "\n"
#define pri3(x, y, z) cout << (x) << " " << (y) << " " << (z) << "\n"
//#define modpow(x, p, m) { ll a=1; while(p){ if(p%2)a =a*x%m; x = x+x%m; p/=2; } return a; }
 
#define m0(h) memset(h, 0, sizeof(h))
#define m1(h) memset(h, 1, sizeof(h))
#define m(h, n) memset(h, (n), sizeof(h))
#define all(n) (n).begin(),(n).end()
#define bit(n) (1LL << (n))
#define pb push_back
 
#ifdef LOCAL

#define dpri(...) fprintf(stderr, __VA_ARGS__)
#define pria(g) rep(i,g.size()){ cout << i << "{"; rep(j,g[i].size()) cout << g[i][j] << " "; cout << "}" << "\n"; }
#else
#define dpri(...) 42
#define pria(g) 42
#endif
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // ---------------------
  // コーディング開始
  // ---------------------
  ll n;
  string s;
  cin >> n;
  ll l[n];
  ll a;
  rep(i,n){
    cin >> a;
    l[i]=a;
  }
  ll ans =0;
  for(ll i=0;i<n-2;i++)
    for(ll j=i+1;j<n-1;j++)
      for(ll k=j+1;k<n;k++)
        if(l[i]<l[j]+l[k])
          if(l[k]<l[i]+l[j])
            if(l[j]<l[k]+l[i])
              ans++;
  pri(ans);



  //l[n]=3001;
  //ll sk[3001];
  //sort(l,l+n);
  //ll co=0;
  //rep(i,n){
  //  for(ll j=l[i];j<l[i+1];j++){
  //    sk[j]=i+1;
  //  }
  //}
  //rep(i,9){
  //  pri(sk[i]);
  //}
  //pri("-------------------");
  //ll ans = 0;
  //rep(i,n-2) for(ll j=0;j<n-1;j++){
  //  pri3(l[i],l[j],sk[l[i]+l[j]]-sk[max(abs(l[i]-l[j]),0ll)]);
  //  pri("-----------");
  //}
  return 0;
}
