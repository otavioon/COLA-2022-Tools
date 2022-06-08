#include <bits/stdc++.h>
using namespace std;

int main() {
  int c1[3], c2[3], c3[3], d1, d2;
  bool p = false;
  cin >> c1[0] >> c2[0] >> c3[0];
  d1 = c1[0] - c2[0]; //b1 - b2
  d2 = c2[0] - c3[0]; //b2 - b3
  for(int i = 1; i < 3; i++){
    cin >> c1[i] >> c2[i] >> c3[i];
    if(d1 != c1[i] - c2[i] || d2 != c2[i] - c3[i]) p = true;
  }
  if(p) cout << "No" << endl;
  else cout << "Yes" << endl;
}