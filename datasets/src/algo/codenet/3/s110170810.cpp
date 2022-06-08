#include<bits/stdc++.h>
using namespace std;
int n,a[1000001],b[1000001],c[1000001],i,j,k,t,ai,ci;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)	cin>>b[i];
	for(int i=1;i<=n;i++)	cin>>c[i];
	sort(a+1,a+n+1),sort(b+1,b+n+1),sort(c+1,c+n+1);
	for(i=1;i<=n;i++)
	{
		j=1;k=n;ai=0;ci=0;
		while(a[j]<b[i]&&j<=n){
			j++;
			ai++;
		}
		while(c[k]>b[i]&&k>=1){
			ci++;
			k--;
		}
		t=t+ai*ci;
	}
	cout<<t;
}