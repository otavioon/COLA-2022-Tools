#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int INF = 100100100;
const double PI = 3.14159265358979323846;
typedef long long ll;
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define REP(i, n) for (ll i = 0; i < (n); ++i)

int main(void) {
  int n;
  cin >> n;
  int a[n], b[n], c[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  int ans = 0;
  sort(a, a + n);
  sort(b, b + n);
  sort(c, c + n);
  for (int i = 0; i < n; i++) {
    for (int j = lower_bound(b, b + n, a[i]) - b; j < n; j++) {
      ans += n - (lower_bound(c, c + n, b[j]) - c);
    }
  }
  cout << ans << endl;
  return 0;
}