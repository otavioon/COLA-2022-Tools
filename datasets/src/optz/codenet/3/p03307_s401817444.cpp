#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n,c=0;
  cin>>n;
  vector<ll> a(n),b(n);
  for(ll i=1;i<=n;i++){
    cin>>a[i-1];
    b[i-1]=a[i-1]-i;
  }
  sort(b.begin(),b.end());
  ll bb;
  if(n%2==1){
    bb=b[n/2];
  }else{
    bb=(b[n/2]+b[n/2-1])/2;
  }
  for(ll i=0;i<n;i++){
    c+=abs(b[i]-bb);
  }
  cout<<c;
}
