// >>> TEMPLATES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using i32 = int32_t;
using i64 = int64_t;
#define int ll
#define double ld
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define repR(i,n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep1R(i,n) for (int i = (int)(n); i >= 1; i--)
#define loop(i,a,B) for (int i = a; i B; i++)
#define loopR(i,a,B) for (int i = a; i B; i--)
#define all(x) (x).begin(), (x).end()
#define allR(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
auto constexpr INF32 = numeric_limits<int32_t>::max()/2-1;
auto constexpr INF64 = numeric_limits<int64_t>::max()/2-1;
auto constexpr INF   = numeric_limits<int>::max()/2-1;
#ifdef LOCAL
#include "debug.hpp"
#define dump(...) cerr << "[" << setw(3) << __LINE__ << ":" << __FUNCTION__ << "] ", dump_impl(#__VA_ARGS__, __VA_ARGS__)
#define say(x) cerr << "[" << __LINE__ << ":" << __FUNCTION__ << "] " << x << endl
#define debug if (1)
#else
#define dump(...) (void)(0)
#define say(x) (void)(0)
#define debug if (0)
#endif
template <class T> using pque_max = priority_queue<T>;
template <class T> using pque_min = priority_queue<T, vector<T>, greater<T> >;
template <class T, class = typename T::iterator, class = typename enable_if<!is_same<T, string>::value>::type>
ostream& operator<<(ostream& os, T const& v) { bool f = true; for (auto const& x : v) os << (f ? "" : " ") << x, f = false; return os; }
template <class T, class = typename T::iterator, class = typename enable_if<!is_same<T, string>::value>::type>
istream& operator>>(istream& is, T &v) { for (auto& x : v) is >> x; return is; }
template <class T, class S> istream& operator>>(istream& is, pair<T,S>& p) { return is >> p.first >> p.second; }
struct IOSetup { IOSetup() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } iosetup;
template <class F> struct FixPoint : private F {
    constexpr FixPoint(F&& f) : F(forward<F>(f)) {}
    template <class... T> constexpr auto operator()(T&&... x) const { return F::operator()(*this, forward<T>(x)...); }
};
struct MakeFixPoint {
    template <class F> constexpr auto operator|(F&& f) const { return FixPoint<F>(forward<F>(f)); }
};
#define MFP MakeFixPoint()|
#define def(name, ...) auto name = MFP [&](auto &&name, __VA_ARGS__)
template <class T, size_t d> struct vec_impl {
    using type = vector<typename vec_impl<T,d-1>::type>;
    template <class... U> static type make_v(size_t n, U&&... x) { return type(n, vec_impl<T,d-1>::make_v(forward<U>(x)...)); }
};
template <class T> struct vec_impl<T,0> { using type = T; static type make_v(T const& x = {}) { return x; } };
template <class T, size_t d = 1> using vec = typename vec_impl<T,d>::type;
template <class T, size_t d = 1, class... Args> auto make_v(Args&&... args) { return vec_impl<T,d>::make_v(forward<Args>(args)...); }
template <class T> void quit(T const& x) { cout << x << endl; exit(0); }
template <class T> constexpr bool chmin(T& x, T const& y) { if (x > y) { x = y; return true; } return false; }
template <class T> constexpr bool chmax(T& x, T const& y) { if (x < y) { x = y; return true; } return false; }
template <class It> constexpr auto sumof(It b, It e) { return accumulate(b,e,typename iterator_traits<It>::value_type{}); }
template <class T> int sz(T const& x) { return x.size(); }
template <class C, class T> int lbd(C const& v, T const& x) {
    return lower_bound(v.begin(), v.end(), x)-v.begin();
}
template <class C, class T> int ubd(C const& v, T const& x) {
    return upper_bound(v.begin(), v.end(), x)-v.begin();
}
template <class C, class F> int ppt(C const& v, F f) {
    return partition_point(v.begin(), v.end(), f)-v.begin();
}
// <<<

int32_t main() {
    int n; cin >> n;
    multiset<int> s;
    rep (i,n) {
        int a; cin >> a;
        s.insert(a);
    }
    auto f = [](int n) {
        int ret = 1;
        while (ret <= n) ret <<= 1;
        return ret;
    };

    int cnt = 0;
    while (s.size()) {
        auto it = --s.end();
        int x = *it;
        s.erase(it);
        int y = f(x)-x;
        it = s.find(y);
        if (it != s.end()) {
            dump(x,y);
            cnt++;
            s.erase(it);
        }
    }
    cout << cnt << endl;
}
