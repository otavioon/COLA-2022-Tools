#include<bits/stdc++.h>
using namespace std;

int main (void) {
  int n;
  cin >> n;
  
  for (int i = 2; i <= 1e9; i++) {
    if (!i % 2) continue;
    if (i % n) {
      cout << i << endl;
      return 0;
    }
  }
}