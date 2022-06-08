#include<iostream>
#include<algorithm>
using namespace std;
int n,a[200000],b[200000],c[200000],ans;
int main()
{
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++) cin>>b[i];
	for (int i=0;i<n;i++) cin>>c[i];
	sort(a,a+n);sort(b,b+n);sort(c,c+n);
	int i=0,j=0;
	for (;i<n;i++) if (c[n-1]<b[i]) break;
	for (;j<n;j++) if (b[n-1]<a[j]) break;
	for (int k=0;k<n;k++)
		for (int l=0;l<j;l++)
			for (int m=0;m<i;m++)
				if (a[k]<b[l]&&b[l]<c[m]) ans++;
	cout<<ans;
	return 0;
}