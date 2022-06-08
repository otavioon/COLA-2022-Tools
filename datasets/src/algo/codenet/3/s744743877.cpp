#include<bits/stdc++.h>
using namespace std;
int sum=0;
int main()
{
	int n;
	cin>>n;
	int a[n+1],b[n+1],c[n+1];
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
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(a[i]<b[j]&&b[j]<c[k]) sum++;
			}
		}
	}
	cout<<sum;
}