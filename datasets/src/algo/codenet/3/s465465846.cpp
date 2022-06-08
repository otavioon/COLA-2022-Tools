#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<string>
#include<set>
#include<map>
#define ll long long
#define INF 0x3f3f3f3f
#define N 100005
using namespace std;

int a[3][N];

int main()
{
	int n;
	scanf("%d",&n);
	int x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[0][i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[1][i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[2][i]);
	}
	sort(a[0],a[0]+n);
	sort(a[1],a[1]+n);
	sort(a[2],a[2]+n);
	ll ans=0;
	for(int j=0;j<n;j++)
	{
		ll i=0,k=0;
		while(a[0][i]<a[1][j]&&i<n) i++;
		while(a[2][k]<=a[1][j]&&k<n) k++;
		if(a[1][j]>a[2][n-1]) break;
	//	cout<<i<<' '<<k<<endl;
		ans+=i*(n-k);
	}
	printf("%lld\n",ans);
	return 0;
}