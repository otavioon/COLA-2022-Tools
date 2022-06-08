#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for (int i; i < N; i++) {
    cin >> vec[i];
  }
  int now = 0;
  for (int i; i < N; i++) {
    now = vec[now] - 1;
    if (now == 1) {
      cout << i + 1 << endl;
      exit(0);
    } 
  }
  cout << -1 << endl;
}