#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	int N,i,j,p,sum=0;//??????N?i,j,p,sum
	cin>>N;//??N
	int a[N+1];//??????a[N+1]
	for(i=1;i<=N;i++)
	{
		cin>>a[i];//??a[i]
		if(a[i]%2==0)//?a[i]???
		{
			a[i]=0;//?a[i]=0
			sum=sum+1;//sum??1
		}
	}
	for(i=1;i<=N;i++)//??????????????????
	{
		for(j=1;j<=N-i;j++)
		{
			if(a[j]>a[j+1])
			{
				p=a[j];
				a[j]=a[j+1];
				a[j+1]=p;
			}
		}
	}
	for(j=sum+1;j<=N;j++)//????sum+1????N??
	{
		if(j==sum+1)
			cout<<a[j];
		else
			cout<<','<<a[j];
	}
	return 0;
}
