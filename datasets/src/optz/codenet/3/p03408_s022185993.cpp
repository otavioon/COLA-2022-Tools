#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i = i + 1) {
    cin >> s.at(i);
  }  
  int m;
  cin >> m;
  vector<string> t(m);
  for (int i = 0; i < m; i = i + 1) {
    cin >> t.at(i);
  }
  
  vector<int> count(n, 1);
  
  for (int i = 0; i < n; i = i + 1) {
    for (int j = 0; j < n; j = j + 1) {
      if (s.at(i) == s.at(j) && i != j) {
        count.at(i) = count.at(i) + 1;
      }
    }
    for (int j = 0; j < m; j = j + 1) {
      if (s.at(i) == t.at(j)) {
        count.at(i) = count.at(i) - 1;
      }
    }
    //cout << count.at(i) << endl;
  }
  
  int max = count.at(0);
  for (int i = 0; i < n; i = i + 1) {
    if (max < count.at(i)) {
      max = count.at(i);
    }
  }
  
  if (max <= 0) {
    cout << 1 << endl;
  } else {
    cout << max << endl;
  }
}