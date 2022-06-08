#include <bits/stdc++.h>
using namespace std;

int main() {
  char C[3][4];
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> C[i][j];
    }
  }
  cout << (C[1][1] == C[2][3] && C[1][2] == C[2][2] && C[1][3] == C[2][1] ? "YES" : "NO") << endl;
}