#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  bool frag = 0;
  long k = 0;
  long ans = 0;
  
  cin >> s >> k;
  
  for(int i = 0; i < s.size() - 1; i++){
    if(s.at(i) == s.at(i + 1)){
      if(frag == 0){
        ans++;
        frag = 1;
      }
      else{
        frag = 0;
      }
    }
    else{
      frag = 0;
    }
  }
  
  if(s.at(s.size() - 1) == s.at(0) && frag == 0){
    ans++;
  }
  
  ans *= k;
  
  cout << ans << endl;
  
  return 0;
}