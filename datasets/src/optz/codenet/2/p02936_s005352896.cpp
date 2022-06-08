#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,q;

struct Tree{
  int N;
  vector<vector<int>> info;
  explicit Tree();
  explicit Tree(int n) : N(n){
    info.resize(N);
  }
  void init(){
    for(int i=0; i<N-1; i++){
      int a,b; scanf("%d %d", &a, &b);
      a--; b--;
      this->info[a].push_back(b);
      this->info[b].push_back(a);
    }
  }
};

struct Solver : public Tree{
  int Q;
  ll x;
  vector<ll> ans;
  vector<int> reached;
  explicit Solver(int n, int q) : Tree(n), Q(q){
    this->init();
    ans.resize(n); ans.assign(n,0);
    reached.resize(n); reached.assign(n,0);
  }
  void print_item(){
    for(int i=0; i<N; i++){
      if(!this->info.empty()){
        for(int j=0; j<(int)this->info[i].size(); j++){
          printf("%d %d\n", i, this->info[i][j]);
        }
      }
    }
  }
  void dfs(int i){
    reached[i] = 1;
    if(!this->info[i].empty()){
      for(int j=0; j<(int)this->info[i].size(); j++){
        int im = this->info[i][j];
        if(this->reached[im]) continue;
        ans[im] += ans[i];
        dfs(im);
      }
    }
    return;
  }
  void solve(){
    for(int i=0; i<Q; i++){
      int p;
      scanf("%d %lld", &p, &x); p--;
      ans[p] += x;
    }
    dfs(0);
    for(int i=0; i<N; i++){
      printf("%lld\n", ans[i]);
    }
  }
};

int main(){
  scanf("%d %d", &n, &q);

  Solver solver(n,q);
  solver.solve();
}