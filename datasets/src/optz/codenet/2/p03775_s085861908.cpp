//includes
#include<iostream>
#include<vector>
#include<set>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<map>
#include<queue>
#include<iomanip>
#include<numeric>
#include<assert.h>
#include<cstring>
#include<unordered_map>
#include<bitset>

//macros and consts
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define FORE(i,a) for(auto &i : a)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define accm accumulate
#define Fi first
#define Se second
#define INF 1e9
#define llINF (1LL<<60)
#define mINF -1e9
#define mllINF -(1LL<<60)
#define endl "\n"
#define CONT continue
#define BRK break

//shorter types
using namespace std;
using ll = long long;
using vi = std::vector<int>;
using vc = std::vector<char>;
using vll = std::vector<long long>;
using vs = std::vector<string>;
using Mi = map<int,int>;
using Mll = map<ll,ll>;
using UMi = unordered_map<int,int>;
using UMll = unordered_map<ll,ll>;
using Pi = pair<int,int>;
using Pll = pair<ll,ll>;
using vPi = vector<Pi>;
using vPll = vector<Pll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvc = vector<vector<char>>;
using vvs = vector<vector<string>>;
using pqgi = priority_queue<int,vector<int>,greater<int>>;
using pqsi = priority_queue<int,vector<int>,less<int>>;
using pqgll = priority_queue<int,vector<int>,greater<int>>;
using pssll = priority_queue<int,vector<int>,less<int>>;
template<class T>
using vec = vector<T>;

//frequent functions and data structures
class Cpmath{
  public:
    template<typename T>
    static T gcd(T a, T b){
      if (a == 0) 
        return b; 
      return gcd(b % a, a); 
    }
    template<typename T>
    static T findGCD(vector<T> &arr, size_t n){
      T result = arr[0]; 
      for (size_t i = 1; i < n; i++) 
        result = gcd(arr[i], result); 
      return result; 
    }
    template<typename T>
    static T findLCM(vector<T> &arr, size_t n){
      T lcm = arr[0];
      for(size_t i = 1; i < n ;i++){
        lcm = (lcm / gcd(arr[i],lcm)) * arr[i];
      }
      return lcm;
    }
    template<typename T>
    static vector<T> divisor(T n){
      vector<T> ret;
      for(T i = 1; i * i <= n ; i++){
        if(n % i == 0){
          ret.pb(i);
        }
      }
      sort(all(ret));
      return ret;
    }
    template<typename T>
    static bool is_prime(T n){
      if(n == 1){
        return false;
      }
      for(size_t i = 2 ; i <= pow(n,0.5) ; i++){
        if(n % i == 0){
          return false;
        }
      }
      return true;
    }
    static ll fact(ll n){
      if(n == 0){
        return 1LL;
      }
      else{
        return n * fact(n - 1);
      }
    }
    static ll permutation(int n, int r){
      assert(n >= r);
      ll ret = 1;
      for(int i = n ; i > n - r ; i--){
        ret *= i;
      }
      return ret;
    }
};

class NCR{
  private:
    static const int MAX = 210000;
    static const int MOD = 998244353;
    ll fac[MAX],finv[MAX],inv[MAX];
  public:
    void COMinit(){
      fac[0] = fac[1] = 1;
      finv[0] = finv[1] = 1;
      inv[1] = 1;
      for(int i = 2 ; i < MAX ; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
      }
    }
    ll COM(int n,int k){
      if(n < k) return 0;
      if(n < 0 || k < 0){
        return 0;
      }
      return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
    }
};

struct BipartiteMatching {
	//https://atcoder.jp/contests/arc092/submissions/2217043
    vector<vector<int>> E; int n, m; vector<int> match, dist;
    void init(int _n,int _m){n=_n,m=_m;E.resize(n+m+2);match.resize(n+m+2);dist.resize(n+m+2);}
    bool bfs() {
        queue<int> que;
        FOR(i, 1, n + 1) {
            if (!match[i]) dist[i] = 0, que.push(i);
            else dist[i] = INF;
        }
        dist[0] = INF;
        while (!que.empty()) {
            int u = que.front(); que.pop();
            if (u) for(auto &v : E[u]) if (dist[match[v]] == INF) {
                dist[match[v]] = dist[u] + 1;
                que.push(match[v]);
            }
        }
        return (dist[0] != INF);
    }
    bool dfs(int u) {
        if (u) {
            for(auto &v : E[u]) if (dist[match[v]] == dist[u] + 1) if (dfs(match[v])) {
                match[v] = u; match[u] = v;
                return true;
            }
            dist[u] = INF;
            return false;
        }
        return true;
    }
    void add(int a, int b) { b += n; E[a + 1].push_back(b + 1); E[b + 1].push_back(a + 1); }
    int whois(int x) { return match[x + 1] - 1; }
    int solve() {
        FOR(i, 0, n + m + 1) match[i] = 0;
        int res = 0;
        while (bfs()) FOR(i, 1, n + 1) if (!match[i] && dfs(i)) res++;
        return res;
    }
};

struct SegmentTree{
  private:
    int n;
    vector<int> node;
  public:
    SegmentTree(vector<int> v){
      int sz = v.size();
      n = 1;
      while(n < sz) n *= 2;
      node.resize(2 * n - 1 , INF);
      for(int i = 0 ; i < sz ; i++){
        node[i + n - 1] = v[i];
      }
      for(int i = n - 2 ; i >= 0 ; i--){
        node[i] = min(node[2*i+1],node[2*i+2]);
      }
    }
    void update(int x, int val){
      x += (n - 1);
      node[x] = val;
      while(x > 0){
        x = (x - 1) / 2;
        node[x] = min(node[2*x+1],node[2*x+2]);
      }
    }
    int getmin(int a, int b , int k = 0, int l = 0, int r = -1){
      if(r < 0){
        r = n;
      }
      if(r <= a || b <= l){
        return INF;
      }
      if(a <= l && r <= b){
        return node[k];
      }
      int vl = getmin(a,b,2*k+1,l,(l+r)/2);
      int vr = getmin(a,b,2*k+2,(l+r)/2,r);
      return min(vl,vr);
    }
};

template<class Abel> struct WUnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    WUnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};

struct UnionFind{
  vector<int> par;
  UnionFind(int n) : par(n,-1) {}
  void init(int n) {par.assign(n,-1);}
  int root(int x){
    if(par[x] < 0) return x;
    else return par[x] = root(par[x]);
  }
  bool issame(int x,int y){
    return root(x) == root(y);
  }
  bool merge(int x,int y){
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]){
      swap(x,y);
    }
    par[x] += par[y];
    par[y] = x;
    return true;
  }
  int size(int x){
    return -par[root(x)];
  }
};

void YN(bool a){
  cout << (a?"YES":"NO") << endl;
}

void Yn(bool a){
  cout << (a?"Yes":"No") << endl;
}
void yn(bool a){
  cout << (a?"yes":"no") << endl;
}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<int> lcs(const vector<int>& a, const vector<int>& b) {
  const int n = a.size(), m = b.size();
  vector< vector<int> > X(n+1, vector<int>(m+1));
  vector< vector<int> > Y(n+1, vector<int>(m+1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i] == b[j]) {
        X[i+1][j+1] = X[i][j] + 1;
        Y[i+1][j+1] = 0;
      } else if (X[i+1][j] < X[i][j+1]) {
        X[i+1][j+1] = X[i][j+1];
        Y[i+1][j+1] = +1;
      } else {
        X[i+1][j+1] = X[i+1][j];
        Y[i+1][j+1] = -1;
      }
    }
  }
  vector<int> c;
  for (int i = n, j = m; i > 0 && j > 0; ) {
    if      (Y[i][j] > 0) --i;
    else if (Y[i][j] < 0) --j;
    else { c.push_back(a[i-1]); --i; --j; }
  }
  reverse(c.begin(), c.end());
  return c;
}

template<typename T>
inline int digitsum(T num){
  int ret = 0;
  while(num){
    ret += num % 10;
    num /= 10;
  }
  return ret;
}
template<typename InputIt,typename T>
inline bool argexist(InputIt first,InputIt last,const T& x){
  if(std::find(first,last,x) != last){
    return true;
  }
  else{
    return false;
  }
}
template<typename InputIt,typename T>
inline int argfind(InputIt first, InputIt last, const T& x){
  auto it = find(first,last,x);
  return distance(first,it);
}
template<typename InputIt>
inline int argmax(InputIt first, InputIt last) {
    auto it = max_element(first, last);
    return distance(first, it);
}
template<typename InputIt>
inline int argmin(InputIt first, InputIt last) {
    auto it = min_element(first, last);
    return distance(first, it);
}
// you need sort before using this func
template<typename T>
inline void erasebv(vector<T>& c,T v){
  c.erase(remove(begin(c),end(c),v),end(c));
}
// you need sort before using this func
template<typename T>
inline void uniq(T& c) {
    c.erase(unique(begin(c), end(c)), end(c));
}
template<typename T>
inline T POP_BACK(vector<T>& que) {
    T x = que.back(); que.pop_back();
    return x;
}
template<typename T>
inline T POP_BACK(deque<T>& que) {
    T x = que.back(); que.pop_back();
    return x;
}
template<typename T>
inline T POP_FRONT(deque<T>& que) {
    T x = que.front(); que.pop_front();
    return x;
}
template<typename T, typename C>
inline T POP(stack<T,C>& stk) {
    T x = stk.top(); stk.pop();
    return x;
}
template<typename T, typename C>
inline T POP(queue<T,C>& que) {
    T x = que.front(); que.pop();
    return x;
}
template<typename T, typename Cont, typename Cmp>
inline T POP(priority_queue<T,Cont,Cmp>& que) {
    T x = que.top(); que.pop();
    return x;
}
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {return s << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  return s;
}
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
  s << vv[i] << endl;
  }
  return s;
}

//utils to solve graph chals easy
namespace GraphLib{
	//http://www.prefield.com/algorithm/index.html
  using Weight = int;
  struct Edge{
    int src,dst;
    Weight weight;
    Edge(int src,int dst,Weight weight):
      src(src),dst(dst),weight(weight){}
  };
  bool operator < (const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight :
      e.src != f.src ? e.src < f.src : e.dst < f.dst;
  }
  using Edges = vector<Edge>;
  using Graph = vector<Edges>;
  using Array = vector<Weight>;
  using Matrix = vector<Array>;
  
  void DijkstraShortestPath(const Graph &g, int s,
      vector<Weight> &dist, vector<int> &prev) {
    int n = g.size();
    dist.assign(n, INF); dist[s] = 0;
    prev.assign(n, -1);
    priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
    for (Q.push(Edge(-2, s, 0)); !Q.empty(); ) {
      Edge e = Q.top(); Q.pop();
      if (prev[e.dst] != -1) continue;
      prev[e.dst] = e.src;
      FORE(f,g[e.dst]) {
        if (dist[f.dst] > e.weight+f.weight) {
          dist[f.dst] = e.weight+f.weight;
          Q.push(Edge(f.src, f.dst, e.weight+f.weight));
        }
      }
    }
  }
  vector<int> DijkstraBuildPath(const vector<int> &prev, int t) {
    vector<int> path;
    for (int u = t; u >= 0; u = prev[u])
      path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
  }

  bool BellmandFordshortestPath(const Graph g, int s,
    vector<Weight> &dist, vector<int> &prev) {
    int n = g.size();
    dist.assign(n, INF+INF); dist[s] = 0;
    prev.assign(n, -2);
    bool negative_cycle = false;
    REP(k, n) REP(i, n) FORE(e,g[i]) { // you can increase k for safety
      if (dist[e.dst] > dist[e.src] + e.weight) {
        dist[e.dst] = dist[e.src] + e.weight;
        prev[e.dst] = e.src;
        if (k == n-1) {
          dist[e.dst] = -INF;
          negative_cycle = true;
        }
      }
    }
    return !negative_cycle;
  }
  vector<int> BellmanFordbuildPath(const vector<int> &prev, int t) {
    vector<int> path;
    for (int u = t; u >= 0; u = prev[u])
      path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
  }


  void visit(const Graph & g, int v, int u,
      Edges& brdg, vector< vector<int> >& tecomp,
      stack<int>& roots, stack<int>& S, vector<bool>& inS,
      vector<int>& num, int& time) {
    num[v] = ++time;
    S.push(v); inS[v] = true;
    roots.push(v);
    FORE(e, g[v]) {
      int w = e.dst;
      if (num[w] == 0)
        visit(g, w, v, brdg, tecomp, roots, S, inS, num, time);
      else if (u != w && inS[w])
        while (num[roots.top()] > num[w]) roots.pop();
    }
    if (v == roots.top()) {
      brdg.push_back(Edge(u, v, 1)); // any weight will do
      tecomp.push_back(vector<int>());
      while (1) {
        int w = S.top(); S.pop(); inS[w] = false;
        tecomp.back().push_back(w);
        if (v == w) break;
      }
      roots.pop();
    }
  }
  void bridge(const Graph& g, Edges& brdg, vector< vector<int> >& tecomp) {
    const int n = g.size();
    vector<int> num(n);
    vector<bool> inS(n);
    stack<int> roots, S;
    int time = 0;
    REP(u, n) if (num[u] == 0) {
      visit(g, u, n, brdg, tecomp, roots, S, inS, num, time);
      brdg.pop_back();
    }
  }
  pair<Weight, Edges> minimumSpanningTree(const Graph &g, int r = 0) {
    int n = g.size();
    Edges T;
    Weight total = 0;
  
    vector<bool> visited(n);
    priority_queue<Edge> Q;
    Q.push( Edge(-1, r, 0) );
    while (!Q.empty()) {
      Edge e = Q.top(); Q.pop();
      if (visited[e.dst]) continue;
      T.push_back(e);
      total += e.weight;
      visited[e.dst] = true;
      FORE(f, g[e.dst]) if (!visited[f.dst]) Q.push(f);
    }
    return pair<Weight, Edges>(total, T);
  }
}


//here begins your code
int digitnum(ll n){
  int ret = 1;
  while(true){
    if(n / 10 != 0){
      n /= 10;
      ret++;
    }
    else{
      BRK;
    }
  }
  return ret;
}
ll F(ll A,ll B){
  ll a = digitnum(A);
  ll b = digitnum(B);
  if(a >= b){
    return a;
  }
  else{
    return b;
  }
}

ll N;
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N;
  vector<ll> divisors = Cpmath::divisor(N);
  ll mi = llINF;
  FORE(e,divisors){
    mi = min(mi,F(e,N/e));
  }
  cout << mi << endl;
  //check types
  //do not eb if you resize
  //resize before you access by idx
  return 0;
}
