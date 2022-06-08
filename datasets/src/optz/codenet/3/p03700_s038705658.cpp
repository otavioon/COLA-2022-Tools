#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

typedef int64_t ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);

bool can_exterminate(const vector<ll>& h, const ll& n, const ll& a, const ll& b) {
  ll ext = a - b;
  ll nn = n;
  rep(i, h.size()) {
    ll rem = h[i] - b * n;
    if (rem > 0) {
      nn -= (rem + ext - 1) / ext;
    }
    if (nn < 0) return false;
  }
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> h(n);
  rep(i, n) cin >> h[i];
  sort(ALL(h), greater<ll>());

  ll lb = 0;
  ll ub = 1e+9;

  while (ub - lb > 1) {
    ll mid = lb + (ub - lb) / 2;
    if (can_exterminate(h, mid, a, b)) ub = mid;
    else lb = mid;
  }

  cout << ub << endl;

  return 0;
}
