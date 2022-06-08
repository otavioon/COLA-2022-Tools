#include<algorithm>
#include<stack>
#include<ctime>
#include<cstring>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<queue>
using namespace std;
typedef int _int;
#define int long long 
inline int read(){
	int num=0,f=1;char x=getchar();
	while(x<'0'||x>'9'){if(x=='-')f=-1;x=getchar();}
	while(x>='0'&&x<='9'){num=num*10+x-'0';x=getchar();}
	return num*f;
}
const int maxn=200005;
int n,k,MAX;
int A[maxn];
bool check(int x){
	int cnt=0;
	for(int i=1;i<=n;++i){
		cnt+=(int)ceil((double)A[i]/x)-1;
	}
	return cnt<=k;
}
_int main(){
	n=read();k=read();
	for(int i=1;i<=n;++i){
		A[i]=read();
		MAX=max(MAX,A[i]);
	}
	int L=0,R=MAX,ans=0;
	while(L<=R){
		int mid=(L+R)>>1;
		if(check(mid))ans=mid,R=mid-1;
		else L=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}
