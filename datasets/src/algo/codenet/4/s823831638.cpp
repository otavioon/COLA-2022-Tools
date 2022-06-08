#include <bits/stdc++.h>
using namespace std;

// エイリアス
using  ll = long signed long;
using ull = long unsigned long;
using  ld = long double;
using   P = pair<int, int>;
using llP = pair<ll, ll>;
using DoP = pair<double, double>;

// 汎用マクロ
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOREACH(i,q) for (auto &i : q)
#define UNIQUE(v) do { sort((v).begin(), (v).end()); (v).erase(unique((v).begin(), (v).end()), (v).end()); } while (false)
#define SZ(x) ((int)(x).size())
template <class T>inline bool chmin(T &a, const T b) {if (a > b) { a = b; return true;} return false;}
template <class T>inline bool chmax(T &a, const T b) {if (a < b) { a = b; return true;} return false;}
template <class T>inline void line_out(const vector<T> vec) {int n = SZ(vec); rep(i, n) { cout << vec[i]; if(i < n-1) cout << " ";}cout << endl;}
const int di[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dj[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int INF = 1 << 28;
const ll INF64 = 1ll << 60;
const int mod = 1000000007;
//const int mod = 998244353;
struct mint
{
  ll x; // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint &operator+=(const mint a)
  {
    if ((x += a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator-=(const mint a)
  {
    if ((x += mod - a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator*=(const mint a)
  {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const
  {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const
  {
    mint res(*this);
    return res -= a;
  }
  mint &operator++()
  {
    if ((x += 1) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator--()
  {
    if ((x += mod - 1) >= mod)
      x -= mod;
    return *this;
  }
  mint operator*(const mint a) const
  {
    mint res(*this);
    return res *= a;
  }
  mint pow(ll t) const
  {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const
  {
    return pow(mod - 2);
  }
  mint &operator/=(const mint a)
  {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const
  {
    mint res(*this);
    return res /= a;
  }
};

int main()
{
  int n, k; cin >> n >> k;
  set<char> d;
  rep(i, k) {
    int x; cin >> x;
    d.insert('0'+x);
  }

  for(int i = n; i <= 10*n; ++i) {
    string s = to_string(i);
    bool ok = true;
    for(auto c : s) {
      if(d.find(c) != d.end()) ok = false;
    }
    if(ok) {
      cout << i << endl;
      return 0;
    }
  }
}
