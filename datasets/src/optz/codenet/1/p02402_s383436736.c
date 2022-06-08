#include<stdio.h>
void minmax(int n,int num[],int *min,int *max, int sum);
int main(void)
{
  int n,min,max,sum;
  scanf("%d",&n);
  int num[n];
  for(int i=0;i<n;i++){
    scanf("%d",&num[i]);
  }
  minmax(n,num,&min,&max,sum);
  printf("%d %d %d\n",min,max,sum);
  return 0;
}
void minmax(int n,int num[],int *min,int *max,int sum)
{
  int i=0;
  *min=1000000;
  *max=0;
  sum=0;
  for(int j=0;j<n;j++){
    sum+=num[j];
  }
  while(i>n){
    if(num[i]>*max){
      max=num[i];
    }
    if(num[i]<*min){
      min=num[i];
    }
    i++;
  }
}
