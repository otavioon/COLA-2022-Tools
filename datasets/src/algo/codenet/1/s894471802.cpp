#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

// 4近傍、8近傍
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
  // 入力
  int grid[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> grid[i][j];
    }
  }

  int sum1 = grid[0][0] + grid[1][1] + grid[2][2];
  int sum2 = grid[0][1] + grid[1][2] + grid[2][0];
  int sum3 = grid[0][2] + grid[1][0] + grid[2][1];

  // 解答
  cout << (sum1 == sum2 && sum2 == sum3 ? "Yes" : "No") << endl;

  return 0;
}
