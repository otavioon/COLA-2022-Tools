#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9

int ans = INF;
int N, K;
vector<int> D;
vector<bool> flag(10, true);
void dfs(int pay){
  if(pay >= N){
    ans = min(pay, ans);
    return;
  }
  REP(i, 10){
    if(flag[i]){
      dfs(pay*10+i);
    }
  }
}

int main(){
  cin >> N >> K;
  D.resize(K);
  REP(i, K){
    cin >> D[i];
    flag[D[i]] = false;
  }
  FOR(i, 1, 10){
    if(flag[i]){
      dfs(i);
    }
  }
  cout << ans << endl;


  return 0;
}
