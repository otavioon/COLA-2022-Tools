#include <iostream>
using namespace std;

int main(){
  int c[3][3];
  for(int i=0; i<3; i++){
    cin >> c[i][0] >> c[i][1] >> c[i][2];
  }
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      if(c[i+1][j] - c[i][j] != c[i+1][j+1] - c[i][j+1]){
	goto LOOP_END;
      }
    }
  }
  cout << "Yes" << flush;
  return 0;
 LOOP_END:
  cout << "No" << flush;
}