#include <bits/stdc++.h>
using namespace std;


vector<int> ans;
vector<int> vec[200000]; 


void dfs(int v){
  for(int u : vec[v]){
    ans.at(u) += ans.at(v);
    dfs(u);
  }
  
}

int main() {
  int n, q;
  cin >> n;
  cin >> q;
  
  
  for (int i = 0; i < n - 1; i ++){
    int a, b;
    cin >> a;
    cin >> b;
    --a;
    --b;
    vec[a].push_back(b);
  }
  
  ans.resize(n);

  for (int i = 0; i < q; i ++){
    int p, x;
    cin >> p;
    cin >> x;
    --p;
    
    ans.at(p) += x;
    
  }

  dfs(0);
  
  for(int i; i < n; i++){
    cout << ans.at(i) << endl;
  }
  

  
}