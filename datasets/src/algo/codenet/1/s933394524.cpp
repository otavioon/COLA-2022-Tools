#include<cstdio>
#include<string>
#include<cstring>
#include<utility>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<vector>
#include<iostream>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define inf 0x7fffffff
using namespace std;
int a[4][4];
int main()
{
	int i,j,k,n,m,x,y;
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	if(a[1][2]-a[1][1]==a[2][2]-a[2][1]&&a[2][2]-a[2][1]==a[3][2]-a[3][1]&&
	   a[1][3]-a[1][1]==a[2][3]-a[2][1]&&a[2][3]-a[2][1]==a[3][3]-a[3][1]&&
	   a[2][1]-a[1][1]==a[2][2]-a[1][2]&&a[2][2]-a[1][2]==a[2][3]-a[1][3]&&
	   a[3][1]-a[1][1]==a[3][2]-a[1][2]&&a[3][2]-a[1][2]==a[3][3]-a[1][3])
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	return 0;
}