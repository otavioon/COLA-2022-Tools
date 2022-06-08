#include<iostream>        //如果所有的数加起来-正对角线上的数=正对角线上的数*2 就是yes 
using namespace std;
int main()
{
	int c[4][4];
	for(int i=1;i<4;i++)
	{
		for(int j=1;j<4;j++)
		cin>>c[i][j];
	}
	int asum=0;
	int xsum=0;
	for(int i=1;i<4;i++)
	{
		for(int j=1;j<4;j++)
		{
			asum=asum+c[i][j]; 
		}
		xsum=xsum+c[i][i];
	} 
	if(asum-xsum==xsum*2)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
} 