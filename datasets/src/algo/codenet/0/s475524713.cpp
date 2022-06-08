#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
#define maxn 110
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
inline void write(ll x)
{
	static char buf[20];
	int len=0;
	if(x<0)putchar('-'),x=-x;
	for(;x;x/=10)buf[len++]=x%10+'0';
	if(!len)putchar('0');
	else while(len)putchar(buf[--len]);
}
inline void writesp(ll x){write(x); putchar(' ');}
inline void writeln(ll x){write(x); putchar('\n');}
char s[maxn];
int a[maxn];
int n,k;
int main()
{
	scanf("%s",s); n=strlen(s);
	k=read();
	int last=0,tot=0;
	for(int i=0;i<n;i++)
		if(s[i]!=s[i+1])a[++tot]=i-last+1,last=i+1;
	ll ans=0;
	if(tot==1)ans=(ll)n*k/2;
	else if(s[0]==s[n-1]){
		for(int i=2;i<tot;i++)
			ans+=(ll)k*(a[i]/2);
		ans+=(a[1]/2)+(ll)(k-1)*((a[1]+a[tot])/2)+(a[tot]/2);
	}
	else{
		for(int i=1;i<=tot;i++)
			ans+=(ll)k*(a[i]/2);
	}
	writeln(ans);
	return 0;
}