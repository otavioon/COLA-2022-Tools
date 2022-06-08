#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[100001]={}, b[100001]={}, c[100001]={};

int main(){
  int n; cin >> n;
  for(int i=0; i<n; i++){cin >> a[i];}
  for(int i=0; i<n; i++){cin >> b[i];}
  for(int i=0; i<n; i++){cin >> c[i];}

  sort(a,a+n);
  sort(b,b+n);
  sort(c,c+n);

  int u=0, v=0, ans=0, reg=0;
  for(int i=0; i<n; i++){
    while((b[u] < c[i]) && u < n){
      u++;
      reg += v;
      while((a[v] < b[u-1]) && v < n){
        reg++;
        v++;
      }
    }
    ans += reg;
  }
  cout << ans << endl;
}