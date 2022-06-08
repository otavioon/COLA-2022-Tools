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
  string N;
  ll K;
  cin >> N >> K;
  vector<ll> d(K);
  set<ll> s;
  for (int i = 0; i < K; i++) {
    cin >> d[i];
    s.insert(d[i]);
  }
  string ans = "";
  for (int i = 0; i < N.size(); i++) {
    char x = N[i];
    for (char c = x; c <= '9'; c++) {
      if (s.find(c - '0') == s.end()) {
        ans += c;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}