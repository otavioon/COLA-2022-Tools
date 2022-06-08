#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  long long k;
  cin >> s >> k;
  if (s.size() == 1) {
    cout << k / 2 << '\n';
    return 0;
  }

  long long ans = 0, a, b;
  a = distance(s.begin(), find_if(s.begin(), s.end(),
                                  [&](char c) { return c != s.front(); }));
  b = distance(s.rbegin(), find_if(s.rbegin(), s.rend(),
                                   [&](char c) { return c != s.back(); }));

  int cur = 0;
  while (cur < s.size()) {
    int cnt = 1;
    while (cur + cnt < s.size() && s[cur] == s[cur + cnt]) {
      cnt++;
    }

    ans += cnt / 2;
    cur += cnt;
  }

  ans *= k;
  if (s.front() == s.back()) {
    ans -= (a / 2 + b / 2 - (a + b) / 2) * (k - 1);
  }

  cout << ans << '\n';

  return 0;
}
