#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int b[10];
int main()
{
   int a[6];
   int cc[7];
   int i,j,count=0;
   for(a[1]=1;a[1]<6;a[1]++)
	    for(a[2]=1;a[2]<6;a[2]++)
			 for(a[3]=1;a[3]<6;a[3]++)
				  for(a[4]=1;a[4]<6;a[4]++)
					   for(a[5]=1;a[5]<6;a[5]++)
					   {
						   	    cc[1]=(a[1]==5);
                                cc[2]=(a[2]==2);
                                cc[3]=(a[5]==1);
                                cc[4]=(a[1]!=3);
                                cc[5]=(a[1]==4);
                                cc[6]=(a[1]!=a[2] && a[1]!=a[3] && a[1]!=a[4] && a[1]!=a[5] && a[2]!=a[3] && a[2]!=a[4] && a[2]!=a[5] && a[3]!=a[4] && a[3]!=a[5] && a[4]!=a[5]);
                            if(cc[a[1]]==1 && cc[a[2]]==1 && cc[a[3]]!=1 && cc[a[4]]!=1 && cc[a[5]]!=1 && cc[6]==1 && a[2]!=5 && a[3]!=5)
							{
								for(j=1;j<6;j++)
									for(i=1;i<6;i++)
									{
										if(a[i]==j&&count==0)
										{
											cout<<i;
											count++;
											break;
										}
										if(a[i]==j&&count==1)
											cout<<" "<<i;
									}	
								break;
							}
					   }
  
					   
  
   return 0;

}