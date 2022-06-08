#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005], b[100005], c[100005];
unsigned long long dp[100005];
int main(){
	int n;
	int i, j, k;
	unsigned long long ans=0;
	
	scanf("%d", &n);
	for(i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for(i=1; i<=n; i++)
		scanf("%d", &b[i]);
	for(i=1; i<=n; i++)
		scanf("%d", &c[i]);
	
	sort(a+1, a+1+n);
	sort(b+1, b+1+n);
	sort(c+1, c+1+n);
	
	b[n+1]=a[n+1]=0x7fffffff;
	for(i=0,j=1; j<=n; j++){
		while(a[i+1]<b[j])
			i++;
		dp[j]=dp[j-1]+i;
	}
	for(j=0,k=1; k<=n; k++){
		while(b[j+1]<c[k])
			j++;
		ans+=dp[j];
	}
	printf("%llu", ans);
	return 0;
} 