#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[3],i,j;
	int arr[3][3];
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&arr[i][j]);
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<3;j++)
		{
			if(a[i]+a[j]!=arr[i][j])
			{
				printf("No");
				return 0;
			}
		}
	}
	printf("Yes");
	return 0;
} 