#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);

  ll ma = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ma = max(ma, a[i]);
  }

  ll left = -1;
  ll right = ma + 1;

  while (right - left > 1) {
    const ll mid = (left + right) / 2;

    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += (a[i] + mid - 1) / mid - 1;
    }

    if (sum <= k)
      right = mid;
    else
      left = mid;
  }

  cout << right << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);

  solve();
  return 0;
}
