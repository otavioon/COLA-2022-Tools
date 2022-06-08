#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int num[10];

int main()
{
	int x,y,z;
	for(int i=1;i<10;i++)
	{
		cin>>num[i];
	}
	
	x=num[4]+num[5]+num[6]-num[7]-num[8]-num[9];
	y=num[1]+num[2]+num[3]-(num[4]+num[5]+num[6]);
	z=num[1]+num[2]+num[3]-num[7]-num[8]-num[9];
	
	if(x%3==0 && y%3==0 && z%3==0)
	{
		cout<<"Yes"<<endl;
	}
	else
	cout<<"No"<<endl;
	
	return 0;
}