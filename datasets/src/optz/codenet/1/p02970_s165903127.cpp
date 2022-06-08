#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  
  int sum = 1, i = 1;
  
  while (n > (2*d + 1) * i){
    sum ++;
    i++;
  }
  
  cout << sum << endl;
}