#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

//****************************************************
//*  ? ? ?: homework.cpp                          *
//*  ?    ?: ???                                *
//*  ????: 2012?11?5?                         *
//*  ????: ??????????                  *
//****************************************************


int main()
{
	int k, n, m, i, j, x, sum; //sum??? 
	cin >> k; //????
	while (k--)
	{
		cin >> m >> n;
		sum = 0;
		for (i = 1; i <= m; i++)
		{
			for (j = 1; j <= n; j++)
			{
				cin >> x; //???? 
				if ((i == 1) || (i == m) || (j == 1) || (j == n)) 
					sum = sum + x; //?????? 
			}
		}
		cout << sum << endl;
	}
	
	return 0;
}
