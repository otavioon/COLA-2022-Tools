#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;
ll gcd(ll x, ll y){
  if(y==0) return x;
  else return gcd(y, x%y);
}
ll lcm(ll x,ll y){
  ll g=gcd(x,y);
  return x/g*y;
}

int main(){
  int fig[3][3];
  rep(i,3){
    rep(j,3){
      cin >> fig[i][j];
    }
  }
  bool ok=true;
  rep(i,2){
    if(fig[2][i]-fig[1][i]!=fig[2][i+1]-fig[1][i+1]) ok=false;
  }
  rep(i,2){
    if(fig[1][i]-fig[0][i]!=fig[1][i+1]-fig[0][i+1]) ok=false;
  }
  rep(i,2){
    if(fig[i][2]-fig[i][1]!=fig[i+1][2]-fig[i+1][1]) ok=false;
  }
  rep(i,2){
    if(fig[i][1]-fig[i][0]!=fig[i+1][1]-fig[i+1][0]) ok=false;
  }
  if(ok) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
}
