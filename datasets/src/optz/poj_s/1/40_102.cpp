#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int main ()
{
    int a,b,c,d,e,sum,a1,b1,c1,d1,e1,a2,b2,c2,d2,e2;
	for (a = 1; a <=5;a++)
		for (b = 1; b <= 5 ;b++)
		{
			if (a != b)
				for (c = 1; c <= 5; c++)
				{
					if (c != b && c != a)
						for (d = 1; d <= 5; d++)
						{
							if (d != a && d != b && d != c)
								for (e = 1; e <= 5; e++)
								{
									if (e !=a && e != b && e !=c && e != d && e != 2 && e !=3)
									{
										a1 = (e == 1);
										b1 = (b == 2);
										c1 = (a == 5);
										d1 = (c != 1);
										e1 = (d == 1);
										if (a1 + b1 + c1 + d1 +e1 == 2)
										{a2= (a1 == 1 && (a == 1 || a == 2));
										 b2= (b1 == 1 && (b == 1 || b ==2));
										 c2= (c1 == 1 && (c == 1 || c == 2));
										d2 = (d1 == 1 && (d == 1 || d == 2));
										e2 =  (e1 == 1 && (e == 1));
												if (a2 + b2 +c2 +d2 +e2 ==2)		 cout << a <<" "<<b <<" "<<c <<" "<<d <<" " <<e;}
									}
								}
						}
				}
		}

	return 0;
}