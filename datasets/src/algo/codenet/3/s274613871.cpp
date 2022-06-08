#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
int n,l,r,a[N],b[N],c[N],ans;
 
signed main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	for (int i=1;i<=n;++i)
		cin>>b[i];
	for (int i=1;i<=n;++i)
		cin>>c[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	sort(c+1,c+1+n);
	l=0;
	r=1;
	for(int i=1;i<=n;++i)
	{
		for (;l<n&&a[l+1]<b[i];++l);
		for (;r<=n&&c[r]<=b[i];++r);
		ans+=l*(n-r+1);
	}
	cout<<ans;
	return 0;
}