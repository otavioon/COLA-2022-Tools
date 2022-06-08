#include<bits/stdc++.h>
using namespace std;
typedef int sign;
typedef long long ll;
#define For(i,a,b) for(register sign i=(sign)(a);i<=(sign)(b);++i)
#define Fordown(i,a,b) for(register sign i=(sign)(a);i>=(sign)(b);--i)
const int N=2e5+5;
template<typename T>bool cmax(T &a,T b){return (a<b)?a=b,1:0;}
template<typename T>bool cmin(T &a,T b){return (a>b)?a=b,1:0;}
template<typename T>T read()
{
	T ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(isdigit(ch))ans=(ans<<3)+(ans<<1)+(ch-'0'),ch=getchar();
	return ans*f;
}
template<typename T>void write(T x,char y)
{
	if(x==0)
	{
		putchar('0'),putchar(y);
		return;
	}
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	static char wr[20];
	int top=0;
	for(;x;x/=10)wr[++top]=x%10+'0';
	while(top)putchar(wr[top--]);
	putchar(y);
}
void file()
{
#ifndef ONLINE_JUDGE
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
}
int n,a[N];
void input()
{
	n=read<int>();
	For(i,1,n)a[i]=read<int>();
}
void work()
{
	int ans=0;
	sort(a+1,a+n+1);
	Fordown(i,30,0)
	{
		int r=n;
		For(l,1,r)
		{
			while(r>l&&a[r]+a[l]>(1<<i))r--;
			if(r<=l)break;
			if(a[l]+a[r]==(1<<i))a[l]=a[r]=0,ans++,r--;
		}
		int top=0;
		For(i,1,n)if(a[i])a[++top]=a[i];
		n=top;
	}
	write(ans,'\n');
}
int main()
{

	input();
	work();
	return 0;
}
