#include <bits/stdc++.h>

uint64_t pow2(uint64_t x) {
  return static_cast<uint64_t>(1) << x;
}

uint64_t calc(uint64_t x) {
  uint64_t p = std::ceil(std::log2(x + 1));
  return pow2(p);
}

int main() {
  uint64_t n;
  std::cin >> n;
  std::multiset<uint64_t, std::greater<uint64_t>> a;
  for (uint64_t i = 0; i < n; i++) {
    uint64_t t;
    std::cin >> t;
    a.insert(t);
  }

  uint64_t count = 0;

  while (!a.empty()) {
    const auto b = a.begin();
    const auto val = *b;
    const auto pair = calc(val) - val;
    if (val < pair) {
      a.erase(b);
    } else if (val == pair) {
      if (val == *std::next(b)) {
        a.erase(b);
        a.erase(a.begin());
        count++;
      } else {
        a.erase(b);
      }
    } else {
      const auto itr = a.find(pair);
      if (itr != a.end()) {
        a.erase(itr);
        a.erase(a.begin());
        count++;
      } else {
        a.erase(b);
      }
    }
  }

  std::cout << count << std::endl;
  return 0;
}
