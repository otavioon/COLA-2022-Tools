#include <bits/stdc++.h>

using namespace std;

int k;
string s, s2;

int main() {
  cin >> s >> k;
  bool all_equal = true;
  for (int i = 1; i < s.size() && all_equal; i++) {
    if (s[i] != s[0])
      all_equal = false;
  }
  if (all_equal) {
    cout << ((long long) s.size() * (long long) k / 2) << endl;
  } else {
    s2 = "" + s;
    long long res = 0;
    char last_char = '0';
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == last_char) {
        s[i] = '0';
        res++;
      }
      last_char = s[i];
    }
    s2 = last_char + s2;
    long long res2 = 0;
    last_char = '1';
    for (int i = 0; i < s2.size(); i++) {
      if (s2[i] == last_char) {
        s2[i] = '0';
        res2++;
      }
      last_char = s2[i];
    }
    res += res2 * (k - 1);
    cout << res << endl;
  }
  return 0;
}