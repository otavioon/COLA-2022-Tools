#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<map>
#include<queue>
#include<set>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int n,a[110000],b[110000],c[110000],p,q;
long long ans;
int main(){
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]);
	fo(i,1,n) scanf("%d",&b[i]);
	fo(i,1,n) scanf("%d",&c[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	p=0;q=1;
	fo(i,1,n){
		while (p<n&&a[p+1]<b[i]) p++;
		while (q<=n&&c[q]<=b[i]) q++;
		ans+=p*(long long)(n-q+1);
	}
	printf("%lld\n",ans);
	return 0;
}