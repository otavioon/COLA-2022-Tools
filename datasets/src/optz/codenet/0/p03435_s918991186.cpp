#include <bits/stdc++.h>

// main.cpp

constexpr bool equals(const std::int_fast64_t x, const std::int_fast64_t y, const std::int_fast64_t z) {
  return x == y && y == z;
}

int main() {
  std::array<std::array<std::int_fast64_t, 3>, 3> c;
  for (std::array<std::int_fast64_t, 3>& c_i : c) {
    std::copy_n(std::istream_iterator<std::int_fast64_t>(std::cin), 3, c_i.begin());
  }

  std::cout << (equals(c[0][0] - c[1][0], c[0][1] - c[1][1], c[0][2] - c[1][2]) && equals(c[1][0] - c[2][0], c[1][1] - c[2][1], c[1][2] - c[2][2]) && equals(c[2][0] - c[0][0], c[2][1] - c[0][1], c[2][2] - c[0][2]) ? "Yes" : "No") << std::endl;
  return 0;
}