#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

/*??? 1200012866
2012.10.12
??3?5?7??*/
int main()
{
	int n,f=0;//f???????????
	cin>>n;
	if(n%105==0&&f==0){cout<<"3 5 7";f=1;}
	if(n%15==0&&f==0){cout<<"3 5";f=1;}
	if(n%21==0&&f==0){cout<<"3 7";f=1;}
	if(n%35==0&&f==0){cout<<"5 7";f=1;}
	if(n%3==0&&f==0){cout<<"3";f=1;}
	if(n%5==0&&f==0){cout<<"5";f=1;}
	if(n%7==0&&f==0){cout<<"7";f=1;}
	if(f==0)cout<<"n";//???????n

	return 0;
}