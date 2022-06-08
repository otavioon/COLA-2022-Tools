#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int c[3][3];

int main() {
  rep(i,3) rep(j,3) cin >> c[i][j];
  bool ok = true;
  int h_dif1 = c[0][1] - c[0][0];
  int h_dif2 = c[0][2] - c[0][0];
  if (c[1][1] - c[1][0] != h_dif1) ok = false;
  if (c[1][2] - c[1][0] != h_dif2) ok = false;
  if (c[2][1] - c[2][0] != h_dif1) ok = false;
  if (c[2][2] - c[2][0] != h_dif2) ok = false;
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}