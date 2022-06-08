#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int c[3][3];
  for (int i = 0; i < 9; i++) {
    cin >> c[i / 3][i % 3];
  }

  int b2 = c[0][1] - c[0][0];
  int b3 = c[0][2] - c[0][0];
  for (int i = 1; i < 3; i++) {
    if (b2 != (c[i][1] - c[i][0]) || b3 != (c[i][2] - c[i][0])) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
