#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  multiset<long long> a;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    a.insert(num);
  }

  int ans = 0;
  while (!a.empty()) {
    long long x = *a.rbegin();
    a.erase(a.find(x));
    long long next_two_power = 1;
    while (next_two_power <= x) {
      next_two_power <<= 1;
    }

    long long target = next_two_power - x;
    auto it = a.find(target);
    if (it != a.end()) {
      a.erase(it);
      ans++;
    }
  }
  cout << ans;
}
