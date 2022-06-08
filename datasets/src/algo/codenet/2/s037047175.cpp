#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n;
cin >> n ;
multiset<ll> s;
ll ma=0;
rep(i, n){
  ll a;
  cin >> a;
  ma=max(ma,a);
  s.insert(a);
}
ll tar=1<<(64-__builtin_clzll(ma)+1);
while(tar!=0){
  auto itr=s.end();
  rep(i,s.size()){
    itr--;
    if(*itr<tar/2)break;
    if(s.find(tar-*itr)!=s.end()){
      ans++;
      s.erase(s.find(tar-*itr));
      itr=s.erase(itr);
    }
  }
  tar/=2;
}

cout << ans << endl;
return 0;
}
