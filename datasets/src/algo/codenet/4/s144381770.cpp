#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  set<char> hate;
  for (int i = 0; i < K; i++) {
    char c;
    cin >> c;
    hate.insert(c);
  }
  while (1) {
    string s = to_string(N);
    int l = s.size();
    bool b = true;
    for (int i = 0; i < l; i++) if (hate.count(s[i])) b = false;
    if (b) {
      cout << N << endl;
      return 0;
    }
    else N++;
  }
} 