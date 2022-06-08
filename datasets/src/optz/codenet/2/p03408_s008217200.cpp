#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll = int64_t;
#define int ll

#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define REP(i, b) FOR(i, 0, b)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(x) x.begin(), x.end()

using pi = pair<int, int>;
using vi = vector<int>;
using ld = long double;

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  REP(i, (int)v.size()) {
    if (i) os << ",";
    os << v[i];
  }
  os << "}";
  return os;
}

ll read() {
  ll i;
  scanf("%" SCNd64, &i);
  return i;
}

void printSpace() { printf(" "); }

void printEoln() { printf("\n"); }

void print(ll x, int suc = 1) {
  printf("%" PRId64, x);
  if (suc == 1) printEoln();
  if (suc == 2) printSpace();
}

string readString() {
  static char buf[3341000];
  scanf("%s", buf);
  return string(buf);
}

char *readCharArray() {
  static char buf[3341000];
  static int bufUsed = 0;
  char *ret = buf + bufUsed;
  scanf("%s", ret);
  bufUsed += strlen(ret) + 1;
  return ret;
}

template <class T, class U>
void chmax(T &a, U b) {
  if (a < b) a = b;
}

template <class T, class U>
void chmin(T &a, U b) {
  if (b < a) a = b;
}

template <class T>
T Sq(const T &t) {
  return t * t;
}

const int mod = 1e9 + 7;

signed main() {
  int n = read();
  map<string, int> s;
  REP(i, n) {
    string tmp = readString();
    s[tmp] += 1;
  }
  int m = read();
  REP(i, m) {
    string tmp = readString();
    s[tmp] -= 1;
  }
  int ans = 0;
  for (auto p : s) {
    chmax(ans, p.second);
  }
  print(ans);
}
