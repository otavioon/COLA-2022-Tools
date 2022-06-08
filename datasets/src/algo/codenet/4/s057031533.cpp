#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  set<int> D;
  for (int i = 0; i < K; i++) {
    int d;
    cin >> d;
    D.insert(d);
  }
  
  for (int i = N; i <= 10 * N; i++) {
    bool B = true;
    int X = i;
    while (X > 0) {
      if (D.count(X % 10)) {
        B = false;
        break;
      }
      X /= 10;
    }
    if (B) {
      cout << i << endl;
      break;
    }
  }
}