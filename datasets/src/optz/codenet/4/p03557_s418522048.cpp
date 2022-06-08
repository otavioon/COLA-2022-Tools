#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  
  set<int> a, b, c;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    a.insert(x);
  }
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    b.insert(x);
  }
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    c.insert(x);
  }
  
  int ans = 0;
  for (auto ea: a) {
    auto itb = b.upper_bound(ea);
    if (itb == b.end()) break;
    auto itc = c.upper_bound(*itb);
    if (itc == c.end()) break;
    else {
      ans++;
      b.erase(itb);
      c.erase(itc);
    }
  }
  
  cout << ans << endl;
  return 0;
}	