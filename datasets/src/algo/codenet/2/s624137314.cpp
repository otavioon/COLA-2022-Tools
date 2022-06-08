#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
using ll = long long;

int main() {
  ll n, a;
  cin >> n;
  multiset<ll, greater<>> st;
  rep(i, n) {
    cin >> a;
    st.insert(a);
  }
  ll ans = 0;
  while(!st.empty()) {
    auto it = st.begin();
    st.erase(it);
    ll p = 2;
    while(p <= *it) {
      p *= 2;
    }
    auto jt = st.find(p - *it);
    if(jt == st.end()) continue;
    st.erase(jt);
    ans++;
  }
  cout << ans << endl;
}