#include <bits/stdc++.h>
using namespace std;

struct init_ { init_(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(10); } } init_;

template<class C> using iodef_rng_t = typename enable_if<decltype(declval<C>().begin(), true_type{})::value && !is_same<C, string>::value>::type;
template<class C, class = iodef_rng_t<C>> istream& operator>>(istream& in, C& c) { for (auto& v : c) { in >> v; } return in; }
template<class C, class = iodef_rng_t<C>> ostream& operator<<(ostream& out, const C& c) { int i = 0; for (const auto& v : c) { if (i++) { out << ' '; } out << v; } return out; }
template<size_t N, class T, class R> using when_last = typename enable_if<N == tuple_size<remove_reference_t<T>>::value - 1, R>::type;
template<size_t N, class T, class R> using when_init = typename enable_if<N != tuple_size<remove_reference_t<T>>::value - 1, R>::type;
template<size_t N = 0, class T> auto operator>>(istream& in, T&& t) -> when_last<N, T, istream&> { return in >> get<N>(t); }
template<size_t N = 0, class T> auto operator>>(istream& in, T&& t) -> when_init<N, T, istream&> { return operator>><N + 1>(in >> get<N>(t), forward<T>(t)); }
template<size_t N = 0, class T> auto operator<<(ostream& out, const T& t) -> when_last<N, T, ostream&> { return out << get<N>(t); }
template<size_t N = 0, class T> auto operator<<(ostream& out, const T& t) -> when_init<N, T, ostream&> { return operator<<<N + 1>(out << get<N>(t) << ' ', t); }

#ifdef LOCAL
template<class T> void trace_(const char* s, const T& v) { cerr << s << "=" << v; }
template<class T, class... Ts> void trace_(const char* s, const T& v, const Ts&... vs) { for (; *s != ','; ++s) { cerr << *s; } cerr << "=" << v << ","; trace_(++s, vs...); }
#define TRACE(...) (cerr << "\033[2m\033[33m", trace_(#__VA_ARGS__, __VA_ARGS__), cerr << "\033[0m\n")
#else
#define TRACE(...)
#endif


int n, k;
set<int> ds;
int ans = numeric_limits<int>::max();
void dfs(int v) {
    for (auto d : ds) {
        auto w = v * 10 + d;
        if (w >= n) {
            ans = min(ans, w);
        } else if (w != 0) {
            dfs(w);
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < 10; i++) {
        ds.emplace(i);
    }
    for (int i = 0; i < k; i++) {
        int d;
        cin >> d;
        ds.erase(d);
    }
    dfs(0);
    cout << ans << '\n';
}
