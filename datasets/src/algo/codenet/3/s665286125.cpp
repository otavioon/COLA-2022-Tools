#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;
char c;
int n,i,j,a[3][100005],k;
long long ans;
int main()
{
	cin>>n;
	for(j=0;j<=2;j++)
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[j][i]);
	}
	for(i=0;i<=2;i++)
	sort(&a[i][1],&a[i][n+1]);
	for(i=1;i<=n;i++)
	{
		for(j=n;j>=1;j--)
		if(a[0][i]>a[1][n])
		{
			i=n+1;
			break;
		}
		else if(a[0][i]>=a[1][j])
		break;
		else 
		{
			for(k=n;k>=1;k--)
			if(a[1][j]>=a[2][k])
			break;
			else 
			{
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}