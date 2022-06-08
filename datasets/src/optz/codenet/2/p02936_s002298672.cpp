#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

// 深さ優先探索
vector<bool> seen;
vll score;
void dfs(const Graph &G, int v) {
  seen[v] = true; // v を訪問済にする

  // v から行ける各頂点 next_v について
  for (auto next_v : G[v]) {
    if (seen[next_v]) continue; // next_v が探索済だったらスルー
    score[next_v] += score[v];
    dfs(G, next_v); // 再帰的に探索
  }
}

int main()
{
  int N,Q;
  cin >> N >> Q;
  
  Graph G(N);
  vint P(Q);
  vint X(Q);
  REP(i,N-1){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
  }
  REP(i,Q){
    cin >> P[i] >> X[i];
    P[i]--;
  }
  
  score.assign(N, 0);
  REP(i,Q){
    score[P[i]] += X[i];
  }
  seen.assign(N,false);
  REP(i,N){
    if(seen[i])continue;
    dfs(G,i);
  }
  for(auto s :score){
    cout << s << " ";
  }
  cout << endl;
}