#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(void) {
  int c[4][4];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> c[i][j];
    }
  }

  for (int i = 1; i <= 2; i++) {
    int d=c[i][0]-c[0][0];
    if(c[i][1]!=c[0][1]+d || c[i][2]!=c[0][2]+d){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  
  return 0;
}
