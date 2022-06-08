#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
#define MAX_C 1000000001
#define MOD 1000000007

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) cin >> c[i];

  sort(a.begin(), a.end());
  //sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    int bi = b[i];
    auto ita = lower_bound(a.begin(), a.end(), bi);
    if (ita == a.begin()) continue;
    ita--;
    auto itc = upper_bound(c.begin(), c.end(), bi);
    //cnt += (ll) (ita - a.begin() + 1) * (c.end() - itc);
    cnt += (ll) (distance(a.begin(), ita) + 1) * (distance(itc, c.end()));
  }

  cout << cnt << endl;
}
