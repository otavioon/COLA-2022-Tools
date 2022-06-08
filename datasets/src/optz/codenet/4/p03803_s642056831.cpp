#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  a++;
  b++;
  a %= 13, b %= 13;
  if (a == b) cout << "Draw" << '\n';
  else if (a > b) cout << "Alice" << '\n';
  else cout << "Bob" << '\n';
}
