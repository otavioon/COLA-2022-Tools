#include <bits/stdc++.h>

#define REP(i,a,b) for(int i=a;i<(b);i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

int main() {
  int N, K; cin >> N >> K;
  set<int> st;
  rep(i, K) { int x; cin >> x; st.insert(x); }
  for (int n = N; ; n++) {
    string s = std::to_string(n);
    int sz = s.size();
    bool flag = 1;
    rep(i, sz) {
      if (st.count(s[i] - '0')) { flag = 0; break; }
    }
    if (flag) {
      cout << n << "\n";
      exit(0);
    }
  }
}
