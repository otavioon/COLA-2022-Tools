#include<stdio.h>
int main(){
  int n,i,j,temp;
  scanf("%d",&n);
  long long num[n],total=0;
  for(i=0;i<n;i++){
    scanf("%lld",&num[i]);
  }
  for(i=1;i<=n;i++){
    for(j=0;j<n-1;j++){
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
  printf("%lld %lld %lld\n",num[0],num[n-1],total);
  return(0);
}