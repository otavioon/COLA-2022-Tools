#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n, m;
  cin >> n;
  map<string,int> mp;
  rep(i,n) {
    string s;
    cin >> s;
    mp[s]++;
  }
  cin >> m;
  rep(i,m) {
    string t;
    cin >> t;
    mp[t]--;
  }
  int ans = 0;
  for(auto x : mp) ans = max(ans,x.second);
  cout << ans << endl;
  return 0;
}