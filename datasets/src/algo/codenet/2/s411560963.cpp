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
  multiset<int> mst;
  int res = 0;
  rep(i,n){
    int x;cin >> x;
    mst.insert(x);
  }
  for(int i = 32;i > 0;i--){
    int f = *mst.begin();
    for(auto iter = mst.begin();iter != mst.end();iter++){
      f = *iter;
      auto au = mst.find((1 << i)-f);
      if(au == iter || au == mst.end())continue;
      res++;
      mst.erase(iter);
      mst.erase(au);
      iter = mst.lower_bound(f);
    }
  }
  cout << res << endl;


  return 0;
}
