#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;


int main()
{
	int a,b,c,d,e;
	int h[6];
	for (e=1;e<=5;e++)
	{
		if (e==2||e==3)
			continue;
		else
			for (d=1;d<=5;d++)
			{
				if (d==e)
					continue;
				else 
					for (c=1;c<=5;c++)
					{
						if (c==e||c==d)
							continue;
						else
							for (b=1;b<=5;b++)
							{
								if (b==e||b==d||b==c)
									continue;
								else
								{
									a=15-b-c-d-e;
								if (((e==1)+(b==2)+(a==5)+(c!=1)+(d==1))==2)
								{
									if ((a==1||a==2)&&(e==1))
									{
									    if ((b==1||b==2)&&(b==2))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									    
										if ((c==1||c==2)&&(a==5))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									    
										if ((d==1||d==2)&&(c!=1))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									    
										if ((e==1||e==2)&&(d==1))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									}

									if ((b==1||b==2)&&(e==1))
									{
									    if ((a==1||a==2)&&(e==1))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									    
										if ((c==1||c==2)&&(a==5))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									    
										if ((d==1||d==2)&&(c!=1))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									    
										if ((e==1||e==2)&&(d==1))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									}
									if ((c==1||c==2)&&(a==5))
									{
									    if ((b==1||b==2)&&(b==2))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									    
										if ((a==1||a==2)&&(e==1))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									    
										if ((d==1||d==2)&&(c!=1))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									   
										if ((e==1||e==2)&&(d==1))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									}
									if ((d==1||d==2)&&(c!=1))
									{
									    if ((b==1||b==2)&&(b==2))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									    
										if ((c==1||c==2)&&(a==5))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									    
										if ((a==1||a==2)&&(e==1))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									    
										if ((e==1||e==2)&&(d==1))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									}
									if ((e==1||e==2)&&(d==1))
									{
									    if ((b==1||b==2)&&(b==2))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									    
										if ((c==1||c==2)&&(a==5))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									    
										if ((d==1||d==2)&&(c!=1))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									    
										if ((a==1||a==2)&&(e==1))
									        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;									}
								}
								}
							}
					}
			}
	}

	return 0;
}