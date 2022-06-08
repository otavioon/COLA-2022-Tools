#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#define Rint register int
#define Temp template<typename T>
#define mem(a,b) memset(a,(b),sizeof(a))
using namespace std;
typedef long long LL;
Temp inline void chkmin(T &x,T y){if(y<x)x=y;}
Temp inline void chkmax(T &x,T y){if(y>x)x=y;}
Temp inline void read(T &x){
	x=0;T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}
const int maxn=100000+10;
int n;
LL ans;
int a[maxn],b[maxn],c[maxn];
int la[maxn],lb[maxn];
inline int lower_find(int k,int x){
	int l=1,r=n+1;
	if(k==1){
		while(l<r){
			int mid=((l+r)>>1);
			if(a[mid]<=x)l=mid+1;
			else r=mid;
		}
		return l;
	}
	else if(k==2){
		while(l<r){
			int mid=((l+r)>>1);
			if(b[mid]<=x)l=mid+1;
			else r=mid;
		}
		return l;
	}
	else if(k==3){
		while(l<r){
			int mid=((l+r)>>1);
			if(c[mid]<=x)l=mid+1;
			else r=mid;
		}
		return l;
	}
}
int main(){
	read(n);
	for(Rint i=1;i<=n;i++)read(a[i]);
	for(Rint i=1;i<=n;i++)read(b[i]);
	for(Rint i=1;i<=n;i++)read(c[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	for(Rint i=1;i<=n;i++)la[i]=lower_find(2,a[i])-1;
	for(Rint i=1;i<=n;i++)lb[i]=lower_find(3,b[i])-1;
	for(Rint i=1;i<=n;i++){
		for(Rint j=la[i]+1;j<=n;j++){
			ans+=(n-lb[j]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}