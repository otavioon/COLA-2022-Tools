#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

bool ok(int i, set<int> s) {
  while (i > 0) {
    int n = i % 10;
    i /= 10;
    if (s.find(n) != s.end())
      return false;
  }
  return true;
}

int main() {
  int N, K;
  cin >> N >> K;

  set<int> D;
  rep(i, K) {
    int d;
    cin >> d;
    D.insert(d);
  }

  int i = N;
  while (true) {
    if (ok(i, D)) {
      cout << i << endl;
      return 0;
    }
    i++;
  }
}