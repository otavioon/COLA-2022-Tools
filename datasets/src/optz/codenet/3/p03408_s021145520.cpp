#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
 int n,m;
  cin>>n;
  vector<string> s(n);
  rep(i,0,n) cin>>s[i];
  cin>>m;
  vector<string> t(m);
  rep(i,0,m) cin>>t[i];
  ///////////
  int ans=0;
  rep(i,0,n){
    int count=0;
    rep(j,0,n){
      if(s[j]==s[i]) count++; 
    }
    rep(j,0,m){
      if(t[j]==s[i]) count--; 
    }
    ans=max(ans,count);
  }
  cout<<ans<<endl;
}