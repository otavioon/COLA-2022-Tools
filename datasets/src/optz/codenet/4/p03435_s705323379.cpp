#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

void yes() {
  cout << "Yes" << endl;
  exit(0);
}

void no() {
  cout << "No" << endl;
  exit(0);
}

int main() {
  vector<vector<ll>> c(3, vector<ll>(3));
  REP(i, 3) {
    REP(j, 3) { cin >> c[i][j]; }
  }
  bool ok = true;

  REP(j, 2) {
    set<ll> st;
    REP(i, 3) { st.insert(c[i][j + 1] - c[i][j]); }
    if (SZ(st) != 1) {
      no();
    }
  }

  REP(i, 2) {
    set<ll> st;
    REP(j, 3) { st.insert(c[i + 1][j] - c[i][j]); }
    if (SZ(st) != 1) {
      no();
    }
  }

  yes();
}