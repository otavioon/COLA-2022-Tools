#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  int N,K;
  cin>>N>>K;
  vector<ll> A(N);
  for(int i(0);i<N;i++){
    cin>>A[i];
  }
  if(K==0){
    ll ans(0);
    for(int i(0);i<N;i++){
      ans = max(ans,A[i]);
    }
    cout << ans << endl;
    return 0;
  }
  ll l = 0,r = 1e9+1;
  while(r-l>1){
    ll x = (l+r)/2;
    //ccout << x << endl;
    //cout << l << " " << r << endl;
    bool ok = [&]{
      // ll nedan = A*x + B*int(to_string(x).size());
      // if (nedan <= X) return true;
      // else return false;
      ll cnt(0);
      for(int i(0);i<N;i++){
        if(A[i]%x == 0) cnt += A[i]/x-1;
        else cnt += A[i]/x;
      }
      if(cnt > K) return true;
      else return false;
    }();
    if (ok) l = x;
    else r = x;
  }
  int cnt(0);
  if(l == 0){
    cout << 1 << endl;
    return 0;
  }
  for(int i(0);i<N;i++){
    if(A[i]%l==0) cnt+=A[i]/l-1;
    else cnt+=A[i]/l;
  }
  if(cnt <= K) cout << l << endl;
  else cout << r << endl;
  return 0;
}

