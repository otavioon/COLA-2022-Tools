#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=41;
int n,m;
typedef long long ll;
ll f[maxn][maxn][maxn],ans;
char s[maxn][maxn];

ll dp(int l,int r,int mid)
{
	if (~f[l][r][mid])
		return f[l][r][mid];
	if (l==r)
		return f[l][r][mid]=1;
	if (l==mid||mid==r)
		return f[l][r][mid]=0;
	int j,k,p,q;
	ll res=0;
	for (j=l;j<=mid-1;j++)
		for (k=mid+1;k<=r;k++)
			if (s[j][k]=='1')
				for (p=j;p<=mid-1;p++)
					for (q=mid+1;q<=k;q++)
						res+=1ll*dp(l,p,j)*dp(p+1,q-1,mid)*dp(q,r,k);
	return f[l][r][mid]=res;
}

int main()
{
	int i;
	scanf("%d",&n);
	m=(n<<1);
	for (i=1;i<=m;i++)
		scanf("%s",s[i]+1);
	memset(f,-1,sizeof(f));
	f[2][m][2]=f[2][m][m]=0;
	for (i=3;i<m;i++)
		if (s[1][i]=='1')
			ans+=dp(2,m,i);
	printf("%lld\n",ans);
	return 0;
}