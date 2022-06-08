#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define ALL(a) (a).begin(), (a).end()

template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using DoP = pair<double, double>;
using edge = struct { int to; ll cost; }; // edge x = {to, cost}

const int di[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dj[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int INF = INT_MAX;
const ll INF64 = 1ll << 40;
const int mod = 1000000007;

struct Sieve
{
  int n;
  vector<int> f, primes;
  Sieve(int n = 1) : n(n), f(n + 1)
  {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i)
    {
      if (f[i])
        continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i * i; j <= n; j += i)
      {
        if (!f[j])
          f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x; }
  vector<int> factorList(int x)
  {
    vector<int> res;
    while (x != 1)
    {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x)
  {
    vector<int> fl = factorList(x);
    if (fl.size() == 0)
      return {};
    vector<P> res(1, P(fl[0], 0));
    for (int p : fl)
    {
      if (res.back().first == p)
      {
        res.back().second++;
      }
      else
      {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
};
struct UnionFind
{
  vector<int> par;
  vector<int> siz;
  UnionFind(int N) : par(N), siz(N, 1) {for (int i = 0; i < N; i++) par[i] = i;}
  
  void init(int N) {
    siz.assign(N, 1);
    par.resize(N);
    for(int i = 0; i < N; ++i) par[i] = i;
  }

  int root(int x) {
    while(par[x] != x) {x = par[x] = par[par[x]];}
    return x;
  }

  bool unite(int x, int y)
  {
    x = root(x);
    y = root(y);
    if(x == y) return false;

    if(siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    return true;

  }

  bool isSame(int x, int y) {return root(x) == root(y); }

  int size(int x) { return siz[root(x)]; }
};
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
// h(n, r) = c(n+r-1, r)
struct combination
{
  vector<mint> fact, ifact;
  combination(int n) : fact(n + 1), ifact(n + 1)
  {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
      fact[i] = fact[i - 1] * i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i)
      ifact[i - 1] = ifact[i] * i;
  }
  mint operator()(int n, int k)
  {
    if (k < 0 || k > n)
      return 0;
    return fact[n] * ifact[k] * ifact[n - k];
  }
};

ll modpow(ll a, ll n) {
  ll res = 1;
  while (n > 0) {
      if (n & 1) res = res * a % mod;
      a = a * a % mod;
      n >>= 1;
  }
  return res;
}

int main(){
  int n, k;
  cin >> n >> k;
  vector<bool> d(10, true);
  rep(i, k) {
    int x;
    cin >> x;
    d[x] = false;
  }
  for(int i = n; i < 10*n; ++i) {
    string s = to_string(i);
    bool ok = true;
    rep(j, s.size()) if(!d[s[j]-'0']) ok = false;
    if(ok) {
      cout << i << endl;
      return 0;
    }
  }
}