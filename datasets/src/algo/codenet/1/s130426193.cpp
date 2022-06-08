// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

/*
 * C[0][0] = A[0] + B[0];
 * C[0][1] = A[0] + B[1];
 * C[0][2] = A[0] + B[2];
 * C[1][0] = A[1] + B[0];
 * C[1][1] = A[1] + B[1];
 * C[1][2] = A[1] + B[2];
 * C[2][0] = A[2] + B[0];
 * C[2][1] = A[2] + B[1];
 * C[2][2] = A[2] + B[2];
 
 * C[0][0] + C[1][1] + C[2][2] == C[0][1] + C[1][2] + C[2][0] == C[0][2] + C[1][0] + C[2][1];
 */
const int n = 3;
int C[n][n];
int main() {
  loop(i,0,n) {
    loop(j,0,n) {
      cin >> C[i][j];
    }
  }
  
  int a = C[0][1] + C[1][2] + C[2][0];
  if (C[0][0] + C[1][1] + C[2][2] == a and a == C[0][2] + C[1][0] + C[2][1]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
