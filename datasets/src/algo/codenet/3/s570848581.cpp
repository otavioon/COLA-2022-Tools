#include<bits/stdc++.h>
using namespace std;
long long n,a[1000020],b[1000020],c[1000020],i,j,k,t,ai,ci;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)	scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)	scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)	scanf("%lld",&c[i]);
	sort(a+1,a+n+1),sort(b+1,b+n+1),sort(c+1,c+n+1);
	for(i=1;i<=n;i++)
	{
		j=1;k=1;ai=0;ci=0;
		while(a[j]<b[i]&&j<=n){
			j++;
			ai++;
		}
		while(c[k]<=b[i]&&k<=n){
			ci++;
			k++;
		}
		t=t+ai*(n-ci);
	}
	cout<<t<<endl;
    return 0;
}