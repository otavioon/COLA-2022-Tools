#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<queue>
#include<cmath>
#include<memory.h>
#include<ctime>
#include<cstdio>

using namespace std;

long long a[100005],b[100005],c[100005];

int main()
{
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}	
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	long long an=0,cn=0;	
	for(int i=1;i<=n;i++)
	{
		while(a[an+1]<b[i]&&an+1<=n)
		{
			an++;
		}
        while(c[cn+1]<=b[i]&&cn+1<=n)
        {
        	cn++;
		}        
		ans+=an*(n-cn);
	}
	cout<<ans<<endl;
	return 0;
}
