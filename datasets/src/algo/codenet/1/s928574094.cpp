#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 30;

int main() {
  bool can = true;
  int a, b, c, x, y;
  cin >> a >> b >> c;
  x = a - b;
  y = b - c;
  for (int i = 0; i < 2; i++) {
    cin >> a >> b >> c;
    if (x != a - b || y != b - c) can = false;
  }
  cout << ((can) ? "Yes" : "No") << endl;
}
