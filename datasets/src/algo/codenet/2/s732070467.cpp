#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
  int n;
  cin>>n;
  multiset<ll> s;
  rep(i,n) {
    ll x;
    cin>>x;
    s.insert(x);
  }
  int ans=0;
  while(!s.empty()) {
    auto m = max_element(s.begin(),s.end());
    s.erase(m);
    ll y=1;
    while(y<=*m)y*=2;
    if(s.find(y-*m)!=s.end()) {
      s.erase(s.find(y-*m));
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
