#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >> n;
  vector<string> s(n);
  for(int i=0; i<n;i++){
    cin >> s.at(i);
  }
  cin >> m;
  vector<string> t(m);
  for(int i=0; i<m; i++){
    cin >> t.at(i);
  }
  
  int i;
  int sum=1,ans=0;

  vector<string> u;
  for(i=0;i<n;i++){
    
    for(int j=i+1;j<n;j++){
      if(s.at(i) == s.at(j)){
        sum++;
      }
    }
    for(int l=0;l<m;l++){
      if(s.at(i)==t.at(l)){
      sum--;
      }
    }
      
    if(ans<sum){
      ans = sum;
      //u=s.at(i);

    }
    sum=1;
  }
  
    cout << ans << endl;
}


         
    
  