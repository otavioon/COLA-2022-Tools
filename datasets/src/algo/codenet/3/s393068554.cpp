#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100005
#define ll long long

int n,l,r,i,a[N],b[N],c[N];
ll ans;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);sort(a+1,a+n+1);
	for(i=1;i<=n;i++)scanf("%d",&b[i]);sort(b+1,b+n+1);
	for(i=1;i<=n;i++)scanf("%d",&c[i]);sort(c+1,c+n+1);
	l=0,r=1;
	for(i=1;i<=n;i++){
		while(l<n&&a[l+1]<b[i])l++;
		while(r<=n&&c[r]<=b[i])r++;
		ans+=1ll*l*(n-r+1);
	}printf("%lld\n",ans); 
	return 0;
}