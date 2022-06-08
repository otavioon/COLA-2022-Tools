#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000020;
long long n,a[MAX],b[MAX],c[MAX],i,j,k,t,ai,ci;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)	scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)	scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)	scanf("%lld",&c[i]);
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