#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll n;
  cin >> n;
  vec a(n);
  for(ll i=0;i<n;i++) cin >> a[i];
  set<ll> al;
  sort(a.rbegin(),a.rend());
  ll ans=0;
  for(ll i=0;i<n;i++) {
    if(al.count(i)) continue;
    ll beki=2;
    while(beki<a[i]) {
      beki*=2;
    }
    ll l=i+1,r=n;
    ll temp=(l+r)/2;
    while(l+1<r) {
      if(a[temp]<beki-a[i]) {
        r=temp;
      }
      else {
        l=temp;
      }
      temp=(l+r)/2;
    }
    r--;
    while(al.count(r)&&i<r) r--;
    if(r<=i) continue;
    if(a[r]+a[i]==beki) {
      ans++;
      al.insert(i);
      al.insert(r);
    }
  }
  cout << ans << endl;
}