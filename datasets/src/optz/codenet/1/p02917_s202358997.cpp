#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
const int inf = 1e9 + 7;
const ll INF = 1e18;
const int mod = 1000000007;
#define abs(x) (x >= 0 ? x : -(x))
#define lb(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define ub(v, x) (int)(upper_bound(all(v), x) - v.begin())
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> T pow(T a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
ll modpow(ll a, ll b, ll _mod) { return b ? modpow(a * a % _mod, b / 2, _mod) * (b % 2 ? a : 1) % _mod : 1; }
template<class T> ostream& operator << (ostream& os, const vector<T>& vec) { for (auto &vi: vec) os << vi << " "; return os; }
template<class T, class U> ostream& operator << (ostream& os, const pair<T, U>& p) { os << p.F << " " << p.S; return os; }
template<typename T >inline istream& operator >> (istream& is, vector<T>& v) { rep(j, sz(v)) is >> v[j]; return is; }
template<class T> inline void add(T &a, int b) { a += b; if (a >= mod) a -= mod; }


void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(10);

    int T;
    // cin >> T;
    T = 1;

    while (T--) {
        solve();
    }
}


void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n - 1);
  cin >> b;

  a[0] = b[0];
  a[n - 1] = b[n - 2];
  rep3(i, 1, n - 1) {
    a[i] = min(b[i], b[i - 1]);
  }
  // cout << a << endl;
  cout << accumulate(all(a), 0) << endl;
}
