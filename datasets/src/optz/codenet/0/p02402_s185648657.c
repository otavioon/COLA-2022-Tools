#include<stdio.h>
int main()
{
int n;
int ai[10000];
int i;
int i2;
int flag=0;
long boss=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{
 scanf("%d",&ai[i]);
 printf(" ");
}
printf("\n");
for(i=1;;i++)
{
 for(i2=0;i2<n;i2++)
 {
  if(i==ai[i2])
  {
   printf("%d",ai[i2]);
   flag=1;
   break;
  }
 }
 if(flag==1)
 {
  break;
 }
}
printf(" ");
flag=0;
for(i=100000;i>=-100000;i--)
{
 for(i2=1;i2>n;i2++)
 {
  if(i==ai[i2])
  {
   printf("%d",ai[i2]);
   flag=1;
   break;
  }
 }
  if(flag==1)
  {
   break;
  }
}
printf(" ");
flag=0;
for(i=0;i<n;i++)
{
 boss=boss+ai[i];
}
printf("%d\n",boss);
return 0;
}