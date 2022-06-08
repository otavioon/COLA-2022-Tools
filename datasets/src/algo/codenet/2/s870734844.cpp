#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

multiset<int> m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    m.insert(t);
  }

  int ans = 0;
  while (m.size() >= 2) {
    auto it = prev(m.end());
    int bk = *it;
    m.erase(it);
    for (int j = 30; j >= 0; j--) {
      int pk = 1 << j;
      if (pk > bk && pk - bk <= bk) {
        auto it2 = m.find(pk - bk);
        if (it2 != m.end()) {
          ans++;
          m.erase(it2);
        }
      }
    }
  }

  cout << ans << endl;
}