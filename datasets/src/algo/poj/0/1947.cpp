#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

//********************************************************************
//??????K???
//?????????????K???
//??????
//********************************************************************
int main()                             //???


{                                      //?????
	int n, k, num[1000];               //?????????
	cin>>n>>k;
	for(int i = 0; i < n; i++)         //??????
		cin>>num[i];
	int c = 1;                         //??????
    for(int j = 0; j < n; j++)
	{
			for(int m = 0; m < n; m++)
			{
				if(m == j)
					continue;
				else if(num[j] + num[m] == k)
                      c = 0;
			}
	}
	if(c == 1)
		cout<<"no"<<endl;
	if(c == 0)
		cout<<"yes"<<endl;
	return 0;
}
