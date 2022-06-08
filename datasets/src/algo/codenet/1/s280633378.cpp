#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
  int c[3][3];
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cin >> c[i][j];
    }
  }

  int b = 0;
  for(int i = 1; i <= 2; i++){
    b = c[i][0] - c[0][0];
    for(int j = 1; j <= 2; j++){
      if(b != c[i][j] - c[0][j]){
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;

  return 0;
}