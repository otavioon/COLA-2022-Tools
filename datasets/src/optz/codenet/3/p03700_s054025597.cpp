#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b;
vector<ll> h;

bool solve(ll total) {
  ll cnt_a = total;
  ll cnt_b = 0;
  for (int i = 0; i < n; i++) {
    ll rest = h[i] - a * cnt_a - b * cnt_b;
    if (rest > 0) {
      return false;
    }
    ll cnt = - rest / (a - b);
    cnt_a = cnt;
    cnt_b = total - cnt_a;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> a >> b;
  h = vector<ll>(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  sort(h.begin(), h.end(), greater<ll>());
  ll ok = (h[0] + b - 1) / b;
  ll ng = (h[0] + a - 1) / a - 1;
  while (ok - ng > 1) {
    ll mid = (ok + ng) / 2;
    if (solve(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << ok << endl;
  return 0;
}