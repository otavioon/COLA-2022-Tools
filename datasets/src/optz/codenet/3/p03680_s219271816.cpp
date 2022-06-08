#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define REP(X, Y, Z) for (ll(X) = (Y); (X) < (Z); (X)++)

using namespace std;
using ll = long long;
using dll = deque<ll>;
using pll = pair<ll, ll>;
using qll = queue<ll>;
using usll = unordered_set<ll>;
using umll = unordered_map<ll, ll>;
using sll = stack<int>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll kMod = 1e9 + 7;

ll gcd(ll a, ll b) {
  if (a < b) {
    return gcd(b, a);
  }
  ll c = a % b;
  while (c != 0) {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

void init() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}

int main() {
  init();

  ll N;
  cin >> N;
  vll A(N);
  REP(i, 0, N) {
    ll a;
    cin >> a;
    A[i] = a;
  }

  usll S;
  ll now_i = 0;
  ll count = 0;
  for (;;) {
    if (now_i == 1) {
      cout << count << endl;
      return 0;
    }

    if (S.find(A[now_i] - 1) != S.end()) {
      cout << -1 << endl;
      return 0;
    }

    count++;
    now_i = A[now_i] - 1;
    S.emplace(now_i);
  }

  return 0;
}
