#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int p=a[1],ans=0;
	int temp;
	while(ans<=n)
	{
		if(p==2)
		{
			break;
		}
		temp=p;
		p=a[temp];
		ans++;
	}
	if(ans>n)
	{
		cout<<"-1";
		return 0;
	}
	cout<<ans+1;
	return 0;
}