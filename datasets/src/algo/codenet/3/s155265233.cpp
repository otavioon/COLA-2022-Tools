#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int a[100000];
int b[100000];
int c[100000];

int bs(int d[],int n,int t)
{
	int l=0;
	int r=n;
	if(d[n-1]<=t)
	{
		return -1;
	}
	if(d[0]>t)
	{
		return 0;
	}
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(d[mid]>t)
		{
			r=mid;
		}else{
			l=mid;
		}
	}
	return r;
}

int main()
{
	int n;
	ll ans=0;
	
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

	for(int i=0;i<n;i++)
	{
		int bindex = bs(b,n,a[i]);
		if(bindex==-1)
		{
			break;
		}
		int bb = b[bindex];
		for(int j=bindex;j<n;j++)
		{
			int cindex = bs(c,n,b[j]);
			//cerr<<j<<" "<<cindex<<endl;
			if(cindex==-1)
			{
				break;
			}
			ans += n-cindex;
		}
	}
	cout<<ans<<endl;
	return 0;
}