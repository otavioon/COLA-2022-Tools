#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <algorithm>
#include <map>
#include <sstream>

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
static ull tenq = 1000000000;
static ull mod = tenq + 7;

using namespace std;

int main()
{
  ll N = 3;
  vector<vector<ll>> as(N, vector<ll>(N));
  for (auto i = 0; i < N; i++) {
    for (auto j = 0; j < N; j++) cin >> as[i][j];
  }

  bool correct = true;
  for (auto i = 0; i < N; i++) {
    for (auto j = i + 1; j < N; j++) {
      ll d0 = as[i][0] - as[j][0];
      ll d1 = as[i][1] - as[j][1];
      ll d2 = as[i][2] - as[j][2];

      ll d3 = as[0][i] - as[2][j];
      ll d4 = as[1][i] - as[1][j];
      ll d5 = as[2][i] - as[2][j];

      if (!(d0 == d1 && d0 == d2 && d3 == d4 && d3 == d5)) correct = false;
    }
  }

  cout << (correct ? "Yes" : "No") << endl;

  return 0;
}
