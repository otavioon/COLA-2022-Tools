#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define INF 9223372036854775807
#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define RFOR(i,a,b) for(long long i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<P> Graph;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,a,b;
  cin >> n >> a >> b;
  
  vector <ll>h(n);
  REP(i,n) cin >> h[i];
  
  sort(h.begin(),h.end(),greater<ll>());

  ll ng = 0, ok = MOD;
  while(ok-ng > 1){
    ll check = (ok+ng)/2;
 //   cout << check << ":";
    vector<ll> c;
    c = h;
    REP(i,n){
      c[i] -= check*b;
    }
    int k = 0;
    ll cnt = check;
    while(c[k] > 0 && cnt >= 0 && k<n){
      cnt -= ceil((double)c[k]/(a-b));
      k++;
    }
    if(cnt < 0) ng = check;
    else	    ok = check;
//    cout << ng << " " << ok << endl;
  }
  
  cout << ok << endl;
  
  return 0;
}