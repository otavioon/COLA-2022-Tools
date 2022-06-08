#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rrep(i, n) for(int i=(n-1); i>=0; --i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()
#define memr(dp, val) memset(dp, val, sizeof(dp))
using namespace std;
typedef long long ll;
static const int INTINF = (INT_MAX >> 1); // 10^9 + 10^7
static const ll LLINF = (LLONG_MAX >> 1);
static const int MAX = 1e5+1;
static const ll MOD = 1e9+7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <size_t N> string to_string(bitset<N> bs) {
  string res;
  for (size_t i = 0; i < N; ++i) res += '0' + bs[i];
  return res;
}
string to_string(vector<bool> v) {
  string res = "{";
  for (bool e : v) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p);
template <class C> string to_string(C c) {
  string res = "{";
  for (auto e : c) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug() { cerr << '\n'; }
template <class Head, class... Tail> void debug(Head head, Tail... tail) {
  cerr << '\t' << to_string(head), debug(tail...);
}
#ifdef LOCAL
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

vector<int> g[MAX];
int col[MAX];

void bfs(int v, int bef, int c){
  if(col[v] != -1) return;
  col[v] = c;
  for(int u : g[v]){
    if(u == bef) continue;
    
    bfs(u, v, 1 - c);
  }
}

int main(int argc, const char * argv[]) {
  std::cout << std::fixed << std::setprecision(15);

  int N; cin >> N;
  memr(col, -1);
  vector<int> A(N);
  set<int> st;
  vector<int> twos(30);
  rep2(i, 1, 31) twos[i-1] = pow(2, i);
  rep(i, N){
    cin >> A[i];
    st.insert(A[i]);
  }

  int ans = 0;
  int tmp = 0;
  rep(i, N){
    st.erase(A[i]);
    rep(j, 30){
      auto it = st.find(abs(A[i] - twos[j]));
      if(it != st.end()){
        DEBUG(A[i]);
        DEBUG(twos[j]);
        DEBUG(i);
        DEBUG(distance(st.begin(), it));
        int k = distance(st.begin(), it);
        g[i].push_back(k);
        g[k].push_back(i);
        tmp = i;
      }
    }
  }

  rep(i, N)
    bfs(i, -1, 0);

  int b=0, w=0;
  rep(i, N){
    if(col[i]) w++;
    else b++;
  }


  cout << min(w, b) << endl;
}  
