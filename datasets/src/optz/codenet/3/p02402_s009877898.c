#include<stdio.h>
int main(){
  int n,i,j,temp,total=0;
  scanf("%d",&n);
  int num[n];
  for(i=0;i<n;i++){
    scanf("%d",&num[i]);
  }
  for(i=1;i<=n;i++){
    for(j=0;j<n-i;j++){
      if(num[j]>num[j+i]){
	temp=num[j];
	num[j]=num[j+1];
	num[j+1]=temp;
      }
    }
  }
  for(i=0;i<n;i++){
    total+=num[i];
  }
  printf("%d %d %d\n",num[0],num[n-1],total);
  return(0);
}