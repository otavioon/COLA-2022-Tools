#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	
	int a,b,c,d,e;
	for(a=5;a<=5;a++)
		for(b=2;b<=2;b++)
			for(c=1;c<=1;c++)
				for(d=3;d<=3;d++)
					for(e=4;e<=4;e++)
						if(a!=b&&a!=c&&a!=d&&a!=e&&b!=c&&b!=d&&b!=e&&c!=d&&c!=e&&d!=e&&e!=2&&e!=3&&((e==1&&(a==1|| a==2))+ (b==2&&(b==1||b==2))  +  (a==5&&(c==1||c==2)) +(c!=1&&(d==1||d==2)) +(d==1&&(e==1||e==2)) ==2)  )
	cout << a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;



		return 0;
}