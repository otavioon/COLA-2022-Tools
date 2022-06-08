#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<stack>
#include<string>
#include<algorithm>
#include<functional>
#include<cstring>
#include<complex>
#include<bitset>
#include<iostream>
using namespace std;

/**** Type Define ****/

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> Q;
typedef complex<double> C;

/**** Macro Define ****/

#define cx real()
#define cy imag()

/**** Const List   ****/

const ll INF = 1LL << 60;
const double DINF = 1e30;
const ll mod = 1000000007;
const ll MAX_FLOW_MAX_V = 10000;
const ll MIN_COST_FLOW_MAX_V = 10000;
const ll BIPARTITE_MATCHING_MAX_V = 10000;
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, -1, 0, 1};
const C I = C(0, 1);
const double EPS = 1e-10;
const ll NCK_MAX = 510000;

/**** General Functions ****/

template <typename T>
T tmin(T a, T b) { return a > b ? b : a; };

template <typename T>
T tmax(T a, T b) { return a > b ? a : b; };

template <typename T>
T tadd(T a, T b) { return a + b; };

template <typename T>
T tmul(T a, T b) { return a * b; };

template <typename T>
T tpow(T a, T b) { return a * b; };

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll extgcd(ll a, ll b, ll& x, ll& y) {
  if (b == 0) {
    x = 1, y = 0; return a;
  }
  ll q = a/b, g = extgcd(b, a - q*b, x, y);
  ll z = x - q * y;
  x = y;
  y = z;
  return g;
}

ll invmod (ll a, ll m) { // a^-1 mod m
  ll x, y;
  extgcd(a, m, x, y);
  x %= m;
  if (x < 0) x += m;
  return x;
}

ll *fac, *finv, *inv;

void nCk_init(ll mod) {
  fac = new ll[NCK_MAX];
  finv = new ll[NCK_MAX];
  inv = new ll[NCK_MAX];
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (ll i = 2; i < NCK_MAX; i++) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = mod - inv[mod%i] * (mod / i) % mod;
    finv[i] = finv[i-1] * inv[i] % mod;
  }
}

ll nCk(ll n, ll k, ll mod) {
  if (fac == NULL) nCk_init(mod);
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}

ll lmin(ll a, ll b) { return a > b ? b : a; };

ll lmax(ll a, ll b) { return a > b ? a : b; };

ll lsum(ll a, ll b) { return a + b; };

/**** Matrix ****/

template <typename T>
struct Matrix {
  typedef vector<T> vec;
  typedef vector<vec> mat;
  ll x, y; // x: horizon  y: vertical
  mat d;

  Matrix(ll _y, ll _x = -1) {
    if (_x == -1) _x = _y;
    x = _x, y = _y;
    for (int i = 0; i < y; i++) for (int j = 0; j < x; j++) d[i][j] = 0;
  }
  void unit() {
    for (int i = 0; i < y; i++) for (int j = 0; j < x; j++) d[i][j] = i == j ? 1 : 0;
  }
  Matrix copy() {
    Matrix m(y, x);
    for (int i = 0; i < y; i++) for (int j = 0; j < x; j++) m.d[i][j] = d[i][j];
    return m;
  }
  Matrix<T> operator + (Matrix<T>& t) { // No error check! Don't forget to check Matrix size!!
    Matrix<T> m(y, x);
    for (int i = 0; i < y; i++) for (int j = 0; j < x; j++) m.d[i][j] = d[i][j] + t.d[i][j];
    return m;
  }
  Matrix<T> operator - (Matrix<T>& t) {
    Matrix<T> m(y, x);
    for (int i = 0; i < y; i++) for (int j = 0; j < x; j++) m.d[i][j] = d[i][j] - t.d[i][j];
    return m;
  }
  Matrix<T> operator * (T t) {
    Matrix<T> m(y, x);
    for (int i = 0; i < y; i++) for (int j = 0; j < x; j++) m.d[i][j] = d[i][j] * t;
    return m;
  }
  Matrix<T> det(Matrix<T>& t) { // x need to correspond to t.y
    Matrix<T> m(y, x);
    for (int i = 0; i < y; i++)
      for (int j = 0; j < x; j++)
        for (int k = 0; k < t.x; k++) m.d[i][j] += d[i][k] * t.d[k][j]; ////////////// mod???
    return m;
  }
};

/**** Zip ****/

template <typename T>
class Zip {
  vector<T> d;
  bool flag;
public:
  Zip() {
    flag = false;
  }
  void add(T x) {
    d.push_back(x);
    flag = true;
  }
  ll getNum(T x) { // T need to have operator < !!
    if (flag) {
      sort(d.begin(), d.end());
      d.erase(unique(d.begin(), d.end()), d.end());
      flag = false;
    }
    return lower_bound(d.begin(), d.end(), x) - d.begin();
  }
  ll size() {
    if (flag) {
      sort(d.begin(), d.end());
      d.erase(unique(d.begin(), d.end()), d.end());
      flag = false;
    }
    return (ll)d.size();
  }
};

/**** Union Find ****/

class UnionFind {
  vector<ll> par, rank; // par > 0: number, par < 0: -par
public:
  void init(ll n) {
    par.resize(n, 1); rank.resize(n, 0);
  }
  ll getSize(ll x) {
    return par[find(x)];
  }
  ll find(ll x) {
    if (par[x] > 0) return x;
    return -(par[x] = -find(-par[x]));
  }
  void merge(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      par[y] += par[x];
      par[x] = -y;
    } else {
      par[x] += par[y];
      par[y] = -x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }
  bool isSame(ll x, ll y) {
    return find(x) == find(y);
  }
};

template <typename T>
struct UnionFindT {
  vector<ll> par;
  vector<ll> rank;
  vector<T> diff_weight;

  UnionFindT(ll n = 1, T SUM_UNITY = 0) {
    init(n, SUM_UNITY);
  }

  void init(ll n = 1, T SUM_UNITY = 0) {
    par.resize(n); rank.resize(n); diff_weight.resize(n);
    for (ll i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
  }

  ll find(ll x) {
    if (par[x] == x) {
      return x;
    }
    else {
      ll r = find(par[x]);
        diff_weight[x] += diff_weight[par[x]];
        return par[x] = r;
    }
  }

  T weight(ll x) {
    find(x);
    return diff_weight[x];
  }

  bool isSame(ll x, ll y) {
    return find(x) == find(y);
  }

  bool merge(ll x, ll y, T w) {
    w += weight(x); w -= weight(y);
    x = find(x); y = find(y);
    if (x == y) return false;
    if (rank[x] < rank[y]) swap(x, y), w = -w;
    if (rank[x] == rank[y]) ++rank[x];
    par[y] = x;
    diff_weight[y] = w;
    return true;
  }

  T diff(ll x, ll y) {
    return weight(y) - weight(x);
  }
};

class PersistentUnionFind {
  vector<ll> rank, fin, par;
  ll index;
public:
  void init(ll n) {
    index = 0;
    par.resize(n); rank.resize(n, 1); fin.resize(n, 0);
    for (ll i = 0; i < n; i++) par[i] = i;
  }
  ll find(ll x, ll t) {
    if (t >= fin[x] && par[x] != x) return find(par[x], t);
    return x;
  }
  void merge(ll x, ll y) {
    x = find(x, index);
    y = find(y, index);
    index++;
    if (x == y) return;
    if (rank[x] < rank[y]) par[x] = y, fin[x] = index;
    else {
      par[y] = x, fin[y] = index;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }
  bool isSame(ll x, ll y, ll t) { return find(x, t) == find(y, t); }
};

/**** Segment Tree ****/

template <typename T>
class SegmentTree {
  ll n;
  vector<T> node;
  function<T(T, T)> fun, fun2;
  bool customChange;
  T outValue, initValue;
public:
  void init(ll num, function<T(T, T)> resultFunction, T init, T out, function<T(T, T)> changeFunction = NULL) {
    // changeFunction: (input, beforevalue) => newvalue
    fun = resultFunction;
    fun2 = changeFunction;
    customChange = changeFunction != NULL;
    n = 1;
    while (n < num) n *= 2;
    node.resize(2 * n - 1, init);
    outValue = out;
    initValue = init;
  }
  void valueChange(ll num, T value) {
    num += n-1;
    if (customChange) node[num] = fun2(value, node[num]);
    else node[num] = value;
    while (num > 0) num = (num - 1) / 2, node[num] = fun(node[num * 2 + 1], node[num * 2 + 2]);
  }
  T rangeQuery(ll a, ll b, ll l = 0, ll r = -1, ll k = 0) { // [a, b)
    if (r == -1) r = n;
    if (a <= l && r <= b) return node[k];
    if (b <= l || r <= a) return outValue;
    ll mid = (l + r) / 2;
    return fun(rangeQuery(a, b, l, mid, 2*k+1), rangeQuery(a, b, mid, r, 2*k+2));
  }
};

template <typename T>
class LazySegmentTree {
  ll n;
  vector<T> node;
  vector<T> lazyNode;
  function<T(T, T)> fun, fun2;
  function<T(T, ll)> fun3;
  T outValue, initValue;
  T substitution(T a, T b) { return a; }
  void eval(ll k, ll l, ll r) {
    if (lazyNode[k] == 0) return;
    node[k] = fun2(fun3(lazyNode[k], r - l), node[k]);
    if (r - l > 1) {
      lazyNode[2 * k + 1] = fun2(lazyNode[k], lazyNode[2 * k + 1]);
      lazyNode[2 * k + 2] = fun2(lazyNode[k], lazyNode[2 * k + 2]);
    }
    lazyNode[k] = initValue;
  }
public:
  void init(ll num, function<T(T, T)> resultFunction, function<T(T, T)> changeFunction, function<T(T, ll)> lazyFunction, T init, T out) {
    // changeFunction: (input, beforevalue) => newvalue
    // lazyFunction: (lazyNode, diff) => newvalue
    fun = resultFunction;
    fun2 = changeFunction;
    fun3 = lazyFunction;
    n = 1;
    while (n < num) n *= 2;
    node.resize(2 * n - 1, init);
    lazyNode.resize(2 * n - 1, init);
    outValue = out;
    initValue = init;
  }
  void rangeChange(ll a, ll b, T value, ll l = 0, ll r = -1, ll k = 0) {
    if (r == -1) r = n;
    eval(k, l, r);
    if (b <= l || r <= a) return;
    if (a <= l && r <= b) {
      lazyNode[k] = fun2(value, lazyNode[k]);
      eval(k, l, r);
    } else {
      ll mid = (l + r) / 2;
      rangeChange(a, b, value, l, mid, 2*k+1);
      rangeChange(a, b, value, mid, r, 2*k+2);
      node[k] = fun(node[2*k+1], node[2*k+2]);
    }
  }
  T rangeQuery(ll a, ll b, ll l = 0, ll r = -1, ll k = 0) { // [a, b)
    if (r == -1) r = n;
    if (b <= l || r <= a) return outValue;
    eval(k, l, r);
    if (a <= l && r <= b) return node[k];
    ll mid = (l + r) / 2;
    return fun(rangeQuery(a, b, l, mid, 2*k+1), rangeQuery(a, b, mid, r, 2*k+2));
  }
};

/**** Network Flow ****/

class MaxFlow {
public:
  struct edge { ll to, cap, rev; };

  vector<edge> G[MAX_FLOW_MAX_V];
  bool used[MAX_FLOW_MAX_V];
  ll level[MAX_FLOW_MAX_V];
  ll iter[MAX_FLOW_MAX_V];
  
  void init() {
    for (ll i = 0; i < MAX_FLOW_MAX_V; i++) {
      G[i].clear();
    }
  }
  void add_edge(ll from, ll to, ll cap) {
    G[from].push_back((edge){to, cap, (ll)G[to].size()});
    G[to].push_back((edge){from, 0, (ll)G[from].size() - 1});
  }
  void add_undirected_edge(ll e1, ll e2, ll cap) {
    G[e1].push_back((edge){e2, cap, (ll)G[e2].size()});
    G[e2].push_back((edge){e1, cap, (ll)G[e1].size() - 1});
  }
  ll dfs(ll v, ll t, ll f) {
    if (v == t) return f;
    used[v] = true;
    for (ll i = 0; i < (ll)G[v].size(); i++) {
      edge &e = G[v][i];
      if (!used[e.to]&& e.cap > 0) {
        ll d = dfs(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  ll max_flow(ll s, ll t) {
    ll flow = 0;
    while (1) {
      memset(used, 0, sizeof(used));
      ll f = dfs(s, t, INF);
      if (f == 0) return flow;
      flow += f;
    }
  }
  void bfs(ll s) {
    memset(level, -1, sizeof(level));
    queue<ll> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
      ll v = que.front(); que.pop();
      for (ll i = 0; i < (ll)G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          que.push(e.to);
        }
      }
    }
  }
  ll dinic_dfs(ll v, ll t, ll f) {
    if (v == t) return f;
    for (ll &i= iter[v]; i < (ll)G[v].size(); i++) {
      edge &e = G[v][i];
      if (e.cap > 0 && level[v] < level[e.to]) {
        ll d = dinic_dfs(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  ll dinic(ll s, ll t) {
    ll flow = 0;
    while (1) {
      bfs(s);
      if (level[t] < 0) return flow;
      memset(iter, 0, sizeof(iter));
      ll f;
      while ((f = dinic_dfs(s, t, INF)) > 0) {
        flow += f;
      }
    }
  }
};

/**** bipartite matching ****/

class BipartiteMatching {
  vector<ll> pre, root;
  vector<vector<ll>> to;
  vector<ll> p, q;
  ll n, m;
public:
  BipartiteMatching(ll n, ll m):pre(n,-1),root(n,-1),to(n),p(n,-1),q(m,-1),n(n),m(m){}
  void add(ll a, ll b) { to[a].push_back(b);}
  ll solve() {
    ll res = 0;
    bool upd = true;
    while (upd) {
      upd = false;
      queue<ll> s;
      for (ll i = 0; i < n; ++i) {
        if (!~p[i]) {
          root[i] = i;
          s.push(i);
        }
      }
      while (!s.empty()) {
        ll v = s.front(); s.pop();
        if (~p[root[v]]) continue;
        for (ll i = 0; i < (ll)to[v].size(); ++i) {
          ll u = to[v][i];
          if (!~q[u]) {
            while (~u) {
              q[u] = v;
              swap(p[v],u);
              v = pre[v];
            }
            upd = true;
            ++res;
            break;
          }
          u = q[u];
          if (~pre[u]) continue;
          pre[u] = v; root[u] = root[v];
          s.push(u);
        }
      }
      if (upd) fill(pre.begin(),pre.end(),-1), fill(root.begin(),root.end(),-1);
    }
    return res;
  }
};

class MinCostFlow {
public:
  struct edge { ll to, cap, cost, rev; };

  ll V;
  vector<edge> G[MIN_COST_FLOW_MAX_V];
  ll dist[MIN_COST_FLOW_MAX_V];
  ll prevv[MIN_COST_FLOW_MAX_V];
  ll preve[MIN_COST_FLOW_MAX_V];
  ll h[MIN_COST_FLOW_MAX_V];

  MinCostFlow(ll v) {
    V = v;
  }
  void init() {
    for (ll i = 0; i < MAX_FLOW_MAX_V; i++) {
      G[i].clear();
    }
  }
  void add_edge(ll from, ll to, ll cap, ll cost) {
    G[from].push_back((edge){to, cap, cost, (ll)G[to].size()});
    G[to].push_back((edge){from, 0, -cost, (ll)G[from].size() - 1});
  }
  void add_undirected_edge(ll e1, ll e2, ll cap, ll cost) {
    add_edge(e1, e2, cap, cost);
    add_edge(e2, e1, cap, cost);
  }
  ll min_cost_flow(ll s, ll t, ll f) { // minas
    ll res = 0;
    while (f > 0) {
      fill(dist, dist + V, INF);
      dist[s] = 0;
      bool update = true;
      while (update) {
        update = false;
        for (ll v = 0; v < V; v++) {
          if (dist[v] == INF) continue;
          for (ll i = 0; i < (ll)G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
              dist[e.to] = dist[v] + e.cost;
              prevv[e.to] = v;
              preve[e.to] = i;
              update = true;
            }
          }
        }
      }
      if (dist[t] == INF) {
        return -1;
      }
      ll d = f;
      for (ll v = t; v != s; v = prevv[v]) {
        d = min(d, G[prevv[v]][preve[v]].cap);
      }
      f -= d;
      res += d * dist[t];
      for (ll v = t; v != s; v = prevv[v]) {
        edge &e = G[prevv[v]][preve[v]];
        e.cap -= d;
        G[v][e.rev].cap += d;
      }
    }
    return res;
  }
  ll min_cost_flow_dijkstra(ll s, ll t, ll f) {
    ll res = 0;
    fill(h, h + V, 0);
    while (f > 0) {
      priority_queue<P, vector<P>, greater<P> > que;
      fill(dist, dist + V, 0);
      dist[s] = 0;
      que.push(P(0, s));
      while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
          edge &e = G[v][i];
          if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
            dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
            prevv[e.to] = v;
            preve[e.to] = i;
            que.push(P(dist[e.to], e.to));
          }
        }
      }
      if (dist[t] == INF) {
        return -1;
      }
      for (int v = 0; v < V; v++) h[v] += dist[v];
      int d = f;
      for (int v = t; v != s; v = prevv[v]) {
        d = tmin<ll>(d, G[prevv[v]][preve[v]].cap);
      }
      f -= d;
      res += d * h[t];
      for (int v = t; v != s; v = prevv[v]) {
        edge &e = G[prevv[v]][preve[v]];
        e.cap -= d;
        G[v][e.rev].cap += d;
      }
      return res;
    }
    return 0;
  }
};

/**** LIS ****/
ll lis(ll* a, ll n, ll* dp) {
  fill(dp, dp + n, INF);
  for (ll i = 0; i < n; i++) *lower_bound(dp, dp + n, a[i]) = a[i];
  return (ll)(lower_bound(dp, dp + n, INF) - dp);
}

/**** Binary Search ****/

ll binarySearch(function<bool(ll)> check, ll ok, ll ng) {
  while ((ok - ng > 1) || (ng - ok > 1)) {
    ll mid = (ok + ng) / 2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  return ok;
}

double binarySearchDouble(function<bool(double)> check, double ok, double ng) {
  while ((ok - ng > EPS) || (ng - ok > EPS)) {
    double mid = (ok + ng) / 2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  return ok;
}

/**** Geometry ****/

bool isEqual(double a, double b) { return abs(a - b) < EPS; }
bool isCEqual(C a, C b) { return isEqual(a.cx, b.cx) && isEqual(a.cy, b.cy); }
bool isZero(double a) { return abs(a) < EPS; } // a == 0
bool isUZero(double a) { return a > EPS; } // a > 0
bool isUEZero(double a) { return a > -EPS; } // a >= 0
bool isLZero(double a) { return a < -EPS; } // a < 0
bool isLEZero(double a) { return a < EPS; } // a <= 0
C getUnitVector(C a) { double len = abs(a); return isZero(len) ? C(0.0, 0.0) : a / len; }
double dot(C a, C b) { return a.cx * b.cx + a.cy * b.cy; } // |a||b|cosθ
double det(C a, C b) { return a.cx * b.cy - a.cy * b.cx; } // |a||b|sinθ
bool isLineOrthogonal(C a1, C a2, C b1, C b2) { return isZero(dot(a1 - a2, b1 - b2)); } // a1-a2, b1-b2
bool isLineParallel(C a1, C a2, C b1, C b2) { return isZero(det(a1 - a2, b1 - b2)); } // a1-a2, b1-b2
bool isPointOnLine(C a, C b, C c) { return isZero(det(b - a, c - a)); } // a-b <- c
/*
bool isPointOnLineSegment(C a, C b, C c) { // a-b <- c
  return isZero(det(b - a, c - a)) && isUEZero(dot(b - a, c - a)) && isUEZero(dot(a - b, c - b));
}
*/
bool isPointOnLineSegment(C a, C b, C c) { return isZero(abs(a-c) + abs(c-b) - abs(a-b)); }
double distanceLineAndPoint(C a, C b, C c) { return abs(det(b-a, c-a)) / abs(b-a); } // a-b <- c
double distanceLineSegmentAndPoint(C a, C b, C c) { // a-b <- c
  if (isLEZero(dot(b-a, c-a))) return abs(c-a);
  if (isLEZero(dot(a-b, c-b))) return abs(c-b);
  return abs(det(b-a, c-a)) / abs(b-a);
}
bool isIntersectedLine(C a1, C a2, C b1, C b2) { // a1-a2, b1-b2
  return !isLineParallel(a1, a2, b1, b2);
}
C intersectionLine(C a1, C a2, C b1, C b2) { // isIntersectedLine-> true
  C a = a2 - a1, b = b2 - b1;
  return a1 + a * det(b, b1 - a1) / det(b, a);
}
bool comp_C(const C& c1, const C& c2) {
  if (c1.cx != c2.cx) return c1.cx < c2.cx;
  return c1.cy < c2.cy;
}
vector<C> convex_hull(C* ps, ll n) {
  sort(ps, ps+n, comp_C);
  ll k = 0;
  vector<C> qs(n*2);
  for (ll i = 0; i < n; i++) {
    while (k > 1 && det((qs[k-1] - qs[k-2]), (ps[i] - qs[k-1])) <= EPS) k--;
    qs[k++] = ps[i];
  }
  for (ll i = n-2, t = k; i >= 0; i--) {
    while (k > t && det((qs[k-1] - qs[k-2]), (ps[i] - qs[k-1])) <= EPS) k--;
    qs[k++] = ps[i];
  }
  qs.resize(k-1);
  return qs;
}

/**** main function ****/

ll n, d;

int main() {
  scanf("%lld%lld", &n, &d);
  printf("%lld\n", (n+2*d) / (2*d+1));
}
