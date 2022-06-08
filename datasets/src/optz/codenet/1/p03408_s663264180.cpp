#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  
  
  string s[100];
  
  
  string t[100];
  
  for(int i=0; i<n; i++){
    cin >> s[i];
  }
  cin >> m;
  for(int i=0; i<m; i++){
    cin >> t[i];
  }
  int maxx=0;
  for(int i=0; i<=100; i++){
    int cnt = 0;
    for(int j=0; j<=100; j++){
      if(s[i]==s[j]){
        cnt++;
      }
      if(s[i]==t[j]){
        cnt--;
      }
    }
    maxx = max(maxx, cnt);
  }
  cout << maxx << endl;
}