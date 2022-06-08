#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef long  l;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
const int INF=1000000001;
const double PI=3.141592653589;
const ll mod=1000000007;

int main(){
  int n; cin>>n;
  ll ans=0;

  vector<ll> a(n);
  vector<ll> b(n);
  vector<ll> c(n);

  rep(i,n) cin>>a[i];
  rep(i,n) cin>>b[i];
  rep(i,n) cin>>c[i];

  rep(i,n){
    auto itra=lower_bound(ALL(a),b[i]);
    auto itrc=upper_bound(ALL(c),b[i]);
    ans+=(itra-a.begin())*(c.end()-itrc);
  }
  cout<<ans<<endl;
  return 0;
}
