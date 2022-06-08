#include <bits/stdc++.h>
using namespace std;

int main() {
  int c[10], sum = 0;
  for (int i = 0; i < 9; i++) {
    cin >> c[i];
    sum += c[i];
  }

  if (3 * (c[0] + c[4] + c[8]) == sum) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}