#include <bits/stdc++.h>
#define il inline
#define Max 100005
#define int long long
#define ll long long
using namespace std;
il int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c>'9'||c<'0')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
char s[Max];
int n,m,f[Max][2],ans;
signed main()
{
	scanf("%s",s+1);
	cin>>n;
	m=strlen(s+1);
	for(int i=1;i<=m;i++) s[i+m]=s[i];
	f[1][0]=0,f[1][1]=1;
	for(int i=2;i<=m*2;i++)
	{
		if(s[i]==s[i-1]) f[i][0]=f[i-1][1],f[i][1]=min(f[i-1][0],f[i-1][1])+1;
		else f[i][0]=min(f[i-1][0],f[i-1][1]),f[i][1]=f[i][0]+1;
	}
	ans=1e17;
	if(s[1]!=s[m]) ans=min(f[m][0],f[m][1])*n;
	else ans=min(ans,f[m][1]*n),ans=min(ans,f[m][0]*n+n-1);
	ans=min(ans,f[2*m][1]*(n/2)+min(f[m][0],f[m][1])*(n&1));
	if(s[1]!=s[m]) ans=min(ans,f[2*m][0]*(n/2)+min(f[m][0],f[m][1])*(n&1));
	cout<<ans<<endl;
}