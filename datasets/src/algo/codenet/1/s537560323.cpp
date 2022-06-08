#include<stdio.h>

int main(void){
  int c[3][3];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      scanf("%d",&c[i][j]);
    }
  }
  if((c[0][0]-c[1][0]!=c[0][1]-c[1][1])||(c[0][0]-c[1][0]!=c[0][2]-c[1][2])||(c[0][0]-c[2][0]!=c[0][1]-c[2][1])||(c[0][0]-c[2][0]!=c[0][2]-c[2][2])){
    printf("No");
  }
  else{
    printf("Yes");
  }
  return 0;
}
