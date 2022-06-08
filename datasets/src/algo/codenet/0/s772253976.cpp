#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long ll;

int n,k;
char st[105];

int main() {
	scanf("%s",st+1);n=strlen(st+1);
	scanf("%d",&k);
	bool same=1;
	fo(i,1,n) same&=st[i]==st[1];
	if (same) {
		printf("%lld\n",(ll)n*k/2);
		return 0;
	}
	if (st[1]==st[n]) {
		int l=1,r=n;
		while (l<n&&st[l+1]==st[1]) l++;
		while (r>1&&st[r-1]==st[n]) r--;
		ll ans=l/2+(n-r+1)/2;
		ans+=(ll)(l+n-r+1>>1)*(k-1);
		int len=0;
		fo(i,l+1,r-1) 
			if (i==l+1||st[i]==st[i-1]) len++;
			else {
				ans+=(ll)len/2*k;
				len=1;
			}
		ans+=(ll)len/2*k;
		printf("%lld\n",ans);
		return 0;
	}
	ll ans=0;int len=0;
	fo(i,1,n) 
		if (i==1||st[i]==st[i-1]) len++;
		else {
			ans+=(ll)len/2*k;
			len=1;
		}
	ans+=(ll)len/2*k;
	printf("%lld\n",ans);
	return 0;
}