#include <iostream>
#include <string>

using ll_t = long long;

ll_t solve(const std::string &s, int k) {
  ll_t res = 0;
  int len = s.length();
  bool pre_has_changed = false;
  for (int i = 1; i < len; ++i) {
    if (s[i] == s[i - 1] && !pre_has_changed) {
      ++res;
      pre_has_changed = true;
    } else {
      pre_has_changed = false;
    }
    if (i == len - 1 && s[i] == s[0] && !pre_has_changed) ++res;
  }
  return static_cast<ll_t>(res) * k;
}

int main() {
  int k;
  std::string s;
  std::cin >> s >> k;
  std::cout << solve(s, k) << std::endl;
  return 0;
}
