#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;

int main() {
  string s;
  ll k;
  cin >> s >> k;
  ll n = s.size();
  ll l = 0;
  ll r = 0;
  char c = s[0];
  ll lid = 0;
  ll rid = 0;
  rep(i, n) {
    if (s[i] == c) l++;
    else {
      lid = i;
      break;
    }
  }
  c = s[n-1];
  repr(i, n-1) {
    if (s[i] == c) r++;
    else {
      rid = i+1;
      break;
    }
  }
  ll sum = l+r;
  if (sum > n) {
    sum /= 2;
    sum *= k;
    cout << sum/2 << endl;
    return 0;
  }
  sum /= 2;
  ll cnt = 0;
  ll ans = 0;
  if (s[0] != s[n-1]) {
    sum = 0;
    ans += l/2 + r/2;
  }
  s += 'A';
  c = s[lid];
  FOR(i, lid, rid) {
    if (s[i] == c) cnt++;
    else {
      c = s[i];
      ans += cnt / 2;
      cnt = 1;
    }
  }
  if (!sum) cout << ans*k << endl;
  else {
    sum *= k-1;
    ans += sum;
    ans += l/2 + r/2;
    cout << ans << endl;
  }
  

  
  return 0;
}