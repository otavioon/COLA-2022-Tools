#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	int a,b,c,d,e,a1[6][2],flag=0;
	int i;
	for(a=1;a<=5;a++)
	{for(b=1;b<=5;b++)
	{for(c=1;c<=5;c++)
	{			for(d=1;d<=5;d++)
	{				for(e=1;e<=5;e++)
					{
     
						a1[1][1]=(e==1);
						a1[2][1]=(b==2);
						a1[3][1]=(a==5);
						a1[4][1]=(c!=1);
						a1[5][1]=(d==1);
							if((a+b+c+d+e==15)&&(a*b*c*d*e==120)&&((a1[1][1]+a1[2][1]+a1[3][1]+a1[4][1]+a1[5][1])==2)&&e!=2&&e!=3)
							{
								a1[1][0]=a;
								a1[2][0]=b;
								a1[3][0]=c;
								a1[4][0]=d;
								a1[5][0]=e;
								for(i=1;i<=5;i++)
								{
									if(((a1[i][0]==1)&&(a1[i][1]==1))||((a1[i][0]==2)&&a1[i][1]==1))
									{ 
								
										flag+=1;
									}
								}
								if(flag==2)
								{

								cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e;
								}
								else{
									flag=0;
								}
							}


	}
	}
	}
	}
	}



return 0;
}
