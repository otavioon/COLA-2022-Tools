//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace std::chrono;
#define int long long
#define ll long long
auto start_time = system_clock::now();

//@formatter:off
#ifdef _DEBUG
//区間削除は出来ない
template<class T> struct my_pbds_tree {    set<T> s;    auto begin() { return s.begin(); }    auto end() { return s.end(); }    auto rbegin() { return s.rbegin(); }    auto rend() { return s.rend(); }    auto empty() { return s.empty(); }    auto size() { return s.size(); }    void clear() { s.clear(); }    template<class U> void insert(U v) { s.insert(v); }template<class U> void operator+=(U v) { insert(v); }    template<class F> auto erase(F v) { return s.erase(v); }    template<class U> auto find(U v) { return s.find(v); }    template<class U> auto lower_bound(U v) { return s.lower_bound(v); }    template<class U> auto upper_bound(U v) { return s.upper_bound(v); }    auto find_by_order(ll k) {        auto it = s.begin();        for (ll i = 0; i < k; i++)it++;        return it;    }    auto order_of_key(ll v) {        auto it = s.begin();        ll i=0;        for (;it != s.end() && *it <v ; i++)it++;        return i;    }};
#define pbds(T) my_pbds_tree<T>
#else
#define unordered_map __gnu_pbds::gp_hash_table
//find_by_order(k) k番目のイテレーター
//order_of_key(k)  k以上が前から何番目か
#define pbds(U) __gnu_pbds::tree<U, __gnu_pbds::null_type, less<U>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>
#endif
struct xorshift {    static uint64_t splitmix64(uint64_t x) {        x += 0x9e3779b97f4a7c15;        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;        return x ^ (x >> 31);    }    size_t operator()(uint64_t x) const {        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();        return splitmix64(x + FIXED_RANDOM);    }    size_t operator()(std::pair<ll, ll> x) const {        ll v=((x.first) << 32) | x.second;        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();        return splitmix64(v + FIXED_RANDOM);    }};
template<class U, class L> void operator+=(__gnu_pbds::tree<U, __gnu_pbds::null_type, less<U>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> &s, L v) { s.insert(v); }
//衝突対策
#define ws wszzzz

template<class A, class B, class C>struct T2 {A f;B s;C t;T2() { f = 0, s = 0, t = 0; }T2(A f, B s, C t) : f(f), s(s), t(t) {}bool operator<(const T2 &r) const {        return f != r.f ? f < r.f : s != r.s ? s < r.s : t < r.t;        /*return f != r.f ? f > r.f : s != r.s ?n s > r.s : t > r.t; 大きい順 */   }    bool operator>(const T2 &r) const {        return f != r.f ? f > r.f : s != r.s ? s > r.s : t > r.t;        /*return f != r.f ? f > r.f : s != r.s ? s > r.s : t > r.t; 小さい順 */   }    bool operator==(const T2 &r) const {        return f == r.f && s == r.s && t == r.t;    }    bool operator!=(const T2 &r) const {        return f != r.f || s != r.s || t != r.t;    }};
template<class A, class B, class C, class D> struct F2 {    A a;    B b;    C c;    D d;    F2() { a = 0, b = 0, c = 0, d = 0; }    F2(A a, B b, C c, D d) : a(a), b(b), c(c), d(d) {}    bool operator<(const F2 &r) const {        return a != r.a ? a < r.a : b != r.b ? b < r.b : c != r.c ? c < r.c : d < r.d;    /*    return a != r.a ? a > r.a : b != r.b ? b > r.b : c != r.c ? c > r.c : d > r.d;*/    }    bool operator>(const F2 &r) const {        return a != r.a ? a > r.a : b != r.b ? b > r.b : c != r.c ? c > r.c : d > r.d;/*        return a != r.a ? a < r.a : b != r.b ? b < r.b : c != r.c ? c < r.c : d < r.d;*/    }    bool operator==(const F2 &r) const {        return a == r.a && b == r.b && c == r.c && d == r.d;    }    bool operator!=(const F2 &r) const {        return a != r.a || b != r.b || c != r.c || d != r.d;    }    ll operator[](ll i) {        assert(i < 4);        return i == 0 ? a : i == 1 ? b : i == 2 ? c : d;    }};
typedef T2<ll, ll, ll> T;
typedef F2<ll, ll, ll, ll> F;
T mt(ll a, ll b, ll c) {return T(a, b, c);}

//@マクロ省略系 型,構造
#define double long double
#define ull unsigned long long
using dou = double;
using itn = int;
using str = string;
using bo= bool;
#define au auto
using P = pair<ll, ll>;
using pd =pair<dou, dou>;
#define fi first
#define se second
#define beg begin
#define rbeg rbegin
#define con continue
#define bre break
#define brk break
#define is ==
#define el else
#define elf else if
#define wh while
#define upd update

#define maxq 1
#define minq -1

#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define MALLOC(type, len) (type*)malloc((len) * sizeof(type))
#define lam(right) [&](ll& p){return p right;}

//マクロ省略系 コンテナ
using vi = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;
using vd = vector<double>;
using vc = vector<char>;
using vp = vector<P>;
using vt = vector<T>;

#define V vector
#define o_vvt(o1, o2, o3, o4, name, ...) name
#define vvt0(t) V<V<t>>
#define vvt1(t,a) V<V<t>>a
#define vvt2(t,a, b) V<V<t>>a(b)
#define vvt3(t,a, b, c) V<V<t>> a(b,V<t>(c))
#define vvt4(t,a, b, c, d) V<V<t>> a(b,V<t>(c,d))

#define vvi(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(ll,__VA_ARGS__)
#define vvb(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(bool,__VA_ARGS__)
#define vvs(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(string,__VA_ARGS__)
#define vvd(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(double,__VA_ARGS__)
#define vvc(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(char,__VA_ARGS__)
#define vvp(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(P,__VA_ARGS__)
#define vvt(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(T,__VA_ARGS__)

template<typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts> auto make_v(size_t a, Ts... ts) {return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));}
#define vni(name, ...) auto name = make_v<ll>(__VA_ARGS__)
#define vnb(name, ...) auto name = make_v<bool>(__VA_ARGS__)
#define vns(name, ...) auto name = make_v<string>(__VA_ARGS__)
#define vnd(name, ...) auto name = make_v<double>(__VA_ARGS__)
#define vnc(name, ...) auto name = make_v<char>(__VA_ARGS__)
#define vnp(name, ...) auto name = make_v<P>(__VA_ARGS__)

#define PQ priority_queue<ll, vector<ll>, greater<ll> >
#define tos to_string
using mapi = map<ll, ll>;
using mapp = map<P, ll>;
using mapd = map<dou, ll>;
using mapc = map<char, ll>;
using maps = map<str, ll>;
using seti = set<ll>;
using setd = set<dou>;
using setc = set<char>;
using sets = set<str>;
using qui = queue<ll>;
#define bset bitset
#define uset unordered_set
#define useti unordered_set<ll,ll,xorshift>
#define mset multiset
#define mseti multiset<ll>
#define umap unordered_map
#define umapi unordered_map<ll,ll,xorshift>
#define umapp unordered_map<P,ll,xorshift>
#define mmap multimap

template<class T> struct pq {    priority_queue<T, vector<T>, greater<T> > q;/*小さい順*/    T su = 0;    void clear() {q = priority_queue<T, vector<T>, greater<T> >();su = 0;}    void operator+=(T v) {su += v;q.push(v);}    T sum() {return su;}    T top() {return q.top();}    void pop() {su -= q.top();q.pop();}    T poll() {T ret = q.top();su -= ret;q.pop();return ret;}    ll size() {return q.size();}};
template<class T> struct pqg {    priority_queue<T> q;/*大きい順*/    T su = 0;    void clear() {q = priority_queue<T>();su = 0;}    void operator+=(T v) {su += v;q.push(v);}    T sum() {return su;}    T top() {return q.top();}    void pop() {su -= q.top();q.pop();}    T poll() {T ret = q.top();su -= ret;q.pop();return ret;}    ll size() {return q.size();}};
#define pqi pq<ll>
#define pqgi pqg<ll>
//マクロ 繰り返し
#define o_rep(o1, o2, o3, o4, name, ...) name
# define rep1(n) for(ll rep1i = 0,rep1lim=n; rep1i < rep1lim ; ++rep1i)
# define rep2(i, n) for(ll i = 0,rep2lim=n; i < rep2lim ; ++i)
#define rep3(i, m, n) for(ll i = m,rep3lim=n; i < rep3lim ; ++i)
#define rep4(i, m, n, ad) for(ll i = m,rep4lim=n; i < rep4lim ; i+= ad)
#define rep(...) o_rep(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)

#define rer2(i, n) for(ll i = n; i >= 0 ; i--)
#define rer3(i, m, n) for(ll i = m,rer3lim=n; i >= rer3lim ; i--)
#define rer4(i, m, n, dec) for(ll i = m,rer4lim=n; i >= rer4lim ; i-=dec)
#define rer(...) o_rep(__VA_ARGS__,rer4,rer3,rer2,)(__VA_ARGS__)

#define reps2(i, j, n) for(ll i = 0,reps2lim=n; i < reps2lim ;++i)for(ll j = 0; j < reps2lim ; ++j)
#define reps3(i, j, k, n) for(ll i = 0,reps3lim=n; i < reps3lim ; ++i)for(ll j = 0; j < reps3lim ; ++j)for(ll k = 0; k < reps3lim ; ++k)
#define reps4(i, j, k, l, n) for(ll i = 0,reps4lim=n; i < reps4lim ; ++i)for(ll j = 0; j < reps4lim ; ++j)for(ll k = 0; k < reps4lim ; ++k)for(ll l = 0; l < reps4lim ; ++l)
#define o_reps(o1, o2, o3, o4, o5, name, ...) name
#define reps(...) o_reps(__VA_ARGS__,reps4,reps3,reps2,rep2,)(__VA_ARGS__)

#define repss(i, j, k, a, b, c) for(ll i = 0; i < a ; ++i)for(ll j = 0; j < b ; ++j)for(ll k = 0; k < c ; ++k)

#define fora(a, b) for(auto&& a : b)

#define form(st, l, r) for (auto &&it = st.lower_bound(l); it != st.end() && (*it).fi < r; ++it)
#define forit(st, l, r) for (auto &&it = st.lower_bound(l); it != st.end() && (*it) < r;)

//マクロ 定数
#define k3 1010
#define k4 10101
#define k5 101010
#define k6 1010101
#define k7 10101010
const ll inf = (ll) 1e9 + 100;
const ll linf = (ll) 1e18 + 100;
const char infc = '{';
const string infs = "{";
const double eps = 1e-9;
const double PI = 3.1415926535897932384626433832795029L;
ll ma = numeric_limits<ll>::min();
ll mi = numeric_limits<ll>::max();

//マクロ省略形 関数等
#define arsz(a) (sizeof(a)/sizeof(a[0]))
#define sz(a) ((ll)(a).size())
#define mp make_pair
#define pb pop_back
#define pf push_front
#define eb emplace_back
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

constexpr bool ev(ll a) { return !(a & 1); }
constexpr bool od(ll a) { return (a & 1); }
//@拡張系 こう出来るべきというもの

//埋め込み 存在を意識せずに機能を増やされているもの
//@formatter:on
namespace std {
    template<> class hash<std::pair<signed, signed>> { public:size_t operator()(const std::pair<signed, signed> &x) const { return hash<ll>()(((ll) x.first << 32) | x.second); }};
    template<> class hash<std::pair<ll, ll>> { public:/*大きいllが渡されると、<<32でオーバーフローするがとりあえず問題ないと判断*/size_t operator()(const std::pair<ll, ll> &x) const { return hash<ll>()(((ll) x.first << 32) | x.second); }};
}
//@formatter:off
//stream まとめ
istream &operator>>(istream &iss, P &a) {    iss >> a.first >> a.second;    return iss;}template<typename T> istream &operator>>(istream &iss, vector<T> &vec) {    for (T &x: vec) iss >> x;    return iss;}template<class T, class U> ostream &operator<<(ostream &os, pair<T, U> p) {    os << p.fi << " " << p.se << endl;    return os;}ostream &operator<<(ostream &os, T p) {    os << p.f << " " << p.s << " " << p.t;    return os;}ostream &operator<<(ostream &os, F p) {    os << p.a << " " << p.b << " " << p.c << " " << p.d;    return os;}template<typename T> ostream &operator<<(ostream &os, vector<T> &vec) {    for (ll i = 0; i < vec.size(); ++i)os << vec[i] << (i + 1 == vec.size() ? "" : " ");    return os;}template<typename T> ostream &operator<<(ostream &os, vector<vector<T>> &vec) {    for (ll i = 0; i < vec.size(); ++i) {        for (ll j = 0; j < vec[i].size(); ++j) { os << vec[i][j] << " "; }        os << endl;    }    return os;}template<typename T, typename U> ostream &operator<<(ostream &os, map<T, U> &m) {    for (auto &&v:m) os << v;    return os;}template<class T> ostream &operator<<(ostream &os, set<T>s) {fora(v,s){os<<v<<" ";}return os;}
template<typename W, typename H> void resize(vector<W> &vec, const H head) { vec.resize(head); }template<typename W, typename H, typename ... T> void resize(vector<W> &vec, const H &head, const T ... tail) {vec.resize(head);for (auto &v: vec)resize(v, tail...);}
template<typename T, typename F> bool all_of2(T &v, F f) { return f(v); }
template<typename T, typename F> bool all_of2(vector<T> &v, F f) {    rep(i, sz(v)) { if (!all_of2(v[i], f))return false; }    return true;}
template<typename T, typename F> bool any_of2(T &v, F f) { return f(v); }
template<typename T, typename F> bool any_of2(vector<T> &v, F f) {    rep(i, sz(v)) { if (any_of2(v[i], f))return true; }    return false;}
template<typename T, typename F> bool none_of2(T &v, F f) { return f(v); }
template<typename T, typename F> bool none_of2(vector<T> &v, F f) {    rep(i, sz(v)) { if (none_of2(v[i], f))return false; }    return true;}
template<typename T, typename F> bool find_if2(T &v, F f) { return f(v); }
template<typename T, typename F> ll find_if2(vector<T> &v, F f) {    rep(i, sz(v)) { if (find_if2(v[i], f))return i; }    return sz(v);}
template<typename T, typename F> bool rfind_if2(T &v, F f) { return f(v); }
template<typename T, typename F> ll rfind_if2(vector<T> &v, F f) {    rer(i, sz(v) - 1) { if (rfind_if2(v[i], f))return i; }    return -1;}
template<class T> bool contains(string &s, const T &v) { return s.find(v) != string::npos; }
template<typename T> bool contains(vector<T> &v, const T &val) { return std::find(v.begin(), v.end(), val) != v.end(); }
template<typename T, typename F> bool contains_if2(vector<T> &v, F f) { return find_if(v.begin(), v.end(), f) != v.end(); }
template<typename T, typename F> ll count_if2(T &v, F f) { return f(v); }
template<typename T, typename F> ll count_if2(vector<T> &vec, F f) {    ll ret = 0;    fora(v, vec)ret += count_if2(v, f);    return ret;}
template<typename T, typename F> void for_each2(T &v, F f) { f(v); }
template<typename T, typename F> void for_each2(vector<T> &vec, F f) { fora(v, vec)for_each2(v, f); }
template<typename W> ll count_od(vector<W> &a) {return count_if2(a,[](ll v){return v&1 ;});}
template<typename W> ll count_ev(vector<W> &a) {return count_if2(a,[](ll v){return !(v&1) ;});}
#define all_of(a,right) all_of2(a,lam(right))
#define any_of(a,right) any_of2(a,lam(right))
#define none_of(a,right) none_of2(a,lam(right))
#define find_if(a,right) find_if2(a,lam(right))
#define rfind_if(a,right) rfind_if2(a,lam(right))
#define contains_if(a,right) contains_if2(a,lam(right))
#define count_if(a, right) count_if2(a,lam(right))
#define for_each(a, right) do{fora(v,a){v right;}}while(0)


template<class T, class U> void replace(vector<T> &a, T key, U v) { replace(a.begin(), a.end(), key, v); }
void replace(str &a, char key, str v) { if (v == "")a.erase(remove(all(a), key), a.end()); }
void replace(str &a, char key, char v) { replace(all(a), key, v); }
//keyと同じかどうか01で置き換える
template<class T, class U> void replace(vector<T> &a, U k) { rep(i, sz(a)) a[i] = a[i] == k; }
template<class T, class U> void replace(vector<vector<T >> &a, U k) { rep(i, sz(a))rep(j, sz(a[0])) a[i][j] = a[i][j] == k; }
template<class T> void replace(T &a) { replace(a, '#'); }
void replace(str &a, str key, str v) {stringstream t;ll kn = sz(key);std::string::size_type Pos(a.find(key));ll l = 0;while (Pos != std::string::npos) {t << a.substr(l, Pos - l);t << v;l = Pos + kn;Pos = a.find(key, Pos + kn);}t << a.substr(l, sz(a) - l);a = t.str();}
template<class T> bool includes(vector<T> &a, vector<T> &b) {vi c = a;vi d = b;sort(all(c));sort(all(d));return includes(all(c), all(d));}
template<class T> bool is_permutation(vector<T> &a, vector<T> &b) { return is_permutation(all(a), all(b)); }
template<class T> bool next_permutation(vector<T> &a) { return next_permutation(all(a)); }
void iota(vector<ll> &ve, ll s, ll n) {ve.resize(n);iota(all(ve), s);}
vi iota(ll s, ll len) {vi ve(len);iota(all(ve), s);return ve;}
template<class A, class B> auto vtop(vector<A> &a, vector<B> &b) {    assert(sz(a) == sz(b));    /*stringを0で初期化できない  */  vector<pair<A, B>> res;    rep(i, sz(a))res.eb(a[i], b[i]);return res;}
template<class A, class B> void ptov(vector<pair<A, B>> &p, vector<A> &a, vector<B> &b) {    a.resize(sz(p)), b.resize(sz(p));    rep(i, sz(p))a[i] = p[i].fi, b[i] = p[i].se;}
template<class A, class B, class C> auto vtot(vector<A> &a, vector<B> &b, vector<C> &c) {    assert(sz(a) == sz(b) && sz(b) == sz(c));    vector<T2<A, B, C>> res;    rep(i, sz(a))res.eb(a[i], b[i], c[i]);    return res;}
template<class A, class B, class C, class D> auto vtof(vector<A> &a, vector<B> &b, vector<C> &c, vector<D> &d) {    assert(sz(a) == sz(b) && sz(b) == sz(c) && sz(c) == sz(d));    vector<F2<A, B, C, D>> res;    rep(i, sz(a))res.eb(a[i], b[i], c[i], d[i]);    return res;}
enum pcomparator { fisi, fisd, fdsi, fdsd, sifi, sifd, sdfi, sdfd };
enum tcomparator {    fisiti, fisitd, fisdti, fisdtd, fdsiti, fdsitd, fdsdti, fdsdtd,    fitisi, fitisd, fitdsi, fitdsd, fdtisi, fdtisd, fdtdsi, fdtdsd,    sifiti, sifitd, sifdti, sifdtd, sdfiti, sdfitd, sdfdti, sdfdtd,    sitifi, sitifd, sitdfi, sitdfd, sdtifi, sdtifd, sdtdfi, sdfdfd,    tifisi, tifisd, tifdsi, tifdsd, tdfisi, tdfisd, tdfdsi, tdfdsd,    tisifi, tisifd, tisdfi, tisdfd, tdsifi, tdsifd, tdsdfi, tdsdfd};
template<class A, class B> void sort(vector<pair<A, B>> &a, pcomparator type) {    typedef pair<A, B> U;    if (type == fisi) sort(all(a), [&](U l, U r) { return l.fi != r.fi ? l.fi < r.fi : l.se < r.se; });    else if (type == fisd) sort(all(a), [&](U l, U r) { return l.fi != r.fi ? l.fi < r.fi : l.se > r.se; });    else if (type == fdsi) sort(all(a), [&](U l, U r) { return l.fi != r.fi ? l.fi > r.fi : l.se < r.se; });    else if (type == fdsd) sort(all(a), [&](U l, U r) { return l.fi != r.fi ? l.fi > r.fi : l.se > r.se; });    else if (type == sifi) sort(all(a), [&](U l, U r) { return l.se != r.se ? l.se < r.se : l.fi < r.fi; });    else if (type == sifd) sort(all(a), [&](U l, U r) { return l.se != r.se ? l.se < r.se : l.fi > r.fi; });    else if (type == sdfi) sort(all(a), [&](U l, U r) { return l.se != r.se ? l.se > r.se : l.fi < r.fi; });    else if (type == sdfd) sort(all(a), [&](U l, U r) { return l.se != r.se ? l.se > r.se : l.fi > r.fi; });};template<class U> void sort(vector<U> &a, pcomparator type) {    if (type == fisi) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f < r.f : l.s < r.s; });    else if (type == fisd) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f < r.f : l.s > r.s; });    else if (type == fdsi) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f > r.f : l.s < r.s; });    else if (type == fdsd) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f > r.f : l.s > r.s; });    else if (type == sifi) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s < r.s : l.f < r.f; });    else if (type == sifd) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s < r.s : l.f > r.f; });    else if (type == sdfi) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s > r.s : l.f < r.f; });    else if (type == sdfd) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s > r.s : l.f > r.f; });};template<class A, class B, class C, class D> void sort(vector<F2<A, B, C, D> > &a, pcomparator type) {    typedef F2<A, B, C, D> U;    if (type == fisi) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a < r.a : l.b < r.b; });    else if (type == fisd) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a < r.a : l.b > r.b; });    else if (type == fdsi) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a > r.a : l.b < r.b; });    else if (type == fdsd) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a > r.a : l.b > r.b; });    else if (type == sifi) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b < r.b : l.a < r.a; });    else if (type == sifd) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b < r.b : l.a > r.a; });    else if (type == sdfi) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b > r.b : l.a < r.a; });    else if (type == sdfd) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b > r.b : l.a > r.a; });};template<class U> void sort(vector<U> &a, tcomparator type) {    if (type == 0) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f < r.f : l.s != r.s ? l.s < r.s : l.t < r.t; });    else if (type == 1) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f < r.f : l.s != r.s ? l.s < r.s : l.t > r.t; });    else if (type == 2) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f < r.f : l.s != r.s ? l.s > r.s : l.t < r.t; });    else if (type == 3) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f < r.f : l.s != r.s ? l.s > r.s : l.t > r.t; });    else if (type == 4) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f > r.f : l.s != r.s ? l.s < r.s : l.t < r.t; });    else if (type == 5) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f > r.f : l.s != r.s ? l.s < r.s : l.t > r.t; });    else if (type == 6) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f > r.f : l.s != r.s ? l.s > r.s : l.t < r.t; });    else if (type == 7) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f > r.f : l.s != r.s ? l.s > r.s : l.t > r.t; });    else if (type == 8) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f < r.f : l.t != r.t ? l.t < r.t : l.s < r.s; });    else if (type == 9) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f < r.f : l.t != r.t ? l.t < r.t : l.s > r.s; });    else if (type == 10) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f < r.f : l.t != r.t ? l.t > r.t : l.s < r.s; });    else if (type == 11) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f < r.f : l.t != r.t ? l.t > r.t : l.s > r.s; });    else if (type == 12) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f > r.f : l.t != r.t ? l.t < r.t : l.s < r.s; });    else if (type == 13) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f > r.f : l.t != r.t ? l.t < r.t : l.s > r.s; });    else if (type == 14) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f > r.f : l.t != r.t ? l.t > r.t : l.s < r.s; });    else if (type == 15) sort(all(a), [&](U l, U r) { return l.f != r.f ? l.f > r.f : l.t != r.t ? l.t > r.t : l.s > r.s; });    else if (type == 16) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s < r.s : l.f != r.f ? l.f < r.f : l.t < r.t; });    else if (type == 17) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s < r.s : l.f != r.f ? l.f < r.f : l.t > r.t; });    else if (type == 18) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s < r.s : l.f != r.f ? l.f > r.f : l.t < r.t; });    else if (type == 19) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s < r.s : l.f != r.f ? l.f > r.f : l.t > r.t; });    else if (type == 20) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s > r.s : l.f != r.f ? l.f < r.f : l.t < r.t; });    else if (type == 21) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s > r.s : l.f != r.f ? l.f < r.f : l.t > r.t; });    else if (type == 22) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s > r.s : l.f != r.f ? l.f > r.f : l.t < r.t; });    else if (type == 23) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s > r.s : l.f != r.f ? l.f > r.f : l.t > r.t; });    else if (type == 24) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s < r.s : l.t != r.t ? l.t < r.t : l.f < r.f; });    else if (type == 25) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s < r.s : l.t != r.t ? l.t < r.t : l.f > r.f; });    else if (type == 26) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s < r.s : l.t != r.t ? l.t > r.t : l.f < r.f; });    else if (type == 27) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s < r.s : l.t != r.t ? l.t > r.t : l.f > r.f; });    else if (type == 28) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s > r.s : l.t != r.t ? l.t < r.t : l.f < r.f; });    else if (type == 29) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s > r.s : l.t != r.t ? l.t < r.t : l.f > r.f; });    else if (type == 30) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s > r.s : l.t != r.t ? l.t > r.t : l.f < r.f; });    else if (type == 31) sort(all(a), [&](U l, U r) { return l.s != r.s ? l.s > r.s : l.t != r.t ? l.t > r.t : l.f > r.f; });    else if (type == 32) sort(all(a), [&](U l, U r) { return l.t != r.t ? l.t < r.t : l.f != r.f ? l.f < r.f : l.s < r.s; });    else if (type == 33) sort(all(a), [&](U l, U r) { return l.t != r.t ? l.t < r.t : l.f != r.f ? l.f < r.f : l.s > r.s; });    else if (type == 34) sort(all(a), [&](U l, U r) { return l.t != r.t ? l.t < r.t : l.f != r.f ? l.f > r.f : l.s < r.s; });    else if (type == 35) sort(all(a), [&](U l, U r) { return l.t != r.t ? l.t < r.t : l.f != r.f ? l.f > r.f : l.s > r.s; });    else if (type == 36) sort(all(a), [&](U l, U r) { return l.t != r.t ? l.t > r.t : l.f != r.f ? l.f < r.f : l.s < r.s; });    else if (type == 37) sort(all(a), [&](U l, U r) { return l.t != r.t ? l.t > r.t : l.f != r.f ? l.f < r.f : l.s > r.s; });    else if (type == 38) sort(all(a), [&](U l, U r) { return l.t != r.t ? l.t > r.t : l.f != r.f ? l.f > r.f : l.s < r.s; });    else if (type == 39) sort(all(a), [&](U l, U r) { return l.t != r.t ? l.t > r.t : l.f != r.f ? l.f > r.f : l.s > r.s; });    else if (type == 40) sort(all(a), [&](U l, U r) { return l.t != r.t ? l.t < r.t : l.s != r.s ? l.s < r.s : l.f < r.f; });    else if (type == 41) sort(all(a), [&](U l, U r) { return l.t != r.t ? l.t < r.t : l.s != r.s ? l.s < r.s : l.f > r.f; });    else if (type == 42) sort(all(a), [&](U l, U r) { return l.t != r.t ? l.t < r.t : l.s != r.s ? l.s > r.s : l.f < r.f; });    else if (type == 43) sort(all(a), [&](U l, U r) { return l.t != r.t ? l.t < r.t : l.s != r.s ? l.s > r.s : l.f > r.f; });    else if (type == 44) sort(all(a), [&](U l, U r) { return l.t != r.t ? l.t > r.t : l.s != r.s ? l.s < r.s : l.f < r.f; });    else if (type == 45) sort(all(a), [&](U l, U r) { return l.t != r.t ? l.t > r.t : l.s != r.s ? l.s < r.s : l.f > r.f; });    else if (type == 46) sort(all(a), [&](U l, U r) { return l.t != r.t ? l.t > r.t : l.s != r.s ? l.s > r.s : l.f < r.f; });    else if (type == 47) sort(all(a), [&](U l, U r) { return l.t != r.t ? l.t > r.t : l.s != r.s ? l.s > r.s : l.f > r.f; });}template<class A, class B, class C, class D> void sort(vector<F2<A, B, C, D>> &a, tcomparator type) {    typedef F2<A, B, C, D> U;    if (type == 0) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a < r.a : l.b != r.b ? l.b < r.b : l.c < r.c; });    else if (type == 1) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a < r.a : l.b != r.b ? l.b < r.b : l.c > r.c; });    else if (type == 2) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a < r.a : l.b != r.b ? l.b > r.b : l.c < r.c; });    else if (type == 3) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a < r.a : l.b != r.b ? l.b > r.b : l.c > r.c; });    else if (type == 4) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a > r.a : l.b != r.b ? l.b < r.b : l.c < r.c; });    else if (type == 5) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a > r.a : l.b != r.b ? l.b < r.b : l.c > r.c; });    else if (type == 6) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a > r.a : l.b != r.b ? l.b > r.b : l.c < r.c; });    else if (type == 7) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a > r.a : l.b != r.b ? l.b > r.b : l.c > r.c; });    else if (type == 8) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a < r.a : l.c != r.c ? l.c < r.c : l.b < r.b; });    else if (type == 9) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a < r.a : l.c != r.c ? l.c < r.c : l.b > r.b; });    else if (type == 10) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a < r.a : l.c != r.c ? l.c > r.c : l.b < r.b; });    else if (type == 11) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a < r.a : l.c != r.c ? l.c > r.c : l.b > r.b; });    else if (type == 12) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a > r.a : l.c != r.c ? l.c < r.c : l.b < r.b; });    else if (type == 13) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a > r.a : l.c != r.c ? l.c < r.c : l.b > r.b; });    else if (type == 14) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a > r.a : l.c != r.c ? l.c > r.c : l.b < r.b; });    else if (type == 15) sort(all(a), [&](U l, U r) { return l.a != r.a ? l.a > r.a : l.c != r.c ? l.c > r.c : l.b > r.b; });    else if (type == 16) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b < r.b : l.a != r.a ? l.a < r.a : l.c < r.c; });    else if (type == 17) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b < r.b : l.a != r.a ? l.a < r.a : l.c > r.c; });    else if (type == 18) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b < r.b : l.a != r.a ? l.a > r.a : l.c < r.c; });    else if (type == 19) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b < r.b : l.a != r.a ? l.a > r.a : l.c > r.c; });    else if (type == 20) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b > r.b : l.a != r.a ? l.a < r.a : l.c < r.c; });    else if (type == 21) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b > r.b : l.a != r.a ? l.a < r.a : l.c > r.c; });    else if (type == 22) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b > r.b : l.a != r.a ? l.a > r.a : l.c < r.c; });    else if (type == 23) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b > r.b : l.a != r.a ? l.a > r.a : l.c > r.c; });    else if (type == 24) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b < r.b : l.c != r.c ? l.c < r.c : l.a < r.a; });    else if (type == 25) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b < r.b : l.c != r.c ? l.c < r.c : l.a > r.a; });    else if (type == 26) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b < r.b : l.c != r.c ? l.c > r.c : l.a < r.a; });    else if (type == 27) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b < r.b : l.c != r.c ? l.c > r.c : l.a > r.a; });    else if (type == 28) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b > r.b : l.c != r.c ? l.c < r.c : l.a < r.a; });    else if (type == 29) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b > r.b : l.c != r.c ? l.c < r.c : l.a > r.a; });    else if (type == 30) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b > r.b : l.c != r.c ? l.c > r.c : l.a < r.a; });    else if (type == 31) sort(all(a), [&](U l, U r) { return l.b != r.b ? l.b > r.b : l.c != r.c ? l.c > r.c : l.a > r.a; });    else if (type == 32) sort(all(a), [&](U l, U r) { return l.c != r.c ? l.c < r.c : l.a != r.a ? l.a < r.a : l.b < r.b; });    else if (type == 33) sort(all(a), [&](U l, U r) { return l.c != r.c ? l.c < r.c : l.a != r.a ? l.a < r.a : l.b > r.b; });    else if (type == 34) sort(all(a), [&](U l, U r) { return l.c != r.c ? l.c < r.c : l.a != r.a ? l.a > r.a : l.b < r.b; });    else if (type == 35) sort(all(a), [&](U l, U r) { return l.c != r.c ? l.c < r.c : l.a != r.a ? l.a > r.a : l.b > r.b; });    else if (type == 36) sort(all(a), [&](U l, U r) { return l.c != r.c ? l.c > r.c : l.a != r.a ? l.a < r.a : l.b < r.b; });    else if (type == 37) sort(all(a), [&](U l, U r) { return l.c != r.c ? l.c > r.c : l.a != r.a ? l.a < r.a : l.b > r.b; });    else if (type == 38) sort(all(a), [&](U l, U r) { return l.c != r.c ? l.c > r.c : l.a != r.a ? l.a > r.a : l.b < r.b; });    else if (type == 39) sort(all(a), [&](U l, U r) { return l.c != r.c ? l.c > r.c : l.a != r.a ? l.a > r.a : l.b > r.b; });    else if (type == 40) sort(all(a), [&](U l, U r) { return l.c != r.c ? l.c < r.c : l.b != r.b ? l.b < r.b : l.a < r.a; });    else if (type == 41) sort(all(a), [&](U l, U r) { return l.c != r.c ? l.c < r.c : l.b != r.b ? l.b < r.b : l.a > r.a; });    else if (type == 42) sort(all(a), [&](U l, U r) { return l.c != r.c ? l.c < r.c : l.b != r.b ? l.b > r.b : l.a < r.a; });    else if (type == 43) sort(all(a), [&](U l, U r) { return l.c != r.c ? l.c < r.c : l.b != r.b ? l.b > r.b : l.a > r.a; });    else if (type == 44) sort(all(a), [&](U l, U r) { return l.c != r.c ? l.c > r.c : l.b != r.b ? l.b < r.b : l.a < r.a; });    else if (type == 45) sort(all(a), [&](U l, U r) { return l.c != r.c ? l.c > r.c : l.b != r.b ? l.b < r.b : l.a > r.a; });    else if (type == 46) sort(all(a), [&](U l, U r) { return l.c != r.c ? l.c > r.c : l.b != r.b ? l.b > r.b : l.a < r.a; });    else if (type == 47) sort(all(a), [&](U l, U r) { return l.c != r.c ? l.c > r.c : l.b != r.b ? l.b > r.b : l.a > r.a; });}

void sort(string &a) { sort(all(a)); }
template<class T> void sort(vector<T> &a) { sort(all(a)); }
//P l, P rで f(P) の形で渡す
template<class U, class F> void sort(vector<U> &a, F f) { sort(all(a), [&](U l, U r) { return f(l) < f(r); }); };
template<class T> void rsort(vector<T> &a) { sort(all(a), greater<T>()); };
template<class U, class F> void rsort(vector<U> &a, F f) { sort(all(a), [&](U l, U r) { return f(l) > f(r); }); };
//F = T<T>
//例えばreturn p.fi + p.se;
template<class A, class B> void sortp(vector<A> &a, vector<B> &b) {    auto c = vtop(a, b);    sort(c);    rep(i, sz(a)) a[i] = c[i].fi, b[i] = c[i].se;}template<class A, class B, class F> void sortp(vector<A> &a, vector<B> &b, F f) {    auto c = vtop(a, b);    sort(c, f);    rep(i, sz(a)) a[i] = c[i].fi, b[i] = c[i].se;}template<class A, class B> void rsortp(vector<A> &a, vector<B> &b) {    auto c = vtop(a, b);    rsort(c);    rep(i, sz(a))a[i] = c[i].first, b[i] = c[i].second;}template<class A, class B, class F> void rsortp(vector<A> &a, vector<B> &b, F f) {    auto c = vtop(a, b);    rsort(c, f);    rep(i, sz(a))a[i] = c[i].first, b[i] = c[i].second;}
template<class A, class B, class C> void sortt(vector<A> &a, vector<B> &b, vector<C> &c) {    auto d = vtot(a, b, c);    sort(d);    rep(i, sz(a)) a[i] = d[i].f, b[i] = d[i].s, c[i] = d[i].t;}
template<class A, class B, class C, class F> void sortt(vector<A> &a, vector<B> &b, vector<C> &c, F f) {    auto d = vtot(a, b, c);    sort(d, f);    rep(i, sz(a)) a[i] = d[i].f, b[i] = d[i].s, c[i] = d[i].t;}
template<class A, class B, class C> void rsortt(vector<A> &a, vector<B> &b, vector<C> &c) {    auto d = vtot(a, b, c);    rsort(d);    rep(i, sz(a)) a[i] = d[i].f, b[i] = d[i].s, c[i] = d[i].t;}
template<class A, class B, class C, class F> void rsortt(vector<A> &a, vector<B> &b, vector<C> &c, F f) {    auto d = vtot(a, b, c);    rsort(d, f);    rep(i, sz(a)) a[i] = d[i].f, b[i] = d[i].s, c[i] = d[i].t;}
template<class A, class B, class C, class D> void sortf(vector<A> &a, vector<B> &b, vector<C> &c, vector<D> &d) {    auto e = vtof(a, b, c, d);    sort(e);    rep(i, sz(a)) a[i] = e[i].a, b[i] = e[i].b, c[i] = e[i].c, d[i] = e[i].d;}
template<class A, class B, class C, class D> void rsortf(vector<A> &a, vector<B> &b, vector<C> &c, vector<D> &d) {    auto e = vtof(a, b, c, d);    rsort(e);    rep(i, sz(a)) a[i] = e[i].a, b[i] = e[i].b, c[i] = e[i].c, d[i] = e[i].d;}
//sortindex 元のvectorはソートしない
template<class T> vi sorti(vector<T> &a) {    auto b = a;    vi ind = iota(0, sz(a));    sortp(b, ind);    return ind;}/*indexの分で型が変わるためpcomparatorが必要*/template<class T> vi sorti(vector<T> &a, pcomparator f) {    auto b = a;    vi ind = iota(0, sz(a));    sortp(b, ind, f);    return ind;}template<class T, class F> vi sorti(vector<T> &a, F f) {    vi ind = iota(0, sz(a));    sort(all(ind), [&](ll x, ll y) { return f(a[x]) < f(a[y]); });    return ind;}template<class T> vi rsorti(vector<T> &a) {    auto b = a;    vi ind = iota(0, sz(a));    rsortp(b, ind);    return ind;}template<class T, class F> vi rsorti(vector<T> &a, F f) {    vi ind = iota(0, sz(a));    sort(all(ind), [&](ll x, ll y) { return f(a[x]) > f(a[y]); });    return ind;}template<class A, class B, class F> vi sortpi(vector<A> &a, vector<B> &b, F f) {    auto c = vtop(a, b);    vi ind = iota(0, sz(a));    sort(all(ind), [&](ll x, ll y) { return f(c[x]) < f(c[y]); });    return ind;}template<class A, class B> vi sortpi(vector<A> &a, vector<B> &b, pcomparator f) {    vi ind = iota(0, sz(a));    auto c = a;    auto d = b;    sortt(c, d, ind, f);    return ind;}template<class A, class B> vi sortpi(vector<A> &a, vector<B> &b) { return sortpi(a, b, fisi); };template<class A, class B, class F> vi rsortpi(vector<A> &a, vector<B> &b, F f) {    auto c = vtop(a, b);    vi ind = iota(0, sz(a));    sort(all(ind), [&](ll x, ll y) { return f(c[x]) > f(c[y]); });    return ind;}template<class A, class B> vi rsortpi(vector<A> &a, vector<B> &b) { return sortpi(a, b, fdsd); };template<class A, class B, class C, class F> vi sortti(vector<A> &a, vector<B> &b, vector<C> &c, F f) {    auto d = vtot(a, b, c);    vi ind = iota(0, sz(a));    sort(all(ind), [&](ll x, ll y) { return f(d[x]) < f(d[y]); });    return ind;}template<class A, class B, class C> vi sortti(vector<A> &a, vector<B> &b, vector<C> &c, pcomparator f) {    vi ind = iota(0, sz(a));    auto d = vtof(a, b, c, ind);    sort(d, f);    rep(i, sz(a))ind[i] = d[i].d;    return ind;}template<class A, class B, class C> vi sortti(vector<A> &a, vector<B> &b, vector<C> &c) {    vi ind = iota(0, sz(a));    sort(all(ind), [&](ll x, ll y) {        if (a[x] == a[y]) {            if (b[x] == b[y])return c[x] < c[y];            else return b[x] < b[y];        } else {            return a[x] < a[y];        }    });    return ind;}template<class A, class B, class C, class F> vi rsortti(vector<A> &a, vector<B> &b, vector<C> &c, F f) {    auto d = vtot(a, b, c);    vi ind = iota(0, sz(a));    sort(all(ind), [&](ll x, ll y) { return f(d[x]) > f(d[y]); });    return ind;}template<class A, class B, class C> vi rsortti(vector<A> &a, vector<B> &b, vector<C> &c) {    vi ind = iota(0, sz(a));    sort(all(ind), [&](ll x, ll y) {        if (a[x] == a[y]) {            if (b[x] == b[y])return c[x] > c[y];            else return b[x] > b[y];        } else {            return a[x] > a[y];        }    });    return ind;}
template<class T> void sort2(vector<vector<T >> &a) { for (ll i = 0, n = a.size(); i < n; ++i)sort(a[i]); }
template<class T> void rsort2(vector<vector<T >> &a) { for (ll i = 0, n = a.size(); i < n; ++i)rsort(a[i]); }

template<typename A, size_t N, typename T> void fill(A (&a)[N], const T &v) { rep(i, N)a[i] = v; }template<typename A, size_t N, size_t O, typename T> void fill(A (&a)[N][O], const T &v) { rep(i, N)rep(j, O)a[i][j] = v; }template<typename A, size_t N, size_t O, size_t P, typename T> void fill(A (&a)[N][O][P], const T &v) { rep(i, N)rep(j, O)rep(k, P)a[i][j][k] = v; }template<typename A, size_t N, size_t O, size_t P, size_t Q, typename T> void fill(A (&a)[N][O][P][Q], const T &v) { rep(i, N)rep(j, O)rep(k, P)rep(l, Q)a[i][j][k][l] = v; }template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R, typename T> void fill(A (&a)[N][O][P][Q][R], const T &v) { rep(i, N)rep(j, O)rep(k, P)rep(l, Q)rep(m, R)a[i][j][k][l][m] = v; }template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R, size_t S, typename T> void fill(A (&a)[N][O][P][Q][R][S], const T &v) { rep(i, N)rep(j, O)rep(k, P)rep(l, Q)rep(m, R)rep(n, S)a[i][j][k][l][m][n] = v; }
template<typename W, typename T>void fill(W &xx, const T vall) {    xx = vall;}template<typename W, typename T>void fill(vector<W> &vecc, const T vall) {    for (auto &&vx     : vecc)fill(vx, vall);}
template<typename W,typename T>void fill(vector<W> &xx,const T v,ll len) {rep(i, len)xx[i]=v;}
template<typename W,typename T>void fill(vector<vector<W>> &xx,const T v,ll lh,ll lw) {rep(i, lh)rep(j,lw)xx[i][j]=v;}
template<class T,class U>void fill(vector<T> &a,U val,vi& ind) {fora(v,ind)a[v]=val;}

template<typename A, size_t N> A sum(A (&a)[N]) {    A res = 0;    rep(i, N)res += a[i];    return res;}template<typename A, size_t N, size_t O> A sum(A (&a)[N][O]) {    A res = 0;    rep(i, N)rep(j, O)res += a[i][j];    return res;}template<typename A, size_t N, size_t O, size_t P> A sum(A (&a)[N][O][P]) {    A res = 0;    rep(i, N)rep(j, O)rep(k, P)res += a[i][j][k];    return res;}template<typename A, size_t N, size_t O, size_t P, size_t Q> A sum(A (&a)[N][O][P][Q]) {    A res = 0;    rep(i, N)rep(j, O)rep(k, P)rep(l, Q)res += a[i][j][k][l];    return res;}template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R> A sum(A (&a)[N][O][P][Q][R]) {    A res = 0;    rep(i, N)rep(j, O)rep(k, P)rep(l, Q)rep(m, R)res += a[i][j][k][l][m];    return res;}template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R, size_t S> A sum(A (&a)[N][O][P][Q][R][S]) {    A res = 0;    rep(i, N)rep(j, O)rep(k, P)rep(l, Q)rep(m, R)rep(n, S)res += a[i][j][k][l][m][n];    return res;}
//@汎用便利関数 入力
ll in() {ll ret;cin >> ret;return ret;}
string sin() {string ret;cin >> ret;return ret;}
template<class T>  void in(T &head) { cin >> head; }template<class T, class... U>  void in(T &head, U &... tail) {cin >> head;in(tail...);}

#define o_din(o1, o2, o3, o4, o5, o6, name, ...) name
#define din1(a) ll a;cin>>a
#define din2(a, b) ll a,b;cin>>a>> b
#define din3(a, b, c) ll a,b,c;cin>>a>>b>>c
#define din4(a, b, c, d) ll a,b,c,d;cin>>a>>b>>c>>d
#define din5(a, b, c, d, e) ll a,b,c,d,e;cin>>a>>b>>c>>d>>e
#define din6(a, b, c, d, e, f) ll a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f
#define din(...) o_din(__VA_ARGS__,din6,din5,din4,din3,din2 ,din1)(__VA_ARGS__)

#define o_dind(o1, o2, o3, o4, name, ...) name
#define din1d(a) din1(a);a--
#define din2d(a, b) din2(a,b);a--,b--
#define din3d(a, b, c) din3(a,b,c);a--,b--,c--
#define din4d(a, b, c, d) din4(a,b,c,d);a--,b--,c--,d--
#define dind(...) o_dind(__VA_ARGS__,din4d,din3d,din2d ,din1d)(__VA_ARGS__)

template<class T> void out2(T &&head) { cout << head; }
template<class T, class... U> void out2(T &&head, U &&... tail) {    cout << head << " ";    out2(tail...);}
template<class T, class... U> void out(T &&head, U &&... tail) {    cout << head << " ";    out2(tail...);    cout << "" << endl;}
template<class T> void out(T &&head) {    cout << head  << endl;}
void out() {    cout << ""  << endl;}
#ifdef _DEBUG
template<class T> string out_m(vector<T> &a, ll W = inf) {    stringstream ss;    if (W == inf)W = min(sz(a), 12ll);    ss << endl;    ss << std::right << std::setw(sz(tos(a[0]))) << 0;    rep(i, 1, W) { ss << std::right << std::setw(sz(tos(a[i])) + 1) << i; }    ss << " size : "<<sz(a);    ss << "" << endl;    rep(i, W) { ss << a[i] << " "; }    ss << "" << endl;    return ss.str();}
template<class T> string out_m(vector<vector<T> > &a, ll H = inf, ll W = inf, int key = -1) {    H = min({H, sz(a), 12ll});    W = min({W, sz(a[0]), 12ll});    stringstream ss;    ss << endl;    if (key == -1)ss << " *|"; else ss << " " << key << "|";    rep(w, W)ss << std::right << std::setw(4) << w;    ss << "" << endl;    rep(w, W * 4 + 3)ss << "_";    ss << "" << endl;    rep(h, H) {        ss << std::right << std::setw(2) << h << "|";        rep(w, W) { if (a[h][w] == linf) ss << "  e" << " "; else ss << std::right << std::setw(4) << a[h][w]; }        ss << "" << endl;    }    ss << endl;    return ss.str();}
template<class T> string out_m(vector<vector<vector<T> > > &a, ll H = inf, ll W = inf, ll U = inf) {stringstream ss;    if (H == inf)H = 5;    H = min(H, sz(a));    rep(i, H) {        ss << endl;        ss << out_m(a[i], W, U, i);    }    ss << endl;    return ss.str();}
string out_m(int a) {stringstream ss;ss << a << endl;return ss.str();}
template<class T> string out_m(T &a) {stringstream ss;ss << a << endl;return ss.str();}
template<class T> void outv(vector<T> &a, ll W=inf) {cout << out_m(a,W) << endl;}
template<class T> void outv(vector<vector<T> > &a, ll H = linf, ll W = linf,int key=-1) {    cout << out_m(a,H,W,key) << endl;}
template<class T> void outv(vector<vector<vector<T> > > &a, ll H = linf, ll W = linf,ll U = linf) {cout << out_m(a,H,W,U)<< endl;}
#else
template<class T> void outv(vector<T> &a, ll W=inf) {rep(i,min(W,sz(a))){cout<< a[i]<<" ";}cout << "" << endl;}
template<class T> void outv(vector<vector<T> > &a, ll H = linf, ll W = linf,int key=-1) {rep(i,min(H,sz(a))){outv(a[i],W);}}
template<class T> void outv(vector<vector<vector<T> > > &a, ll H = linf, ll W = linf,ll U = linf) {;}
#endif
template<class T> void outl(vector<T> &a,int n=inf) { rep(i, min(n,sz(a)))cout << a[i] << endl; }
template<class T> void na(vector<T> &a, ll n) {    a.resize(n);    rep(i, n)cin >> a[i];}
#define dna(a, n) vi a(n); rep(dnai,n) cin >> a[dnai];
template<class T> void nao(vector<T> &a, ll n) {    a.resize(n + 1);    a[0] = 0;    rep(i, n)cin >> a[i + 1];}
template<class T> void naod(vector<T> &a, ll n) {    a.resize(n + 1);    a[0] = 0;    rep(i, n)cin >> a[i + 1], a[i + 1]--;}
template<class T> void nad(vector<T> &a, ll n) {    a.resize(n);    rep(i, n)cin >> a[i], a[i]--;}
template<class T, class U> void na2(vector<T> &a, vector<U> &b, ll n) {    a.resize(n);    b.resize(n);    rep(i, n)cin >> a[i] >> b[i];}
#define dna2(a, b, n) vi a(n),b(n);rep(dna2i, n)cin >> a[dna2i] >> b[dna2i];
template<class T, class U> void nao2(vector<T> &a, vector<U> &b, ll n) {    a.resize(n + 1);    b.resize(n + 1);    a[0] = b[0] = 0;    rep(i, n)cin >> a[i + 1] >> b[i + 1];}
#define dna2d(a, b, n) vi a(n),b(n);rep(dna2di, n){cin >> a[dna2di] >> b[dna2di];a[dna2di]--,b[dna2di]--;}
template<class T, class U> void na2d(vector<T> &a, vector<U> &b, ll n) {    a.resize(n);    b.resize(n);    rep(i, n)cin >> a[i] >> b[i], a[i]--, b[i]--;}
template<class T, class U, class W> void na3(vector<T> &a, vector<U> &b, vector<W> &c, ll n) {    a.resize(n);    b.resize(n);    c.resize(n);    rep(i, n)cin >> a[i] >> b[i] >> c[i];}
#define dna3(a, b, c, n) vi a(n),b(n),c(n);   rep(dna3i, n)cin >> a[dna3i] >> b[dna3i] >> c[dna3i];
template<class T, class U, class W> void na3d(vector<T> &a, vector<U> &b, vector<W> &c, ll n) {    a.resize(n);    b.resize(n);    c.resize(n);    rep(i, n)cin >> a[i] >> b[i] >> c[i], a[i]--, b[i]--, c[i]--;}
#define dna3d(a, b, c, n) vi a(n),b(n),c(n);  rep(dna3di, n){cin >> a[dna3di] >> b[dna3di] >> c[dna3di];a[dna3di]--,b[dna3di]--,c[dna3di]--;}
template<class T, class U, class W,class X> void na4(vector<T> &a, vector<U> &b, vector<W> &c,vector<X> &d, ll n) {    a.resize(n);    b.resize(n);    c.resize(n);    d.resize(n);    rep(i, n)cin >> a[i] >> b[i] >> c[i]>> d[i];}
#define dna4(a, b, c,d, n) vi a(n),b(n),c(n),d(n);   rep(dna4i, n)cin >> a[dna4i] >> b[dna4i] >> c[dna4i]>>d[dna4i];
#define dna4d(a, b, c,d, n) vi a(n),b(n),c(n),d(n);   rep(dna4i, n)cin >> a[dna4i] >> b[dna4i] >> c[dna4i]>>d[dna4i],--a[dna4i] ,-- b[dna4i],-- c[dna4i],--d[dna4i];
#define nt(a, h, w) resize(a,h,w);rep(nthi,h)rep(ntwi,w) cin >> a[nthi][ntwi];
#define ntd(a, h, w) resize(a,h,w);rep(ntdhi,h)rep(ntdwi,w) cin >> a[ntdhi][ntdwi], a[ntdhi][ntdwi]--;
#define ntp(a, h, w) resize(a,h+2,w+2);fill(a,'#');rep(ntphi,1,h+1)rep(ntpwi,1,w+1) cin >> a[ntphi][ntpwi];
//デバッグ
#define sp << " " <<

#define debugName(VariableName) # VariableName

#define deb1(x)  debugName(x)<<" = "<<out_m(x)
#define deb2(x, ...) deb1(x) <<", "<< deb1(__VA_ARGS__)
#define deb3(x, ...) deb1(x) <<", "<< deb2(__VA_ARGS__)
#define deb4(x, ...) deb1(x) <<", "<< deb3(__VA_ARGS__)
#define deb5(x, ...) deb1(x) <<", "<< deb4(__VA_ARGS__)
#define deb6(x, ...) deb1(x) <<", "<< deb5(__VA_ARGS__)
#define deb7(x, ...) deb1(x) <<", "<< deb6(__VA_ARGS__)
#define deb8(x, ...) deb1(x) <<", "<< deb7(__VA_ARGS__)
#define deb9(x, ...) deb1(x) <<", "<< deb8(__VA_ARGS__)
#define deb10(x, ...) deb1(x) <<", "<< deb9(__VA_ARGS__)

#define o_ebug(o1, o2, o3, o4, o5, o6, o7, o8, o9, o10, name, ...) name

#ifdef _DEBUG
#define deb(...)  cerr<< o_ebug(__VA_ARGS__,deb10,deb9,deb8,deb7,deb6,deb5,deb4,deb3,deb2,deb1)(__VA_ARGS__) <<endl
#else
#define deb(...) ;
#endif


#define debugline(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n'


//@formatter:off
//よく使うクラス、構造体
struct unionfind {
    vector<ll> par;
    vector<ll> siz;
    vector<ll> es;
    ll n, trees;//連結グループの数(親の種類)
    unionfind(ll n) : n(n), trees(n) {        par.resize(n);        siz.resize(n);        es.resize(n);        for (ll i = 0; i < n; i++) {            par[i] = i;            siz[i] = 1;        }    }
    ll root(ll x) { if (par[x] == x) { return x; } else { return par[x] = root(par[x]); }}
    bool unite(ll x, ll y) {
        x = root(x);
        y = root(y);
        es[x]++;
        if (x == y) return false;
        if (siz[x] > siz[y]) swap(x, y);
        trees--;
        par[x] = y;
        siz[y] += siz[x];
        es[y] += es[x];
        return true;
    }
    bool same(ll x, ll y) { return root(x) == root(y); }
    ll size(ll x) { return siz[root(x)]; }
    ll esize(ll x) { return es[root(x)]; }
    vi sizes(){        vi cou(n);        vi ret;        ret.reserve(n);        rep(i, n){            cou[root (i)]++;        }        rep(i, n){            if(cou[i])ret.push_back(cou[i]);        }        return ret;    }
    //つながりを無向グラフと見なし、xが閉路に含まれるか判定
    bool close(ll x) { return esize(x) >= size(x); }
    V<vi> sets() {        vi ind(n, -1);        ll i = 0;        vvi(res, trees);        rep(j, n) {            ll r = root(j);            if (ind[r] == -1)ind[r] = i++;            res[ind[r]].push_back(j);        }        rep(i, trees) {            ll r = root(res[i][0]);            if (res[i][0] == r)continue;            rep(j, 1, sz(res[i])) {                if (res[i][j] == r) {                    swap(res[i][0], res[i][j]);                    break;                }            }        }        return res;    }
};//@formatter:off


using bll =__int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = __uint128_t;

std::ostream &operator<<(std::ostream &dest, __int128_t value) {    std::ostream::sentry s(dest);    if (s) {        __uint128_t tmp = value < 0 ? -value : value;        char buffer[128];        char *d = std::end(buffer);        do {            --d;            *d = "0123456789"[tmp % 10];            tmp /= 10;        } while (tmp != 0);        if (value < 0) {            --d;            *d = '-';        }        ll len = std::end(buffer) - d;        if (dest.rdbuf()->sputn(d, len) != len) { dest.setstate(std::ios_base::badbit); }    }    return dest;}
//__int128 toi128(string &s) {    __int128 ret = 0;    for (ll i = 0; i < s.length(); ++i)        if ('0' <= s[i] && s[i] <= '9')            ret = 10 * ret + s[i] - '0';    return ret;}


//エラー
void ole() {
#ifdef _DEBUG
    debugline("ole");    exit(0);
#endif
    string a = "a";    rep(i, 30)a += a;    rep(i, 1 << 17)cout << a << endl;    cout << "OLE 出力長制限超過" << endl;    exit(0);}
void re() {    assert(0 == 1);    exit(0);}
void tle() { while (inf)cout << inf << endl; }

//便利関数

//テスト用
char ranc() { return (char) ('a' + rand() % 26); }
ll rand(ll min, ll max) {    assert(min <= max);    if (min >= 0 && max >= 0) { return rand() % (max + 1 - min) + min; } else if (max < 0) { return -rand(-max, -min); } else { if (rand() % 2) { return rand(0, max); } else { return -rand(0, -min); }}}
vi ranv(ll n, ll min, ll max) {    vi v(n);    rep(i, n)v[i] = rand(min, max);    return v;}
str ransu(ll n) {    str s;    rep(i, n)s += (char) rand('A', 'Z');    return s;}
str ransl(ll n) {    str s;    rep(i, n)s += (char) rand('a', 'z');    return s;}
//単調増加
vi ranvinc(ll n, ll min, ll max) {    vi v(n);    bool bad = 1;    while (bad) {        bad = 0;        v.resize(n);        rep(i, n) {            if (i && min > max - v[i - 1]) {                bad = 1;                break;            }            if (i)v[i] = v[i - 1] + rand(min, max - v[i - 1]); else v[i] = rand(min, max);        }    }    return v;}
//便利 汎用
void ranvlr(ll n, ll min, ll max, vi &l, vi &r) {    l.resize(n);    r.resize(n);    rep(i, n) {        l[i] = rand(min, max);        r[i] = l[i] + rand(0, max - l[i]);    }}
vp run_length(vi &a) {    vp ret;    ret.eb(a[0], 1);    rep(i, 1, sz(a)) { if (ret.back().fi == a[i]) { ret.back().se++; } else { ret.eb(a[i], 1); }}    return ret;}
vector<pair<char, ll>> run_length(string &a) {    vector<pair<char, ll>> ret;    ret.eb(a[0], 1);    rep(i, 1, sz(a)) { if (ret.back().fi == a[i]) { ret.back().se++; } else { ret.eb(a[i], 1); }}    return ret;}
template<class F> ll mgr(ll ok, ll ng, F f) {    if (ok < ng)        while (ng - ok > 1) {            ll mid = (ok + ng) / 2;            if (f(mid))ok = mid; else ng = mid;        }    else        while (ok - ng > 1) {            ll mid = (ok + ng) / 2;            if (f(mid))ok = mid; else ng = mid;        }    return ok;}
//strを整数として比較
string smax(str &a, str b) {    if (sz(a) < sz(b)) { return b; }    else if (sz(a) > sz(b)) { return a; }    else if (a < b)return b;    else return a;}
//strを整数として比較
string smin(str &a, str b) {    if (sz(a) > sz(b)) { return b; }    else if (sz(a) < sz(b)) { return a; }    else if (a > b)return b;    else return a;}
template<typename W, typename T> ll find(vector<W> &a, const T key) {    rep(i, sz(a))if (a[i] == key)return i;    return -1;}
template<typename W, typename T> P find(vector<vector<W >> &a, const T key) {    rep(i, sz(a))rep(j, sz(a[0]))if (a[i][j] == key)return mp(i, j);    return mp(-1, -1);}
template<typename W, typename U> T find(vector<vector<vector<W >>> &a, const U key) {    rep(i, sz(a))rep(j, sz(a[0]))rep(k, sz(a[0][0]))if (a[i][j][k] == key)return mt(i, j, k);    return mt(-1, -1, -1);}


template<typename W, typename T> ll count2(W &a, const T k) { return a == k; }
template<typename W, typename T> ll count2(vector<W> &a, const T k) {    ll ret = 0;    fora(v, a)ret += count2(v, k);    return ret;}
template<typename W, typename T> ll count(vector<W> &a, const T k) {    ll ret = 0;    fora(v, a)ret += count2(v, k);    return ret;}
ll count(str &a, str k) {    ll ret = 0, len = k.length();    auto pos = a.find(k);    while (pos != string::npos)pos = a.find(k, pos + len), ++ret;    return ret;}
vi count(str &a) {    vi cou(26);    char c = 'a';    if ('A' <= a[0] && a[0] <= 'Z')c = 'A';    rep(i, sz(a))++cou[a[i] - c];    return cou;}
#define couif count_if
//algorythm


ll rev(ll a) {    ll res = 0;    while (a) {        res *= 10;        res += a % 10;        a /= 10;    }    return res;}
template<class T> void rev(vector<T> &a) { reverse(all(a)); }
template<class U> void rev(vector<vector<U>> &a) {    vector<vector<U> > b(sz(a[0]), vector<U>(sz(a)));    rep(h, sz(a)) rep(w, sz(a[0]))b[w][h] = a[h][w];    a = b;}
void  rev(string &a) { reverse(all(a)); }
constexpr ll p10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000ll, 100000000000ll, 1000000000000ll, 10000000000000ll, 100000000000000ll, 1000000000000000ll, 10000000000000000ll, 100000000000000000ll, 1000000000000000000ll};

ll get(ll a, ll keta) { return (a / (ll) pow(10, keta)) % 10; }
ll keta(ll v) { if (v < p10[9]) { if (v < p10[4]) { if (v < p10[2]) { if (v < p10[1]) return 1; else return 2; } else { if (v < p10[3]) return 3; else return 4; }} else { if (v < p10[7]) { if (v < p10[5]) return 5; else if (v < p10[6])return 6; else return 7; } else { if (v < p10[8])return 8; else return 9; }}} else { if (v < p10[13]) { if (v < p10[11]) { if (v < p10[10]) return 10; else return 11; } else { if (v < p10[12]) return 12; else return 13; }} else { if (v < p10[15]) { if (v < p10[14]) return 14; else if (v < p10[15])return 15; else return 16; } else { if (v < p10[17])return 17; else return 18; }}}}
ll dsum(ll v,ll sin=10) {    ll ret = 0;    for (; v; v /= sin)ret += v % sin;    return ret;}

struct sint {
    ll v;
    sint(ll v) : v(v) {}
    operator ll() { return v; }
    //下からi番目
    ll operator[](ll i) { return (v / p10[i]) % 10; }
    ll back(ll i) { return operator[](i); }
    //上からi番目
    ll top(ll i) {
        ll len = keta(v);
        return operator[](len - 1 - i);
    }
    //先頭からi番目にセット
    ll settop(ll i, ll k) {
        ll len = keta(v);
        return set(len - 1 - i, k);
    }
    ll set(ll i, ll k) {
        if (i < 0)return settop(abs(i) - 1, k);
        return v += p10[i] * (k - (v / p10[i]) % 10);
    }
    ll add(ll i, ll k = 1) { return v += p10[i] * k; }
    ll addtop(ll i, ll k = 1) { return v += p10[keta(v) - i - 1] * k; }
    ll dec(ll i, ll k = 1) { return v -= p10[i] * k; }
    ll dectop(ll i, ll k = 1) { return v -= p10[keta(v) - i - 1] * k; }
#define op(t, o)template<class T> t operator o(T r){return v o r;}
    op(ll, +=);    op(ll, -=);    op(ll, *=);    op(ll, /=);    op(ll, %=);    op(ll, +);    op(ll, -);    op(ll, *);    op(ll, /);    op(ll, %);    op(bool, ==);    op(bool, !=);    op(bool, <);    op(bool, <=);    op(bool, >);    op(bool, >=);
#undef op
    template<class T>  ll operator<<=(T r) { return v *= p10[r]; }
    template<class T>  ll operator<<(T r) { return v * p10[r]; }
    template<class T>  ll operator>>=(T r) { return v /= p10[r]; }
    template<class T>  ll operator>>(T r) { return v / p10[r]; }
};
ll mask10(ll v) { return p10[v] - 1; }
//変換系
template<class T> auto keys(T a) {    vector<decltype((a.begin())->fi)> res;    for (auto &&k :a)res.push_back(k.fi);    return res;}
template<class T> auto values(T a) {    vector<decltype((a.begin())->se)> res;    for (auto &&k :a)res.push_back(k.se);    return res;}
template<class T, class U>  bool chma(T &a, const U &b) {    if (a < b) {        a = b;        return true;    }    return false;}
template<class U>  bool chma(const U &b) { return chma(ma, b); }
template<class T, class U>  bool chmi(T &a, const U &b) {    if (b < a) {        a = b;        return true;    }    return false;}
template<class U>  bool chmi(const U &b) { return chmi(mi, b); }
template<class T>  T min(T a, signed b) { return a < b ? a : b; }
template<class T>  T max(T a, signed b) { return a < b ? b : a; }
template<class T>  T min(T a, T b, T c) { return a >= b ? b >= c ? c : b : a >= c ? c : a; }
template<class T>  T max(T a, T b, T c) { return a <= b ? b <= c ? c : b : a <= c ? c : a; }
template<class T>  T min(vector<T>& a) { return *min_element(all(a)); }
template<class T>  T mini(vector<T>& a) { return min_element(all(a)) - a.begin(); }
template<class T>  T min(vector<T>& a, ll n) { return *min_element(a.begin(), a.begin() + min(n, sz(a))); }
template<class T>  T min(vector<T>& a, ll s, ll n) { return *min_element(a.begin() + s, a.begin() + min(n, sz(a))); }
template<class T>  T max(vector<T>& a) { return *max_element(all(a)); }
template<class T,class U>  T max(vector<T>& a,vector<U>& b) { return max(*max_element(all(a)),*max_element(all(b))); }
template<class T>  T maxi(vector<T>& a) { return max_element(all(a)) - a.begin(); }
template<class T>  T max(vector<T>& a, ll n) { return *max_element(a.begin(), a.begin() + min(n, sz(a))); }
template<class T>  T max(vector<T>& a, ll s, ll n) { return *max_element(a.begin() + s, a.begin() + min(n, sz(a))); }
template<typename A, size_t N>  A max(A (&a)[N]) {    A res = a[0];    rep(i, N)res = max(res, a[i]);    return res;}template<typename A, size_t N, size_t O>  A max(A (&a)[N][O]) {    A res = max(a[0]);    rep(i, N)res = max(res, max(a[i]));    return res;}template<typename A, size_t N, size_t O, size_t P>  A max(A (&a)[N][O][P]) {    A res = max(a[0]);    rep(i, N)res = max(res, max(a[i]));    return res;}template<typename A, size_t N, size_t O, size_t P, size_t Q>  A max(A (&a)[N][O][P][Q], const T &v) {    A res = max(a[0]);    rep(i, N)res = max(res, max(a[i]));    return res;}template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R>  A max(A (&a)[N][O][P][Q][R]) {    A res = max(a[0]);    rep(i, N)res = max(res, max(a[i]));    return res;}template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R, size_t S>  A max(A (&a)[N][O][P][Q][R][S]) {    A res = max(a[0]);    rep(i, N)res = max(res, max(a[i]));    return res;}
template<typename A, size_t N>  A min(A (&a)[N]) {    A res = a[0];    rep(i, N)res = min(res, a[i]);    return res;}template<typename A, size_t N, size_t O>  A min(A (&a)[N][O]) {    A res = min(a[0]);    rep(i, N)res = min(res, max(a[i]));    return res;}template<typename A, size_t N, size_t O, size_t P>  A min(A (&a)[N][O][P]) {    A res = min(a[0]);    rep(i, N)res = min(res, min(a[i]));    return res;}template<typename A, size_t N, size_t O, size_t P, size_t Q>  A min(A (&a)[N][O][P][Q], const T &v) {    A res = min(a[0]);    rep(i, N)res = min(res, min(a[i]));    return res;}template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R>  A min(A (&a)[N][O][P][Q][R]) {    A res = min(a[0]);    rep(i, N)res = min(res, min(a[i]));    return res;}template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R, size_t S>  A min(A (&a)[N][O][P][Q][R][S]) {    A res = min(a[0]);    rep(i, N)res = min(res, min(a[i]));    return res;}
template<class T> T sum(vector<T> &v, ll s = 0, ll t = inf) {    T ret = 0;    rep(i, s, min(sz(v), t))ret += v[i];    return ret;}template<class T> T sum(vector<vector<T> > &v) {    T ret = 0;    rep(i, sz(v))ret += sum(v[i]);    return ret;}template<class T> T sum(vector<vector<vector<T> > > &v) {    T ret = 0;    rep(i, sz(v))ret += sum(v[i]);    return ret;}template<class T> T sum(vector<vector<vector<vector<T> > > > &v) {    T ret = 0;    rep(i, sz(v))ret += sum(v[i]);    return ret;}template<class T> T sum(vector<vector<vector<vector<vector<T> > > > > &v) {    T ret = 0;    rep(i, sz(v))ret += sum(v[i]);    return ret;}template<class T> auto sum(priority_queue<T, vector<T>, greater<T> > &r) {    auto q = r;    T ret = 0;    while (sz(q)) {        ret += q.top();        q.pop();    }    return ret;}template<class T> auto sum(priority_queue<T> &r) {    auto q = r;    T ret = 0;    while (sz(q)) {        ret += q.top();        q.pop();    }    return ret;}
//template<class T, class U, class... W>  auto sumn(vector<T> &v, U head, W... tail) {    auto ret = sum(v[0], tail...);    rep(i, 1, min(sz(v), head))ret += sum(v[i], tail...);    return ret;}
void clear(PQ &q) { q = PQ(); }
template<class T> void clear(queue<T> &q) { while (q.size())q.pop(); }
template<class T> T *negarr(ll size) {    T *body = (T *) malloc((size * 2 + 1) * sizeof(T));    return body + size;}
template<class T> T *negarr2(ll h, ll w) {    double **dummy1 = new double *[2 * h + 1];    double *dummy2 = new double[(2 * h + 1) * (2 * w + 1)];    dummy1[0] = dummy2 + w;    for (ll i = 1; i <= 2 * h + 1; ++i) { dummy1[i] = dummy1[i - 1] + 2 * w + 1; }    double **a = dummy1 + h;    return a;}
//imoは0-indexed
//ruiは1-indexed
template<class T> vector<T> imo(vector<T> &v) {    vector<T> ret = v;    rep(i, sz(ret) - 1)ret[i + 1] += ret[i];    return ret;}
//kと同じものの数
template<class T, class U> vi imo(vector<T> &a, U k) {vector<T> ret = a;rep(i, sz(ret))ret[i] = a[i] == k;rep(i, sz(ret) - 1)ret[i + 1] += ret[i];return ret;}
template<class T> vector<T> imox(vector<T> &v) {    vector<T> ret = v;    rep(i, sz(ret) - 1)ret[i + 1] ^= ret[i];    return ret;}
//漸化的に最小を持つ
template<class T> vector<T> imi(vector<T> &v) {    vector<T> ret = v;    rep(i, sz(ret) - 1)chmi(ret[i + 1], ret[i]);    return ret;}
template<class T> struct ruiC {    const vector<T> rui;    ruiC(vector<T> &ru) : rui(ru) {}    T operator()(ll l, ll r) {        if (l > r) {            cerr<<"ruic ";deb(l, r);assert(0);        }        return rui[r] - rui[l];    }    T operator[](ll i) { return rui[i]; }    T back() { return rui.back(); }    ll size() { return rui.size(); }};
template<class T> struct rruic {    const T *rrui;    rruic(T *ru) : rrui(ru) {}     T operator()(ll l, ll r) {        assert(l >= r);        return rrui[r] - rrui[l];    }     T operator[](ll i) { return rrui[i]; }};
template<class T> vector<T> ruiv(vector<T> &a) {    vector<T> ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] + a[i];    return ret;}
template<class T> ruiC<T> ruic(vector<T> &a) {    vector<T> ret = ruiv(a);    return ruiC<T>(ret);}
vector<ll> ruiv(string &a) {    if (sz(a) == 0)return vi(1);    ll dec = ('0' <= a[0] && a[0] <= '9') ? '0' : 0;    vector<ll> ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] + a[i] - dec;    return ret;}
ruiC<ll> ruic(string &a) {    vector<ll> ret = ruiv(a);    return ruiC<ll>(ret);}
//kと同じものの数
template<class T, class U> vi ruiv(T &a, U k) {    vi ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] + (a[i] == k);    return ret;}
template<class T, class U> ruiC<ll> ruic(T &a, U k) {    vi ret = ruiv(a, k);    return ruiC<ll>(ret);}
//xor
template<class T> struct ruixC {    const vector<T> rui;    ruixC(vector<T> &ru) : rui(ru) {}    T operator()(ll l, ll r) {        if (l > r) {            cerr << "ruiXc ";            deb(l, r);            assert(0);        }        return rui[r] ^ rui[l];    }    T operator[](ll i) { return rui[i]; }    T back() { return rui.back(); }    ll size() { return rui.size(); }};
template<class T> vector<T> ruix(vector<T> &a) {    vector<T> ret(a.size() + 1);    rep(i, a.size())ret[i + 1] = ret[i] ^ a[i];    return ret;}
template<class T> ruixC<ll> ruixc(vector<T>  &a) {vi ret = ruix(a);return ruixC<ll>(ret);}
template<class T> vector<T> ruim(vector<T> &a) {    vector<T> res(a.size() + 1, 1);    rep(i, a.size())res[i + 1] = res[i] * a[i];    return res;}
//漸化的に最小を1indexで持つ
template<class T> vector<T> ruimi(vector<T> &a) {    ll n = sz(a);    vector<T> ret(n + 1);    rep(i, 1, n) {        ret[i] = a[i - 1];        chmi(ret[i + 1], ret[i]);    }    return ret;}
//template<class T> T *rrui(vector<T> &a) {
//右から左にかけての半開区間 (-1 n-1]
template<class T> rruic<T> rrui(vector<T> &a) {    ll len = a.size();    T *body = (T *) malloc((len + 1) * sizeof(T));    T *res = body + 1;    rer(i, len - 1)res[i - 1] = res[i] + a[i];    return rruic<T>(res);}
//掛け算
template<class T> T *rruim(vector<T> &a) {    ll len = a.size();    T *body = (T *) malloc((len + 1) * sizeof(T));    T *res = body + 1;    res[len - 1] = 1;    rer(i, len - 1)res[i - 1] = res[i] * a[i];    return res;}
template<class T, class U> void inc(T &a, U v = 1) { a += v; }
template<class T, class U> void inc(vector<T> &a, U v = 1) { for (auto &u:a)inc(u, v); }
template<class T, class U> void dec(T &a, U v = 1) { a -= v; }
template<class T, class U> void dec(vector<T> &a, U v = 1) { for (auto &u :a)dec(u, v); }
template<class U> void dec(string &a, U v = 1) { for (auto &u :a)dec(u, v); }
template<class T> void dec(vector<T> &a) { for (auto &u :a)dec(u, 1); }
template<class T,class U> void dec(vector<T> &a,vector<U> &b) { for (auto &u :a)dec(u, 1);for (auto &u :b)dec(u, 1); }
template<class T,class U,class W> void dec(vector<T> &a,vector<U> &b,vector<W>&c ) { for (auto &u :a)dec(u, 1);for (auto &u :b)dec(u, 1);for (auto &u :c)dec(u, 1); }
bool ins(ll h, ll w, ll H, ll W) { return h >= 0 && w >= 0 && h < H && w < W; }
bool ins(ll l, ll v, ll r) { return l <= v && v < r; }
template<class T> bool ins(vector<T> &a, ll i, ll j = 0) { return ins(0, i, sz(a)) && ins(0, j, sz(a)); }
ll u(ll a) { return a < 0 ? 0 : a; }
template<class T> vector<T> u(const vector<T> &a) {    vector<T> ret = a;    fora(v, ret)v = u(v);    return ret;}
#define MIN(a) numeric_limits<a>::min()
#define MAX(a) numeric_limits<a>::max()
template<class F> ll goldd_l(ll left, ll right, F calc) {    double GRATIO = 1.6180339887498948482045868343656;    ll lm = left + (ll) ((right - left) / (GRATIO + 1.0));    ll rm = lm + (ll) ((right - lm) / (GRATIO + 1.0));    ll fl = calc(lm);    ll fr = calc(rm);    while (right - left > 10) {        if (fl < fr) {            right = rm;            rm = lm;            fr = fl;            lm = left + (ll) ((right - left) / (GRATIO + 1.0));            fl = calc(lm);        } else {            left = lm;            lm = rm;            fl = fr;            rm = lm + (ll) ((right - lm) / (GRATIO + 1.0));            fr = calc(rm);        }    }    ll minScore = MAX(ll);    ll resIndex = left;    for (ll i = left; i < right + 1; ++i) {        ll score = calc(i);        if (minScore > score) {            minScore = score;            resIndex = i;        }    }    return resIndex;}
template<class F> ll goldt_l(ll left, ll right, F calc) {        double GRATIO = 1.6180339887498948482045868343656;        ll lm = left + (ll) ((right - left) / (GRATIO + 1.0));        ll rm = lm + (ll) ((right - lm) / (GRATIO + 1.0));        ll fl = calc(lm);        ll fr = calc(rm);        while (right - left > 10) {            if (fl > fr) {                right = rm;                rm = lm;                fr = fl;                lm = left + (ll) ((right - left) / (GRATIO + 1.0));                fl = calc(lm);            } else {                left = lm;                lm = rm;                fl = fr;                rm = lm + (ll) ((right - lm) / (GRATIO + 1.0));                fr = calc(rm);            }        }    if (left > right) {        ll l = left;        left = right;        right = l;    }    ll maxScore = MIN(ll);    ll resIndex = left;    for (ll i = left; i < right + 1; ++i) {        ll score = calc(i);        if (maxScore < score) {            maxScore = score;            resIndex = i;        }    }    return resIndex;}
/*loopは200にすればおそらく大丈夫 余裕なら300に*/
template<class F> dou goldd_d(dou left, dou right, F calc, ll loop = 140) {    dou GRATIO = 1.6180339887498948482045868343656;    dou lm = left + ((right - left) / (GRATIO + 1.0));    dou rm = lm + ((right - lm) / (GRATIO + 1.0));    dou fl = calc(lm);    dou fr = calc(rm);    /*200にすればおそらく大丈夫*/    /*余裕なら300に*/    ll k = 141;    loop++;    while (--loop) {        if (fl < fr) {            right = rm;            rm = lm;            fr = fl;            lm = left + ((right - left) / (GRATIO + 1.0));            fl = calc(lm);        } else {            left = lm;            lm = rm;            fl = fr;            rm = lm + ((right - lm) / (GRATIO + 1.0));            fr = calc(rm);        }    }    return left;}
template<class F> dou goldt_d(dou left, dou right, F calc, ll loop = 140) {    double GRATIO = 1.6180339887498948482045868343656;    dou lm = left + ((right - left) / (GRATIO + 1.0));    dou rm = lm + ((right - lm) / (GRATIO + 1.0));    dou fl = calc(lm);    dou fr = calc(rm);    loop++;    while (--loop) {        if (fl > fr) {            right = rm;            rm = lm;            fr = fl;            lm = left + ((right - left) / (GRATIO + 1.0));            fl = calc(lm);        } else {            left = lm;            lm = rm;            fl = fr;            rm = lm + ((right - lm) / (GRATIO + 1.0));            fr = calc(rm);        }    }    return left;}
//l ~ rを複数の区間に分割し、極致を与えるiを返す time-20 msまで探索
template<class F> ll goldd_ls(ll l, ll r, F calc, ll time = 2000) {    auto lim = milliseconds(time - 20);    ll mini = 0, minv = MAX(ll);    /*区間をk分割する*/    rep(k, 1, inf) {        auto s = system_clock::now();        ll haba = (r - l + k) / k;/*((r-l+1) + k-1) /k*/        ll nl = l;        ll nr = l + haba;        rep(i, k) {            ll ni = goldd_l(nl, nr, calc);            if (chmi(minv, calc(ni))) mini = ni;            nl = nr;            nr = nl + haba;        }        auto end = system_clock::now();        auto part = duration_cast<milliseconds>(end - s);        auto elapsed = duration_cast<milliseconds>(end - start_time);        if (elapsed + part * 2 >= lim) { break; }    }    return mini;}
template<class F> ll goldt_ls(ll l, ll r, F calc, ll time = 2000) {    auto lim = milliseconds(time - 20);    ll maxi = 0, maxv = MIN(ll);    /*区間をk分割する*/    rep(k, 1, inf) {        auto s = system_clock::now();        ll haba = (r - l + k) / k;/*((r-l+1) + k-1) /k*/        ll nl = l;        ll nr = l + haba;        rep(i, k) {            ll ni = goldt_l(nl, nr, calc);            if (chma(maxv, calc(ni))) maxi = ni;            nl = nr;            nr = nl + haba;        }        auto end = system_clock::now();        auto part = duration_cast<milliseconds>(end - s);        auto elapsed = duration_cast<milliseconds>(end - start_time);        if (elapsed + part * 2 >= lim) { break; }    }    return maxi;}
template<class F> dou goldd_d_s(dou l, dou r, F calc, ll time = 2000) {    /*20ms余裕を持つ*/    auto lim = milliseconds(time - 20);    dou mini = 0, minv = MAX(dou);    /*区間をk分割する*/    rep(k, 1, inf) {        auto s = system_clock::now();        dou haba = (r - l) / k;        dou nl = l;        dou nr = l + haba;        rep(i, k) {            dou ni = goldd_d(nl, nr, calc);            if (chmi(minv, calc(ni))) mini = ni;            nl = nr;            nr = nl + haba;        }        auto end = system_clock::now();        auto part = duration_cast<milliseconds>(end - s);        auto elapsed = duration_cast<milliseconds>(end - start_time);        if (elapsed + part * 2 >= lim) { break; }    }    return mini;}
template<class F> dou goldt_d_s(dou l, dou r, F calc, ll time = 2000) {    /*20ms余裕を残している*/    auto lim = milliseconds(time - 20);    dou maxi = 0, maxv = MIN(dou);    /*区間をk分割する*/    rep(k, 1, inf) {        auto s = system_clock::now();        dou haba = (r - l) / k;        dou nl = l;        dou nr = l + haba;        rep(i, k) {            dou ni = goldt_d(nl, nr, calc);            if (chma(maxv, calc(ni))) maxi = ni;            nl = nr;            nr = nl + haba;        }        auto end = system_clock::now();        auto part = duration_cast<milliseconds>(end - s);        auto elapsed = duration_cast<milliseconds>(end - start_time);        if (elapsed + part * 2 >= lim) { break; }    }    return maxi;}
template<class T> T min(vector<vector<T >> &a) {    T res = MAX(T);    rep(i, a.size())chmi(res, *min_element(all(a[i])));    return res;}
template<class T> T max(vector<vector<T >> &a) {    T res = MIN(T);    rep(i, a.size())chma(res, *max_element(all(a[i])));    return res;}
constexpr bool bget(ll m, ll keta) { return (m >> keta) & 1; }
ll bget(ll m, ll keta, ll sinsuu) {    m /= (ll) pow(sinsuu, keta);    return m % sinsuu;}
ll bit(ll n) { return (1LL << (n)); }
ll bit(ll n, ll sinsuu) { return (ll) pow(sinsuu, n); }
ll mask(ll n) { return (1ll << n) - 1; }
#define bcou __builtin_popcountll
//最下位ビット
ll lbit(ll n) { return n & -n; }
//最上位ビット
ll hbit(ll n) {    n |= (n >> 1);    n |= (n >> 2);    n |= (n >> 4);    n |= (n >> 8);    n |= (n >> 16);    n |= (n >> 32);    return n - (n >> 1);}
ll hbitk(ll n) {    ll k = 0;    rer(i, 5) {        ll a = k + (1ll << i);        ll b = 1ll << a;        if (b <= n)k += 1ll << i;    }    return k;}
//初期化は0を渡す
ll nextComb(ll &mask, ll n, ll r) {    if (!mask)return mask = (1LL << r) - 1;    ll x = mask & -mask; /*最下位の1*/    ll y = mask + x; /*連続した下の1を繰り上がらせる*/    ll res = ((mask & ~y) / x >> 1) | y;    if (bget(res, n))return mask = 0; else return mask = res;}
//n桁以下でビットがr個立っているもののvectorを返す
vi bitCombList(ll n, ll r) {    vi res;    ll m = 0;    while (nextComb(m, n, r)) { res.push_back(m); }    return res;}
char itoal(ll i) { return 'a' + i; }
char itoaL(ll i) { return 'A' + i; }
ll altoi(char c) {    if ('A' <= c && c <= 'Z')return c - 'A';    return c - 'a';}
ll ctoi(char c) { return c - '0'; }
char itoc(ll i) { return i + '0'; }
ll vtoi(vi &v) {    ll res = 0;    if (sz(v) > 18) {        debugline("vtoi");        deb(sz(v));        ole();    }    rep(i, sz(v)) {        res *= 10;        res += v[i];    }    return res;}
vi itov(ll i) {    vi res;    while (i) {        res.push_back(i % 10);        i /= 10;    }    rev(res);    return res;}
vi stov(string &a) {    ll n = sz(a);    vi ret(n);    rep(i, n) { ret[i] = a[i] - '0'; }    return ret;}
//基準を満たさないものは0になる
vi stov(string &a, char one) {    ll n = sz(a);    vi ret(n);    rep(i, n)ret[i] = a[i] == one;    return ret;}
vector<vector<ll>> ctoi(vector<vector<char>> s, char c) {    ll n = sz(s), m = sz(s[0]);    vector<vector<ll>> res(n, vector<ll>(m));    rep(i, n)rep(j, m)res[i][j] = s[i][j] == c;    return res;}
#define unique(v) v.erase( unique(v.begin(), v.end()), v.end() );
//[i] := i番として圧縮されたものを返す
vi compress(vi &a) {    vi b;    ll len = a.size();    for (ll i = 0; i < len; ++i) { b.push_back(a[i]); }    sort(b);    unique(b);    for (ll i = 0; i < len; ++i) { a[i] = lower_bound(all(b), a[i]) - b.begin(); }    ll blen = sz(b);    vi ret(blen);    rep(i, blen) { ret[i] = b[i]; }    return ret;}
vi compress(vi &a, umap<ll, ll> &map) {    vi b;    ll len = a.size();    for (ll i = 0; i < len; ++i) { b.push_back(a[i]); }    sort(b);    unique(b);    for (ll i = 0; i < len; ++i) {        ll v = a[i];        a[i] = lower_bound(all(b), a[i]) - b.begin();        map[v] = a[i];    }    ll blen = sz(b);    vi ret(blen);    rep(i, blen) { ret[i] = b[i]; }    return ret;}
vi compress(vi &a, vi &r) {    vi b;    ll len = a.size();    fora(v, a)b.push_back(v);    fora(v, r)b.push_back(v);    sort(b);    unique(b);    for (ll i = 0; i < len; ++i) a[i] = lower_bound(all(b), a[i]) - b.begin();    for (ll i = 0; i < sz(r); ++i) r[i] = lower_bound(all(b), r[i]) - b.begin();    ll blen = sz(b);    vi ret(blen);    rep(i, blen) { ret[i] = b[i]; }    return ret;}
vi compress(vi &a, vi &r, vi &s) {    vi b;    ll len = a.size();    fora(v, a)b.push_back(v);    fora(v, r)b.push_back(v);    fora(v, s)b.push_back(v);    sort(b);    unique(b);    for (ll i = 0; i < len; ++i) a[i] = lower_bound(all(b), a[i]) - b.begin();    for (ll i = 0; i < sz(r); ++i) r[i] = lower_bound(all(b), r[i]) - b.begin();    for (ll i = 0; i < sz(s); ++i) r[i] = lower_bound(all(b), s[i]) - b.begin();    ll blen = sz(b);    vi ret(blen);    rep(i, blen) { ret[i] = b[i]; }    return ret;}
vi compress(V<vi> &a) {    vi b;    fora(vv, a)fora(v, vv)b.push_back(v);    sort(b);    unique(b);    fora(vv, a)fora(v, vv)v = lower_bound(all(b), v) - b.begin();    ll blen = sz(b);    vi ret(blen);    rep(i, blen) { ret[i] = b[i]; }    return ret;}
vi compress(vector<vector<vi >> &a) {    vi b;    fora(vvv, a)fora(vv, vvv)fora(v, vv)b.push_back(v);    sort(b);    unique(b);    fora(vvv, a)fora(vv, vvv)fora(v, vv)v = lower_bound(all(b), v) - b.begin();    ll blen = sz(b);    vi ret(blen);    rep(i, blen) { ret[i] = b[i]; }    return ret;}
void compress(ll a[], ll len) {    vi b;    for (ll i = 0; i < len; ++i) { b.push_back(a[i]); }    sort(b);    unique(b);    for (ll i = 0; i < len; ++i) { a[i] = lower_bound(all(b), a[i]) - b.begin(); }}
//要素が見つからなかったときに困る
#define binarySearch(a, v) (binary_search(all(a),v))
#define lowerIndex(a, v) (lower_bound(all(a),v)-a.begin())
#define lowerBound(a, v) (*lower_bound(all(a),v))
#define upperIndex(a, v) (upper_bound(all(a),v)-a.begin())
#define upperBound(a, v) (*upper_bound(all(a),v))
template<class T> void fin(T s) { cout << s << endl, exit(0); }

//便利 数学 math
ll mod(ll a, ll m) { return (a % m + m) % m; }
ll pow(ll a) { return a * a; };
ll fact(ll v) { return v <= 1 ? 1 : v * fact(v - 1); }

ll comi(ll n, ll r) {    assert(n < 100);    static vvi(pas, 100, 100);    if (pas[0][0])return pas[n][r];    pas[0][0] = 1;    rep(i, 1, 100) {        pas[i][0] = 1;        rep(j, 1, i + 1)pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];    }    return pas[n][r];}
double comd(ll n, ll r) {    assert(n < 2020);    static vvd(comb, 2020, 2020);    if (comb[0][0] == 0) {        comb[0][0] = 1;        rep(i, 2000) {            comb[i + 1][0] = 1;            rep(j, 1, i + 2) {                comb[i + 1][j] = comb[i][j] + comb[i][j - 1];            }        }    }    return comb[n][r];}
ll gcd(ll a, ll b) {while (b) a %= b, swap(a, b);return abs(a);}
ll gcd(vi b) {ll res = b[0];rep(i, 1, sz(b))res = gcd(b[i], res);return res;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll lcm(vi a) {ll res = a[0];rep(i, 1, sz(a))res = lcm(a[i], res);return res;}
ll ceil(ll a, ll b) {if (b == 0) {debugline("ceil");deb(a, b);ole();return -1;} else if (a < 0) { return 0; } else { return (a + b - 1) / b; }}
ll lower_remi__bx_a(ll kei, ll rem, ll x) {if (rem >= x) return 0;return (x - rem + kei - 1) / kei;}
ll lower_remv__bx_a(ll kei, ll rem, ll x) {if (rem >= x) return rem;return (x - rem + kei - 1) / kei * kei + rem;}
ll upper_remi__bx_a(ll kei, ll rem, ll x) {if (rem > x) return 0;return (x - rem + kei) / kei;}
ll upper_remv__bx_a(ll kei, ll rem, ll x) {if (rem > x) return rem;return (x - rem + kei) / kei * kei + rem;}
//v * v >= aとなる最小のvを返す
ll sqrt(ll a) {if (a < 0) {debugline("sqrt");deb(a);ole();}ll res = (ll) std::sqrt(a);while (res * res < a)++res;return res;}
double log(double e, double x) { return log(x) / log(e); }
ll sig(ll t) { return ((1 + t) * t) >> 1; }
ll sig(ll s, ll t) { return ((s + t) * (t - s + 1)) >> 1; }


//幾何 Pをcomplexとして扱う
template<class T, class U> bool eq(T a, U b) { return fabs(a - b) < eps; }
dou atan2(pd a) { return atan2(a.se, a.fi); }
dou angle(pd f, pd t) { return atan2(t.se - f.se, t.fi - f.fi); }
dou distance(pd a, pd b) { return hypot(a.fi - b.fi, a.se - b.se); }
//bを中心とするabcのtheta aからcにかけて時計回り
dou angle(pd a, pd b, pd c) {    dou ax = a.fi - b.fi;    dou ay = a.se - b.se;    dou cx = c.fi - b.fi;    dou cy = c.se - b.se;    double ret = atan2(cy, cx) - atan2(ay, ax);    if (ret < 0) ret += 2 * PI;    return ret;}

dou dot(pd a, pd b) { return a.fi * b.fi + a.se + b.se; }
dou cro(pd a, pd b) { return a.fi * b.se - a.se + b.fi; }

//機能拡張
template<typename CharT, typename Traits, typename Alloc>basic_string<CharT, Traits, Alloc>operator+(const basic_string<CharT, Traits, Alloc> &lhs, const int rv) {    basic_string<CharT, Traits, Alloc> str(lhs);    str.append(to_string(rv));    return str;}template<typename CharT, typename Traits, typename Alloc>void operator+=(basic_string<CharT, Traits, Alloc> &lhs, const int rv) {    lhs += to_string(rv);}template<typename CharT, typename Traits, typename Alloc>basic_string<CharT, Traits, Alloc>operator+(const basic_string<CharT, Traits, Alloc> &lhs, const signed rv) {    basic_string<CharT, Traits, Alloc> str(lhs);    str.append(to_string(rv));    return str;}template<typename CharT, typename Traits, typename Alloc>void operator+=(basic_string<CharT, Traits, Alloc> &lhs, const signed rv) {    lhs += to_string(rv);}
template<class T, class U> void operator+=(queue<T> &a, U v) { a.push(v); }template<class T, class U> void operator+=(deque<T> &a, U v) { a.push_back(v); }template<class T> priority_queue<T, vector<T>, greater<T> > &operator+=(priority_queue<T, vector<T>, greater<T> > &a, vector<T> &v) {    fora(d, v)a.push(d);    return a;}template<class T, class U> priority_queue<T, vector<T>, greater<T> > &operator+=(priority_queue<T, vector<T>, greater<T> > &a, U v) {    a.push(v);    return a;}template<class T, class U> priority_queue<T> &operator+=(priority_queue<T> &a, U v) {    a.push(v);    return a;}template<class T> set<T> &operator+=(set<T> &a, vector<T> v) {    fora(d, v)a.insert(d);    return a;}template<class T, class U> auto operator+=(set<T> &a, U v) { return    a.insert(v);}template<class T, class U> auto operator-=(set<T> &a, U v) { return    a.erase(v);}template<class T, class U> auto operator+=(mset<T> &a, U v) { return a.insert(v); }template<class T, class U> set<T, greater<T>> &operator+=(set<T, greater<T>> &a, U v) {    a.insert(v);    return a;}template<class T, class U> vector<T> &operator+=(vector<T> &a, U v) {    a.push_back(v);    return a;}template<class T, class U> vector<T> operator+(const vector<T> &a, U v) {    vector<T> ret = a;    ret += v;    return ret;}template<class T, class U> vector<T> operator+(U v, const vector<T> &a) {    vector<T> ret = a;    ret.insert(ret.begin(), v);    return ret;}template<class T> vector<T> operator+(vector<T> a, vector<T> b) {    vector<T> ret;    ret = a;    fora(v, b)ret += v;    return ret;}template<class T> vector<T> &operator+=(vector<T> &a, vector<T> &b) {    fora(v, b)a += v;    return a;}template<class T> vector<T> &operator-=(vector<T> &a, vector<T> &b) {    if (sz(a) != sz(b)) {        debugline("vector<T> operator-=");        deb(a);        deb(b);        exit(0);    }    rep(i, sz(a))a[i] -= b[i];    return a;}
template<class T> vector<T> operator-(vector<T> &a, vector<T> &b) {    if (sz(a) != sz(b)) {        debugline("vector<T> operator-");        deb(a);        deb(b);        ole();    }    vector<T> res(sz(a));    rep(i, sz(a))res[i] = a[i] - b[i];    return res;}
template<class T, class U> vector<T> operator*(vector<T> &a, U b) {    vector<T> ret;    fora(v, a)ret += v * b;    return ret;}
template<class T, class U> vector<T> operator/(vector<T> &a, U b) {    vector<T> ret;    fora(v, a)ret += v / b;    return ret;}
template<class T, class U> vector<T> operator*=(vector<T> &a, U b) {    fora(v, a)v *= b;    return a;}
template<class T, class U> vector<T> operator/=(vector<T> &a, U b) {    fora(v, a)v /= b;    return a;}
template<typename T> void erase(vector<T> &v, unsigned ll i) { v.erase(v.begin() + i); }
template<typename T> void erase(vector<T> &v, unsigned ll s, unsigned ll e) { v.erase(v.begin() + s, v.begin() + e); }
template<class T, class U> void erase(map<T, U> &m, ll okl, ll ngr) { m.erase(m.lower_bound(okl), m.lower_bound(ngr)); }
template<class T> void erase(set<T> &m, ll okl, ll ngr) { m.erase(m.lower_bound(okl), m.lower_bound(ngr)); }
template<typename T> void erasen(vector<T> &v, unsigned ll s, unsigned ll n) { v.erase(v.begin() + s, v.begin() + s + n); }
template<typename T, typename U> void insert(vector<T> &v, unsigned ll i, U t) { v.insert(v.begin() + i, t); }
template<typename T, typename U> void push_front(vector<T> &v, U t) { v.insert(v.begin(), t); }
template<typename T, typename U> void insert(vector<T> &v, unsigned ll i, vector<T> list) { for (auto &&va:list)v.insert(v.begin() + i++, va); }
template<typename T> void insert(set<T> &v, vector<T> list) { for (auto &&va :list)v.insert(va); }
vector<string> split(const string a, const char deli) {    string b = a + deli;    ll l = 0, r = 0, n = b.size();    vector<string> res;    rep(i, n) {        if (b[i] == deli) {            r = i;            if (l < r)res.push_back(b.substr(l, r - l));            l = i + 1;        }    }    return res;}
vector<string> split(const string a, const string deli) {    vector<string> res;    ll kn = sz(deli);    std::string::size_type Pos(a.find(deli));    ll l = 0;    while (Pos != std::string::npos) {        if (Pos - l)res.push_back(a.substr(l, Pos - l));        l = Pos + kn;        Pos = a.find(deli, Pos + kn);    }    if (sz(a) - l)res.push_back(a.substr(l, sz(a) - l));    return res;}
void yn(bool a) { if (a)cout << "yes" << endl; else cout << "no" << endl; }
void Yn(bool a) { if (a)cout << "Yes" << endl; else cout << "No" << endl; }
void YN(bool a) { if (a)cout << "YES" << endl; else cout << "NO" << endl; }
void fyn(bool a) {    if (a)cout << "yes" << endl; else cout << "no" << endl;    exit(0);}
void fYn(bool a) {    if (a)cout << "Yes" << endl; else cout << "No" << endl;    exit(0);}
void fYN(bool a) {    if (a)cout << "YES" << endl; else cout << "NO" << endl;    exit(0);}
void Possible(bool a) {    if (a)cout << "Possible" << endl; else cout << "Impossible" << endl;    exit(0);}
void POSSIBLE(bool a) {    if (a)cout << "POSSIBLE" << endl; else cout << "IMPOSSIBLE" << endl;    exit(0);}
template<typename T> class fixed_point        : T {public:    explicit constexpr fixed_point(T &&t) noexcept: T(std::forward<T>(t)) {}    template<typename... Args> constexpr decltype(auto) operator()(Args &&... args) const { return T::operator()(*this, std::forward<Args>(args)...); }};template<typename T> static inline constexpr decltype(auto) fix(T &&t) noexcept { return fixed_point<T>{std::forward<T>(t)}; }

//@formatter:off
template<typename T> T minv(T a, T m);
template<typename T> T minv(T a);

template<typename T>
class Modular {
public:
    using Type = typename decay<decltype(T::value)>::type;    constexpr Modular() : value() {}    template<typename U>    Modular(const U &x) {        value = normalize(x);    }    template<typename U>    static Type normalize(const U &x) {        Type v;        if (-mod() <= x && x < mod()) v = static_cast<Type>(x);        else v = static_cast<Type>(x % mod());        if (v < 0) v += mod();        return v;    }    const Type &operator()() const { return value; }    template<typename U>explicit operator U() const { return static_cast<U>(value); }    constexpr static Type mod() { return T::value; }    Modular &operator+=(const Modular &other) {        if ((value += other.value) >= mod()) value -= mod();        return *this;    }    Modular &operator-=(const Modular &other) {        if ((value -= other.value) < 0) value += mod();        return *this;    }    template<typename U> Modular &operator+=(const U &other) { return *this += Modular(other); }    template<typename U> Modular &operator-=(const U &other) { return *this -= Modular(other); }    Modular &operator++() { return *this += 1; }    Modular &operator--() { return *this -= 1; }    Modular operator++(signed) {        Modular result(*this);        *this += 1;        return result;    }    Modular operator--(signed) {        Modular result(*this);        *this -= 1;        return result;    }    Modular operator-() const { return Modular(-value); }
    template<typename U = T>typename enable_if<is_same<typename Modular<U>::Type, signed>::value, Modular>::type &operator*=(const Modular &rhs) {
#ifdef _WIN32
        uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;asm("divl %4; \n\t": "=a" (d), "=d" (m): "d" (xh), "a" (xl), "r" (mod()));value = m;
#else
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
        return *this;
    }
    template<typename U = T>    typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type &operator*=(const Modular &rhs) {        int64_t q = static_cast<int64_t>(static_cast<double>(value) * rhs.value / mod());        value = normalize(value * rhs.value - q * mod());        return *this;    }    template<typename U = T>    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type &operator*=(const Modular &rhs) {        value = normalize(value * rhs.value);        return *this;    }    Modular &operator/=(const Modular &other) { return *this *= Modular(minv(other.value)); }    template<typename U> friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);    template<typename U> friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);    template<typename U> friend std::istream &operator>>(std::istream &stream, Modular<U> &number);    operator int() { return value; }private:    Type value;
};
template<typename T> bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value == rhs.value; }template<typename T, typename U> bool operator==(const Modular<T> &lhs, U rhs) { return lhs == Modular<T>(rhs); }template<typename T, typename U> bool operator==(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) == rhs; }template<typename T> bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) { return !(lhs == rhs); }template<typename T, typename U> bool operator!=(const Modular<T> &lhs, U rhs) { return !(lhs == rhs); }template<typename T, typename U> bool operator!=(U lhs, const Modular<T> &rhs) { return !(lhs == rhs); }template<typename T> bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value < rhs.value; }template<typename T> Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }template<typename T, typename U> Modular<T> operator+(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) += rhs; }template<typename T, typename U> Modular<T> operator+(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }template<typename T> Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }template<typename T, typename U> Modular<T> operator-(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) -= rhs; }template<typename T, typename U> Modular<T> operator-(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }template<typename T> Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }template<typename T, typename U> Modular<T> operator*(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) *= rhs; }template<typename T, typename U> Modular<T> operator*(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }template<typename T> Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }template<typename T, typename U> Modular<T> operator/(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) /= rhs; }template<typename T, typename U> Modular<T> operator/(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

constexpr signed MOD =
//        998244353;
1e9 + 7;//MOD
using mint = Modular<std::integral_constant<decay<decltype(MOD)>::type, MOD>>;
constexpr int mint_len = 1400001;
vi fac, finv, inv;
vi p2;
mint com(int n, int r) {    if (r < 0 || r > n) return 0;    return mint(finv[r] * fac[n] % MOD * finv[n - r]);}
mint pom(int n, int r) {/*    if (!sz(fac)) com(0, -1);*/    if (r < 0 || r > n) return 0;    return mint(fac[n] * finv[n - 1]);}
mint npr(int n, int r) {/*    if (!sz(fac)) com(0, -1);*/    if (r < 0 || r > n) return 0;    return mint(fac[n] * finv[n - r]);}
int nprin(int n, int r) {/*    if (!sz(fac)) com(0, -1);*/    if (r < 0 || r > n) return 0;    return fac[n] * finv[n - r] % MOD;}
int icom(int n, int r) {    const int NUM_ = 1400001;    static ll fac[NUM_ + 1], finv[NUM_ + 1], inv[NUM_ + 1];    if (fac[0] == 0) {        inv[1] = fac[0] = finv[0] = 1;        for (int i = 2; i <= NUM_; ++i) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;        for (int i = 1; i <= NUM_; ++i) fac[i] = fac[i - 1] * i % MOD, finv[i] = finv[i - 1] * inv[i] % MOD;    }    if (r < 0 || r > n) return 0;    return ((finv[r] * fac[n] % MOD) * finv[n - r]) % MOD;}
#define ncr com
#define ncri icom
//n個の場所にr個の物を置く
mint nhr(int n, int r) { return com(n + r - 1, r); }
mint hom(int n, int r) { return com(n + r - 1, r); }
int nhri(int n, int r) { return icom(n + r - 1, r); }
template<typename T> T minv(T a, T m) {    T u = 0, v = 1;    while (a != 0) {        T t = m / a;        m -= t * a;        swap(a, m);        u -= t * v;        swap(u, v);    }    assert(m == 1);    return u;}
template<typename T> T minv(T a) {    if (a < mint_len)return inv[a];    T u = 0, v = 1;    T m = MOD;    while (a != 0) {        T t = m / a;        m -= t * a;        swap(a, m);        u -= t * v;        swap(u, v);    }    assert(m == 1);    return u;}
template<typename T, typename U> Modular<T> mpow(const Modular<T> &a, const U &b) {    assert(b >= 0);    int x = a(), res = 1;    U p = b;    while (p > 0) {        if (p & 1) (res *= x) %= MOD;        (x *= x) %= MOD;        p >>= 1;    }    return res;}
template<typename T, typename U, typename V> mint mpow(const T a, const U b, const V m = MOD) {    assert(b >= 0);    int x = a, res = 1;    U p = b;    while (p > 0) {        if (p & 1) (res *= x) %= m;        (x *= x) %= m;        p >>= 1;    }    return res;}
template<typename T, typename U> mint mpow(const T a, const U b) {    assert(b >= 0);    int x = a, res = 1;    U p = b;    while (p > 0) {        if (p & 1) (res *= x) %= MOD;        (x *= x) %= MOD;        p >>= 1;    }    return res;}
template<typename T, typename U, typename V> int mpowi(const T &a, const U &b, const V &m = MOD) {    assert(b >= 0);    int x = a, res = 1;    U p = b;    while (p > 0) {        if (p & 1) (res *= x) %= m;        (x *= x) %= m;        p >>= 1;    }    return res;}
template<typename T> string to_string(const Modular<T> &number) {    return to_string(number());}
string yuri(const mint &a) {    stringstream st;    rep(i, 300) {rep(j, 300) {if ((mint) i / j == a) {st << i << " / " << j;return st.str();}}}    rep(i, 1000) {rep(j, 1000) {if ((mint) i / j == a) {st << i << " / " << j;return st.str();}}}    return st.str();}
template<typename T> std::ostream &operator<<(std::ostream &stream, const Modular<T> &number) {stream << number();
#ifdef _DEBUG
//    stream << " -> " << yuri(number);
#endif
    return stream;
}
//@formatter:off
template<typename T> std::istream &operator>>(std::istream &stream, Modular<T> &number) {    typename common_type<typename Modular<T>::Type, int64_t>::type x;    stream >> x;    number.value = Modular<T>::normalize(x);    return stream;}
using PM = pair<mint, mint>;
using vm = vector<mint>;
using mapm = map<int, mint>;
using umapm = umap<int, mint>;
#define vvm(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(mint,__VA_ARGS__)
#define vnm(name, ...) auto name = make_v<mint>(__VA_ARGS__)

struct setmod{
    setmod() {
//    p2.resize(mint_len);p2[0] = 1; for (int i = 1; i < mint_len; ++i) p2[i] = p2[i - 1] * 2 % MOD;
        fac.resize(mint_len);    finv.resize(mint_len);    inv.resize(mint_len);    inv[1] = fac[0] = finv[0] = 1;    for (int i = 2; i < mint_len; ++i) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;    for (int i = 1; i < mint_len; ++i) fac[i] = fac[i - 1] * i % MOD, finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}setmodv;
//@formatter:on
//nhr n個の場所にr個の物を分ける

//@起動時
struct initon {
    initon() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout.setf(ios::fixed);
        cout.precision(16);
        srand((unsigned) clock() + (unsigned) time(NULL));
    };
} initonv;//@formatter:on

//gra mll pr
//上下左右
const string udlr = "udlr";
string UDLR = "UDLR";//x4と連動 UDLR.find('U') := x4[0]
//右、上が正
constexpr ll y4[] = {1, -1, 0, 0};
constexpr ll x4[] = {0, 0, -1, 1};
constexpr ll y8[] = {0, 1, 0, -1, -1, 1, 1, -1};
constexpr ll x8[] = {1, 0, -1, 0, 1, -1, 1, -1};


ll n, m, k, d, H, W, x, y, z, q;
ll cou;
vi a, b, c;
//vvi (s, 0, 0);
vvc (ba, 0, 0);
vp p;
str s;


void solve() {
    din(n, d);
    vi was(n + 100);
    int st = d;
    chmi(st, n - 1);
    auto sub = [&](int r) {
        int l = u(r - d);
        rep(i, l, r + d + 1) {
            was[i] = 1;
        }
    };
    sub(st);
    cou++;
    rep(i, st, n) {
        if (was[i - d] == 0){
            sub(i);
            cou++;
        }
    }
    rep(i, n){
        if(was[i]==0){
            cou++;
            brk;
        }
    }
    cout << cou << endl;
}
auto my(ll n, vi &a) {
    return 0;
}
auto sister(ll n, vi &a) {
    ll ret = 0;
    return ret;
}

signed main() {
    solve();

#define arg n,a
#ifdef _DEBUG
    bool bad = 0;
    for (ll i = 0, ok = 1; i < k5 && ok; ++i) {
        ll n = rand(1, 8);
        vi a = ranv(n, 1, 10);
        auto myres = my(arg);
        auto res = sister(arg);
        ok = myres == res;
        if (!ok) {
            out(arg);
            cerr << "AC : " << res << endl;
            cerr << "MY  : " << myres << endl;
            bad = 1;


            break;
        }
    }
    if (!bad) {
//        cout << "完璧 : solveを書き直そう" << endl;
//        cout << "     : そして、solve()を呼び出すのだ" << endl;
//        cout << "     : cin>>n; na(a,n);も忘れるな" << endl;
    }
#endif
    return 0;
};
