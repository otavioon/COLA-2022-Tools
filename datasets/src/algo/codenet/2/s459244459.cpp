#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll keta(ll t){
  ll k = 0; 
  while(t > 0){
    t >>= 1;
    k++;
  }
  return k;
}

int main(){
  ll N;  cin >> N;
  multiset<ll> a;
  for(ll i = 0; i < N; i++){
    ll tmp; cin >> tmp;
    a.emplace(tmp);
  }
  ll ans = 0;
  
  while(a.size() > 1){
    auto it = a.end();
    it--;
    a.erase(it);
    ll pr = (1 << keta(*it)) - *it;
    auto pit = a.find(pr);
    if(pit != a.end()){
      ans++;
      a.erase(pit);
    }
  }
  cout << ans;
}