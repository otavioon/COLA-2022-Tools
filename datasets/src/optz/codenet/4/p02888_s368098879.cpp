#include<iostream>
#include<cstdio>
using namespace std;
const int CN = 4e3+3;
int n,a[CN];
int tot[CN],sum[CN],ans = 0;
int abs(int x) {return x>0?x:-x;}
int main(){
  cin>>n; for(int i=1;i<=n;i++) cin>>a[i],tot[ a[i] ]++,tot[0] = max(tot[0], a[i]);
  for(int t=1;t<=tot[0]*2;t++) sum[t] = sum[t-1] + tot[t];
  for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
      if(i != j){
      	ans += sum[ a[i] + a[j] - 1 ] - sum[ abs(a[i] - a[j]) ];
      	if(a[i] + a[j] > a[i] && abs(a[i] - a[j]) < a[i]) ans--;
      	if(a[i] + a[j] > a[j] && abs(a[i] - a[j]) < a[j]) ans--;
	  }
  cout<<ans/3; 
}