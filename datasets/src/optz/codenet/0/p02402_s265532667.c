#include <stdio.h>
int main(void)
{
int i,n,tmp;
int sum=0,max=0,min=0;

scanf("%d",&n);
for (i = 0;i < n;i++)
{
 scanf("%d",&tmp);
  sum += tmp;
  if(i == 0)
    tmp = max = min;
  else if(max < tmp)
     max = tmp;
  else if(min > tmp)
     min = tmp;
}
printf("%d %d %d\n",min,max,sum);
     
return 0;
}