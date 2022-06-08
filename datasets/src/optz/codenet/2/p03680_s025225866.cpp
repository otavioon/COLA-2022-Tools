#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a;
  for (int i=0; i<n; i++) {
    int tmp;
    cin >> tmp;
    tmp--;
    a.push_back(tmp);
  }

  int now = 0, cnt = 0;
  for (;;) {
    if (now == 1) {
      printf("%d\n", cnt);
      break;
    }
    if (cnt >= n) {
      printf("-1\n");
      break;
    }
    cnt++;
    now = a[now];
  }

  return 0;
}
