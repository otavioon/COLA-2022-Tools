#include <iostream>
using namespace std;
int main()
{
	int a1,a2,a3,b1,b2,b3;
	int x[4][4];
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>x[i][j];
		}
	}
	a1=0;
	b1=x[1][1];
	b2=x[1][2];
	b3=x[1][3];
	a2=x[2][1]-b1;
	a3=x[3][1]-b1;
	if(a2+b2==x[2][2]&&a2+b3==x[2][3]&&a3+b2==x[3][2]&&a3+b3==x[3][3]);
	{cout<<"Yes";
	return 0;
	}
	cout<<"No";
}