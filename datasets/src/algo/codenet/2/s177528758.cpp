#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  multiset<int> st;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    st.insert(a);
  }
  int ans = 0;
  while (st.size()) {
    int cur = *prev(st.end());
    st.erase(prev(st.end()));
    for (int i = 0; i < 31; i++) {
      int t = (1 << i) - cur;
      if (t <= 0) continue;
      if (st.find(t) == st.end()) continue;
      ans++;
      st.erase(st.find(t));
    }
  }
  cout << ans << endl;
  return 0;
}