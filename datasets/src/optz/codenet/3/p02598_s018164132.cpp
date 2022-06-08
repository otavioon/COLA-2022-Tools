#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <utility>
#include <cctype>
#include <iterator>
////////////////////////////////////////////////
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define FOR(i, m, n) for (int i = (int)m; i < (int)n; i++)
#define REPvec(itr, mp) for (auto itr = mp.begin(); itr != mp.end(); itr++)
#define REPe(e, mp) for (auto& e : mp)
#define all(x) x.begin(), x.end()
#define MOD 1000000007  // 1e9+7
using namespace std;
using ll = long long int;
using vecint = vector<int>;
using vecll = vector<ll>;
using vec2int = vector<vector<int>>;
using P = pair<int, int>;
////////////////////////////////////////////////
int main() {
  ////////////////////////////////////////////////
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ////////////////////////////////////////////////
  int n;
  ll k;
  cin >> n >> k;
  vecll a(n);
  REPe(e, a) cin >> e;
  sort(all(a));
  ll r = a.back();
  ll l = 1;
  // cout << a.back() << endl;
  auto check = [&](ll x) {
    ll num = 0;
    REPe(e, a) {
      if(e != x){
	      num += e / x;
      }
    }
    if (num > k) {
      return false;
    } else {
      return true;
    }
  };

  if (check(l)) {
    cout << l << endl;
    return 0;
  }
  while (r - l > 1) {
    ll c = (r + l) / 2;
    if (check(c)) {
      r = c;
    } else {
      l = c;
    }
  }
  cout << r << endl;
}
