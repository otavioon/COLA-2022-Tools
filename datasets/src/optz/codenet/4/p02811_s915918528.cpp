#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll lcm(ll x,ll y){
    return (x*1LL*y)/(__gcd(x,y));
}
int main (){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);

  ll n,m;cin>>n>>m;
  ll A[n+5],g;
  for(int i=1;i<=n;i++)cin>>A[i];
  g = A[1];
  for(int i=2;i<=n;i++)g = __gcd(g , A[i]);

  set<int> S;
  for(int i=1;i<=n;i++)S.insert(A[i]/g);
  vector<ll>Aa;
  for(auto x:S)Aa.push_back(x);
  ll lc = Aa[0];
  for(int i=1;i<Aa.size();i++)lc = lcm(lc , Aa[i]);
  ll res = m/lc;
  cout<<res/2 + res%2<<endl;
  return 0;
}


