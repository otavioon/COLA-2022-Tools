#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int a[N];
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
  }
  int ans = a[n-1];
  for (int i = n-1; i >= 1; i--) {
    if (i > 1) ans += min(a[i], a[i-1]);
    else ans += a[i];
  }
  cout << ans;
}
