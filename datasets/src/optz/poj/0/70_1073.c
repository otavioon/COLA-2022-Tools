#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	int n,i,j,k,l;
	int a,b[13],c[13];
	scanf ("%d",&n);
	for (k=1;k<=n;k++)
	{
		scanf ("%d%d%d",&a,&i,&j);
		if (i>j)
		{
			l=i;
			i=j;
			j=l;
		}
		if (a%4==0&&a%100!=0||a%400==0)
		{
			b[1]=c[1]=0;
			b[2]=c[2]=31;
			b[3]=c[3]=60;
			b[4]=c[4]=91;
			b[5]=c[5]=121;
			b[6]=c[6]=152;
			b[7]=c[7]=182;
			b[8]=c[8]=213;
			b[9]=c[9]=244;
			b[10]=c[10]=274;
			b[11]=c[11]=305;
			b[12]=c[12]=335;
			if ((c[j]-b[i])%7==0)
			{
				printf ("YES\n");
			}
			else
			{
				printf ("NO\n");
			}
		}
		else
		{
			b[1]=c[1]=0;
			b[2]=c[2]=31;
			b[3]=c[3]=59;
			b[4]=c[4]=90;
			b[5]=c[5]=120;
			b[6]=c[6]=151;
			b[7]=c[7]=181;
			b[8]=c[8]=212;
			b[9]=c[9]=243;
			b[10]=c[10]=273;
			b[11]=c[11]=304;
			b[12]=c[12]=334;
			if ((c[j]-b[i])%7==0)
			{
				printf ("YES\n");
			}
			else
			{
				printf ("NO\n");
			}
		}
	}
		return 0;
}