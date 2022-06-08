#include <bits/stdc++.h>
#define FOR(i, m, n) for (int i = m; i < (n); i++)
#define RFOR(i, m, n) for (int i = (m - 1); i >= 0; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, n, 0)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

int main() {
  int n;
  cin >> n;
  int a[n];
  REP(i, n) { cin >> a[i]; }
  int count = 1;
  int number = 1;
  while (count <= n) {
    if (a[number - 1] == 2) {
      break;
    }
    number = a[number - 1];
    count++;
  }
  if (count > n) {
    cout << -1 << endl;
    return 0;
  }
  cout << count << endl;
  return 0;
}