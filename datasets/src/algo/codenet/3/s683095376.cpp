#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,f[100001][5],l=0,r,mid,a[1000001],b[100001],c[100001];
int main()
{
	scanf("%lld",&n);
	for(int j=1;j<=n;++j)
		scanf("%lld",&a[j]);
		for(int j=1;j<=n;++j)
		scanf("%lld",&b[j]);
		for(int j=1;j<=n;++j)
		scanf("%lld",&c[j]);
	sort(a+1,a+1+n);sort(b+1,b+1+n);sort(c+1,c+1+n);
	for(int i=1;i<=n;++i)
	{
		f[1][i]=i;
	}
	for(int j=1;j<=n;++j)
		{
			l=0,r=n;
			while(l<=r)
			{
				mid=(l+r)/2;
				if(b[j]<=a[mid])
				{
					r=mid-1;
				}
				else
				l=mid+1;
			}
			f[2][j]=f[2][j-1]+f[1][r];
		}
	for(int j=1;j<=n;++j)
		{
			l=0,r=n;
			while(l<=r)
			{
				mid=(l+r)/2;
				if(c[j]<=b[mid])
				{
					r=mid-1;
				}
				else
				l=mid+1;
			}
			f[3][j]=f[3][j-1]+f[2][r];
		}
	printf("%lld",f[3][n]);
	return 0;
}