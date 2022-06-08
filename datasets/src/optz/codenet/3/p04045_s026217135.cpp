#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, k, ans, t;
  cin >> n >> k;
  unordered_set<int> d;
  rep(i, k) cin >> t, d.insert(t);

  bool ok;
  while (1) {
    ok = true;
    ans = n;
    while (ans) {
      if (d.find(ans % 10) != d.end()) {
        ok = false;
        break;
      }
      ans /= 10;
    }

    if (ok) break;
    n++;
  }

  cout << n << endl;
  return 0;
}
