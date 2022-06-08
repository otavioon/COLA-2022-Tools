#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MaxN = 1e5;

bool cmp(int x,int y)
{
	return x>y;
}
LL a[MaxN+5],b[MaxN+5],c[MaxN+5],d[MaxN+5],e[MaxN+5],f[MaxN+5],n;
int l,r,mid,s;
int main()
{
	scanf("%lld",&n);
	for(LL i = 1;i<=n;i++)  scanf("%lld",&a[i]);
	for(LL i = 1;i<=n;i++)  scanf("%lld",&b[i]);
	for(LL i = 1;i<=n;i++)  scanf("%lld",&c[i]);
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);

	for(LL j=1;j<=n;j++){
		l=1;
		r=n;
		while(l<=r){
			mid=(l+r)/2;

			if(b[j]<=a[mid]){
				r=mid-1;
			}
			else  l=mid+1;
		}
		d[j]=r;
	}
	for(LL j=1;j<=n;j++){
		l=1;
		r=n;
		while(l<=r){
			mid=(l+r)/2;
			if(b[j]<=c[mid]){
				r=mid-1;
			}
			else  l=mid+1;
		}
		e[j]=n-r;
	}
	s = 0;
	for(LL h=1;h<=n;h++){
		f[h]=d[h]*e[h];
		s = s+f[h];
	}
	printf("%d\n",s);
}