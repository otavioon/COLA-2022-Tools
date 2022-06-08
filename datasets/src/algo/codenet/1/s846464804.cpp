#include <bits/stdc++.h>
using namespace std;

int main(){
  int c[9];
  for(int i=0;i<9;i++){
  	cin >> c[i];
  }
  int a1 = c[0]+c[4]+c[8],
  a2 = c[0]+c[5]+c[7],
  a3 = c[1]+c[3]+c[8],
  a4 = c[1]+c[5]+c[6],
  a5 = c[2]+c[3]+c[7],
  a6 = c[2]+c[4]+c[6];
  if(a1==a2&&a2==a3&&a3==a4&&a4==a5&&a5==a6)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}