#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
#define M 1000000007
int main(){
  int n,c=0;
  cin>>n;
  int v[n];
  vector<int> a(2010,0),b(2010,0);
  for(int i=0;i<n;i++){
    cin>>v[i];
    a[v[i]]++;
  }
  for(int i=1;i<2010;i++){
    b[i]=b[i-1]+a[i];
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int d;
      int ma=max(v[i],v[j]),mi=min(v[i],v[j]);
      d=max(0,b[ma+mi-1]-b[ma-mi]);
      if(ma+mi>ma&&ma-mi<ma)d--;
      if(ma+mi>mi&&ma-mi<mi)d--;
      c+=max(0,d);
    }
  }
  cout<<c/3;
}