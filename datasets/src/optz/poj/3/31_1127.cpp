#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;


int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		getchar();
		char a[260]={0},b[260]={0},c[260]={0};
		cin.getline(a,255);
		cin.getline(b,255);
		int a1[260]={0},b1[260]={0},c1[260]={0},i=0,na,nb;
		while(a[++i]!=0)
			;
		na=i;
		while(i-->0)
			a1[251-na+i]=a[i]-'0';
		while(b[++i]!=0)
			;
		nb=i;
		while(i-->0)
			b1[251-nb+i]=b[i]-'0';
		for(i=255;i>0;i--)
		{
			c1[i]+=a1[i]-b1[i];
			if(c1[i]<0)
			{
				c1[i]+=10;
				c1[i-1]-=1;
			}
		}
		for(i=0;c1[i]==0&&i<255;i++)
			;
		if(i==255)
			cout<<"0";
		else
			for(;i<251;i++)
				cout<<c1[i];
		cout<<endl;
	}
	return 0;
}