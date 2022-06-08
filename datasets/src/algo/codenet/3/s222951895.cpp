#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<stack>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#define N 100100
#define LL long long

using namespace std;

int a[N],b[N],c[N];
LL A[N],B[N];

int main()
{
	int n;
	scanf ("%d",&n);
	for (int i=1;i<=n;i++)
		scanf ("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf ("%d",&b[i]);
	for (int i=1;i<=n;i++)
		scanf ("%d",&c[i]);
	
	sort (a+1,a+n+1);
	sort (b+1,b+n+1);
	sort (c+1,c+n+1);
	
	int loc = 1;
	for (int i=1;i<=n;i++)
	{
		while (loc <= n && b[i]>a[loc])
			loc ++;
		B[i] = loc-1;
	}
	
	loc = 1;
	LL ans = 0,tmp = 0;
	for (int i=1;i<=n;i++)
	{
		while (loc <= n && c[i]>b[loc])
			tmp += B[loc++];
		ans += tmp;
	}
	
	printf ("%lld\n",ans);
	return 0;
}
