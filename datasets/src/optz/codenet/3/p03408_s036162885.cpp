#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> blue(n);
  for (int i = 0; i < n; i++) {
    cin >> blue.at(i);
  }
  int m;
  cin >> m;
  vector<string> red(m);
  for (int i = 0; i < m; i++) {
    cin >> red.at(i);
  }

  int ans = 0;
  for (int i = 0; i < n; i ++) {
    int tmp = 0;
    for (int j = 0; j < n; j ++) {
      if (blue.at(i) == blue.at(j)) {
        tmp ++;
      }
    }
    for (int j = 0; j < m; j ++) {
      if (blue.at(i) == red.at(j)) {
        tmp --;
      }
    }
    ans = max(0, tmp);
  }

  cout << ans << endl;
}
