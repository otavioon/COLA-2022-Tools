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

  for (int i = 0; i < 2; i++) {
    int j=c[i][0]-c[0][0];
    if(c[i][1]!=c[0][1]+j || c[i][2]!=c[0][2]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  
  return 0;
}
