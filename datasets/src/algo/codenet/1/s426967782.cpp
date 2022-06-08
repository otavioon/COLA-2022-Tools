#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
  int A[3][3];
  rep(i,9) cin >> A[i/3][i%3];
  int b0 = A[0][0];
  int b1 = A[0][1];
  int b2 = A[0][2];
  int a1 = A[1][0] - b0;
  int a2 = A[2][0] - b0;
  if (A[1][1] == a1 + b1 &&
      A[1][2] == a1 + b2 &&
      A[2][1] == a2 + b1 &&
      A[2][2] == a2 + b2) {
        cout << "Yes" << endl;
      }  else {
        cout << "No" << endl;
      }
}