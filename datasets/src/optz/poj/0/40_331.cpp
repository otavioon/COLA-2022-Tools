#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;


int main()
{
	int a=1,b=1,c=1,d=1,e=1,as,bs,cs,ds,es;
	as = (e == 1);
	bs = (b == 2);
	cs = (a == 5);
	ds = (c != 1);
	es = (d == 1);
	// cout << as << bs << cs << ds << es;
	for (a = 1; a <= 5; a++)
		for (b = 1; b <= 5; b++)
			for (c = 1; c <= 5; c++)
				for (d = 1; d <= 5; d++)
					for (e = 1; e <= 5; e++)
						if (e!=2 && e != 3)
						{

							if (((b == 1) && (d == 2)) || ((b == 2) && (d == 1)))
							{
								if ((b==2)&&(d!=1)&&(e!=1)&&(a!=5)&&(c==1))
								cout << a << " " << b << " " << c << " " << d << " " << e << endl;
							}

							if (((b == 1) && (e == 2)) || ((b == 2) && (e == 1)))
							{
								if ((b==2)&&(d==1)&&(e!=1)&&(a!=5)&&(c==1))
								cout << a << " " << b << " " << c << " " << d << " " << e << endl;
							}
							
							if ( ((b == 1)&&(c == 2)) || ((b == 2)&&(c ==1)) )
							{    if ((a == 5)&&(b == 2)&&(e!=1)&&(d == 3) && (e != 5))
								{cout << a << " " << b << " " << c << " " << d << " " << e << endl;}
							}


							if (((c == 1) && (d == 2)) || ((c == 2) && (d == 1)))
							{
								if ((b==2)&&(d==1)&&(e!=1)&&(a!=5)&&(c==1))
								cout << a << " " << b << " " << c << " " << d << " " << e << endl;
							}

							if (((c == 1) && (e == 2)) || ((c == 2) && (e == 1)))
							{
								if ((b==2)&&(d==1)&&(e!=1)&&(a!=5)&&(c==1))
								cout << a << " " << b << " " << c << " " << d << " " << e << endl;
							}

							if (((d == 1) && (e == 2)) || ((d == 2) && (e == 1)))
							{
								if ((b==2)&&(d==1)&&(e!=1)&&(a!=5)&&(c==1))
								cout << a << " " << b << " " << c << " " << d << " " << e << endl;
							}
						}
	return 0;
}