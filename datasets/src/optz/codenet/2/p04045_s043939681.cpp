#include <bits/stdc++.h>
using namespace std;
using lint = long long;
lint N, K;
set<lint> SET;
vector<lint> ans;


void dfs(lint num){
  if(num >= N) {
    ans.push_back(num);
    return;
  }
  if(num == 0){
    for(auto value : SET){
      if(value != 0) dfs(value);
    }
  }
  else{
    for(auto value : SET){
      dfs(10 * num + value);
    }
  }
}

signed main(){
  cin >> N >> K;
  for(lint i = 0; i < 10; i++) SET.insert(i);
  for(lint i = 0; i < K; i++){
    lint x; cin >> x; SET.erase(x);
  }
  dfs(0);
  sort(ans.begin(), ans.end());
  cout << ans[0] << endl;
}