#include <bits/stdc++.h>
using namespace std;

vector<bool> num(10);

bool ok(int n) {
  while (n > 0) {
    if (num.at(n % 10)) return false;
    n /= 10;
  }
  return true;
}

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i ++) {
    int tmp; cin >> tmp;
    num.at(tmp) = true;
  }

  int ans = n;
  while (!ok(ans)) {
    ans ++;
  }

  cout << ans << endl;
}
