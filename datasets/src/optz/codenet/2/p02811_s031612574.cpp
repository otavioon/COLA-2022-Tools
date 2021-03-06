/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author aajisaka
 */

#include<bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define SPEED ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using ll = long long;
using P = pair<ll, ll>;

constexpr long double PI = 3.14159265358979323846264338327950288L;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

class A500YenCoins {
public:
    void solve(istream& cin, ostream& cout) {
      SPEED;
      int k, x; cin >> k >> x;
      if (k*500 >= x) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
};

signed main() {
  A500YenCoins solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}