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
            for (ll i = 40; i >= 0; i--) {
                  if (s.find(x - (1LL << i)) != s.end()) {
                        ans++;
                        s.erase(s.find(x - (1LL << i)));
                        flag = 0;
                        break;
                  }
            }
            if (flag) s.insert(x);
      }
      cout << ans;

      return 0;
}
