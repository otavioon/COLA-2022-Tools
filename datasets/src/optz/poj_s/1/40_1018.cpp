#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	int a,b,c,d,e;
	for(a=1;a<=5;a++)
		for(b=1;b<=5;b++)
			for(c=1;c<=5;c++)
				for(d=1;d<=5;d++)
					for(e=1;e<=5;e++){
						int c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
						c1=(e==1);
						c2=(b==2);
						c3=(a==5);
						c4=(c!=1);
						c5=(d==1);
						c6=(a==1&&c1==1||a==2&&c1==1)||(a==3&&c1==0||a==4&&c1==0||a==5&&c1==0);
						c7=(b==1&&c2==1||b==2&&c2==1)||(b==3&&c2==0||b==4&&c2==0||b==5&&c2==0);
		                c8=(c==1&&c3==1||c==2&&c3==1)||(c==3&&c3==0||c==4&&c3==0||c==5&&c3==0);
		                c9=(d==1&&c4==1||d==2&&c4==1)||(d==3&&c4==0||d==4&&c4==0||d==5&&c4==0);
		                c10=(e==1&&c5==1||e==2&&c5==1)||(e==3&&c5==0||e==4&&c5==0||e==5&&c5==0);//?????????????
						if(a!=b&&a!=c&&a!=d&&a!=e&&b!=c&&b!=d&&b!=e&&c!=d&&c!=e&&d!=e&&c6&&c7&&c8&&c9&&c10&&e!=2&&e!=3)//?????e?????
							cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
					}
	return 0;
}