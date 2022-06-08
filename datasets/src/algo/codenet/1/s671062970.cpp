#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int c[3][3];

bool ok() {
  int b1 = c[0][0], b2 = c[0][1], b3 = c[0][2];
  int a2 = c[1][0] - c[0][0];
  if(a2 + b2 != c[1][1] || a2 + b3 != c[1][2]) return false;
  int a3 = c[2][0] - c[0][0];
  if(a3 + b2 != c[2][1] || a3 + b3 != c[2][2]) return false;
  return true;
}

int main () {
  rep(i,3)rep(j,3) {
    cin >> c[i][j];
  }

  cout << (ok() ? "Yes" : "No") << endl;
  return 0;
}
