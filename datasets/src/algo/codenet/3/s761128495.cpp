#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=100005;

int a[maxn],b[maxn],c[maxn],d1[maxn],d2[maxn];

int main()
{
	int n,i,j;
	scanf("%d",&n);
	for (i=0;i<n;i++) scanf("%d",&a[i]);
	for (i=0;i<n;i++) scanf("%d",&b[i]);
	for (i=0;i<n;i++) scanf("%d",&c[i]);
	sort(a,a+n);sort(b,b+n);sort(c,c+n);
	for (i=0;i<n;i++) 
	{
	  for (j=0;j<n;j++)
	  	if (b[j]>a[i]) break;
	  d1[i]=j;
   }
	for (i=0;i<n;i++)
	{
	  for (j=0;j<n;j++)
	    if (c[j]>b[i]) 
		   break;
	  d2[i]=j;
	}
	ll tot=0;
	for (i=0;i<n;i++)
	  for (j=d1[i];j<n;j++)
	    tot+=(n-d2[j]);
	printf("%d\n",tot);
	return 0;
}