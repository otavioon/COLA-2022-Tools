#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
  int n;
  cin >> n;
  multiset<int> s;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    s.insert(x);
  }

  int result = 0;
  while (!s.empty()) {
    int x = *prev(s.end());
    s.erase(prev(s.end()));

    for (int d = 1; d <= 2 * x; d *= 2) {
      if (d < x) continue;
      int r = d - x;
      auto it = s.find(r);
      if (it == s.end()) {
        continue;
      }
      s.erase(it);
      result++;
      break;
    }
  }

  cout << result << endl;

  return 0;
}
