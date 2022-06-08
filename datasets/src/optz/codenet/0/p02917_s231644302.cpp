#pragma region header
#include <bits/stdc++.h>
#define int long long
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define mp make_pair
#define rep1(i, n) for (decltype(+n) i = 0; i < (n); i++)
#define rrep1(i, n) for (auto i = n - 1; i > static_cast<decltype(i)>(-1); i--)
#define rep2(i, a, b) for (auto i = (a); i < (b); i++)
#define rrep2(i, a, b) for (auto i = b - 1; i >= a; i--)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep2, rep1) (__VA_ARGS__)
#define rrep(...) GET_MACRO(__VA_ARGS__, rrep2, rrep1) (__VA_ARGS__)
#define each(i, a) for (auto &&i : (a))
using namespace std;

using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vvs = vector<vs>;
using vd = vector<ld>;
using vvd = vector<vd>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;
using vp = vector<pii>;
using vvp = vector<vp>;
using mii = map<int, int>;
using vm = vector<mii>;
using vvm = vector<vm>;
template <class T, class U>
using umap = unordered_map<T, U>;
using umii = umap<int, int>;
using seti = set<int>;
template <class T>
using uset = unordered_set<T>;
using useti = uset<int>;
template <class T>
using less_queue = priority_queue<T>;
template <class T>
using greater_queue = priority_queue<T, vector<T>, greater<T>>;
using int128 = __int128_t;

ostream &operator<<(ostream &dest, int128 value) {
  ostream::sentry s(dest);
  if (s) {
    int128 tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(ios_base::badbit);
    }
  }
  return dest;
}

const int INF = 1e18;
const ld EPS = 1e-10;

template <class T>
void SORT(T &a) { stable_sort(all(a)); }
template <class T>
void RSORT(T &a) { stable_sort(rall(a)); }
template <class T>
void rev(T &a) { reverse(all(a)); }
template <class T>
void uniq(T &a) { a.erase(unique(all(a)), end(a)); }
template <class T>
auto min_of(const T &a) { return *min_element(all(a)); }
template <class T>
auto max_of(const T &a) { return *max_element(all(a)); }
template <class T>
T sum_of(const vector<T> &a) { return accumulate(all(a), (T)0); }
template <class T, class U>
int count_of(const T &a, const U &i) { return count(all(a), i); }
template <class T>
bool has(const vector<T> &a, const T &i) { return find(all(a), i) != a.end(); }
bool has(const string &a, const char &i) { return find(all(a), i) != a.end(); }
template <class T>
bool has(const set<T> &a, const T &i) { return a.find(i) != a.end(); }
template <class T>
int sz(const T &a) { return a.size(); };

template <class T>
void COUT(const T &x) { cout << x << endl; }
template <class T, class U>
void COUT(const T &x, const U &y) { cout << x << ' ' << y << endl; }
template <class T, class U, class V>
void COUT(const T &x, const U &y, const V &z) { cout << x << ' ' << y << ' ' << z << endl; }
template <class T>
void CSP(const T &x) { cout << x << ' '; }
template <class T>
void CVEC(const T &v) {
  int c = v.size() - 1;
  for (int i = 0; i < c; i++) cout << v[i] << ' ';
  if (c > -1) cout << v[c];
  cout << endl;
}

template <class T>
bool amin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool amax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

constexpr int lshift(const int &x) noexcept { return 1ll << x; }
constexpr int popcount(const unsigned int &x) noexcept { return __builtin_popcountll(x); }
constexpr int least1(const unsigned int &x) noexcept { return __builtin_ffsll(x); }
constexpr int ceil_div(const int &x, const int &y) noexcept { return (x + y - 1) / y; }

#pragma endregion header

// no MOD


void solve(int n, vi b) {
  int ans = 0;
  rep(i, n)ans += min(b[i], b[i + 1]);
  COUT(ans);
}


#pragma region main
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(15);

  int n;
  cin >> n;
  vi b(n + 1, INF);
  for(int i = 1 ; i < n ; i++){
    cin >> b[i];
  }
  solve(n, move(b));
}
#pragma endregion main
