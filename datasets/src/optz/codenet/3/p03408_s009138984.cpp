#include<iostream>
using namespace std;

int main(){
  int n,m,i,j;
  char s[105];
  char t[105];
  cin >> n;
  for(i=0;i<n;i++){
    cin >> s[i];
  }
  cin >> m;
  for(i=0;i<m;i++){
    cin >> t[i];
  }
  int x;
  int ans = 0;
  for(i=0;i<n;i++){
    x = 0;
    for(j=0;j<max(n,m);j++){
      if(j < n){
        if(s[i] == s[j]) x += 1;
      }
      if(j < m){
        if(s[i] == t[j]) x -= 1;
      }
    }
    if(x > ans){
      ans = x;
    }
  }
  cout << ans << endl;
  return 0;
}
