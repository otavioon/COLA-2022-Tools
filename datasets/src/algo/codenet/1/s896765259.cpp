#include<cstdio>
#include<algorithm>
using namespace std;
int a[11],b[11],c[11][11];
int main()
{
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)scanf("%d",&c[i][j]);
	for (int i=0;i<=100000;i++)
	{
		a[1]=i;
		b[1]=c[1][1]-a[1];
		a[2]=c[2][1]-b[1];
		b[2]=c[2][2]-a[2];
		a[3]=c[3][2]-b[2];
		b[3]=c[3][3]-a[3];
		if ((a[1]+b[2]==c[1][2])&&(a[1]+b[3]==c[1][3])&&(a[2]+b[3]==c[2][3])&&(a[3]+b[1]==c[3][1]))
		{
			printf("Yes");
			return 0;
		}
	}
	printf("No");
}