#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	
	int b[6],a[6];
	int i,j,k,x;
	
	
	for(i=1;i<=5;i++)
	{   
		a[5]=i;
		if(a[5]==2 || a[5]==3) continue;
		if(a[5]==1) b[5]=1;
		else b[5]=0;
		for(j=1;j<=5;j++)
		{
			a[4]=j;
			if(a[4]==a[5]) continue;
			if(a[4]==1 ||a[4]==2) b[4]=1;
			else b[4]=0;
			
			for(k=1;k<=5;k++)
			{
				a[3]=k;
				if(a[3]==a[4]||a[3]==a[5]) continue;
				if(a[3]==1 ||a[3]==2) b[3]=1;
				else b[3]=0;
				for(x=1;x<=5;x++)
				{
					a[2]=x;
					if(a[2]==a[3]||a[2]==a[4]||a[2]==a[5]) continue;
					if(a[2]==1 ||a[2]==2) b[2]=1;
					else b[2]=0;
					a[1]=15-a[5]-a[4]-a[3]-a[2];
					if(a[1]==1 ||a[1]==2) b[1]=1;
					else b[1]=0;

					if(b[1]==(a[5]==1)&&b[2]==(a[2]==2)&&b[3]==(a[1]==5)&&b[4]==(a[3]!=1)&&b[5]==(a[4]==1))
					
					
						cout<<a[1]<<' '<<a[2]<<' '<<a[3]<<' '<<a[4]<<' '<<a[5];
				}
			}
		}
	}
	return 0;
}


