# include "cmath"
# include "queue"
# include "cstdio"
# include "cstring"
# include "iostream"
# include "algorithm"
# define Maxn 33005
# define fi first
# define se second
# define P pair<int,int>
# define rep(i,x,y) for(int i=x;i<=y;i++)
# define rep_d(i,x,y) for(int i=x;i>=y;i--)
# define rep_t(u) for(int i=head[u];i;i=f[i].next)
using namespace std;
typedef long long ll;
inline int read()
{
	int ok=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		ok=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return ok*k;
}
int f[Maxn];
int main()
{
	int n;
	n=read();
	rep(i,1,n)
	f[i]=read();
	sort(f+1,f+n+1);
	int ans=0;
	rep(x,1,n-2)
	{
		rep(y,x+1,n-1)
		{
			int l=y+1;
			int c=f[y]+f[x];
			int r=upper_bound(f+y+1,f+n+1,c)-f-1;
//			cout<<x<<' '<<y<<' '<<l<<' '<<r<<endl;
			if(f[l]>=f[y]+f[x])
			continue;
			ans+=r-l+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}

