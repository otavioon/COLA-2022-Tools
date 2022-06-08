#include <iostream>
using namespace std;

int main(void) {
  int sum = 0, ldiag = 0, rdiag = 0, val;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> val;
      sum += val;
      if (i + j == 2) rdiag += val;
      if (i == j) ldiag += val;
    }
  }

  if (ldiag == rdiag && sum % 3 == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}