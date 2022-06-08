#include<bits/stdc++.h>
#include<math.h>
using namespace std;
 
int main(){
  int c[3][3]={};
  int c11;
  bool correct = true;

  for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
      cin >> c[i][j];
      if (i==0 && j==0) c11 = c[0][0];
      c[i][j] -= c11;
      if (c[i][j] != c[i][0] + c[0][j]) correct = false;
    }
  }
  
  cout << (correct? "Yes" : "No") << endl;


}
 