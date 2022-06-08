#include <iostream>
#include <vector>
#include <set>

int solve_D() {
  size_t N;
  std::cin >> N;

  std::vector<uint32_t> lines(N);
  for (auto line : lines) {
    uint32_t L;
    std::cin >> L;
    line = L * L;
  }

  // 1. 全探索：O(N^3)
  auto solver1 = [&]() -> size_t {
    struct Triangle {
      Triangle(uint32_t x, uint32_t y, uint32_t z) noexcept {
        if (x > y) std::swap(x, y);
        if (x > z) std::swap(x, z);
        if (y > z) std::swap(y, z);
        a = x;
        b = y;
        c = z;
      }

      bool operator<(const Triangle& other) const noexcept {
        if (a < other.a) return true;
        if (a > other.a) return false;
        if (b < other.b) return true;
        if (b > other.b) return false;
        return c < other.c;
      }

      uint32_t a, b, c;
    };
    std::set<Triangle> set;
    for (size_t i = 0; i < lines.size() - 2; ++i) {
      const auto a = lines[i];
      for (size_t j = i + 1; j < lines.size() - 1; ++j) {
        const auto b = lines[j];
        for (size_t k = j + 1; k < lines.size(); ++k) {
          const auto c = lines[k];
          if (a == b * c) set.emplace(a, b, c);
        }
      }
    }
    return set.size();
  };

  std::cout << solver1();

  return 0;
}

int main() {
  return solve_D();
}
