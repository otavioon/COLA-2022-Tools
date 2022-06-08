#include<stdio.h>
int main()
{
	int a,b,c[3010][10],i=0,j;
	while(1>0)
	{
		scanf("%d %d",&a,&b);
		if(a==0 && b==0)
			break;
		i++;
		if(a<b)
		{
			c[i][1]=a;
			c[i][2]=b;
		}
		else
		{
			c[i][1]=b;
			c[i][2]=a;
		}
	}	
	for(j=1;j<=i;j++)
		printf("%d %d\n",c[j][1],c[j][2]);
	
}
