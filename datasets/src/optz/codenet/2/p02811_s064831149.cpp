#include <type_traits>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <queue>
#include <functional>
#include <numeric>
#include <cassert>
#include <climits>
#include <map>
#include <array>
#include <bitset>

using namespace std;

// tourist's modular-arithmetic class
template<typename T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a;
        swap(a, m);
        u -= t * v;
        swap(u, v);
    }
    assert(m == 1);
    return u;
}

template<typename T>
class Modular {
public:
    using Type = typename decay<decltype(T::value)>::type;

    constexpr Modular() : value() {}

    template<typename U>
    Modular(const U &x) {
        value = normalize(x);
    }

    template<typename U>
    static Type normalize(const U &x) {
        Type v;
        if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
        else v = static_cast<Type>(x % mod());
        if (v < 0) v += mod();
        return v;
    }

    const Type &operator()() const { return value; }

    template<typename U>
    explicit operator U() const { return static_cast<U>(value); }

    constexpr static Type mod() { return T::value; }

    Modular &operator+=(const Modular &other) {
        if ((value += other.value) >= mod()) value -= mod();
        return *this;
    }

    Modular &operator-=(const Modular &other) {
        if ((value -= other.value) < 0) value += mod();
        return *this;
    }

    template<typename U>
    Modular &operator+=(const U &other) { return *this += Modular(other); }

    template<typename U>
    Modular &operator-=(const U &other) { return *this -= Modular(other); }

    Modular &operator++() { return *this += 1; }

    Modular &operator--() { return *this -= 1; }

    Modular operator++(int) {
        Modular result(*this);
        *this += 1;
        return result;
    }

    Modular operator--(int) {
        Modular result(*this);
        *this -= 1;
        return result;
    }

    Modular operator-() const { return Modular(-value); }

    template<typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type &operator*=(const Modular &rhs) {
#ifdef _WIN32
        uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
        uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
        asm(
        "divl %4; \n\t"
        : "=a" (d), "=d" (m)
        : "d" (xh), "a" (xl), "r" (mod())
        );
        value = m;
#else
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
        return *this;
    }

    template<typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type &
    operator*=(const Modular &rhs) {
        int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }

    template<typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type &operator*=(const Modular &rhs) {
        value = normalize(value * rhs.value);
        return *this;
    }

    Modular &operator/=(const Modular &other) { return *this *= Modular(inverse(other.value, mod())); }

    template<typename U>
    friend const Modular<U> &abs(const Modular<U> &v) { return v; }

    template<typename U>
    friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

    template<typename U>
    friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);

    template<typename U>
    friend std::istream &operator>>(std::istream &stream, Modular<U> &number);

private:
    Type value;
};


template<typename T>
bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value == rhs.value; }

template<typename T, typename U>
bool operator==(const Modular<T> &lhs, U rhs) { return lhs == Modular<T>(rhs); }

template<typename T, typename U>
bool operator==(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) == rhs; }

template<typename T>
bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

template<typename T, typename U>
bool operator!=(const Modular<T> &lhs, U rhs) { return !(lhs == rhs); }

template<typename T, typename U>
bool operator!=(U lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

template<typename T>
bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value < rhs.value; }

template<typename T>
Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }

template<typename T, typename U>
Modular<T> operator+(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) += rhs; }

template<typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }

template<typename T>
Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }

template<typename T, typename U>
Modular<T> operator-(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) -= rhs; }

template<typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }

template<typename T>
Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }

template<typename T, typename U>
Modular<T> operator*(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) *= rhs; }

template<typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }

template<typename T>
Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> operator/(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T> &a, const U &b) {
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

template<typename T>
bool IsZero(const Modular<T> &number) {
    return number() == 0;
}

template<typename T>
string to_string(const Modular<T> &number) {
    return to_string(number());
}

template<typename T>
std::ostream &operator<<(std::ostream &stream, const Modular<T> &number) {
    return stream << number();
}

template<typename T>
std::istream &operator>>(std::istream &stream, Modular<T> &number) {
    typename common_type<typename Modular<T>::Type, int64_t>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}

struct fast_ios {
    fast_ios() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    };
} fast_ios_;

template<typename A, typename B>
bool chkmin(A &a, const B &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<typename A, typename B>
bool chkmax(A &a, const B &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

int cas;

ostream &kase() {
    return cout << "Case #" << ++cas << ": ";
}

template<typename T>
ostream &operator<<(ostream &stream, const vector<T> &vec) {
    if (!vec.empty()) {
        stream << vec[0];
        for (size_t i = 1; i != vec.size(); ++i)
            stream << ' ' << vec[i];
    }
    return stream;
}

template<typename T>
void print(const vector<T> &t) { cout << t << '\n'; }

template<typename T>
void print(const vector<vector<T>> &t) {
    for (const auto &row : t) {
        print(row);
    }
}

template<typename T>
void print(const T &t) { cout << t << ' '; }

template<typename T, typename ...Args>
void print(const T &t, const Args &...rest) {
    print(t);
    print(rest...);
}

template<typename T>
void println(const T &t) { cout << t << '\n'; }

template<typename T, typename ...Args>
void println(const T &t, const Args &...rest) {
    print(t);
    println(rest...);
}

template<typename T>
istream &operator>>(istream &stream, vector<T> &vec) {
    for (auto &x : vec) stream >> x;
    return stream;
}

void scan() {}

template<class T, class ...Args>
void scan(T &a, Args &...rest) {
    cin >> a;
    scan(rest...);
}

using ull = unsigned long long;
using ll = long long;
using ul = unsigned long;
using vl = vector<ll>;
using vi = vector<int>;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pip = pair<int, pii>;
using pll = pair<ll, ll>;
using vb = vector<bool>;
using vpii = vector<pii>;
using ldb = long double;

template<typename int_t>
inline int_t lowbit(int_t x) { return x & -x; }

#if __cplusplus < 201402L
template<class Iterator>
std::reverse_iterator<Iterator> make_reverse_iterator(Iterator it) {
    return std::reverse_iterator<Iterator>(it);
}
#endif

template<typename iter_t>
struct iter_pair {
    iter_t _beg, _end;

    iter_t begin() { return _beg; }

    iter_t end() { return _end; }
};

template<class cont>
iter_pair<reverse_iterator<decltype(begin(declval<cont>()))>>
reverse(cont &&r) {
    return {make_reverse_iterator(end(r)), make_reverse_iterator(begin(r))};
}

#define rng(i, a, b) for(int i = (int)(a); i < (int)(b); ++i)
#define up(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define down(i, b, a) for (int i = int(b); i >= int(a); i--)
#define rep(n) for(int _iter_##n = 0, _num_##n = (int)n; _iter_##n < _num_##n; ++_iter_##n)
#define FOR(x, cont) for (const auto &x: cont)
#define For(x, cont) for (auto &x: cont)
#define all(x) begin(x), end(x)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ep emplace
#define SZ(x) (int)(x).size()
template<typename T, typename Comp = less<T>>
using pq = priority_queue<T, vector<T>, Comp>;
#define popcnt(x) __builtin_popcountll((x))
#define UNIQ(vec) (vec).erase(unique(ALL(vec)), end(vec))
#define LB(cont, x) int(lower_bound(ALL(cont), x) - begin(cont))
#define UB(cont, x) int(upper_bound(ALL(cont), x) - begin(cont))
const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
const int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};
auto bet = [](const ll x, const ll y, const ll i) {
    return x <= i && i <= y;
};

template<typename T1, typename T2>
T1 ceil(T1 x, T2 y) { // y >= 1，是整数。需要注意 x + y - 1 是否会溢出
    return (x + y - 1) / y;
}

inline int h_bit(unsigned long long x) {
    return (int) sizeof(unsigned long long) * 8 - 1 - __builtin_clzll(x);
}

unsigned long long pow2(unsigned long long x) { // round up to power of 2
    return 1ull << (h_bit((ull) x) + (x != lowbit(x)));
}

template<typename T>
class BIT {
    vector<T> a;
    using BinOp = function<T(T, T)>;
    BinOp bin_op;
    const T init;
public:
    explicit BIT(int n, BinOp op = [](T x, T y) { return x + y; }, T init = T{})
            : bin_op(op), init(init), a(n + 1, init) {}

    T prefix(int x) const {
        auto res = init;
        while (x) {
            res = bin_op(a[x], res);
            x -= x & -x;
        }
        return res;
    }

    void modify(int x, T v) {
        while (x < (int) a.size()) {
            a[x] = bin_op(a[x], v);
            x += x & -x;
        }
    }

    void clear() {
        fill(a.begin(), a.end(), init);
    }
};

vi get_prime(int n) {
    vi minp((ul) n + 1), p;
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            minp[i] = i;
            p.pb(i);
        }
        FOR(x, p) {
            if (x <= minp[i] && x * i <= n)
                minp[x * i] = x;
            else break;
        }
    }
    return p;
}

// alias templates
template<typename T> using vv = vector<vector<T>>;
template<typename T1, typename T2 = T1> using vp = vector<pair<T1, T2>>;
template<typename T, int n> using va = vector<array<T, n>>;

//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
#ifdef __GNUC__

#include <ext/pb_ds/assoc_container.hpp>

template<typename T, typename comp = less<T>>
using order_set = __gnu_pbds::tree<
        T,
        __gnu_pbds::null_type,
        comp,
        __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update>;

#include <ext/pb_ds/trie_policy.hpp>

using trie = __gnu_pbds::trie<string, __gnu_pbds::null_type>;
#endif

//并查集
class UnionFind {
    vi par, sz;
    int nTree;
public:
    explicit UnionFind(int n) : par(n), sz(n, 1), nTree(n) { //0-indexed
        iota(par.begin(), par.end(), 0);
    }

    int n_tree() const {
        return nTree;
    }

    int size(int x) {
        return sz[root(x)];
    }

    int root(int x) {
        return x == par[x] ? x : par[x] = root(par[x]);
    }

    bool unite(int x, int y) {
        int rx = root(x), ry = root(y);
        if (rx != ry) {
            par[rx] = ry;
            --nTree;
            sz[ry] += sz[rx];
            return true;
        }
        return false;
    }
    bool is_root(int x) const {
        return par[x] == x;
    }
};

template<typename T, typename Compare = std::less<T>>
struct SparseTable {
    size_t n{}; // 0-indexed
    vv<T> a;

    template<typename ptr_t>
    SparseTable(ptr_t beg, ptr_t end):n(end - beg) {
        a.resize((size_t) h_bit(n) + 1); // 注意：不能写成 h_bit(n)
        a[0].assign(beg, end);
        rng (i, 0, SZ(a) - 1) {
            a[i + 1].resize(n);
            rng(j, 0, n - (1u << i)) {
                a[i + 1][j] = min(a[i][j], a[i][j + (1u << i)], Compare());
            }
            rng(j, n - (1u << i), n) {
                a[i + 1][j] = a[i][j];
            }
        }
    }

    using idx_t = long;

    T query(idx_t l, idx_t r) { // l <=  r
        int i = h_bit(r - l + 1ul);
        return min(a[i][l], a[i][r + 1 - (1u << i)], Compare());
    }
};

// debug code by tourist
string to_string(const string &s) {
    return '"' + s + '"';
}

string to_string(const char *s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template<typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// end DEBUG
template<typename T, typename Compare>
class MonoQueue {
private:
    deque<pair<T, int>> que;
    Compare cmp;
public:
    void push(const T &val, int i) {
        while (!que.empty() && !cmp(que.back().first, val)) {
            que.pop_back();
        }
        que.emplace_back(val, i);
    }

    T get(int i) {
        while (que.front().second < i) {
            que.pop_front();
        }
        return que.front().first;
    }
};

template<typename T>
struct Binom {
    vector<T> fact, inv_fact;

    explicit Binom(int n) : fact(n + 1), inv_fact(n + 1) {
        fact[0] = 1;
        up (i, 1, n) fact[i] = fact[i - 1] * i;
        inv_fact[n] = 1 / fact[n];
        down (i, n, 1) {
            inv_fact[i - 1] = inv_fact[i] * i;
        }
    }

    T get_binom(int x, int y) const {
        assert(x <= SZ(fact) - 1);
        assert(x >= 0 && y >= 0);
        if (x < y) return 0;
        return fact[x] * inv_fact[y] * inv_fact[x - y];
    }

    T get_fact(int n) const {
        assert(n < SZ(fact));
        return fact[n];
    }
};

template<typename T>
T get_mid(T l, T r) {
    assert(l <= r);
    return l + (r - l) / 2;
}

template<typename T>
int get_bit(T a, int i) {
    return a >> i & 1;
}

/*using ModType = int;

  struct VarMod {
  static ModType value;
  };
  ModType VarMod::value;
  ModType &md = VarMod::value;
  using Mint = Modular<VarMod>;*/
constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
//////////////////^"^///////////////////////////////////

int main() {
#if defined LOCAL && !defined DUIPAI
    ifstream in("in.txt");
    cin.rdbuf(in.rdbuf());
    //  ofstream out("main.out");
    //  cout.rdbuf(out.rdbuf());
#endif
    int k, x;
    scan(k, x);
    println(k * 500 >= x ? "Yes" : "No");
#if defined LOCAL && !defined DUIPAI
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
