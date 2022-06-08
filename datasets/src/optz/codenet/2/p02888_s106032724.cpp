//
// Created by Tetsuya Shiota on 2019-04-13.
//

#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define REP(i, b, n) for (Int i = b; i < Int(n); i++)
#define rep(i, n) REP(i, 0, n)
#define FOR(e, o) for (auto &&e : o)
#ifdef LOCAL
#define pp(x) cerr << __LINE__ << ' ' << #x << " = " << (x) << endl
#define dump(x)                                                                \
  cerr << __LINE__ << ' ' << #x << " : ";                                      \
  FOR(e, x) cerr << e << ' ';                                                  \
  cerr << endl;
#else
#define pp(x)
#define dump(x)
#endif

using namespace std;

using Int = long long;
using vi = vector<Int>;
using vvi = vector<vi>;
using pii = pair<Int, Int>;

const Int dy[] = {-1, 0, 1, 0};
const Int dx[] = {0, 1, 0, -1};

template <typename T> void reverse(vector<T> &v) {
  reverse(v.begin(), v.end());
}
template <typename T> void sort(vector<T> &v) { sort(v.begin(), v.end()); }
template <typename T> void rsort(vector<T> &v) { sort(v.rbegin(), v.rend()); }
template <typename T> T sum(const vector<T> &v) {
  return accumulate(v.begin(), v.end(), T(0));
}
template <class T> void update_max(T &a, const T &b) { a = max(a, b); }
template <class T> void update_min(T &a, const T &b) { a = min(a, b); }
vector<pair<char, Int>> merge_cont_char(const string &s) {
  vector<pair<char, Int>> ret;
  if (s.empty())
    return ret;
  ret.push_back(make_pair(s[0], 0));
  FOR(c, s) {
    if (ret.back().first == c)
      ret.back().second++;
    else
      ret.push_back(make_pair(c, 1));
  }
  return ret;
}

class Shakutori {
public:
  // 全体の範囲
  // [0, end)
  // 注目している範囲
  // [tail, head)
  Int head, tail, end = 0;
  bool moveHead() {
    if (head == end) {
      return false;
    }
    head++;
    return true;
  }
  void moveTail() { tail++; }
  bool valid() {
    if (head == tail)
      return true;
    // [tail, head)
    // が解として適当か検証する
    return true;
  }
  void solve() {
    head = tail = 0;
    Int ans = 0;
    while (moveHead()) {
      while (!valid()) {
        moveTail();
      }
      // ここで解を更新する
    }
  }
};

class Solver {
public:
  Int ans = 0, N;
  vi L;
  Solver() {}
  void input() {
    cin >> N;
    L = vi(N);
    FOR(l, L)cin >> l;
  }
  void solve() {
    sort(L);
    map<Int, Int> num;
    FOR(l, L)num[l]++;
    rep(i, N){
      REP(j, i+1, N){
        ans += upper_bound(L.begin(), L.end(), L[i] + L[j]-1) - upper_bound(L.begin(), L.end(), L[j]);
      }
    }
  }
  void output() {
    cout << ans <<endl;
  }
};

void initilization() {
  struct BoolName : numpunct<char> {
    string t, f;
    BoolName(string t = "Yes", string f = "No") : t(t), f(f) {}
    string do_truename() const { return t; }
    string do_falsename() const { return f; }
  };
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(15) << boolalpha;
  cout.imbue(locale(cout.getloc(), new BoolName));
}

int main() {
  initilization();
#ifdef LOCAL
  while (1) {
    Solver s;
    s.input();
    if (cin.eof())
      break;
    s.solve();
    s.output();
  }
#else
  Solver s;
  s.input();
  s.solve();
  s.output();
#endif
  return 0;
}
