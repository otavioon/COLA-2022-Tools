#include <cstdio>

using namespace std;

int main(void){
  int mtrx[3][3];
  
  for (int i=0; i<9; i++){
    int t;
    scanf("%d", &t);
    mtrx[i%3][i/3] = t;
  }
  
  for (int i=0; i<3; i++){
    while (mtrx[i][0] && mtrx[i][1] && mtrx[i][2]){
      mtrx[i][0]--; mtrx[i][1]--; mtrx[i][2]--;
    }
  }
  
  if ((mtrx[0][0]==mtrx[1][0] && mtrx[1][0]==mtrx[2][0]) &&
      (mtrx[0][1]==mtrx[1][1] && mtrx[1][1]==mtrx[2][1]) &&
      (mtrx[0][2]==mtrx[1][2] && mtrx[1][2]==mtrx[2][2])){
    puts("Yes");
  } else {
    puts("No");
  }
  
  return 0;
}