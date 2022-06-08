#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
using ll = long long;

int main() {
  ll n, a;
  cin >> n;
  multiset<ll> st;
  rep(i, n) {
    cin >> a;
    st.insert(a);
  }
  ll ans = 0;
  ll p2 = pow(2, 34);
  while(!st.empty()) {
    auto it = st.end();
    st.erase(--it);
    ll p = p2;
    while(p > *it) {
      p /= 2;
      auto jt = st.find(p - *it);
      if(jt == st.end()) continue;
      st.erase(jt);
      ans++;
      break;
    }
  }
  cout << ans << endl;
}