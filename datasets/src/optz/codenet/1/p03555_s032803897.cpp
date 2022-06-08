#include <bits/stdc++.h>

using namespace std;

string inv (string a) {
  string r = "";
  for (int i = 2; i > 0 - 1; --i) r += a[i];
  return r;
}

int main () {
  string a, b;
  cin >> a >> b;
  if (a[0] == b[2] && b[0] == a[2]) cout << "YES";
  else cout << "NO";
  return 0;
}