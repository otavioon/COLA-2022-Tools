#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  ll n;cin>>n;
  multiset<ll> a;
  rep(i, n){
    ll t; cin>>t;
    a.insert(t);
  }

  int result=0;
  while(a.size()){
    auto cit = a.end();
    cit--;
    ll c = *cit;
    a.erase(cit);
    rrep1(i, 31){
      ll t = pow(2LL, i)-c;
      if(t<=0)break;
      if(t>c)continue;

      auto it = a.find(t);
      if(it==a.end())continue;

      result++;
      a.erase(it);
      break;
    }
  }
  
  cout<<result<<endl;

  return 0;
}
