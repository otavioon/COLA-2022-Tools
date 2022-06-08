#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int min;
  int number=1;
  int indicator = 0;
  while (indicator == 0){
  min = N*number;
  if (min % 2 == 0){
    indicator = 1;
   }
  else {
    number += 1;
   }
  }
  cout << min;
}

