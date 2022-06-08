#include<stdio.h>
int main()
{
	int N,D;
	scanf("%d%d",&N,&D);
	int a=0,b=1;
	
	
	while((N-D)>=D)
	{
		if(b==1){N=N-D;
		a++;
		b++; 
		}
		if(b!=1)
		{
			N=N-2*D;
			a++;
		}
		
		
	}
	
	
	printf("%d",a);
}