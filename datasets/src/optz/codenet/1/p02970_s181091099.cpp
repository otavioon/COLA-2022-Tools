#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N , D;
  cin >> N , D;
  
  int i = 0;
  
  while ((D * 2) * i >= N) {
    i++;
  }
  cout << i << endl;
}
 