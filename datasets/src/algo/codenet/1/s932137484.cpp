#include <bits/stdc++.h>
using namespace std;

int main() {
  int x = 0;
  for (int i = 0; i < 9; i++) {
    int s;
    cin >> s;
    x += s;
  }
  if (x % 3 == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}