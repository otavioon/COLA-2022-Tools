#include <cstdio>
#include <algorithm>
#include <set>


int main() {
  std::multiset<int> set;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    int x;
    scanf("%d", &x);
    set.emplace(x);
  }
  int result = 0;
  while (set.size() >= 2) {
    int x = *set.rbegin();
    set.erase(--set.end());
    int b = 1;
    while (b <= x) b <<= 1;
    int y = b - x;
    auto it = set.find(y);
    if (it != set.end())
      set.erase(it), ++ result;
  }
  printf("%d\n", result);
}
