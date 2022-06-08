#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main()
{
  string s; ll k; cin>>s>>k;
  ll n=s.size();
  ll ans=0;
  
  if(n==1){
    ans=k/2;
    cout<<ans<<endl;
    return 0;
  }
  
  ll top=0;
  ll back=0;
  
  ll cnt;
  for(ll i=0;i<n;i+=cnt){
    cnt=1;
    for(ll j=i+1;j<n;j++){
      if(s[i]==s[j]) cnt++;
      else break;
    }
    if(i==0){
        top=cnt;
        continue;
    }
    if(i+cnt>=n){
        back=cnt;
        continue;
    }
    ans+=cnt/2;
  }
  
  ans*=k;
  
  if(top==n){
    ans=(n*k)/2;
  }else{
    if(s[0]==s[n-1]) ans+=(top+back)/2*(k-1)+top/2+back/2;
    else ans+=k*(top/2+back/2);
  }
  
  cout<<ans<<endl;
  return 0;
}