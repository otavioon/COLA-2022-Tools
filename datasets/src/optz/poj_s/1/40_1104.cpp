#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;



int main()
{
	int a[6];
	for(a[1]=1;a[1]<=5;a[1]++)
	{
		for(a[2]=1;a[2]<=5;a[2]++)
		{
			if(a[2]!=a[1])
			{
				for(a[3]=1;a[3]<=5;a[3]++)
				{
					if((a[3]!=a[1])&&(a[3]!=a[2]))
					{
						for(a[4]=1;a[4]<=5;a[4]++)
						{
							if((a[4]!=a[1])&&(a[4]!=a[2])&&(a[4]!=a[3]))
								for(a[5]=1;a[5]<=5;a[5]++)
								{
									if((a[5]!=a[1])&&(a[5]!=a[2])&&(a[5]!=a[3])&&(a[5]!=a[4])&&(a[5]!=2&&a[5]!=3))
									{
										int num=0;
										if(a[1]<=2&&a[5]==1) num++;
										if(a[2]<=2&&a[2]==2) num++;
										if(a[3]<=2&&a[1]==5) num++;
										if(a[4]<=2&&a[3]!=1) num++;
										if(a[5]<=2&&a[4]==1) num++;
										if(num==2&&((a[5]==1)+(a[2]==2)+(a[1]==5)+(a[3]!=1)+(a[4]==1))==2)
										{
											cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<a[5];
										}
										
									}
								}
						}
					}
				}
			}
		}
	}
	return 0;
}