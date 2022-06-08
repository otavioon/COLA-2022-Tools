#include <stdio.h>
int main()
{
  int n,box[10000],max,min,sum=0,i;
  scanf("%d",&n);
  if(n>0 && n<=10000)
  {
    for(i=0;i<n;i++)
    {
      scanf("%d",&box[i]);
    }
  }
  max=box[0];
  min=box[0];
  for(i=0;i<n;i++)
  {
    if(box[i] >= -1000000 && box[i] <= 1000000)
    {
      sum+=box[i];
      if(box[i]>max)max=box[i];
      else if(box[i]<min)min=box[i];
    }
  }
  printf("%d %d %d\n",min,max,sum);
  return 0;
}