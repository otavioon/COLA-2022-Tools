// {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <numeric>
#include <complex>
#include <utility>
#include <type_traits>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for(ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define FORR(i, a, b) for(ll i = static_cast<ll>(a); i >= static_cast<ll>(b); --i)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;

using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using IP = pair<int, P>;
using LLP = pair<ll, LP>;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

constexpr int INF = 100000000;
constexpr ll LINF = 10000000000000000ll;
constexpr int MOD = static_cast<int>(1e9 + 7);
constexpr double EPS = 1e-9;

// {{{ popcount
static int popcount(int x) {
    return __builtin_popcount(static_cast<unsigned int>(x));
}
static int popcount(unsigned int x) {
    return __builtin_popcount(x);
}
static int popcount(long x) {
    return __builtin_popcountl(static_cast<unsigned long>(x));
}
static int popcount(unsigned long x) {
    return __builtin_popcountl(x);
}
static int popcount(long long x) {
    return __builtin_popcountll(static_cast<unsigned long long>(x));
}
static int popcount(unsigned long long x) {
    return __builtin_popcountll(x);
}
// }}}

// template specialization of std::hash for std::pair
namespace std {
template<typename T, typename U>
struct hash<pair<T, U> > {
    size_t operator()(const pair<T, U> &key) const noexcept {
        size_t h1 = hash<T>()(key.first);
        size_t h2 = hash<U>()(key.second);
        return h1 ^ (h2 << 1);
    }
};
} // namespace std

// print vector
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    size_t sz = v.size();
    os << "[";
    for (size_t i = 0; i < sz-1; i++) {
        os << v[i] << ", ";
    }
    os << v[sz-1] <<  "]";
    return os;
}

// print array (except char literal)
template<
    typename T,
    int N,
    typename std::enable_if<!std::is_same<T, char>::value, std::nullptr_t>::type = nullptr>
ostream &operator<<(ostream &os, const T (&v)[N]) {
    os << "[";
    for (size_t i = 0; i < N-1; i++) {
        os << v[i] << ", ";
    }
    os << v[N-1] <<  "]";
    return os;
}

// print array
template<typename T>
void printArray(T *arr, size_t sz) {
    cerr << "[";
    for (size_t i = 0; i < sz-1; i++) {
        cerr << arr[i] << ",";
    }
    cerr << arr[sz-1] <<  "]" << endl;
}

// print pair
template<typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "(" << p.first << ", " << p.se << ")";
    return os;
}

static inline ll mod(ll x, ll m)
{
    ll y = x % m;
    return (y >= 0 ? y : y+m);
}

struct Compare {
    //vector<ll> &x_, &y_;
    //Compare(vector<ll> &x, vector<ll> &y): x_(x), y_(y) {}
    //bool operator()(const P &lhs, const P &rhs) {
    //    return x_[lhs.fi]+y_[lhs.se] < x_[rhs.fi]+y_[rhs.se];
    //}
    bool operator()(const int x, const int y) {
        return x < y;
    }
};

// print floating-point number
// cout << fixed << setprecision(12) <<

// }}}

int N;
ll a[100010], b[100010], c[100010];

int small(ll *arr, int n, ll val) {
    int l = 0, u = n;
    while (u-l > 1) {
        //cout << l << ":" << u << endl;
        int mid = (l + u) / 2;
        if (arr[mid] < val) {
            l = mid;
        } else {
            u = mid;
        }
    }
    return l;
}

int large(ll *arr, int n, ll val) {
    int l = -1, u = n-1;
    while (u-l > 1) {
        int mid = (l + u) / 2;
        //cout << l << "!" << u << "!" << mid << "!" << val << endl;
        if (arr[mid] <= val) {
            l = mid;
        } else {
            u = mid;
        }
    }
    return u;
}

void solve()
{
    int ret = 0;
    sort(a, a+N);
    sort(b, b+N);
    sort(c, c+N);
    REP (i, N) {
        int s = small(a, N, b[i]);
        int l = large(c, N, b[i]);
        //cout << b[i] << " " << s << " " << l << endl;
        ret += (s+1) * (N-l);
    }
    cout << ret << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP (i, N) cin >> a[i];
    REP (i, N) cin >> b[i];
    REP (i, N) cin >> c[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
