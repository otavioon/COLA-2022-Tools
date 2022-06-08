#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, A;
  cin >> N;
  vector<string> cards(100 + 10);
  for (int i = 0; i < N; i++) cin >> cards.at(i);
  
  cin >> M;
  for (int i = N; i < N + M; i++) cin >> cards.at(i);
  
  vector<int> point(N + M);
  
  for (int i = 0; i < N + M; i++) {
    for (int j = 0; j < N + M; j++) {
        if (cards.at(i) == cards.at(j)) {
          if (j < N) point.at(i)++;
          else point.at(i)--;
        }
    }
  }
    
  for (int i = 0; i < N + M; i++) {
    for (int j = 0; j < N + M; j++) {
      if (point.at(j) == i + 1) A = i + 1;
    }
  }
  
  if (A <= 0) A = 0;
  
  cout << A << endl;
}