#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define rep(i,j,n) for (ll i = j; i < (n); i++)
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) (a<=x&&x<b)
#define out(ans) cout << ans << endl
typedef pair<ll,ll>P;
const ll mod=1e9+7;
const int INF = 1000000;
const double PI=3.14159265359;

int main(){

  ll n,q;cin>>n>>q;

  vector<P>v;
  ll parent[n];CLR(parent,-1);
  vector<P>ab;
  rep(i,0,n-1){
    ll a,b;cin>>a>>b;
    ab.push_back(P(--a,--b));
  }
  sort(ab.begin(),ab.end());

  rep(i,0,ab.size()){
    // ll a,b;cin>>a>>b;
    // --a,--b;
    ll a=ab[i].first,b=ab[i].second;
    if(parent[b]==-1){
      parent[b]=a;
      v.push_back(P(a,b));
    }
    else {
      parent[a]=b;
      v.push_back(P(b,a));
    }
  }
  sort(v.begin(),v.end());

  map<ll,ll>mp;
  rep(i,0,q){
    ll p,x;cin>>p>>x;
    mp[--p]+=x;
  }
  // rep(i,0,v.size()){
  //   out(v[i].first<<":"<<v[i].second);
  // }

  rep(i,0,v.size()){
    mp[v[i].second]+=mp[parent[v[i].second]];
  }
  rep(i,0,n){
    cout<<mp[i]<<" ";
  }
  cout<<endl;

  return 0;
}
