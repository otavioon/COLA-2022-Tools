#include <iostream>
#include <set>

int main() {
  size_t N;

  std::cin >> N;

  std::multiset<size_t> A;

  for (size_t i=0; i<N; i++) {
    size_t a;
    std::cin >> a;
    A.insert(a);
  }

  size_t ans=0;

  while (A.size() > 1) {
    auto const max = *std::prev(A.end());
    A.erase(std::prev(A.end()));

    for (size_t sum=0x80000000; sum>1; sum>>=1) {
      if (max >= sum) break;

      auto it_tgt = A.lower_bound(sum - max);

      if (it_tgt == A.end()) continue;

      std::cerr << sum << ' '
                << max << ' '
                << *it_tgt << std::endl;

      if (*it_tgt + max == sum) {
        ans++;
        A.erase(it_tgt);
      }
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
