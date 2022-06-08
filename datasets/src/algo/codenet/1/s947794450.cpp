#include <iostream>
using namespace std;

int c[3][3];

int main() {
  cin >> c[0][0] >> c[0][1] >> c[0][2];
  int diff = 0;
  bool ans = true;
  for (int i = 1; i <= 2; i++) {
    cin >> c[i][0];
    diff = c[i][0] - c[i-1][0];
    for (int j = 1; j <= 2; j++) {
      cin >> c[i][j];
      if (diff != c[i][j] - c[i-1][j]) {
	ans = false;
      }
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
}