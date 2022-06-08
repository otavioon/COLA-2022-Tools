#include<bits/stdc++.h>
 
#pragma GCCoptimize (2)
using namespace std;
 
int a[100000000];
int b[100000000];
int c[100000000];
 
int main(){
	int n;
	int x=1,y=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	scanf("%d",&c[i]);
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