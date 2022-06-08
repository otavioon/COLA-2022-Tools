#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> inline int Log2(T& x) {int k; for(k=0; (T(1)<<k)<=x; ++k); return k;}


int main() {
  ll N; cin >> N;
  multiset<int> a;
  rep(i, N) {
    int x; cin >> x;
    a.insert(x);
  }

  int ans = 0;
  while (!a.empty()) {
    auto it = a.end();
    it--;
    int x = *it;
    int k = Log2(x);
    int y = (1<<k) - *it;
    a.erase(it);

    it = a.find(y);
    if (it != a.end()) {
      a.erase(it);
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
