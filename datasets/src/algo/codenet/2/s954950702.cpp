#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

template <class T>
void cout_vec2(const vector<vector<T>> &vec){
  rep(i,vec.size()){
    rep(j,vec[i].size()){
      cout<<vec[i][j]<<' ';
    }
    cout<<endl;
  }
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin>>n;
  multiset<ll> a;
  rep(i,n){
    ll x;
    cin>>x;
    a.insert(x);
  }
  ll ans=0;
  while(!a.empty()){
    auto itr=a.end();
    itr--;
    ll now=*itr;
    a.erase(itr);
    ll tar=1;
    while(tar<=now) tar*=2;
    auto ser=a.lower_bound(tar-now);
    if(ser!=a.end() && *ser==tar-now){
      ans++;
      a.erase(ser);
    }
  }
  cout<<ans<<endl;
}