#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);

  int n,k;
  cin >> n >> k;
  vector<int> d(k);
  REP(i,k) cin >> d[i];

  vector<bool> a(10, true);

  REP(i,10){
    REP(j,k){
      if(i == d[j]){
        a[i] = false;
      }
    }
  }

  int cn = n;
  int keta = 0;
  while(cn > 0){
    cn /= 10;
    keta++;
  }

  ostringstream oss;
  oss << n;
  string sn = oss.str();

  vec ans(keta);

  REP(i, keta){
    int min = INF;
    int gj = -1;
    REP(j, a.size()){
      char c = sn[i];
      int tmp = a[j] ? j - atoll(&c) : INF;
      if( tmp >= 0 && tmp < min){
        gj = j;
        min = tmp;
      }
    }
    if(min == INF){
      ans[i] = 10;
      FOR(j, 1, keta){
        REP(k, a.size()) 
        if(a[k]){
          ans[j] = k;
          break;
        } 
      }
      break;
    }
    else if(min > 0){
      ans[i] = gj;
      FOR(j, 1, keta){
        REP(k, a.size()) 
        if(a[k]){
          ans[j] = k;
          break;
        } 
      }
      break;
    }
    else{
      ans[i] = gj;
    }
  }
  
  REP(i, ans.size()){
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
