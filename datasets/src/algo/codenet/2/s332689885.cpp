#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n;
multiset<int> ms;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    ms.insert(x);
  }
  int ans = 0;
  while (!ms.empty()) {
    int largest = *prev(ms.end());
    ms.erase(prev(ms.end()));
    int k;
    for (int i = 0; i < 31; ++i) {
      if ((1 << i) > largest) {
        k = (1 << i) - largest;
        break;
      }
    }
    auto p = ms.lower_bound(k);
    if (p != ms.end() && *p == k) {
      ms.erase(p);
      ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}