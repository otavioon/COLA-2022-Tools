#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

// repetition
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// container util
#define all(x) (x).begin(), (x).end()

// debug
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x)                                         \
  cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
       << " " << __FILE__ << endl;

// typedef
typedef long long lint;
typedef unsigned long long ull;
typedef complex<long double> Complex;
typedef pair<int, int> P;
typedef tuple<int, int, int> TP;
typedef vector<int> vec;
typedef vector<vec> mat;

// constant
const int MOD = (int)1e9 + 7;
const int INF = (int)1e18;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

// conversion
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}

//
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
//

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  lint k;
  cin >> s >> k;
  lint res = 0, r = 0, m = 0, l = 0, tmp = 0;
  bool flag = true;
  rep(i, s.size()) {
    if (s.size() <= i + 1) {
      if (flag) {
        l++;
      } else {
        r = tmp;
        r++;
      }
      continue;
    }
    if (s[i] == s[i + 1]) {
      if (flag) {
        l++;
      } else {
        tmp++;
      }
    } else {
      if (flag) {
        flag = false;
        l++;
      } else {
        if (tmp == 0) continue;
        m += tmp;
        m++;
        tmp = 0;
      }
    }
  }

  //  cout << "l = " << l << endl;
  //  cout << "m = " << m << endl;
  //  cout << "r = " << r << endl;

  if (s.front() == s.back()) {
    res += (r / 2) + (m / 2) * k + (l / 2);
    res += (r + l) / 2 * (k - 1);
  } else {
    res += (r / 2) * k + (m / 2) * k + (l / 2) * k;
  }

  if (flag) {
    if (l % 2) {
      res = l / 2 * (k + 1) / 2;

      if (1 < k) res += (l + 1) / 2 * (k / 2);
    } else {
      res = l / 2 * k;
    }
  }

  if (s.size() == 1) {
    res = k / 2;
  }

  cout << res << endl;

  return 0;
}