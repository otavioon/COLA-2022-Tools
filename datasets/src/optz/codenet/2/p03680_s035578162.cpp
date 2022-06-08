#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k=0,a[n],d=0;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  while(d<n+1){
    d++;
    k=a[k];
    if(k==1){
      cout << d;
      return 0;
    }
  }
  cout << -1;
}
