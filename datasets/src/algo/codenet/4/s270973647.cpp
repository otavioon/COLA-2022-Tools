#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  set<char> hsh;
  char c;
  for (int i = 0; i < k; ++i) {
    cin >> c;
    hsh.insert(c);
  }
  string res;
  for (int i = n; i <= 999999; ++i) {
    ostringstream oss;
    oss << i;
    string num = oss.str();
    bool ok = true;
    for (auto &x : num) {
      if (hsh.find(x) != hsh.end()) {
        ok = false;
        break;
      }
    }
    if (ok) {
      res = num;
      break;
    }
  }
  cout << res << endl;

  return 0;
}

