#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f, maxn=200007, mod=1e9+7;

int a[maxn];
long long h[maxn];
int n,ans;
int main(){
	h[0]=1;
	for(int i=1;i<=31;i++)h[i]=h[i-1]<<1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int k=30;k>=1;k--){
		for(int i=1,j=n;i<j;i++){
			if(a[i]!=inf){
				while(j>i&&(a[i]+a[i]>inf))j--;
				if(j>i&&a[i]+a[j]==h[k])ans++,a[i]=a[j]=inf;
			}
		}
	}
	printf("%d\n",ans);
    return 0;
}
