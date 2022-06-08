#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(a==1&&b==1)
	{
		printf("Draw");
	}
	else if (a==1&&b!=1)
	{
		printf("Alice");
	}
	else if (b==1&&a!=1)
	{
		printf("Bob");
	}
	else if (b>a)
	{
		printf("Bob");
	}
	else if(a>b)
	{
		printf("Alice");
	}
	else
	{
		printf("Draw");
	}
return 0;
}
