#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  string s;
  ll k;
  cin >> s >> k;
  ll n = s.size();
  ll ans = 0;

  ll top = 0;   // 元の文字列で先頭で同じ文字が連続している数
  ll back = 0;  // 元の文字列で末尾で同じ文字が連続している数

  ll same_char_cnt;
  for (ll i = 0; i < n; i += same_char_cnt) {
    same_char_cnt = 1;
    for (ll j = i + 1; j < n; j++) {
      if (s[i] == s[j])
        same_char_cnt++;
      else
        break;
    }

    if (i == 0) {
      top = same_char_cnt;
      continue;
    }

    if (i + same_char_cnt >= n) {
      back = same_char_cnt;
      continue;
    }

    ans += same_char_cnt / 2;
  }

  ans *= k;

  if (top == n) {
    ans = (n * k) / 2;
  } else {
    if (s[0] == s[n - 1])
      ans += (top + back) / 2 * (k - 1) + top / 2 + back / 2;
    else
      ans += k * (top / 2 + back / 2);
  }

  cout << ans << endl;
  return 0;
}