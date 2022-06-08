#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N;
  ll K;
  cin >> N >> K;
  vector<ll> d(K);
  set<ll> s;
  for (int i = 0; i < K; i++) {
    cin >> d[i];
    s.insert(d[i]);
  }
  for (int i = N; i < 100000; i++) {
    int x = i;
    bool flag = true;
    while (x > 0) {
      if (s.count(x % 10)) {
        flag = false;
        break;
      }
      x /= 10;
    }
    if (flag) {
      cout << i << endl;
      break;
    }
  }
}