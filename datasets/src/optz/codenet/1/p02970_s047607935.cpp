#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,a;
  cin >> n >> a;
  int b = 2*a+1;
  int v = 0;
  for (int i=0; i<n; i++) {
    v++;
    if (b >= n) {
      break;
    }
    b *= 2;
  }
  cout << v << endl;
}