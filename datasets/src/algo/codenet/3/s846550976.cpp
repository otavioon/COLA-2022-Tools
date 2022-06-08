#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=100005;

int a[maxn],b[maxn],c[maxn];

int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	for (i=0;i<n;i++) scanf("%d",&a[i]);
	for (i=0;i<n;i++) scanf("%d",&b[i]);
	for (i=0;i<n;i++) scanf("%d",&c[i]);
	sort(a,a+n);sort(b,b+n);sort(c,c+n);
	i=0;j=0;
	ll tot=0;
	for (k=0;k<n;k++)
	{
		while (b[k]>a[i] && i<n) i++;
		while (b[k]>=c[j] && j<n) j++;
		//cout<<i<<' '<<j<<' '<<(i+1)*(n-j)<<endl;
		tot+=i*(n-j);
	}
	printf("%lld\n",tot);
	return 0;
}