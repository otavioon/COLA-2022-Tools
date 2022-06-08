#include <bits/stdc++.h>
using namespace std;
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
 
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
 
  int N, K, k;
  cin >> N >> K;
  set<int> set;
  rep(i, 0, 10) { set.insert(i); }
 
  rep(i, 0, K) {
    cin >> k;
    set.erase(k);
  }
 
  bool ok;
  int ans = N;
 
  while (N < 10001) {
    string str = to_string(ans);
    ok = true;
    rep(i, 0, str.size()) {
      if (!set.count(str[i] - '0')) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << ans << endl;
      break;
    }
    ans++;
  }
  getchar();
}