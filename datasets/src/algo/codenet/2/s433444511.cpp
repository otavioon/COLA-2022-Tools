#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n;
  cin >> n;
  multiset<ll> mst;
  ll res = 0;
  rep(i,n){
    ll x;cin >> x;
    mst.insert(x);
  }
  for(ll i = 32;i > 0;i--){
    ll f = *mst.begin();
    for(auto iter = mst.begin();iter != mst.end();){
      f = *iter;
      auto au = mst.find((1ll << i)-f);
      if(au == mst.end()){
        iter++;
        continue;
      }
      if(au == iter){
        au++;
        if(au == mst.end() || (au != mst.end() && (*au) != (*iter))){
          iter++;
          continue;
        }
      }
      res++;
      mst.erase(iter);
      mst.erase(au);
      iter = mst.lower_bound(f);
    }

  }
  cout << res << endl;
  

  return 0;
}
