#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*????????*/

void main()
{
	int n,k,x[100][4],y,z;
	char a[100][20],b[100],c[100];
	scanf("%d",&n);
	for(k=0,y=0,z=0;k<n;k++)
	{
		scanf("%s %d %d %c %c %d",a[k],&x[k][0],&x[k][1],&b[k],&c[k],&x[k][2]);
		x[k][3]=0;
		if(x[k][0]>80&&x[k][2]>0)
		{
			x[k][3]=x[k][3]+8000;
		}
		if(x[k][0]>85&&x[k][1]>80)
		{
			x[k][3]=x[k][3]+4000;
		}
		if(x[k][0]>90)
		{
			x[k][3]=x[k][3]+2000;
		}
		if(x[k][0]>85&&c[k]=='Y')
		{
			x[k][3]=x[k][3]+1000;
		}
		if(x[k][1]>80&&b[k]=='Y')
		{
			x[k][3]=x[k][3]+850;
		}
		z=z+x[k][3];
		if(x[k][3]>x[y][3])y=k;
	}
	printf("%s\n%d\n%d\n",a[y],x[y][3],z);
}

