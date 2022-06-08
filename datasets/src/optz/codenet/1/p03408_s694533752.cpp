#include <bits/stdc++.h>
using namespace std;

//#define int long long
struct Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

/* cpp template {{{ */

/* short */
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define X real()
#define Y imag()

/* REPmacro */
#define REPS(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) REPS(i, 0, n)
#define REP0(i,n) for (ll i = 0; i <= (ll)(n); ++i)
#define REP1(i,n) for (ll i = 1; i <= (ll)(n); ++i)
#define RREP(i, n) REPS(i, 1, n + 1)
#define DEPS(i, a, n) for (ll i = (a); i >= (ll)(n); --i)
#define DEP(i, n) DEPS(i, n, 0)
#define EACH(i, n) for (auto&& i : n)

/* debug */
#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

/* alias */
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;
using D = double;
using P = complex<D>;
using vs = vector<string>;
template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

/* const */
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;
const D EPS = 1e-9;
const int dx[] = {0, 1, 0, -1, 1, -1, 1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

/* func */
inline bool inside(int y, int x, int H, int W) {return y >= 0 && x >= 0 && y < H && x < W;}
inline int in() {int x; cin >> x; return x;}
inline ll IN() {ll x; cin >> x; return x;}
inline vs split(const string& t, char c) {vs v; stringstream s(t); string b; while(getline(s, b, c)) v.eb(b); return v;}
template <typename T> inline bool chmin(T& a, const T& b) {if (a > b) a = b; return a > b;}
template <typename T> inline bool chmax(T& a, const T& b) {if (a < b) a = b; return a < b;}
template <typename T, typename S> inline void print(const pair<T, S>& p) {cout << p.first << " " << p.second << endl;}
template <typename T> inline void print(const T& x) {cout << x << '\n';}
template <typename T, typename S> inline void print(const vector<pair<T, S>>& v) {for (auto&& p : v) print(p);}
template <typename T> inline void print(const vector<T>& v, string s = " ") {rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");}
template<typename T>
istream& operator >> (istream& is, vector<T>& vec){
  for(T& x: vec) is >> x;
  //for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいいです。
  return is;
}
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec){
  for(int i=0; i<vec.size(); i++){
    os << vec[i] << ( i+1 == vec.size() ? "" : " " );
  }
  return os;
}
/* }}} */

signed main() 
{
  int n = in();
  string s[110];
  rep(i,n) cin >> s[i];
  int m = in();
  string t[110];
  rep(i,m) cin >> t[i];

  int ans=0;

  rep(i,n)
  {
    int score=0;
    rep(j,n) if(s[j]==s[i]) score++;
    rep(j,m) if(t[j]==t[i]) score--;
    ans=max(ans,score);
  }
  cout << ans << endl;
  return 0;
}