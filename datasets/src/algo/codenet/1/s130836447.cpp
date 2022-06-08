#include <iostream>
using namespace std;

int main(){
  int c[3][3];
  for (int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        cin >> c[i][j];}}
   
  int d1=(c[1][1]-c[1][2]);
  int d2=(c[1][2]-c[1][3]);

  for (int i=1;i<3;i++){
    if(c[i][1]-c[i][2]==d1 && c[i][2]-c[i][3]==d2)
      continue;
    else {cout <<"No";goto Exit;}}
 
   cout << "Yes";
    
   Exit: ;

}