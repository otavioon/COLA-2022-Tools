#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  multiset<ll, greater<ll> > se;
  rep(i, N) {
    ll a;
    cin >> a;
    se.insert(a);
  }
  int ans = 0;
  while(!se.empty()) {
    ll tmp = *se.begin();
    ll pair = (ll)pow(2, ceil(log2(tmp))) - tmp;
    if(pair == 0) pair = tmp;
    se.erase(se.begin());
    auto itr = se.find(pair);
    if(itr != se.end()) {
      ans++;
      se.erase(itr);
    }
  }
  cout << ans << endl;
  return 0;
}

