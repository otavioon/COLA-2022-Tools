#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;


int main()
{
	int hang, lie, a[100][100];
	cin >> hang >> lie;
	for(int i = 0; i < hang; i++)
	{
		for(int j = 0; j < lie; j++)
		{
			cin >> a[i][j];         //??????
		}
	}
	for(int k = 0; k < lie; k++) //????????k?????
	{
		for(int l = k; (l >= 0) && (k - l < hang); l--) // ?????????????,??????k+1???????????
		{
			cout << a[k - l][l] << endl << endl;	
		}
	}
	for(int p = lie; p < hang + lie - 1; p++)  //????????p?????
	{
		for(int q = lie - 1;(q >= 0) && (p - q < hang);q--)
		{		
			cout << a[p - q][q] << endl << endl;			
		}
	}
	return 0;
}
