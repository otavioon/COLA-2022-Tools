#include <stdio.h>
int main(void)
{
  int n,max,min,sum,i,a[i];
  max=0;
  min=0;
  sum=0;
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
  return 0;
}