#include<bits/stdc++.h>
using namespace std;

int main() {
  int N, A[101], b = 0, s = 100000000;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (b < A[i]) {
      if(s > b && i == 0) s = A[i];
      else if (s > b) s = b;
      b = A[i];
    }
    else if (s > A[i]) s = A[i];
  }
  if (s == 100000000) s = 0;
  cout << b - s;
}