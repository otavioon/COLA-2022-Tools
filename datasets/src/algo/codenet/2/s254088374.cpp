#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, x, n) for (int i = (x); i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
template<typename T> void cmax(T &a, T b) { a = max(a, b); }
template<typename T> void cmin(T &a, T b) { a = min(a, b); }

signed main() {
  int n;
  cin >> n;
  multiset<int> s;
  rep(i, n) {
    int a;
    cin >> a;
    s.insert(a);
  }
  int ans = 0;
  while (!s.empty()) {
    auto x = s.end();
    x--;
    int t = *x;
    s.erase(x);
    int u = 1;
    while (u <= t) u *= 2;
    u -= t;
    auto y = s.find(u);
    if (y == s.end()) continue;
    ans++;
    s.erase(y);
  }
  cout << ans << endl;
  return 0;
}
