#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (auto &e : a)
    cin >> e;
  for (auto &e : b)
    cin >> e;
  for (auto &e : c)
    cin >> e;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  vector<int> bcnt(n);
  for (int i = 0; i < n; ++i) {
    auto m = upper_bound(c.begin(), c.end(), b[i]);
    bcnt[i] = distance(m, c.end());
  }
  for (int i = n-2; 0 <= i; --i) {
    bcnt[i] += bcnt[i+1];
  }


  uint64_t ans = 0;
  for (int i = 0; i < n; ++i) {
    auto m = upper_bound(b.begin(), b.end(), a[i]);
    int pos = distance(b.begin(), m);
    ans += bcnt[pos];
  }
  cout << ans << "\n";
}
