#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	int A,B,C,D,E,a,b,c,d,e;
	for(E=1;E<=5;E++)
	{
	for(A=1;A<=5;A++)
	{
		for(B=1;B<=5;B++)
		{
			for(C=1;C<=5;C++)
			{
				for(D=1;D<=5;D++)
				{
					if(A!=B&&A!=C&&A!=D&&A!=E&&B!=C&&B!=D&&B!=E&&C!=D&&C!=E&&D!=E&&E!=2&&E!=3)
					{
						a=0;b=0;c=0;d=0;e=0;
						if(E==1){a=1;}
						if(B==2){b=1;}
						if(A==5){c=1;}
						if(C!=1){d=1;}
						if(D==1){e=1;}
						if(a+b+c+d+e==2)
						{
							if(a==1&&(A==1||A==2))
							{
								if(b==1&&(B==1||B==2))
								{
									cout<<A<<' '<<B<<' '<<C<<' '<<D<<' '<<E;
								}
								if(c==1&&(C==1||C==2))
								{
									cout<<A<<' '<<B<<' '<<C<<' '<<D<<' '<<E;
								}
								if(d==1&&(D==1||D==2))
								{
									cout<<A<<' '<<B<<' '<<C<<' '<<D<<' '<<E;
								}
								if(e==1&&(E==1||E==2))
								{
									cout<<A<<' '<<B<<' '<<C<<' '<<D<<' '<<E;
								}
							}
							if(b==1&&(B==1||B==2))
							{
								if(c==1&&(C==1||C==2))
								{
									cout<<A<<' '<<B<<' '<<C<<' '<<D<<' '<<E;
								}
								if(d==1&&(D==1||D==2))
								{
									cout<<A<<' '<<B<<' '<<C<<' '<<D<<' '<<E;
								}
								if(e==1&&(E==1||E==2))
								{
									cout<<A<<' '<<B<<' '<<C<<' '<<D<<' '<<E;
								}
							}
							if(c==1&&(C==1||C==2))
							{
								if(d==1&&(D==1||D==2))
								{
									cout<<A<<' '<<B<<' '<<C<<' '<<D<<' '<<E;
								}
								if(e==1&&(E==1||E==2))
								{
									cout<<A<<' '<<B<<' '<<C<<' '<<D<<' '<<E;
								}
							}
							if(d==1&&(D==1||D==2))
							{
								if(e==1&&(E==1||E==2))
								{
									cout<<A<<' '<<B<<' '<<C<<' '<<D<<' '<<E;
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
