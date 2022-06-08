#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a.at(i);
  }
  ll i,j;
  sort(a.begin(),a.end());
  ll ans=0;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      ll x=a.at(i)+a.at(j);
      ans+=lower_bound(a.begin(),a.end(),x)-a.begin()-j-1;
    }
  }
  cout << ans;
}