#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<ll>vec(a);
  vector<ll>veco(a);
  vector<ll>vec2(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
  }
  vec2=vec;
  sort(vec.begin(),vec.end());
  for(ll i=0;i<a;i++){
    veco.at(i)=min(vec.at(i),vec2.at(i));
  }
  ll c=veco.at(0);
  for(ll i=0;i<a;i++){
    c+=veco.at(i);
  }
  cout<<c<<endl;
}
    
