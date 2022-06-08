#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  multiset<ll> a;
  for (int i = 0; i < n; i++) {
    ll x; cin >> x;
    a.insert(x);
  }

  int ans = 0;
  while (a.size() >= 2u) {
    auto it = a.end();
    it--;
    ll x = *it;
    a.erase(it);

    ll p = 1;
    while (p <= x) p *= 2;
    ll y = p - x;

    it = a.find(y);
    if (it != a.end()) {
      ans++;
      a.erase(it);
    }
  }
  cout << ans << endl;

  return 0;
}
