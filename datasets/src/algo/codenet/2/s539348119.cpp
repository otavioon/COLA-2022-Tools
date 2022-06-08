#include <bits/stdc++.h>
int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  size_t n; std::cin >> n;
  std::multiset<int, std::greater<int>> set;
  for (size_t i = 0; i < n; i++) {
    int x; std::cin >> x;
    set.insert(x);
  }
  int ret = 0;
  while (!set.empty()) {
    int x = *set.begin(); set.erase(set.begin());
    int y = std::pow(2, (int)std::log2(x) + 1) - x;
    auto it = set.find(y);
    if (it != set.end()) {
      ret++;
      set.erase(it);
    }
  }
  std::cout << ret << std::endl;
  return 0;
}