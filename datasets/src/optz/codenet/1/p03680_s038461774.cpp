#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int mark[100001],A[100001];
int main()
{
	int n,i,x,c=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>A[i];
	x=1;
	c=0;
	mark[1]=1;
	while(x!=2)
	{
		c++;
		x=A[x];
		if(mark[x])
		break;
		mark[x]=1;
	}
	if(x==2)
		cout<<c;
	else
		cout<<"-1";
	return 0;
}

