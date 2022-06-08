#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[100001],b[100001],c[100001],dp[100001];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	int ax=0;
	long long ans=0;
	for(int i=1;i<=n;i++){
		while(ax<n&&a[ax+1]<b[i]) ax++;
		dp[i]=ax;
	}
	int bx=0;
	long long ans2=0;
	for(int i=1;i<=n;i++){
		while(bx<n&&b[bx+1]<c[i]) bx++,ans2+=(long long)dp[bx];
		ans+=ans2;
	}
	printf("%lld",ans);
}