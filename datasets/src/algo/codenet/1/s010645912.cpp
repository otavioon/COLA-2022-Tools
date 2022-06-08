#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int c[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> c[i][j];
    }
  }
  cout << (c[0][0] + c[1][2] + c[2][1] == c[0][1] + c[1][0] + c[2][2] && c[0][2] + c[1][1] + c[2][0] == c[0][1] + c[1][0] + c[2][2] ? "Yes\n" : "No\n");
  return 0;
}
