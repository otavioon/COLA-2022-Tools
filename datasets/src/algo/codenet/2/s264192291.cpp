#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){

  int n; cin >> n;
  multimap<int,int> mp;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    mp.insert({a,1});
  }

  // mp.eraseの方でもやりたみ
  int ans = 0;
  for(; !mp.empty();){
    auto p = mp.end();
    p--;
    int t = 1;
    while(p->first > t) t *= 2;
    mp.erase(p);
    if(mp.find(t-p->first) != mp.end()){
      mp.erase(mp.find(t-p->first));
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
