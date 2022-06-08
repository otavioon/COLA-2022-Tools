#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
#include<stack>
#include<cstdio>
#include<cstring>
#include<bitset>
#include<unordered_map>
#include<climits>
#include<fstream>
#include<complex>
#include<time.h>
#include<cassert>
#include<functional>
#include<numeric>
#include<tuple>
using namespace std;
using ll = long long;
using ld = long double;
#define int long long
#define all(a) (a).begin(),(a).end()
#define fs first
#define sc second
#define xx first
#define yy second.first
#define zz second.second
#define H pair<int, int>
#define P pair<int, pair<int, int>>
#define Q(i,j,k) mkp(i,mkp(j,k))
#define rng(i,s,n) for(int i = (s) ; i < (n) ; i++)
#define rep(i,n) rng(i, 0, (n))
#define mkp make_pair
#define vec vector
#define vi vec<int>
#define pb emplace_back
#define siz(a) (int)(a).size()
#define crdcomp(b) sort(all((b)));(b).erase(unique(all((b))),(b).end())
#define getidx(b,i) (lower_bound(all(b),(i))-(b).begin())
#define ssp(i,n) (i==(int)(n)-1?"\n":" ")
#define ctoi(c) (int)(c-'0')
#define itoc(c) (char)(c+'0')
#define cyes printf("Yes\n")
#define cno printf("No\n")
#define cdf(n) int quetimes_=(n);rep(qq123_,quetimes_)
#define gcj printf("Case #%lld: ",qq123_+1)
#define readv(a,n) a.resize(n,0);rep(i,(n)) a[i]=read()
#define found(a,x) (a.find(x)!=a.end())
//#define endl "\n"
constexpr int mod = (ll)1e9 + 7;
constexpr int Mod = 998244353;
constexpr ld EPS = 1e-10;
constexpr ll inf = (ll)3 * 1e18;
constexpr int Inf = (ll)15 * 1e8;
constexpr int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
ll read() { ll u, k = scanf("%lld", &u); return u; }
string reads() { string s; cin >> s; return s; }
H readh(short g = 0) { H u; int k = scanf("%lld %lld", &u.fs, &u.sc); if (g == 1) u.fs--, u.sc--; if (g == 2) u.fs--; return u; }
bool ina(H t, int h, int w) { return 0 <= t.fs && t.fs < h && 0 <= t.sc && t.sc < w; }
bool ina(int t, int l, int r) { return l <= t && t < r; }
ll gcd(ll i, ll j) { return j ? gcd(j, i % j) : i; }
ll popcount(ll x) {
    int sum = 0; for (int i = 0; i < 60; i++)if ((1ll << i) & x) sum++;
    return sum;
}
template<typename T>
class csum {
    vec<T> v;
public:
    csum(vec<T>& a) :v(a) { build(); }
    csum() {}
    void init(vec<T>& a) { v = a; build(); }
    void build() {
        for (int i = 1; i < v.size(); i++) v[i] += v[i - 1];
    }
    T a(int l, int r) {
        if (r < l) return 0;
        return v[r] - (l == 0 ? 0 : v[l - 1]);
    }//[l,r]
    T b(int l, int r) {
        return a(l, r - 1);
    }//[l,r)
    T a(pair<int, int>t) {
        return a(t.first, t.second);
    }
    T b(pair<int, int>t) {
        return b(t.first, t.second);
    }
};
class mint {
public:ll v;
      mint(ll v = 0) { s(v % mod + mod); }
      constexpr static int mod = (ll)1e9 + 7;
      constexpr static int fn_ = (ll)2e6 + 5;
      static mint fact[fn_], comp[fn_];
      mint pow(int x) const {
          mint b(v), c(1);
          while (x) {
              if (x & 1) c *= b;
              b *= b;
              x >>= 1;
          }
          return c;
      }
      inline mint& s(int vv) {
          v = vv < mod ? vv : vv - mod;
          return *this;
      }
      inline mint inv()const { return pow(mod - 2); }
      inline mint operator-()const { return mint() - *this; }
      inline mint& operator+=(const mint b) { return s(v + b.v); }
      inline mint& operator-=(const mint b) { return s(v + mod - b.v); }
      inline mint& operator*=(const mint b) { v = v * b.v % mod; return *this; }
      inline mint& operator/=(const mint b) { v = v * b.inv().v % mod; return *this; }
      inline mint operator+(const mint b) const { return mint(v) += b; }
      inline mint operator-(const mint b) const { return mint(v) -= b; }
      inline mint operator*(const mint b) const { return mint(v) *= b; }
      inline mint operator/(const mint b) const { return mint(v) /= b; }
      friend ostream& operator<<(ostream& os, const mint& m) {
          return os << m.v;
      }
      friend istream& operator>>(istream& is, mint& m) {
          int x; is >> x; m = mint(x);
          return is;
      }
      bool operator<(const mint& r)const { return v < r.v; }
      bool operator>(const mint& r)const { return v > r.v; }
      bool operator<=(const mint& r)const { return v <= r.v; }
      bool operator>=(const mint& r)const { return v >= r.v; }
      bool operator==(const mint& r)const { return v == r.v; }
      bool operator!=(const mint& r)const { return v != r.v; }
      explicit operator bool()const { return v; }
      explicit operator int()const { return v; }
      mint comb(mint k) {
          if (k > * this) return mint();
          if (!fact[0]) combinit();
          if (v >= fn_) {
              if (k > * this - k) k = *this - k;
              mint tmp(1);
              for (int i = v; i >= v - k.v + 1; i--) tmp *= mint(i);
              return tmp * comp[k.v];
          }
          return fact[v] * comp[k.v] * comp[v - k.v];
      }//nCk
      mint perm(mint k) {
          if (k > * this) return mint();
          if (!fact[0]) combinit();
          if (v >= fn_) {
              mint tmp(1);
              for (int i = v; i >= v - k.v + 1; i--) tmp *= mint(i);
              return tmp;
          }
          return fact[v] * comp[v - k.v];
      }//nPk
      static void combinit() {
          fact[0] = 1;
          for (int i = 1; i < fn_; i++) fact[i] = fact[i - 1] * mint(i);
          comp[fn_ - 1] = fact[fn_ - 1].inv();
          for (int i = fn_ - 2; i >= 0; i--) comp[i] = comp[i + 1] * mint(i + 1);
      }
}; mint mint::fact[fn_], mint::comp[fn_];
//--------------------------------------------------------------


//---------------------------------------------------------------------



signed main() {
    int n, d; cin >> n >> d;
    cout << (n + 2 * d) / (2 * d+1) << endl;
}