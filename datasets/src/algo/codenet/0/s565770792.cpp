#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define int long long
using namespace std;
int a1[105][2],a2[105][2],m,n;
char a[105];
signed main(){
	scanf("%s",a+1); n=strlen(a+1); cin>>m;
	a1[1][1]=1; a1[1][0]=0;
	rep(i,2,n){
		a1[i][0]=min(a1[i-1][0],a1[i-1][1]);
		a1[i][1]=min(a1[i-1][0],a1[i-1][1])+1;
		if(a[i]==a[i-1]) a1[i][0]=a1[i-1][1];
	}
	a2[1][1]=1; a2[1][0]=999999999;
	rep(i,2,n){
		a2[i][0]=min(a2[i-1][0],a2[i-1][1]);
		a2[i][1]=min(a2[i-1][0],a2[i-1][1])+1;
		if(a[i]==a[i-1]) a2[i][0]=a2[i-1][1];
	}
	if(a[1]!=a[n]) printf("%lld",min(a1[n][0],a1[n][1])*m);
	else printf("%lld",min(min(a2[n][0],a2[n][1]),a1[n][1])*(m-1)+min(a1[n][1],a1[n][0]));
	return 0;
} 