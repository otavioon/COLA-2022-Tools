#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(var, begin, end) for (int var = (begin); var <= (end); var++)
#define RFOR(var, begin, end) for (int var = (begin); var >= (end); var--)
#define REP(var, length) FOR(var, 0, length - 1)
#define RREP(var, length) RFOR(var, length - 1, 0)
#define EACH(value, var) for (auto value : var)
#define SORT(var) sort(var.begin(), var.end())
#define REVERSE(var) reverse(var.begin(), var.end())
#define RSORT(var) SORT(var); REVERSE(var)
#define OPTIMIZE_STDIO ios::sync_with_stdio(false); cin.tie(0); cout.precision(10); cout << fixed
#define endl '\n'

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

void solve(istream& cin, ostream& cout) {
  string s;
  int k;
  cin >> s >> k;
  ll same = 0, now_same = 0;
  char now = s[0];
  FOR(i, 1, s.size() - 1) {
    if (s[i] == now) {
      now_same++;
    } else if (now_same > 0) {
      same += now_same + 1;
      now_same = 0;
    }
    now = s[i];
  }
  if (now_same > 0) same += now_same + 1;
  ll ans;
  if (s[0] == s[s.size() - 1]) {
    if (same == s.size()) ans = (ll)(s.size() / 2) * k;
    else {
      ll a = 1, b = 1;
      FOR(i, 1, s.size() - 1) {
        if (s[i] == s[i - 1]) a++;
        else
          break;
      }
      RFOR(i, s.size() - 2, 0) {
        if (s[i] == s[i + 1]) b++;
        else
          break;
      }
      ans = (ll)(same / 2) * k - (a / 2 + b / 2 - (a + b) / 2) * (k - 1);
    }
  } else {
    ans = (ll)(same / 2) * k;
  }
  cout << ans << endl;
}

#ifndef TEST
int main() {
  OPTIMIZE_STDIO;
  solve(cin, cout);
  return 0;
}
#endif
