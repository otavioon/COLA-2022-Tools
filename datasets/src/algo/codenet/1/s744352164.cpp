#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  int c[9];
  FOR(i, 0, 9) cin >> c[i];
  int a21, a31 ,b21, b31; //a2-a1みたいな感じ
  a21 = c[1]-c[0];
  a31 = c[2]-c[0];
  b21 = c[3]-c[0];
  b31 = c[6]-c[0];

  if (c[4] == (a21 + b21 + c[0])) {
    if (c[5] == (a31 + b21 + c[0])) {
      if (c[7] == (a21 + b31 + c[0])) {
        if (c[8] == (a31 + b31 + c[0])) {
          cout << "Yes" <<endl;
          return 0;
          
        }
      }
    }
  }
  
  cout << "No" << endl;
  return 0;
}


