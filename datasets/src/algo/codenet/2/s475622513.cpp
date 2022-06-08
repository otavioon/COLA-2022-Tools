#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      multiset<ll> s;
      int ans = 0;
      while (n--) {
            ll x; cin >> x; int flag = 1;
            if (flag) s.insert(x);
      }

      while (s.size()) {
            ll x = *s.begin(); s.erase(s.begin());
            for (ll i = 40; i >= 0; i--) {
                  if (s.find(abs((1LL << i) - x)) != s.end()) {
                        ans++;
                        s.erase(s.find(abs(x - (1LL << i))));
                        break;
                  }
            }
      }
      cout << ans;

      return 0;
}
