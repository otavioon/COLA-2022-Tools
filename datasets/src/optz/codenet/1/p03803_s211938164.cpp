#include <stdio.h>
int main()
{
	int A;
	int B;
	scanf("%d %d",&A,&B);
	if(A==1||B==1)
	{
		if(A==B)printf("Draw");
		else if(A==1)printf("Alice");
		else printf("Bob");
	}
	else
	{
		if(A>B)printf("Alice");
		else if(A<B)printf("Bob");
		else printf("Draw");
	}
	return 0;
}