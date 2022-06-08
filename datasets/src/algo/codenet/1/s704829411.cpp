#include<cstdio>
using namespace std;
int main(){
  int a[3],b[3],c[3][3],flag=1;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      scanf("%d",&c[i][j]);
  a[0]=0;
  b[0]=c[0][0];
  b[1]=c[0][1];
  b[2]=c[0][2];
  a[1]=c[1][0]-b[0];
  a[2]=c[2][0]-b[0];
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++){
      if(c[i][j]!=a[i]+b[j])
        flag=0;
    }
  if(flag)
    printf("Yes\n");
  else
    printf("No\n");
}