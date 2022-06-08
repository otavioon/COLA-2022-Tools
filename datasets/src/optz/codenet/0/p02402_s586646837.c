#include <stdio.h>
int main(void)
{
int i,n,tmp,tmp2;
int long sum=0;
int max,min;

scanf("%d",&n);
for (i = 0;i < n;i++)
{
 scanf("%d",&tmp);
  sum += tmp;
tmp2=tmp;
  if(i == 0){
    tmp = max;
    min = tmp2;
  }else if(max < tmp)
     max = tmp;
  else if(min > tmp2)
     min = tmp2;
}
printf("%d %d %ld\n",min,max,sum);
     
return 0;
}