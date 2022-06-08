#include <bits/stdc++.h>
using namespace std;

int main(){
  int mas[3][3];
  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      cin >> mas[i][j];
    }
  }


  int min1 = mas[0][1] - mas[0][0];
  int min2 = mas[0][2] - mas[0][1];

  if(mas[1][1] - mas[1][0] == min1 && mas[1][2] - mas[1][1] == min2 && mas[2][1] - mas[2][0] == min1 && mas[2][2] - mas[2][1] == min2){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  return 0;

}