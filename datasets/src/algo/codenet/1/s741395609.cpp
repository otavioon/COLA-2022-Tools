#include<bits/stdc++.h>

using namespace std;

int main() {
  int c[3][3];
  
  for (int i = 0; i < 3; i++) {
    cin >> c[i][0] >> c[i][1] >> c[i][2]; 
  }
  int a1, b1, b2, b3;
  a1 = 0;
  b1 = c[0][0];
  b2 = c[0][1];
  b3 = c[0][2];
  
  int a2 = c[1][0] - b1;
  int a3 = c[2][0] - b1;
  
  if (a2 + b2 == c[1][1] && a2+ b3 == c[1][2] && a3 + b2 == c[2][1] && a3 + b3 == c[2][2]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}