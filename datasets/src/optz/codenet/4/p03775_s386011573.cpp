
// #define int long long
// #define repeat(i, n) for (int i = 0; i < n; ++i)

#include <cmath> // cmath includes sqrt, abs
#include <iostream> // iostream includes cout, endl
#include <string> // string
#include <algorithm> // algorithm includes sort

// #include <bits/stdc++.h>

using namespace std;

int main() {
  bool can = true;
  int num = 0;
  // int sum = 0;
  // string S;
  // int N;
  long long N;

  cin >> N;

  num = 100;
  for (int a = 1; a <= sqrt(N); ++a) {
    if (N % a == 0) {
      // cout << "N: " << N << ", A: " << a << endl;
      num = min(num, (int)log10(N) - (int)log10(a) + 1);
    }
  }

  cout << num << endl;
  
  // cout << sum << endl;
  // if (can) cout << "Yes" << endl;
  // else cout << "No" << endl;
  return 0;
}
