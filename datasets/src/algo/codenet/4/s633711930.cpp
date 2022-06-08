// https://atcoder.jp/contests/

#include <bits/stdc++.h>
#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define REPR(i, n) for (int(i) = (n); (i) >= 0; (i)--)
#define FOR(i, m, n) for (int(i) = (m); (i) < (n); i++)
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;

bool in(int n, set<int> &d)
{
  while (0 < n)
  {
    if (0 < d.count(n % 10))
      return false;
    n /= 10;
  }
  return true;
}

int main()
{
  int n, k;
  cin >> n >> k;

  set<int> d;
  REP(i, k)
  {
    int di;
    cin >> di;
    d.insert(di);
  }

  while (!in(n, d))
  {
    n++;
  }

  cout << n << '\n';

  return 0;
}
