#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
#include<map>
#include<set>
using namespace std;
int n;
pair <int,int> a[200005];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	    scanf("%d",&a[i].first);
	sort(a,a+n);
	int ans=0;
	for(int i=n;i--;)
	{
		if(a[i].second)
		    continue;
		int j;
		for(j=1;j<=a[i].first;j*=2)
		    ;
		int k=upper_bound(a,a+i,make_pair(j-a[i].first,0))-a;
		if(0<k&&k<=i&&a[i].first+a[k-1].first==j)
		{
			ans++;
			a[i].second=a[k-1].second=1;
		}
	}
	cout<<ans;
	return 0;
}