#include<stdio.h>
int main(void)
{
  int i,j,a,b,c,flag=1,x[10000],y[10000];
  i=0;
  do{
    scanf("%d %d",&a,&b);
    if(a>b){
      c=a;
      a=b;
      b=c;
    }
  	x[i]=a;
  	y[i]=b;
  	i++;
  	if(a==0&&b==0){
  	  flag=0;
  	}
  }while(flag);
  for(j=0;j<i-1;j++){
    printf("%d %d\n",x[j],y[j]);
  }
  return 0;
}