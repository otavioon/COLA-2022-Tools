#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using Graph = vector<vector<int>>;
#define int ll
#define double long double
void YN(bool flg) {cout<<(flg?"YES":"NO")<<'\n';}
void Yn(bool flg) {cout<<(flg?"Yes":"No")<<'\n';}
void yn(bool flg) {cout<<(flg?"yes":"no")<<'\n';}
#define SORT(a) sort(a.begin(),a.end())
#define REVERSE(a) reverse(a.begin(),a.end())
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define out(n) cout << n << '\n'
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<VI> VVI;
const int MOD = 1000000007;
const long long INF = 10e10;
const double PI = acos(-1.0);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T>auto MAX(const T& a) { return *max_element(a.begin(),a.end()); }
template<class T>auto MIN(const T& a) { return *min_element(a.begin(),a.end()); }
template<class T, class U>U SUM(const T& a, const U& v) { return accumulate(a.begin(),a.end(), v); }
template<class T, class U>U COUNT(const T& a, const U& v) { return count(a.begin(),a.end(), v); }
template<class T, class U>int LOWER(const T& a, const U& v) { return lower_bound(a.begin(),a.end(), v) - a.begin(); }
template<class T, class U>int UPPER(const T& a, const U& v) { return upper_bound(a.begin(),a.end(), v) - a.begin(); }
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }
int LCM(int a, int b) { int g = GCD(a, b); return a / g * b; }
int POW(int a, int n) { int r = 1; while (n > 0) { if (n & 1)r *= a; a *= a; n >>= 1; }return r; }
int isPrime(int n){if(n<2){return 0;}for(int i=2; i*i<=n; i++){if(n%i==0){return 0;}}return 1;}
/*素因数分解*/map< int, int >prime_factor(int n){map< int, int > ret;for(int i = 2; i * i <= n; i++) {while(n % i == 0) {ret[i]++;n /= i;}}if(n != 1) ret[n] = 1;return ret;}
/*約数列挙*/vector<int> divisor(int n){vector<int> v; for(int i=1; i*i<=n; i++){if(n%i==0){v.push_back(i);if(i!=n/i){v.push_back(n/i);}}}sort(v.begin(),v.end()); return v;}
template< int mod >struct ModInt {int x;ModInt() : x(0) {}ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}ModInt &operator+=(const ModInt &p) {if((x += p.x) >= mod) x -= mod;return *this;}ModInt &operator-=(const ModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return *this;}ModInt &operator*=(const ModInt &p) {x = (int) (1LL * x * p.x % mod);return *this;}ModInt &operator/=(const ModInt &p) {*this *= p.inverse();return *this;}ModInt operator-() const { return ModInt(-x); }ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }bool operator==(const ModInt &p) const { return x == p.x; }bool operator!=(const ModInt &p) const { return x != p.x; }ModInt inverse() const {int a = x, b = mod, u = 1, v = 0, t;while(b > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);}return ModInt(u);}ModInt pow(int64_t n) const {ModInt ret(1), mul(x);while(n > 0) {if(n & 1) ret *= mul;mul *= mul;n >>= 1;}return ret;}friend ostream &operator<<(ostream &os, const ModInt &p) {return os << p.x;}friend istream &operator>>(istream &is, ModInt &a) {int64_t t;is >> t;a = ModInt< mod >(t);return (is);}static int get_mod() { return mod; }};
using modint = ModInt< MOD >;

//----------------ライブラリとか----------------

int n,a,b;
VI h;

bool f(int k){
    int tmp = 0; //中心の爆発回数
    for(int i=0; i<n; i++){
        int rem = h[i]-b*k; //(a-b)tmp
        if(rem > 0) tmp += (rem+(a-b-1)) / (a-b);
    }
    return (tmp <= k);
}

int binary_search(int ok, int ng){
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if(f(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(15);

    cin >> n >> a >> b;
    h = VI(n); REP(i,n) cin >> h[i];
    out(binary_search(INF,0));

    return 0;
}