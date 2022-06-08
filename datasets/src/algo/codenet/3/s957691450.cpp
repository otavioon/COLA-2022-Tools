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

int main()
{
	int n;
	long long ans=0;
	long long a[100005],b[100005],c[100005];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}	
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
	long long an,cn;	
	for(int i=0;i<n;i++)
	{
		an=0;
		cn=0;
		while(a[an]<b[i]&&an<n)
		{
			an++;
		}
        while(c[cn]<=b[i]&&cn<n)
        {
        	cn++;
		}        
		ans+=an*(n-cn);
	}
	cout<<ans<<endl;
	return 0;
}
