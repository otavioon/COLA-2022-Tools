#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int n, k;
  cin >> n >> k;
  set<char> d;
  for (int c = '0'; c <= '9'; c++) d.insert(c);
  rep(i, k) {
    char tmp;
    cin >> tmp;
    d.erase(tmp);
  }

  auto is_ok = [&](int n) {
    string s = to_string(n);
    int l = s.length();
    bool ret = true;
    rep(i, l) {
      if (d.count(s[i]) == 0) ret = false;
    }
    return ret;
  };

  int ans = n;
  while (true) {
    if (is_ok(ans)) break;
    ans++;
  }
  cout << ans << endl;
}
