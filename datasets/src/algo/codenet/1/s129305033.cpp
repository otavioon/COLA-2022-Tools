#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int main(){
  ll b1,b2,b3;
  cin>>b1 >>b2 >>b3;
  bool ok = true;
  for(int i=0;i<2;i++){
    ll x,y,z;
    cin>>x >>y >>z;
    ll now=b1-x;
    if(now!=b2-y||now!=b3-z){
      ok = false;
    }
  }
  cout<<(ok?"Yes":"No")<<endl;
  return 0;
}