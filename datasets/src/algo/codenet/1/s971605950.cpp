#include<bits/stdc++.h>
using namespace std;

int c[3][3];
int main(){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      scanf("%d",&c[i][j]);
    }
  }
  int sum1=c[0][0]+c[1][1]+c[2][2];
  int sum2=c[0][1]+c[2][0]+c[1][2];
  int sum3=c[1][0]+c[0][2]+c[2][1];
  if(sum1==sum2&&sum2==sum3){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
}
