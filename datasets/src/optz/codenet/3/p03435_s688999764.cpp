#include <iostream>
#include <algorithm>

using namespace std;

int c[3][3];
int i,j;
bool flag = false;

int main(){

  for (i=0; i<3; i++){
    for (j=0; j<3; j++){
        cin >> c[i][j];
      }
  }

  int a[3],b[3];
  a[0]=0;
  b[0]=c[0][0];
  b[1]=c[0][1];
  b[2]=c[0][2];
  a[1]=c[1][0] - b[1];
  a[1]=c[2][0] - b[2];

  if ( c[1][1] == a[1] +b[1] ){
    if ( c[1][2] == a[1] + b[2]){
      if ( c[2][1] == a[2] + b[1]){
        if ( c[2][2] == a[2] + b[2]){
                flag = true;
        }
      }
    }
  }

  if (flag){
    cout << "Yes" << endl;
  }else{
    cout <<  "No" << endl;
  }

  return 0;
}