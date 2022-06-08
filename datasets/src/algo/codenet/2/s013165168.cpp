#include<bits/stdc++.h>
using namespace std;
long long num[40];
int a[200001],b[200001];
int main()
{
	int n;
	cin>>n;
	int c;
	int t=0,m=0;
	num[0]=1;
	for(int i=1;i<=39;i++)
		num[i]=num[i-1]*2;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=39;j++)
			if(a[i]<num[j])
			{
				b[i]=num[j]-a[i];
				break;
			}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(b[i]==a[j]&&i!=j&&b[i]!=-1&&a[j]!=-1)
			{
				ans++;
				b[i]=b[j]=a[i]=a[j]=-1;
			}
	}
//	for(int i=1;i<=n;i++)
//		cout<<"a["<<i<<"]:"<<a[i]<<" b["<<i<<"]:"<<b[i]<<endl;
	cout<<ans;
}