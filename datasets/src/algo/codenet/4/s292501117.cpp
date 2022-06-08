#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int n, k, dd;
  cin >> n >> k;
  set<int> d;
  for (int i = 0; i < 10; ++i) d.insert(i);
  rep(i, k) cin >> dd, d.erase(dd);

  int ans = n;
  bool flg = true;
  while (1) {
    string s = to_string(ans);
    flg = true;
    for (int i = 0; i < s.length(); ++i) {
      int nn = s[i] - '0';
      if (d.find(nn) == d.end()) {
        flg = false;
        break;
      }
    }
    if (flg) break;
    ans++;
  }

  cout << ans << endl;
  return 0;

}
