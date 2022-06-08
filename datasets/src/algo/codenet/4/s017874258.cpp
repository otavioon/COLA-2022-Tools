// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

set<int> S;
int n, k;
const int INF = 100000000;
vector<int> dp(10000000, -1);

int dfs(int m) {
  int &cc = dp[m];
  if (~cc) return cc;
  if (m >= n) return cc = m;
  int min_ = INF;
  loop(i,0,10) {
    if (S.count(i)) continue;
    if (m == 0 and i == 0) continue;
    min_ = min(min_, dfs(m * 10 + i));
  }
  return cc = min_;
}

int main() {
  cin >> n >> k;
  loop(i,0,k) {
    int a; cin >> a;
    S.insert(a);
  }
  cout << dfs(0) << endl;
  return 0;
}
