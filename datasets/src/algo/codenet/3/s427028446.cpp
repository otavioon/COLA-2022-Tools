#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
long long n,a[N],b[N],c[N],x,y;
long long ans;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	for(int i=0;i<n;i++)cin>>c[i];
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
	x=0,y=0;
	for(int i=0;i<n;i++)
	{
		while(a[x]<b[i]&&x<n)x++;
		while(c[y]<=b[i]&&y<n)y++;
		ans+=x*(n-y);
	}
	cout<<ans<<endl;
	return 0;
}