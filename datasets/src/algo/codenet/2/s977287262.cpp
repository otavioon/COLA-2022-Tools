#include <algorithm>
#include <cstdio>
#include <set>

const int N = 200050;

int n;
std::multiset<int> S;

int main() {
  scanf("%d", &n);
  for (int i = 0, x; i < n; ++i) {
    scanf("%d", &x);
    S.insert(x);
  }
  int ans = 0;
  while (!S.empty()) {
    std::multiset<int>::iterator it = --S.end();
    int x = *it; S.erase(it);
    int k = 1;
    while (x >= k) k <<= 1;
    it = S.find(k - x);
    if (it != S.end()) ++ans, S.erase(it);
  }
  printf("%d\n", ans);
}