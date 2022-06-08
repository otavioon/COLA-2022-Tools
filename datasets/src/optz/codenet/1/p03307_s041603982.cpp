/**
 * 
 */

// #include {{{
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <forward_list>
#include <functional>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#ifdef LOCAL
#include <fmt/format.h>
#include <fmt/ostream.h>
#endif

using namespace std;
// }}}

// type {{{
using  i8 =   int8_t;
using  u8 =  uint8_t;
using i16 =  int16_t;
using u16 = uint16_t;
using i32 =  int32_t;
using u32 = uint32_t;
using i64 =  int64_t;
using u64 = uint64_t;

using i128 =  __int128_t;
using u128 = __uint128_t;

template<typename T>
using MaxHeap = priority_queue<T, vector<T>, less<T>>;
template<typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
// }}}

// hide {{{
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-const-variable"
#endif
// }}}

// 適宜調整
constexpr bool AUTOFLUSH = false;

constexpr int IOS_PREC = 12;

constexpr int INF_I32 =             1'010'000'000;
constexpr i64 INF_I64 = 1'010'000'000'000'000'000LL;

constexpr auto   INF = INF_I64;
constexpr double EPS = 1e-12;

constexpr i64 MOD = 1'000'000'007;

// hide {{{
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// }}}

// util {{{
constexpr i32 I32_MAX = numeric_limits<i32>::max();
constexpr i32 I32_MIN = numeric_limits<i32>::min();

constexpr i64 I64_MAX = numeric_limits<i64>::max();
constexpr i64 I64_MIN = numeric_limits<i64>::min();

constexpr double PI = 3.14159265358979323846;

template<typename F>
class RecursiveFunc {
public:
    RecursiveFunc(F&& f) : f_(f) {}

    template<typename... Args>
    decltype(auto) operator()(Args&&... args) const {
        return f_(*this, forward<Args>(args)...);
    }

private:
    F f_;
};

template<typename F>
auto RECURSIVE(F&& f) {
    return RecursiveFunc<decay_t<F>>(forward<F>(f));
}

template<typename T>
int GETBIT(T x, int i) { return (x>>i) & 1; }
template<typename T>
T SETBIT(T x, int i) { return x | (T(1)<<i); }
template<typename T>
T CLEARBIT(T x, int i) { return x & ~(T(1)<<i); }

template<typename T>
constexpr const T& MAX(const T& x, const T& y) { return std::max(x, y); }
template<typename T, typename Comp>
constexpr const T& MAX(const T& x, const T& y, Comp comp) { return std::max(x, y, comp); }
template<typename T>
constexpr T MAX(initializer_list<T> ilist) { return std::max(ilist); }
template<typename T, typename Comp>
constexpr T MAX(initializer_list<T> ilist, Comp comp) { return std::max(ilist, comp); }

template<typename T>
constexpr const T& MIN(const T& x, const T& y) { return std::min(x, y); }
template<typename T, typename Comp>
constexpr const T& MIN(const T& x, const T& y, Comp comp) { return std::min(x, y, comp); }
template<typename T>
constexpr T MIN(initializer_list<T> ilist) { return std::min(ilist); }
template<typename T, typename Comp>
constexpr T MIN(initializer_list<T> ilist, Comp comp) { return std::min(ilist, comp); }

template<typename T>
constexpr T ABS(T x) {
    static_assert(is_signed<T>::value, "ABS(): argument must be signed");
    return x < 0 ? -x : x;
}

template<typename T>
constexpr T abs_diff(T x, T y) {
    return x < y ? y-x : x-y;
}

template<typename T>
constexpr bool is_odd(T x)  { return x % 2 != 0; }
template<typename T>
constexpr bool is_even(T x) { return x % 2 == 0; }

template<typename T>
constexpr bool parity_same(T x, T y) {
    return (is_odd(x) && is_odd(y)) || (is_even(x) && is_even(y));
}

template<typename T>
constexpr int cmp(T x, T y) { return (y < x) - (x < y); }

template<typename T>
constexpr int sgn(T x) { return cmp(x, T(0)); }

constexpr i64 ipow(i64 a, i64 b) {
    assert(b >= 0);
    i64 res(1);
    for(i64 i = 0; i < b; ++i)
        res *= a;
    return res;
}

i64 ilog10(i64 x) {
    assert(x > 0);
    i64 res = -1;
    while(x > 0) {
        ++res;
        x /= 10;
    }
    return res;
}

pair<i64,i64> divmod(i64 a, i64 b) {
    return make_pair(a/b, a%b);
}

constexpr i64 div_ceil(i64 a, i64 b) {
    return a/b + (((a<0)^(b>0)) && (a%b));
}

constexpr i64 div_floor(i64 a, i64 b) {
    return a/b - (((a>0)^(b>0)) && (a%b));
}

constexpr i64 modulo(i64 a, i64 b) {
    assert(0 < b);
    i64 r = a % b;
    return r >= 0 ? r : r+b;
}

template<typename T>
constexpr T CLAMP(T x, T lo, T hi) {
    assert(lo <= hi);
    if(x < lo)
        return lo;
    else if(hi < x)
        return hi;
    else
        return x;
}

template<typename T, typename U>
bool chmax(T& xmax, const U& x) {
    if(xmax < x) {
        xmax = x;
        return true;
    }
    else {
        return false;
    }
}

template<typename T, typename U>
bool chmin(T& xmin, const U& x) {
    if(x < xmin) {
        xmin = x;
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
constexpr int SIZE(const T& c) {
    return static_cast<int>(c.size());
}

template<typename T, size_t N>
constexpr int SIZE(const T (&)[N]) {
    return static_cast<int>(N);
}

template<typename InputIt, typename T>
int argfind(InputIt first, InputIt last, const T& x) {
    auto it = find(first, last, x);
    return distance(first, it);
}

template<typename InputIt>
int argmax(InputIt first, InputIt last) {
    auto it = max_element(first, last);
    return distance(first, it);
}

template<typename InputIt>
int argmin(InputIt first, InputIt last) {
    auto it = min_element(first, last);
    return distance(first, it);
}

template<typename InputIt>
bool alltrue(InputIt first, InputIt last) {
    return all_of(first, last, [](bool b) { return b; });
}

template<typename InputIt>
bool anytrue(InputIt first, InputIt last) {
    return any_of(first, last, [](bool b) { return b; });
}

template<typename InputIt>
bool allfalse(InputIt first, InputIt last) {
    return !anytrue(first, last);
}

template<typename InputIt>
bool anyfalse(InputIt first, InputIt last) {
    return !alltrue(first, last);
}

// hash {{{
template<typename T>
struct myhash {
    size_t operator()(const T& x) const {
        hash<T> h;
        return h(x);
    }
};

template<typename T>
size_t myhash_value(const T& x) {
    return myhash<T>()(x);
}

template<typename T>
void myhash_combine(size_t& seed, const T& x) {
    seed ^= myhash_value(x) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

template<typename T1, typename T2>
struct myhash<pair<T1,T2>> {
    size_t operator()(const pair<T1,T2>& p) const {
        size_t seed = 0;
        myhash_combine(seed, p.first);
        myhash_combine(seed, p.second);
        return seed;
    }
};

template<size_t I=0, typename... TS, enable_if_t<I == sizeof...(TS), nullptr_t> = nullptr>
void TUPLEHASH(size_t&, const tuple<TS...>&) {}

template<size_t I=0, typename... TS, enable_if_t<I < sizeof...(TS), nullptr_t> = nullptr>
void TUPLEHASH(size_t& seed, const tuple<TS...>& t) {
    myhash_combine(seed, get<I>(t));
    TUPLEHASH<I+1, TS...>(seed, t);
}

template<typename... TS>
struct myhash<tuple<TS...>> {
    size_t operator()(const tuple<TS...>& t) const {
        size_t seed = 0;
        TUPLEHASH(seed, t);
        return seed;
    }
};

template<typename Seq>
void SEQHASH(size_t& seed, const Seq& v) {
    for(const auto& e : v)
        myhash_combine(seed, e);
}

template<typename T>
struct myhash<vector<T>> {
    size_t operator()(const vector<T>& v) const {
        size_t seed = 0;
        SEQHASH(seed, v);
        return seed;
    }
};

template<typename T, size_t N>
struct myhash<array<T,N>> {
    size_t operator()(const array<T,N>& v) const {
        size_t seed = 0;
        SEQHASH(seed, v);
        return seed;
    }
};

template<typename T>
using HashSet = unordered_set<T,myhash<T>>;

template<typename K, typename V>
using HashMap = unordered_map<K,V,myhash<K>>;

template<typename T>
using HashMultiSet = unordered_multiset<T,myhash<T>>;

template<typename K, typename V>
using HashMultiMap = unordered_multimap<K,V,myhash<K>>;
// }}}

template<typename T, typename... Args>
void vec_emplace_front(vector<T>& v, Args&&... args) {
    v.emplace(begin(v), args...);
}

template<typename K, typename V>
pair<typename map<K,V>::iterator, bool> insert_or_assign(map<K,V>& m, const K& k, const V& v) {
    auto it = m.lower_bound(k);
    if(it != end(m) && !m.key_comp()(k,it->first)) {
        it->second = v;
        return make_pair(it, false);
    }
    else {
        auto it_ins = m.insert(it, make_pair(k,v));
        return make_pair(it_ins, true);
    }
}

template<typename K, typename V>
pair<typename HashMap<K,V>::iterator, bool>
insert_or_assign(HashMap<K,V>& m, const K& k, const V& v) {
    auto it = m.find(k);
    if(it != end(m)) {
        it->second = v;
        return make_pair(it, false);
    }
    else {
        auto it_ins = m.insert(it, make_pair(k,v));
        return make_pair(it_ins, true);
    }
}

template<typename T>
void FROM_STRING(const string& s, T& x) {
    istringstream in(s);
    in >> x;
}

template<typename T>
string TO_STRING(const T& x) {
    ostringstream out;
    out << x;
    return out.str();
}

template<typename InputIt>
string JOIN(InputIt first, InputIt last, const string& sep) {
    ostringstream out;
    while(first != last) {
        out << *first++;
        if(first != last)
            out << sep;
    }
    return out.str();
}

template<typename InputIt>
auto SUM(InputIt first, InputIt last) {
    using T = typename iterator_traits<InputIt>::value_type;
    return accumulate(first, last, T());
}

template<typename InputIt>
i64 ACCUMULATE(InputIt first, InputIt last, i64 value) {
    return accumulate(first, last, value);
}

template<typename InputIt>
i64 ACCUMULATE(InputIt first, InputIt last) {
    return ACCUMULATE(first, last, i64(0));
}

template<typename InputIt1, typename InputIt2>
i64 INNER_PRODUCT(InputIt1 first1, InputIt1 last1, InputIt2 first2, i64 value) {
    return inner_product(first1, last1, first2, value);
}

template<typename InputIt1, typename InputIt2>
i64 INNER_PRODUCT(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
    return INNER_PRODUCT(first1, last1, first2, i64(0));
}

template<typename T>
void UNIQ(T& c) {
    c.erase(unique(begin(c), end(c)), end(c));
}

template<typename T, typename F>
enable_if_t<rank<T>::value==0> ARRAY_FOREACH(T& e, F f) {
    f(e);
}

template<typename Array, typename F>
enable_if_t<rank<Array>::value!=0> ARRAY_FOREACH(Array& ary, F f) {
    for(auto& e : ary)
        ARRAY_FOREACH(e, f);
}

template<typename Array, typename U>
enable_if_t<rank<Array>::value!=0> ARRAY_FILL(Array& ary, const U& v) {
    ARRAY_FOREACH(ary, [&v](auto& elem) { elem = v; });
}

template<typename T>
T POP_BACK(vector<T>& que) {
    T x = que.back(); que.pop_back();
    return x;
}

template<typename T>
T POP_BACK(deque<T>& que) {
    T x = que.back(); que.pop_back();
    return x;
}

template<typename T>
T POP_FRONT(deque<T>& que) {
    T x = que.front(); que.pop_front();
    return x;
}

template<typename T, typename C>
T POP(stack<T,C>& stk) {
    T x = stk.top(); stk.pop();
    return x;
}

template<typename T, typename C>
T POP(queue<T,C>& que) {
    T x = que.front(); que.pop();
    return x;
}

template<typename T, typename Cont, typename Cmp>
T POP(priority_queue<T,Cont,Cmp>& que) {
    T x = que.top(); que.pop();
    return x;
}

template<typename T>
void RD(T& x) {
    cin >> x;
#ifdef LOCAL
    if(!cin) assert(false);
#endif
}

template<typename T>
void RD(vector<T>& v, int n) {
    v.reserve(n);
    for(int i = 0; i < n; ++i) {
        T e; RD(e);
        v.emplace_back(e);
    }
}

template<typename T, size_t N>
void RD(array<T,N>& v) {
    for(size_t i = 0; i < N; ++i) {
        RD(v[i]);
    }
}

// 出力 {{{
// FPRINTSEQ {{{
template<typename InputIt>
ostream& FPRINTSEQ(ostream& out, InputIt first, InputIt last) {
    while(first != last) {
        out << *first++;
        if(first != last)
            out << ' ';
    }
    return out;
}
template<typename InputIt>
ostream& PRINTSEQ(InputIt first, InputIt last) {
    return FPRINTSEQ(cout, first, last);
}
template<typename InputIt>
ostream& DPRINTSEQ(InputIt first, InputIt last) {
#ifdef LOCAL
    FPRINTSEQ(cerr, first, last);
#endif
    return cerr;
}
// }}}

// 1次元生配列 {{{
template<typename T, size_t N>
ostream& FPRINTARRAY1(ostream& out, const T (&c)[N]) {
    return FPRINTSEQ(out, begin(c), end(c));
}
template<typename T, size_t N>
ostream& PRINTARRAY1(const T (&c)[N]) {
    return FPRINTARRAY1(cout, c);
}
template<typename T, size_t N>
ostream& DPRINTARRAY1(const T (&c)[N]) {
#ifdef LOCAL
    FPRINTARRAY1(cerr, c);
#endif
    return cerr;
}
// }}}

// 2次元生配列 {{{
template<typename T, size_t N1, size_t N2>
ostream& FPRINTARRAY2(ostream& out, const T (&c)[N1][N2]) {
    out << '\n';
    for(const auto& e : c) {
        FPRINTARRAY1(out, e) << '\n';
    }
    return out;
}
template<typename T, size_t N1, size_t N2>
ostream& PRINTARRAY2(const T (&c)[N1][N2]) {
    return FPRINTARRAY2(cout, c);
}
template<typename T, size_t N1, size_t N2>
ostream& DPRINTARRAY2(const T (&c)[N1][N2]) {
#ifdef LOCAL
    FPRINTARRAY2(cerr, c);
#endif
    return cerr;
}
// }}}

// 非mapコンテナ {{{
template<typename T>
ostream& operator<<(ostream& out, const vector<T>& c) {
    return FPRINTSEQ(out, begin(c), end(c));
}

// 特別扱い
template<typename T>
ostream& operator<<(ostream& out, const vector<vector<T>>& c) {
    out << '\n';
    for(const auto& e : c) {
        out << e << '\n';
    }
    return out;
}

// 特別扱い
ostream& operator<<(ostream& out, const vector<string>& c) {
    out << '\n';
    for(const string& e : c) {
        out << e << '\n';
    }
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const deque<T>& c) {
    return FPRINTSEQ(out, begin(c), end(c));
}

template<typename T>
ostream& operator<<(ostream& out, const set<T>& c) {
    return FPRINTSEQ(out, begin(c), end(c));
}

template<typename T>
ostream& operator<<(ostream& out, const HashSet<T>& c) {
    return out << set<T>(begin(c), end(c));
}

template<typename T>
ostream& operator<<(ostream& out, const multiset<T>& c) {
    return FPRINTSEQ(out, begin(c), end(c));
}

template<typename T>
ostream& operator<<(ostream& out, const HashMultiSet<T>& c) {
    return out << multiset<T>(begin(c), end(c));
}

template<typename T, size_t N>
ostream& operator<<(ostream& out, const array<T,N>& c) {
    return FPRINTSEQ(out, begin(c), end(c));
}
// }}}

// mapコンテナ {{{
template<typename InputIt>
ostream& FPRINTMAP(ostream& out, InputIt first, InputIt last) {
    out << "{\n";
    for(auto it = first; it != last; ++it) {
        out << "  " << it->first << " : " << it->second << '\n';
    }
    out << "}\n";
    return out;
}
template<typename InputIt>
ostream& PRINTMAP(InputIt first, InputIt last) {
    return FPRINTMAP(cout, first, last);
}
template<typename InputIt>
ostream& DPRINTMAP(InputIt first, InputIt last) {
#ifdef LOCAL
    FPRINTMAP(cerr, first, last);
#endif
    return cerr;
}

template<typename K, typename V>
ostream& operator<<(ostream& out, const map<K,V>& c) {
    return FPRINTMAP(out, begin(c), end(c));
}

template<typename K, typename V>
ostream& operator<<(ostream& out, const HashMap<K,V>& c) {
    return out << map<K,V>(begin(c), end(c));
}

template<typename K, typename V>
ostream& operator<<(ostream& out, const multimap<K,V>& c) {
    return FPRINTMAP(out, begin(c), end(c));
}

template<typename K, typename V>
ostream& operator<<(ostream& out, const HashMultiMap<K,V>& c) {
    return out << multimap<K,V>(begin(c), end(c));
}
// }}}

// stack/queue/priority_queue {{{
template<typename T, typename C>
ostream& operator<<(ostream& out, stack<T,C> c) {
    while(!c.empty()) {
        out << c.top();
        c.pop();
        if(!c.empty()) out << ' ';
    }
    return out;
}

template<typename T, typename C>
ostream& operator<<(ostream& out, queue<T,C> c) {
    while(!c.empty()) {
        out << c.front();
        c.pop();
        if(!c.empty()) out << ' ';
    }
    return out;
}

template<typename T, typename Cont, typename Cmp>
ostream& operator<<(ostream& out, priority_queue<T,Cont,Cmp> c) {
    while(!c.empty()) {
        out << c.top();
        c.pop();
        if(!c.empty()) out << ' ';
    }
    return out;
}
// }}}

// pair/tuple {{{
template<typename T1, typename T2>
ostream& operator<<(ostream& out, const pair<T1,T2>& p) {
    return out << '(' << p.first << ',' << p.second << ')';
}

template<size_t I=0, typename... TS, enable_if_t<I == sizeof...(TS), nullptr_t> = nullptr>
ostream& FPRINTTUPLE(ostream& out, const tuple<TS...>&) {
    if(sizeof...(TS) == 0)
        out << '(';
    return out << ')';
}

template<size_t I=0, typename... TS, enable_if_t<I < sizeof...(TS), nullptr_t> = nullptr>
ostream& FPRINTTUPLE(ostream& out, const tuple<TS...>& t) {
    if(I == 0)
        out << '(';
    else
        out << ',';
    out << get<I>(t);
    return FPRINTTUPLE<I+1, TS...>(out, t);
}

template<typename... TS>
ostream& operator<<(ostream& out, const tuple<TS...>& t) {
    return FPRINTTUPLE(out, t);
}
// }}}

// PRINT {{{
ostream& FPRINT(ostream& out) { return out; }

template<typename T, typename... TS>
ostream& FPRINT(ostream& out, const T& x, const TS& ...args) {
    out << x;
    if(sizeof...(args))
        out << ' ';
    return FPRINT(out, args...);
}

template<typename... TS>
ostream& FPRINTLN(ostream& out, const TS& ...args) {
    FPRINT(out, args...);
    return out << '\n';
}

template<typename... TS>
ostream& PRINT(const TS& ...args) {
    return FPRINT(cout, args...);
}

template<typename... TS>
ostream& PRINTLN(const TS& ...args) {
    return FPRINTLN(cout, args...);
}

template<typename... TS>
ostream& DPRINT(const TS& ...args) {
#ifdef LOCAL
    FPRINT(cerr, args...);
#endif
    return cerr;
}

template<typename... TS>
ostream& DPRINTLN(const TS& ...args) {
#ifdef LOCAL
    FPRINTLN(cerr, args...);
#endif
    return cerr;
}
// }}}
// }}}

void FLUSH() {
    cout.flush();
}

[[noreturn]] void EXIT() {
#ifdef LOCAL
    cout.flush();
    cerr.flush();
#else
    FLUSH();
#endif
    //quick_exit(0); // does not work on codeforces
    _Exit(0);
}

struct IoInit {
    IoInit() {
#ifndef LOCAL
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
#endif
        cout << fixed << setprecision(IOS_PREC);
#ifdef LOCAL
        cerr << fixed << setprecision(IOS_PREC);
#endif

        if(AUTOFLUSH)
            cout << unitbuf;
    }
} IOINIT;

#define FOR(i, start, end) for(i64 i = (start); i < (end); ++i)
#define REP(i, n) FOR(i, 0, n)

#define ALL(f,c,...) (([&](decltype((c)) cc) { return (f)(begin(cc), end(cc), ## __VA_ARGS__); })(c))

#define GENERIC(f) ([](auto&&... args) -> decltype(auto) { return (f)(forward<decltype(args)>(args)...); })

#define DBG(x) DPRINTLN('L', __LINE__, ':', #x, ':', (x))

#define PAIR make_pair
#define TUPLE make_tuple
// }}}

i64 N;

void solve() {
    i64 ans = is_even(N) ? N : 2*N;

    PRINTLN(ans);
}

signed main(signed /*argc*/, char** /*argv*/) {
    RD(N);

    

    solve();

    EXIT();
}
