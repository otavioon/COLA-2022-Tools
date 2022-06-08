#include <bits/stdc++.h>
using namespace std;
#define int long long
#define stoi stoll
using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;
#define ALL(c) begin(c),end(c)
#define RALL(c) rbegin(c),rend(c)
#define ITR(i,b,e) for(auto i=(b);i!=(e);++i)
#define FORE(x,c) for(auto &&x:c)
#define REPF(i,a,n) for(int i=a,i##len=(int)(n);i<i##len;++i)
#define REP(i,n) REPF(i,0,n)
#define REPR(i,n) for(int i=(int)(n);i>=0;--i)
#define SZ(c) ((int)c.size())
#define CONTAIN(c,x) (c.find(x)!=end(c))
#define INSEG(l,x,r) ((l)<=(x)&&(x)<(r))
#define dump(...)
#define pb push_back
#define _ 0
const signed INF_=1001001001; const long long INF=1001001001001001001LL;
const int DX[9]={0,1,0,-1,1,1,-1,-1,0},DY[9]={-1,0,1,0,-1,1,1,-1,0};
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) {
    ITR(i,begin(v),end(v))os<<*i<<(i==end(v)-1?"":" ");return os;}
template<class T> istream& operator>>(istream &is,vector<T> &v) {
    ITR(i,begin(v),end(v)) is>>*i;return is;}
template<class T,class U> istream& operator>>(istream &is, pair<T,U> &p) {
    is>>p.first>>p.second;return is;}
template<class T, class U> bool chmax(T &a,const U &b){return a<b?a=b,1:0;}
template<class T, class U> bool chmin(T &a,const U &b){return a>b?a=b,1:0;}
template <class T> void PSUM(T& c) {partial_sum(begin(c), end(c), begin(c));}
template<class T> using heap=priority_queue<T,vector<T>,greater<T>>;
struct before_main_function {
    before_main_function() {
        cin.tie(0); ios::sync_with_stdio(false);
        cout << setprecision(15) << fixed;
        // #define endl "\n"
    }
} before_main_function;
//------------------8<------------------------------------8<--------------------

template<typename Monoid>
struct SegmentTree {
    using T = typename Monoid::T;
    size_t n;
    vector<T> t;

    void prop_to(std::size_t i) { t[i] = Monoid::op(t[i << 1], t[i << 1 | 1]); }
    SegmentTree(size_t size, const T& v = Monoid::identity()) {
        n = 1;
        while (n < size) n <<= 1;
        t.resize(n << 1, v);
    }
    template <class InputIt>
    SegmentTree(InputIt first, InputIt last) : n(distance(first, last)), t(n << 1, Monoid::identity()) {
        copy(first, last, begin(t) + n);
        for (size_t i = n - 1; i > 0; i--) prop_to(i);
    }
    static T modify_update(const T& a, const T& b) { return b; }
    static T modify_add(const T& a, const T& b) { return a + b; }
    void update(size_t i, const T& v, const function<T(T, T)>& func = modify_update) {
        i += n;
        t[i] = func(t[i], v);
        while (i >>= 1) prop_to(i);
    }
    T query(size_t l, size_t r) {
        T res = Monoid::identity();
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = Monoid::op(res, t[l++]);
            if (r & 1) res = Monoid::op(res, t[--r]);
        }
        return res;
    }
    T get(size_t i) { return t[i + n]; }
};

struct RMQ {
    using T = pii;
    static T op(T a, T b) { return min(a, b); }
    static constexpr T identity() { return {INF, INF}; }
};

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    sort(ALL(a));
    vector<vector<int>> g(n);
    vector<int> deg(n);
    REP(i, n) {
        REP(j, 31) {
            if (1LL << j == a[i] * 2) continue;
            auto itr = lower_bound(ALL(a), (1LL << j) - a[i]);
            if (itr == end(a)) continue;
            if (*itr + a[i] != (1LL << j)) continue;
            g[i].push_back(itr - begin(a)); 
            deg[i]++;
        }
    }

    vector<pii> tmp(n);
    REP(i, n) tmp[i] = {deg[i], i};
    SegmentTree<RMQ> seg(ALL(tmp));
    vector<bool> alive(n, true);
    int ans = 0;
    while (1) {
        pii mn = seg.query(0, n);
        if (mn.first == INF) break;
        
        int V = mn.second;
        int W = -1;
        FORE(w, g[V]) {
            if (alive[w]) {
                ans++;
                W = w;
                break;
            }
        }

        FORE(w, g[V]) {
            if (!alive[w]) continue;
            pii t = seg.get(w);
            seg.update(t.second, {t.first - 1, t.second});
        }
        if (W != -1) {
            FORE(w, g[W]) {
                if (!alive[w]) continue;
                pii t = seg.get(w);
                seg.update(t.second, {t.first - 1, t.second});
            }
        }
        
        seg.update(V, {INF, V});
        alive[V] = false;
        if (W != -1) {
            seg.update(W, {INF, W});
            alive[W] = false;
        }
    }
    cout << ans << endl;
    return (0^_^0);
}

