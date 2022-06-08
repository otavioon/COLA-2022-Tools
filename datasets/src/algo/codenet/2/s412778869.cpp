#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define FOR(it, c) \
  for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

int main() {
  int N;
  cin >> N;
  multiset<int> m;
  rep(i, N) {
    int a;
    cin >> a;
    m.insert(a);
  }

  int ret = 0;

  while (!m.empty()) {
    int x = *(m.rbegin());
    m.erase(x);

    ll p = 1;
    while (p < x) p *= 2;
    int y = p - x;

    if (m.find(y) != m.end()) {
      m.erase(y);
      ret++;
    }
  }

  cout << ret << endl;

  return 0;
}
