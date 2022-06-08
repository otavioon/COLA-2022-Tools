#include<cstdio>
int main(){
	int a[9]={};
	for(int i=0;i<9;i++){
		scanf("%d",&a[i]);
	}
	int p=a[0]+a[4]+a[8];
	int q=a[0]+a[5]+a[7];
	int r=a[1]+a[3]+a[8];
	int s=a[1]+a[5]+a[6];
	int t=a[2]+a[4]+a[6];
	int u=a[2]+a[3]+a[7];
	if(p==q && q==r && r==s && s==t && t==u)printf("Yes\n");
	else printf("No\n");
	return 0;
}