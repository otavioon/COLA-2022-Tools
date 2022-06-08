#include <bits/stdc++.h>
using namespace std;

int N;
multiset<int> ms;
int ans = 0;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int inp;
    cin >> inp;
    ms.emplace(inp);
  }

  while (!ms.empty()) {
    auto it = ms.end();
    it--;
    int a = *it;
    ms.erase(it);

    int b = 1;
    while (b <= a) {
      b <<= 1;
    }
    b -= a;

    auto jt = ms.find(b);
    if (jt != ms.end()) {
      ans++;
      ms.erase(jt);
    }
  }

  cout << ans << endl;
}