#include <algorithm>
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define REP(i,num,n) for(ll i=num, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define len(x) ((ll)(x).size())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
typedef long long ll;
ll INF = 1e18;
using namespace std;

int main(){
  cout<<fixed<<setprecision(10);

  ll N;
  cin >> N;

  vector<ll> L(N);
  rep(i,N) cin >> L[i];
  
  ll ans = 0;

  for(ll i=0;i<N-1;++i){
    for(ll j=i+1; j<N; ++j){
      ll a = L[i];
      ll b = L[j];
      ll t1 = upper_bound(L.begin(),L.end(),a+b-1)-L.begin();
      ll t2 = upper_bound(L.begin(),L.end(),a-b)-L.begin();
      ll t3 = upper_bound(L.begin(),L.end(),b-a)-L.begin();
      
      ll t4 = max(t2,t3);
      
      if (t1!=t4)
          ans += t1-t4+1;
          
      if (t4<=i<=t1)
          ans -= 1;
      if (t4<=j<=t1)
          ans -= 1;
      
    }
  }
  
  ans = ans/3;
  cout << ans << endl;

  return 0;
}
