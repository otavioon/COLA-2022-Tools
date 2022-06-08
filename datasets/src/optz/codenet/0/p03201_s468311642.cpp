#include <stdio.h>
#include <algorithm>
#define MN 200000
int n,a[MN+5],ans;
bool vis[MN+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	std::sort(a+1,a+1+n);
	for(int k=(1<<30);k>=2;k>>=1){
		int l=1;
		for(;a[n]>=(k>>1);n--){
			if(vis[n]) continue;
			while(l<n&&(vis[l]||a[l]+a[n]<k)) l++;
			if(l>=n) continue;
			if(a[l]+a[n]==k){
				vis[l]=vis[n]=true;
				ans++;
			}
		}
	}
	printf("%d\n",ans);
}