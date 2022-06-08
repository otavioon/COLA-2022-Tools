
#include "bits/stdc++.h"

#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define rep(i, a, b) for (long i = (a); i <= (b); ++i)
#define per(i, a, b) for (long i = (a); i >= (b); --i)

using namespace std;

using I = int;
using L = long;
using F = float;
using S = string;
using SS = stringstream;
using C = char;
using LL = long long;
using VI = vector<int>;
using VL = vector<long>;
using VF = vector<float>;
using VS = vector<string>;
using VVI = vector<vector<int>>;
using VVL = vector<vector<long>>;
using PLL = pair<long, long>;
using PLF = pair<long, float>;
using PLS = pair<long, string>;
using PSL = pair<string, long>;
using PSF = pair<string, float>;
using PSS = pair<string, string>;
using MLL = map<long, long>;
using MLF = map<long, float>;
using MLS = map<long, string>;
using MSL = map<string, long>;
using MSF = map<string, float>;
using MSS = map<string, string>;

const long kMax2 = 109;
const long kMax3 = 1009;
const long kMax4 = 10009;
const long kMax5 = 100009;
const long kMax6 = 1000009;
const long kInfI = 0x3F3F3F3F;
const float kInfF = 1e15;

template <class T>
void PrintVector(const vector<T> & v) {
  for (const auto & e: v) {
    cout << e << endl;
  }
}

template <class T>
void PrintVector(const vector<T> & v, I n) {
  rep(i, 0, n - 1) {
    cout << v[i] << endl;
  }
}

int main(int argc, char const *argv[]) {
  I x, y, z;
  cin >> x >> y >> z;
  I d1 = y - x, d2 = z - y;
  rep(i, 0, 1) {
    I x, y, z;
    cin >> x >> y >> z;
    if ((y - x != d1) || (z - y != d2)) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}
