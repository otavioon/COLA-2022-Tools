#include <cstdio>
#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <tuple>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <iterator>
#include <regex>

#define REP(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define FOR(x,xs) for(auto &x: xs)

using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef pair<ll,ll> PL;
typedef vector<int> VI;
typedef vector<ll> VL;

template <class T, template <class, class> class C, class charT = char>
void vdump(const C<T, allocator<T>> &v, const charT* delimiter = ", ",
           ostream &stream = cout) {
  copy(v.begin(), v.end(), ostream_iterator<T>(stream, delimiter));
  stream << endl;
}

ll next_power(ll x) {
  ll pow = 1;
  while (pow <= x) {
    pow *= 2;
  }
  return pow;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  multiset<ll, greater<ll>> balls;
  REP(i,0,n) {
    ll a;
    cin >> a;
    balls.emplace(a);
  }
  ll ans = 0;
  while (! balls.empty()) {
    auto max_it = balls.begin();
    ll max_b = *max_it;
    balls.erase(max_it);
    ll sum = next_power(max_b);
    auto opponent = balls.find(sum - max_b);
    if (opponent != balls.end()) {
      ans++;
      balls.erase(opponent);
    }
  }
  cout << ans << endl;

  return 0;
}
