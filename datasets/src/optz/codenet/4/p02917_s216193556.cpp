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
#include<cassert>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> Q;
typedef complex<double> C;
#define cx real()
#define cy imag()
const ll INF = 1LL << 60;
const double DINF = 1e30;
const ll mod = 1000000007;
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, -1, 0, 1};
const C I = C(0, 1);
const double EPS = 1e-10;
const ll NCK_MAX = 510000;

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

template <typename T>
class Zip {
  vector<T> d;
  bool flag;
  void init() {
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    flag = false;
  }
public:
  Zip() {
    flag = false;
  }
  void add(T x) {
    d.push_back(x);
    flag = true;
  }
  ll getNum(T x) {
    if (flag) init();
    return lower_bound(d.begin(), d.end(), x) - d.begin();
  }
  ll size() {
    if (flag) init();
    return (ll)d.size();
  }
};

class UnionFind {
  vector<ll> par, rank; // par > 0: number, par < 0: -par
public:
  void init(ll n) {
    par.resize(n); rank.resize(n);
    fill(par.begin(), par.end(), 1); fill(rank.begin(), rank.end(), 0);
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
    node.resize(2 * n - 1);
    fill(node.begin(), node.end(), init);
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
class Graph {
  struct edge { ll to; T cost; };
  struct edge_data { ll from, to; T cost; };

  ll v;
  vector<vector<edge>> e, re;
  vector<edge_data> ed;
  vector<bool> used;
  vector<ll> vs, cmp;
  bool isDirected, isMinasEdge;
public:
  Graph(ll _v, bool _isDirected = true, ll range_add = 0) {
    // range_add 0:no / 1:in / 2:out / 3:in+out
    //_v++;
    v = _v, isDirected = _isDirected; isMinasEdge = false;
    e.resize(v), re.resize(v);
  }
  void add_edge(ll s, ll t, T cost = 1) {
    e[s].push_back((edge){t, cost});
    if (!isDirected) e[t].push_back((edge){s, cost});
    else re[t].push_back((edge){s, cost});
    ed.push_back((edge_data){s, t, cost});
    if (cost < 0) isMinasEdge = true;
  }
  vector<T> dijkstra(ll s) {
    vector<T> d(v, INF);
    d[s] = 0;
    auto edge_cmp = [](const edge& a, const edge& b) { return a.cost > b.cost; };
    priority_queue<edge, vector<edge>, decltype(edge_cmp)> pq(edge_cmp);
    pq.push((edge){s, 0});
    while (!pq.empty()) {
      edge temp = pq.top(); pq.pop();
      if (d[temp.to] < temp.cost) continue;
      for (const edge& next : e[temp.to]) {
        T cost = temp.cost + next.cost;
        if (d[next.to] > cost) {
          d[next.to] = cost;
          pq.push((edge){next.to, cost});
        }
      }
    }
    return d;
  }
  vector<T> bellmanford(ll s) {
    vector<T> d(v, INF);
    d[s] = 0;
    for (ll i = 0; i < v; i++) {
      for (const edge_data& temp : ed) {
        if (d[temp.from] != INF && d[temp.to] > d[temp.from] + temp.cost) d[temp.to] = d[temp.from] + temp.cost;
        if (!isDirected && d[temp.to] != INF && d[temp.from] > d[temp.to] + temp.cost) d[temp.from] = d[temp.to] + temp.cost;
      }
    }
    for (ll i = 0; i < v; i++) {
      for (const edge_data& temp : ed) {
        if (d[temp.from] != INF && d[temp.to] > d[temp.from] + temp.cost) d[temp.to] = -INF;
        if (!isDirected && d[temp.to] != INF && d[temp.from] > d[temp.to] + temp.cost) d[temp.from] = -INF;
      }
    }
    return d;
  }
  vector<T> shortest_path(ll s) {
    if (isMinasEdge) return bellmanford(s);
    else return dijkstra(s);
  }
  T kruskal() {
    // if (isDirected)
    UnionFind uf;
    uf.init(v);
    auto edge_data_cmp = [](const edge_data& a, const edge_data& b) { return a.cost < b.cost; };
    sort(ed.begin(), ed.end(), edge_data_cmp);
    T ans = 0;
    for (const edge_data& temp : ed) {
      if (uf.isSame(temp.from, temp.to)) continue;
      uf.merge(temp.from, temp.to);
      ans += temp.cost;
    }
    return ans;
  }
  void scc_dfs(ll s) {
    used[s] = true;
    for (const edge& i : e[s]) if (!used[i.to]) scc_dfs(i.to);
    vs.push_back(s);
  }
  void scc_rdfs(ll s, ll k) {
    used[s] = true;
    cmp[s] = k;
    for (const edge& i : re[s]) if (!used[i.to]) scc_rdfs(i.to, k);
  }
  vector<ll> scc() {
    used.resize(v);
    fill(used.begin(), used.end(), false);
    cmp.resize(v);
    vs.clear();
    for (ll i = 0; i < v; i++) if (!used[i]) scc_dfs(i);
    used.resize(v);
    fill(used.begin(), used.end(), false);
    ll k = 0;
    for (ll i = vs.size() - 1; i >= 0; i--) if (!used[vs[i]]) scc_rdfs(vs[i], k++);
    return cmp;
  }
};

ll n, b[100], ans;

int main() {
  scanf("%lld", &n);
  for (ll i = 0; i < n-1; i++) scanf("%lld", &b[i]);
  for (ll i = 0; i < n; i++) ans += min(b[min(n-2, i)], b[max(0LL, i-1)]);
  printf("%lld\n", ans);
}
