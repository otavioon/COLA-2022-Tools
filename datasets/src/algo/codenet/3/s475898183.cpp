#include<stdio.h>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
int a[maxn],b[maxn],c[maxn];
int main()
{
	int i;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=n;i++) scanf("%d",&b[i]);
	for (i=1;i<=n;i++) scanf("%d",&c[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	i=0;
	int j=1,k=0;
	long long ans=0;
	while(j<=n){
		while(a[i+1]<b[j]&&i+1<=n)i++;
		while(k+1<=n&&b[j]>=c[k+1])k++;
		if (b[j]>c[n]) break;
		ans=ans+(long long)i*(n-k);
		//printf("%d %d %d %lld\n",i,j,n-k,ans);
		j++;
	}
	printf("%lld\n",ans);
	return 0;
}