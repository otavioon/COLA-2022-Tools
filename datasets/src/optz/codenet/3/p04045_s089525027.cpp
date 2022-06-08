#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> v(10);
  for(int i=0; i<10; ++i) v[i] = i;
  for(int i=0; i<k; ++i){
    int d;
    cin >> d;
    v.erase(lower_bound(v.begin(),v.end(),d));
  }
  queue<int> que;
  for(int i=0; i<10-k; ++i){
    if(v[i] == 0) continue;
    que.push(v[i]);
  }
  int ans;
  while(1){
    int x = que.front();
    if(x >= n){
      ans = x;
      break;
    }
    que.pop();
    for(int i=0; i<10-k; ++i) que.push(x*10+v[i]);
  }
  cout << ans << endl;
}