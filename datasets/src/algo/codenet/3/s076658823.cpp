#include<bits/stdc++.h>

using namespace std;

int a[10000000];
int b[10000000];
int c[10000000];

int main(){
	int n;
	int x=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	cin>>b[i];
	for(int i=1;i<=n;i++)
	cin>>c[i];
	int ans=0;
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	
	for(int i=1;i<=n;i++)
	for(int j=x;j<=n;j++)
	{
		if(a[i]<b[j]) {
		
		for(int k=1;k<=n;k++)
		{
			if(c[k]>b[j])
			{
				ans+=(n-k+1);
				break;
			}
		}
		}
		else if(a[i]>=b[j])
		x=j;
	}
	cout<<ans;
	return 0;
}
