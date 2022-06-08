//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  string s;cin>>s;
  ll k;cin>>k;
  ll ans=0;
  ll part=1;
  for(ll i=1;i<s.size();i++){
    if(s[i]==s[i-1]){
      part++;
      if(i==s.size()-1){
        ans+=part/2;
      }
    }
    else {
      ans+=part/2;
      part=1;
    }
  }
  ans*=k;
  ll a=1;
  for(ll i=1;i<s.size();i++){
    if(s[i]==s[i-1])a++;
    else break;
  }
  reverse(s.begin(),s.end());
  ll b=1;
  for(ll i=1;i<s.size();i++){
    if(s[i]==s[i-1])b++;
    else break;
  }
  //cout<<ans<<endl;
  if(s[0]==s[s.size()-1]){
    ans-=(a/2+b/2-(a+b)/2)*(k-1);
  }
  cout<<ans<<endl;
}
  