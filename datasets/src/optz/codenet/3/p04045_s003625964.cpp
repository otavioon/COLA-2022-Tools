#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<bool> h(10, 0);
  for (int i = 0; i < k; i++) {
    int a;
    cin >> a;
    h[a] = 1;
  }

  for (n; 1; n++) {
    bool ok = 1;
    for (int x = 1; x < 1000000; x *= 10) {
      if (h[n % (10 * x) / x] == 1 && n >= x) {
        ok = 0;
        break;
      }
    }
    if (ok)
      break;
  }
  cout << n << endl;
}