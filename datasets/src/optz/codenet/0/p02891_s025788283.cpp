#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  long long k;
  cin >> s >> k;
  if (s.size() == 1) {
    cout << k / 2 << '\n';
    return 0;
  }

  long long cnt = 0, a, b;
  a = distance(s.begin(), find_if(s.begin(), s.end(),
                                  [&](char c) { return c != s.front(); }));
  b = distance(s.rbegin(), find_if(s.rbegin(), s.rend(),
                                   [&](char c) { return c != s.back(); }));
  a++, b++;

  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == s[i - 1]) {
      cnt++;
      i++;
    }
  }

  long long ans = cnt * k;
  if (s.front() == s.back()) {
    ans -= (a / 2 + b / 2 - (a + b) / 2) * (k - 1);
  }

  cout << ans << '\n';

  return 0;
}
