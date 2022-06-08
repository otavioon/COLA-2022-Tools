#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i < (n);++i)
using namespace std;
using ll = long long;
ll INF = 1e12;


int main(){
  ll N, A, B;
  cin >> N >> A >> B;
  vector<ll> h(N);
  for(int i=0;i<N;i++) cin >> h[i];
  auto b_s = [&](ll ok, ll ng){
    auto f = [&](ll k){
      ll tmp = 0;
      for(int i=0;i<N;i++){
        ll rem = h[i] - B*k;
        if(rem > 0) tmp += (rem+(A-B-1)) / (A-B);
      }
      return (tmp <= k);
    };

    
      while (abs(ok-ng) > 1)
      {
        /* code */
        ll mid = (ok+ng) /2;
        //真ん中で条件を満たせたらture
        if(f(mid)) ok = mid;
        else ng = mid;
      }
      return ok;
  };
  
  cout << b_s(INF, 0) << endl;
}