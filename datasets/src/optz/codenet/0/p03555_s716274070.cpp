#include <bits/stdc++.h>
using namespace std;

int main() {
  string n, m;
  cin >> n >> m;
  int x = 0;
  
  for(int i = 0; i < 3; i++) {
    if(i == 0) {
      if(n.at(0) == m.at(2)) {
        x++;
      }
    }
    if(i == 1) {
      if(n.at(1) == m.at(1)) {
        x++;
      }
    }
    if(i == 2) {
      if(n.at(2) == m.at(0)) {
        x++;
      }
    }
  }
  
  if(x == 3) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
      
}