#include "bits/stdc++.h"

/*----------------------------------------------------------------*/

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)
#define bit(i, a) for (ll i = 0; i < (1LL << (a)); i++)
#define umap unordered_map
#define uset unordered_set
#define to_str to_string

/*----------------------------------------------------------------*/

using namespace std;
using ld = long double;
using vld = vector<ld>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using str = string;
using vstr = vector<str>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

/*----------------------------------------------------------------*/

template<class T> bool chmin(T a, T &b) { return a < b ? b = a, true : false; }
template<class T> bool chmax(T a, T &b) { return a > b ? b = a, true : false; }
template<class T> T min(vector<T> a) { return *min_element(all(a)); }
template<class T> T max(vector<T> a) { return *max_element(all(a)); }
template<class T> T sum(vector<T> a) { return accumulate(all(a), (T)0); }

/*----------------------------------------------------------------*/

constexpr ld PI = 3.141592653589793L;

/*----------------------------------------------------------------*/

ll gcd(ll n, ll m) { return m ? gcd(m, n % m) : n; }
ll lcm(ll n, ll m) { return n / gcd(n, m) * m; }
ll ctz(ll n) { ll ans = 0; for (; ~n & 1; n >>= 1) ans++; return ans; }
bool is_prime(ll n) {
    if (n == 1) return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
ll popcnt(ll n) {
    n = ((n & 0xaaaaaaaaaaaaaaaa) >> 1) + (n & 0x5555555555555555);
    n = ((n & 0xcccccccccccccccc) >> 2) + (n & 0x3333333333333333);
    n = ((n & 0xf0f0f0f0f0f0f0f0) >> 4) + (n & 0x0f0f0f0f0f0f0f0f);
    n = ((n & 0xff00ff00ff00ff00) >> 8) + (n & 0x00ff00ff00ff00ff);
    n = ((n & 0xffff0000ffff0000) >> 16) + (n & 0x0000ffff0000ffff);
    n = ((n & 0xffffffff00000000) >> 32) + (n & 0x00000000ffffffff);
    return n;
}
str zfill(str s, ll n) { return str(n - s.length(), '0') + s; }
bool is_pld(str s) { return s == str(rall(s)); }
ll to_ll(char c) { return (ll)c - '0'; }
ll to_ll(str s) {
    ll ans = 0;
    rep(i, 0, (ll)s.length())
        ans = 10 * ans + to_ll(s[i]);
    return ans;
}

/*----------------------------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(15);

    ll n, a, b;
    cin >> n >> a >> b;
    vll h(n);
    rep(i, 0, n)
        cin >> h[i];

    auto f = [=](ll k) {
        ll tmp = 0;
        rep(i, 0, n) {
            ll rem = h[i] - b * k;
            if (rem > 0)
                tmp += (rem + (a - b) - 1) / (a - b);
        }
        return tmp <= k;
    };

    ll ok = 1e9, ng = 0;
    while (llabs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (f(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << '\n';
}
