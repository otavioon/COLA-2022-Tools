#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

const int N=3e5+5;
int n,a[N],calc[N],tl,ans;

int ask(int x)
{
	int i;
	for(i=30;~i;--i)
		if(x&(1<<i))
			break;
	return (1<<i+1)-x;
}
int ok(int x)
{
	int i;
	for(i=30;~i;--i)
		if(x&(1<<i))
			break;
	int tt=x^(1<<i);
	if(!tt) return 1;
	return 0;
}

void cc()
{
	int i,l=1;
	for(i=tl;i;--i)
	{
		int mx=ask(calc[i]);
		while(l<i-1&&calc[l]<=mx) ++l;
		if(l>=i) continue;
		if(ok(calc[l]+calc[i])) ++l,++ans;
	}
}

bool cmp(int x,int y)
{
	return (x&1)<(y&1);
}
void init()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	while(n)
	{
		tl=0;
		sort(a+1,a+n+1,cmp);
		for(i=n;i;--i)
		{
			if(!(a[i]&1)) break;
			calc[++tl]=a[i];
		}
		cc();n=i;
		for(i=1;i<=n;++i) a[i]>>=1;
	}
	printf("%d\n",ans);
}

int main()
{
	init();
	return 0;
}