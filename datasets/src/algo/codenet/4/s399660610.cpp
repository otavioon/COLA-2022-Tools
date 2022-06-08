#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_K = (int)(1e1 + 5);

int n, k;
set<int> dset;

int ans = 0;

int main(void) {
  // Here your code !
  scanf("%d %d", &n, &k);

  for (int i = 0; i < k; ++i) {
    int tmp;
    scanf("%d", &tmp);
    dset.insert(tmp);
  }

  for (int i = n; i < 100 * n; ++i) {
    bool flg = false;
    string str_i = to_string(i);

    for (auto c: str_i) {
      int num = c - '0';
      if (dset.find(num) != dset.end()) {
        flg = true;
        break;
      }
    }

    if (flg) continue;

    ans = i;
    break;
  }

  printf("%d\n", ans);

  return 0;
}
