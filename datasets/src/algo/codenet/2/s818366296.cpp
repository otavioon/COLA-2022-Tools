#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  multiset<int> w;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    w.insert(x);
  }
  int res = 0;
  while (!w.empty()) {
    auto it = w.end();
    --it;
    int x = *it;
    w.erase(it);
    int pw = 1;
    while (pw <= x) pw *= 2;
    if (w.count(pw - x)) {
      ++res;
      w.erase(w.find(pw - x));
    }
  }
  cout << res << endl;
  return 0;
}