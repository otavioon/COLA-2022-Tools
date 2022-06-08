// -----------------------------------
// Author     : MatsuTaku
// Affiliation: Tokushima University
// Country    : Japan
// Date       : 04/01/2020
// -----------------------------------

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  int N,K; cin>>N>>K;
  set<int> D;
  for (int i = 0; i < K; i++) {
    int d; cin>>d;
    D.insert(d);
  }
  int ans = N;
  while (true) {
    bool end = true;
    int c = ans;
    while (c) {
      auto b = c%10;
      if (D.count(b)) {
        end = false;
        break;
      }
      c /= 10;
    }
    if (end) {
      break;
    }
    ans++;
  }
  cout << ans << endl;

  return 0;
}
