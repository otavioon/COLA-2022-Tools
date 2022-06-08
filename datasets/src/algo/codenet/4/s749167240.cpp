#include <iostream>
#include <string.h>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
  string h;
  int n;
  cin >> h >> n;
  set<int> D;
  for (int i = 0; i < n; i++) {
    int sub;
    cin >> sub;
    D.insert(sub);    
  }  
  int ok = -1;
  int hhh = stoi(h);
  if (ok != -1) {
  }
  else {
    for (int j = hhh; j < 100000; j++) {
      string hh = to_string(j);
      for (int i = 0; i < hh.size(); i++) {
        if (D.count(hh[i] - 48) == 1) {
          break;  
        }    
        if (i == hh.size() - 1) {
          cout << hh << endl;  
          return 0;
        }
      }    
    }      
  }
}