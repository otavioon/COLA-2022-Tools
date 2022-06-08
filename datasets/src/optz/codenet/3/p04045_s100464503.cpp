#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<bool> dec(10,1);
  int x;
  int mx = 0;
  for (int i = 0 ; i < k; i++) {
    cin >> x;
    dec[x] = 0;
  }
  for (int i = 0; i < 10; i++) {
    if(dec[i]) {
      mx = i;
    }
  }
  int res = mx;
  int cnt = 1;
  while(res < n) {
    res *= 10;
    res += mx;
    cnt *= 10;
  }
  int ans = 0;
  while(ans < n) {
    for (int i = 0; i < 10; i++) {
      if(dec[i]) {
        if(ans + (i*cnt) + (res/10) >= n) {
          ans += i*cnt;
          res /= 10;
          cnt /= 10;
          break;
        }
      }
    }
  }
  cout << ans;
  return 0;
}
