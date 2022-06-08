#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int Max=100005;

int main()
{
	int n;
	scanf("%d",&n);
	int a[Max],b[Max],c[Max];
	long long ans=0;
	for(int i=1;i<=n;i++)
	    scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
	    scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)     
	    scanf("%d",&c[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	int i=0,j=1,k=0;
	while(j<=n)
	{
		while(a[i+1]<b[j]&&i+1<=n) i++;
		while(k+1<=n && b[j]>=c[k+1]) k++;
		if (b[j]>c[n]) break;
    	ans+=(long long)i*(n-k);
		j++;
	}
	printf("%I64d\n",ans);
	return 0;
}