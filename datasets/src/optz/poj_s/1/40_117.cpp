#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int main(){
int a,b,c,d,e;  //???????a,b,c,d,e???
for(a=1;a<=5;a++)
for(b=1;b<=5;b++)
for(c=1;c<=5;c++)
for(d=1;d<=5;d++)
for(e=1;e<=5;e++)

{
	if(
		(((e==1)&&(a==1||a==2))||((e!=1)&&(a!=1)&&(a!=2)))
		&&
		(((b==2)&&(b==1||b==2))||((b!=2)&&(b!=1)&&(b!=2)))
		&&
		(((a==5)&&(c==1||c==2))||((a!=5)&&(c!=1)&&(c!=2)))
		&&
		(((c!=1)&&(d==1||d==2))||((c==1)&&(d!=1)&&(d!=2)))
		&&
		(((d==1)&&(e==1||e==2))||((d!=1)&&(e!=1)&&(e!=2)))
		&&
		(e!=2)
		&&
		(e!=3)
		&&
		((a-b)*(b-c)*(c-d)*(d-e)*(a-c)*(a-d)*(a-e)*(b-d)*(b-e)*(c-e)!=0)    //????????????
		)

		cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;}
	//??a,b,c,d,e????
return 0;
}

    