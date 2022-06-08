#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll N; cin>>N;
  vector<ll> hen(1000,0);
  rep(i,N)
  {
    ll L; cin>>L;
    hen.at(L-1)++;
  }
  
  
  ll ans=0;
  
  ll count=0;
  for(ll i=1;i<1000;i++)
  {
    for(ll j=i+1;j<min(2*i,(ll)1000);j++)
    {
      count+=hen.at(j-1);
    }
    for(ll j=i+1;j<1000;j++)
    {
      count-=hen.at(j-1);
      if(i+j<=1000) {count+=hen.at(i+j-1-1);}
      ans+=hen.at(i-1)*hen.at(j-1)*count;
    }
  }
  
  count=0;
  for(ll i=1;i<1000;i++)
  {
    for(ll j=i+1;j<=min(2*i-1,(ll)1000);j++)
    {
      ans+=hen.at(i-1)*(hen.at(i-1)-1)/2*hen.at(j-1);
    }
  }
  
  rep(i,N)
  {
    if(hen.at(i)>=3) {ans+=hen.at(i)*(hen.at(i)-1)*(hen.at(i)-2)/(2*3);}
  }
  
  cout<<ans<<endl;
  return 0;
}
