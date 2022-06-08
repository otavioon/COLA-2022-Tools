#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  long long k;
  cin >> k;
  long long ans=0,t=0;
  int n = s.size(),x=0,y=0;
  if(n == 1){
    ans = k/2;
  }
  else {
    for(int i=0;i<n;i++){
      int q=0;
      for(int j=i;j<n;j++){
        if(s.at(i) == s.at(j)){
          q++;
          if(j = n-1){
            i = n-1;
            break;
          }
        }
        else {
          i = j-1;
          break;
        }
      }
      ans += q/2;
    }
    
    for(int i=0;i<n;i++){
      if(s.at(i) == s.at(0)){
        x++;
      }
      else {
        break;
      }
    }
    for(int i=n-1;i>=0;i--){
      if(s.at(i) == s.at(n-1)){
        y++;
      }
      else {
        break;
      }
    }
    
    if(s.at(0) == s.at(n-1)){
      if(x == 1 && y == 1){
        t = k-1;
      }
      else {
        if(x<n && x%2 == 1 && y%2 == 1){
          t = k-1;
        }
        else if(x == n && n%2 == 1){
          t = k/2;
        }

      }
    }
    ans = ans*k + t;
  }
  cout << ans << endl;       
  
  return 0;
}
