#include <stdio.h>
int main(void)
{
  int n,max,min,sum,i,a[n];
  max=0;
  min=0;
  sum=0;
  a[n]=0;
  scanf("%d",&n);
  while(i<n){
    scanf("%d",&a[i]);
    sum+=a[i];
    if(a[max]<a[i]){
      max=i;
    }
    if(a[min]>a[i]){
      min=i;
    }
    i++;
  }
  printf("%d %d %d\n",a[min],a[max],sum);
}