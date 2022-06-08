#include<stdio.h>
int main(void)
{
int x, y;

scanf("%d %d", &x, &y);

if(x>y&&y>0)
printf("%d %d\n", y, x);
else if(x<=y&&x>0)
printf("%d %d\n", x, y);



return 0;
}