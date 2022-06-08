#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,k,flag=1,pos=0,len=1,sumv=0,ans;
int b[1005];

char a[1005];

signed main()
{
	string s;
	cin>>s>>k;
	n=s.size();
	for (int i=1;i<=n;i++)  a[i]=s[i-1];
	
	for (int i=1;i<=n-1;i++)
	{
		if (a[i]!=a[i+1])
		{
			flag=0;
			break;
		}
	}
	if (flag==1)  return cout<<(s.size()*k)/2<<endl,0;
	
	for (int i=n+1;i<=2*n;i++)  a[i]=a[i-n];
	for (int i=2;i<=2*n;i++)
	{
		if (a[i]!=a[i-1]&&i>n)
		{
			b[++pos]=len;
			break;
		}
		else if (a[i]!=a[i-1])
		{
			b[++pos]=len;
			len=1;
		}
		else len++;
	}//1 2 3
	for (int i=1;i<=pos;i++)  sumv+=(b[i]/2);
	
	if (a[n]!=a[1])  return cout<<sumv*k<<endl,0;
	if (k==1)  return cout<<sumv<<endl,0;
	
	if (b[pos]%2==1)  ans=sumv+(k-2)*(sumv-(b[1]/2))+sumv;
	else ans=sumv+(k-2)*(sumv-(b[1]/2))+sumv-1;
	
	cout<<ans<<endl;
	return 0;
}