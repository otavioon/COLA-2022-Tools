#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m; i<n; i++)
using namespace std;

int main(){
  int n, t=0, c=0;
  cin >> n;
  int a[n], b[n];
  rep(i,0,n) cin >> a[i];
  sort(a, a+n);
  rep(i,1,a[n-1]+1){
    rep(j,0,n){
      if(i==a[j]){
        b[c]=i;
        c++;
        break;
      }
    }
  }
  
  rep(i,0,c-2){
    rep(j,i+1,c-1){
      rep(k,j+1,c){
        if(b[i]<b[j]+b[k] && b[j]<b[k]+b[i] && b[k]<b[i]+b[j]) t++;
      }
    }
  }
  cout << t << endl;
  
  return 0;
}