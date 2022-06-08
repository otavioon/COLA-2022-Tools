#include <bits/stdc++.h>

using namespace std;

struct initon {
    initon() {
        cin.tie(0);
        ios::sync_with_stdio(false);
    };
} hoee;
//別名
#define int long long
#define ull unsigned long long
#define vec vector
#define con continue
#define bre break
#define brk break
#define is ==
#define eq ==
#define no !=
#define ne !=
#define dif !=
#define df !=
#define rs resize
#define PQ priority_queue<ll, vector<ll>, greater<ll> >
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvi = vector<vi>;
using vs = vector<string>;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using vp = vector<P>;
using dou = double;
using itn = int;
using str = string;
using bo= bool;
#define uset unordered_set
#define umap unordered_map
#define F first
#define S second
//定数
#define k4 10101
#define k5 101010
#define k6 1010101
#define k7 10101010

const int INF = (int) 1e9 + 100;
const int MINF = (int) -1e9 - 100;
const ll LINF = (ll) 1e18 + 100;
const ll MLINF = (ll) 1e18 - 100;
const double EPS = 1e-9;
const int y4[] = {-1, 1, 0, 0};
const int x4[] = {0, 0, -1, 1};
const int y8[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int x8[] = {1, 0, -1, 0, 1, -1, 1, -1};

//配列
#define sz(a) (sizeof(a)/sizeof(a[0]))

//コンテナ
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

template<class T> inline void sort(vector<T> &a) { sort(a.begin(), a.end()); };
template<class T> inline void rsort(vector<T> &a) { sort(a.begin(), a.end(), greater<T>()); };
template<class T> inline void sort(vector<T> &a, int len) { sort(a.begin(), a.begin() + len); };
template<class T> inline void rsort(vector<T> &a, int len) { sort(a.begin(), a.begin() + len, greater<T>()); };


//繰り返し
#define _overloadrep(_1, _2, _3, name, ...) name
# define _rep(i, n) for(int i = 0,RLN = (n); i < RLN ; i++)
#define repi(i, m, n) for(int i = m,RLN = (n); i < RLN ; i++)
#define rep(...) _overloadrep(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rer(i, n) for(int RLN = (n) ,i = RLN; i >= 0 ; i--)
#define reri(i, m, n) for(int RLN = (m) ,i = RLN; i >= n ; i--)
#define rer(...) _overloadrep(__VA_ARGS__,reri,_rer,)(__VA_ARGS__)
#define fora(a, b) for(auto&& a : b)
#define rea(a, b) for(auto&& a : b)
#define repa(a, b) for(auto&& a : b)

template<typename A, size_t N, typename T> void fill(A (&a)[N], const T &v) {
    rep(i, N)a[i] = v;
}
template<typename A, size_t N, size_t O, typename T> void fill(A (&a)[N][O], const T &v) {
    rep(i, N)rep(j, O)a[i][j] = v;
}
template<typename A, size_t N, size_t O, size_t P, typename T> void fill(A (&a)[N][O][P], const T &v) {
    rep(i, N)rep(j, O)rep(k, P)a[i][j][k] = v;
}
template<typename A, size_t N, size_t O, size_t P, size_t Q, typename T> void fill(A (&a)[N][O][P][Q], const T &v) {
    rep(i, N)rep(j, O)rep(k, P)rep(l, Q)a[i][j][k][l] = v;
}
template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R, typename T> void
fill(A (&a)[N][O][P][Q][R], const T &v) {
    rep(i, N)rep(j, O)rep(k, P)rep(l, Q)rep(m, R)a[i][j][k][l][m] = v;
}
template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R, size_t S, typename T> void
fill(A (&a)[N][O][P][Q][R][S], const T &v) {
    rep(i, N)rep(j, O)rep(k, P)rep(l, Q)rep(m, R)rep(n, S)a[i][j][k][l][m][n] = v;
}
template<class T, class U> void fill(vector<T> &a, U v) {
    rep(i, a.size())a[i] = v;
}
template<class T, class U> void fill(vector<vector<T>> &a, U v) {
    rep(i, a.size())rep(j, a[0].size())a[i][j] = v;
}
template<class T, class U> void fill(vector<vector<vector<T>>> &a, U v) {
    rep(i, a.size())rep(j, a[0].size())rep(k, a[0][0].size())a[i][j][k] = v;
}

#define arcpy(a, b) memcpy(a,b,sizeof(b))

//入力
template<typename T = int> T in() {
    T x;
    cin >> x;
    return (x);
}
string sin() { return in<string>(); }
double din() { return in<double>(); }
ll lin() { return in<ll>(); }

#define na(a, n) rep(i,n) cin >> a[i];
#define nad(a, n) rep(i,n) cin >> a[i], a[i]--;
#define na3(a, b, c, n) rep(i, n)cin >> a[i] >> b[i] >> c[i];
#define add3(a, b, c, n) rep(i, n)a.pb(in()),b.pb(in()),c.pb(in());
#define na2(a, b, n) rep(i, n)cin >> a[i] >> b[i];

#define nt(a, h, w) rep(hi,h)rep(wi,w) cin >> a[hi][wi];
#define ntd(a, h, w) rep(hi,h)rep(wi,w) cin >> a[hi][wi], a[hi][wi]--;
#define ntp(a, h, w) fill(a,'#');rep(hi,1,h+1)rep(wi,1,w+1) cin >> a[hi][wi];

#define addAll(a, n) rep(i,n) a.pb(in());
#define addAlld(a, n) rep(i,n) a.pb(in()-1);


//出力
template<class T> void out(T x) {
    if (typeid(x) == typeid(double))cout << fixed << setprecision(10) << x << endl;
    else cout << x << endl;
}
//デバッグ
#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

//よく使うクラス、構造体
class UnionFind {
public:
    vi par, rank, sizes;
    int n, trees;
    UnionFind(int n) : n(n), trees(n) {
        par.resize(n), rank.resize(n), sizes.resize(n);
        rep(i, n)par[i] = i, sizes[i] = 1;
    }
    int root(int x) {
        if (par[x] == x)return x;
        else return par[x] = root(par[x]);
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y)return;
        if (rank[x] < rank[y])swap(x, y);
        trees--;
        par[y] = x;
        sizes[x] += sizes[y];
        if (rank[x] == rank[y])rank[x]++;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return sizes[root(x)]; }
    //順不同 umapなので
    vvi sets() {
        vvi res(trees);
        umap<int, vi> map;
        rep(i, n) map[root(i)].push_back(i);
        int i = 0;
        for (auto &&p:map) {
            int r = p.F;
            res[i].push_back(r);
            for (auto &&v:p.S) {
                if (r == v)continue;
                res[i].push_back(v);
            }
            i++;
        }
        return res;
    }
};

//MOD関連
ll MOD = (int) 1e9 + 7;
int mpow(int v, ll a) {
    ll x = v, n = a, res = 1;
    while (n) {
        if (n & 1)res = (res * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return res;
}

class mint {
private:
    ll v;
public:
    static ll mod(ll a) { return (a % MOD + MOD) % MOD; }
    mint(ll a = 0) { this->v = mod(a); };
    mint(const mint &a) { v = a.v; }
    mint operator+(const mint &a) { return mint(v + a.v); }
    mint operator+(const ll a) { return mint(v + a % MOD); }
    mint operator+(const signed a) { return mint(v + a % MOD); }
    friend mint operator+(const ll a, const mint &b) { return mint(a % MOD + b.v); }
    void operator+=(const mint &a) { v = (v + a.v) % MOD; }
    void operator+=(const ll a) { v = mod(v + a % MOD); }
    void operator+=(const signed a) { v = mod(v + a % MOD); }
    friend void operator+=(ll &a, const mint &b) { a = mod(a % MOD + b.v); }
    mint operator-(const mint &a) { return mint(v - a.v); }
    mint operator-(const ll a) { return mint(v - a % MOD); }
    mint operator-(const signed a) { return mint(v - a % MOD); }
    friend mint operator-(const ll a, const mint &b) { return mint(a % MOD - b.v); }
    void operator-=(const mint &a) { v = mod(v - a.v); }
    void operator-=(const ll a) { v = mod(v - a % MOD); }
    void operator-=(const signed a) { v = mod(v - a % MOD); }
    friend void operator-=(ll &a, const mint &b) { a = mod(a % MOD - b.v); }
    mint operator*(const mint &a) { return mint(v * a.v); }
    mint operator*(const ll a) { return mint(v * (a % MOD)); }
    mint operator*(const signed a) { return mint(v * (a % MOD)); }
    friend mint operator*(const ll a, const mint &b) { return mint(a % MOD * b.v); }
    void operator*=(const mint &a) { v = (v * a.v) % MOD; }
    void operator*=(const ll a) { v = mod(v * (a % MOD)); }
    void operator*=(const signed a) { v = mod(v * (a % MOD)); }
    friend void operator*=(ll &a, const mint &b) { a = mod(a % MOD * b.v); }
    mint operator/(const mint &a);
    mint operator/(const ll a);
    mint operator/(const signed a);
    friend mint operator/(const ll a, const mint &b);
    void operator/=(const mint &a);
    void operator/=(const ll a);
    void operator/=(const signed a);
    friend void operator/=(ll &a, const mint &b);
    mint operator^(const mint &a) { return mpow(v, a.v); };
    mint operator^(const ll a) { return mpow(v, a); };
    mint operator^(const signed a) { return mpow(v, a); };
    friend mint operator^(const ll a, const mint &b) { return mpow(a, b.v); };
    void operator^=(const mint &a) { v = mpow(v, a.v); }
    void operator^=(const ll a) { v = mpow(v, a); }
    void operator^=(const signed a) { v = mpow(v, a); }

    //単項演算子
    mint operator+() { return *this; }
    mint operator++() {
        v++;
        return *this;
    }
    mint operator++(signed d) {
        mint res = *this;
        v++;
        return res;
    }
    mint operator-() { return operator*(-1); }
    mint operator--() {
        v++;
        return *this;
    }
    void operator--(signed d) {
        mint res = *this;
        v++;
    }
    bool operator==(mint &a) {
        return v == a.v;
    }
    bool operator==(signed a) {
        return v == a;
    }
    friend bool operator==(signed a, mint &b) {
        return a == b.v;
    }
    bool operator!=(mint &a) {
        return v != a.v;
    }
    bool operator!=(signed a) {
        return v != a;
    }
    friend bool operator!=(signed a, mint &b) {
        return a != b.v;
    }
    operator int() { return v; }
};
const int setModMax = 510000;
mint fac[setModMax], finv[setModMax], inv[setModMax];
void setMod() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < setModMax; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
mint minv(ll a) {
    if (fac[0] == 0)setMod();
    if (a < setModMax) return inv[a];
    a %= MOD;
    ll b = MOD, x = 1, y = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        x -= t * y;
        swap(x, y);
    }
    return (x % MOD + MOD) % MOD;
}

mint mint::operator/(const mint &a) { return mint(v * minv(a.v)); }
mint mint::operator/(const ll a) { return mint(v * minv(a)); }
mint mint::operator/(const signed a) { return mint(v * minv(a)); }
mint operator/(const ll a, const mint &b) { return mint(a % MOD * minv(b.v)); }
void mint::operator/=(const mint &a) { v = (v * minv(a.v)) % MOD; }
void mint::operator/=(const ll a) { v = mod(v * minv(a)); }
void mint::operator/=(const signed a) { v = mod(v * minv(a)); }
void operator/=(ll &a, const mint &b) { a = mint::mod(a % MOD * minv(b.v)); }
bool isPrime[4010101];
vi primes;
void setPrime() {
    fill(isPrime, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= sqrt(sz(isPrime)) + 5; ++i) {
        if (!isPrime[i])continue;
        for (int j = 2; i * j < sz(isPrime); ++j) {
            isPrime[i * j] = false;
        }
    }
    rep(i, sz(isPrime))if (isPrime[i])primes.pb(i);
}
mint com(ll n, ll r) {
    if (n < r || n < 0 || r < 0)return 0;
    if (fac[0] == 0)setMod();
    return fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;
}
//便利関数
template<class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<class T> T min(T a, signed b) {
    return a < b ? a : b;
}
template<class T> T max(T a, signed b) {
    return a < b ? b : a;
}
template<class T> T sum(vector<T> &v, int len = -1) {
    if (len == -1)len = v.size();
    T res = 0;
    rep(i, min((int) len, (int) v.size()))res += v[i];
    return res;
}
void clear(PQ &q) {
    while (q.size())q.pop();
}
template<class T> void clear(queue<T> &q) {
    while (q.size())q.pop();
}

template<class T> vector<T> ruiv(vector<T> &a) {
    vector<T> res(a.size() + 1);
    rep(i, a.size())res[i + 1] = res[i] + a[i];
    return res;
}

template<class T> void plus(vector<T> &a, T v = 1) {
    for (auto &&u :a)u += v;
}
template<class T> void minu(vector<T> &a, T v = 1) {
    for (auto &&u :a)u -= v;
}
template<class T> void minus(vector<T> &a, T v = 1) {
    for (auto &&u :a)u -= v;
}
inline bool inside(int y, int x, int H, int W) { return y >= 0 && x >= 0 && y < H && x < W; }
ll u(ll a) { return a < 0 ? 0 : a; }
#define inc(s, x, t) s<=x&&x<t
#define MIN(a) numeric_limits<a>::min()
#define MAX(a) numeric_limits<a>::max()

template<class T> T min(vector<vector<T>> &a) {
    T res = MAX(T);
    rep(i, a.size())chmin(res, *min_element(all(a[i])));
    return res;
}
template<class T> T max(vector<vector<T>> &a) {
    T res = MIN(T);
    rep(i, a.size())chmax(res, *max_element(all(a[i])));
    return res;
}
bool bget(ll m, int keta) {
    return (m >> keta) & 1;
}
int bget(ll m, int keta, int sinsuu) {
    m /= (ll) pow(sinsuu, keta);
    return m % sinsuu;
}
inline ll bit(int n) {
    return (1LL << (n));
}
inline ll bit(int n, int sinsuu) {
    return (ll) pow(sinsuu, n);
}
int bcou(ll m) {
    return __builtin_popcount(m & 0xFFFFFFFF) + __builtin_popcount(m >> 32);
}
int ctoi(char c) {
    if ('A' <= c && c <= 'Z')return c - 'A';
    return c - 'a' + 26;
}

char itoc(int i) {
    if (i < 26)return 'A' + i;
    return 'a' + i - 26;
}
#define lowerIndex(a, v) (lower_bound(all(a),v)-a.begin())
#define lowerBound(a, v) (*lower_bound(all(a),v))
#define upperIndex(a, v) (upper_bound(all(a),v)-a.begin())
#define upperBound(a, v) (*upper_bound(all(a),v))
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

void compress(vi &a) {
    vi b;
    int len = a.size();
    for (int i = 0; i < len; ++i) {
        b.push_back(a[i]);
    }
    sort(b);
    UNIQUE(b);
    for (int i = 0; i < len; ++i) {
        a[i] = lower_bound(all(b), a[i]) - b.begin();
    }
}

void compress(int a[], int len) {
    vi b;
    for (int i = 0; i < len; ++i) {
        b.push_back(a[i]);
    }
    sort(b);
    UNIQUE(b);
    for (int i = 0; i < len; ++i) {
        a[i] = lower_bound(all(b), a[i]) - b.begin();
    }
}
ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}
ll sqrt(ll a) {
    ll res = (ll) sqrt(a);
    while (res * res < a)res++;
    return res;
}
ll sig(ll t) { return (1 + t) * t / 2; }
ll sig(ll s, ll t) { return (s + t) * (t - s + 1) / 2; }
template<class T> inline void fin(T s) { cout << s << endl, exit(0); }

#define ans(a) cout<<a<<endl;continue;
#define lower_index(a, v) lower_bound(all(a),v)-a.begin()
#define upper_index(a, v) upper_bound(all(a),v)-a.begin()
#define poll(a) q.front();q.pop()
#define dpoll(a) q.front();q.pop_front()
#define pollLast(a) q.back();q.pop_back()
#define pollBack(a) q.back();q.pop_back()
template<class T> struct edge {
    int from, to;
    T cost;
    int id;
    int type;
    edge(int f, int t, T c = 1, int id = -1, int ty = -1) : from(f), to(t), cost(c), id(id), type(ty) {}
};
template<typename T> class graph {
protected:
    vector<bool> _used;
public :
    vector<vector<edge<T>>> g;
    vector<edge<T>> edges;
    int n;
    graph(int n) : n(n) {
        g.resize(n);
        _used.resize(n);
    }
    void clear() {
        g.clear();
        edges.clear();
    }
    void resize(int n) {
        this->n = n;
        g.resize(n);
        _used.resize(n);
    }
    bool isleaf(int v, int r) {
        return g[v].size() == 1 && g[v][0].to == r;
    }
    virtual void add(int from, int to, T cost, int ty) = 0;
    virtual bool used(edge<T> &e) = 0;
    virtual bool used(int id) = 0;
    virtual void del(edge<T> &e) = 0;
    virtual void del(int id) = 0;
};

template<class T=int> class undigraph : public graph<T> {
public:
    using graph<T>::g;
    using graph<T>::n;
    using graph<T>::edges;
    using graph<T>::_used;

    undigraph(int n) : graph<T>(n) {
    }
    void add(int f, int t, T cost = 1, int ty = -1) {
        assert(0 <= f && f < n && 0 <= t && t < n);
        int id = edges.size();
        g[f].emplace_back(f, t, cost, id, ty);
        g[t].emplace_back(t, f, cost, id + 1, ty);
        edges.emplace_back(f, t, cost, id, ty);
        edges.emplace_back(t, f, cost, id + 1, ty);
    }
    void add(edge<T> &e) {
        int f = e.from, t = e.to, ty = e.type;
        T cost = e.cost;
        add(f, t, cost, ty);
    }
    bool used(edge<T> &e) {
        return _used[e.id];
    }
    bool used(int id) {
        return _used[id];
    }
    void del(edge<T> &e) {
        _used[e.id] = _used[e.id ^ 1] = 1;
    }
    void del(int id) {
        _used[id] = _used[id ^ 1] = 1;
    }
};

template<typename T =ll> class digraph : public graph<T> {
public:
    using graph<T>::g;
    using graph<T>::n;
    using graph<T>::edges;
    using graph<T>::_used;

    digraph(int n) : graph<T>(n) {
    }
    void add(int f, int t, T cost = 1, int ty = -1) {
        assert(0 <= f && f < n && 0 <= t && t < n);
        int id = edges.size();
        g[f].emplace_back(t, cost, ty, id);
        edges.emplace_back(f, t, cost, ty, id);
    }
    bool used(edge<T> &e) {
        return _used[e.id];
    }
    bool used(int id) {
        return _used[id];
    }
    void del(edge<T> &e) {
        _used[e.id] = _used[e.id ^ 1] = 1;
    }
    void del(int id) {
        _used[id] = _used[id ^ 1] = 1;
    }
};
template<class T> bool nibu(const graph<T> &g) {
    UnionFind uf(g.n * 2);
    for (auto &&e :g.edges)uf.unite(e.f, e.t + g.n), uf.unite(e.f + g.n, e.t);
    return !uf.same(0, g.n);
}
template<class T> vector<T> dijkstra(const graph<T> &g, int s) {
    assert(inc(0, s, g.n));
    T initValue = MAX(T);
    vector<T> dis(g.n, initValue);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
    dis[s] = 0;
    q.emplace(0, s);
    while (q.size()) {
        T nowc = q.top().F;
        int i = q.top().S;
        q.pop();
        if (dis[i] != nowc)continue;
        for (auto &&e  : g.g[i]) {
            int to = e.to;
            T cost = nowc + e.cost;
            if (dis[to] > cost) {
                dis[to] = cost;
                q.emplace(dis[to], to);
            }
        }
    }
    //たどり着かないなら-1
    for (auto &&d :dis) if (d == initValue)d = -1;
    return dis;
}
ll ma = numeric_limits<ll>::min();
ll mi = numeric_limits<ll>::max();
int N, K, M, H, W, Q, cou;
vi A, B, C;
bool bad[12];
signed main() {
    cin >> N >> K;
    rep(i, K) {
        bad[in()] = 1;
    }
    rep(v, N, LINF) {
        int tem = v;
        bool ok = 1;
        while (tem) {
            if (bad[tem % 10])ok = 0;
            tem /= 10;
        }
        if(ok)fin(v);
    }

    return 0;
}