#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

int main(){
  string S; cin >> S;
  ll K; cin >> K;
  ll N = S.length();

  vector<ll> q;
  for (int i = 0; i < N; ++i){
    ll num = 1;
    while (i + 1 <= N && S[i] == S[i + 1]) i++, num++;
    q.push_back(num);
  }
  ll ans = 0;
  if ((ll)q.size() == 1) cout << N * K / 2 << endl;
  else if (S[0] != S[N - 1]) {
    rep(i, (int)q.size()) ans += q[i] / 2;
    ans *= K;
    cout << ans << endl;
  }
  else {
    ans += q[0] / 2;
    ans += q[(ll)q.size() - 1] / 2;
    for (int i = 1; i < (int)q.size() - 1; ++i) ans += q[i] / 2;
    ll tmp = (q[0] + q[(ll)q.size() - 1]) / 2;
    tmp *= (K - 1);
    ans += tmp;
    cout << ans << endl;
  }
}
