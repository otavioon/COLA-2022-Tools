#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int pos = 1;
  vector<bool> been(N, false);
  been.at(0) = true;
  
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a.at(i);
  
  bool fin = false;
  
  int i = 0;
  
  while (!fin) {
    
    pos = a.at(pos - 1);
    
    if (pos == 2) {
      fin = true;
    }
    else if (been.at(pos -1)) {
      cout << -1 << endl;
      break;
    }
    i++;
  }
  
  if (fin) cout << i << endl;
}