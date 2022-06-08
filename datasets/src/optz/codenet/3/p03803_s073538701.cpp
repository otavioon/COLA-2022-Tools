#include<iostream>
using namespace std;

int main() {
  int A, B;
  cin >> A >>B;
  if((A >= 2 && A <= 13) && (B >= 2 && B <= 13)) {
    if (A > B) {
      cout << "Alice" << endl;
    }
    else if (A < B) {
      cout << "Bob" << endl;
    }
    else {
      cout << "Draw" << endl;
    }
  }
  else {
    if (A == 1 && B != 1) {
      cout << "Alice" << endl;
    }
    else if (B == 1 && A != 1) {
      cout << "Bob" << endl;
    }
    else {
      cout << "Draw" << endl;
    }
  }
}
