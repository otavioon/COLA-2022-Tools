#include<bits/stdc++.h>

#define HAS_TEST_CASE 0  // Do you forget to complete this?

namespace registerGen
{
typedef long long ll;

const int N=5e5;
const double eps=1e-6;

int n,m,a[N+10];
char str[N+10];

inline bool check(double x)
{
	int res=0;
	for(int i=1;i<=n;i++)
	{
		double tmp=1.0*a[i]/x;
		if(double(tmp-int(tmp))==0.0)res+=int(tmp)-1;
		else res+=int(tmp);
	}
	return res<=m;
}

inline void main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	int l=0,r=0x3f3f3f3f,ans=0;
	for(int i=1;i<=n;i++)
		ans=std::max(ans,a[i]);
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}
}

int main()
{
#if !defined(ONLINE_JUDGE) && HAS_TEST_CASE
	freopen("tmp.out","w",stdout);
#endif
	int T=1;
#if HAS_TEST_CASE
	scanf("%d",&T);
#endif
	while(T--)registerGen::main();
	return 0;
}
