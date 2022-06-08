#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
    a.at(i)--;
  }

  int i = 0, ans = 0;
  vector<bool> b(N, false);
  while (true) {
    ans++;
    b.at(i) = true;
    i = a.at(i);
    if (i == 1) {
      cout << ans << endl;
      return 0;
    }
    if (b.at(i)) {
      cout << -1 << endl;
      return 0;
    }
  }
}