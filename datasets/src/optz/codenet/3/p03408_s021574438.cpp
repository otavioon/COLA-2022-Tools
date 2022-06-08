#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int b, N, M;
  cin >> N;
  vector<string> v(N);
  for (int i = 0; i < N; i++) cin >> v.at(i);
  cin >> M;
  vector<string> w(M);
  for (int i = 0; i < M; i++) cin >> w.at(i);
  
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (v.at(i) == v.at(j)) a.at(i)++;
    }
    for (int j = 0; j < M; j++) {
      if (v.at(i) == w.at(j)) a.at(i)--;
    }
  }
  
  b = a.at(0);
  for (int i = 1; i < N; i++) {
    if (b < a.at(i)) b = a.at(i);
  }
  if (b < 0) b = 0;
  cout << b << endl;
}