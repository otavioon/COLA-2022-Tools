#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int N,M;
  cin >> N;
  vector<string> s(N);
  rep(i,N)
    cin >> s.at(i);
  cin >> M;
  vector<string> t(M);
  rep(i,M)
    cin >> t.at(i);
  vector<int> sum(N);
  
  rep(i,N){
    rep(j,N){
      if(s.at(i)==s.at(j))
        sum.at(i)++;
    } 
    rep(j,M){
      if(s.at(i)==t.at(j))
        sum.at(i)--;
    }
  }

  int result = sum.at(0);

  rep(i,N){
    if(result<sum.at(i))
      result = sum.at(i);
  }
  
  if(result<=0)
    cout << 0 << endl;
  else
    cout << result << endl;
    
  
  
  
  
  
    
  
}