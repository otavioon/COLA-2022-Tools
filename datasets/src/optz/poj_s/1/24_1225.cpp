#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

//***********************************************************************************
//???????2?n??
//??  ????
//???  11-13
//***********************************************************************************


int main()
{
	int n;                    //??
	int a[41] = {0};          //??????????0
	int i, j, k;

	cin >> n;

	a[40] = 1;                 //???????????

	for(k = 0; k < n; k ++)
	{
		int tem[41] = {0};                    //????????????

		for(i = 40; i >= 0; i --)
			tem[i] = a[i] * 2;

		for(i = 40; i >= 0; i --)              //???????????a[]???
		{
			tem[i - 1] += tem[i] / 10;
			a[i] = tem[i] % 10;
		}
	}

	int count = 0;                            //??????0???

	for(i = 0; i <= 40; i ++)
	{
		if(a[i] == 0 && count == 0)
			continue;
		else
		{
			cout << a[i];
			count = 1;
		}
	}


	
	return 0;
}
