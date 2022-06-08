#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

const long long MOD = 1000000007;
vector<set<int>> pr(2*1e5);
vector<set<int>> tre(2*1e5);

void tr(int x,int y){
  //cout << x << y<< endl;
  if(x!=0 && y!=0){
    for(auto i:pr.at(y)){
      pr.at(x).insert(i);
    }
  }
  if(x!=0) pr.at(x).insert(y);
  for(auto i:tre.at(x)){
    if(i!=y) tr(i,x);
  }
  
  return;
}
  

int main(){
  int n,q,a,b;
  cin >> n >> q;
  vector<ll> pt(n);
  rep(i,n-1){
    cin >> a >> b;
    a--;b--;
    tre.at(a).insert(b);
    tre.at(b).insert(a);
  }
  tr(0,0);
  ll p;
  rep(i,q){
    cin >> a >> p;
    a--;
    pt.at(a) += p;
  }
  ll ans;
  rep(i,n){
    ans=pt.at(i);
    for(auto j:pr.at(i)) ans += pt.at(j);
    cout << ans << " ";
  }
  cout << endl;
  
}
