#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <algorithm>
#include <map>
#include <sstream>
#include <unordered_map>
#include <set>

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
static ull tenq = 1000000000;
static ull mod = tenq + 7;

using namespace std;

int main()
{
  ll N, K, x;
  cin >> N >> K;
  set<ll> s;
  for (auto i = 0; i < 10; i++) s.insert(i);
  for (auto i = 0; i < K; i++) {
    cin >> x;
    s.erase(x);
  }

  while (true) {
    x = N;
    ll digit = 1;
    while (x > 0) {
//      cout << "N=" << N << " x=" << x << " digit=" << digit << endl;
      if (s.find(x % 10) == s.end()) {
        N = (x+1) * digit;
        break;
      }
      digit *= 10;
      x /= 10;
    }
    if (x == 0) break;
  }

  cout << N << endl;

  return 0;
}
