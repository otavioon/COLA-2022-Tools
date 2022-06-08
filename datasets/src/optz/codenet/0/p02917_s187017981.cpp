#include <bits/stdc++.h>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| |   / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |   V /
const ll N   = 1e5 + 5;    //   | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //    ____| |_| |_|   |_|
ll read() {
  ll   x = 0, f = 1;
  char ch = getchar();

  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1; ch = getchar();
  }

  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0'; ch = getchar();
  }
  return x * f;
}

ll n;
ll b[N];
ll a[N];
ll ans;

int main() {
  n = read();

  for (int i = 1; i < n; i++) b[i] = read();
  a[1] = b[1];
  a[2] = b[1];

  for (int i = 2; i < n; i++) {
    if (a[i] >= b[i]) a[i] = a[i + 1] = b[i];
    else a[i + 1] = b[i];
  }

  for (int i = 1; i <= n; i++) ans += a[i];
  cout << ans << endl;
  return 0;
}
