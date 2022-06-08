#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
#define maxn 100010
int n;
ll a,b,h[maxn];
bool test(int mid){
	int ans=0;
	for(int i=0;i<n;i++){
		int c=h[i]-mid*b;
		if(c>0){
			if(c%(a-b)==0)
				ans+=c/(a-b);
			else
				ans+=c/(a-b)+1;
		}
	}
	return ans<=mid;
}
int main(){
	scanf("%d%lld%lld",&n,&a,&b);
	ll maxh=0;
	for(int i=0;i<n;i++){
		scanf("%lld",&h[i]);
		maxh=max(maxh,h[i]);
	}
	ll l=0,r=maxh/b+1;
	while(l<r){
		ll mid=(l+r)/2;
		if(test(mid))
			r=mid;
		else
			l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}