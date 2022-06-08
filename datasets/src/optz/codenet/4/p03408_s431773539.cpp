#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
  int N,M;
  cin >> N;
  set<string> c;
  vector<string> s(N);
  rep(i,N){
    cin >> s.at(i);
    if(!(c.count(s.at(i)))){
      c.insert(s.at(i));
    }
  }
  cin >> M;
  vector<string> t(M);
  rep(i,M){
    cin >> t.at(i);
    if(!(c.count(t.at(i)))){
      c.insert(t.at(i));
    }
  }
  int ans = 0;
  for(auto p : c){
    int num = 0;
    rep(j,N){
      if(p==s.at(j)){
        ++num;
      }
    }
    rep(j,M){
      if(p==t.at(j)){
        --num;
      }
    }
    ans = max(num,ans);
  }
  cout << ans << endl;
}
