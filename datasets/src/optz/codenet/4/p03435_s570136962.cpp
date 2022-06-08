#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int m[3][3];
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      cin >> m[i][j];
    }
  }
  int a[3] = {0};
  int b[3] = {0};
  a[0] = 0;
  b[0] = m[0][0] - a[0];
  b[1] = m[0][1] - a[0];
  b[2] = m[0][2] - a[0];
  a[1] = m[1][0] - b[0];
  a[2] = m[2][0] - b[0];

  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      if (a[i] + b[j] != m[i][j]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
