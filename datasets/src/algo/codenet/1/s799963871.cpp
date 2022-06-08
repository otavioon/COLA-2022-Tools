#include <iostream>
using namespace std;

int main(){
  int c[3][3];
  for (int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        cin >> c[i][j];}}
   
  int d1=(c[0][0]-c[0][1]);
  int d2=(c[0][1]-c[1][2]);

  for (int i=1;i<3;i++){
    if(c[i][0]-c[i][1]==d1 && c[i][1]-c[i][2]==d2)
      continue;
    else {cout <<"No";goto Exit;}}
 
   cout << "Yes";
    
   Exit: ;

}