#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(i=0;i<n;i++)

int main(){
  ll i,j,k,N,c[3][3];
  rep(i,3){
    rep(j,3){
      cin>>c[i][j];
    }
  }
  set<ll> se;
  rep(i,3){
    rep(j,3){
      if(i==j)continue;
      se.insert(c[0][i]+c[1][j]+c[2][((i+1)^(j+1))-1]);
    }
  }
  if(se.size()==1){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}