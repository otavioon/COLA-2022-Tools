#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  string s[150],t[150];
  cin >> n;
  int i;
  for(i=0;i<n;i++){
    cin >> s[i];
  }
  cin >> m;
  int j;
  for(j=0;j<m;j++){
    cin >> t[j];
  }
  int p[150];
  int k;
  for(k=0;k<n;k++){
    for(i=0;i<n;i++){
      if(s[k]==s[i]){
        p[k]++;
      }
    }
    for(j=0;j<m;j++){
      if(s[k]==t[j]){
        p[k]--;
      }
    }
  }
  sort(p,p+n);
  cout << max(0,p[n-1]) << endl;
}