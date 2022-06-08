#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  vector<int> button(N);
  
  for (int i = 0; i < N; i++) {
    cin >> button.at(i); 
  }
  
  int num = 0;
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (button.at(num) == 2) {
       count += i + 1;
       break;
    }
    
    num = button.at(num) - 1;
  }
  if (count == 0) {
    cout << -1 << endl; 
  } else {
    cout << count << endl; 
  }
}