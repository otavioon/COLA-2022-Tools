#include<bits/stdc++.h>
using namespace std;

int main(){
  int c[3][3];
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cin >> c[i][j];
    }
  }
  int b0=c[0][0];
  int b1=c[0][1];
  int b2=c[0][2];
  int a1=c[1][0]-b0;
  int a2=c[2][0]-b0;
  if(a1+b1==c[1][1] && a1+b2==c[1][2] && a2+b1==c[2][1] && a2+b2==c[2][2]){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}