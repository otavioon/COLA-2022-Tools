#include <iostream>
#include <vector>
#include <string>

using namespace std;


int change(string s){
  
  int ans = 0;
  
  char first = s[0];

  for(int i = 1; i < s.length(); i++){
    char sec = s[i];
    
    if(first != sec || first == '0'){
      first = sec;
    }else{
      first = '0';
      ans++;
    
    }
      
  }
  //cout << ans << endl;
  return ans;
}



int main(void){
  
  string s;
  long k;
  cin >> s >> k;
  
  long ans = change(s);
  
  if(k >= 2 && change(s+s) != ans*2){
    if(k >= 3 && change(s+s+s) != ans*3){
      cout << ans*k + 1 << endl;
    }
    else{
    cout << ans*k + k - 1 << endl;  
    }
  }
  else{
  cout << ans * k << endl;
  }
  
  return 0;
}