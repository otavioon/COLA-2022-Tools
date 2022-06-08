#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define INF 1e9;
using namespace std;
typedef long long ll;
int main() {
  ll N, K;
  cin >> N >> K;

  ll D[K];
  REP(i, K) { cin >> D[i]; }

  FOR(i, N, 100000) {
    ll tmp = i;
    set<ll> s;

    while (tmp > 0) {
      s.insert(tmp % 10);
      tmp /= 10;
    }

    bool f = true;

    REP(j, K) {
      if (s.count(D[j])) {
        f = false;
      }
    }
    if (f) {
      cout << i;
      return 0;
    }
  }
  return 0;
}