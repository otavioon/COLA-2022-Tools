#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{int n;
cin>>n;
if(n%3==0&&n%5==0&&n%7==0)
	cout<<"3 5 7";
else					//????????????
	{if(n%5==0&&n%7==0)
	cout<<"5 7";
	if(n%3==0&&n%5==0)
	cout<<"3 5";
	if(n%3==0&&n%7==0)
	cout<<"3 7";
	if((!(n%3==0&&n%5==0))&&(!(n%3==0&&n%7==0))&&(!(n%5==0&&n%7==0)))	//?????????????
		{if(n%3==0)
		cout<<'3';
		if(n%5==0)
		cout<<'5';
		if(n%7==0)
		cout<<'7';
		if(n%3!=0&&n%5!=0&&n%7!=0)		//???????????
		cout<<'n';
		}
	}
return 0;
}