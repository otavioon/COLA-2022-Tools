#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
#include <deque>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define MOD1 1000000007



int main() {
  int c[3][3];
  rep(i, 3) {
    rep(j, 3) {
      cin >> c[i][j];
    }
  }

  int a1 = 0;
  int b1 = c[0][0], b2 = c[0][1], b3 = c[0][2];
  int a2 = c[1][0] - b1, a3 = c[2][0] - b1;

  if (a2 + b2 == c[1][1] && a2 + b3 == c[1][2]
   && a3 + b2 == c[2][1] && a3 + b3 == c[2][2]) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }


}
