#include <iostream>
using namespace std;
int main ()
{
	int a[3][3];
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
	int k,l;
	k=2*(a[0][0]+a[1][1]+a[2][2]);
	l=a[0][1]+a[0][2]+a[1][0]+a[1][2]+a[2][0]+a[2][1];
	
	if (k==l)
	{
		cout<<"Yes";
	}
	else 
	{
		cout<<"No";
	}
}