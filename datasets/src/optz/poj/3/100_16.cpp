#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

//****************************************************** 
//* ? ? ?   ?? ? ?                              *
//* ? ?      ?? ? ?                              *
//* ? ? ? ??2010 ? 11 ? 17 ?                   * 
//* ? ?      ?1000010185                            *
//****************************************************** 
int main()
{

	//?????????????????????????????WA??????????
	int a, b, c, A, B, C;
	for (a = 0; a < 3; a ++)
		for (b = 0; b < 3; b ++)
			for (c = 0; c < 3; c ++)
			{
				A = (b > a) + (c == a);
				B = (a > b) + (a > c);
				C = (c > b) + (b > a);
				if ((((a > b && A < B) || (a < b && A > B)) +
					((a > c && A < C) || (a < c && A > C)) +
					((b > c && B < C) || (b < c && B > C))) == 3)
					if (a > b)
					{
						if (b > c)
							cout << "CBA";
						else if (a > c)
							cout << "BCA";
						else
							cout << "BAC";
					}
					else if (b < c)
						cout << "ABC";
					else if (a > c)
						cout << "CAB";
					else
						cout << "ACB";
			}
	return 0;
}